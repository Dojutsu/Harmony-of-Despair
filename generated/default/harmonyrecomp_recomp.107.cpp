#include "harmonyrecomp_funcs.107.h"

DEFINE_REX_FUNC(sub_82216F28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82216F30;
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x82216F44;
	sub_825A43F0(ctx, base);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stfs f1,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// lfs f31,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// bne cr6,0x82216f6c
	if (!ctx.cr6.eq) goto loc_82216F6C;
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,48(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// b 0x82216f70
	goto loc_82216F70;
loc_82216F6C:
	// stfs f31,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
loc_82216F70:
	// stfs f31,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// stfs f31,28(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// beq cr6,0x82216f88
	if (ctx.cr6.eq) goto loc_82216F88;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
loc_82216F88:
	// lwz r29,4(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x8221705c
	goto loc_8221705C;
loc_82216F98:
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r30,16(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x82217050
	if (ctx.cr6.eq) goto loc_82217050;
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82217050
	if (!ctx.cr6.eq) goto loc_82217050;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82216FCC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82217050
	if (ctx.cr0.eq) goto loc_82217050;
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fmr f13,f31
	ctx.f13.f64 = ctx.f31.f64;
	// fmr f12,f31
	ctx.f12.f64 = ctx.f31.f64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82217030
	if (!ctx.cr6.eq) goto loc_82217030;
	// lfs f12,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f13,f0,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f12.f64)));
	// lfs f10,12(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f11,f0,f10
	ctx.f11.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f10.f64)));
	// lfs f10,12(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsubs f12,f10,f11
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f11,f12,f12,f11
	ctx.f11.f64 = double(float(std::fma(ctx.f12.f64, ctx.f12.f64, ctx.f11.f64)));
	// fdivs f11,f9,f11
	ctx.f11.f64 = double(float(ctx.f9.f64 / ctx.f11.f64));
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmuls f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
loc_82217030:
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f11,28(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// fadds f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
loc_82217050:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82216520
	ctx.lr = 0x82217058;
	sub_82216520(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8221705C:
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82216f98
	if (!ctx.cr6.eq) goto loc_82216F98;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82217078;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82225CB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f0,14876(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14876);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f13,-2188(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2188);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82225cd8
	if (ctx.cr6.lt) goto loc_82225CD8;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_82225CD8:
	// fsubs f0,f3,f2
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f12,480(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 480);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// blt cr6,0x82225cfc
	if (ctx.cr6.lt) goto loc_82225CFC;
	// lfs f12,484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 484);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x82225d00
	if (!ctx.cr6.gt) goto loc_82225D00;
loc_82225CFC:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_82225D00:
	// fabs f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// lfs f0,140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bge cr6,0x82225d28
	if (!ctx.cr6.lt) goto loc_82225D28;
	// li r11,4
	ctx.r11.s64 = 4;
loc_82225D28:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8222BA40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8222BA48;
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82223a50
	ctx.lr = 0x8222BA60;
	sub_82223A50(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8222bd24
	if (ctx.cr0.eq) goto loc_8222BD24;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fabs f13,f0
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// addi r25,r11,12236
	ctx.r25.s64 = ctx.r11.s64 + 12236;
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,1968(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 1968);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8222ba8c
	if (!ctx.cr6.gt) goto loc_8222BA8C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8222BA8C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8222ba9c
	if (ctx.cr0.eq) goto loc_8222BA9C;
loc_8222BA94:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8222bd28
	goto loc_8222BD28;
loc_8222BA9C:
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// lwz r10,148(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 5;
	// addic. r30,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r30.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8222bacc
	if (ctx.cr0.lt) goto loc_8222BACC;
	// addi r29,r31,132
	ctx.r29.s64 = ctx.r31.s64 + 132;
loc_8222BAB8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x822296a0
	ctx.lr = 0x8222BAC4;
	sub_822296A0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x8222bab8
	if (!ctx.cr0.lt) goto loc_8222BAB8;
loc_8222BACC:
	// lwz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8222bd24
	if (ctx.cr6.eq) goto loc_8222BD24;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x8222BAE4;
	sub_82222D88(ctx, base);
	// mr. r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq 0x8222bd24
	if (ctx.cr0.eq) goto loc_8222BD24;
	// lbz r11,53(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 53);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8222bd24
	if (!ctx.cr0.eq) goto loc_8222BD24;
	// ld r11,16(r24)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r24.u32 + 16);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lwz r11,24(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8222BB18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x8222BB30;
	sub_825E02A0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8222bd24
	if (ctx.cr6.eq) goto loc_8222BD24;
	// ld r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lfs f31,232(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// addi r30,r31,100
	ctx.r30.s64 = ctx.r31.s64 + 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// std r10,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// stfs f31,8(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// bl 0x8221a7c0
	ctx.lr = 0x8222BB60;
	sub_8221A7C0(ctx, base);
	// lwz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// blt cr6,0x8222bbd4
	if (ctx.cr6.lt) goto loc_8222BBD4;
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8236c610
	ctx.lr = 0x8222BBA4;
	sub_8236C610(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8222bbb4
	if (ctx.cr6.eq) goto loc_8222BBB4;
	// bl 0x825e0378
	ctx.lr = 0x8222BBB4;
	sub_825E0378(ctx, base);
loc_8222BBB4:
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8222bbd4
	if (ctx.cr6.eq) goto loc_8222BBD4;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r11.u32);
	// bne 0x8222bbd4
	if (!ctx.cr0.eq) goto loc_8222BBD4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
loc_8222BBD4:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r27,r31,132
	ctx.r27.s64 = ctx.r31.s64 + 132;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lfs f3,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82229550
	ctx.lr = 0x8222BBF0;
	sub_82229550(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f30,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r26,r11,-32216
	ctx.r26.s64 = ctx.r11.s64 + -32216;
	// lwz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8222bcb8
	if (!ctx.cr6.gt) goto loc_8222BCB8;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f29,1748(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1748);
	ctx.f29.f64 = double(temp.f32);
loc_8222BC18:
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8236c610
	ctx.lr = 0x8222BC48;
	sub_8236C610(ctx, base);
	// lwz r29,0(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8222bca8
	if (ctx.cr6.eq) goto loc_8222BCA8;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,8(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 8, temp.u32);
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8222bc78
	if (!ctx.cr6.lt) goto loc_8222BC78;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// b 0x8222bc84
	goto loc_8222BC84;
loc_8222BC78:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x8222bc84
	if (!ctx.cr6.gt) goto loc_8222BC84;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
loc_8222BC84:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lfs f3,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x82229550
	ctx.lr = 0x8222BC98;
	sub_82229550(ctx, base);
	// lfs f0,22972(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 22972);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8222bcb8
	if (!ctx.cr6.lt) goto loc_8222BCB8;
loc_8222BCA8:
	// lwz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8222bc18
	if (ctx.cr6.lt) goto loc_8222BC18;
loc_8222BCB8:
	// lbz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 164);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8222bcdc
	if (!ctx.cr0.eq) goto loc_8222BCDC;
	// lbz r11,152(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 152);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8222ba94
	if (ctx.cr0.eq) goto loc_8222BA94;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,164(r31)
	REX_STORE_U8(ctx.r31.u32 + 164, ctx.r11.u8);
	// b 0x8222ba94
	goto loc_8222BA94;
loc_8222BCDC:
	// lfs f0,168(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,168(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 168, temp.u32);
	// fnmsubs f0,f13,f0,f30
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f0.f64, -ctx.f30.f64)));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8222bd04
	if (!ctx.cr6.lt) goto loc_8222BD04;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// b 0x8222bd10
	goto loc_8222BD10;
loc_8222BD04:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x8222bd10
	if (!ctx.cr6.gt) goto loc_8222BD10;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
loc_8222BD10:
	// lfs f12,3420(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 3420);
	ctx.f12.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stfs f0,172(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 172, temp.u32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x8222bd28
	if (ctx.cr6.lt) goto loc_8222BD28;
loc_8222BD24:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8222BD28:
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

DEFINE_REX_FUNC(sub_822494E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// addi r11,r1,-32
	ctx.r11.s64 = ctx.r1.s64 + -32;
	// stfs f1,-32(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// stfs f1,-28(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// stfs f1,-16(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f1,-20(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// addi r8,r1,-32
	ctx.r8.s64 = ctx.r1.s64 + -32;
	// stfs f1,-24(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// lwz r7,4(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f1,-4(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// stfs f1,-8(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f1,-12(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
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
	// std r11,32(r3)
	REX_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// stfs f1,40(r7)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r7.u32 + 40, temp.u32);
	// stfs f1,44(r7)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r7.u32 + 44, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8224C440) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x8224C448;
	__savegprlr_14(ctx, base);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r22,0
	ctx.r22.s64 = 0;
	// stw r3,372(r1)
	REX_STORE_U32(ctx.r1.u32 + 372, ctx.r3.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r3,52
	ctx.r30.s64 = ctx.r3.s64 + 52;
	// stw r22,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r22.u32);
	// li r31,2
	ctx.r31.s64 = 2;
	// stw r22,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r22.u32);
	// stw r22,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r22.u32);
	// stw r22,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r22.u32);
	// stw r22,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r22.u32);
	// stw r22,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r22.u32);
	// stw r22,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r22.u32);
loc_8224C47C:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,28
	ctx.r5.s64 = 28;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x8224C48C;
	sub_8273A030(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r30,r30,28
	ctx.r30.s64 = ctx.r30.s64 + 28;
	// bne 0x8224c47c
	if (!ctx.cr0.eq) goto loc_8224C47C;
	// stw r22,108(r29)
	REX_STORE_U32(ctx.r29.u32 + 108, ctx.r22.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stw r22,112(r29)
	REX_STORE_U32(ctx.r29.u32 + 112, ctx.r22.u32);
	// stw r22,116(r29)
	REX_STORE_U32(ctx.r29.u32 + 116, ctx.r22.u32);
	// stw r22,120(r29)
	REX_STORE_U32(ctx.r29.u32 + 120, ctx.r22.u32);
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r10,172(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// lwz r9,4(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// rlwinm r11,r9,4,12,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8224c4d4
	if (ctx.cr6.eq) goto loc_8224C4D4;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x8224c4d8
	goto loc_8224C4D8;
loc_8224C4D4:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_8224C4D8:
	// stw r11,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8224c970
	if (ctx.cr6.eq) goto loc_8224C970;
	// lwz r11,2504(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2504);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// beq cr6,0x8224c970
	if (ctx.cr6.eq) goto loc_8224C970;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r21,r11,5436
	ctx.r21.s64 = ctx.r11.s64 + 5436;
	// addi r31,r29,64
	ctx.r31.s64 = ctx.r29.s64 + 64;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lis r27,-32114
	ctx.r27.s64 = -2104623104;
	// stw r21,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r21.u32);
	// lis r28,-32114
	ctx.r28.s64 = -2104623104;
	// lis r29,-32114
	ctx.r29.s64 = -2104623104;
	// lis r30,-32114
	ctx.r30.s64 = -2104623104;
	// lis r3,-32114
	ctx.r3.s64 = -2104623104;
	// lis r4,-32114
	ctx.r4.s64 = -2104623104;
	// lis r5,-32114
	ctx.r5.s64 = -2104623104;
	// lis r6,-32114
	ctx.r6.s64 = -2104623104;
	// lis r7,-32114
	ctx.r7.s64 = -2104623104;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r26,-32227
	ctx.r26.s64 = -2112028672;
	// lis r25,-32114
	ctx.r25.s64 = -2104623104;
	// lis r24,-32114
	ctx.r24.s64 = -2104623104;
	// lis r23,-32114
	ctx.r23.s64 = -2104623104;
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r27,r27,11376
	ctx.r27.s64 = ctx.r27.s64 + 11376;
	// addi r28,r28,11360
	ctx.r28.s64 = ctx.r28.s64 + 11360;
	// addi r29,r29,11344
	ctx.r29.s64 = ctx.r29.s64 + 11344;
	// stw r27,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r27.u32);
	// addi r30,r30,11328
	ctx.r30.s64 = ctx.r30.s64 + 11328;
	// stw r28,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r28.u32);
	// addi r3,r3,11312
	ctx.r3.s64 = ctx.r3.s64 + 11312;
	// stw r29,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// addi r4,r4,11296
	ctx.r4.s64 = ctx.r4.s64 + 11296;
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// addi r5,r5,11280
	ctx.r5.s64 = ctx.r5.s64 + 11280;
	// stw r3,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// addi r6,r6,11264
	ctx.r6.s64 = ctx.r6.s64 + 11264;
	// stw r4,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// addi r7,r7,11248
	ctx.r7.s64 = ctx.r7.s64 + 11248;
	// stw r5,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// addi r11,r11,11472
	ctx.r11.s64 = ctx.r11.s64 + 11472;
	// stw r6,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// addi r17,r26,-24072
	ctx.r17.s64 = ctx.r26.s64 + -24072;
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// addi r16,r25,11456
	ctx.r16.s64 = ctx.r25.s64 + 11456;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r15,r24,11440
	ctx.r15.s64 = ctx.r24.s64 + 11440;
	// addi r14,r23,11424
	ctx.r14.s64 = ctx.r23.s64 + 11424;
	// addi r20,r8,11232
	ctx.r20.s64 = ctx.r8.s64 + 11232;
	// addi r19,r9,11392
	ctx.r19.s64 = ctx.r9.s64 + 11392;
	// addi r18,r10,11408
	ctx.r18.s64 = ctx.r10.s64 + 11408;
	// b 0x8224c5c4
	goto loc_8224C5C4;
loc_8224C5C0:
	// lwz r21,80(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8224C5C4:
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8224c5d8
	if (!ctx.cr6.eq) goto loc_8224C5D8;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x8224c5e4
	goto loc_8224C5E4;
loc_8224C5D8:
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_8224C5E4:
	// stw r11,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r11.u32);
	// addi r21,r31,-4
	ctx.r21.s64 = ctx.r31.s64 + -4;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8224c60c
	if (ctx.cr6.eq) goto loc_8224C60C;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r17
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r17.u32);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x8224c614
	if (!ctx.cr6.eq) goto loc_8224C614;
loc_8224C60C:
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x8224c624
	goto loc_8224C624;
loc_8224C614:
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_8224C624:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r9,-12816(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r9,172(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 172);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8224c928
	if (!ctx.cr6.eq) goto loc_8224C928;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8224c928
	if (ctx.cr6.eq) goto loc_8224C928;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224C664;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,-8(r21)
	REX_STORE_U32(ctx.r21.u32 + -8, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224C67C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,0(r21)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// stw r7,-4(r21)
	REX_STORE_U32(ctx.r21.u32 + -4, ctx.r7.u32);
	// bl 0x823b47e8
	ctx.lr = 0x8224C68C;
	sub_823B47E8(ctx, base);
	// cmplwi cr6,r3,77
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 77, ctx.xer);
	// bne cr6,0x8224c69c
	if (!ctx.cr6.eq) goto loc_8224C69C;
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C69C:
	// cmplwi cr6,r3,72
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 72, ctx.xer);
	// beq cr6,0x8224c8ec
	if (ctx.cr6.eq) goto loc_8224C8EC;
	// cmpwi cr6,r7,12
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 12, ctx.xer);
	// beq cr6,0x8224c8e4
	if (ctx.cr6.eq) goto loc_8224C8E4;
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// beq cr6,0x8224c894
	if (ctx.cr6.eq) goto loc_8224C894;
	// lwz r11,64(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// lwz r10,60(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224c85c
	if (ctx.cr0.eq) goto loc_8224C85C;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8224c85c
	if (ctx.cr6.eq) goto loc_8224C85C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224C6EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224C6FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// bl 0x823bd0f0
	ctx.lr = 0x8224C708;
	sub_823BD0F0(ctx, base);
	// lhz r23,33(r3)
	ctx.r23.u64 = REX_LOAD_U16(ctx.r3.u32 + 33);
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi r23,0
	ctx.cr0.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq 0x8224c848
	if (ctx.cr0.eq) goto loc_8224C848;
	// addi r26,r31,-64
	ctx.r26.s64 = ctx.r31.s64 + -64;
	// li r24,0
	ctx.r24.s64 = 0;
loc_8224C720:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823bd0f0
	ctx.lr = 0x8224C72C;
	sub_823BD0F0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8224c73c
	if (!ctx.cr0.eq) goto loc_8224C73C;
loc_8224C734:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8224c780
	goto loc_8224C780;
loc_8224C73C:
	// lhz r11,33(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 33);
	// cmplw cr6,r25,r11
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8224c734
	if (!ctx.cr6.lt) goto loc_8224C734;
	// lwz r11,12(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8224c778
	if (ctx.cr6.eq) goto loc_8224C778;
	// lhz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8224c778
	if (ctx.cr0.eq) goto loc_8224C778;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8224c778
	if (ctx.cr6.eq) goto loc_8224C778;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8224c77c
	goto loc_8224C77C;
loc_8224C778:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8224C77C:
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
loc_8224C780:
	// lhz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82248dd8
	ctx.lr = 0x8224C790;
	sub_82248DD8(ctx, base);
	// clrlwi. r28,r3,16
	ctx.r28.u64 = ctx.r3.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// li r30,0
	ctx.r30.s64 = 0;
	// beq 0x8224c828
	if (ctx.cr0.eq) goto loc_8224C828;
loc_8224C79C:
	// li r7,0
	ctx.r7.s64 = 0;
	// clrlwi r6,r30,16
	ctx.r6.u64 = ctx.r30.u32 & 0xFFFF;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823beeb8
	ctx.lr = 0x8224C7B4;
	sub_823BEEB8(ctx, base);
	// clrlwi. r10,r22,24
	ctx.r10.u64 = ctx.r22.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,8(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r7,12(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// stw r7,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// lwz r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// bne 0x8224c7f8
	if (!ctx.cr0.eq) goto loc_8224C7F8;
	// lwz r10,152(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// li r22,1
	ctx.r22.s64 = 1;
	// stw r11,64(r26)
	REX_STORE_U32(ctx.r26.u32 + 64, ctx.r11.u32);
	// stw r10,72(r26)
	REX_STORE_U32(ctx.r26.u32 + 72, ctx.r10.u32);
	// b 0x8224c81c
	goto loc_8224C81C;
loc_8224C7F8:
	// lwz r10,64(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 64);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8224c808
	if (!ctx.cr6.lt) goto loc_8224C808;
	// stw r11,64(r26)
	REX_STORE_U32(ctx.r26.u32 + 64, ctx.r11.u32);
loc_8224C808:
	// lwz r10,72(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 72);
	// lwz r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8224c81c
	if (!ctx.cr6.gt) goto loc_8224C81C;
	// stw r11,72(r26)
	REX_STORE_U32(ctx.r26.u32 + 72, ctx.r11.u32);
loc_8224C81C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x8224c79c
	if (ctx.cr6.lt) goto loc_8224C79C;
loc_8224C828:
	// li r11,-28
	ctx.r11.s64 = -28;
	// li r10,28
	ctx.r10.s64 = 28;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stw r11,8(r21)
	REX_STORE_U32(ctx.r21.u32 + 8, ctx.r11.u32);
	// stw r10,16(r21)
	REX_STORE_U32(ctx.r21.u32 + 16, ctx.r10.u32);
	// addi r24,r24,21
	ctx.r24.s64 = ctx.r24.s64 + 21;
	// cmplw cr6,r25,r23
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r23.u32, ctx.xer);
	// blt cr6,0x8224c720
	if (ctx.cr6.lt) goto loc_8224C720;
loc_8224C848:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r22,0
	ctx.r22.s64 = 0;
	// lwz r10,12(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 12);
	// subf. r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8224c928
	if (!ctx.cr0.eq) goto loc_8224C928;
loc_8224C85C:
	// lwz r11,-4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -4);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 18, ctx.xer);
	// bgt cr6,0x8224c904
	if (ctx.cr6.gt) goto loc_8224C904;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-6680
	ctx.r12.s64 = ctx.r12.s64 + -6680;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// lis r12,-32219
	ctx.r12.s64 = -2111504384;
	// nop 
	// addi r12,r12,-14188
	ctx.r12.s64 = ctx.r12.s64 + -14188;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8224C894;
	case 1:
		goto loc_8224C89C;
	case 2:
		goto loc_8224C904;
	case 3:
		goto loc_8224C8A4;
	case 4:
		goto loc_8224C8AC;
	case 5:
		goto loc_8224C8B4;
	case 6:
		goto loc_8224C8BC;
	case 7:
		goto loc_8224C8C4;
	case 8:
		goto loc_8224C8CC;
	case 9:
		goto loc_8224C8D4;
	case 10:
		goto loc_8224C8DC;
	case 11:
		goto loc_8224C8E4;
	case 12:
		goto loc_8224C904;
	case 13:
		goto loc_8224C904;
	case 14:
		goto loc_8224C904;
	case 15:
		goto loc_8224C904;
	case 16:
		goto loc_8224C8EC;
	case 17:
		goto loc_8224C8F4;
	case 18:
		goto loc_8224C8FC;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8224C894:
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C89C:
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8A4:
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8AC:
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8B4:
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8BC:
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8C4:
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8CC:
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8D4:
	// lwz r11,124(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8DC:
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8E4:
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8EC:
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8F4:
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C8FC:
	// mr r11,r15
	ctx.r11.u64 = ctx.r15.u64;
	// b 0x8224c908
	goto loc_8224C908;
loc_8224C904:
	// mr r11,r16
	ctx.r11.u64 = ctx.r16.u64;
loc_8224C908:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r8,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_8224C928:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r31,r31,28
	ctx.r31.s64 = ctx.r31.s64 + 28;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bne 0x8224c5c0
	if (!ctx.cr0.eq) goto loc_8224C5C0;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,372(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r9,32(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// stw r9,108(r10)
	REX_STORE_U32(ctx.r10.u32 + 108, ctx.r9.u32);
	// lwz r9,36(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// stw r9,112(r10)
	REX_STORE_U32(ctx.r10.u32 + 112, ctx.r9.u32);
	// lwz r9,40(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// stw r9,116(r10)
	REX_STORE_U32(ctx.r10.u32 + 116, ctx.r9.u32);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// stw r11,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r11.u32);
loc_8224C970:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8227E3D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8227E3E0;
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
	// beq 0x8227e474
	if (ctx.cr0.eq) goto loc_8227E474;
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
	ctx.lr = 0x8227E410;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ori r11,r11,62460
	ctx.r11.u64 = ctx.r11.u64 | 62460;
	// bne 0x8227e440
	if (!ctx.cr0.eq) goto loc_8227E440;
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
	// bne cr6,0x8227e440
	if (!ctx.cr6.eq) goto loc_8227E440;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x8227e464
	goto loc_8227E464;
loc_8227E440:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8227e474
	if (!ctx.cr6.eq) goto loc_8227E474;
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
	// bne cr6,0x8227e474
	if (!ctx.cr6.eq) goto loc_8227E474;
	// li r5,0
	ctx.r5.s64 = 0;
loc_8227E464:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8228a4c0
	ctx.lr = 0x8227E470;
	sub_8228A4C0(ctx, base);
	// b 0x8227e4d8
	goto loc_8227E4D8;
loc_8227E474:
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
	// bne 0x8227e4d0
	if (!ctx.cr0.eq) goto loc_8227E4D0;
	// li r9,1
	ctx.r9.s64 = 1;
	// bl 0x82236c80
	ctx.lr = 0x8227E4AC;
	sub_82236C80(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14376(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f13,152(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8227e4d8
	if (!ctx.cr6.lt) goto loc_8227E4D8;
	// stfs f0,152(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 152, temp.u32);
	// b 0x8227e4d8
	goto loc_8227E4D8;
loc_8227E4D0:
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x82236c80
	ctx.lr = 0x8227E4D8;
	sub_82236C80(ctx, base);
loc_8227E4D8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8228B368) {
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
	// ori r4,r4,63628
	ctx.r4.u64 = ctx.r4.u64 | 63628;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8228B390;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8228b3a0
	if (ctx.cr0.eq) goto loc_8228B3A0;
	// bl 0x8228aa98
	ctx.lr = 0x8228B39C;
	sub_8228AA98(ctx, base);
	// b 0x8228b3a4
	goto loc_8228B3A4;
loc_8228B3A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8228B3A4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8228BB50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8228BB58;
	__savegprlr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// li r11,24
	ctx.r11.s64 = 24;
	// addi r30,r30,-3164
	ctx.r30.s64 = ctx.r30.s64 + -3164;
	// subfc r11,r11,r4
	ctx.xer.ca = ctx.r4.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r27,1
	ctx.r27.s64 = 1;
	// and r28,r11,r4
	ctx.r28.u64 = ctx.r11.u64 & ctx.r4.u64;
	// cmplwi cr6,r10,13
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 13, ctx.xer);
	// bne cr6,0x8228bb98
	if (!ctx.cr6.eq) goto loc_8228BB98;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,63332
	ctx.r11.u64 = ctx.r11.u64 | 63332;
	// stbx r27,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r27.u8);
loc_8228BB98:
	// bl 0x824281d8
	ctx.lr = 0x8228BB9C;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8228bdd0
	if (ctx.cr0.eq) goto loc_8228BDD0;
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8228bdd0
	if (!ctx.cr0.eq) goto loc_8228BDD0;
	// bl 0x8242a5e0
	ctx.lr = 0x8228BBB0;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8228bbc0
	if (!ctx.cr0.eq) goto loc_8228BBC0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8228bbc4
	goto loc_8228BBC4;
loc_8228BBC0:
	// bl 0x8242aa28
	ctx.lr = 0x8228BBC4;
	sub_8242AA28(ctx, base);
loc_8228BBC4:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8228bbe4
	if (ctx.cr0.eq) goto loc_8228BBE4;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2848
	ctx.r11.s64 = ctx.r11.s64 + -2848;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x8228be28
	if (!ctx.cr6.eq) goto loc_8228BE28;
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
loc_8228BBE4:
	// lis r11,0
	ctx.r11.s64 = 0;
	// stw r27,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r27.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// ori r11,r11,62384
	ctx.r11.u64 = ctx.r11.u64 | 62384;
	// ori r10,r10,62376
	ctx.r10.u64 = ctx.r10.u64 | 62376;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f0,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x8242a5e0
	ctx.lr = 0x8228BC10;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8228bc20
	if (!ctx.cr0.eq) goto loc_8228BC20;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8228bc24
	goto loc_8228BC24;
loc_8228BC20:
	// bl 0x8242aa28
	ctx.lr = 0x8228BC24;
	sub_8242AA28(ctx, base);
loc_8228BC24:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8228be28
	if (ctx.cr0.eq) goto loc_8228BE28;
	// bl 0x82429a18
	ctx.lr = 0x8228BC30;
	sub_82429A18(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,20068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r9,63384
	ctx.r11.u64 = ctx.r9.u64 | 63384;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stbx r28,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r28.u8);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// ori r10,r10,63380
	ctx.r10.u64 = ctx.r10.u64 | 63380;
	// addi r30,r30,-2160
	ctx.r30.s64 = ctx.r30.s64 + -2160;
	// sth r27,0(r30)
	REX_STORE_U16(ctx.r30.u32 + 0, ctx.r27.u16);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stwx r6,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r6.u32);
	// lfs f0,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
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
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x82428150
	ctx.lr = 0x8228BCD0;
	sub_82428150(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// ori r11,r11,63388
	ctx.r11.u64 = ctx.r11.u64 | 63388;
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x82429960
	ctx.lr = 0x8228BCE8;
	sub_82429960(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,63392
	ctx.r11.u64 = ctx.r11.u64 | 63392;
	// ori r10,r10,62488
	ctx.r10.u64 = ctx.r10.u64 | 62488;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// ori r9,r9,62484
	ctx.r9.u64 = ctx.r9.u64 | 62484;
	// stbx r3,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u8);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfsx f0,r31,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfsx f13,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
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
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x82428150
	ctx.lr = 0x8228BD68;
	sub_82428150(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// ori r11,r10,63396
	ctx.r11.u64 = ctx.r10.u64 | 63396;
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
	// bl 0x825a4a90
	ctx.lr = 0x8228BD88;
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
	ctx.lr = 0x8228BD9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// ori r11,r11,63400
	ctx.r11.u64 = ctx.r11.u64 | 63400;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,10
	ctx.r3.s64 = 10;
	// stwx r29,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r29.u32);
	// bl 0x82429ff8
	ctx.lr = 0x8228BDC0;
	sub_82429FF8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a48b0
	ctx.lr = 0x8228BDCC;
	sub_825A48B0(ctx, base);
	// b 0x8228be28
	goto loc_8228BE28;
loc_8228BDD0:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62380
	ctx.r11.u64 = ctx.r11.u64 | 62380;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8228be00
	if (ctx.cr0.eq) goto loc_8228BE00;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// li r10,22
	ctx.r10.s64 = 22;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
	// b 0x8228be28
	goto loc_8228BE28;
loc_8228BE00:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8228be28
	if (ctx.cr6.eq) goto loc_8228BE28;
	// cmplwi cr6,r28,24
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 24, ctx.xer);
	// bge cr6,0x8228be28
	if (!ctx.cr6.lt) goto loc_8228BE28;
	// lis r11,0
	ctx.r11.s64 = 0;
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
loc_8228BE28:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822A5198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x822A51A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r11,22072
	ctx.r30.s64 = ctx.r11.s64 + 22072;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// ld r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// li r4,100
	ctx.r4.s64 = 100;
	// lfs f0,-29492(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,19212(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19212);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x822A51F4;
	sub_825E02A0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r29,r11,-4080
	ctx.r29.s64 = ctx.r11.s64 + -4080;
	// beq 0x822a5224
	if (ctx.cr0.eq) goto loc_822A5224;
	// lfs f0,-4740(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4740);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f13,2884(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2884);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x8221b560
	ctx.lr = 0x822A521C;
	sub_8221B560(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x822a5228
	goto loc_822A5228;
loc_822A5224:
	// li r31,0
	ctx.r31.s64 = 0;
loc_822A5228:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822a5284
	if (ctx.cr6.eq) goto loc_822A5284;
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
	ctx.lr = 0x822A5248;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32214
	ctx.r11.s64 = -2111176704;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r11,r11,-28152
	ctx.r11.s64 = ctx.r11.s64 + -28152;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// bl 0x82222ad8
	ctx.lr = 0x822A5260;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822a5284
	if (!ctx.cr6.eq) goto loc_822A5284;
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
	ctx.lr = 0x822A5284;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822A5284:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r4,100
	ctx.r4.s64 = 100;
	// bl 0x825e02a0
	ctx.lr = 0x822A5294;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822a52b8
	if (ctx.cr0.eq) goto loc_822A52B8;
	// lfs f0,-4740(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4740);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f13,1072(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1072);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x8221b560
	ctx.lr = 0x822A52B0;
	sub_8221B560(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x822a52bc
	goto loc_822A52BC;
loc_822A52B8:
	// li r31,0
	ctx.r31.s64 = 0;
loc_822A52BC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822a5318
	if (ctx.cr6.eq) goto loc_822A5318;
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
	ctx.lr = 0x822A52DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32214
	ctx.r11.s64 = -2111176704;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r11,r11,-27752
	ctx.r11.s64 = ctx.r11.s64 + -27752;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// bl 0x82222ad8
	ctx.lr = 0x822A52F4;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822a5318
	if (!ctx.cr6.eq) goto loc_822A5318;
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
	ctx.lr = 0x822A5318;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822A5318:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822B2A28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x822B2A30;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r3,260
	ctx.r29.s64 = ctx.r3.s64 + 260;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r27,2
	ctx.r27.s64 = 2;
	// ori r28,r11,62392
	ctx.r28.u64 = ctx.r11.u64 | 62392;
loc_822B2A4C:
	// lwz r10,8(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r9,4(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x822b2a94
	if (!ctx.cr6.lt) goto loc_822B2A94;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r9,r31,r28
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r28.u32);
	// subfic r9,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// subfe r11,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r11,r27
	ctx.r4.u64 = ctx.r11.u64 & ctx.r27.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822B2A94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822B2A94:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 27, ctx.xer);
	// blt cr6,0x822b2a4c
	if (ctx.cr6.lt) goto loc_822B2A4C;
	// addi r29,r31,244
	ctx.r29.s64 = ctx.r31.s64 + 244;
	// li r30,0
	ctx.r30.s64 = 0;
loc_822B2AA8:
	// lwz r10,8(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r9,4(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x822b2af0
	if (!ctx.cr6.lt) goto loc_822B2AF0;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r9,r31,r28
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r28.u32);
	// subfic r9,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// subfe r11,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r11,r27
	ctx.r4.u64 = ctx.r11.u64 & ctx.r27.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822B2AF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822B2AF0:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 3, ctx.xer);
	// blt cr6,0x822b2aa8
	if (ctx.cr6.lt) goto loc_822B2AA8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822B6858) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x822B6860;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r28,r11,10020
	ctx.r28.s64 = ctx.r11.s64 + 10020;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82232c30
	ctx.lr = 0x822B687C;
	sub_82232C30(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-17388
	ctx.r11.s64 = ctx.r11.s64 + -17388;
	// addi r30,r30,-3160
	ctx.r30.s64 = ctx.r30.s64 + -3160;
	// addi r29,r11,4
	ctx.r29.s64 = ctx.r11.s64 + 4;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r27,3
	ctx.r27.s64 = 3;
	// addi r26,r11,22072
	ctx.r26.s64 = ctx.r11.s64 + 22072;
loc_822B689C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// li r4,84
	ctx.r4.s64 = 84;
	// bl 0x825e02a0
	ctx.lr = 0x822B68AC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822b68c0
	if (ctx.cr0.eq) goto loc_822B68C0;
	// bl 0x8222f918
	ctx.lr = 0x822B68B8;
	sub_8222F918(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x822b68c4
	goto loc_822B68C4;
loc_822B68C0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_822B68C4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// clrlwi r5,r10,16
	ctx.r5.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822B68E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822B6900;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822b6914
	if (!ctx.cr6.eq) goto loc_822B6914;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x822b6920
	goto loc_822B6920;
loc_822B6914:
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_822B6920:
	// lwz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x822b6944
	if (!ctx.cr6.lt) goto loc_822B6944;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r31,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r31.u32);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// b 0x822b6950
	goto loc_822B6950;
loc_822B6944:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823849b0
	ctx.lr = 0x822B6950;
	sub_823849B0(ctx, base);
loc_822B6950:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// bne 0x822b689c
	if (!ctx.cr0.eq) goto loc_822B689C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822BF338) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r11,r11,32544
	ctx.r11.s64 = ctx.r11.s64 + 32544;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lfs f13,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r31,-3036
	ctx.r31.s64 = ctx.r31.s64 + -3036;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,0(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// lfs f0,-30128(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// li r4,100
	ctx.r4.s64 = 100;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// lwz r30,100(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x825e02a0
	ctx.lr = 0x822BF3CC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822bf420
	if (ctx.cr0.eq) goto loc_822BF420;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f12,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r30,1
	ctx.r8.s64 = ctx.r30.s64 + 1;
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f0,-11144(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11144);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r7,-4080
	ctx.r11.s64 = ctx.r7.s64 + -4080;
	// lfs f13,14280(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14280);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f1,244(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 244);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82218490
	ctx.lr = 0x822BF418;
	sub_82218490(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x822bf424
	goto loc_822BF424;
loc_822BF420:
	// li r31,0
	ctx.r31.s64 = 0;
loc_822BF424:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822bf468
	if (ctx.cr6.eq) goto loc_822BF468;
	// lis r11,-32212
	ctx.r11.s64 = -2111045632;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r11,r11,-2944
	ctx.r11.s64 = ctx.r11.s64 + -2944;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// bl 0x82222ad8
	ctx.lr = 0x822BF444;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822bf468
	if (!ctx.cr6.eq) goto loc_822BF468;
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
	ctx.lr = 0x822BF468;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822BF468:
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

DEFINE_REX_FUNC(sub_822C8010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x822C8018;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// addi r27,r27,-3156
	ctx.r27.s64 = ctx.r27.s64 + -3156;
	// addi r30,r30,-3128
	ctx.r30.s64 = ctx.r30.s64 + -3128;
	// li r22,-1
	ctx.r22.s64 = -1;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r11,285(r3)
	REX_STORE_U8(ctx.r3.u32 + 285, ctx.r11.u8);
	// stw r22,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r22.u32);
	// lwz r5,8(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x822c8074
	if (ctx.cr6.eq) goto loc_822C8074;
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
	// ble 0x822c8070
	if (!ctx.cr0.gt) goto loc_822C8070;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x822C8070;
	sub_827388E8(ctx, base);
loc_822C8070:
	// stw r29,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r29.u32);
loc_822C8074:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r25,r25,-3160
	ctx.r25.s64 = ctx.r25.s64 + -3160;
	// addi r9,r11,12236
	ctx.r9.s64 = ctx.r11.s64 + 12236;
	// ld r10,2880(r10)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r10.u32 + 2880);
	// li r26,0
	ctx.r26.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// ori r24,r8,62388
	ctx.r24.u64 = ctx.r8.u64 | 62388;
	// lfs f31,232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// stfs f31,288(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// li r23,1
	ctx.r23.s64 = 1;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// std r10,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r10.u64);
	// bgt cr6,0x822c8214
	if (ctx.cr6.gt) goto loc_822C8214;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x822c814c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822C814C;
	// bdzf 4*cr6+eq,0x822c8178
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822C8178;
	// bdzf 4*cr6+eq,0x822c81b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822C81B0;
	// bdzf 4*cr6+eq,0x822c81e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822C81E8;
	// bdzf 4*cr6+eq,0x822c81b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822C81B0;
	// bdzf 4*cr6+eq,0x822c81bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822C81BC;
	// bne cr6,0x822c81f8
	if (!ctx.cr6.eq) goto loc_822C81F8;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// ori r10,r10,62385
	ctx.r10.u64 = ctx.r10.u64 | 62385;
	// addi r11,r11,4440
	ctx.r11.s64 = ctx.r11.s64 + 4440;
	// lbzx r10,r31,r10
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822c8104
	if (ctx.cr0.eq) goto loc_822C8104;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// b 0x822c8108
	goto loc_822C8108;
loc_822C8104:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
loc_822C8108:
	// lfs f0,-2832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2832);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_822C8118:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822c9aa0
	ctx.lr = 0x822C8120;
	sub_822C9AA0(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,25440
	ctx.r4.s64 = ctx.r11.s64 + 25440;
	// bl 0x822c9aa0
	ctx.lr = 0x822C8130;
	sub_822C9AA0(ctx, base);
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822c9aa0
	ctx.lr = 0x822C8140;
	sub_822C9AA0(ctx, base);
	// li r28,1
	ctx.r28.s64 = 1;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// b 0x822c8214
	goto loc_822C8214;
loc_822C814C:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,25444
	ctx.r4.s64 = ctx.r11.s64 + 25444;
	// bl 0x822c9aa0
	ctx.lr = 0x822C815C;
	sub_822C9AA0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,-19108
	ctx.r4.s64 = ctx.r11.s64 + -19108;
	// bl 0x822c9aa0
	ctx.lr = 0x822C816C;
	sub_822C9AA0(ctx, base);
	// li r28,1
	ctx.r28.s64 = 1;
	// li r29,1
	ctx.r29.s64 = 1;
	// b 0x822c8214
	goto loc_822C8214;
loc_822C8178:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,25444
	ctx.r4.s64 = ctx.r11.s64 + 25444;
	// bl 0x822c9aa0
	ctx.lr = 0x822C8188;
	sub_822C9AA0(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,25448
	ctx.r4.s64 = ctx.r11.s64 + 25448;
	// bl 0x822c9aa0
	ctx.lr = 0x822C8198;
	sub_822C9AA0(ctx, base);
	// li r28,1
	ctx.r28.s64 = 1;
	// li r23,2
	ctx.r23.s64 = 2;
	// li r29,1
	ctx.r29.s64 = 1;
loc_822C81A4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822c9130
	ctx.lr = 0x822C81AC;
	sub_822C9130(ctx, base);
	// b 0x822c8214
	goto loc_822C8214;
loc_822C81B0:
	// stw r26,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r26.u32);
	// li r29,2
	ctx.r29.s64 = 2;
	// b 0x822c81a4
	goto loc_822C81A4;
loc_822C81BC:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lwzx r29,r31,r24
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// addi r30,r30,-3136
	ctx.r30.s64 = ctx.r30.s64 + -3136;
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822c8214
	if (ctx.cr6.eq) goto loc_822C8214;
	// bl 0x8246ec58
	ctx.lr = 0x822C81E0;
	sub_8246EC58(ctx, base);
	// stw r26,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r26.u32);
	// b 0x822c8214
	goto loc_822C8214;
loc_822C81E8:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-19108
	ctx.r11.s64 = ctx.r11.s64 + -19108;
	// addi r4,r11,-4
	ctx.r4.s64 = ctx.r11.s64 + -4;
	// b 0x822c8118
	goto loc_822C8118;
loc_822C81F8:
	// stb r26,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r26.u8);
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
	ctx.lr = 0x822C8214;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822C8214:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lbz r9,466(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 466);
	// addi r10,r10,-3164
	ctx.r10.s64 = ctx.r10.s64 + -3164;
	// stw r22,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r22.u32);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// beq 0x822c8250
	if (ctx.cr0.eq) goto loc_822C8250;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x822c8250
	if (ctx.cr6.eq) goto loc_822C8250;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// beq cr6,0x822c8250
	if (ctx.cr6.eq) goto loc_822C8250;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
loc_822C8250:
	// lwzx r11,r31,r24
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// add r30,r31,r24
	ctx.r30.u64 = ctx.r31.u64 + ctx.r24.u64;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x822c8290
	if (ctx.cr6.eq) goto loc_822C8290;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// beq cr6,0x822c8290
	if (ctx.cr6.eq) goto loc_822C8290;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// clrlwi r4,r29,16
	ctx.r4.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822C828C;
	sub_8224A2A0(ctx, base);
	// stw r29,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
loc_822C8290:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822D4418) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x822D4420;
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
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r9,r10,17092
	ctx.r9.s64 = ctx.r10.s64 + 17092;
	// addi r11,r11,-3100
	ctx.r11.s64 = ctx.r11.s64 + -3100;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lfs f0,17092(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17092);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-18652(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18652);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f1,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f1.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822d4460
	if (!ctx.cr6.gt) goto loc_822D4460;
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_822D4460:
	// addis r28,r30,1
	ctx.r28.s64 = ctx.r30.s64 + 65536;
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// addi r28,r28,-3076
	ctx.r28.s64 = ctx.r28.s64 + -3076;
	// addi r31,r31,-3120
	ctx.r31.s64 = ctx.r31.s64 + -3120;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fsubs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// stfs f0,0(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// lfs f30,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x822D4494;
	sub_8222FF78(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addis r29,r30,1
	ctx.r29.s64 = ctx.r30.s64 + 65536;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r29,-3144
	ctx.r29.s64 = ctx.r29.s64 + -3144;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
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
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// bl 0x8231e0d8
	ctx.lr = 0x822D454C;
	sub_8231E0D8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r27,r11,12468
	ctx.r27.s64 = ctx.r11.s64 + 12468;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// fcmpu cr6,f30,f31
	ctx.cr6.compare(ctx.f30.f64, ctx.f31.f64);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// ble cr6,0x822d45b4
	if (!ctx.cr6.gt) goto loc_822D45B4;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x822d45ac
	if (ctx.cr6.lt) goto loc_822D45AC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D45AC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822d45fc
	if (!ctx.cr0.eq) goto loc_822D45FC;
loc_822D45B4:
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f30.f64, ctx.f31.f64);
	// bge cr6,0x822d4618
	if (!ctx.cr6.lt) goto loc_822D4618;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r31)
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
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x822d45f4
	if (ctx.cr6.gt) goto loc_822D45F4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D45F4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822d4618
	if (ctx.cr0.eq) goto loc_822D4618;
loc_822D45FC:
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d4730
	if (!ctx.cr6.eq) goto loc_822D4730;
	// stw r26,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
	// b 0x822d4730
	goto loc_822D4730;
loc_822D4618:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822d48c0
	ctx.lr = 0x822D4620;
	sub_822D48C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822d4730
	if (!ctx.cr0.eq) goto loc_822D4730;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f30,-2484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2484);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x822D4644;
	sub_8222FF78(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x822d6708
	ctx.lr = 0x822D464C;
	sub_822D6708(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f30.f64);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// blt cr6,0x822d465c
	if (ctx.cr6.lt) goto loc_822D465C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D465C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822d4680
	if (ctx.cr0.eq) goto loc_822D4680;
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d4730
	if (!ctx.cr6.eq) goto loc_822D4730;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x822d472c
	goto loc_822D472C;
loc_822D4680:
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x822d4730
	if (!ctx.cr6.lt) goto loc_822D4730;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,-232(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// ori r11,r11,62384
	ctx.r11.u64 = ctx.r11.u64 | 62384;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822d46bc
	if (!ctx.cr0.eq) goto loc_822D46BC;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62464
	ctx.r11.u64 = ctx.r11.u64 | 62464;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822d4730
	if (ctx.cr0.eq) goto loc_822D4730;
loc_822D46BC:
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r31,r31,-3128
	ctx.r31.s64 = ctx.r31.s64 + -3128;
	// bl 0x8222ff78
	ctx.lr = 0x822D46D8;
	sub_8222FF78(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x822d4858
	ctx.lr = 0x822D46E0;
	sub_822D4858(ctx, base);
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822D46FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d4730
	if (!ctx.cr6.eq) goto loc_822D4730;
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bne 0x822d4728
	if (!ctx.cr0.eq) goto loc_822D4728;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
loc_822D4728:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_822D472C:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_822D4730:
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

DEFINE_REX_FUNC(sub_822F64A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x822F64A8;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82429a18
	ctx.lr = 0x822F64B8;
	sub_82429A18(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r11,r11,62656
	ctx.r11.u64 = ctx.r11.u64 | 62656;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lwzx r5,r31,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwa r6,28(r5)
	ctx.r6.s64 = int32_t(REX_LOAD_U32(ctx.r5.u32 + 28));
	// lfs f0,20068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// std r6,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lwa r11,24(r5)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r5.u32 + 24));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x82428150
	ctx.lr = 0x822F6568;
	sub_82428150(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r9,40(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 40);
	// lis r5,0
	ctx.r5.s64 = 0;
	// ori r11,r11,62708
	ctx.r11.u64 = ctx.r11.u64 | 62708;
	// lhz r7,552(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 552);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stwx r6,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r6.u32);
	// ori r29,r5,62676
	ctx.r29.u64 = ctx.r5.u64 | 62676;
	// addi r3,r3,-2872
	ctx.r3.s64 = ctx.r3.s64 + -2872;
	// ori r28,r4,62680
	ctx.r28.u64 = ctx.r4.u64 | 62680;
	// ori r10,r10,62668
	ctx.r10.u64 = ctx.r10.u64 | 62668;
	// ori r8,r8,62672
	ctx.r8.u64 = ctx.r8.u64 | 62672;
	// stbx r30,r31,r29
	REX_STORE_U8(ctx.r31.u32 + ctx.r29.u32, ctx.r30.u8);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r7,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// li r5,20
	ctx.r5.s64 = 20;
	// stwx r9,r31,r28
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, ctx.r9.u32);
	// li r3,15
	ctx.r3.s64 = 15;
	// stwx r6,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r6.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stwx r11,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u32);
	// bl 0x82429ff8
	ctx.lr = 0x822F65D0;
	sub_82429FF8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822FDCB0) {
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
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3096
	ctx.r30.s64 = ctx.r30.s64 + -3096;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822fdda8
	if (ctx.cr6.eq) goto loc_822FDDA8;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x822fdda8
	if (!ctx.cr6.eq) goto loc_822FDDA8;
	// bl 0x82232628
	ctx.lr = 0x822FDCF4;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822fdda8
	if (!ctx.cr0.eq) goto loc_822FDDA8;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,-13032(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822fdd3c
	if (ctx.cr6.eq) goto loc_822FDD3C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lfs f0,64(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,60(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 60);
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
	// bl 0x823aefa8
	ctx.lr = 0x822FDD38;
	sub_823AEFA8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_822FDD3C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// ori r10,r10,62456
	ctx.r10.u64 = ctx.r10.u64 | 62456;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sthx r11,r31,r10
	REX_STORE_U16(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u16);
	// bl 0x82300990
	ctx.lr = 0x822FDD54;
	sub_82300990(ctx, base);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// lis r11,0
	ctx.r11.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r6,-32208
	ctx.r6.s64 = -2110783488;
	// lfs f0,12468(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,62536
	ctx.r11.u64 = ctx.r11.u64 | 62536;
	// ori r10,r10,62460
	ctx.r10.u64 = ctx.r10.u64 | 62460;
	// ori r9,r9,62472
	ctx.r9.u64 = ctx.r9.u64 | 62472;
	// ori r8,r8,62540
	ctx.r8.u64 = ctx.r8.u64 | 62540;
	// addi r7,r6,-8760
	ctx.r7.s64 = ctx.r6.s64 + -8760;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stwx r7,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r5,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r5.u8);
	// stbx r6,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r6.u8);
	// bl 0x822fddc8
	ctx.lr = 0x822FDDA8;
	sub_822FDDC8(ctx, base);
loc_822FDDA8:
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

DEFINE_REX_FUNC(sub_82302190) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82302198;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r31,-2992
	ctx.r31.s64 = ctx.r31.s64 + -2992;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82302204
	if (ctx.cr6.eq) goto loc_82302204;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x823021C4;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823021d4
	if (ctx.cr0.eq) goto loc_823021D4;
	// stb r29,84(r3)
	REX_STORE_U8(ctx.r3.u32 + 84, ctx.r29.u8);
	// stb r29,85(r3)
	REX_STORE_U8(ctx.r3.u32 + 85, ctx.r29.u8);
loc_823021D4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222c98
	ctx.lr = 0x823021E4;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823021fc
	if (ctx.cr0.eq) goto loc_823021FC;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x823021FC;
	sub_82222BB0(ctx, base);
loc_823021FC:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82302204:
	// addis r7,r30,1
	ctx.r7.s64 = ctx.r30.s64 + 65536;
	// addi r7,r7,-3048
	ctx.r7.s64 = ctx.r7.s64 + -3048;
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82302298
	if (ctx.cr6.eq) goto loc_82302298;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
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
	// bne cr6,0x82302248
	if (!ctx.cr6.eq) goto loc_82302248;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x8230224c
	if (!ctx.cr6.eq) goto loc_8230224C;
loc_82302248:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8230224C:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82302294
	if (ctx.cr0.eq) goto loc_82302294;
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82302294
	if (!ctx.cr6.eq) goto loc_82302294;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82302294
	if (ctx.cr6.eq) goto loc_82302294;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32181
	ctx.r9.s64 = -2109014016;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r9,r9,12352
	ctx.r9.s64 = ctx.r9.s64 + 12352;
	// stb r8,300(r11)
	REX_STORE_U8(ctx.r11.u32 + 300, ctx.r8.u8);
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,296(r11)
	REX_STORE_U32(ctx.r11.u32 + 296, ctx.r9.u32);
	// stfs f0,280(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 280, temp.u32);
loc_82302294:
	// stw r29,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r29.u32);
loc_82302298:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82308D50) {
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
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,140
	ctx.r4.s64 = 140;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82308D78;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82308d9c
	if (ctx.cr0.eq) goto loc_82308D9C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r4,r10,-25136
	ctx.r4.s64 = ctx.r10.s64 + -25136;
	// lfs f1,-832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -832);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82223b50
	ctx.lr = 0x82308D94;
	sub_82223B50(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82308da0
	goto loc_82308DA0;
loc_82308D9C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82308DA0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82308e4c
	if (ctx.cr6.eq) goto loc_82308E4C;
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
	ctx.lr = 0x82308DC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,11
	ctx.r11.s64 = 11;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// sth r11,102(r31)
	REX_STORE_U16(ctx.r31.u32 + 102, ctx.r11.u16);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,13600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13600);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,284(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 284);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82308DE4;
	sub_825A4A40(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82308DF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,255
	ctx.r11.s64 = 255;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f1,-1628(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1628);
	ctx.f1.f64 = double(temp.f32);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x82223bf0
	ctx.lr = 0x82308E2C;
	sub_82223BF0(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r10,91(r31)
	REX_STORE_U8(ctx.r31.u32 + 91, ctx.r10.u8);
	// beq cr6,0x82308e44
	if (ctx.cr6.eq) goto loc_82308E44;
	// stb r10,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r10.u8);
loc_82308E44:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x82308e50
	goto loc_82308E50;
loc_82308E4C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82308E50:
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

DEFINE_REX_FUNC(sub_8230CD50) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x825a4a90
	ctx.lr = 0x8230CD74;
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
	ctx.lr = 0x8230CD88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r3,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// li r10,5
	ctx.r10.s64 = 5;
	// divwu r10,r11,r10
	ctx.r10.u64 = uint32_t(ctx.r10.u32 ? ctx.r11.u32 / ctx.r10.u32 : 0);
	// mulli r10,r10,5
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(5));
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3024
	ctx.r11.s64 = ctx.r11.s64 + -3024;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bge cr6,0x8230cdcc
	if (!ctx.cr6.lt) goto loc_8230CDCC;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r10,r10,-18392
	ctx.r10.s64 = ctx.r10.s64 + -18392;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8230ce0c
	if (ctx.cr6.eq) goto loc_8230CE0C;
	// lis r7,-32207
	ctx.r7.s64 = -2110717952;
	// addi r7,r7,-18392
	ctx.r7.s64 = ctx.r7.s64 + -18392;
	// b 0x8230cde4
	goto loc_8230CDE4;
loc_8230CDCC:
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r10,r10,-15888
	ctx.r10.s64 = ctx.r10.s64 + -15888;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8230ce0c
	if (ctx.cr6.eq) goto loc_8230CE0C;
	// lis r7,-32207
	ctx.r7.s64 = -2110717952;
	// addi r7,r7,-15888
	ctx.r7.s64 = ctx.r7.s64 + -15888;
loc_8230CDE4:
	// lis r9,0
	ctx.r9.s64 = 0;
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// ori r9,r9,62516
	ctx.r9.u64 = ctx.r9.u64 | 62516;
	// ori r10,r10,62396
	ctx.r10.u64 = ctx.r10.u64 | 62396;
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f0,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stbx r6,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r6.u8);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
loc_8230CE0C:
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

DEFINE_REX_FUNC(sub_82311938) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82311940;
	__savegprlr_23(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af28
	ctx.lr = 0x82311948;
	__savefpr_28(ctx, base);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,13
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 13, ctx.xer);
	// blt cr6,0x82311964
	if (ctx.cr6.lt) goto loc_82311964;
	// li r29,12
	ctx.r29.s64 = 12;
loc_82311964:
	// lwz r10,264(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// mulli r11,r29,36
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(36));
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addis r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 65536;
	// addi r31,r31,-3160
	ctx.r31.s64 = ctx.r31.s64 + -3160;
	// lwz r11,116(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231198C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr. r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r27,r11,12468
	ctx.r27.s64 = ctx.r11.s64 + 12468;
	// lfs f28,-232(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -232);
	ctx.f28.f64 = double(temp.f32);
	// bne 0x823119a4
	if (!ctx.cr0.eq) goto loc_823119A4;
	// lfs f28,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f28.f64 = double(temp.f32);
loc_823119A4:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8222ff78
	ctx.lr = 0x823119B8;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x823119D4;
	sub_8222FF78(ctx, base);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// rlwinm r29,r29,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// lfs f30,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82311A08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r25,r11,-30128
	ctx.r25.s64 = ctx.r11.s64 + -30128;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823120ac
	if (ctx.cr6.lt) goto loc_823120AC;
	// beq cr6,0x82311c40
	if (ctx.cr6.eq) goto loc_82311C40;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82311a58
	if (ctx.cr6.lt) goto loc_82311A58;
	// bne cr6,0x82312134
	if (!ctx.cr6.eq) goto loc_82312134;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82311A4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,32(r31)
	REX_STORE_U8(ctx.r31.u32 + 32, ctx.r11.u8);
	// b 0x82312134
	goto loc_82312134;
loc_82311A58:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f13,216(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32115
	ctx.r5.s64 = -2104688640;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r28,r1,128
	ctx.r28.s64 = ctx.r1.s64 + 128;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r5,22072
	ctx.r3.s64 = ctx.r5.s64 + 22072;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r4,100
	ctx.r4.s64 = 100;
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,92(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f30,88(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r3,48(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// stfs f30,84(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f30,80(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,220(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 220);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v59,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vaddfp128 v61,v59,v60
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f30.f64 = double(temp.f32);
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f31.f64 = double(temp.f32);
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x82311B40;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82311b84
	if (ctx.cr0.eq) goto loc_82311B84;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,1812(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1812);
	ctx.f0.f64 = double(temp.f32);
	// li r9,3
	ctx.r9.s64 = 3;
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stw r9,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r9.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lfs f0,-6412(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6412);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// lfs f1,-432(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -432);
	ctx.f1.f64 = double(temp.f32);
	// std r10,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r10.u64);
	// bl 0x82218490
	ctx.lr = 0x82311B7C;
	sub_82218490(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// b 0x82311b88
	goto loc_82311B88;
loc_82311B84:
	// li r28,0
	ctx.r28.s64 = 0;
loc_82311B88:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82312128
	if (ctx.cr6.eq) goto loc_82312128;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82311BA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r11,r11,10080
	ctx.r11.s64 = ctx.r11.s64 + 10080;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r11,76(r28)
	REX_STORE_U32(ctx.r28.u32 + 76, ctx.r11.u32);
	// bl 0x82222ad8
	ctx.lr = 0x82311BC0;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82311be4
	if (!ctx.cr6.eq) goto loc_82311BE4;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82311BE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82311BE4:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f30,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f30,112(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x82312848
	ctx.lr = 0x82311C3C;
	sub_82312848(ctx, base);
	// b 0x82312128
	goto loc_82312128;
loc_82311C40:
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// li r4,1
	ctx.r4.s64 = 1;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82311C60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,216(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fneg f0,f28
	ctx.f0.u64 = ctx.f28.u64 ^ 0x8000000000000000;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f0,220(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 220);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
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
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,160(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lhz r5,102(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lhz r4,86(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 86);
	// bctrl 
	ctx.lr = 0x82311D10;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// addis r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 65536;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f12,24(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,-2676
	ctx.r10.s64 = ctx.r10.s64 + -2676;
	// lfs f11,12(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// lfs f0,-2088(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2088);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// lfs f12,28(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f29,268(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f29,264(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f29,260(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// fmadds f13,f13,f29,f11
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f29.f64, ctx.f11.f64)));
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// lfs f11,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f29,256(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
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
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r28,r1,96
	ctx.r28.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r24,r1,80
	ctx.r24.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r1,112
	ctx.r23.s64 = ctx.r1.s64 + 112;
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
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
	// stfs f30,156(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f30,148(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,232(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v61,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,144(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
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
	// lvx128 v60,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vaddfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stfs f0,236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,268(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// addi r10,r7,32544
	ctx.r10.s64 = ctx.r7.s64 + 32544;
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lfs f13,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,4(r31)
	REX_STORE_U64(ctx.r31.u32 + 4, ctx.r11.u64);
	// lfs f11,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,216(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lfs f12,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
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
	// lfs f0,220(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 220);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f11,152(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f11,148(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,184(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
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
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// vaddfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// vaddfp128 v63,v60,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// vaddfp128 v63,v63,v60
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82312134
	if (ctx.cr6.eq) goto loc_82312134;
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aebd8
	ctx.lr = 0x823120A0;
	sub_823AEBD8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82312134
	if (!ctx.cr0.lt) goto loc_82312134;
	// b 0x82312128
	goto loc_82312128;
loc_823120AC:
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823120CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x825a49b0
	ctx.lr = 0x823120DC;
	sub_825A49B0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lfs f31,1812(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1812);
	ctx.f31.f64 = double(temp.f32);
	// li r4,50
	ctx.r4.s64 = 50;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// li r3,10
	ctx.r3.s64 = 10;
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x825a49b0
	ctx.lr = 0x8231210C;
	sub_825A49B0(ctx, base);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,16(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
loc_82312128:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82312134:
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82312154;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lfs f1,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82312174;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f28,f0
	ctx.cr6.compare(ctx.f28.f64, ctx.f0.f64);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bge cr6,0x82312230
	if (!ctx.cr6.lt) goto loc_82312230;
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lfs f13,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lfs f0,216(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f28,f13
	ctx.f13.f64 = double(float(ctx.f28.f64 * ctx.f13.f64));
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,240(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f13,248(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f13,252(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vsubfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,272(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// b 0x82312234
	goto loc_82312234;
loc_82312230:
	// addi r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 4;
loc_82312234:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82312244;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,248(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// li r11,255
	ctx.r11.s64 = 255;
	// add r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 + ctx.r10.u64;
	// stb r11,161(r1)
	REX_STORE_U8(ctx.r1.u32 + 161, ctx.r11.u8);
	// stb r11,160(r1)
	REX_STORE_U8(ctx.r1.u32 + 160, ctx.r11.u8);
	// stb r11,162(r1)
	REX_STORE_U8(ctx.r1.u32 + 162, ctx.r11.u8);
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r9,87(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// stb r9,163(r1)
	REX_STORE_U8(ctx.r1.u32 + 163, ctx.r9.u8);
	// lwz r4,160(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82312288;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lfs f1,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823122A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af74
	ctx.lr = 0x823122B4;
	__restfpr_28(ctx, base);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8236C8A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8236C8B0;
	__savegprlr_23(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8236C8C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8236ca40
	if (ctx.cr0.eq) goto loc_8236CA40;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r23,0
	ctx.r23.s64 = 0;
	// lwz r3,-13032(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8236c90c
	if (ctx.cr6.eq) goto loc_8236C90C;
	// lfs f0,236(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
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
	ctx.lr = 0x8236C908;
	sub_823AEFA8(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
loc_8236C90C:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r24,r11,29408
	ctx.r24.s64 = ctx.r11.s64 + 29408;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// lis r27,-32111
	ctx.r27.s64 = -2104426496;
	// lis r26,-32111
	ctx.r26.s64 = -2104426496;
	// addi r25,r10,2668
	ctx.r25.s64 = ctx.r10.s64 + 2668;
	// addi r29,r9,2704
	ctx.r29.s64 = ctx.r9.s64 + 2704;
	// addi r28,r11,4864
	ctx.r28.s64 = ctx.r11.s64 + 4864;
loc_8236C938:
	// ld r10,3456(r26)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r26.u32 + 3456);
	// li r11,4
	ctx.r11.s64 = 4;
	// ld r9,8(r29)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r29.u32 + 8);
	// li r6,3
	ctx.r6.s64 = 3;
	// ld r8,3128(r27)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r27.u32 + 3128);
	// lfs f0,232(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// ld r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// lfs f13,236(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 236);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r6,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r6.u32);
	// std r10,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.r10.u64);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// std r9,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r9.u64);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// std r8,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r8.u64);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stw r28,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r28.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// std r7,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r7.u64);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8236C998:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,4(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfsu f13,8(r10)
	ea = 8 + ctx.r10.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8236c998
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8236C998;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8235fe48
	ctx.lr = 0x8236CA24;
	sub_8235FE48(ctx, base);
	// addi r11,r24,96
	ctx.r11.s64 = ctx.r24.s64 + 96;
	// stw r25,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r25.u32);
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8236c938
	if (ctx.cr6.lt) goto loc_8236C938;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
loc_8236CA40:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82378DD0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82378DD8;
	__savegprlr_29(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// vspltisw v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x1)));
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// vspltisw128 v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x2)));
	// addi r11,r11,-31920
	ctx.r11.s64 = ctx.r11.s64 + -31920;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r10,-31936
	ctx.r10.s64 = ctx.r10.s64 + -31936;
	// vspltisw128 v60,-1
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// addi r9,r9,-31952
	ctx.r9.s64 = ctx.r9.s64 + -31952;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// vmulfp128 v62,v1,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v11,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// vslw128 v59,v60,v60
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// vslw128 v58,v60,v60
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lvx128 v9,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r8,-31968
	ctx.r9.s64 = ctx.r8.s64 + -31968;
	// addi r11,r11,-32000
	ctx.r11.s64 = ctx.r11.s64 + -32000;
	// addi r10,r10,-32016
	ctx.r10.s64 = ctx.r10.s64 + -32016;
	// addi r8,r7,-31984
	ctx.r8.s64 = ctx.r7.s64 + -31984;
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lvx128 v8,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lvx128 v7,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r7,-32032
	ctx.r11.s64 = ctx.r7.s64 + -32032;
	// lvx128 v6,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r9,-32048
	ctx.r10.s64 = ctx.r9.s64 + -32048;
	// lvx128 v5,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32242
	ctx.r9.s64 = -2113011712;
	// vrfin128 v10,v62
	simde_mm_store_ps(ctx.v10.f32, simde_mm_round_ps(simde_mm_load_ps(ctx.v62.f32), SIMDE_MM_FROUND_TO_NEAREST_INT | SIMDE_MM_FROUND_NO_EXC));
	// li r8,432
	ctx.r8.s64 = 432;
	// addi r9,r9,31600
	ctx.r9.s64 = ctx.r9.s64 + 31600;
	// lvx128 v4,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	ctx.r11.s64 = 48;
	// lvx128 v3,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r10,64
	ctx.r10.s64 = 64;
	// lvx128 v2,r9,r8
	ea = (ctx.r9.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vctsxs v13,v10,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v10.f32)));
	// vnmsubfp v1,v10,v11,v1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v1.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vadduwm v12,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vand128 v62,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v57,v13,v63
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vnmsubfp v13,v10,v9,v1
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v1.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vand128 v63,v12,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vcmpequw128 v1,v62,v61
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vand128 v62,v12,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vcmpequw128 v31,v57,v61
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vcmpequw128 v9,v62,v61
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vmulfp128 v0,v13,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v12,v7,v0,v8
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v11,v5,v0,v6
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmulfp128 v10,v0,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v12,v12,v0,v4
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v11,v11,v0,v3
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v0,v12,v0,v2
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v13,v11,v10,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vor128 v62,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vor128 v57,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vsel v10,v0,v13,v1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vor128 v12,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vor128 v11,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v57.u8));
	// vsel v0,v12,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vor128 v62,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vxor128 v0,v10,v59
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// vor128 v13,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vsel v12,v0,v10,v31
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vxor128 v0,v62,v58
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// vor128 v10,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vor128 v59,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vcmpequw128 v12,v63,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vslw128 v63,v60,v60
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// lvx128 v0,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v57,v59,1
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xAA));
	// li r11,16
	ctx.r11.s64 = 16;
	// vor128 v62,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// lvx128 v13,r9,r10
	ea = (ctx.r9.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v11,v57,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lvx128 v12,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v5,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// li r8,416
	ctx.r8.s64 = 416;
	// vor128 v8,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// li r7,400
	ctx.r7.s64 = 400;
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vor128 v7,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// vspltw128 v54,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vsel v31,v10,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vspltw128 v53,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vslw128 v55,v60,v60
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vor128 v9,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// vor128 v6,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)ctx.v56.u8));
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// vor128 v10,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v54.u8));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// vor128 v3,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// addi r31,r1,208
	ctx.r31.s64 = ctx.r1.s64 + 208;
	// vor128 v11,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v53.u8));
	// addi r30,r1,96
	ctx.r30.s64 = ctx.r1.s64 + 96;
	// vsel v1,v5,v6,v0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// addi r29,r1,176
	ctx.r29.s64 = ctx.r1.s64 + 176;
	// vsel v30,v8,v7,v0
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// lvx128 v63,r9,r8
	ea = (ctx.r9.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v5,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)ctx.v56.u8));
	// lvx128 v62,r9,r7
	ea = (ctx.r9.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v6,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)ctx.v54.u8));
	// vspltw128 v59,v59,2
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x55));
	// vxor128 v7,v58,v55
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v2,v9,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v8,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v57.u8));
	// li r11,384
	ctx.r11.s64 = 384;
	// vsel v4,v3,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// vsel v3,v30,v5,v12
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// vsel v5,v31,v6,v12
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// vsel v6,v1,v7,v12
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// vsel v7,v2,v8,v12
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v3,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v10,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// stvx128 v5,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v62,v60,v60
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stvx128 v6,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stvx128 v7,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v12,v9,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// lvx128 v63,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v11,v59,v62
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v13,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v53.u8));
	// vsel v10,v4,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vsel v0,v12,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v10,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82378cd0
	ctx.lr = 0x82379024;
	sub_82378CD0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// bl 0x82378cd0
	ctx.lr = 0x82379034;
	sub_82378CD0(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82396DF0) {
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
	// bl 0x82396e48
	ctx.lr = 0x82396E10;
	sub_82396E48(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82396e28
	if (ctx.cr0.eq) goto loc_82396E28;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82396e28
	if (ctx.cr6.eq) goto loc_82396E28;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82396E28;
	sub_825E0378(ctx, base);
loc_82396E28:
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

DEFINE_REX_FUNC(sub_82399C00) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,28720
	ctx.r3.s64 = ctx.r11.s64 + 28720;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82399F18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82399F20;
	__savegprlr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,1368
	ctx.r3.s64 = ctx.r11.s64 + 1368;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r11,-15508(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82399F44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x82399F48;
	sub_8245A220(ctx, base);
	// stw r3,448(r31)
	REX_STORE_U32(ctx.r31.u32 + 448, ctx.r3.u32);
	// lwz r11,-15508(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15508);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r4,9
	ctx.r4.s64 = 9;
	// addi r3,r10,6928
	ctx.r3.s64 = ctx.r10.s64 + 6928;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82399F64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x82399F68;
	sub_8245A220(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// stw r3,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r3.u32);
	// addi r29,r11,20460
	ctx.r29.s64 = ctx.r11.s64 + 20460;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r30,r31,340
	ctx.r30.s64 = ctx.r31.s64 + 340;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// addi r27,r11,28648
	ctx.r27.s64 = ctx.r11.s64 + 28648;
	// addi r28,r10,2452
	ctx.r28.s64 = ctx.r10.s64 + 2452;
loc_82399F8C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82399F90:
	// lbzx r10,r11,r27
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r27.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne 0x82399f90
	if (!ctx.cr0.eq) goto loc_82399F90;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_82399FB0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82399fb0
	if (!ctx.cr6.eq) goto loc_82399FB0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82399FC4:
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
	// bne cr6,0x82399fc4
	if (!ctx.cr6.eq) goto loc_82399FC4;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_82399FE4:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82399fe4
	if (!ctx.cr6.eq) goto loc_82399FE4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82399FF8:
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
	// bne cr6,0x82399ff8
	if (!ctx.cr6.eq) goto loc_82399FF8;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8245d000
	ctx.lr = 0x8239A020;
	sub_8245D000(ctx, base);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r11,r29,12
	ctx.r11.s64 = ctx.r29.s64 + 12;
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82399f8c
	if (ctx.cr6.lt) goto loc_82399F8C;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823A34E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823A34F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8235f428
	ctx.lr = 0x823A34FC;
	sub_8235F428(ctx, base);
	// li r9,7
	ctx.r9.s64 = 7;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r9,232(r30)
	REX_STORE_U32(ctx.r30.u32 + 232, ctx.r9.u32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r7,r9,12236
	ctx.r7.s64 = ctx.r9.s64 + 12236;
	// addi r11,r11,29792
	ctx.r11.s64 = ctx.r11.s64 + 29792;
	// li r31,0
	ctx.r31.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lfs f13,12236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12236);
	ctx.f13.f64 = double(temp.f32);
	// stw r31,228(r30)
	REX_STORE_U32(ctx.r30.u32 + 228, ctx.r31.u32);
	// addi r11,r30,237
	ctx.r11.s64 = ctx.r30.s64 + 237;
	// lfs f0,232(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stb r31,236(r30)
	REX_STORE_U8(ctx.r30.u32 + 236, ctx.r31.u8);
	// stb r31,237(r30)
	REX_STORE_U8(ctx.r30.u32 + 237, ctx.r31.u8);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r31,238(r30)
	REX_STORE_U8(ctx.r30.u32 + 238, ctx.r31.u8);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
loc_823A3548:
	// li r7,23
	ctx.r7.s64 = 23;
	// stfs f0,7(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 7, temp.u32);
	// stw r31,3(r11)
	REX_STORE_U32(ctx.r11.u32 + 3, ctx.r31.u32);
	// stw r10,11(r11)
	REX_STORE_U32(ctx.r11.u32 + 11, ctx.r10.u32);
	// stw r31,15(r11)
	REX_STORE_U32(ctx.r11.u32 + 15, ctx.r31.u32);
	// stw r10,19(r11)
	REX_STORE_U32(ctx.r11.u32 + 19, ctx.r10.u32);
	// ld r9,3456(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 3456);
	// stfs f13,31(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 31, temp.u32);
	// stb r31,35(r11)
	REX_STORE_U8(ctx.r11.u32 + 35, ctx.r31.u8);
	// stdx r9,r11,r7
	REX_STORE_U64(ctx.r11.u32 + ctx.r7.u32, ctx.r9.u64);
	// stbu r31,36(r11)
	ea = 36 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r31.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x823a3548
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823A3548;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stw r10,820(r30)
	REX_STORE_U32(ctx.r30.u32 + 820, ctx.r10.u32);
	// stw r31,824(r30)
	REX_STORE_U32(ctx.r30.u32 + 824, ctx.r31.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// addi r10,r9,-27424
	ctx.r10.s64 = ctx.r9.s64 + -27424;
	// stw r31,828(r30)
	REX_STORE_U32(ctx.r30.u32 + 828, ctx.r31.u32);
	// addi r28,r11,22072
	ctx.r28.s64 = ctx.r11.s64 + 22072;
	// stw r10,816(r30)
	REX_STORE_U32(ctx.r30.u32 + 816, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r31,832(r30)
	REX_STORE_U32(ctx.r30.u32 + 832, ctx.r31.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r29,r30,836
	ctx.r29.s64 = ctx.r30.s64 + 836;
	// lwz r3,44(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823A35B0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823a35c0
	if (ctx.cr0.eq) goto loc_823A35C0;
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x823a35c4
	goto loc_823A35C4;
loc_823A35C0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_823A35C4:
	// stw r31,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r31,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r31.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// stw r31,16(r29)
	REX_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,28(r29)
	REX_STORE_U32(ctx.r29.u32 + 28, ctx.r31.u32);
	// addi r29,r30,868
	ctx.r29.s64 = ctx.r30.s64 + 868;
	// lwz r3,44(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823A35EC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823a35fc
	if (ctx.cr0.eq) goto loc_823A35FC;
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x823a3600
	goto loc_823A3600;
loc_823A35FC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_823A3600:
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,16(r29)
	REX_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r31.u32);
	// stw r31,28(r29)
	REX_STORE_U32(ctx.r29.u32 + 28, ctx.r31.u32);
	// stw r31,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// rlwinm r11,r11,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823AD920) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x823AD928;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,3276
	ctx.r11.s64 = 214695936;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ori r31,r11,52428
	ctx.r31.u64 = ctx.r11.u64 | 52428;
	// li r26,1
	ctx.r26.s64 = 1;
	// subf r11,r10,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x823ad990
	if (!ctx.cr6.lt) goto loc_823AD990;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,632
	ctx.r4.s64 = ctx.r11.s64 + 632;
	// bl 0x822167f8
	ctx.lr = 0x823AD95C;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82216678
	ctx.lr = 0x823AD968;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x823AD96C;
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
	ctx.lr = 0x823AD980;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x823AD990;
	sub_8235EC48(ctx, base);
loc_823AD990:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bge cr6,0x823ad9a4
	if (!ctx.cr6.lt) goto loc_823AD9A4;
	// li r10,8
	ctx.r10.s64 = 8;
loc_823AD9A4:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// ble cr6,0x823ad9bc
	if (!ctx.cr6.gt) goto loc_823AD9BC;
	// subf r9,r10,r31
	ctx.r9.u64 = ctx.r31.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x823ad9bc
	if (ctx.cr6.gt) goto loc_823AD9BC;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
loc_823AD9BC:
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
	ctx.lr = 0x823AD9DC;
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
	// beq 0x823ada18
	if (ctx.cr0.eq) goto loc_823ADA18;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x823ADA18;
	sub_827388E8(ctx, base);
loc_823ADA18:
	// lwz r5,16(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r29,r26
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r26.u32, ctx.xer);
	// bgt cr6,0x823ada94
	if (ctx.cr6.gt) goto loc_823ADA94;
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
	// beq 0x823ada48
	if (ctx.cr0.eq) goto loc_823ADA48;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827388e8
	ctx.lr = 0x823ADA48;
	sub_827388E8(ctx, base);
loc_823ADA48:
	// subf. r11,r29,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823ada6c
	if (ctx.cr0.eq) goto loc_823ADA6C;
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823ada6c
	if (ctx.cr0.eq) goto loc_823ADA6C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_823ADA64:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x823ada64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823ADA64;
loc_823ADA6C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x823adb08
	if (ctx.cr6.eq) goto loc_823ADB08;
	// addi r11,r27,-4
	ctx.r11.s64 = ctx.r27.s64 + -4;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq 0x823adb08
	if (ctx.cr0.eq) goto loc_823ADB08;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
loc_823ADA88:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x823ada88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823ADA88;
	// b 0x823adb08
	goto loc_823ADB08;
loc_823ADA94:
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
	// beq 0x823adab8
	if (ctx.cr0.eq) goto loc_823ADAB8;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x827388e8
	ctx.lr = 0x823ADAB8;
	sub_827388E8(ctx, base);
loc_823ADAB8:
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
	// beq 0x823adae4
	if (ctx.cr0.eq) goto loc_823ADAE4;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827388e8
	ctx.lr = 0x823ADAE4;
	sub_827388E8(ctx, base);
loc_823ADAE4:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x823adb08
	if (ctx.cr6.eq) goto loc_823ADB08;
	// addi r11,r31,-4
	ctx.r11.s64 = ctx.r31.s64 + -4;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi r26,0
	ctx.cr0.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq 0x823adb08
	if (ctx.cr0.eq) goto loc_823ADB08;
	// mtctr r26
	ctx.ctr.u64 = ctx.r26.u64;
loc_823ADB00:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x823adb00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823ADB00;
loc_823ADB08:
	// lwz r3,16(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823adb18
	if (ctx.cr6.eq) goto loc_823ADB18;
	// bl 0x825e0378
	ctx.lr = 0x823ADB18;
	sub_825E0378(ctx, base);
loc_823ADB18:
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

DEFINE_REX_FUNC(sub_823B76D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x823B76E0;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// sth r27,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r27.u16);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// sth r27,2(r3)
	REX_STORE_U16(ctx.r3.u32 + 2, ctx.r27.u16);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r27,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r27.u32);
	// subf r10,r4,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r4.u64;
loc_823B7708:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stbx r9,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne 0x823b7708
	if (!ctx.cr0.eq) goto loc_823B7708;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x823B772C;
	sub_8273A030(ctx, base);
	// lbz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 88);
	// addi r30,r30,32
	ctx.r30.s64 = ctx.r30.s64 + 32;
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823b77f8
	if (ctx.cr0.eq) goto loc_823B77F8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x823b784c
	if (!ctx.cr6.eq) goto loc_823B784C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x823B7754;
	sub_8273A030(ctx, base);
	// lbz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 84);
	// lhz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// addi r29,r30,16
	ctx.r29.s64 = ctx.r30.s64 + 16;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lhz r9,82(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 82);
	// li r28,16384
	ctx.r28.s64 = 16384;
	// stb r11,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
	// sth r10,0(r31)
	REX_STORE_U16(ctx.r31.u32 + 0, ctx.r10.u16);
	// sth r9,2(r31)
	REX_STORE_U16(ctx.r31.u32 + 2, ctx.r9.u16);
	// lbz r11,85(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 85);
	// stb r11,5(r31)
	REX_STORE_U8(ctx.r31.u32 + 5, ctx.r11.u8);
	// bne 0x823b7788
	if (!ctx.cr0.eq) goto loc_823B7788;
	// li r28,8192
	ctx.r28.s64 = 8192;
loc_823B7788:
	// rlwinm r11,r10,25,23,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FF;
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// lis r9,16383
	ctx.r9.s64 = 1073676288;
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// srawi r11,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 7;
	// ori r10,r9,65535
	ctx.r10.u64 = ctx.r9.u64 | 65535;
	// addze r30,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r30.s64 = temp.s64;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// rlwinm r4,r30,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x823b77b4
	if (!ctx.cr6.gt) goto loc_823B77B4;
	// li r4,-1
	ctx.r4.s64 = -1;
loc_823B77B4:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823B77C8;
	sub_825E02A0(ctx, base);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823b784c
	if (ctx.cr6.eq) goto loc_823B784C;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
loc_823B77DC:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r10,r29,512
	ctx.r10.s64 = ctx.r29.s64 + 512;
	// add r29,r28,r10
	ctx.r29.u64 = ctx.r28.u64 + ctx.r10.u64;
	// stwx r10,r9,r11
	REX_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r10.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x823b77dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823B77DC;
	// b 0x823b784c
	goto loc_823B784C;
loc_823B77F8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x823B7808;
	sub_8273A030(ctx, base);
	// lhz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// lhz r9,82(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 82);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lbz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 84);
	// li r5,0
	ctx.r5.s64 = 0;
	// lbz r7,85(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 85);
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,4
	ctx.r4.s64 = 4;
	// sth r10,0(r31)
	REX_STORE_U16(ctx.r31.u32 + 0, ctx.r10.u16);
	// sth r9,2(r31)
	REX_STORE_U16(ctx.r31.u32 + 2, ctx.r9.u16);
	// stb r8,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r8.u8);
	// stb r7,5(r31)
	REX_STORE_U8(ctx.r31.u32 + 5, ctx.r7.u8);
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823B7840;
	sub_825E02A0(ctx, base);
	// addi r11,r30,528
	ctx.r11.s64 = ctx.r30.s64 + 528;
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_823B784C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823BF3A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x823BF3B0;
	__savegprlr_19(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// lwz r7,12(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x823bf95c
	if (ctx.cr6.eq) goto loc_823BF95C;
	// lwz r11,56(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823bf418
	if (ctx.cr6.eq) goto loc_823BF418;
	// lhz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x823bf418
	if (!ctx.cr6.gt) goto loc_823BF418;
	// lwz r10,72(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 72);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823bf418
	if (ctx.cr6.eq) goto loc_823BF418;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r6,3,13,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0x7FFF8;
	// lwzx r10,r9,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x823bf41c
	goto loc_823BF41C;
loc_823BF418:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823BF41C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823bf95c
	if (ctx.cr6.eq) goto loc_823BF95C;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823bd038
	ctx.lr = 0x823BF430;
	sub_823BD038(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823bf95c
	if (ctx.cr0.eq) goto loc_823BF95C;
	// lwz r11,56(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823bf474
	if (ctx.cr6.eq) goto loc_823BF474;
	// lhz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x823bf474
	if (!ctx.cr6.gt) goto loc_823BF474;
	// lwz r10,72(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 72);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823bf474
	if (ctx.cr6.eq) goto loc_823BF474;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r6,3,13,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0x7FFF8;
	// lwzx r10,r9,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x823bf478
	goto loc_823BF478;
loc_823BF474:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823BF478:
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lwa r10,404(r1)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 404));
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lbz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 60);
	// rlwinm. r8,r10,31,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// frsp f7,f0
	ctx.f7.f64 = double(float(ctx.f0.f64));
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lhz r29,100(r1)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r1.u32 + 100);
	// frsp f6,f13
	ctx.f6.f64 = double(float(ctx.f13.f64));
	// beq 0x823bf4e8
	if (ctx.cr0.eq) goto loc_823BF4E8;
	// lha r10,33(r3)
	ctx.r10.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 33));
	// clrlwi r8,r29,16
	ctx.r8.u64 = ctx.r29.u32 & 0xFFFF;
	// lha r7,116(r31)
	ctx.r7.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 116));
	// lha r6,96(r1)
	ctx.r6.s64 = int16_t(REX_LOAD_U16(ctx.r1.u32 + 96));
	// add r11,r10,r7
	ctx.r11.u64 = ctx.r10.u64 + ctx.r7.u64;
	// subf r11,r6,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r6.u64;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x823bf508
	goto loc_823BF508;
loc_823BF4E8:
	// lha r11,33(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 33));
	// lha r10,96(r1)
	ctx.r10.s64 = int16_t(REX_LOAD_U16(ctx.r1.u32 + 96));
	// lha r8,116(r31)
	ctx.r8.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 116));
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_823BF508:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// lhz r30,102(r1)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// lha r10,118(r31)
	ctx.r10.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 118));
	// clrlwi. r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f8,f0,f7
	ctx.f8.f64 = double(float(ctx.f0.f64 + ctx.f7.f64));
	// bne 0x823bf54c
	if (!ctx.cr0.eq) goto loc_823BF54C;
	// lha r7,35(r3)
	ctx.r7.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 35));
	// clrlwi r9,r30,16
	ctx.r9.u64 = ctx.r30.u32 & 0xFFFF;
	// lha r8,98(r1)
	ctx.r8.s64 = int16_t(REX_LOAD_U16(ctx.r1.u32 + 98));
	// subf r10,r7,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r7.u64;
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// b 0x823bf568
	goto loc_823BF568;
loc_823BF54C:
	// lha r11,35(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 35));
	// lha r9,98(r1)
	ctx.r9.s64 = int16_t(REX_LOAD_U16(ctx.r1.u32 + 98));
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
loc_823BF568:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f5,56(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f5.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f9,f0,f6
	ctx.f9.f64 = double(float(ctx.f0.f64 + ctx.f6.f64));
	// lfs f0,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 + ctx.f0.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x823BF58C;
	sub_822EA1A8(ctx, base);
	// fmr f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f1.f64;
	// fmr f1,f5
	ctx.f1.f64 = ctx.f5.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x823BF598;
	sub_822EA1A8(ctx, base);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f7,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f7,160(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f7,168(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f9,144(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r24,r1,192
	ctx.r24.s64 = ctx.r1.s64 + 192;
	// stfs f9,156(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r22,r1,144
	ctx.r22.s64 = ctx.r1.s64 + 144;
	// stfs f9,152(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r23,r1,160
	ctx.r23.s64 = ctx.r1.s64 + 160;
	// stfs f9,148(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r21,r1,192
	ctx.r21.s64 = ctx.r1.s64 + 192;
	// stfs f6,140(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r19,r1,192
	ctx.r19.s64 = ctx.r1.s64 + 192;
	// stfs f6,136(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f6,132(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r20,r1,176
	ctx.r20.s64 = ctx.r1.s64 + 176;
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// fmuls f13,f0,f4
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f4.f64));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmuls f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f8,188(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f8,184(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f8,180(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lfs f13,40(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f4
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f4.f64));
	// stfs f8,176(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fmuls f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f11,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v61,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v61,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x823BF704;
	sub_82322D08(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x823bcf40
	ctx.lr = 0x823BF720;
	sub_823BCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x823BF730;
	sub_8255F918(ctx, base);
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f8,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f8,184(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f8,180(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stfs f8,176(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stw r9,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fsubs f11,f9,f0
	ctx.f11.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// stfs f11,188(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f11,184(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f11,180(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f11,176(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r10.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x823BF7BC;
	sub_82322D08(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x823bcf40
	ctx.lr = 0x823BF7D8;
	sub_823BCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x823BF7E8;
	sub_8255F918(ctx, base);
	// stfs f11,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f11,180(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f11,184(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f11,176(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r8,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r8.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f11,f0,f8
	ctx.f11.f64 = double(float(ctx.f0.f64 + ctx.f8.f64));
	// stfs f11,188(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f11,184(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f11,180(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f11,176(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x823BF874;
	sub_82322D08(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x823bcf40
	ctx.lr = 0x823BF890;
	sub_823BCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x823BF8A0;
	sub_8255F918(ctx, base);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f11,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f11,188(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f11,184(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stfs f11,180(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f9,176(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f9,184(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f9,188(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f9,180(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stw r11,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// bl 0x82322d08
	ctx.lr = 0x823BF914;
	sub_82322D08(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x823bcf40
	ctx.lr = 0x823BF930;
	sub_823BCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x823BF940;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// b 0x823bf960
	goto loc_823BF960;
loc_823BF95C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823BF960:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F34F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823F3500;
	__savegprlr_29(ctx, base);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// rlwinm r29,r4,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,4232
	ctx.r11.s64 = ctx.r11.s64 + 4232;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwzx r30,r29,r11
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// blt cr6,0x823f3578
	if (ctx.cr6.lt) goto loc_823F3578;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bge cr6,0x823f3578
	if (!ctx.cr6.lt) goto loc_823F3578;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r10,76(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// rlwinm r9,r30,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,-21368
	ctx.r11.s64 = ctx.r11.s64 + -21368;
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
	ctx.lr = 0x823F3578;
	sub_823C82A8(ctx, base);
loc_823F3578:
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
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
	ctx.lr = 0x823F35B8;
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
	ctx.lr = 0x823F35EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,16
	ctx.r11.s64 = 1048576;
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// ori r11,r11,518
	ctx.r11.u64 = ctx.r11.u64 | 518;
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// lis r9,16
	ctx.r9.s64 = 1048576;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// ori r10,r10,519
	ctx.r10.u64 = ctx.r10.u64 | 519;
	// ori r9,r9,521
	ctx.r9.u64 = ctx.r9.u64 | 521;
	// ori r11,r8,417
	ctx.r11.u64 = ctx.r8.u64 | 417;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r4,256
	ctx.r4.s64 = 256;
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// lwzx r5,r29,r7
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r7.u32);
	// bl 0x823c7af0
	ctx.lr = 0x823F3630;
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
	ctx.lr = 0x823F3654;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x823c8220
	ctx.lr = 0x823F365C;
	sub_823C8220(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FB278) {
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
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// bl 0x823f9a28
	ctx.lr = 0x823FB294;
	sub_823F9A28(ctx, base);
	// lwz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x823fb2d4
	if (!ctx.cr6.eq) goto loc_823FB2D4;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,42
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 42, ctx.xer);
	// beq cr6,0x823fb2bc
	if (ctx.cr6.eq) goto loc_823FB2BC;
	// li r11,39
	ctx.r11.s64 = 39;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x823fb2c4
	goto loc_823FB2C4;
loc_823FB2BC:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
loc_823FB2C4:
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r31)
	REX_STORE_U64(ctx.r31.u32 + 136, ctx.r11.u64);
loc_823FB2D4:
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

DEFINE_REX_FUNC(sub_823FE5D0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823ff300
	sub_823FF300(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FEAD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x823FEAE0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,80(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823feaf8
	if (ctx.cr6.eq) goto loc_823FEAF8;
	// bl 0x823d1c58
	ctx.lr = 0x823FEAF8;
	sub_823D1C58(ctx, base);
loc_823FEAF8:
	// lwz r3,76(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 76);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r27,80(r28)
	REX_STORE_U32(ctx.r28.u32 + 80, ctx.r27.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823feb10
	if (ctx.cr6.eq) goto loc_823FEB10;
	// bl 0x823cb0f0
	ctx.lr = 0x823FEB10;
	sub_823CB0F0(ctx, base);
loc_823FEB10:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stw r27,76(r28)
	REX_STORE_U32(ctx.r28.u32 + 76, ctx.r27.u32);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r11,-12856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823feb38
	if (ctx.cr6.eq) goto loc_823FEB38;
	// lwz r10,208(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 208);
	// lwz r11,204(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
loc_823FEB38:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823feb5c
	if (ctx.cr6.eq) goto loc_823FEB5C;
	// addi r30,r28,120
	ctx.r30.s64 = ctx.r28.s64 + 120;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
loc_823FEB48:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8245d0d8
	ctx.lr = 0x823FEB50;
	sub_8245D0D8(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r30,r30,24
	ctx.r30.s64 = ctx.r30.s64 + 24;
	// bne 0x823feb48
	if (!ctx.cr0.eq) goto loc_823FEB48;
loc_823FEB5C:
	// lwz r3,72(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823feb6c
	if (ctx.cr6.eq) goto loc_823FEB6C;
	// bl 0x8221cc98
	ctx.lr = 0x823FEB6C;
	sub_8221CC98(ctx, base);
loc_823FEB6C:
	// addi r31,r28,-4
	ctx.r31.s64 = ctx.r28.s64 + -4;
	// stw r27,72(r28)
	REX_STORE_U32(ctx.r28.u32 + 72, ctx.r27.u32);
	// li r30,18
	ctx.r30.s64 = 18;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
loc_823FEB7C:
	// lwz r11,-13064(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -13064);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823feb98
	if (ctx.cr6.eq) goto loc_823FEB98;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823feb98
	if (ctx.cr6.eq) goto loc_823FEB98;
	// bl 0x8235d960
	ctx.lr = 0x823FEB98;
	sub_8235D960(ctx, base);
loc_823FEB98:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r27,4(r31)
	ea = 4 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r27.u32);
	ctx.r31.u32 = ea;
	// bne 0x823feb7c
	if (!ctx.cr0.eq) goto loc_823FEB7C;
	// addi r8,r28,896
	ctx.r8.s64 = ctx.r28.s64 + 896;
	// li r7,2
	ctx.r7.s64 = 2;
loc_823FEBAC:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r9,-4(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -4);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823febec
	if (ctx.cr6.eq) goto loc_823FEBEC;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823febe8
	if (ctx.cr6.eq) goto loc_823FEBE8;
loc_823FEBC8:
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r6,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// lwz r6,4(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stw r6,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r6.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823febc8
	if (!ctx.cr6.eq) goto loc_823FEBC8;
loc_823FEBE8:
	// stw r9,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_823FEBEC:
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// bne 0x823febac
	if (!ctx.cr0.eq) goto loc_823FEBAC;
	// addi r11,r28,920
	ctx.r11.s64 = ctx.r28.s64 + 920;
	// li r30,1
	ctx.r30.s64 = 1;
	// addi r31,r11,4
	ctx.r31.s64 = ctx.r11.s64 + 4;
loc_823FEC04:
	// lwzu r3,-16(r31)
	ea = -16 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823fec14
	if (ctx.cr6.eq) goto loc_823FEC14;
	// bl 0x825e0378
	ctx.lr = 0x823FEC14;
	sub_825E0378(ctx, base);
loc_823FEC14:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r27,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// bge 0x823fec04
	if (!ctx.cr0.lt) goto loc_823FEC04;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r31,r28,888
	ctx.r31.s64 = ctx.r28.s64 + 888;
	// li r30,31
	ctx.r30.s64 = 31;
	// addi r29,r11,-27424
	ctx.r29.s64 = ctx.r11.s64 + -27424;
loc_823FEC38:
	// stwu r29,-24(r31)
	ea = -24 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r29.u32);
	ctx.r31.u32 = ea;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8245d0d8
	ctx.lr = 0x823FEC44;
	sub_8245D0D8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x823fec38
	if (!ctx.cr0.lt) goto loc_823FEC38;
	// addi r3,r28,116
	ctx.r3.s64 = ctx.r28.s64 + 116;
	// bl 0x823cb628
	ctx.lr = 0x823FEC54;
	sub_823CB628(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240BA38) {
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
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// bge cr6,0x8240ba7c
	if (!ctx.cr6.lt) goto loc_8240BA7C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r3,36
	ctx.r10.s64 = ctx.r3.s64 + 36;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x8240b8a0
	ctx.lr = 0x8240BA78;
	sub_8240B8A0(ctx, base);
	// b 0x8240bac0
	goto loc_8240BAC0;
loc_8240BA7C:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240baa4
	if (ctx.cr6.eq) goto loc_8240BAA4;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r4,r10,8
	ctx.r4.s64 = ctx.r10.s64 + 8;
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x822489e0
	ctx.lr = 0x8240BAA4;
	sub_822489E0(ctx, base);
loc_8240BAA4:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r10,36
	ctx.r10.s64 = ctx.r10.s64 + 36;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_8240BAC0:
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

DEFINE_REX_FUNC(sub_824106A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r9,156(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// lwz r10,80(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 80);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,52(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x824106d4
	if (!ctx.cr6.eq) goto loc_824106D4;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lfs f13,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,15656(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 15656);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x824106f8
	if (!ctx.cr6.lt) goto loc_824106F8;
loc_824106D4:
	// lwz r11,64(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r8,52(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x82410700
	if (!ctx.cr6.eq) goto loc_82410700;
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// lfs f13,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,18380(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 18380);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x82410700
	if (ctx.cr6.gt) goto loc_82410700;
loc_824106F8:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82410704
	goto loc_82410704;
loc_82410700:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82410704:
	// lbz r8,152(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x82410728
	if (ctx.cr0.eq) goto loc_82410728;
	// lbz r8,153(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 153);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne 0x82410728
	if (!ctx.cr0.eq) goto loc_82410728;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x8241072c
	if (!ctx.cr0.eq) goto loc_8241072C;
loc_82410728:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8241072C:
	// stb r11,77(r9)
	REX_STORE_U8(ctx.r9.u32 + 77, ctx.r11.u8);
	// lbz r11,152(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// stb r11,76(r9)
	REX_STORE_U8(ctx.r9.u32 + 76, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82415980) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82415988;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,860(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 860);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824159a8
	if (ctx.cr6.eq) goto loc_824159A8;
	// bl 0x823c74f0
	ctx.lr = 0x824159A8;
	sub_823C74F0(ctx, base);
loc_824159A8:
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r11,860(r31)
	REX_STORE_U32(ctx.r31.u32 + 860, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x824159C8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824159d8
	if (ctx.cr0.eq) goto loc_824159D8;
	// bl 0x823c9508
	ctx.lr = 0x824159D4;
	sub_823C9508(ctx, base);
	// b 0x824159dc
	goto loc_824159DC;
loc_824159D8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824159DC:
	// stw r3,860(r31)
	REX_STORE_U32(ctx.r31.u32 + 860, ctx.r3.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r10,156(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// stw r10,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r8,860(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 860);
	// lfs f0,-27352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27352);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stfs f0,16(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lfs f13,17264(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17264);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,20(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// lwz r11,860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 860);
	// lfs f12,12468(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// stw r29,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r29.u32);
	// stb r10,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r10.u8);
	// lwz r11,860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 860);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stfs f12,4(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8241B4E8) {
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
	// lwz r31,156(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// lbz r11,429(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 429);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8241b56c
	if (ctx.cr0.eq) goto loc_8241B56C;
	// lwz r4,352(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x823c60b0
	ctx.lr = 0x8241B518;
	sub_823C60B0(ctx, base);
	// li r30,-1
	ctx.r30.s64 = -1;
	// lwz r3,324(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,144
	ctx.r6.s64 = 144;
	// li r5,464
	ctx.r5.s64 = 464;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x823be020
	ctx.lr = 0x8241B53C;
	sub_823BE020(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r3,324(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,144
	ctx.r6.s64 = 144;
	// lfs f0,24656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24656);
	ctx.f0.f64 = double(temp.f32);
	// li r4,4
	ctx.r4.s64 = 4;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823be020
	ctx.lr = 0x8241B56C;
	sub_823BE020(ctx, base);
loc_8241B56C:
	// lwz r11,532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8241b580
	if (ctx.cr6.eq) goto loc_8241B580;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x823ca190
	ctx.lr = 0x8241B580;
	sub_823CA190(ctx, base);
loc_8241B580:
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

DEFINE_REX_FUNC(sub_82423F00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82423F08;
	__savegprlr_23(ctx, base);
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f29.u64);
	// stfd f30,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f30.u64);
	// stfd f31,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r7,r8,12472
	ctx.r7.s64 = ctx.r8.s64 + 12472;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lfs f29,12472(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12472);
	ctx.f29.f64 = double(temp.f32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lfs f30,-236(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -236);
	ctx.f30.f64 = double(temp.f32);
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// li r23,-1
	ctx.r23.s64 = -1;
	// addi r31,r11,-7108
	ctx.r31.s64 = ctx.r11.s64 + -7108;
	// addi r24,r10,-21684
	ctx.r24.s64 = ctx.r10.s64 + -21684;
	// addi r28,r9,-18428
	ctx.r28.s64 = ctx.r9.s64 + -18428;
loc_82423F50:
	// rlwinm r10,r30,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 30) & 0x3FFFFFFF;
	// lfs f0,7728(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 7728);
	ctx.f0.f64 = double(temp.f32);
	// clrlwi r11,r30,30
	ctx.r11.u64 = ctx.r30.u32 & 0x3;
	// lfs f13,-2380(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -2380);
	ctx.f13.f64 = double(temp.f32);
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f11,112(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r11.u64);
	// lfd f12,120(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// addi r11,r28,-3772
	ctx.r11.s64 = ctx.r28.s64 + -3772;
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lfs f12,-26608(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -26608);
	ctx.f12.f64 = double(temp.f32);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// lwz r6,348(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 348);
	// lwz r3,324(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 324);
	// fmr f4,f29
	ctx.f4.f64 = ctx.f29.f64;
	// lbzx r4,r30,r11
	ctx.r4.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stb r25,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r25.u8);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// lfs f11,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f2,f10,f12,f11
	ctx.f2.f64 = double(float(std::fma(ctx.f10.f64, ctx.f12.f64, ctx.f11.f64)));
	// fmadds f3,f9,f0,f13
	ctx.f3.f64 = double(float(std::fma(ctx.f9.f64, ctx.f0.f64, ctx.f13.f64)));
	// bl 0x823c67c0
	ctx.lr = 0x82423FB8;
	sub_823C67C0(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 11, ctx.xer);
	// blt cr6,0x82423f50
	if (ctx.cr6.lt) goto loc_82423F50;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r10,408(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 408);
	// lwz r9,404(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 404);
	// addi r30,r11,-4080
	ctx.r30.s64 = ctx.r11.s64 + -4080;
	// subf r11,r9,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r9.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82424104
	if (ctx.cr0.eq) goto loc_82424104;
	// lwz r11,356(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 356);
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r11,r10
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82424104
	if (ctx.cr6.eq) goto loc_82424104;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82424104
	if (ctx.cr6.eq) goto loc_82424104;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8257a428
	ctx.lr = 0x8242401C;
	sub_8257A428(ctx, base);
	// mr. r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq 0x82424104
	if (ctx.cr0.eq) goto loc_82424104;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823b4f20
	ctx.lr = 0x8242402C;
	sub_823B4F20(ctx, base);
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// lfs f13,3304(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 3304);
	ctx.f13.f64 = double(temp.f32);
	// stb r25,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r25.u8);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// srawi r10,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 4;
	// lfs f12,3308(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 3308);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// lfs f0,7728(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 7728);
	ctx.f0.f64 = double(temp.f32);
	// subf r10,r8,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r8.u64;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lfs f0,-1848(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -1848);
	ctx.f0.f64 = double(temp.f32);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lfs f1,8720(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8720);
	ctx.f1.f64 = double(temp.f32);
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// lwz r5,348(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 348);
	// std r10,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f13,120(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// extsw r7,r7
	ctx.r7.s64 = ctx.r7.s32;
	// std r8,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r8.u64);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfd f11,120(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// std r7,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r11.u64);
	// lfd f10,120(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x823c5c80
	ctx.lr = 0x82424104;
	sub_823C5C80(ctx, base);
loc_82424104:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f13,20928(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 20928);
	ctx.f13.f64 = double(temp.f32);
	// lfs f31,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f12,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// li r9,14
	ctx.r9.s64 = 14;
	// lfs f11,1896(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1896);
	ctx.f11.f64 = double(temp.f32);
	// li r8,8
	ctx.r8.s64 = 8;
	// lfs f10,1600(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1600);
	ctx.f10.f64 = double(temp.f32);
	// li r7,9
	ctx.r7.s64 = 9;
	// lfs f0,-11928(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11928);
	ctx.f0.f64 = double(temp.f32);
	// li r11,10
	ctx.r11.s64 = 10;
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fadds f13,f0,f12
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fadds f13,f0,f11
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f9,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fadds f13,f0,f10
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f10.f64));
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fadds f13,f0,f9
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f9.f64));
	// lfs f8,13784(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13784);
	ctx.f8.f64 = double(temp.f32);
	// li r6,11
	ctx.r6.s64 = 11;
	// lfs f7,2812(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2812);
	ctx.f7.f64 = double(temp.f32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// fadds f13,f0,f8
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f8.f64));
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fadds f0,f0,f7
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f7.f64));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stw r9,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// stw r25,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r25.u32);
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// stw r8,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r8.u32);
	// stw r7,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r7.u32);
	// stw r11,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r11.u32);
	// stw r6,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r6.u32);
	// stw r5,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r5.u32);
	// stw r10,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r10.u32);
loc_824241B4:
	// lwz r11,432(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 432);
	// lbz r11,21(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824241cc
	if (!ctx.cr0.eq) goto loc_824241CC;
	// cmplwi cr6,r30,7
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 7, ctx.xer);
	// beq cr6,0x82424218
	if (ctx.cr6.eq) goto loc_82424218;
loc_824241CC:
	// lwz r11,356(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 356);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lwz r6,348(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 348);
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// fmr f4,f29
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f29.f64;
	// fmr f3,f31
	ctx.f3.f64 = ctx.f31.f64;
	// addic r8,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfsx f2,r31,r10
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f2.f64 = double(temp.f32);
	// subfe r4,r8,r11
	temp.u8 = (~ctx.r8.u32 + ctx.r11.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r8.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwzx r3,r31,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// bl 0x823cbe68
	ctx.lr = 0x82424200;
	sub_823CBE68(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// lwz r3,328(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 328);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r25,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r25.u8);
	// bl 0x823c67c0
	ctx.lr = 0x82424218;
	sub_823C67C0(ctx, base);
loc_82424218:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// blt cr6,0x824241b4
	if (ctx.cr6.lt) goto loc_824241B4;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
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

DEFINE_REX_FUNC(sub_8243E3E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x8243E3F0;
	__savegprlr_19(ctx, base);
	// stfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.f30.u64);
	// stfd f31,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,2432(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2432);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f1,108(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmr f31,f2
	ctx.f31.f64 = ctx.f2.f64;
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r19,r6
	ctx.r19.u64 = ctx.r6.u64;
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// stfs f1,96(r1)
	temp.f32 = float(ctx.f1.f64);
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
	// lfs f1,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827389e8
	ctx.lr = 0x8243E458;
	sub_827389E8(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,2436(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 2436);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r9,32688
	ctx.r9.s64 = ctx.r9.s64 + 32688;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fctiwz f0,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfd f0,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r24,92(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827389e8
	ctx.lr = 0x8243E4C0;
	sub_827389E8(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,2444(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 2444);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// fctiwz f0,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,92(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lfs f1,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827389e8
	ctx.lr = 0x8243E518;
	sub_827389E8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// li r25,0
	ctx.r25.s64 = 0;
	// li r22,0
	ctx.r22.s64 = 0;
	// stw r25,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// li r21,0
	ctx.r21.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r26,92(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpw cr6,r29,r26
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r26.s32, ctx.xer);
	// bgt cr6,0x8243e6b0
	if (ctx.cr6.gt) goto loc_8243E6B0;
	// clrlwi r20,r31,24
	ctx.r20.u64 = ctx.r31.u32 & 0xFF;
	// lis r23,-32112
	ctx.r23.s64 = -2104492032;
loc_8243E548:
	// lwz r10,-13032(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + -13032);
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8243e57c
	if (ctx.cr6.eq) goto loc_8243E57C;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x823ae2c0
	ctx.lr = 0x8243E574;
	sub_823AE2C0(ctx, base);
	// lwz r25,80(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_8243E57C:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// bne cr6,0x8243e594
	if (!ctx.cr6.eq) goto loc_8243E594;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8243e594
	if (ctx.cr6.eq) goto loc_8243E594;
	// cmpw cr6,r29,r26
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r26.s32, ctx.xer);
	// beq cr6,0x8243e6a4
	if (ctx.cr6.eq) goto loc_8243E6A4;
loc_8243E594:
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// beq cr6,0x8243e5d8
	if (ctx.cr6.eq) goto loc_8243E5D8;
	// lwz r10,-13032(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + -13032);
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8243e5d8
	if (ctx.cr6.eq) goto loc_8243E5D8;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ae2c0
	ctx.lr = 0x8243E5D0;
	sub_823AE2C0(ctx, base);
	// lwz r28,88(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_8243E5D8:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// bne cr6,0x8243e5ec
	if (!ctx.cr6.eq) goto loc_8243E5EC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8243e670
	if (ctx.cr6.eq) goto loc_8243E670;
	// b 0x8243e630
	goto loc_8243E630;
loc_8243E5EC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8243e630
	if (!ctx.cr6.eq) goto loc_8243E630;
	// extsw r10,r29
	ctx.r10.s64 = ctx.r29.s32;
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f13,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// frsp f2,f13
	ctx.f2.f64 = double(float(ctx.f13.f64));
	// bl 0x8243df30
	ctx.lr = 0x8243E624;
	sub_8243DF30(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8243e670
	if (!ctx.cr0.eq) goto loc_8243E670;
	// li r11,1
	ctx.r11.s64 = 1;
loc_8243E630:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x8243e640
	if (!ctx.cr6.eq) goto loc_8243E640;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// b 0x8243e654
	goto loc_8243E654;
loc_8243E640:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8243e664
	if (ctx.cr6.eq) goto loc_8243E664;
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r9,0(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
loc_8243E654:
	// bne cr6,0x8243e664
	if (!ctx.cr6.eq) goto loc_8243E664;
	// cmpwi cr6,r31,16
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 16, ctx.xer);
	// blt cr6,0x8243e594
	if (ctx.cr6.lt) goto loc_8243E594;
	// b 0x8243e670
	goto loc_8243E670;
loc_8243E664:
	// mr r25,r28
	ctx.r25.u64 = ctx.r28.u64;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
loc_8243E670:
	// cmpw cr6,r31,r22
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r22.s32, ctx.xer);
	// ble cr6,0x8243e680
	if (!ctx.cr6.gt) goto loc_8243E680;
	// mr r22,r31
	ctx.r22.u64 = ctx.r31.u64;
	// mr r21,r25
	ctx.r21.u64 = ctx.r25.u64;
loc_8243E680:
	// cmpw cr6,r29,r26
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r26.s32, ctx.xer);
	// beq cr6,0x8243e6a4
	if (ctx.cr6.eq) goto loc_8243E6A4;
	// subf r11,r29,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r29.u64;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x8243e698
	if (!ctx.cr6.gt) goto loc_8243E698;
	// li r11,16
	ctx.r11.s64 = 16;
loc_8243E698:
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// cmpw cr6,r29,r26
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r26.s32, ctx.xer);
	// ble cr6,0x8243e548
	if (!ctx.cr6.gt) goto loc_8243E548;
loc_8243E6A4:
	// cmpwi cr6,r22,16
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 16, ctx.xer);
	// ble cr6,0x8243e6b0
	if (!ctx.cr6.gt) goto loc_8243E6B0;
	// li r22,16
	ctx.r22.s64 = 16;
loc_8243E6B0:
	// extsw r11,r22
	ctx.r11.s64 = ctx.r22.s32;
	// clrlwi. r10,r19,24
	ctx.r10.u64 = ctx.r19.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f30,f0,f30
	ctx.f30.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// beq 0x8243e6fc
	if (ctx.cr0.eq) goto loc_8243E6FC;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x8243e6fc
	if (ctx.cr6.eq) goto loc_8243E6FC;
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8243e060
	ctx.lr = 0x8243E6F0;
	sub_8243E060(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f30.f64);
	// bge cr6,0x8243e6fc
	if (!ctx.cr6.lt) goto loc_8243E6FC;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
loc_8243E6FC:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f30,-128(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82457BC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r10,172(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 172);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82457c80
	if (ctx.cr6.eq) goto loc_82457C80;
	// lwz r11,168(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 168);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82457c80
	if (ctx.cr0.eq) goto loc_82457C80;
	// lwz r11,444(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 444);
	// li r7,12
	ctx.r7.s64 = 12;
	// li r8,78
	ctx.r8.s64 = 78;
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// li r9,16
	ctx.r9.s64 = 16;
	// sth r8,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r8.u16);
	// li r31,10
	ctx.r31.s64 = 10;
	// sth r7,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r7.u16);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r6,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// addi r11,r4,436
	ctx.r11.s64 = ctx.r4.s64 + 436;
	// stw r8,444(r4)
	REX_STORE_U32(ctx.r4.u32 + 444, ctx.r8.u32);
	// addi r8,r4,360
	ctx.r8.s64 = ctx.r4.s64 + 360;
	// lwz r5,4(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lwz r11,444(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 444);
	// addi r9,r8,-4
	ctx.r9.s64 = ctx.r8.s64 + -4;
	// sth r3,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r3.u16);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// sth r7,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r7.u16);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// stw r5,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
	// stw r10,444(r4)
	REX_STORE_U32(ctx.r4.u32 + 444, ctx.r10.u32);
loc_82457C64:
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82457c64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82457C64;
	// stw r6,352(r4)
	REX_STORE_U32(ctx.r4.u32 + 352, ctx.r6.u32);
	// stw r6,356(r4)
	REX_STORE_U32(ctx.r4.u32 + 356, ctx.r6.u32);
	// stw r6,424(r4)
	REX_STORE_U32(ctx.r4.u32 + 424, ctx.r6.u32);
	// stw r6,428(r4)
	REX_STORE_U32(ctx.r4.u32 + 428, ctx.r6.u32);
	// stw r6,432(r4)
	REX_STORE_U32(ctx.r4.u32 + 432, ctx.r6.u32);
loc_82457C80:
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8245F068) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x8245F070;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r31,-12864(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -12864);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245f454
	if (ctx.cr6.eq) goto loc_8245F454;
	// bl 0x82213210
	ctx.lr = 0x8245F08C;
	sub_82213210(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82213210
	ctx.lr = 0x8245F094;
	sub_82213210(ctx, base);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// li r19,0
	ctx.r19.s64 = 0;
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stw r19,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r19.u32);
	// addi r29,r11,136
	ctx.r29.s64 = ctx.r11.s64 + 136;
	// stw r19,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r19.u32);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r31,12
	ctx.r11.s64 = ctx.r31.s64 + 12;
	// stfs f0,10036(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 10036, temp.u32);
	// stb r19,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r19.u8);
	// stb r19,13(r31)
	REX_STORE_U8(ctx.r31.u32 + 13, ctx.r19.u8);
	// lwz r10,-12816(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -12816);
	// addi r30,r3,4120
	ctx.r30.s64 = ctx.r3.s64 + 4120;
	// lwz r11,-12952(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r9,1404(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 1404);
	// stw r9,132(r10)
	REX_STORE_U32(ctx.r10.u32 + 132, ctx.r9.u32);
	// lbz r10,4032(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 4032);
	// beq cr6,0x8245f110
	if (ctx.cr6.eq) goto loc_8245F110;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,808
	ctx.r8.s64 = 808;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// divw r11,r11,r8
	ctx.r11.u64 = uint32_t((ctx.r8.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r8.s32 == -1)) ? ctx.r11.s32 / ctx.r8.s32 : 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8245f110
	if (!ctx.cr6.lt) goto loc_8245F110;
	// mulli r11,r10,808
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(808));
	// lwzx r27,r11,r9
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// b 0x8245f114
	goto loc_8245F114;
loc_8245F110:
	// mr r27,r19
	ctx.r27.u64 = ctx.r19.u64;
loc_8245F114:
	// lbz r22,1488(r29)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r29.u32 + 1488);
	// addi r26,r22,-1
	ctx.r26.s64 = ctx.r22.s64 + -1;
	// cmplwi cr6,r26,16
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 16, ctx.xer);
	// blt cr6,0x8245f128
	if (ctx.cr6.lt) goto loc_8245F128;
	// li r26,15
	ctx.r26.s64 = 15;
loc_8245F128:
	// bl 0x82213210
	ctx.lr = 0x8245F12C;
	sub_82213210(ctx, base);
	// lis r21,-32112
	ctx.r21.s64 = -2104492032;
	// lbz r10,4036(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 4036);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// add r27,r26,r30
	ctx.r27.u64 = ctx.r26.u64 + ctx.r30.u64;
	// addic r7,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// addi r9,r26,2334
	ctx.r9.s64 = ctx.r26.s64 + 2334;
	// lwz r11,-16508(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -16508);
	// subfe r10,r7,r10
	temp.u8 = (~ctx.r7.u32 + ctx.r10.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r7.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r8,r26,2350
	ctx.r8.s64 = ctx.r26.s64 + 2350;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stb r10,1669(r31)
	REX_STORE_U8(ctx.r31.u32 + 1669, ctx.r10.u8);
	// rlwinm r25,r9,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r10,r26,2366
	ctx.r10.s64 = ctx.r26.s64 + 2366;
	// stb r11,1670(r31)
	REX_STORE_U8(ctx.r31.u32 + 1670, ctx.r11.u8);
	// rlwinm r24,r8,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r11,4035(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 4035);
	// rlwinm r23,r10,2,0,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r11,1668(r31)
	REX_STORE_U8(ctx.r31.u32 + 1668, ctx.r11.u8);
	// addi r11,r27,12984
	ctx.r11.s64 = ctx.r27.s64 + 12984;
	// stb r6,1672(r31)
	REX_STORE_U8(ctx.r31.u32 + 1672, ctx.r6.u8);
	// lbz r11,4034(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 4034);
	// stb r11,1673(r31)
	REX_STORE_U8(ctx.r31.u32 + 1673, ctx.r11.u8);
	// lwzx r11,r25,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + ctx.r30.u32);
	// stw r11,1592(r31)
	REX_STORE_U32(ctx.r31.u32 + 1592, ctx.r11.u32);
	// lwzx r11,r24,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + ctx.r30.u32);
	// stw r11,1596(r31)
	REX_STORE_U32(ctx.r31.u32 + 1596, ctx.r11.u32);
	// lwzx r11,r23,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r30.u32);
	// stw r11,1600(r31)
	REX_STORE_U32(ctx.r31.u32 + 1600, ctx.r11.u32);
	// lwz r11,9332(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 9332);
	// stw r11,1604(r31)
	REX_STORE_U32(ctx.r31.u32 + 1604, ctx.r11.u32);
	// lbz r11,12984(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 12984);
	// stb r11,1674(r31)
	REX_STORE_U8(ctx.r31.u32 + 1674, ctx.r11.u8);
	// lbz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 36);
	// stb r11,10034(r31)
	REX_STORE_U8(ctx.r31.u32 + 10034, ctx.r11.u8);
	// lbz r11,37(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 37);
	// stb r11,10035(r31)
	REX_STORE_U8(ctx.r31.u32 + 10035, ctx.r11.u8);
	// lbz r3,1484(r29)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r29.u32 + 1484);
	// bl 0x82577128
	ctx.lr = 0x8245F1C8;
	sub_82577128(ctx, base);
	// lbz r11,1485(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 1485);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r18,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r18.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// bl 0x82213210
	ctx.lr = 0x8245F1E8;
	sub_82213210(ctx, base);
	// stb r18,4036(r3)
	REX_STORE_U8(ctx.r3.u32 + 4036, ctx.r18.u8);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// lbz r10,1486(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 1486);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stb r20,4035(r28)
	REX_STORE_U8(ctx.r28.u32 + 4035, ctx.r20.u8);
	// rlwinm r11,r10,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stw r11,-16508(r21)
	REX_STORE_U32(ctx.r21.u32 + -16508, ctx.r11.u32);
	// bl 0x82443da0
	ctx.lr = 0x8245F208;
	sub_82443DA0(ctx, base);
	// stb r3,4032(r28)
	REX_STORE_U8(ctx.r28.u32 + 4032, ctx.r3.u8);
	// stb r22,4033(r28)
	REX_STORE_U8(ctx.r28.u32 + 4033, ctx.r22.u8);
	// lbz r11,1489(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 1489);
	// stb r11,4034(r28)
	REX_STORE_U8(ctx.r28.u32 + 4034, ctx.r11.u8);
	// lwz r11,1408(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 1408);
	// stwx r11,r25,r30
	REX_STORE_U32(ctx.r25.u32 + ctx.r30.u32, ctx.r11.u32);
	// lwz r11,1412(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 1412);
	// stwx r11,r24,r30
	REX_STORE_U32(ctx.r24.u32 + ctx.r30.u32, ctx.r11.u32);
	// lwz r11,1416(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 1416);
	// stwx r11,r23,r30
	REX_STORE_U32(ctx.r23.u32 + ctx.r30.u32, ctx.r11.u32);
	// lwz r11,1420(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 1420);
	// stw r11,9332(r30)
	REX_STORE_U32(ctx.r30.u32 + 9332, ctx.r11.u32);
	// lbz r11,1490(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 1490);
	// stb r11,12984(r27)
	REX_STORE_U8(ctx.r27.u32 + 12984, ctx.r11.u8);
	// lbz r11,9850(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 9850);
	// stb r11,36(r30)
	REX_STORE_U8(ctx.r30.u32 + 36, ctx.r11.u8);
	// lbz r11,9851(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 9851);
	// stb r11,37(r30)
	REX_STORE_U8(ctx.r30.u32 + 37, ctx.r11.u8);
	// bl 0x82213210
	ctx.lr = 0x8245F254;
	sub_82213210(ctx, base);
	// lwz r28,4(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r19
	ctx.r25.u64 = ctx.r19.u64;
	// li r27,88
	ctx.r27.s64 = 88;
	// addi r23,r31,184
	ctx.r23.s64 = ctx.r31.s64 + 184;
	// addi r22,r29,-88
	ctx.r22.s64 = ctx.r29.s64 + -88;
	// lis r21,-32112
	ctx.r21.s64 = -2104492032;
	// lis r20,-32112
	ctx.r20.s64 = -2104492032;
loc_8245F270:
	// bl 0x82213210
	ctx.lr = 0x8245F274;
	sub_82213210(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8245f2a8
	if (ctx.cr6.eq) goto loc_8245F2A8;
	// addi r10,r28,184
	ctx.r10.s64 = ctx.r28.s64 + 184;
	// lwz r11,-12768(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -12768);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// mulli r10,r10,45
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(45));
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// b 0x8245f2b0
	goto loc_8245F2B0;
loc_8245F2A8:
	// lwz r11,-12956(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + -12956);
	// lwzx r11,r27,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
loc_8245F2B0:
	// stw r11,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// lwzx r24,r22,r27
	ctx.r24.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r27.u32);
	// bl 0x82213210
	ctx.lr = 0x8245F2BC;
	sub_82213210(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8245f2f0
	if (ctx.cr6.eq) goto loc_8245F2F0;
	// addi r10,r28,184
	ctx.r10.s64 = ctx.r28.s64 + 184;
	// lwz r11,-12768(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -12768);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// mulli r10,r10,45
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(45));
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r24,r10,r11
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r24.u32);
	// b 0x8245f2f8
	goto loc_8245F2F8;
loc_8245F2F0:
	// lwz r11,-12956(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + -12956);
	// stwx r24,r27,r11
	REX_STORE_U32(ctx.r27.u32 + ctx.r11.u32, ctx.r24.u32);
loc_8245F2F8:
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r23,r23,4
	ctx.r23.s64 = ctx.r23.s64 + 4;
	// cmplwi cr6,r27,268
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 268, ctx.xer);
	// blt cr6,0x8245f270
	if (ctx.cr6.lt) goto loc_8245F270;
	// li r8,8331
	ctx.r8.s64 = 8331;
	// addi r11,r30,999
	ctx.r11.s64 = ctx.r30.s64 + 999;
	// addi r9,r29,1505
	ctx.r9.s64 = ctx.r29.s64 + 1505;
	// addi r10,r31,1689
	ctx.r10.s64 = ctx.r31.s64 + 1689;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8245F320:
	// lbz r8,1(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// stbu r8,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r8.u8);
	ctx.r10.u32 = ea;
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// stbu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8245f320
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245F320;
	// mulli r11,r26,200
	ctx.r11.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(200));
	// li r10,50
	ctx.r10.s64 = 50;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r8,r29,176
	ctx.r8.s64 = ctx.r29.s64 + 176;
	// addi r11,r11,9780
	ctx.r11.s64 = ctx.r11.s64 + 9780;
	// addi r9,r31,360
	ctx.r9.s64 = ctx.r31.s64 + 360;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8245F350:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// lwzu r10,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8245f350
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245F350;
	// mulli r11,r26,60
	ctx.r11.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(60));
	// li r10,15
	ctx.r10.s64 = 15;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r8,r29,1420
	ctx.r8.s64 = ctx.r29.s64 + 1420;
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// addi r9,r31,1604
	ctx.r9.s64 = ctx.r31.s64 + 1604;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8245F380:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// lwzu r10,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8245f380
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245F380;
	// mulli r11,r26,15
	ctx.r11.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(15));
	// li r10,15
	ctx.r10.s64 = 15;
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// addi r8,r31,1675
	ctx.r8.s64 = ctx.r31.s64 + 1675;
	// addi r7,r29,1491
	ctx.r7.s64 = ctx.r29.s64 + 1491;
	// addi r9,r9,9528
	ctx.r9.s64 = ctx.r9.s64 + 9528;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8245F3B4:
	// lbzx r10,r9,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// stbx r10,r8,r11
	REX_STORE_U8(ctx.r8.u32 + ctx.r11.u32, ctx.r10.u8);
	// lbzx r10,r7,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r11.u32);
	// stbx r10,r9,r11
	REX_STORE_U8(ctx.r9.u32 + ctx.r11.u32, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8245f3b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245F3B4;
	// li r8,256
	ctx.r8.s64 = 256;
	// addi r11,r30,14076
	ctx.r11.s64 = ctx.r30.s64 + 14076;
	// addi r9,r29,376
	ctx.r9.s64 = ctx.r29.s64 + 376;
	// addi r10,r31,560
	ctx.r10.s64 = ctx.r31.s64 + 560;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8245F3E0:
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// lwzu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r8,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8245f3e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245F3E0;
	// li r10,9
	ctx.r10.s64 = 9;
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// addi r9,r31,10021
	ctx.r9.s64 = ctx.r31.s64 + 10021;
	// addi r8,r29,9837
	ctx.r8.s64 = ctx.r29.s64 + 9837;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8245F408:
	// lbzx r10,r11,r30
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// stbx r10,r9,r11
	REX_STORE_U8(ctx.r9.u32 + ctx.r11.u32, ctx.r10.u8);
	// lbzx r10,r8,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r11.u32);
	// stbx r10,r11,r30
	REX_STORE_U8(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8245f408
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245F408;
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r11,r30,31
	ctx.r11.s64 = ctx.r30.s64 + 31;
	// addi r9,r29,9845
	ctx.r9.s64 = ctx.r29.s64 + 9845;
	// addi r10,r31,10029
	ctx.r10.s64 = ctx.r31.s64 + 10029;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8245F434:
	// lbz r8,1(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// stbu r8,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r8.u8);
	ctx.r10.u32 = ea;
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// stbu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8245f434
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245F434;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,1404(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 1404);
	// bl 0x825a48b0
	ctx.lr = 0x8245F454;
	sub_825A48B0(ctx, base);
loc_8245F454:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82480790) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82480798;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,2277(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2277);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824807c8
	if (ctx.cr0.eq) goto loc_824807C8;
	// lwz r11,2220(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2220);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x824807c8
	if (!ctx.cr6.eq) goto loc_824807C8;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,2220(r3)
	REX_STORE_U32(ctx.r3.u32 + 2220, ctx.r11.u32);
loc_824807C8:
	// lwz r11,2220(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2220);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82480a84
	if (ctx.cr6.lt) goto loc_82480A84;
	// beq cr6,0x82480990
	if (ctx.cr6.eq) goto loc_82480990;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82480940
	if (ctx.cr6.lt) goto loc_82480940;
	// beq cr6,0x824807fc
	if (ctx.cr6.eq) goto loc_824807FC;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x82480aac
	if (!ctx.cr6.lt) goto loc_82480AAC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x82480aac
	goto loc_82480AAC;
loc_824807FC:
	// lfs f0,2248(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2248);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwz r9,2264(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 2264);
	// lwz r11,2256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2256);
	// stfs f13,2248(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 2248, temp.u32);
	// subf. r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f0,-30132(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30132);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// blt 0x82480870
	if (ctx.cr0.lt) goto loc_82480870;
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x824808f8
	if (!ctx.cr6.lt) goto loc_824808F8;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82480844:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// blt cr6,0x82480854
	if (ctx.cr6.lt) goto loc_82480854;
	// li r10,59
	ctx.r10.s64 = 59;
loc_82480854:
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// li r9,1
	ctx.r9.s64 = 1;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r9,317(r10)
	REX_STORE_U8(ctx.r10.u32 + 317, ctx.r9.u8);
	// bdnz 0x82480844
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82480844;
	// b 0x824808f8
	goto loc_824808F8;
loc_82480870:
	// addi r10,r11,60
	ctx.r10.s64 = ctx.r11.s64 + 60;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,60
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 60, ctx.xer);
	// bgt cr6,0x824808c0
	if (ctx.cr6.gt) goto loc_824808C0;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x824808f8
	if (!ctx.cr6.lt) goto loc_824808F8;
	// subf r10,r10,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r10.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82480894:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// blt cr6,0x824808a4
	if (ctx.cr6.lt) goto loc_824808A4;
	// li r10,59
	ctx.r10.s64 = 59;
loc_824808A4:
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// li r9,1
	ctx.r9.s64 = 1;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r9,317(r10)
	REX_STORE_U8(ctx.r10.u32 + 317, ctx.r9.u8);
	// bdnz 0x82480894
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82480894;
	// b 0x824808f8
	goto loc_824808F8;
loc_824808C0:
	// add. r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// beq 0x824808f8
	if (ctx.cr0.eq) goto loc_824808F8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_824808D0:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// blt cr6,0x824808e0
	if (ctx.cr6.lt) goto loc_824808E0;
	// li r10,59
	ctx.r10.s64 = 59;
loc_824808E0:
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// li r9,1
	ctx.r9.s64 = 1;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r9,317(r10)
	REX_STORE_U8(ctx.r10.u32 + 317, ctx.r9.u8);
	// bdnz 0x824808d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824808D0;
loc_824808F8:
	// li r11,60
	ctx.r11.s64 = 60;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r10,r31,320
	ctx.r10.s64 = ctx.r31.s64 + 320;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82480908:
	// lbz r11,-2(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + -2);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82480920
	if (!ctx.cr0.eq) goto loc_82480920;
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82480924
	if (!ctx.cr0.eq) goto loc_82480924;
loc_82480920:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_82480924:
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bdnz 0x82480908
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82480908;
	// cmplwi cr6,r9,60
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 60, ctx.xer);
	// blt cr6,0x82480aac
	if (ctx.cr6.lt) goto loc_82480AAC;
	// lwz r11,2220(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2220);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x82480988
	goto loc_82480988;
loc_82480940:
	// li r10,60
	ctx.r10.s64 = 60;
	// addi r11,r31,320
	ctx.r11.s64 = ctx.r31.s64 + 320;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8248094C:
	// lbz r10,-2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -2);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8248097c
	if (!ctx.cr0.eq) goto loc_8248097C;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// extsb. r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble 0x8248097c
	if (!ctx.cr0.gt) goto loc_8248097C;
	// lbz r10,-3(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -3);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8248097c
	if (!ctx.cr0.eq) goto loc_8248097C;
	// lwz r10,2264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 2264);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,2264(r31)
	REX_STORE_U32(ctx.r31.u32 + 2264, ctx.r10.u32);
loc_8248097C:
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// bdnz 0x8248094c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8248094C;
	// li r11,3
	ctx.r11.s64 = 3;
loc_82480988:
	// stw r11,2220(r31)
	REX_STORE_U32(ctx.r31.u32 + 2220, ctx.r11.u32);
	// b 0x82480aac
	goto loc_82480AAC;
loc_82480990:
	// lfs f0,2244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2244);
	ctx.f0.f64 = double(temp.f32);
	// addi r28,r31,2212
	ctx.r28.s64 = ctx.r31.s64 + 2212;
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f0,2244(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2244, temp.u32);
	// addi r29,r31,44
	ctx.r29.s64 = ctx.r31.s64 + 44;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x822de9b8
	ctx.lr = 0x824809B0;
	sub_822DE9B8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-30132
	ctx.r11.s64 = ctx.r11.s64 + -30132;
	// lfs f0,6084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6084);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x82480a6c
	if (!ctx.cr6.gt) goto loc_82480A6C;
	// lwz r11,2256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2256);
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// bge cr6,0x82480a6c
	if (!ctx.cr6.lt) goto loc_82480A6C;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lbz r9,318(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 318);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x824809f0
	if (!ctx.cr0.eq) goto loc_824809F0;
	// lbz r10,319(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 319);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x824809fc
	if (ctx.cr0.eq) goto loc_824809FC;
loc_824809F0:
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// stbx r30,r11,r31
	REX_STORE_U8(ctx.r11.u32 + ctx.r31.u32, ctx.r30.u8);
loc_824809FC:
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// li r3,312
	ctx.r3.s64 = 312;
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
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
	ctx.lr = 0x82480A24;
	sub_82240A58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824813c8
	ctx.lr = 0x82480A2C;
	sub_824813C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,2256(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 2256);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82480b20
	ctx.lr = 0x82480A3C;
	sub_82480B20(ctx, base);
	// lwz r11,2256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2256);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2256(r31)
	REX_STORE_U32(ctx.r31.u32 + 2256, ctx.r11.u32);
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// stw r10,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// blt cr6,0x82480a6c
	if (ctx.cr6.lt) goto loc_82480A6C;
	// li r11,60
	ctx.r11.s64 = 60;
	// stw r30,2256(r31)
	REX_STORE_U32(ctx.r31.u32 + 2256, ctx.r30.u32);
	// stw r11,2260(r31)
	REX_STORE_U32(ctx.r31.u32 + 2260, ctx.r11.u32);
loc_82480A6C:
	// lbz r11,289(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82480aac
	if (ctx.cr0.eq) goto loc_82480AAC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,2277(r31)
	REX_STORE_U8(ctx.r31.u32 + 2277, ctx.r11.u8);
	// b 0x82480aac
	goto loc_82480AAC;
loc_82480A84:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r30,2256(r31)
	REX_STORE_U32(ctx.r31.u32 + 2256, ctx.r30.u32);
	// stw r8,2220(r31)
	REX_STORE_U32(ctx.r31.u32 + 2220, ctx.r8.u32);
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,2212(r31)
	REX_STORE_U32(ctx.r31.u32 + 2212, ctx.r10.u32);
	// stfs f0,2244(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2244, temp.u32);
	// stw r9,2216(r31)
	REX_STORE_U32(ctx.r31.u32 + 2216, ctx.r9.u32);
loc_82480AAC:
	// lwz r11,2260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2260);
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// blt cr6,0x82480ae4
	if (ctx.cr6.lt) goto loc_82480AE4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82480b10
	if (ctx.cr6.eq) goto loc_82480B10;
loc_82480AC0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82480b20
	ctx.lr = 0x82480AD0;
	sub_82480B20(ctx, base);
	// lwz r11,2260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2260);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82480ac0
	if (ctx.cr6.lt) goto loc_82480AC0;
	// b 0x82480b10
	goto loc_82480B10;
loc_82480AE4:
	// lwz r11,2256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2256);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82480b10
	if (ctx.cr6.eq) goto loc_82480B10;
loc_82480AF0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82480b20
	ctx.lr = 0x82480B00;
	sub_82480B20(ctx, base);
	// lwz r11,2256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2256);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82480af0
	if (ctx.cr6.lt) goto loc_82480AF0;
loc_82480B10:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824A32D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x824A32E0;
	__savegprlr_25(ctx, base);
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
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
	ctx.lr = 0x824A3300;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824a3510
	if (!ctx.cr0.eq) goto loc_824A3510;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// lis r26,-32226
	ctx.r26.s64 = -2111963136;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// lfs f31,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x824a33d0
	if (ctx.cr6.eq) goto loc_824A33D0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x824A332C;
	sub_82222D88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x824a33c8
	if (ctx.cr0.eq) goto loc_824A33C8;
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lfs f13,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-8644(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwz r11,24(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bctrl 
	ctx.lr = 0x824A337C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,-26092(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26092);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f1,f0,f30
	ctx.f1.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A339C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,320(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x824a33ac
	if (!ctx.cr6.lt) goto loc_824A33AC;
	// stfs f31,320(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
loc_824A33AC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f1,320(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A33C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x824a33d0
	goto loc_824A33D0;
loc_824A33C8:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
loc_824A33D0:
	// lwz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// addi r30,r31,136
	ctx.r30.s64 = ctx.r31.s64 + 136;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r28,0
	ctx.r28.s64 = 0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824a3430
	if (ctx.cr0.eq) goto loc_824A3430;
	// addi r27,r31,44
	ctx.r27.s64 = ctx.r31.s64 + 44;
	// li r29,0
	ctx.r29.s64 = 0;
loc_824A33F4:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A3410;
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
	// blt cr6,0x824a33f4
	if (ctx.cr6.lt) goto loc_824A33F4;
loc_824A3430:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824a3510
	if (ctx.cr0.eq) goto loc_824A3510;
	// li r29,0
	ctx.r29.s64 = 0;
loc_824A344C:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A3464;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lwzx r27,r29,r11
	ctx.r27.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r25,0(r27)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,124(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A3484;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,120(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 120);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fadds f1,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f31.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A3498;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A34B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A34CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f0,-8644(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// fadds f31,f31,f0
	ctx.f31.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A34F0;
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
	// blt cr6,0x824a344c
	if (ctx.cr6.lt) goto loc_824A344C;
loc_824A3510:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824B36A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x824B36A8;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lwz r29,4(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,36
	ctx.r4.s64 = 36;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r27,4(r29)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824B36D4;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x824b36e0
	if (ctx.cr0.eq) goto loc_824B36E0;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_824B36E0:
	// addic. r28,r31,4
	ctx.xer.ca = ctx.r31.u32 > 4294967291;
	ctx.r28.s64 = ctx.r31.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x824b36ec
	if (ctx.cr0.eq) goto loc_824B36EC;
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
loc_824B36EC:
	// addic. r3,r31,8
	ctx.xer.ca = ctx.r31.u32 > 4294967287;
	ctx.r3.s64 = ctx.r31.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x824b3700
	if (ctx.cr0.eq) goto loc_824B3700;
	// li r5,28
	ctx.r5.s64 = 28;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x8273a030
	ctx.lr = 0x824B3700;
	sub_8273A030(ctx, base);
loc_824B3700:
	// lis r11,2340
	ctx.r11.s64 = 153354240;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// ori r11,r11,37449
	ctx.r11.u64 = ctx.r11.u64 | 37449;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x824b375c
	if (!ctx.cr6.lt) goto loc_824B375C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,712
	ctx.r4.s64 = ctx.r11.s64 + 712;
	// bl 0x822167f8
	ctx.lr = 0x824B3728;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82216678
	ctx.lr = 0x824B3734;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x824B3738;
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
	ctx.lr = 0x824B374C;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x824B375C;
	sub_8235EC48(ctx, base);
loc_824B375C:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824B7030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x824B7038;
	__savegprlr_21(ctx, base);
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// ld r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r4.u32 + 0);
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824B706C;
	sub_825E02A0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x824b7088
	if (!ctx.cr6.eq) goto loc_824B7088;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r27)
	REX_STORE_U8(ctx.r27.u32 + 23, ctx.r11.u8);
	// b 0x824b776c
	goto loc_824B776C;
loc_824B7088:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f1,332(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 332);
	ctx.f1.f64 = double(temp.f32);
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// lfs f13,1736(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1736);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f12
	ctx.f12.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x824b70b4
	if (!ctx.cr6.gt) goto loc_824B70B4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_824B70B4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824b7228
	if (!ctx.cr0.eq) goto loc_824B7228;
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x824b7228
	if (ctx.cr6.gt) goto loc_824B7228;
	// lwz r11,584(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 584);
	// addi r4,r27,584
	ctx.r4.s64 = ctx.r27.s64 + 584;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B70DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f31,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v0,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// bl 0x82322d08
	ctx.lr = 0x824B714C;
	sub_82322D08(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// li r9,432
	ctx.r9.s64 = 432;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,31600
	ctx.r10.s64 = ctx.r10.s64 + 31600;
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
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
	// vor128 v10,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vcmpeqfp128 v5,v63,v62
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v13,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v4,v63,v62
	simde_mm_store_ps(ctx.v4.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vor128 v9,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// vnmsubfp v1,v7,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v2,v10,v0,v13
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpeqfp128 v3,v0,v62
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vcmpeqfp128 v11,v0,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v7,v0,v1,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v8,v0,v2,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v3,v5,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// vsel v5,v4,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vor v11,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// vnmsubfp v6,v9,v8,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp128 v13,v63,v11,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// vmaddfp v11,v8,v6,v8
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v13,v7,v13,v7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vsel v10,v11,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vsel v12,v13,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v62,v62,v12
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v63,v63,v10
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,504(r27)
	REX_STORE_U64(ctx.r27.u32 + 504, ctx.r11.u64);
	// b 0x824b72c8
	goto loc_824B72C8;
loc_824B7228:
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfs f0,508(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 508);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,504(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 504);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x824B72B8;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_824B72C8:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r27,292
	ctx.r29.s64 = ctx.r27.s64 + 292;
	// stfs f0,8(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// std r11,496(r1)
	REX_STORE_U64(ctx.r1.u32 + 496, ctx.r11.u64);
	// bl 0x824b7930
	ctx.lr = 0x824B72E8;
	sub_824B7930(ctx, base);
	// lwz r11,320(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 320);
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// blt cr6,0x824b735c
	if (ctx.cr6.lt) goto loc_824B735C;
	// lwz r10,28(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// bl 0x8236c610
	ctx.lr = 0x824B732C;
	sub_8236C610(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824b733c
	if (ctx.cr6.eq) goto loc_824B733C;
	// bl 0x825e0378
	ctx.lr = 0x824B733C;
	sub_825E0378(ctx, base);
loc_824B733C:
	// lwz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824b735c
	if (ctx.cr6.eq) goto loc_824B735C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,28(r29)
	REX_STORE_U32(ctx.r29.u32 + 28, ctx.r11.u32);
	// bne 0x824b735c
	if (!ctx.cr0.eq) goto loc_824B735C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
loc_824B735C:
	// lwz r10,320(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 320);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lwz r26,88(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// addi r22,r11,1608
	ctx.r22.s64 = ctx.r11.s64 + 1608;
	// ble cr6,0x824b7524
	if (!ctx.cr6.gt) goto loc_824B7524;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r25,r1,496
	ctx.r25.s64 = ctx.r1.s64 + 496;
	// addi r24,r11,112
	ctx.r24.s64 = ctx.r11.s64 + 112;
	// addi r23,r10,604
	ctx.r23.s64 = ctx.r10.s64 + 604;
loc_824B7390:
	// lwz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bgt cr6,0x824b73d4
	if (ctx.cr6.gt) goto loc_824B73D4;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x822167f8
	ctx.lr = 0x824B73A8;
	sub_822167F8(ctx, base);
	// addi r4,r1,416
	ctx.r4.s64 = ctx.r1.s64 + 416;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// bl 0x82216678
	ctx.lr = 0x824B73B4;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x824B73B8;
	sub_82216E60(ctx, base);
	// stw r24,448(r1)
	REX_STORE_U32(ctx.r1.u32 + 448, ctx.r24.u32);
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// bl 0x82216d98
	ctx.lr = 0x824B73C4;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x8235ec48
	ctx.lr = 0x824B73D4;
	sub_8235EC48(ctx, base);
loc_824B73D4:
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// bl 0x8236c610
	ctx.lr = 0x824B7404;
	sub_8236C610(ctx, base);
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,-3236(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -3236);
	ctx.f13.f64 = double(temp.f32);
	// std r11,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r11.u64);
	// lfd f12,224(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 224);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lfs f0,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f0,8(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x824b7510
	if (ctx.cr6.lt) goto loc_824B7510;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lfs f12,8(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// ld r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
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
	// bl 0x82322d08
	ctx.lr = 0x824B7478;
	sub_82322D08(ctx, base);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f13,192(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,204(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f13,200(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
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
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x824B74FC;
	sub_8255F918(ctx, base);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 9, ctx.xer);
	// stdu r11,8(r25)
	ea = 8 + ctx.r25.u32;
	REX_STORE_U64(ea, ctx.r11.u64);
	ctx.r25.u32 = ea;
	// bge cr6,0x824b7558
	if (!ctx.cr6.lt) goto loc_824B7558;
loc_824B7510:
	// lwz r11,320(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 320);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x824b7390
	if (ctx.cr6.lt) goto loc_824B7390;
loc_824B7524:
	// cmplwi cr6,r30,9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 9, ctx.xer);
	// bge cr6,0x824b7558
	if (!ctx.cr6.lt) goto loc_824B7558;
	// rlwinm r9,r30,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r1,496
	ctx.r11.s64 = ctx.r1.s64 + 496;
	// subfic r10,r30,9
	ctx.xer.ca = ctx.r30.u32 <= 9;
	ctx.r10.u64 = static_cast<uint64_t>(9) - ctx.r30.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r9,r11,-8
	ctx.r9.s64 = ctx.r11.s64 + -8;
loc_824B7540:
	// lwz r8,-8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stwu r8,8(r9)
	ea = 8 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// lwz r8,-4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// bne 0x824b7540
	if (!ctx.cr0.eq) goto loc_824B7540;
loc_824B7558:
	// ld r11,496(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 496);
	// addi r9,r1,504
	ctx.r9.s64 = ctx.r1.s64 + 504;
	// addi r10,r1,496
	ctx.r10.s64 = ctx.r1.s64 + 496;
	// lfs f9,0(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// subf r26,r21,r9
	ctx.r26.u64 = ctx.r9.u64 - ctx.r21.u64;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// subf r27,r21,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r21.u64;
	// std r11,0(r21)
	REX_STORE_U64(ctx.r21.u32 + 0, ctx.r11.u64);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r31,r21
	ctx.r31.u64 = ctx.r21.u64;
	// lfs f10,-24048(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24048);
	ctx.f10.f64 = double(temp.f32);
	// li r30,8
	ctx.r30.s64 = 8;
	// addi r29,r11,32736
	ctx.r29.s64 = ctx.r11.s64 + 32736;
	// addi r28,r10,-32480
	ctx.r28.s64 = ctx.r10.s64 + -32480;
loc_824B7594:
	// add r5,r27,r31
	ctx.r5.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r4,r26,r31
	ctx.r4.u64 = ctx.r26.u64 + ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82322d08
	ctx.lr = 0x824B75A4;
	sub_82322D08(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82222370
	ctx.lr = 0x824B75AC;
	sub_82222370(ctx, base);
	// addi r11,r1,368
	ctx.r11.s64 = ctx.r1.s64 + 368;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8231e0d8
	ctx.lr = 0x824B75C0;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lfs f0,368(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// ble cr6,0x824b7644
	if (!ctx.cr6.gt) goto loc_824B7644;
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lfs f0,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// lfs f13,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,384
	ctx.r8.s64 = ctx.r1.s64 + 384;
	// stfs f13,300(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,292(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f13,296(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f13,288(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,384(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,336(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 336);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// b 0x824b773c
	goto loc_824B773C;
loc_824B7644:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// bge cr6,0x824b76bc
	if (!ctx.cr6.lt) goto loc_824B76BC;
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// lfs f0,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r8,r1,400
	ctx.r8.s64 = ctx.r1.s64 + 400;
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// lfs f13,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,268(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f13,256(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f13,260(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f13,264(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,304(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,400(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x824b773c
	goto loc_824B773C;
loc_824B76BC:
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lfs f12,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// lfs f13,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
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
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,320(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f13,352(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
loc_824B773C:
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8255f918
	ctx.lr = 0x824B774C;
	sub_8255F918(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// bne 0x824b7594
	if (!ctx.cr0.eq) goto loc_824B7594;
loc_824B776C:
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824FA010) {
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
	// bl 0x824fa068
	ctx.lr = 0x824FA030;
	sub_824FA068(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824fa048
	if (ctx.cr0.eq) goto loc_824FA048;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824fa048
	if (ctx.cr6.eq) goto loc_824FA048;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x824FA048;
	sub_825E0378(ctx, base);
loc_824FA048:
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

DEFINE_REX_FUNC(sub_824FAAE8) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x824FAB08;
	sub_8235EC48(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r4,r11,-9604
	ctx.r4.s64 = ctx.r11.s64 + -9604;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8246b640
	ctx.lr = 0x824FAB1C;
	sub_8246B640(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x824fab30
	if (!ctx.cr6.lt) goto loc_824FAB30;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_824FAB30:
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824fab64
	if (ctx.cr6.eq) goto loc_824FAB64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x824FAB48;
	sub_8246D8F0(ctx, base);
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824fab64
	if (ctx.cr6.eq) goto loc_824FAB64;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-9636
	ctx.r3.s64 = ctx.r11.s64 + -9636;
	// bl 0x8246d8f0
	ctx.lr = 0x824FAB64;
	sub_8246D8F0(ctx, base);
loc_824FAB64:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x824FAB74;
	sub_8235EC48(ctx, base);
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

DEFINE_REX_FUNC(sub_824FDC18) {
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
	// lwz r11,324(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 324);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x824fdccc
	if (ctx.cr6.eq) goto loc_824FDCCC;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x824FDC48;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824fdccc
	if (ctx.cr0.eq) goto loc_824FDCCC;
	// lwz r11,324(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 324);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222d88
	ctx.lr = 0x824FDC60;
	sub_82222D88(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x824fdccc
	if (ctx.cr0.eq) goto loc_824FDCCC;
	// lwz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r30,292(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 292);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824FDC88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,15688
	ctx.r11.s64 = ctx.r11.s64 + 15688;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// lfs f13,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
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
	ctx.lr = 0x824FDCC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,108(r31)
	REX_STORE_U8(ctx.r31.u32 + 108, ctx.r11.u8);
loc_824FDCCC:
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

DEFINE_REX_FUNC(sub_82503418) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82503420;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwa r10,300(r3)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r3.u32 + 300));
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// addi r30,r11,13168
	ctx.r30.s64 = ctx.r11.s64 + 13168;
	// lfs f2,560(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 560);
	ctx.f2.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f1,-700(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -700);
	ctx.f1.f64 = double(temp.f32);
	// fdivs f31,f2,f0
	ctx.f31.f64 = double(float(ctx.f2.f64 / ctx.f0.f64));
	// bl 0x825a4a40
	ctx.lr = 0x82503460;
	sub_825A4A40(ctx, base);
	// lwa r11,300(r31)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r31.u32 + 300));
	// lfs f13,1708(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1708);
	ctx.f13.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fcmpu cr6,f13,f1
	ctx.cr6.compare(ctx.f13.f64, ctx.f1.f64);
	// blt cr6,0x8250349c
	if (ctx.cr6.lt) goto loc_8250349C;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r31,424
	ctx.r30.s64 = ctx.r31.s64 + 424;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x825034a0
	if (ctx.cr6.lt) goto loc_825034A0;
loc_8250349C:
	// addi r30,r31,412
	ctx.r30.s64 = ctx.r31.s64 + 412;
loc_825034A0:
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82503298
	ctx.lr = 0x825034AC;
	sub_82503298(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,48
	ctx.r4.s64 = 48;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r29,4(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r27,4(r29)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x825034CC;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x825034d8
	if (ctx.cr0.eq) goto loc_825034D8;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_825034D8:
	// addic. r28,r31,4
	ctx.xer.ca = ctx.r31.u32 > 4294967291;
	ctx.r28.s64 = ctx.r31.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x825034e4
	if (ctx.cr0.eq) goto loc_825034E4;
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
loc_825034E4:
	// addic. r3,r31,8
	ctx.xer.ca = ctx.r31.u32 > 4294967287;
	ctx.r3.s64 = ctx.r31.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x825034f8
	if (ctx.cr0.eq) goto loc_825034F8;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// li r5,40
	ctx.r5.s64 = 40;
	// bl 0x8273a030
	ctx.lr = 0x825034F8;
	sub_8273A030(ctx, base);
loc_825034F8:
	// lis r11,1638
	ctx.r11.s64 = 107347968;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// ori r11,r11,26214
	ctx.r11.u64 = ctx.r11.u64 | 26214;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82503554
	if (!ctx.cr6.lt) goto loc_82503554;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,712
	ctx.r4.s64 = ctx.r11.s64 + 712;
	// bl 0x822167f8
	ctx.lr = 0x82503520;
	sub_822167F8(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82216678
	ctx.lr = 0x8250352C;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x82503530;
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
	ctx.lr = 0x82503544;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235ec48
	ctx.lr = 0x82503554;
	sub_8235EC48(ctx, base);
loc_82503554:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8250BB80) {
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
	// lwz r9,124(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,952(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 952);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15332(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -15332);
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
	ctx.lr = 0x8250BBE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8250bc34
	if (ctx.cr6.eq) goto loc_8250BC34;
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
	// bl 0x823aebd8
	ctx.lr = 0x8250BC20;
	sub_823AEBD8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8250bc34
	if (ctx.cr0.eq) goto loc_8250BC34;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
loc_8250BC34:
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

DEFINE_REX_FUNC(sub_8250F840) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r30,r3,84
	ctx.r30.s64 = ctx.r3.s64 + 84;
	// addi r11,r11,-6044
	ctx.r11.s64 = ctx.r11.s64 + -6044;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82249308
	ctx.lr = 0x8250F870;
	sub_82249308(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r11,r11,3312
	ctx.r11.s64 = ctx.r11.s64 + 3312;
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x82249308
	ctx.lr = 0x8250F884;
	sub_82249308(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,136
	ctx.r11.s64 = ctx.r11.s64 + 136;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_82511098) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lwz r11,312(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 312);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lbz r10,308(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 308);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r9,116(r3)
	REX_STORE_U8(ctx.r3.u32 + 116, ctx.r9.u8);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r8,312(r3)
	REX_STORE_U32(ctx.r3.u32 + 312, ctx.r8.u32);
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,296(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// beq 0x825110e4
	if (ctx.cr0.eq) goto loc_825110E4;
	// lfs f11,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f11.f64 = double(temp.f32);
	// b 0x825110e8
	goto loc_825110E8;
loc_825110E4:
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
loc_825110E8:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stfs f0,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r9,r11,20344
	ctx.r9.s64 = ctx.r11.s64 + 20344;
	// lfs f12,20344(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20344);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,24344(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24344);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-8396(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8396);
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
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82514028) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82514030;
	__savegprlr_24(ctx, base);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r4,376(r1)
	REX_STORE_U64(ctx.r1.u32 + 376, ctx.r4.u64);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// std r5,384(r1)
	REX_STORE_U64(ctx.r1.u32 + 384, ctx.r5.u64);
	// lfs f12,388(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 388);
	ctx.f12.f64 = double(temp.f32);
	// std r6,392(r1)
	REX_STORE_U64(ctx.r1.u32 + 392, ctx.r6.u64);
	// lfs f10,392(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 392);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,384(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f0.f64 = double(temp.f32);
	// std r7,400(r1)
	REX_STORE_U64(ctx.r1.u32 + 400, ctx.r7.u64);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lfs f11,400(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r28,r1,112
	ctx.r28.s64 = ctx.r1.s64 + 112;
	// stfs f11,172(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stfs f10,188(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f10,184(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r30,r11,32640
	ctx.r30.s64 = ctx.r11.s64 + 32640;
	// stfs f11,164(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lis r3,-32111
	ctx.r3.s64 = -2104426496;
	// stfs f11,160(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lis r29,-32225
	ctx.r29.s64 = -2111897600;
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r26,-32226
	ctx.r26.s64 = -2111963136;
	// stfs f10,180(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// stfs f10,176(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r29,r29,32256
	ctx.r29.s64 = ctx.r29.s64 + 32256;
	// lfs f9,404(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 404);
	ctx.f9.f64 = double(temp.f32);
	// ld r10,3128(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 3128);
	// lfs f8,396(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 396);
	ctx.f8.f64 = double(temp.f32);
	// li r25,1
	ctx.r25.s64 = 1;
	// lfs f13,376(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// addi r26,r26,2688
	ctx.r26.s64 = ctx.r26.s64 + 2688;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r11.u64);
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r1,176
	ctx.r27.s64 = ctx.r1.s64 + 176;
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r24,r1,192
	ctx.r24.s64 = ctx.r1.s64 + 192;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stw r25,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r25.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stw r26,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r26.u32);
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r10,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r10.u64);
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lfs f7,380(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 380);
	ctx.f7.f64 = double(temp.f32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v58,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f7,108(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v57,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vaddfp128 v59,v57,v59
	simde_mm_store_ps(ctx.v59.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v59.f32)));
	// lvx128 v57,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f7,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vmulfp128 v60,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f7,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f7,96(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f9,172(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f9,168(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f9,164(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f9,160(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f8,140(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f8,136(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f8,132(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f8,128(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// vaddfp128 v61,v61,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v57.f32)));
	// stvx128 v61,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stvx128 v59,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v60,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r28,r1,112
	ctx.r28.s64 = ctx.r1.s64 + 112;
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vmulfp128 v62,v59,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r29,r1,96
	ctx.r29.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r26,r1,192
	ctx.r26.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,376
	ctx.r4.s64 = ctx.r1.s64 + 376;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f12,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vsubfp128 v63,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f12,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// vmulfp128 v63,v63,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
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
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// ld r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8255f918
	ctx.lr = 0x825142B8;
	sub_8255F918(ctx, base);
	// stfs f8,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f8,120(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// stfs f9,140(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vxor128 v62,v61,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stfs f9,136(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// stfs f9,132(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stfs f9,128(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r29,r1,144
	ctx.r29.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f8,116(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f8,112(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// vxor128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r28,0(r28)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r28.u32 + 0);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,176
	ctx.r30.s64 = ctx.r1.s64 + 176;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vmulfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vmulfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f13,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
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
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
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
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
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
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// ld r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82514464;
	sub_8255F918(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// std r28,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r28.u64);
	// lwz r3,-13032(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// std r10,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r10.u64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825144dc
	if (ctx.cr6.eq) goto loc_825144DC;
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,256(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// stfd f13,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.f13.u64);
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r4,180(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// bl 0x823aefa8
	ctx.lr = 0x825144A4;
	sub_823AEFA8(ctx, base);
	// lfs f0,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,81(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.f0.u64);
	// lwz r8,180(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r10,r1,392
	ctx.r10.s64 = ctx.r1.s64 + 392;
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x823b0938
	ctx.lr = 0x825144DC;
	sub_823B0938(ctx, base);
loc_825144DC:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82548300) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82548308;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,292(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,1608
	ctx.r11.s64 = ctx.r11.s64 + 1608;
	// lfs f0,268(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 268);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8254842c
	if (!ctx.cr6.lt) goto loc_8254842C;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x823bfa70
	ctx.lr = 0x82548340;
	sub_823BFA70(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x8254868c
	if (!ctx.cr6.lt) goto loc_8254868C;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,232(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 232);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8254836C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r29,r3,16
	ctx.r29.u64 = ctx.r3.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x8254868c
	if (ctx.cr0.eq) goto loc_8254868C;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8254868c
	if (ctx.cr6.eq) goto loc_8254868C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
loc_82548388:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r7,0
	ctx.r7.s64 = 0;
	// clrlwi r6,r30,16
	ctx.r6.u64 = ctx.r30.u32 & 0xFFFF;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825483B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8254841c
	if (ctx.cr0.eq) goto loc_8254841C;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82548404
	if (!ctx.cr6.lt) goto loc_82548404;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// neg r10,r10
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// stw r7,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r7.u32);
	// stw r6,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r6.u32);
	// stw r11,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r11.u32);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
loc_82548404:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8254841C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8254841C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x82548388
	if (ctx.cr6.lt) goto loc_82548388;
	// b 0x8254868c
	goto loc_8254868C;
loc_8254842C:
	// lbz r10,324(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 324);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8254868c
	if (ctx.cr0.eq) goto loc_8254868C;
	// ld r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f11,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,296(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// addi r10,r6,-30512
	ctx.r10.s64 = ctx.r6.s64 + -30512;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r30,r1,128
	ctx.r30.s64 = ctx.r1.s64 + 128;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lis r5,-32240
	ctx.r5.s64 = -2112880640;
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lis r29,-32225
	ctx.r29.s64 = -2111897600;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r29,32496
	ctx.r29.s64 = ctx.r29.s64 + 32496;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lis r27,-32226
	ctx.r27.s64 = -2111963136;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r10,-13032(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// addi r27,r27,2688
	ctx.r27.s64 = ctx.r27.s64 + 2688;
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stw r26,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r26.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r27,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r27.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
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
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f10,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f10.f64 = double(temp.f32);
	// fadds f12,f10,f0
	ctx.f12.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// lfs f0,-29492(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v60,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stfs f10,140(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f10,132(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
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
	// stvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v58,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f13,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vsubfp128 v63,v58,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v58,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v58,v60
	simde_mm_store_ps(ctx.v60.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r11.u64);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.r11.u64);
	// beq cr6,0x8254868c
	if (ctx.cr6.eq) goto loc_8254868C;
	// lfs f0,196(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,81(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// addi r10,r10,2880
	ctx.r10.s64 = ctx.r10.s64 + 2880;
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x823b0938
	ctx.lr = 0x8254868C;
	sub_823B0938(ctx, base);
loc_8254868C:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825651D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825651E0;
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
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r30,r3,344
	ctx.r30.s64 = ctx.r3.s64 + 344;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,5856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 5856);
	// lfs f29,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f29.f64 = double(temp.f32);
	// stfs f29,88(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f29,92(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// bl 0x82565428
	ctx.lr = 0x8256521C;
	sub_82565428(ctx, base);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// li r31,0
	ctx.r31.s64 = 0;
	// lis r29,-32228
	ctx.r29.s64 = -2112094208;
	// lis r28,-32114
	ctx.r28.s64 = -2104623104;
	// lwz r11,5860(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 5860);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f30,488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 488);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f31.f64 = double(temp.f32);
loc_82565244:
	// clrldi r11,r31,32
	ctx.r11.u64 = ctx.r31.u64 & 0xFFFFFFFF;
	// lfs f0,5840(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 5840);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmuls f8,f0,f30
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fadds f1,f8,f31
	ctx.f1.f64 = double(float(ctx.f8.f64 + ctx.f31.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x8256526C;
	sub_822EA1A8(ctx, base);
	// lfs f9,-8956(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -8956);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f0,f1,f9
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f1,f8
	ctx.f1.f64 = ctx.f8.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x82565280;
	sub_822EA1A8(ctx, base);
	// fmuls f0,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82565428
	ctx.lr = 0x82565294;
	sub_82565428(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 30, ctx.xer);
	// blt cr6,0x82565244
	if (ctx.cr6.lt) goto loc_82565244;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x825652A8;
	sub_822EA1A8(ctx, base);
	// lfs f9,-8956(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -8956);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f0,f1,f9
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x825652BC;
	sub_822EA1A8(ctx, base);
	// fmuls f0,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82565428
	ctx.lr = 0x825652D0;
	sub_82565428(ctx, base);
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

DEFINE_REX_FUNC(sub_8256E298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8256E2A0;
	__savegprlr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,68
	ctx.r7.s64 = 68;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x8256E2D0;
	sub_825190E8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stb r27,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r27.u8);
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r10,r10,11104
	ctx.r10.s64 = ctx.r10.s64 + 11104;
	// stb r29,308(r31)
	REX_STORE_U8(ctx.r31.u32 + 308, ctx.r29.u8);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// bne cr6,0x8256e30c
	if (!ctx.cr6.eq) goto loc_8256E30C;
	// lfs f0,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8256e310
	goto loc_8256E310;
loc_8256E30C:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_8256E310:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,100(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r10,9
	ctx.r10.s64 = 9;
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// rlwimi r9,r10,0,30,31
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFFC);
	// stw r29,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r29.u32);
	// ori r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 | 32;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// rlwimi r9,r10,0,28,28
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFF7);
	// rlwinm r10,r7,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFF0;
	// stw r8,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// stw r9,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r9.u32);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8256e3a4
	if (!ctx.cr6.eq) goto loc_8256E3A4;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8256e3a4
	if (ctx.cr6.eq) goto loc_8256E3A4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8256e3a4
	if (ctx.cr0.eq) goto loc_8256E3A4;
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8256e3a4
	if (ctx.cr6.eq) goto loc_8256E3A4;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256E398;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8256e3a4
	if (!ctx.cr6.eq) goto loc_8256E3A4;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8256E3A4:
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f12,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8256e48c
	if (!ctx.cr0.eq) goto loc_8256E48C;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lfs f0,-1560(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1560);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r7,-31824
	ctx.r7.s64 = ctx.r7.s64 + -31824;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f13,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
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
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x8256e558
	goto loc_8256E558;
loc_8256E48C:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r10,r10,-29424
	ctx.r10.s64 = ctx.r10.s64 + -29424;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f0,-1560(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1560);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// lvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_8256E558:
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r29,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r29.u8);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82586B40) {
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
	// bl 0x8258c490
	ctx.lr = 0x82586B60;
	sub_8258C490(ctx, base);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r8,r8,14356
	ctx.r8.s64 = ctx.r8.s64 + 14356;
	// stb r11,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r11.u8);
	// lfs f0,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stb r10,18(r31)
	REX_STORE_U8(ctx.r31.u32 + 18, ctx.r10.u8);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stw r10,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stb r11,17(r31)
	REX_STORE_U8(ctx.r31.u32 + 17, ctx.r11.u8);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r11,19(r31)
	REX_STORE_U8(ctx.r31.u32 + 19, ctx.r11.u8);
	// addi r8,r31,32
	ctx.r8.s64 = ctx.r31.s64 + 32;
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// addi r4,r31,48
	ctx.r4.s64 = ctx.r31.s64 + 48;
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stfs f0,84(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 84, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 88, temp.u32);
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stfs f0,92(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 92, temp.u32);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// stfs f0,96(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 96, temp.u32);
	// stw r9,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// bne cr6,0x82586bf4
	if (!ctx.cr6.eq) goto loc_82586BF4;
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_82586BF4:
	// lwz r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r9,8(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82586c40
	if (ctx.cr6.eq) goto loc_82586C40;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmplw cr6,r9,r9
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82586c3c
	if (ctx.cr6.eq) goto loc_82586C3C;
loc_82586C10:
	// li r7,5
	ctx.r7.s64 = 5;
	// addi r6,r11,-4
	ctx.r6.s64 = ctx.r11.s64 + -4;
	// addi r5,r10,-4
	ctx.r5.s64 = ctx.r10.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82586C20:
	// lwzu r7,4(r6)
	ea = 4 + ctx.r6.u32;
	ctx.r7.u64 = REX_LOAD_U32(ea);
	ctx.r6.u32 = ea;
	// stwu r7,4(r5)
	ea = 4 + ctx.r5.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r5.u32 = ea;
	// bdnz 0x82586c20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82586C20;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82586c10
	if (!ctx.cr6.eq) goto loc_82586C10;
loc_82586C3C:
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
loc_82586C40:
	// lwz r9,4(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82586c80
	if (ctx.cr6.eq) goto loc_82586C80;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82586c7c
	if (ctx.cr6.eq) goto loc_82586C7C;
loc_82586C5C:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82586c5c
	if (!ctx.cr6.eq) goto loc_82586C5C;
loc_82586C7C:
	// stw r9,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
loc_82586C80:
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

DEFINE_REX_FUNC(sub_8258E000) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8258E008;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8258E024;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8258e378
	if (ctx.cr0.eq) goto loc_8258E378;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12972(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12972);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258e058
	if (ctx.cr6.eq) goto loc_8258E058;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,916(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 916);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8258e058
	if (ctx.cr6.lt) goto loc_8258E058;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// ble cr6,0x8258e05c
	if (!ctx.cr6.gt) goto loc_8258E05C;
loc_8258E058:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8258E05C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8258e378
	if (!ctx.cr0.eq) goto loc_8258E378;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-12852(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12852);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258e07c
	if (ctx.cr6.eq) goto loc_8258E07C;
	// lbz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
loc_8258E07C:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8258e0a4
	if (ctx.cr0.eq) goto loc_8258E0A4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258e094
	if (ctx.cr6.eq) goto loc_8258E094;
	// lbz r11,17(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 17);
	// b 0x8258e098
	goto loc_8258E098;
loc_8258E094:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8258E098:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq 0x8258e0a8
	if (ctx.cr0.eq) goto loc_8258E0A8;
loc_8258E0A4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8258E0A8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8258e378
	if (!ctx.cr0.eq) goto loc_8258E378;
	// lwz r3,124(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x824443c8
	ctx.lr = 0x8258E0B8;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8258e378
	if (ctx.cr0.eq) goto loc_8258E378;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x8245d190
	ctx.lr = 0x8258E0C8;
	sub_8245D190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8258eb28
	ctx.lr = 0x8258E0D4;
	sub_8258EB28(ctx, base);
	// li r29,-1
	ctx.r29.s64 = -1;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f3,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f3.f64 = double(temp.f32);
	// lis r8,-256
	ctx.r8.s64 = -16777216;
	// lfs f2,56(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f2.f64 = double(temp.f32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lfs f1,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// ori r9,r9,8191
	ctx.r9.u64 = ctx.r9.u64 | 8191;
	// ori r8,r8,255
	ctx.r8.u64 = ctx.r8.u64 | 255;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8258e660
	ctx.lr = 0x8258E104;
	sub_8258E660(ctx, base);
	// lis r10,-1823
	ctx.r10.s64 = -119472128;
	// lis r9,95
	ctx.r9.s64 = 6225920;
	// lfs f3,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f3.f64 = double(temp.f32);
	// lis r8,247
	ctx.r8.s64 = 16187392;
	// lfs f2,60(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f2.f64 = double(temp.f32);
	// ori r10,r10,18943
	ctx.r10.u64 = ctx.r10.u64 | 18943;
	// lfs f1,68(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f1.f64 = double(temp.f32);
	// ori r9,r9,20223
	ctx.r9.u64 = ctx.r9.u64 | 20223;
	// ori r8,r8,1279
	ctx.r8.u64 = ctx.r8.u64 | 1279;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8258e660
	ctx.lr = 0x8258E134;
	sub_8258E660(ctx, base);
	// lbz r3,121(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 121);
	// bl 0x82443da0
	ctx.lr = 0x8258E13C;
	sub_82443DA0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258e178
	if (ctx.cr6.eq) goto loc_8258E178;
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
	// ble cr6,0x8258e178
	if (!ctx.cr6.gt) goto loc_8258E178;
	// mulli r11,r3,808
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(808));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lhz r4,660(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 660);
	// b 0x8258e17c
	goto loc_8258E17C;
loc_8258E178:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8258E17C:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// addi r30,r11,-22012
	ctx.r30.s64 = ctx.r11.s64 + -22012;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f13,1016(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 1016);
	ctx.f13.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f0,-8116(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -8116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 40, temp.u32);
	// stfs f0,44(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 44, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lfs f0,28(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,96(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// lwz r10,112(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// addi r6,r11,58
	ctx.r6.s64 = ctx.r11.s64 + 58;
	// addi r5,r10,29
	ctx.r5.s64 = ctx.r10.s64 + 29;
	// bl 0x823be020
	ctx.lr = 0x8258E1E0;
	sub_823BE020(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = ctx.r31.s64 + 20;
	// bl 0x8245d190
	ctx.lr = 0x8258E1E8;
	sub_8245D190(ctx, base);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lbz r28,128(r31)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r31.u32 + 128);
	// addi r11,r11,10464
	ctx.r11.s64 = ctx.r11.s64 + 10464;
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8258e23c
	if (ctx.cr6.eq) goto loc_8258E23C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8258E218;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8258e23c
	if (ctx.cr0.eq) goto loc_8258E23C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8258E230;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// subfe r11,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x8258e240
	goto loc_8258E240;
loc_8258E23C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8258E240:
	// clrlwi. r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r29,r11,17272
	ctx.r29.s64 = ctx.r11.s64 + 17272;
	// beq 0x8258e2a0
	if (ctx.cr0.eq) goto loc_8258E2A0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8242a868
	ctx.lr = 0x8258E258;
	sub_8242A868(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8258e2a0
	if (ctx.cr0.eq) goto loc_8258E2A0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f5,-19460(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -19460);
	ctx.f5.f64 = double(temp.f32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f4,-7752(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -7752);
	ctx.f4.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f2,5808(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5808);
	ctx.f2.f64 = double(temp.f32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lfs f1,-5324(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -5324);
	ctx.f1.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f7,1024(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1024);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,3064(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3064);
	ctx.f6.f64 = double(temp.f32);
	// stb r8,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r8.u8);
	// lfs f3,15324(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15324);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x8258e8f0
	ctx.lr = 0x8258E2A0;
	sub_8258E8F0(ctx, base);
loc_8258E2A0:
	// addi r3,r31,36
	ctx.r3.s64 = ctx.r31.s64 + 36;
	// bl 0x8245d190
	ctx.lr = 0x8258E2A8;
	sub_8245D190(ctx, base);
	// lbz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8258e2c0
	if (ctx.cr0.eq) goto loc_8258E2C0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8258ed80
	ctx.lr = 0x8258E2C0;
	sub_8258ED80(ctx, base);
loc_8258E2C0:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8258e2d8
	if (!ctx.cr6.eq) goto loc_8258E2D8;
	// li r28,0
	ctx.r28.s64 = 0;
	// b 0x8258e2e4
	goto loc_8258E2E4;
loc_8258E2D8:
	// li r3,2343
	ctx.r3.s64 = 2343;
	// bl 0x8257a428
	ctx.lr = 0x8258E2E0;
	sub_8257A428(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_8258E2E4:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8258e378
	if (!ctx.cr6.gt) goto loc_8258E378;
	// lbz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8258e378
	if (!ctx.cr0.eq) goto loc_8258E378;
	// li r3,2343
	ctx.r3.s64 = 2343;
	// bl 0x823b4f20
	ctx.lr = 0x8258E304;
	sub_823B4F20(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f6,-26228(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -26228);
	ctx.f6.f64 = double(temp.f32);
	// stb r11,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r11.u8);
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lfs f2,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// lfs f1,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// srawi r9,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 4;
	// fmr f5,f6
	ctx.f5.f64 = ctx.f6.f64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfs f7,1028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1028);
	ctx.f7.f64 = double(temp.f32);
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// fmuls f4,f0,f6
	ctx.f4.f64 = double(float(ctx.f0.f64 * ctx.f6.f64));
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f3,f13,f6
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// bl 0x8258e8f0
	ctx.lr = 0x8258E378;
	sub_8258E8F0(ctx, base);
loc_8258E378:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825A7E10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f1,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825A82C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825A82C8;
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
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x825a8378
	if (!ctx.cr6.eq) goto loc_825A8378;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// li r31,736
	ctx.r31.s64 = 736;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// lfs f31,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
loc_825A82F4:
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
	ctx.lr = 0x825A831C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fabs f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x825a833c
	if (ctx.cr6.gt) goto loc_825A833C;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r31,752
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 752, ctx.xer);
	// blt cr6,0x825a82f4
	if (ctx.cr6.lt) goto loc_825A82F4;
	// b 0x825a8370
	goto loc_825A8370;
loc_825A833C:
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
	ctx.lr = 0x825A836C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
loc_825A8370:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// b 0x825a83ac
	goto loc_825A83AC;
loc_825A8378:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r4,184
	ctx.r9.s64 = ctx.r4.s64 + 184;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-12768(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -12768);
	// lwzx r10,r9,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
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
	ctx.lr = 0x825A83AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825A83AC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825AF6E0) {
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
	// ble cr6,0x825af700
	if (!ctx.cr6.gt) goto loc_825AF700;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,-9856(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9856);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f1.f64));
	// b 0x825af70c
	goto loc_825AF70C;
loc_825AF700:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
loc_825AF70C:
	// stfs f0,32(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825B0BE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825B0BF0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32111
	ctx.r30.s64 = -2104426496;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,2496(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2496);
	// bl 0x8263b630
	ctx.lr = 0x825B0C08;
	sub_8263B630(ctx, base);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r5,400
	ctx.r5.s64 = 400;
	// lwz r31,-16176(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + -16176);
	// lwz r11,-16168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -16168);
	// mulli r10,r31,400
	ctx.r10.s64 = static_cast<int64_t>(ctx.r31.u64 * static_cast<uint64_t>(400));
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x8273a030
	ctx.lr = 0x825B0C2C;
	sub_8273A030(ctx, base);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// lwz r3,2496(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2496);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// stw r11,-16176(r29)
	REX_STORE_U32(ctx.r29.u32 + -16176, ctx.r11.u32);
	// bl 0x8263b638
	ctx.lr = 0x825B0C40;
	sub_8263B638(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B4C40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x825B4C48;
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
	// bl 0x82855b44
	ctx.lr = 0x825B4C60;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825b3350
	ctx.lr = 0x825B4C68;
	sub_825B3350(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b4d28
	if (ctx.cr6.lt) goto loc_825B4D28;
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825b4c9c
	if (!ctx.cr6.eq) goto loc_825B4C9C;
	// lis r28,-30009
	ctx.r28.s64 = -1966669824;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// ori r28,r28,4
	ctx.r28.u64 = ctx.r28.u64 | 4;
	// bl 0x82855b34
	ctx.lr = 0x825B4C90;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_825B4C9C:
	// lwz r3,164(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// addi r29,r31,160
	ctx.r29.s64 = ctx.r31.s64 + 160;
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x825b4d28
	if (ctx.cr6.eq) goto loc_825B4D28;
loc_825B4CAC:
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825b4cec
	if (ctx.cr6.eq) goto loc_825B4CEC;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// addi r8,r11,26
	ctx.r8.s64 = ctx.r11.s64 + 26;
loc_825B4CC4:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x825b4ce4
	if (!ctx.cr0.eq) goto loc_825B4CE4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x825b4cc4
	if (!ctx.cr6.eq) goto loc_825B4CC4;
loc_825B4CE4:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x825b4d1c
	if (!ctx.cr6.eq) goto loc_825B4D1C;
loc_825B4CEC:
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
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
	ctx.lr = 0x825B4D1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825B4D1C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x825b4cac
	if (!ctx.cr6.eq) goto loc_825B4CAC;
loc_825B4D28:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82855b34
	ctx.lr = 0x825B4D30;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825BA208) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825BA210;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r11,204
	ctx.r29.s64 = ctx.r11.s64 + 204;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b44
	ctx.lr = 0x825BA228;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BA23C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r9,r3,0,29,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x6;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x825ba264
	if (!ctx.cr6.eq) goto loc_825BA264;
	// lis r30,-30009
	ctx.r30.s64 = -1966669824;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ori r30,r30,6
	ctx.r30.u64 = ctx.r30.u64 | 6;
	// bl 0x82855b34
	ctx.lr = 0x825BA258;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
loc_825BA264:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,56(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x825bbaa8
	ctx.lr = 0x825BA270;
	sub_825BBAA8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825ba288
	if (ctx.cr6.lt) goto loc_825BA288;
	// lwz r3,56(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x825c5728
	ctx.lr = 0x825BA284;
	sub_825C5728(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_825BA288:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x825BA290;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825BCB20) {
	REX_FUNC_PROLOGUE();
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r7,r11,24712
	ctx.r7.s64 = ctx.r11.s64 + 24712;
	// lis r6,-32225
	ctx.r6.s64 = -2111897600;
	// addi r30,r10,20700
	ctx.r30.s64 = ctx.r10.s64 + 20700;
	// stw r7,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// addi r9,r9,18140
	ctx.r9.s64 = ctx.r9.s64 + 18140;
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r6,r6,18888
	ctx.r6.s64 = ctx.r6.s64 + 18888;
	// stw r10,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// lis r5,-32225
	ctx.r5.s64 = -2111897600;
	// stw r9,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// lis r31,-32225
	ctx.r31.s64 = -2111897600;
	// stw r6,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r11,r3,28
	ctx.r11.s64 = ctx.r3.s64 + 28;
	// stw r4,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r4.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r10,r7,18988
	ctx.r10.s64 = ctx.r7.s64 + 18988;
	// addi r5,r5,18980
	ctx.r5.s64 = ctx.r5.s64 + 18980;
	// addi r6,r31,18992
	ctx.r6.s64 = ctx.r31.s64 + 18992;
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r5,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// stw r6,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// stw r9,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r9,232(r3)
	REX_STORE_U32(ctx.r3.u32 + 232, ctx.r9.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// stw r9,236(r3)
	REX_STORE_U32(ctx.r3.u32 + 236, ctx.r9.u32);
	// stw r9,240(r3)
	REX_STORE_U32(ctx.r3.u32 + 240, ctx.r9.u32);
	// stw r8,244(r3)
	REX_STORE_U32(ctx.r3.u32 + 244, ctx.r8.u32);
	// stw r7,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r7.u32);
	// stw r9,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
loc_825BCBC0:
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// addi r7,r8,4
	ctx.r7.s64 = ctx.r8.s64 + 4;
	// stw r6,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r6.u32);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// bdnz 0x825bcbc0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825BCBC0;
	// stw r9,248(r3)
	REX_STORE_U32(ctx.r3.u32 + 248, ctx.r9.u32);
	// stw r9,252(r3)
	REX_STORE_U32(ctx.r3.u32 + 252, ctx.r9.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825C1CD0) {
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
	// lfs f0,84(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// addi r5,r3,8
	ctx.r5.s64 = ctx.r3.s64 + 8;
	// lwz r8,0(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r6,52
	ctx.r6.s64 = 52;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stb r9,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r9.u8);
	// lwz r9,48(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// stb r9,17(r3)
	REX_STORE_U8(ctx.r3.u32 + 17, ctx.r9.u8);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stb r9,18(r3)
	REX_STORE_U8(ctx.r3.u32 + 18, ctx.r9.u8);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stb r9,19(r3)
	REX_STORE_U8(ctx.r3.u32 + 19, ctx.r9.u8);
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// stb r9,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r9.u8);
	// lwz r9,20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// stb r9,21(r3)
	REX_STORE_U8(ctx.r3.u32 + 21, ctx.r9.u8);
	// lwz r9,24(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// stb r9,22(r3)
	REX_STORE_U8(ctx.r3.u32 + 22, ctx.r9.u8);
	// lwz r9,28(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// stb r9,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r9.u8);
	// lwz r9,32(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// stb r9,24(r3)
	REX_STORE_U8(ctx.r3.u32 + 24, ctx.r9.u8);
	// lwz r9,36(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// stb r9,25(r3)
	REX_STORE_U8(ctx.r3.u32 + 25, ctx.r9.u8);
	// lwz r9,40(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// stb r9,26(r3)
	REX_STORE_U8(ctx.r3.u32 + 26, ctx.r9.u8);
	// lwz r9,44(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// stb r9,27(r3)
	REX_STORE_U8(ctx.r3.u32 + 27, ctx.r9.u8);
	// lfs f13,52(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// lfs f12,56(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r8,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// lfs f11,60(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 60);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
	// lfs f10,64(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r8,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r8.u32);
	// lfs f9,68(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 68);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// lfs f8,72(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 72);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r8,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// lfs f7,76(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 76);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r9.u32);
	// lfs f6,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r8,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825C1E00;
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

DEFINE_REX_FUNC(sub_825CCEA0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,68(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825CD000) {
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
	// bl 0x825ce3c8
	ctx.lr = 0x825CD018;
	sub_825CE3C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CD02C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cd068
	if (ctx.cr6.eq) goto loc_825CD068;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CD048;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825CD068;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825CD068:
	// bl 0x825b32d0
	ctx.lr = 0x825CD06C;
	sub_825B32D0(ctx, base);
	// stw r3,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r3.u32);
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

DEFINE_REX_FUNC(sub_825D09D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825D09E0;
	__savegprlr_29(ctx, base);
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
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D0A00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d0a3c
	if (ctx.cr6.eq) goto loc_825D0A3C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D0A1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825D0A34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
loc_825D0A3C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825D5858) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x825D5860;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825d589c
	if (!ctx.cr6.eq) goto loc_825D589C;
	// bl 0x825d5690
	ctx.lr = 0x825D5894;
	sub_825D5690(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_825D589C:
	// bl 0x825d5690
	ctx.lr = 0x825D58A0;
	sub_825D5690(ctx, base);
	// cmplwi cr6,r3,258
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 258, ctx.xer);
	// bne cr6,0x825d59ec
	if (!ctx.cr6.eq) goto loc_825D59EC;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x825d58f8
	if (ctx.cr6.eq) goto loc_825D58F8;
	// li r29,1000
	ctx.r29.s64 = 1000;
loc_825D58B4:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_825D58BC:
	// db16cyc 
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x825d58bc
	if (!ctx.cr0.lt) goto loc_825D58BC;
	// cmpwi cr6,r30,511
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 511, ctx.xer);
	// bgt cr6,0x825d58d8
	if (ctx.cr6.gt) goto loc_825D58D8;
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
loc_825D58D8:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
	// bl 0x825d5690
	ctx.lr = 0x825D58E8;
	sub_825D5690(ctx, base);
	// cmplwi cr6,r3,258
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 258, ctx.xer);
	// bne cr6,0x825d59ec
	if (!ctx.cr6.eq) goto loc_825D59EC;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x825d58b4
	if (!ctx.cr0.eq) goto loc_825D58B4;
loc_825D58F8:
	// addi r26,r31,32
	ctx.r26.s64 = ctx.r31.s64 + 32;
loc_825D58FC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r26
	ea = ctx.r26.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d58fc
	if (!ctx.cr0.eq) goto loc_825D58FC;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825d5690
	ctx.lr = 0x825D5924;
	sub_825D5690(ctx, base);
	// cmplwi cr6,r3,258
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 258, ctx.xer);
	// bne cr6,0x825d59d0
	if (!ctx.cr6.eq) goto loc_825D59D0;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
loc_825D5930:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x825d5960
	if (ctx.cr6.eq) goto loc_825D5960;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_825D5940:
	// db16cyc 
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x825d5940
	if (!ctx.cr0.lt) goto loc_825D5940;
	// cmpwi cr6,r30,511
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 511, ctx.xer);
	// bgt cr6,0x825d595c
	if (ctx.cr6.gt) goto loc_825D595C;
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
loc_825D595C:
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
loc_825D5960:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x825d599c
	if (!ctx.cr6.eq) goto loc_825D599C;
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x825d597c
	if (!ctx.cr6.eq) goto loc_825D597C;
	// li r3,258
	ctx.r3.s64 = 258;
	// b 0x825d59b4
	goto loc_825D59B4;
loc_825D597C:
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x8263d958
	ctx.lr = 0x825D5988;
	sub_8263D958(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x825d59b4
	if (!ctx.cr6.gt) goto loc_825D59B4;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// or r3,r11,r29
	ctx.r3.u64 = ctx.r11.u64 | ctx.r29.u64;
	// b 0x825d59b4
	goto loc_825D59B4;
loc_825D599C:
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bctrl 
	ctx.lr = 0x825D59B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825D59B4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825d59f4
	if (!ctx.cr6.eq) goto loc_825D59F4;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825d5690
	ctx.lr = 0x825D59C8;
	sub_825D5690(ctx, base);
	// cmplwi cr6,r3,258
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 258, ctx.xer);
	// beq cr6,0x825d5930
	if (ctx.cr6.eq) goto loc_825D5930;
loc_825D59D0:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r26
	ea = ctx.r26.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d59d0
	if (!ctx.cr0.eq) goto loc_825D59D0;
loc_825D59EC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_825D59F4:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r26
	ea = ctx.r26.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d59f4
	if (!ctx.cr0.eq) goto loc_825D59F4;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E6DC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825E6DC8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r4,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r4.u64);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x825e6de4
	if (!ctx.cr6.eq) goto loc_825E6DE4;
	// addi r29,r1,88
	ctx.r29.s64 = ctx.r1.s64 + 88;
loc_825E6DE4:
	// li r11,0
	ctx.r11.s64 = 0;
	// std r11,0(r29)
	REX_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x825e6e04
	if (!ctx.cr6.eq) goto loc_825E6E04;
	// lis r3,-16379
	ctx.r3.s64 = -1073414144;
	// ori r3,r3,15
	ctx.r3.u64 = ctx.r3.u64 | 15;
	// b 0x825e6ed4
	goto loc_825E6ED4;
loc_825E6E04:
	// lbz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 20);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825e6e1c
	if (ctx.cr0.eq) goto loc_825E6E1C;
	// lis r3,-16379
	ctx.r3.s64 = -1073414144;
	// ori r3,r3,11
	ctx.r3.u64 = ctx.r3.u64 | 11;
	// b 0x825e6ed4
	goto loc_825E6ED4;
loc_825E6E1C:
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// blt cr6,0x825e6e54
	if (ctx.cr6.lt) goto loc_825E6E54;
	// beq cr6,0x825e6e4c
	if (ctx.cr6.eq) goto loc_825E6E4C;
	// cmplwi cr6,r5,3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 3, ctx.xer);
	// blt cr6,0x825e6e3c
	if (ctx.cr6.lt) goto loc_825E6E3C;
	// lis r3,-16379
	ctx.r3.s64 = -1073414144;
	// ori r3,r3,12
	ctx.r3.u64 = ctx.r3.u64 | 12;
	// b 0x825e6ed4
	goto loc_825E6ED4;
loc_825E6E3C:
	// li r30,1
	ctx.r30.s64 = 1;
	// cmpdi cr6,r4,0
	ctx.cr6.compare<int64_t>(ctx.r4.s64, 0, ctx.xer);
	// bne cr6,0x825e6e64
	if (!ctx.cr6.eq) goto loc_825E6E64;
	// b 0x825e6ec8
	goto loc_825E6EC8;
loc_825E6E4C:
	// li r30,2
	ctx.r30.s64 = 2;
	// b 0x825e6e64
	goto loc_825E6E64;
loc_825E6E54:
	// ld r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 8);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpld cr6,r11,r4
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r4.u64, ctx.xer);
	// beq cr6,0x825e6ec8
	if (ctx.cr6.eq) goto loc_825E6EC8;
loc_825E6E64:
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8263a4c0
	ctx.lr = 0x825E6E74;
	sub_8263A4C0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82748c08
	ctx.lr = 0x825E6E88;
	sub_82748C08(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x825e6eb8
	if (!ctx.cr0.eq) goto loc_825E6EB8;
	// bl 0x82639f50
	ctx.lr = 0x825E6E94;
	sub_82639F50(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825e6ed0
	if (ctx.cr0.eq) goto loc_825E6ED0;
	// cmplwi cr6,r3,18
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 18, ctx.xer);
	// lis r3,-16379
	ctx.r3.s64 = -1073414144;
	// beq cr6,0x825e6eb0
	if (ctx.cr6.eq) goto loc_825E6EB0;
	// ori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 | 1;
	// b 0x825e6ed4
	goto loc_825E6ED4;
loc_825E6EB0:
	// ori r3,r3,4
	ctx.r3.u64 = ctx.r3.u64 | 4;
	// b 0x825e6ed4
	goto loc_825E6ED4;
loc_825E6EB8:
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x8263a4c0
	ctx.lr = 0x825E6EC8;
	sub_8263A4C0(ctx, base);
loc_825E6EC8:
	// ld r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 8);
	// std r11,0(r29)
	REX_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
loc_825E6ED0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825E6ED4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825EB418) {
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
	// bl 0x825ea7d0
	ctx.lr = 0x825EB434;
	sub_825EA7D0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r11,24376
	ctx.r11.s64 = ctx.r11.s64 + 24376;
	// addi r10,r10,24432
	ctx.r10.s64 = ctx.r10.s64 + 24432;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addi r31,r30,152
	ctx.r31.s64 = ctx.r30.s64 + 152;
	// stw r10,152(r30)
	REX_STORE_U32(ctx.r30.u32 + 152, ctx.r10.u32);
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x82856014
	ctx.lr = 0x825EB45C;
	__imp__RtlInitializeCriticalSectionAndSpinCount(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r11,r31,36
	ctx.r11.s64 = ctx.r31.s64 + 36;
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// stb r8,184(r30)
	REX_STORE_U8(ctx.r30.u32 + 184, ctx.r8.u8);
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r8,r11,-20
	ctx.r8.s64 = ctx.r11.s64 + -20;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r7,24104
	ctx.r7.s64 = ctx.r7.s64 + 24104;
loc_825EB484:
	// stwu r7,20(r8)
	ea = 20 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// stw r9,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// stw r9,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// stwu r9,20(r10)
	ea = 20 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x825eb484
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825EB484;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r9,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r9.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825eaa58
	ctx.lr = 0x825EB4B0;
	sub_825EAA58(ctx, base);
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

DEFINE_REX_FUNC(sub_825F1980) {
	REX_FUNC_PROLOGUE();
	// stw r4,112(r3)
	REX_STORE_U32(ctx.r3.u32 + 112, ctx.r4.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825F1AB8) {
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
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f1aec
	if (ctx.cr6.eq) goto loc_825F1AEC;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1AEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825F1AEC:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f1b0c
	if (ctx.cr6.eq) goto loc_825F1B0C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1B0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825F1B0C:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f1b2c
	if (ctx.cr6.eq) goto loc_825F1B2C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1B2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825F1B2C:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f1b4c
	if (ctx.cr6.eq) goto loc_825F1B4C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1B4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825F1B4C:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f1b6c
	if (ctx.cr6.eq) goto loc_825F1B6C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1B6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825F1B6C:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f1b8c
	if (ctx.cr6.eq) goto loc_825F1B8C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1B8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825F1B8C:
	// addi r31,r31,44
	ctx.r31.s64 = ctx.r31.s64 + 44;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and. r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 & ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825f1bbc
	if (ctx.cr0.eq) goto loc_825F1BBC;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1BBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825F1BBC:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f1bcc
	if (ctx.cr6.eq) goto loc_825F1BCC;
	// bl 0x822130c8
	ctx.lr = 0x825F1BCC;
	sub_822130C8(ctx, base);
loc_825F1BCC:
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

DEFINE_REX_FUNC(sub_825F7FC8) {
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
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,4
	ctx.r11.s64 = 4;
	// lwz r3,32(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F800C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r11,128
	ctx.r11.s64 = 128;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq cr6,0x825f8074
	if (ctx.cr6.eq) goto loc_825F8074;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x825f8074
	if (ctx.cr6.eq) goto loc_825F8074;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82764588
	ctx.lr = 0x825F8038;
	sub_82764588(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x825f8074
	if (!ctx.cr0.eq) goto loc_825F8074;
	// addi r11,r31,20
	ctx.r11.s64 = ctx.r31.s64 + 20;
	// addi r10,r1,152
	ctx.r10.s64 = ctx.r1.s64 + 152;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
loc_825F804C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x825f806c
	if (!ctx.cr0.eq) goto loc_825F806C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x825f804c
	if (!ctx.cr6.eq) goto loc_825F804C;
loc_825F806C:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x825f809c
	if (ctx.cr0.eq) goto loc_825F809C;
loc_825F8074:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// addi r11,r11,10304
	ctx.r11.s64 = ctx.r11.s64 + 10304;
	// lwz r10,80(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825f809c
	if (ctx.cr6.eq) goto loc_825F809C;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F809C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825F809C:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
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

DEFINE_REX_FUNC(sub_825FD948) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x825FD950;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// sth r11,88(r1)
	REX_STORE_U16(ctx.r1.u32 + 88, ctx.r11.u16);
	// sth r11,90(r1)
	REX_STORE_U16(ctx.r1.u32 + 90, ctx.r11.u16);
	// beq cr6,0x825fda00
	if (ctx.cr6.eq) goto loc_825FDA00;
	// lis r11,5461
	ctx.r11.s64 = 357892096;
	// ori r11,r11,21845
	ctx.r11.u64 = ctx.r11.u64 | 21845;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825fd9dc
	if (!ctx.cr6.gt) goto loc_825FD9DC;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,56
	ctx.r4.s64 = ctx.r11.s64 + 56;
	// bl 0x822167f8
	ctx.lr = 0x825FD9A4;
	sub_822167F8(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82216678
	ctx.lr = 0x825FD9B0;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x825FD9B4;
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
	ctx.lr = 0x825FD9C8;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235ec48
	ctx.lr = 0x825FD9D8;
	sub_8235EC48(ctx, base);
	// b 0x825fd9fc
	goto loc_825FD9FC;
loc_825FD9DC:
	// mulli r29,r30,12
	ctx.r29.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(12));
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825f8d38
	ctx.lr = 0x825FD9EC;
	sub_825F8D38(ctx, base);
	// add r11,r29,r3
	ctx.r11.u64 = ctx.r29.u64 + ctx.r3.u64;
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_825FD9FC:
	// li r11,1
	ctx.r11.s64 = 1;
loc_825FDA00:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825fda4c
	if (ctx.cr0.eq) goto loc_825FDA4C;
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// beq cr6,0x825fda40
	if (ctx.cr6.eq) goto loc_825FDA40;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_825FDA1C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825fda34
	if (ctx.cr6.eq) goto loc_825FDA34;
	// lwz r8,88(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// stw r27,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
loc_825FDA34:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// bne 0x825fda1c
	if (!ctx.cr0.eq) goto loc_825FDA1C;
loc_825FDA40:
	// mulli r11,r30,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(12));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_825FDA4C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82606B88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82606B90;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r3,-11544(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -11544);
	// bl 0x8260f420
	ctx.lr = 0x82606BA0;
	sub_8260F420(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-11544(r30)
	REX_STORE_U32(ctx.r30.u32 + -11544, ctx.r31.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-14716(r9)
	REX_STORE_U32(ctx.r9.u32 + -14716, ctx.r31.u32);
	// lwsync 
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r11,r11,-15088
	ctx.r11.s64 = ctx.r11.s64 + -15088;
loc_82606BC4:
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
	// bne 0x82606bc4
	if (!ctx.cr0.eq) goto loc_82606BC4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82608aa8
	ctx.lr = 0x82606BE8;
	sub_82608AA8(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
loc_82606BEC:
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,-11572(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -11572);
	// bl 0x8263b630
	ctx.lr = 0x82606BF8;
	sub_8263B630(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82606bec
	if (!ctx.cr0.eq) goto loc_82606BEC;
	// lwz r3,-11572(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -11572);
	// bl 0x8263a978
	ctx.lr = 0x82606C08;
	sub_8263A978(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stw r31,-11572(r30)
	REX_STORE_U32(ctx.r30.u32 + -11572, ctx.r31.u32);
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-11568(r9)
	REX_STORE_U32(ctx.r9.u32 + -11568, ctx.r31.u32);
	// lwz r3,-11580(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -11580);
	// bl 0x8263a978
	ctx.lr = 0x82606C28;
	sub_8263A978(ctx, base);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-11580(r28)
	REX_STORE_U32(ctx.r28.u32 + -11580, ctx.r31.u32);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// mr r28,r31
	ctx.r28.u64 = ctx.r31.u64;
	// lwz r11,-15436(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -15436);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82606c6c
	if (ctx.cr6.eq) goto loc_82606C6C;
	// mr r27,r31
	ctx.r27.u64 = ctx.r31.u64;
loc_82606C4C:
	// lwz r11,-15464(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15464);
	// lwzx r3,r27,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// bl 0x825f9cf8
	ctx.lr = 0x82606C58;
	sub_825F9CF8(ctx, base);
	// lwz r11,-15436(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -15436);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82606c4c
	if (ctx.cr6.lt) goto loc_82606C4C;
loc_82606C6C:
	// lwz r3,-15464(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -15464);
	// bl 0x8260f420
	ctx.lr = 0x82606C74;
	sub_8260F420(ctx, base);
	// stw r31,-15464(r30)
	REX_STORE_U32(ctx.r30.u32 + -15464, ctx.r31.u32);
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// lwz r3,-15452(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -15452);
	// bl 0x8260b8a0
	ctx.lr = 0x82606C88;
	sub_8260B8A0(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// stw r31,-15452(r28)
	REX_STORE_U32(ctx.r28.u32 + -15452, ctx.r31.u32);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// stw r31,-15436(r29)
	REX_STORE_U32(ctx.r29.u32 + -15436, ctx.r31.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-15432(r8)
	REX_STORE_U32(ctx.r8.u32 + -15432, ctx.r31.u32);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stw r31,-15444(r7)
	REX_STORE_U32(ctx.r7.u32 + -15444, ctx.r31.u32);
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// stw r31,-15460(r6)
	REX_STORE_U32(ctx.r6.u32 + -15460, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r31,-15428(r8)
	REX_STORE_U32(ctx.r8.u32 + -15428, ctx.r31.u32);
	// stw r31,-15440(r7)
	REX_STORE_U32(ctx.r7.u32 + -15440, ctx.r31.u32);
	// bl 0x825f99d0
	ctx.lr = 0x82606CC8;
	sub_825F99D0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r28,r11,-14780
	ctx.r28.s64 = ctx.r11.s64 + -14780;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x82606CD8;
	sub_825F8ED0(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// lwz r11,-14784(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -14784);
	// lwz r3,-14796(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -14796);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// beq cr6,0x82606d24
	if (ctx.cr6.eq) goto loc_82606D24;
loc_82606CF8:
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82606d10
	if (ctx.cr6.eq) goto loc_82606D10;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82610080
	ctx.lr = 0x82606D0C;
	sub_82610080(ctx, base);
	// lwz r11,-14784(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -14784);
loc_82606D10:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r27,r27,48
	ctx.r27.s64 = ctx.r27.s64 + 48;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82606cf8
	if (ctx.cr6.lt) goto loc_82606CF8;
	// lwz r3,-14796(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -14796);
loc_82606D24:
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r6,r8,-14776
	ctx.r6.s64 = ctx.r8.s64 + -14776;
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// addi r5,r7,-14792
	ctx.r5.s64 = ctx.r7.s64 + -14792;
	// stw r6,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r6.u32);
	// stw r6,-14776(r8)
	REX_STORE_U32(ctx.r8.u32 + -14776, ctx.r6.u32);
	// addi r8,r4,-14768
	ctx.r8.s64 = ctx.r4.s64 + -14768;
	// stw r5,-14792(r7)
	REX_STORE_U32(ctx.r7.u32 + -14792, ctx.r5.u32);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// stw r5,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r5.u32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r8,-14768(r4)
	REX_STORE_U32(ctx.r4.u32 + -14768, ctx.r8.u32);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// stw r8,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r8.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// bl 0x8260f420
	ctx.lr = 0x82606D70;
	sub_8260F420(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-14796(r29)
	REX_STORE_U32(ctx.r29.u32 + -14796, ctx.r31.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-14784(r30)
	REX_STORE_U32(ctx.r30.u32 + -14784, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r31,-14800(r8)
	REX_STORE_U32(ctx.r8.u32 + -14800, ctx.r31.u32);
	// lwsync 
loc_82606D90:
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
	// stwcx. r31,0,r28
	ea = ctx.r28.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r31.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82606d90
	if (!ctx.cr0.eq) goto loc_82606D90;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r28,r11,-15024
	ctx.r28.s64 = ctx.r11.s64 + -15024;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x82606DB8;
	sub_825F8ED0(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// lwz r11,-15008(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15008);
	// lwz r3,-15036(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -15036);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// beq cr6,0x82606e04
	if (ctx.cr6.eq) goto loc_82606E04;
loc_82606DD8:
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82606df0
	if (ctx.cr6.eq) goto loc_82606DF0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8260ad60
	ctx.lr = 0x82606DEC;
	sub_8260AD60(ctx, base);
	// lwz r11,-15008(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15008);
loc_82606DF0:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r27,r27,284
	ctx.r27.s64 = ctx.r27.s64 + 284;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82606dd8
	if (ctx.cr6.lt) goto loc_82606DD8;
	// lwz r3,-15036(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -15036);
loc_82606E04:
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r6,r8,-15044
	ctx.r6.s64 = ctx.r8.s64 + -15044;
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// addi r5,r7,-15032
	ctx.r5.s64 = ctx.r7.s64 + -15032;
	// stw r6,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r6.u32);
	// stw r6,-15044(r8)
	REX_STORE_U32(ctx.r8.u32 + -15044, ctx.r6.u32);
	// addi r8,r4,-15016
	ctx.r8.s64 = ctx.r4.s64 + -15016;
	// stw r5,-15032(r7)
	REX_STORE_U32(ctx.r7.u32 + -15032, ctx.r5.u32);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// stw r5,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r5.u32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r8,-15016(r4)
	REX_STORE_U32(ctx.r4.u32 + -15016, ctx.r8.u32);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// stw r8,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r8.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// bl 0x8260f420
	ctx.lr = 0x82606E50;
	sub_8260F420(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-15036(r29)
	REX_STORE_U32(ctx.r29.u32 + -15036, ctx.r31.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-15008(r30)
	REX_STORE_U32(ctx.r30.u32 + -15008, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r31,-15020(r8)
	REX_STORE_U32(ctx.r8.u32 + -15020, ctx.r31.u32);
	// lwsync 
loc_82606E70:
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
	// stwcx. r31,0,r28
	ea = ctx.r28.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r31.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82606e70
	if (!ctx.cr0.eq) goto loc_82606E70;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r28,r11,-14744
	ctx.r28.s64 = ctx.r11.s64 + -14744;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x82606E98;
	sub_825F8ED0(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// lwz r11,-14732(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -14732);
	// lwz r3,-14728(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -14728);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// beq cr6,0x82606ee4
	if (ctx.cr6.eq) goto loc_82606EE4;
loc_82606EB8:
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82606ed0
	if (ctx.cr6.eq) goto loc_82606ED0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82614518
	ctx.lr = 0x82606ECC;
	sub_82614518(ctx, base);
	// lwz r11,-14732(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -14732);
loc_82606ED0:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r27,r27,72
	ctx.r27.s64 = ctx.r27.s64 + 72;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82606eb8
	if (ctx.cr6.lt) goto loc_82606EB8;
	// lwz r3,-14728(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -14728);
loc_82606EE4:
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r6,r8,-14740
	ctx.r6.s64 = ctx.r8.s64 + -14740;
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// addi r5,r7,-14756
	ctx.r5.s64 = ctx.r7.s64 + -14756;
	// stw r6,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r6.u32);
	// stw r6,-14740(r8)
	REX_STORE_U32(ctx.r8.u32 + -14740, ctx.r6.u32);
	// addi r8,r4,-14724
	ctx.r8.s64 = ctx.r4.s64 + -14724;
	// stw r5,-14756(r7)
	REX_STORE_U32(ctx.r7.u32 + -14756, ctx.r5.u32);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// stw r5,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r5.u32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r8,-14724(r4)
	REX_STORE_U32(ctx.r4.u32 + -14724, ctx.r8.u32);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// stw r8,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r8.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// bl 0x8260f420
	ctx.lr = 0x82606F30;
	sub_8260F420(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-14728(r29)
	REX_STORE_U32(ctx.r29.u32 + -14728, ctx.r31.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-14732(r30)
	REX_STORE_U32(ctx.r30.u32 + -14732, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r31,-14748(r8)
	REX_STORE_U32(ctx.r8.u32 + -14748, ctx.r31.u32);
	// lwsync 
loc_82606F50:
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
	// stwcx. r31,0,r28
	ea = ctx.r28.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r31.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82606f50
	if (!ctx.cr0.eq) goto loc_82606F50;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r28,r11,-15072
	ctx.r28.s64 = ctx.r11.s64 + -15072;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x82606F78;
	sub_825F8ED0(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// lwz r11,-15068(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15068);
	// lwz r3,-15076(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -15076);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// beq cr6,0x82606fc4
	if (ctx.cr6.eq) goto loc_82606FC4;
loc_82606F98:
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82606fb0
	if (ctx.cr6.eq) goto loc_82606FB0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8260a610
	ctx.lr = 0x82606FAC;
	sub_8260A610(ctx, base);
	// lwz r11,-15068(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15068);
loc_82606FB0:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r27,r27,72
	ctx.r27.s64 = ctx.r27.s64 + 72;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82606f98
	if (ctx.cr6.lt) goto loc_82606F98;
	// lwz r3,-15076(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -15076);
loc_82606FC4:
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r6,r8,-15056
	ctx.r6.s64 = ctx.r8.s64 + -15056;
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// addi r5,r7,-15064
	ctx.r5.s64 = ctx.r7.s64 + -15064;
	// stw r6,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r6.u32);
	// stw r6,-15056(r8)
	REX_STORE_U32(ctx.r8.u32 + -15056, ctx.r6.u32);
	// addi r8,r4,-15084
	ctx.r8.s64 = ctx.r4.s64 + -15084;
	// stw r5,-15064(r7)
	REX_STORE_U32(ctx.r7.u32 + -15064, ctx.r5.u32);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// stw r5,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r5.u32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r8,-15084(r4)
	REX_STORE_U32(ctx.r4.u32 + -15084, ctx.r8.u32);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// stw r8,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r8.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// bl 0x8260f420
	ctx.lr = 0x82607010;
	sub_8260F420(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-15076(r29)
	REX_STORE_U32(ctx.r29.u32 + -15076, ctx.r31.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-15068(r30)
	REX_STORE_U32(ctx.r30.u32 + -15068, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r31,-15048(r8)
	REX_STORE_U32(ctx.r8.u32 + -15048, ctx.r31.u32);
	// lwsync 
loc_82607030:
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
	// stwcx. r31,0,r28
	ea = ctx.r28.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r31.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82607030
	if (!ctx.cr0.eq) goto loc_82607030;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r28,r11,-14980
	ctx.r28.s64 = ctx.r11.s64 + -14980;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x82607058;
	sub_825F8ED0(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// lwz r11,-14976(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -14976);
	// lwz r3,-14968(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -14968);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// beq cr6,0x826070a4
	if (ctx.cr6.eq) goto loc_826070A4;
loc_82607078:
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82607090
	if (ctx.cr6.eq) goto loc_82607090;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8260b390
	ctx.lr = 0x8260708C;
	sub_8260B390(ctx, base);
	// lwz r11,-14976(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -14976);
loc_82607090:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r27,r27,84
	ctx.r27.s64 = ctx.r27.s64 + 84;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82607078
	if (ctx.cr6.lt) goto loc_82607078;
	// lwz r3,-14968(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -14968);
loc_826070A4:
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r6,r8,-15004
	ctx.r6.s64 = ctx.r8.s64 + -15004;
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// addi r5,r7,-14996
	ctx.r5.s64 = ctx.r7.s64 + -14996;
	// stw r6,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r6.u32);
	// stw r6,-15004(r8)
	REX_STORE_U32(ctx.r8.u32 + -15004, ctx.r6.u32);
	// addi r8,r4,-14988
	ctx.r8.s64 = ctx.r4.s64 + -14988;
	// stw r5,-14996(r7)
	REX_STORE_U32(ctx.r7.u32 + -14996, ctx.r5.u32);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// stw r5,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r5.u32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r8,-14988(r4)
	REX_STORE_U32(ctx.r4.u32 + -14988, ctx.r8.u32);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// stw r8,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r8.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// bl 0x8260f420
	ctx.lr = 0x826070F0;
	sub_8260F420(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-14968(r29)
	REX_STORE_U32(ctx.r29.u32 + -14968, ctx.r31.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-14976(r30)
	REX_STORE_U32(ctx.r30.u32 + -14976, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r31,-14972(r8)
	REX_STORE_U32(ctx.r8.u32 + -14972, ctx.r31.u32);
	// lwsync 
loc_82607110:
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
	// stwcx. r31,0,r28
	ea = ctx.r28.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r31.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82607110
	if (!ctx.cr0.eq) goto loc_82607110;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r28,r11,-15400
	ctx.r28.s64 = ctx.r11.s64 + -15400;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x82607138;
	sub_825F8ED0(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// lwz r11,-15416(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15416);
	// lwz r3,-15412(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -15412);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// beq cr6,0x82607184
	if (ctx.cr6.eq) goto loc_82607184;
loc_82607158:
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82607170
	if (ctx.cr6.eq) goto loc_82607170;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x825fe298
	ctx.lr = 0x8260716C;
	sub_825FE298(ctx, base);
	// lwz r11,-15416(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15416);
loc_82607170:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r27,r27,32
	ctx.r27.s64 = ctx.r27.s64 + 32;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82607158
	if (ctx.cr6.lt) goto loc_82607158;
	// lwz r3,-15412(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -15412);
loc_82607184:
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r6,r8,-15392
	ctx.r6.s64 = ctx.r8.s64 + -15392;
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// addi r5,r7,-15384
	ctx.r5.s64 = ctx.r7.s64 + -15384;
	// stw r6,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r6.u32);
	// stw r6,-15392(r8)
	REX_STORE_U32(ctx.r8.u32 + -15392, ctx.r6.u32);
	// addi r8,r4,-15408
	ctx.r8.s64 = ctx.r4.s64 + -15408;
	// stw r5,-15384(r7)
	REX_STORE_U32(ctx.r7.u32 + -15384, ctx.r5.u32);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// stw r5,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r5.u32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r8,-15408(r4)
	REX_STORE_U32(ctx.r4.u32 + -15408, ctx.r8.u32);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// stw r8,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r8.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// bl 0x8260f420
	ctx.lr = 0x826071D0;
	sub_8260F420(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-15412(r29)
	REX_STORE_U32(ctx.r29.u32 + -15412, ctx.r31.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-15416(r30)
	REX_STORE_U32(ctx.r30.u32 + -15416, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r31,-15396(r8)
	REX_STORE_U32(ctx.r8.u32 + -15396, ctx.r31.u32);
	// lwsync 
loc_826071F0:
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
	// stwcx. r31,0,r28
	ea = ctx.r28.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r31.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x826071f0
	if (!ctx.cr0.eq) goto loc_826071F0;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r28,r11,-14904
	ctx.r28.s64 = ctx.r11.s64 + -14904;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x82607218;
	sub_825F8ED0(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// lwz r11,-14900(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -14900);
	// lwz r3,-14884(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -14884);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// beq cr6,0x82607264
	if (ctx.cr6.eq) goto loc_82607264;
loc_82607238:
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82607250
	if (ctx.cr6.eq) goto loc_82607250;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8260f850
	ctx.lr = 0x8260724C;
	sub_8260F850(ctx, base);
	// lwz r11,-14900(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -14900);
loc_82607250:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r27,r27,64
	ctx.r27.s64 = ctx.r27.s64 + 64;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82607238
	if (ctx.cr6.lt) goto loc_82607238;
	// lwz r3,-14884(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -14884);
loc_82607264:
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r6,r8,-14896
	ctx.r6.s64 = ctx.r8.s64 + -14896;
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// addi r5,r7,-14912
	ctx.r5.s64 = ctx.r7.s64 + -14912;
	// stw r6,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r6.u32);
	// stw r6,-14896(r8)
	REX_STORE_U32(ctx.r8.u32 + -14896, ctx.r6.u32);
	// addi r8,r4,-14920
	ctx.r8.s64 = ctx.r4.s64 + -14920;
	// stw r5,-14912(r7)
	REX_STORE_U32(ctx.r7.u32 + -14912, ctx.r5.u32);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// stw r5,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r5.u32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r8,-14920(r4)
	REX_STORE_U32(ctx.r4.u32 + -14920, ctx.r8.u32);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// stw r8,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r8.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// bl 0x8260f420
	ctx.lr = 0x826072B0;
	sub_8260F420(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-14884(r29)
	REX_STORE_U32(ctx.r29.u32 + -14884, ctx.r31.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-14900(r30)
	REX_STORE_U32(ctx.r30.u32 + -14900, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r31,-14888(r8)
	REX_STORE_U32(ctx.r8.u32 + -14888, ctx.r31.u32);
	// lwsync 
loc_826072D0:
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
	// stwcx. r31,0,r28
	ea = ctx.r28.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r31.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x826072d0
	if (!ctx.cr0.eq) goto loc_826072D0;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r30,r11,-14928
	ctx.r30.s64 = ctx.r11.s64 + -14928;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x826072F8;
	sub_825F8ED0(ctx, base);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// lwz r3,-14932(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -14932);
	// bl 0x8260f420
	ctx.lr = 0x82607304;
	sub_8260F420(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-14932(r29)
	REX_STORE_U32(ctx.r29.u32 + -14932, ctx.r31.u32);
	// lwsync 
loc_82607310:
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
	// stwcx. r31,0,r30
	ea = ctx.r30.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r31.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82607310
	if (!ctx.cr0.eq) goto loc_82607310;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r11,-11620(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -11620);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82607384
	if (ctx.cr6.eq) goto loc_82607384;
	// bl 0x826065b8
	ctx.lr = 0x8260733C;
	sub_826065B8(ctx, base);
	// lwz r3,-11620(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -11620);
	// bl 0x82620e20
	ctx.lr = 0x82607344;
	sub_82620E20(ctx, base);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-11620(r30)
	REX_STORE_U32(ctx.r30.u32 + -11620, ctx.r31.u32);
	// lwz r3,-11612(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -11612);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82607368
	if (ctx.cr6.eq) goto loc_82607368;
	// bl 0x8263a978
	ctx.lr = 0x82607360;
	sub_8263A978(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-11612(r29)
	REX_STORE_U32(ctx.r29.u32 + -11612, ctx.r31.u32);
loc_82607368:
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r3,-11616(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -11616);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82607384
	if (ctx.cr6.eq) goto loc_82607384;
	// bl 0x8263a978
	ctx.lr = 0x8260737C;
	sub_8263A978(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-11616(r30)
	REX_STORE_U32(ctx.r30.u32 + -11616, ctx.r31.u32);
loc_82607384:
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-14944(r8)
	REX_STORE_U32(ctx.r8.u32 + -14944, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r31,-14940(r7)
	REX_STORE_U32(ctx.r7.u32 + -14940, ctx.r31.u32);
	// stw r31,-14952(r6)
	REX_STORE_U32(ctx.r6.u32 + -14952, ctx.r31.u32);
	// stw r31,-14956(r5)
	REX_STORE_U32(ctx.r5.u32 + -14956, ctx.r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82644B20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82644B28;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82644B48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x82644b68
	if (ctx.cr0.lt) goto loc_82644B68;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82644B68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82644B68:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82646890) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
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
	ctx.lr = 0x826468C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
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
	ctx.lr = 0x826468F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

DEFINE_REX_FUNC(sub_82649878) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82649880;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,284(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 284);
	// bl 0x82645950
	ctx.lr = 0x826498A8;
	sub_82645950(ctx, base);
	// lwz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// add r10,r3,r29
	ctx.r10.u64 = ctx.r3.u64 + ctx.r29.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x826498c8
	if (!ctx.cr6.gt) goto loc_826498C8;
	// subf r30,r29,r11
	ctx.r30.u64 = ctx.r11.u64 - ctx.r29.u64;
	// subf r28,r30,r3
	ctx.r28.u64 = ctx.r3.u64 - ctx.r30.u64;
loc_826498C8:
	// lwz r9,64(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// mullw r10,r9,r29
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r29.s32);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r9,r9,r30
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r30.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x8263a4c0
	ctx.lr = 0x826498EC;
	sub_8263A4C0(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82649918
	if (ctx.cr6.eq) goto loc_82649918;
	// lwz r9,64(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mullw r11,r9,r30
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r30.s32);
	// lwz r3,292(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r9,r9,r28
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r28.s32);
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x8263a4c0
	ctx.lr = 0x82649918;
	sub_8263A4C0(ctx, base);
loc_82649918:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264D0C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8264D0D0;
	__savegprlr_23(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// addi r30,r3,28
	ctx.r30.s64 = ctx.r3.s64 + 28;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264D10C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// addi r5,r29,4
	ctx.r5.s64 = ctx.r29.s64 + 4;
	// bne cr6,0x8264d11c
	if (!ctx.cr6.eq) goto loc_8264D11C;
	// li r5,0
	ctx.r5.s64 = 0;
loc_8264D11C:
	// lwz r4,68(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// stw r23,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r23.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r30,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stw r4,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x8265faf0
	ctx.lr = 0x8264D15C;
	sub_8265FAF0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8264d170
	if (ctx.cr0.lt) goto loc_8264D170;
	// lwz r11,292(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// lwz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8264D170:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264D184;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82652748) {
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
	// addi r11,r11,8244
	ctx.r11.s64 = ctx.r11.s64 + 8244;
	// addi r10,r10,8224
	ctx.r10.s64 = ctx.r10.s64 + 8224;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// bl 0x82652688
	ctx.lr = 0x82652778;
	sub_82652688(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82662240
	ctx.lr = 0x82652780;
	sub_82662240(ctx, base);
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

DEFINE_REX_FUNC(sub_826541D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// b 0x8265420c
	goto loc_8265420C;
loc_826541E4:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826541fc
	if (ctx.cr6.eq) goto loc_826541FC;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82654200
	goto loc_82654200;
loc_826541FC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82654200:
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x82654218
	if (ctx.cr6.eq) goto loc_82654218;
loc_8265420C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826541e4
	if (!ctx.cr6.eq) goto loc_826541E4;
	// blr 
	return;
loc_82654218:
	// lwz r3,8(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f0,72(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stfs f0,16(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x82646748
	sub_82646748(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265BBE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8265BBF0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,500(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 500);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// bne cr6,0x8265bc20
	if (!ctx.cr6.eq) goto loc_8265BC20;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_8265BC20:
	// lwz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lhz r29,0(r27)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r27.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265bc48
	if (ctx.cr6.eq) goto loc_8265BC48;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8265b450
	ctx.lr = 0x8265BC40;
	sub_8265B450(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8265bca4
	if (ctx.cr6.lt) goto loc_8265BCA4;
loc_8265BC48:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8265b7d0
	ctx.lr = 0x8265BC54;
	sub_8265B7D0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8265bca4
	if (ctx.cr6.lt) goto loc_8265BCA4;
	// lwz r11,472(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 472);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8265bca4
	if (!ctx.cr6.eq) goto loc_8265BCA4;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x8265bca4
	if (ctx.cr6.eq) goto loc_8265BCA4;
	// lwz r11,176(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 176);
	// clrlwi r7,r29,16
	ctx.r7.u64 = ctx.r29.u32 & 0xFFFF;
	// lbz r5,201(r30)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r30.u32 + 201);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwz r3,568(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 568);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bne cr6,0x8265bca0
	if (!ctx.cr6.eq) goto loc_8265BCA0;
	// bl 0x8267f750
	ctx.lr = 0x8265BC94;
	sub_8267F750(ctx, base);
	// sth r29,0(r27)
	REX_STORE_U16(ctx.r27.u32 + 0, ctx.r29.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_8265BCA0:
	// bl 0x8267f1f0
	ctx.lr = 0x8265BCA4;
	sub_8267F1F0(ctx, base);
loc_8265BCA4:
	// sth r29,0(r27)
	REX_STORE_U16(ctx.r27.u32 + 0, ctx.r29.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265FE48) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8265fbf0
	sub_8265FBF0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826603E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x826603F0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8266040C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82660428
	if (!ctx.cr6.eq) goto loc_82660428;
	// lwz r3,148(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 148);
	// bl 0x82684800
	ctx.lr = 0x82660424;
	sub_82684800(ctx, base);
	// b 0x8266048c
	goto loc_8266048C;
loc_82660428:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,13120
	ctx.r3.s64 = ctx.r11.s64 + 13120;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82641ff8
	ctx.lr = 0x82660444;
	sub_82641FF8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82660458
	if (!ctx.cr0.eq) goto loc_82660458;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x8266048c
	goto loc_8266048C;
loc_82660458:
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// addi r10,r30,4
	ctx.r10.s64 = ctx.r30.s64 + 4;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x82660ed0
	ctx.lr = 0x8266047C;
	sub_82660ED0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge 0x8266048c
	if (!ctx.cr0.lt) goto loc_8266048C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264cf40
	ctx.lr = 0x8266048C;
	sub_8264CF40(ctx, base);
loc_8266048C:
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826604A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82667070) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,24812(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24812);
	ctx.f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,24808(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24808);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fmuls f1,f11,f13
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8266B550) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r9,32(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r7,8(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r6,12(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r11.u32);
	// lfs f11,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f11.f64 = double(temp.f32);
	// stw r9,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r9.u32);
	// lfs f10,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r8,24(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8266b5f0
	if (ctx.cr6.eq) goto loc_8266B5F0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// subf r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
loc_8266B59C:
	// lfsx f12,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f9,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fnmsubs f12,f10,f0,f9
	ctx.f12.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f0.f64, -ctx.f9.f64)));
	// fmadds f0,f12,f11,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f11.f64, ctx.f0.f64)));
	// fmadds f13,f0,f11,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f11.f64, ctx.f13.f64)));
	// dcbt r0,r10
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8266b5c4
	if (!ctx.cr6.eq) goto loc_8266B5C4;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x8266b5e4
	goto loc_8266B5E4;
loc_8266B5C4:
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// beq cr6,0x8266b5e0
	if (ctx.cr6.eq) goto loc_8266B5E0;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x8266b5dc
	if (!ctx.cr6.eq) goto loc_8266B5DC;
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x8266b5e4
	goto loc_8266B5E4;
loc_8266B5DC:
	// fadds f12,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
loc_8266B5E0:
	// stfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_8266B5E4:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// bdnz 0x8266b59c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8266B59C;
loc_8266B5F0:
	// stfs f13,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,0(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82674EB8) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,3
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 3, ctx.xer);
	// stw r11,48(r5)
	REX_STORE_U32(ctx.r5.u32 + 48, ctx.r11.u32);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r9,40(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 40);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
loc_82674EE8:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82674f08
	if (!ctx.cr6.eq) goto loc_82674F08;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x82674ee8
	if (ctx.cr6.lt) goto loc_82674EE8;
	// blr 
	return;
loc_82674F08:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,48(r5)
	REX_STORE_U32(ctx.r5.u32 + 48, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82675CA0) {
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
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// bl 0x82675c00
	ctx.lr = 0x82675CB4;
	sub_82675C00(ctx, base);
	// lis r11,-32151
	ctx.r11.s64 = -2107047936;
	// lhz r7,110(r6)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r6.u32 + 110);
	// lis r10,-32151
	ctx.r10.s64 = -2107047936;
	// addi r9,r11,-18200
	ctx.r9.s64 = ctx.r11.s64 + -18200;
	// addi r8,r10,-19400
	ctx.r8.s64 = ctx.r10.s64 + -19400;
	// stw r9,496(r6)
	REX_STORE_U32(ctx.r6.u32 + 496, ctx.r9.u32);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// stw r8,516(r6)
	REX_STORE_U32(ctx.r6.u32 + 516, ctx.r8.u32);
	// bgt cr6,0x82675cfc
	if (ctx.cr6.gt) goto loc_82675CFC;
	// lis r11,-32167
	ctx.r11.s64 = -2108096512;
	// lis r10,-32167
	ctx.r10.s64 = -2108096512;
	// lis r9,-32158
	ctx.r9.s64 = -2107506688;
	// lis r8,-32167
	ctx.r8.s64 = -2108096512;
	// addi r7,r11,31936
	ctx.r7.s64 = ctx.r11.s64 + 31936;
	// addi r5,r10,31936
	ctx.r5.s64 = ctx.r10.s64 + 31936;
	// addi r4,r9,-16512
	ctx.r4.s64 = ctx.r9.s64 + -16512;
	// addi r3,r8,31936
	ctx.r3.s64 = ctx.r8.s64 + 31936;
	// b 0x82675d1c
	goto loc_82675D1C;
loc_82675CFC:
	// lis r11,-32167
	ctx.r11.s64 = -2108096512;
	// lis r10,-32167
	ctx.r10.s64 = -2108096512;
	// lis r9,-32158
	ctx.r9.s64 = -2107506688;
	// lis r8,-32167
	ctx.r8.s64 = -2108096512;
	// addi r7,r11,31936
	ctx.r7.s64 = ctx.r11.s64 + 31936;
	// addi r5,r10,31936
	ctx.r5.s64 = ctx.r10.s64 + 31936;
	// addi r4,r9,-16512
	ctx.r4.s64 = ctx.r9.s64 + -16512;
	// addi r3,r8,31936
	ctx.r3.s64 = ctx.r8.s64 + 31936;
loc_82675D1C:
	// lwz r11,280(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 280);
	// stw r3,512(r6)
	REX_STORE_U32(ctx.r6.u32 + 512, ctx.r3.u32);
	// stw r4,508(r6)
	REX_STORE_U32(ctx.r6.u32 + 508, ctx.r4.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// stw r5,504(r6)
	REX_STORE_U32(ctx.r6.u32 + 504, ctx.r5.u32);
	// stw r7,500(r6)
	REX_STORE_U32(ctx.r6.u32 + 500, ctx.r7.u32);
	// bne cr6,0x82675d58
	if (!ctx.cr6.eq) goto loc_82675D58;
	// lwz r11,40(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82675d4c
	if (!ctx.cr6.eq) goto loc_82675D4C;
	// stw r11,476(r6)
	REX_STORE_U32(ctx.r6.u32 + 476, ctx.r11.u32);
	// b 0x82675d64
	goto loc_82675D64;
loc_82675D4C:
	// lis r11,-32151
	ctx.r11.s64 = -2107047936;
	// addi r10,r11,-23328
	ctx.r10.s64 = ctx.r11.s64 + -23328;
	// b 0x82675d60
	goto loc_82675D60;
loc_82675D58:
	// lis r11,-32151
	ctx.r11.s64 = -2107047936;
	// addi r10,r11,-10328
	ctx.r10.s64 = ctx.r11.s64 + -10328;
loc_82675D60:
	// stw r10,476(r6)
	REX_STORE_U32(ctx.r6.u32 + 476, ctx.r10.u32);
loc_82675D64:
	// lis r11,-32151
	ctx.r11.s64 = -2107047936;
	// lis r10,-32151
	ctx.r10.s64 = -2107047936;
	// addi r9,r11,-12936
	ctx.r9.s64 = ctx.r11.s64 + -12936;
	// addi r8,r10,-11408
	ctx.r8.s64 = ctx.r10.s64 + -11408;
	// stw r9,516(r6)
	REX_STORE_U32(ctx.r6.u32 + 516, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r8,496(r6)
	REX_STORE_U32(ctx.r6.u32 + 496, ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8267B718) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x8267B720;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r24,0
	ctx.r24.s64 = 0;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r22,r24
	ctx.r22.u64 = ctx.r24.u64;
	// mr r25,r24
	ctx.r25.u64 = ctx.r24.u64;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// lwz r18,256(r31)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// beq cr6,0x8267caa8
	if (ctx.cr6.eq) goto loc_8267CAA8;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// li r23,1
	ctx.r23.s64 = 1;
	// li r27,14
	ctx.r27.s64 = 14;
	// li r14,12
	ctx.r14.s64 = 12;
	// addi r20,r11,856
	ctx.r20.s64 = ctx.r11.s64 + 856;
	// li r15,8
	ctx.r15.s64 = 8;
	// addi r19,r10,-28360
	ctx.r19.s64 = ctx.r10.s64 + -28360;
	// ori r16,r9,65535
	ctx.r16.u64 = ctx.r9.u64 | 65535;
	// li r17,36
	ctx.r17.s64 = 36;
	// li r21,45
	ctx.r21.s64 = 45;
loc_8267B778:
	// lwz r11,40(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 40);
	// cmplwi cr6,r11,52
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 52, ctx.xer);
	// bgt cr6,0x8267ca64
	if (ctx.cr6.gt) goto loc_8267CA64;
	// lis r12,-32152
	ctx.r12.s64 = -2107113472;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-18532
	ctx.r12.s64 = ctx.r12.s64 + -18532;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8267B870;
	case 1:
		goto loc_8267CA64;
	case 2:
		goto loc_8267CA64;
	case 3:
		goto loc_8267C220;
	case 4:
		goto loc_8267C4A4;
	case 5:
		goto loc_8267C54C;
	case 6:
		goto loc_8267C574;
	case 7:
		goto loc_8267C574;
	case 8:
		goto loc_8267C598;
	case 9:
		goto loc_8267C764;
	case 10:
		goto loc_8267CA64;
	case 11:
		goto loc_8267BBE8;
	case 12:
		goto loc_8267BD30;
	case 13:
		goto loc_8267BCB8;
	case 14:
		goto loc_8267BD8C;
	case 15:
		goto loc_8267BE0C;
	case 16:
		goto loc_8267CA64;
	case 17:
		goto loc_8267CA64;
	case 18:
		goto loc_8267C030;
	case 19:
		goto loc_8267C228;
	case 20:
		goto loc_8267CA64;
	case 21:
		goto loc_8267CA64;
	case 22:
		goto loc_8267CA64;
	case 23:
		goto loc_8267CA64;
	case 24:
		goto loc_8267CA64;
	case 25:
		goto loc_8267CA64;
	case 26:
		goto loc_8267CA64;
	case 27:
		goto loc_8267CA64;
	case 28:
		goto loc_8267CA64;
	case 29:
		goto loc_8267C230;
	case 30:
		goto loc_8267C38C;
	case 31:
		goto loc_8267C3D4;
	case 32:
		goto loc_8267BE28;
	case 33:
		goto loc_8267C240;
	case 34:
		goto loc_8267CA64;
	case 35:
		goto loc_8267CA64;
	case 36:
		goto loc_8267BF54;
	case 37:
		goto loc_8267C070;
	case 38:
		goto loc_8267C038;
	case 39:
		goto loc_8267BF54;
	case 40:
		goto loc_8267BF0C;
	case 41:
		goto loc_8267BF44;
	case 42:
		goto loc_8267BF4C;
	case 43:
		goto loc_8267CA64;
	case 44:
		goto loc_8267C10C;
	case 45:
		goto loc_8267C1C4;
	case 46:
		goto loc_8267C168;
	case 47:
		goto loc_8267CA64;
	case 48:
		goto loc_8267BF80;
	case 49:
		goto loc_8267CA64;
	case 50:
		goto loc_8267CA64;
	case 51:
		goto loc_8267CA64;
	case 52:
		goto loc_8267C248;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8267B870:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bgt cr6,0x8267b964
	if (ctx.cr6.gt) goto loc_8267B964;
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8267b908
	if (ctx.cr6.eq) goto loc_8267B908;
	// lwz r10,228(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// ble cr6,0x8267b8ac
	if (!ctx.cr6.gt) goto loc_8267B8AC;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
loc_8267B89C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r9,r10,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r11.u8 & 0x3F));
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bgt cr6,0x8267b89c
	if (ctx.cr6.gt) goto loc_8267B89C;
loc_8267B8AC:
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8267b8c8
	if (!ctx.cr6.gt) goto loc_8267B8C8;
loc_8267B8B8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// srw r9,r11,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bgt cr6,0x8267b8b8
	if (ctx.cr6.gt) goto loc_8267B8B8;
loc_8267B8C8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267B8D8;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// slw r9,r23,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r23.u32 << (ctx.r10.u8 & 0x3F));
	// lwz r8,236(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// divw r18,r11,r9
	ctx.r18.u64 = uint32_t((ctx.r9.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r11.s32 / ctx.r9.s32 : 0);
	// cmpw cr6,r18,r8
	ctx.cr6.compare<int32_t>(ctx.r18.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x8267ca7c
	if (ctx.cr6.lt) goto loc_8267CA7C;
	// cmpw cr6,r18,r11
	ctx.cr6.compare<int32_t>(ctx.r18.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x8267ca7c
	if (ctx.cr6.gt) goto loc_8267CA7C;
loc_8267B908:
	// lhz r11,34(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r11,580(r31)
	REX_STORE_U16(ctx.r31.u32 + 580, ctx.r11.u16);
	// beq cr6,0x8267b948
	if (ctx.cr6.eq) goto loc_8267B948;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// rlwinm r9,r24,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
loc_8267B924:
	// lwz r8,584(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// sthx r10,r9,r8
	REX_STORE_U16(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u16);
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// lhz r6,34(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpw cr6,r10,r6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, ctx.xer);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// blt cr6,0x8267b924
	if (ctx.cr6.lt) goto loc_8267B924;
loc_8267B948:
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82658858
	ctx.lr = 0x8267B954;
	sub_82658858(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// b 0x8267bb10
	goto loc_8267BB10;
loc_8267B964:
	// lwz r10,256(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// lhz r5,34(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// lwz r3,320(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// mullw r7,r5,r10
	ctx.r7.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x8267b9dc
	if (!ctx.cr6.gt) goto loc_8267B9DC;
	// clrlwi r4,r5,16
	ctx.r4.u64 = ctx.r5.u32 & 0xFFFF;
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// addi r11,r3,424
	ctx.r11.s64 = ctx.r3.s64 + 424;
loc_8267B994:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// extsh r29,r6
	ctx.r29.s64 = ctx.r6.s16;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lhz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// extsh r28,r9
	ctx.r28.s64 = ctx.r9.s16;
	// cmpw cr6,r29,r28
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r28.s32, ctx.xer);
	// ble cr6,0x8267b9c8
	if (!ctx.cr6.gt) goto loc_8267B9C8;
	// lhz r30,-310(r11)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r11.u32 + -310);
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// extsh r9,r30
	ctx.r9.s64 = ctx.r30.s16;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r30,r9,r10
	ctx.r30.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
loc_8267B9C8:
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// addi r11,r11,1776
	ctx.r11.s64 = ctx.r11.s64 + 1776;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// cmpw cr6,r8,r4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x8267b994
	if (ctx.cr6.lt) goto loc_8267B994;
loc_8267B9DC:
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// sth r24,580(r31)
	REX_STORE_U16(ctx.r31.u32 + 580, ctx.r24.u16);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x8267bae0
	if (!ctx.cr6.gt) goto loc_8267BAE0;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// addi r11,r3,114
	ctx.r11.s64 = ctx.r3.s64 + 114;
loc_8267B9F8:
	// lwz r10,310(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 310);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lhz r4,0(r9)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// subf r7,r3,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r3.u64;
	// cmpw cr6,r5,r3
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r3.s32, ctx.xer);
	// bne cr6,0x8267bac4
	if (!ctx.cr6.eq) goto loc_8267BAC4;
	// lhz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r3,r30
	ctx.r3.s64 = ctx.r30.s16;
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r4,r4,r10
	ctx.r4.u64 = REX_LOAD_U16(ctx.r4.u32 + ctx.r10.u32);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// cmpw cr6,r3,r4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, ctx.xer);
	// bne cr6,0x8267bac4
	if (!ctx.cr6.eq) goto loc_8267BAC4;
	// lhz r4,580(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// lwz r3,584(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r8,r4,r3
	REX_STORE_U16(ctx.r4.u32 + ctx.r3.u32, ctx.r8.u16);
	// lhz r3,580(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// addi r8,r3,1
	ctx.r8.s64 = ctx.r3.s64 + 1;
	// sth r8,580(r31)
	REX_STORE_U16(ctx.r31.u32 + 580, ctx.r8.u16);
	// lhz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rlwinm r4,r8,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r3,r4,r10
	ctx.r3.u64 = REX_LOAD_U16(ctx.r4.u32 + ctx.r10.u32);
	// sth r3,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r3.u16);
	// lhz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r3,r10
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + ctx.r10.u32);
	// sth r8,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r8.u16);
	// lhz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// rlwinm r8,r3,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lhz r4,-2(r8)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r8.u32 + -2);
	// sth r4,8(r11)
	REX_STORE_U16(ctx.r11.u32 + 8, ctx.r4.u16);
	// lhz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// lhz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lhzx r3,r4,r10
	ctx.r3.u64 = REX_LOAD_U16(ctx.r4.u32 + ctx.r10.u32);
	// add r10,r3,r8
	ctx.r10.u64 = ctx.r3.u64 + ctx.r8.u64;
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// sth r10,0(r9)
	REX_STORE_U16(ctx.r9.u32 + 0, ctx.r10.u16);
	// subf r7,r8,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r8.u64;
loc_8267BAC4:
	// addi r10,r6,1
	ctx.r10.s64 = ctx.r6.s64 + 1;
	// lhz r9,34(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// addi r11,r11,1776
	ctx.r11.s64 = ctx.r11.s64 + 1776;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8267b9f8
	if (ctx.cr6.lt) goto loc_8267B9F8;
loc_8267BAE0:
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// lhz r10,34(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x8267caa0
	if (ctx.cr6.gt) goto loc_8267CAA0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8267caa0
	if (!ctx.cr6.gt) goto loc_8267CAA0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// blt cr6,0x8267caa0
	if (ctx.cr6.lt) goto loc_8267CAA0;
	// cntlzw r11,r7
	ctx.r11.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stw r10,216(r26)
	REX_STORE_U32(ctx.r26.u32 + 216, ctx.r10.u32);
loc_8267BB10:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82674b58
	ctx.lr = 0x8267BB18;
	sub_82674B58(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82659b70
	ctx.lr = 0x8267BB2C;
	sub_82659B70(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bgt cr6,0x8267bb4c
	if (ctx.cr6.gt) goto loc_8267BB4C;
	// li r11,52
	ctx.r11.s64 = 52;
	// b 0x8267ca60
	goto loc_8267CA60;
loc_8267BB4C:
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8267bbe0
	if (!ctx.cr6.gt) goto loc_8267BBE0;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
loc_8267BB64:
	// lwz r9,584(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lhzx r8,r11,r9
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r9.u32);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// mulli r11,r7,1776
	ctx.r11.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(1776));
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lhz r6,114(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 114);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8267bbb4
	if (!ctx.cr6.eq) goto loc_8267BBB4;
	// li r5,112
	ctx.r5.s64 = 112;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r24,444(r30)
	REX_STORE_U32(ctx.r30.u32 + 444, ctx.r24.u32);
	// stw r23,436(r30)
	REX_STORE_U32(ctx.r30.u32 + 436, ctx.r23.u32);
	// bl 0x8273a590
	ctx.lr = 0x8267BBA0;
	sub_8273A590(ctx, base);
	// li r5,112
	ctx.r5.s64 = 112;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x8273a590
	ctx.lr = 0x8267BBB0;
	sub_8273A590(ctx, base);
	// stw r24,64(r30)
	REX_STORE_U32(ctx.r30.u32 + 64, ctx.r24.u32);
loc_8267BBB4:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8267fe50
	ctx.lr = 0x8267BBC4;
	sub_8267FE50(ctx, base);
	// lhz r9,580(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// extsh r29,r11
	ctx.r29.s64 = ctx.r11.s16;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r29,r8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x8267bb64
	if (ctx.cr6.lt) goto loc_8267BB64;
loc_8267BBE0:
	// li r11,11
	ctx.r11.s64 = 11;
	// b 0x8267ca60
	goto loc_8267CA60;
loc_8267BBE8:
	// addi r30,r26,224
	ctx.r30.s64 = ctx.r26.s64 + 224;
	// li r4,22
	ctx.r4.s64 = 22;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826828e8
	ctx.lr = 0x8267BBF8;
	sub_826828E8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// stw r24,60(r26)
	REX_STORE_U32(ctx.r26.u32 + 60, ctx.r24.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82678ba0
	ctx.lr = 0x8267BC18;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8267bc38
	if (!ctx.cr6.eq) goto loc_8267BC38;
	// stw r27,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r27.u32);
	// b 0x8267ca64
	goto loc_8267CA64;
loc_8267BC38:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82678ba0
	ctx.lr = 0x8267BC48;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8267bc6c
	if (ctx.cr6.eq) goto loc_8267BC6C;
	// stw r11,60(r26)
	REX_STORE_U32(ctx.r26.u32 + 60, ctx.r11.u32);
	// stw r14,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r14.u32);
	// b 0x8267ca64
	goto loc_8267CA64;
loc_8267BC6C:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82678ba0
	ctx.lr = 0x8267BC7C;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,88(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82678ba0
	ctx.lr = 0x8267BC98;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r14,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r14.u32);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r10,60(r26)
	REX_STORE_U32(ctx.r26.u32 + 60, ctx.r10.u32);
	// b 0x8267ca64
	goto loc_8267CA64;
loc_8267BCB8:
	// lwz r11,60(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8267bd28
	if (!ctx.cr6.gt) goto loc_8267BD28;
	// addi r29,r26,224
	ctx.r29.s64 = ctx.r26.s64 + 224;
loc_8267BCC8:
	// lwz r30,60(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + 60);
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// ble cr6,0x8267bcd8
	if (!ctx.cr6.gt) goto loc_8267BCD8;
	// mr r30,r15
	ctx.r30.u64 = ctx.r15.u64;
loc_8267BCD8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82678ba0
	ctx.lr = 0x8267BCE8;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// bge cr6,0x8267bd10
	if (!ctx.cr6.lt) goto loc_8267BD10;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// subfic r10,r30,8
	ctx.xer.ca = ctx.r30.u32 <= 8;
	ctx.r10.u64 = static_cast<uint64_t>(8) - ctx.r30.u64;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// slw r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
loc_8267BD10:
	// lwz r11,60(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 60);
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,60(r26)
	REX_STORE_U32(ctx.r26.u32 + 60, ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x8267bcc8
	if (ctx.cr6.gt) goto loc_8267BCC8;
loc_8267BD28:
	// stw r27,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r27.u32);
	// b 0x8267ca64
	goto loc_8267CA64;
loc_8267BD30:
	// lwz r11,60(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8267bd84
	if (!ctx.cr6.gt) goto loc_8267BD84;
	// addi r29,r26,224
	ctx.r29.s64 = ctx.r26.s64 + 224;
loc_8267BD40:
	// lwz r30,60(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + 60);
	// cmpwi cr6,r30,24
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 24, ctx.xer);
	// ble cr6,0x8267bd50
	if (!ctx.cr6.gt) goto loc_8267BD50;
	// li r30,24
	ctx.r30.s64 = 24;
loc_8267BD50:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82678ba0
	ctx.lr = 0x8267BD60;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,60(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 60);
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,60(r26)
	REX_STORE_U32(ctx.r26.u32 + 60, ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x8267bd40
	if (ctx.cr6.gt) goto loc_8267BD40;
loc_8267BD84:
	// stw r27,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r27.u32);
	// b 0x8267ca64
	goto loc_8267CA64;
loc_8267BD8C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267BD9C;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lhz r10,580(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// stw r24,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r24.u32);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x8267bde0
	if (!ctx.cr6.gt) goto loc_8267BDE0;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
loc_8267BDD0:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8267bdd0
	if (ctx.cr6.lt) goto loc_8267BDD0;
loc_8267BDE0:
	// lwz r11,132(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8267be00
	if (!ctx.cr6.eq) goto loc_8267BE00;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r24,88(r26)
	REX_STORE_U32(ctx.r26.u32 + 88, ctx.r24.u32);
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
	// stw r23,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r23.u32);
	// b 0x8267ca64
	goto loc_8267CA64;
loc_8267BE00:
	// li r11,40
	ctx.r11.s64 = 40;
	// stw r23,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r23.u32);
	// b 0x8267ca60
	goto loc_8267CA60;
loc_8267BE0C:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82680d98
	ctx.lr = 0x8267BE14;
	sub_82680D98(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267BE28:
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// addi r28,r26,224
	ctx.r28.s64 = ctx.r26.s64 + 224;
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// bl 0x826828e8
	ctx.lr = 0x8267BE40;
	sub_826828E8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8267bee4
	if (!ctx.cr6.gt) goto loc_8267BEE4;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// rlwinm r10,r24,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
loc_8267BE64:
	// lwz r9,584(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lhzx r8,r10,r9
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// mulli r10,r7,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(1776));
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x82678ba0
	ctx.lr = 0x8267BE8C;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r11.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// and r27,r8,r27
	ctx.r27.u64 = ctx.r8.u64 & ctx.r27.u64;
	// bl 0x8265b398
	ctx.lr = 0x8267BEBC;
	sub_8265B398(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lhz r10,580(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// extsh r29,r11
	ctx.r29.s64 = ctx.r11.s16;
	// cmpw cr6,r29,r8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r8.s32, ctx.xer);
	// rlwinm r10,r29,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// blt cr6,0x8267be64
	if (ctx.cr6.lt) goto loc_8267BE64;
loc_8267BEE4:
	// lhz r11,110(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// mulli r10,r11,90
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(90));
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// stw r8,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r8.u32);
	// stw r16,136(r26)
	REX_STORE_U32(ctx.r26.u32 + 136, ctx.r16.u32);
	// bne cr6,0x8267ca8c
	if (!ctx.cr6.eq) goto loc_8267CA8C;
	// li r11,30
	ctx.r11.s64 = 30;
	// b 0x8267ca5c
	goto loc_8267CA5C;
loc_8267BF0C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267BF1C;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x8267caa0
	if (ctx.cr6.eq) goto loc_8267CAA0;
	// stw r17,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r17.u32);
	// b 0x8267ca64
	goto loc_8267CA64;
loc_8267BF44:
	// li r11,42
	ctx.r11.s64 = 42;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267BF4C:
	// li r11,39
	ctx.r11.s64 = 39;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267BF54:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267BF64;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,48
	ctx.r10.s64 = 48;
	// stw r11,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// stw r10,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r10.u32);
loc_8267BF80:
	// addi r28,r26,224
	ctx.r28.s64 = ctx.r26.s64 + 224;
	// lhz r4,34(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826828e8
	ctx.lr = 0x8267BF90;
	sub_826828E8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8267c024
	if (!ctx.cr6.gt) goto loc_8267C024;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// rlwinm r10,r24,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
loc_8267BFB4:
	// lwz r9,584(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lhzx r8,r10,r9
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// mulli r10,r7,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(1776));
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x82678ba0
	ctx.lr = 0x8267BFDC;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r11.u32);
	// bl 0x8265b398
	ctx.lr = 0x8267BFFC;
	sub_8265B398(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lhz r10,580(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// extsh r29,r11
	ctx.r29.s64 = ctx.r11.s16;
	// cmpw cr6,r29,r8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r8.s32, ctx.xer);
	// rlwinm r10,r29,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// blt cr6,0x8267bfb4
	if (ctx.cr6.lt) goto loc_8267BFB4;
loc_8267C024:
	// li r11,18
	ctx.r11.s64 = 18;
	// stw r24,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r24.u32);
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C030:
	// li r11,38
	ctx.r11.s64 = 38;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C038:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c068
	if (!ctx.cr6.eq) goto loc_8267C068;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267C054;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
loc_8267C068:
	// li r11,37
	ctx.r11.s64 = 37;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C070:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c0b4
	if (!ctx.cr6.eq) goto loc_8267C0B4;
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c104
	if (!ctx.cr6.eq) goto loc_8267C104;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267C098;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// sth r10,168(r31)
	REX_STORE_U16(ctx.r31.u32 + 168, ctx.r10.u16);
	// b 0x8267c104
	goto loc_8267C104;
loc_8267C0B4:
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c104
	if (!ctx.cr6.eq) goto loc_8267C104;
	// lwz r11,204(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8267c104
	if (ctx.cr6.eq) goto loc_8267C104;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267C0DC;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bge cr6,0x8267caa0
	if (!ctx.cr6.lt) goto loc_8267CAA0;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8267caa0
	if (ctx.cr6.lt) goto loc_8267CAA0;
	// stw r11,632(r31)
	REX_STORE_U32(ctx.r31.u32 + 632, ctx.r11.u32);
loc_8267C104:
	// li r11,44
	ctx.r11.s64 = 44;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C10C:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c160
	if (!ctx.cr6.eq) goto loc_8267C160;
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c160
	if (!ctx.cr6.eq) goto loc_8267C160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267C134;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,12
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 12, ctx.xer);
	// bgt cr6,0x8267caa0
	if (ctx.cr6.gt) goto loc_8267CAA0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x8267caa0
	if (ctx.cr6.lt) goto loc_8267CAA0;
	// sth r11,170(r31)
	REX_STORE_U16(ctx.r31.u32 + 170, ctx.r11.u16);
loc_8267C160:
	// li r11,46
	ctx.r11.s64 = 46;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C168:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c1c0
	if (!ctx.cr6.eq) goto loc_8267C1C0;
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c1c0
	if (!ctx.cr6.eq) goto loc_8267C1C0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267C190;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// blt cr6,0x8267caa0
	if (ctx.cr6.lt) goto loc_8267CAA0;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bgt cr6,0x8267caa0
	if (ctx.cr6.gt) goto loc_8267CAA0;
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// sth r11,172(r31)
	REX_STORE_U16(ctx.r31.u32 + 172, ctx.r11.u16);
loc_8267C1C0:
	// stw r21,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r21.u32);
loc_8267C1C4:
	// lwz r11,204(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8267c204
	if (ctx.cr6.eq) goto loc_8267C204;
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c204
	if (!ctx.cr6.eq) goto loc_8267C204;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267C1EC;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// sth r10,174(r31)
	REX_STORE_U16(ctx.r31.u32 + 174, ctx.r10.u16);
loc_8267C204:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c218
	if (!ctx.cr6.eq) goto loc_8267C218;
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x8267ca60
	goto loc_8267CA60;
loc_8267C218:
	// stw r15,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r15.u32);
	// b 0x8267ca64
	goto loc_8267CA64;
loc_8267C220:
	// li r11,19
	ctx.r11.s64 = 19;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C228:
	// li r11,29
	ctx.r11.s64 = 29;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C230:
	// li r11,33
	ctx.r11.s64 = 33;
	// sth r24,150(r26)
	REX_STORE_U16(ctx.r26.u32 + 150, ctx.r24.u16);
	// stw r24,44(r26)
	REX_STORE_U32(ctx.r26.u32 + 44, ctx.r24.u32);
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C240:
	// li r11,10
	ctx.r11.s64 = 10;
	// b 0x8267ca60
	goto loc_8267CA60;
loc_8267C248:
	// lhz r11,34(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// addi r30,r26,224
	ctx.r30.s64 = ctx.r26.s64 + 224;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x826828e8
	ctx.lr = 0x8267C25C;
	sub_826828E8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lhz r11,34(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bne cr6,0x8267c2b8
	if (!ctx.cr6.eq) goto loc_8267C2B8;
	// bl 0x82678ba0
	ctx.lr = 0x8267C284;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// stw r11,40(r10)
	REX_STORE_U32(ctx.r10.u32 + 40, ctx.r11.u32);
	// lwz r9,320(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lwz r8,40(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// stw r24,68(r9)
	REX_STORE_U32(ctx.r9.u32 + 68, ctx.r24.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stw r24,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r24.u32);
	// rlwinm r30,r7,27,31,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// b 0x8267c378
	goto loc_8267C378;
loc_8267C2B8:
	// bl 0x82678ba0
	ctx.lr = 0x8267C2BC;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,68(r10)
	REX_STORE_U32(ctx.r10.u32 + 68, ctx.r11.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,320(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// stw r8,1844(r9)
	REX_STORE_U32(ctx.r9.u32 + 1844, ctx.r8.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r7,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r7.u32);
	// bl 0x82678ba0
	ctx.lr = 0x8267C2F8;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// bl 0x82678ba0
	ctx.lr = 0x8267C320;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,1816(r11)
	REX_STORE_U32(ctx.r11.u32 + 1816, ctx.r10.u32);
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lwz r9,1816(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 1816);
	// lwz r7,40(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// cntlzw r5,r9
	ctx.r5.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r8,68(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// and r30,r3,r4
	ctx.r30.u64 = ctx.r3.u64 & ctx.r4.u64;
	// addi r4,r11,1776
	ctx.r4.s64 = ctx.r11.s64 + 1776;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// beq cr6,0x8267c374
	if (ctx.cr6.eq) goto loc_8267C374;
	// li r5,0
	ctx.r5.s64 = 0;
loc_8267C374:
	// bl 0x8267fe50
	ctx.lr = 0x8267C378;
	sub_8267FE50(ctx, base);
loc_8267C378:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r23,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r23.u32);
	// bne cr6,0x8267ca8c
	if (!ctx.cr6.eq) goto loc_8267CA8C;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x8267ca60
	goto loc_8267CA60;
loc_8267C38C:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stw r24,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r24.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8267c3c8
	if (ctx.cr6.lt) goto loc_8267C3C8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267C3AC;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8267c3c8
	if (ctx.cr6.eq) goto loc_8267C3C8;
	// stw r23,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r23.u32);
loc_8267C3C8:
	// li r11,31
	ctx.r11.s64 = 31;
	// sth r24,150(r26)
	REX_STORE_U16(ctx.r26.u32 + 150, ctx.r24.u16);
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C3D4:
	// lwz r11,592(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 592);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c49c
	if (!ctx.cr6.eq) goto loc_8267C49C;
	// lhz r11,150(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 150);
	// lhz r10,580(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x8267c49c
	if (!ctx.cr6.lt) goto loc_8267C49C;
	// addi r29,r26,224
	ctx.r29.s64 = ctx.r26.s64 + 224;
loc_8267C3FC:
	// lhz r10,150(r26)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r26.u32 + 150);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// lwz r9,584(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r6,r7,r9
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r9.u32);
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// mulli r9,r5,1776
	ctx.r9.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(1776));
	// add r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,36(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// addi r4,r10,3
	ctx.r4.s64 = ctx.r10.s64 + 3;
	// srawi r3,r4,2
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 2;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// ble cr6,0x8267c454
	if (!ctx.cr6.gt) goto loc_8267C454;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_8267C444:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r9,r10,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r11.u8 & 0x3F));
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bgt cr6,0x8267c444
	if (ctx.cr6.gt) goto loc_8267C444;
loc_8267C454:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82678ba0
	ctx.lr = 0x8267C464;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,484(r30)
	REX_STORE_U32(ctx.r30.u32 + 484, ctx.r11.u32);
	// lhz r11,150(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 150);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// sth r9,150(r26)
	REX_STORE_U16(ctx.r26.u32 + 150, ctx.r9.u16);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// lhz r6,580(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// cmpw cr6,r4,r5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x8267c3fc
	if (ctx.cr6.lt) goto loc_8267C3FC;
loc_8267C49C:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C4A4:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bgt cr6,0x8267c4bc
	if (ctx.cr6.gt) goto loc_8267C4BC;
	// bl 0x8267fc88
	ctx.lr = 0x8267C4B8;
	sub_8267FC88(ctx, base);
	// b 0x8267c4c0
	goto loc_8267C4C0;
loc_8267C4BC:
	// bl 0x82681678
	ctx.lr = 0x8267C4C0;
	sub_82681678(ctx, base);
loc_8267C4C0:
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,296(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// bl 0x82679fc8
	ctx.lr = 0x8267C4D8;
	sub_82679FC8(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// sth r11,150(r26)
	REX_STORE_U16(ctx.r26.u32 + 150, ctx.r11.u16);
	// lhz r10,580(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x8267c540
	if (!ctx.cr6.gt) goto loc_8267C540;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
loc_8267C4F8:
	// lwz r9,584(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// li r3,0
	ctx.r3.s64 = 0;
	// lhzx r8,r11,r9
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r9.u32);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// mulli r11,r7,1776
	ctx.r11.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(1776));
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stb r24,180(r29)
	REX_STORE_U8(ctx.r29.u32 + 180, ctx.r24.u8);
	// bl 0x82677010
	ctx.lr = 0x8267C520;
	sub_82677010(ctx, base);
	// addi r6,r30,1
	ctx.r6.s64 = ctx.r30.s64 + 1;
	// stfs f1,196(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r29.u32 + 196, temp.u32);
	// lhz r5,580(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r30,r6
	ctx.r30.s64 = ctx.r6.s16;
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r30,r3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x8267c4f8
	if (ctx.cr6.lt) goto loc_8267C4F8;
loc_8267C540:
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r24,132(r26)
	REX_STORE_U32(ctx.r26.u32 + 132, ctx.r24.u32);
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C54C:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82680bc0
	ctx.lr = 0x8267C554;
	sub_82680BC0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// li r10,6
	ctx.r10.s64 = 6;
	// sth r11,152(r26)
	REX_STORE_U16(ctx.r26.u32 + 152, ctx.r11.u16);
	// sth r24,150(r26)
	REX_STORE_U16(ctx.r26.u32 + 150, ctx.r24.u16);
	// stw r10,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r10.u32);
loc_8267C574:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c594
	if (!ctx.cr6.eq) goto loc_8267C594;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8267ffb8
	ctx.lr = 0x8267C588;
	sub_8267FFB8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
loc_8267C594:
	// stw r15,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r15.u32);
loc_8267C598:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bgt cr6,0x8267c624
	if (ctx.cr6.gt) goto loc_8267C624;
	// addi r30,r26,224
	ctx.r30.s64 = ctx.r26.s64 + 224;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r22,r23
	ctx.r22.u64 = ctx.r23.u64;
	// bl 0x826828e8
	ctx.lr = 0x8267C5B8;
	sub_826828E8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8267c624
	if (ctx.cr6.eq) goto loc_8267C624;
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lwz r10,424(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// lhz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// ble cr6,0x8267c624
	if (!ctx.cr6.gt) goto loc_8267C624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82678ba0
	ctx.lr = 0x8267C5F8;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r22,r11
	ctx.r22.u64 = ctx.r11.u64;
	// lhz r9,114(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 114);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8267c624
	if (!ctx.cr6.eq) goto loc_8267C624;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267caa0
	if (!ctx.cr6.eq) goto loc_8267CAA0;
loc_8267C624:
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8267c754
	if (!ctx.cr6.gt) goto loc_8267C754;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// clrlwi r27,r22,24
	ctx.r27.u64 = ctx.r22.u32 & 0xFF;
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
loc_8267C640:
	// lwz r9,584(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lwz r8,8(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r7,460(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 460);
	// lhzx r6,r11,r9
	ctx.r6.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r9.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// mulli r9,r5,1776
	ctx.r9.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(1776));
	// rlwinm r11,r5,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r28,r11,r8
	ctx.r28.u64 = ctx.r11.u64 + ctx.r8.u64;
	// beq cr6,0x8267c688
	if (ctx.cr6.eq) goto loc_8267C688;
	// lwz r11,456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// lhz r10,118(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 118);
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// sraw r9,r8,r6
	temp.u32 = ctx.r6.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r9.s64 = ctx.r8.s32 >> temp.u32;
	// b 0x8267c6a4
	goto loc_8267C6A4;
loc_8267C688:
	// lwz r11,448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 448);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r11,118(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 118);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// beq cr6,0x8267c6a4
	if (ctx.cr6.eq) goto loc_8267C6A4;
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// slw r9,r9,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
loc_8267C6A4:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8267c6bc
	if (ctx.cr6.eq) goto loc_8267C6BC;
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// sraw r10,r11,r10
	temp.u32 = ctx.r10.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r11.s32 < 0) & (((ctx.r11.s32 >> temp.u32) << temp.u32) != ctx.r11.s32);
	ctx.r10.s64 = ctx.r11.s32 >> temp.u32;
	// b 0x8267c6dc
	goto loc_8267C6DC;
loc_8267C6BC:
	// lwz r11,448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 448);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// beq cr6,0x8267c6d8
	if (ctx.cr6.eq) goto loc_8267C6D8;
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// slw r10,r11,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// b 0x8267c6dc
	goto loc_8267C6DC;
loc_8267C6D8:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8267C6DC:
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// lwz r9,56(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// lwz r9,460(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 460);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8267c708
	if (ctx.cr6.eq) goto loc_8267C708;
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// sraw r11,r11,r10
	temp.u32 = ctx.r10.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r11.s32 < 0) & (((ctx.r11.s32 >> temp.u32) << temp.u32) != ctx.r11.s32);
	ctx.r11.s64 = ctx.r11.s32 >> temp.u32;
	// b 0x8267c71c
	goto loc_8267C71C;
loc_8267C708:
	// lwz r10,448(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 448);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8267c71c
	if (ctx.cr6.eq) goto loc_8267C71C;
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// slw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
loc_8267C71C:
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8273a590
	ctx.lr = 0x8267C728;
	sub_8273A590(ctx, base);
	// stw r24,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r24.u32);
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// extsh r29,r11
	ctx.r29.s64 = ctx.r11.s16;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,424(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// lwz r8,16(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// stb r27,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r27.u8);
	// lhz r7,580(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// cmpw cr6,r29,r6
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x8267c640
	if (ctx.cr6.lt) goto loc_8267C640;
loc_8267C754:
	// li r11,9
	ctx.r11.s64 = 9;
	// sth r24,150(r26)
	REX_STORE_U16(ctx.r26.u32 + 150, ctx.r24.u16);
	// sth r24,152(r26)
	REX_STORE_U16(ctx.r26.u32 + 152, ctx.r24.u16);
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267C764:
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267ca58
	if (!ctx.cr6.eq) goto loc_8267CA58;
	// lhz r11,150(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 150);
	// lhz r10,580(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x8267ca58
	if (!ctx.cr6.lt) goto loc_8267CA58;
loc_8267C788:
	// lhz r11,150(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 150);
	// lwz r9,584(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// extsh r8,r11
	ctx.r8.s64 = ctx.r11.s16;
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lwz r7,60(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r7,2
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 2, ctx.xer);
	// lhzx r5,r6,r9
	ctx.r5.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r9.u32);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// mulli r11,r4,1776
	ctx.r11.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(1776));
	// add r27,r11,r10
	ctx.r27.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ble cr6,0x8267c7dc
	if (!ctx.cr6.gt) goto loc_8267C7DC;
	// lwz r10,8(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8267c7dc
	if (!ctx.cr6.eq) goto loc_8267C7DC;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82681518
	ctx.lr = 0x8267C7D8;
	sub_82681518(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_8267C7DC:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,424(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 424);
	// lwz r10,40(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 40);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lbz r22,0(r9)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// bne cr6,0x8267c82c
	if (!ctx.cr6.eq) goto loc_8267C82C;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bgt cr6,0x8267c82c
	if (ctx.cr6.gt) goto loc_8267C82C;
	// cmpwi cr6,r22,1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 1, ctx.xer);
	// bne cr6,0x8267ca0c
	if (!ctx.cr6.eq) goto loc_8267CA0C;
	// lwz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8273a590
	ctx.lr = 0x8267C824;
	sub_8273A590(ctx, base);
	// stw r24,64(r27)
	REX_STORE_U32(ctx.r27.u32 + 64, ctx.r24.u32);
	// b 0x8267ca0c
	goto loc_8267CA0C;
loc_8267C82C:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
	// lwz r30,4(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// ble cr6,0x8267c844
	if (!ctx.cr6.gt) goto loc_8267C844;
	// mr r28,r20
	ctx.r28.u64 = ctx.r20.u64;
loc_8267C844:
	// cmpwi cr6,r22,1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 1, ctx.xer);
	// bne cr6,0x8267c9bc
	if (!ctx.cr6.eq) goto loc_8267C9BC;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// ble cr6,0x8267c880
	if (!ctx.cr6.gt) goto loc_8267C880;
	// lwz r10,444(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 444);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8267c880
	if (!ctx.cr6.eq) goto loc_8267C880;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r5,304(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82681dd0
	ctx.lr = 0x8267C870;
	sub_82681DD0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// b 0x8267c994
	goto loc_8267C994;
loc_8267C880:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8267c8bc
	if (!ctx.cr6.eq) goto loc_8267C8BC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r3,r26,224
	ctx.r3.s64 = ctx.r26.s64 + 224;
	// bl 0x82678ba0
	ctx.lr = 0x8267C898;
	sub_82678BA0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,10
	ctx.r10.s64 = ctx.r11.s64 + 10;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lhz r11,152(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 152);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// sth r8,152(r26)
	REX_STORE_U16(ctx.r26.u32 + 152, ctx.r8.u16);
loc_8267C8BC:
	// lhz r11,152(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 152);
	// lwz r10,304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8267c994
	if (!ctx.cr6.lt) goto loc_8267C994;
	// addi r29,r26,224
	ctx.r29.s64 = ctx.r26.s64 + 224;
loc_8267C8D4:
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82683158
	ctx.lr = 0x8267C8EC;
	sub_82683158(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82678d10
	ctx.lr = 0x8267C904;
	sub_82678D10(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8267caa8
	if (ctx.cr6.lt) goto loc_8267CAA8;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r9,r11,-60
	ctx.r9.s64 = ctx.r11.s64 + -60;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ble cr6,0x8267c944
	if (!ctx.cr6.gt) goto loc_8267C944;
	// lhz r11,152(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 152);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8267c944
	if (!ctx.cr6.eq) goto loc_8267C944;
	// lwz r11,436(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 436);
	// divw r11,r21,r11
	ctx.r11.u64 = uint32_t((ctx.r11.s32 && !(ctx.r21.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r21.s32 / ctx.r11.s32 : 0);
	// b 0x8267c968
	goto loc_8267C968;
loc_8267C944:
	// lhz r11,152(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 152);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8267c95c
	if (!ctx.cr6.eq) goto loc_8267C95C;
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// b 0x8267c968
	goto loc_8267C968;
loc_8267C95C:
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r11,-4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
loc_8267C968:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stwx r9,r10,r30
	REX_STORE_U32(ctx.r10.u32 + ctx.r30.u32, ctx.r9.u32);
	// lhz r11,152(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 152);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// sth r7,152(r26)
	REX_STORE_U16(ctx.r26.u32 + 152, ctx.r7.u16);
	// clrlwi r4,r7,16
	ctx.r4.u64 = ctx.r7.u32 & 0xFFFF;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// lwz r5,304(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// cmpw cr6,r3,r5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x8267c8d4
	if (ctx.cr6.lt) goto loc_8267C8D4;
loc_8267C994:
	// lhz r11,114(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 114);
	// lwz r10,424(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 424);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r7,8(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lhzx r6,r8,r7
	ctx.r6.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r7.u32);
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// stw r5,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r5.u32);
	// sth r24,152(r26)
	REX_STORE_U16(ctx.r26.u32 + 152, ctx.r24.u16);
	// b 0x8267c9c4
	goto loc_8267C9C4;
loc_8267C9BC:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x8267ca0c
	if (ctx.cr6.eq) goto loc_8267CA0C;
loc_8267C9C4:
	// lwz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x8267ca04
	if (!ctx.cr6.gt) goto loc_8267CA04;
	// lwz r8,304(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// rlwinm r10,r23,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
loc_8267C9E0:
	// lwzx r10,r10,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x8267c9f0
	if (!ctx.cr6.gt) goto loc_8267C9F0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8267C9F0:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// blt cr6,0x8267c9e0
	if (ctx.cr6.lt) goto loc_8267C9E0;
loc_8267CA04:
	// stw r9,64(r27)
	REX_STORE_U32(ctx.r27.u32 + 64, ctx.r9.u32);
	// stw r23,444(r27)
	REX_STORE_U32(ctx.r27.u32 + 444, ctx.r23.u32);
loc_8267CA0C:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// ble cr6,0x8267ca34
	if (!ctx.cr6.gt) goto loc_8267CA34;
	// cmpwi cr6,r22,1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 1, ctx.xer);
	// bne cr6,0x8267ca34
	if (!ctx.cr6.eq) goto loc_8267CA34;
	// lhz r11,118(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 118);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// stw r10,428(r27)
	REX_STORE_U32(ctx.r27.u32 + 428, ctx.r10.u32);
	// lwz r9,304(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// stw r9,432(r27)
	REX_STORE_U32(ctx.r27.u32 + 432, ctx.r9.u32);
loc_8267CA34:
	// lhz r11,150(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 150);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r10,150(r26)
	REX_STORE_U16(ctx.r26.u32 + 150, ctx.r10.u16);
	// lhz r7,580(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// cmpw cr6,r6,r5
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x8267c788
	if (ctx.cr6.lt) goto loc_8267C788;
loc_8267CA58:
	// li r11,10
	ctx.r11.s64 = 10;
loc_8267CA5C:
	// li r27,14
	ctx.r27.s64 = 14;
loc_8267CA60:
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
loc_8267CA64:
	// lwz r11,40(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 40);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x8267b778
	if (!ctx.cr6.eq) goto loc_8267B778;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_8267CA7C:
	// lis r3,-32764
	ctx.r3.s64 = -2147221504;
	// ori r3,r3,2
	ctx.r3.u64 = ctx.r3.u64 | 2;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_8267CA8C:
	// li r11,10
	ctx.r11.s64 = 10;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r11,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_8267CAA0:
	// lis r25,-32764
	ctx.r25.s64 = -2147221504;
	// ori r25,r25,2
	ctx.r25.u64 = ctx.r25.u64 | 2;
loc_8267CAA8:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827141F0) {
	REX_FUNC_PROLOGUE();
	// stw r3,20(r1)
	REX_STORE_U32(ctx.r1.u32 + 20, ctx.r3.u32);
	// stw r4,28(r1)
	REX_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// stw r5,36(r1)
	REX_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// lwz r11,20(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r10,48(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// stw r9,-60(r1)
	REX_STORE_U32(ctx.r1.u32 + -60, ctx.r9.u32);
	// lwz r8,20(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r7,48(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 48);
	// lwz r6,4(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// stw r6,-32(r1)
	REX_STORE_U32(ctx.r1.u32 + -32, ctx.r6.u32);
	// lwz r5,-32(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -32);
	// rlwinm r4,r5,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// lwz r3,20(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// divw r10,r4,r11
	ctx.r10.u64 = uint32_t((ctx.r11.s32 && !(ctx.r4.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r4.s32 / ctx.r11.s32 : 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// rotlwi r9,r4,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// andc r7,r11,r8
	ctx.r7.u64 = ctx.r11.u64 & ~ctx.r8.u64;
	// twlgei r7,-1
	if (ctx.r7.s32 == -1 || ctx.r7.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// stw r10,-36(r1)
	REX_STORE_U32(ctx.r1.u32 + -36, ctx.r10.u32);
	// lwz r6,-32(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -32);
	// addi r5,r6,-1
	ctx.r5.s64 = ctx.r6.s64 + -1;
	// lwz r4,20(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r3,32(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 32);
	// mullw r11,r5,r3
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r3.s32);
	// lwz r10,-32(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -32);
	// divw r9,r11,r10
	ctx.r9.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r7,r8,-1
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// andc r6,r10,r7
	ctx.r6.u64 = ctx.r10.u64 & ~ctx.r7.u64;
	// twlgei r6,-1
	if (ctx.r6.s32 == -1 || ctx.r6.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// stw r9,-56(r1)
	REX_STORE_U32(ctx.r1.u32 + -56, ctx.r9.u32);
	// lwz r5,-32(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -32);
	// li r4,2
	ctx.r4.s64 = 2;
	// divw r3,r5,r4
	ctx.r3.u64 = uint32_t((ctx.r4.s32 && !(ctx.r5.s32 == INT32_MIN && ctx.r4.s32 == -1)) ? ctx.r5.s32 / ctx.r4.s32 : 0);
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lwz r10,20(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r9,32(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,-32(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -32);
	// divw r6,r8,r7
	ctx.r6.u64 = uint32_t((ctx.r7.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r7.s32 == -1)) ? ctx.r8.s32 / ctx.r7.s32 : 0);
	// twllei r7,0
	if (ctx.r7.s32 == 0 || ctx.r7.u32 < 0u) ppc_trap(ctx, base, 0);
	// rotlwi r5,r8,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// addi r4,r5,-1
	ctx.r4.s64 = ctx.r5.s64 + -1;
	// andc r3,r7,r4
	ctx.r3.u64 = ctx.r7.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	if (ctx.r3.s32 == -1 || ctx.r3.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// stw r6,-72(r1)
	REX_STORE_U32(ctx.r1.u32 + -72, ctx.r6.u32);
	// lwz r11,-32(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,-76(r1)
	REX_STORE_U32(ctx.r1.u32 + -76, ctx.r10.u32);
	// lwz r9,-60(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -60);
	// li r8,2
	ctx.r8.s64 = 2;
	// divw r7,r9,r8
	ctx.r7.u64 = uint32_t((ctx.r8.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r8.s32 == -1)) ? ctx.r9.s32 / ctx.r8.s32 : 0);
	// stw r7,-44(r1)
	REX_STORE_U32(ctx.r1.u32 + -44, ctx.r7.u32);
	// lwz r6,20(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r5,36(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 36);
	// li r4,2
	ctx.r4.s64 = 2;
	// divw r3,r5,r4
	ctx.r3.u64 = uint32_t((ctx.r4.s32 && !(ctx.r5.s32 == INT32_MIN && ctx.r4.s32 == -1)) ? ctx.r5.s32 / ctx.r4.s32 : 0);
	// stw r3,-28(r1)
	REX_STORE_U32(ctx.r1.u32 + -28, ctx.r3.u32);
	// lwz r11,20(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// li r9,2
	ctx.r9.s64 = 2;
	// divw r8,r10,r9
	ctx.r8.u64 = uint32_t((ctx.r9.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r10.s32 / ctx.r9.s32 : 0);
	// stw r8,-20(r1)
	REX_STORE_U32(ctx.r1.u32 + -20, ctx.r8.u32);
	// lwz r7,20(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r6,28(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// lwz r5,-76(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -76);
	// mullw r4,r6,r5
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// lwz r3,52(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 52);
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stw r11,-48(r1)
	REX_STORE_U32(ctx.r1.u32 + -48, ctx.r11.u32);
	// lwz r10,20(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r9,20(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r8,28(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// lwz r7,32(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 32);
	// mullw r6,r8,r7
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// lwz r5,64(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// add r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stw r4,-64(r1)
	REX_STORE_U32(ctx.r1.u32 + -64, ctx.r4.u32);
	// lwz r3,-36(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8271434c
	if (!ctx.cr6.lt) goto loc_8271434C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-36(r1)
	REX_STORE_U32(ctx.r1.u32 + -36, ctx.r11.u32);
loc_8271434C:
	// lwz r10,28(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// stw r10,-68(r1)
	REX_STORE_U32(ctx.r1.u32 + -68, ctx.r10.u32);
	// b 0x82714364
	goto loc_82714364;
loc_82714358:
	// lwz r9,-68(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -68);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,-68(r1)
	REX_STORE_U32(ctx.r1.u32 + -68, ctx.r8.u32);
loc_82714364:
	// lwz r7,-68(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -68);
	// lwz r6,36(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 36);
	// cmpw cr6,r7,r6
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x827144b0
	if (!ctx.cr6.lt) goto loc_827144B0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r5,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r5.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r4,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r4.u32);
	// b 0x82714394
	goto loc_82714394;
loc_82714388:
	// lwz r3,-24(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// stw r11,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r11.u32);
loc_82714394:
	// lwz r10,-24(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// lwz r9,-56(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -56);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8271442c
	if (!ctx.cr6.lt) goto loc_8271442C;
	// lwz r8,-16(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -16);
	// clrlwi r7,r8,25
	ctx.r7.u64 = ctx.r8.u32 & 0x7F;
	// stw r7,-52(r1)
	REX_STORE_U32(ctx.r1.u32 + -52, ctx.r7.u32);
	// lwz r6,-16(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -16);
	// srawi r5,r6,7
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7F) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 7;
	// rlwinm r4,r5,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r4,-80(r1)
	REX_STORE_U32(ctx.r1.u32 + -80, ctx.r4.u32);
	// lwz r3,-52(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -52);
	// subfic r11,r3,128
	ctx.xer.ca = ctx.r3.u32 <= 128;
	ctx.r11.u64 = static_cast<uint64_t>(128) - ctx.r3.u64;
	// stw r11,-40(r1)
	REX_STORE_U32(ctx.r1.u32 + -40, ctx.r11.u32);
	// lwz r10,-48(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r9,-80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -80);
	// lbzx r8,r10,r9
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// lwz r7,-40(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -40);
	// mullw r6,r7,r8
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// lwz r5,-80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -80);
	// addi r4,r5,2
	ctx.r4.s64 = ctx.r5.s64 + 2;
	// lwz r3,-48(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lbzx r11,r3,r4
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r4.u32);
	// lwz r10,-52(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -52);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// add r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 + ctx.r9.u64;
	// srawi r7,r8,7
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7F) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 7;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// lwz r5,-64(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// stb r6,0(r5)
	REX_STORE_U8(ctx.r5.u32 + 0, ctx.r6.u8);
	// lwz r4,-64(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// addi r3,r4,1
	ctx.r3.s64 = ctx.r4.s64 + 1;
	// stw r3,-64(r1)
	REX_STORE_U32(ctx.r1.u32 + -64, ctx.r3.u32);
	// lwz r11,-16(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -16);
	// lwz r10,-36(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -36);
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r9,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r9.u32);
	// b 0x82714388
	goto loc_82714388;
loc_8271442C:
	// lwz r8,-56(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -56);
	// stw r8,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r8.u32);
	// b 0x82714444
	goto loc_82714444;
loc_82714438:
	// lwz r7,-24(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// addi r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 1;
	// stw r6,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r6.u32);
loc_82714444:
	// lwz r5,20(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r4,-24(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// lwz r3,32(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 32);
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x8271449c
	if (!ctx.cr6.lt) goto loc_8271449C;
	// lwz r11,-16(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -16);
	// srawi r10,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 7;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,-80(r1)
	REX_STORE_U32(ctx.r1.u32 + -80, ctx.r9.u32);
	// lwz r8,-48(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r7,-80(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -80);
	// lbzx r6,r8,r7
	ctx.r6.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r7.u32);
	// lwz r5,-64(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// stb r6,0(r5)
	REX_STORE_U8(ctx.r5.u32 + 0, ctx.r6.u8);
	// lwz r4,-64(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// addi r3,r4,1
	ctx.r3.s64 = ctx.r4.s64 + 1;
	// stw r3,-64(r1)
	REX_STORE_U32(ctx.r1.u32 + -64, ctx.r3.u32);
	// lwz r11,-16(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -16);
	// lwz r10,-36(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -36);
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r9,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r9.u32);
	// b 0x82714438
	goto loc_82714438;
loc_8271449C:
	// lwz r8,-48(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r7,-76(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -76);
	// add r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r6,-48(r1)
	REX_STORE_U32(ctx.r1.u32 + -48, ctx.r6.u32);
	// b 0x82714358
	goto loc_82714358;
loc_827144B0:
	// lwz r5,20(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r4,52(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 52);
	// addi r3,r4,1
	ctx.r3.s64 = ctx.r4.s64 + 1;
	// lwz r11,28(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// lwz r10,-76(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -76);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// add r8,r3,r9
	ctx.r8.u64 = ctx.r3.u64 + ctx.r9.u64;
	// stw r8,-48(r1)
	REX_STORE_U32(ctx.r1.u32 + -48, ctx.r8.u32);
	// lwz r7,20(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r6,20(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r5,-60(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -60);
	// lwz r4,32(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 32);
	// mullw r3,r5,r4
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// lwz r11,64(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// add r10,r11,r3
	ctx.r10.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r9,28(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// lwz r8,-20(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
	// mullw r7,r9,r8
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// add r6,r10,r7
	ctx.r6.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r6,-64(r1)
	REX_STORE_U32(ctx.r1.u32 + -64, ctx.r6.u32);
	// lwz r5,28(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// stw r5,-68(r1)
	REX_STORE_U32(ctx.r1.u32 + -68, ctx.r5.u32);
	// b 0x82714518
	goto loc_82714518;
loc_8271450C:
	// lwz r4,-68(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -68);
	// addi r3,r4,1
	ctx.r3.s64 = ctx.r4.s64 + 1;
	// stw r3,-68(r1)
	REX_STORE_U32(ctx.r1.u32 + -68, ctx.r3.u32);
loc_82714518:
	// lwz r11,-68(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -68);
	// lwz r10,36(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 36);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x82714660
	if (!ctx.cr6.lt) goto loc_82714660;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,-12(r1)
	REX_STORE_U32(ctx.r1.u32 + -12, ctx.r9.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r8.u32);
	// b 0x82714548
	goto loc_82714548;
loc_8271453C:
	// lwz r7,-24(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// addi r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 1;
	// stw r6,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r6.u32);
loc_82714548:
	// lwz r5,-24(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// lwz r4,-72(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -72);
	// cmpw cr6,r5,r4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x827145e0
	if (!ctx.cr6.lt) goto loc_827145E0;
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// clrlwi r11,r3,25
	ctx.r11.u64 = ctx.r3.u32 & 0x7F;
	// stw r11,-52(r1)
	REX_STORE_U32(ctx.r1.u32 + -52, ctx.r11.u32);
	// lwz r10,-12(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// srawi r9,r10,7
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 7;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,-80(r1)
	REX_STORE_U32(ctx.r1.u32 + -80, ctx.r8.u32);
	// lwz r7,-52(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -52);
	// subfic r6,r7,128
	ctx.xer.ca = ctx.r7.u32 <= 128;
	ctx.r6.u64 = static_cast<uint64_t>(128) - ctx.r7.u64;
	// stw r6,-40(r1)
	REX_STORE_U32(ctx.r1.u32 + -40, ctx.r6.u32);
	// lwz r5,-48(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r4,-80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -80);
	// lbzx r3,r5,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// lwz r11,-40(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -40);
	// mullw r10,r11,r3
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// lwz r9,-80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -80);
	// addi r8,r9,4
	ctx.r8.s64 = ctx.r9.s64 + 4;
	// lwz r7,-48(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lbzx r6,r7,r8
	ctx.r6.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// lwz r5,-52(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -52);
	// mullw r4,r5,r6
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// add r3,r10,r4
	ctx.r3.u64 = ctx.r10.u64 + ctx.r4.u64;
	// srawi r11,r3,7
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 7;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// lwz r9,-64(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// stb r10,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r8,-64(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// stw r7,-64(r1)
	REX_STORE_U32(ctx.r1.u32 + -64, ctx.r7.u32);
	// lwz r6,-12(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// lwz r5,-36(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -36);
	// add r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 + ctx.r5.u64;
	// stw r4,-12(r1)
	REX_STORE_U32(ctx.r1.u32 + -12, ctx.r4.u32);
	// b 0x8271453c
	goto loc_8271453C;
loc_827145E0:
	// lwz r3,-72(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -72);
	// stw r3,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r3.u32);
	// b 0x827145f8
	goto loc_827145F8;
loc_827145EC:
	// lwz r11,-24(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r10,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r10.u32);
loc_827145F8:
	// lwz r9,-24(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// lwz r8,-20(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x8271464c
	if (!ctx.cr6.lt) goto loc_8271464C;
	// lwz r7,-12(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// srawi r6,r7,7
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 7;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r5,-80(r1)
	REX_STORE_U32(ctx.r1.u32 + -80, ctx.r5.u32);
	// lwz r4,-48(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r3,-80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -80);
	// lbzx r11,r4,r3
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r3.u32);
	// lwz r10,-64(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// stb r11,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lwz r9,-64(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,-64(r1)
	REX_STORE_U32(ctx.r1.u32 + -64, ctx.r8.u32);
	// lwz r7,-12(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// lwz r6,-36(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -36);
	// add r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r5,-12(r1)
	REX_STORE_U32(ctx.r1.u32 + -12, ctx.r5.u32);
	// b 0x827145ec
	goto loc_827145EC;
loc_8271464C:
	// lwz r4,-48(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r3,-76(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -76);
	// add r11,r4,r3
	ctx.r11.u64 = ctx.r4.u64 + ctx.r3.u64;
	// stw r11,-48(r1)
	REX_STORE_U32(ctx.r1.u32 + -48, ctx.r11.u32);
	// b 0x8271450c
	goto loc_8271450C;
loc_82714660:
	// lwz r10,20(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r9,52(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 52);
	// addi r8,r9,3
	ctx.r8.s64 = ctx.r9.s64 + 3;
	// lwz r7,28(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// lwz r6,-76(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -76);
	// mullw r5,r7,r6
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// add r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 + ctx.r5.u64;
	// stw r4,-48(r1)
	REX_STORE_U32(ctx.r1.u32 + -48, ctx.r4.u32);
	// lwz r3,20(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r11,20(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r10,-60(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -60);
	// lwz r9,32(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lwz r7,64(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// add r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lwz r5,-60(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -60);
	// lwz r4,-20(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
	// mullw r3,r5,r4
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// add r11,r6,r3
	ctx.r11.u64 = ctx.r6.u64 + ctx.r3.u64;
	// lwz r10,28(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// lwz r9,-20(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r7,r11,r8
	ctx.r7.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r7,-64(r1)
	REX_STORE_U32(ctx.r1.u32 + -64, ctx.r7.u32);
	// lwz r6,28(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// stw r6,-68(r1)
	REX_STORE_U32(ctx.r1.u32 + -68, ctx.r6.u32);
	// b 0x827146d8
	goto loc_827146D8;
loc_827146CC:
	// lwz r5,-68(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -68);
	// addi r4,r5,1
	ctx.r4.s64 = ctx.r5.s64 + 1;
	// stw r4,-68(r1)
	REX_STORE_U32(ctx.r1.u32 + -68, ctx.r4.u32);
loc_827146D8:
	// lwz r3,-68(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -68);
	// lwz r11,36(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 36);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82714820
	if (!ctx.cr6.lt) goto loc_82714820;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r10.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r9.u32);
	// b 0x82714708
	goto loc_82714708;
loc_827146FC:
	// lwz r8,-24(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// stw r7,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r7.u32);
loc_82714708:
	// lwz r6,-24(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// lwz r5,-72(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -72);
	// cmpw cr6,r6,r5
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x827147a0
	if (!ctx.cr6.lt) goto loc_827147A0;
	// lwz r4,-8(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// clrlwi r3,r4,25
	ctx.r3.u64 = ctx.r4.u32 & 0x7F;
	// stw r3,-52(r1)
	REX_STORE_U32(ctx.r1.u32 + -52, ctx.r3.u32);
	// lwz r11,-8(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// srawi r10,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 7;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,-80(r1)
	REX_STORE_U32(ctx.r1.u32 + -80, ctx.r9.u32);
	// lwz r8,-52(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -52);
	// subfic r7,r8,128
	ctx.xer.ca = ctx.r8.u32 <= 128;
	ctx.r7.u64 = static_cast<uint64_t>(128) - ctx.r8.u64;
	// stw r7,-40(r1)
	REX_STORE_U32(ctx.r1.u32 + -40, ctx.r7.u32);
	// lwz r6,-48(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r5,-80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -80);
	// lbzx r4,r6,r5
	ctx.r4.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r5.u32);
	// lwz r3,-40(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -40);
	// mullw r11,r3,r4
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// lwz r10,-80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -80);
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// lwz r8,-48(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lbzx r7,r8,r9
	ctx.r7.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// lwz r6,-52(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -52);
	// mullw r5,r6,r7
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// add r4,r11,r5
	ctx.r4.u64 = ctx.r11.u64 + ctx.r5.u64;
	// srawi r3,r4,7
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7F) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 7;
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r10,-64(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// stb r11,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lwz r9,-64(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,-64(r1)
	REX_STORE_U32(ctx.r1.u32 + -64, ctx.r8.u32);
	// lwz r7,-8(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// lwz r6,-36(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -36);
	// add r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r5,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r5.u32);
	// b 0x827146fc
	goto loc_827146FC;
loc_827147A0:
	// lwz r4,-72(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -72);
	// stw r4,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r4.u32);
	// b 0x827147b8
	goto loc_827147B8;
loc_827147AC:
	// lwz r3,-24(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// stw r11,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r11.u32);
loc_827147B8:
	// lwz r10,-24(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// lwz r9,-20(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8271480c
	if (!ctx.cr6.lt) goto loc_8271480C;
	// lwz r8,-8(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// srawi r7,r8,7
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7F) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 7;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r6,-80(r1)
	REX_STORE_U32(ctx.r1.u32 + -80, ctx.r6.u32);
	// lwz r5,-48(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r4,-80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -80);
	// lbzx r3,r5,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// lwz r11,-64(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// stb r3,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r3.u8);
	// lwz r10,-64(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,-64(r1)
	REX_STORE_U32(ctx.r1.u32 + -64, ctx.r9.u32);
	// lwz r8,-8(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// lwz r7,-36(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -36);
	// add r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r6,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r6.u32);
	// b 0x827147ac
	goto loc_827147AC;
loc_8271480C:
	// lwz r5,-48(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r4,-76(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -76);
	// add r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 + ctx.r4.u64;
	// stw r3,-48(r1)
	REX_STORE_U32(ctx.r1.u32 + -48, ctx.r3.u32);
	// b 0x827146cc
	goto loc_827146CC;
loc_82714820:
	// blr 
	return;
}

DEFINE_REX_FUNC(__savefpr_31) {
	REX_FUNC_PROLOGUE();
	// stfd f31,-8(r12)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(__restfpr_23) {
	REX_FUNC_PROLOGUE();
	// lfd f23,-72(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f23.u64 = REX_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = REX_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = REX_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = REX_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = REX_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = REX_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(__savevmx_65) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-1008
	ctx.r11.s64 = -1008;
	// stvx128 v65,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v65.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-992
	ctx.r11.s64 = -992;
	// stvx128 v66,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v66.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-976
	ctx.r11.s64 = -976;
	// stvx128 v67,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v67.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-960
	ctx.r11.s64 = -960;
	// stvx128 v68,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v68.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-944
	ctx.r11.s64 = -944;
	// stvx128 v69,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v69.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-928
	ctx.r11.s64 = -928;
	// stvx128 v70,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v70.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-912
	ctx.r11.s64 = -912;
	// stvx128 v71,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v71.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-896
	ctx.r11.s64 = -896;
	// stvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v72.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v73.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v74.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v75.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v76.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v77.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v78.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v79.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v80.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v81.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v82.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v83.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v84.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v85.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v86.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v87.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v88.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

DEFINE_REX_FUNC(sub_8273CFC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-144
	ctx.r31.s64 = ctx.r12.s64 + -144;
	// std r29,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r29.u64);
	// std r28,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r28.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-32(r1)
	REX_STORE_U32(ctx.r1.u32 + -32, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r28,80(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r29,r11,-13276
	ctx.r29.s64 = ctx.r11.s64 + -13276;
	// b 0x8273d010
	goto loc_8273D010;
loc_8273D010:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwzx r4,r10,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// bl 0x8273c638
	ctx.lr = 0x8273D024;
	sub_8273C638(ctx, base);
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lwz r27,164(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r28,80(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r29,r10,-13276
	ctx.r29.s64 = ctx.r10.s64 + -13276;
	// addi r10,r11,-13272
	ctx.r10.s64 = ctx.r11.s64 + -13272;
	// lwz r1,0(r1)
	ctx.r1.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// ld r29,-16(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r28,-24(r1)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// lwz r12,-32(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -32);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8273F4B8) {
	REX_FUNC_PROLOGUE();
	// rlwinm. r11,r3,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f4c8
	if (ctx.cr0.eq) goto loc_8273F4C8;
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_8273F4C8:
	// rlwinm. r11,r3,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f4d8
	if (ctx.cr0.eq) goto loc_8273F4D8;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8273F4D8:
	// rlwinm. r11,r3,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f4e8
	if (ctx.cr0.eq) goto loc_8273F4E8;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8273F4E8:
	// clrlwi. r11,r3,31
	ctx.r11.u64 = ctx.r3.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f4f8
	if (ctx.cr0.eq) goto loc_8273F4F8;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8273F4F8:
	// rlwinm r3,r3,1,29,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x4;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82741B60) {
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
	// beq cr6,0x82741b94
	if (ctx.cr6.eq) goto loc_82741B94;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lwz r10,20764(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20764);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82741bb8
	if (ctx.cr6.eq) goto loc_82741BB8;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82741B90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82741bb8
	goto loc_82741BB8;
loc_82741B94:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lwz r10,20768(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20768);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82741bb0
	if (ctx.cr6.eq) goto loc_82741BB0;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82741BB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82741BB0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8273ab88
	ctx.lr = 0x82741BB8;
	sub_8273AB88(ctx, base);
loc_82741BB8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82744EB8) {
	REX_FUNC_PROLOGUE();
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x82744d98
	sub_82744D98(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82745348) {
	REX_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x82745218
	sub_82745218(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827457F8) {
	REX_FUNC_PROLOGUE();
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8273a638
	sub_8273A638(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82745A68) {
	REX_FUNC_PROLOGUE();
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
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// b 0x82855b34
	__imp__RtlLeaveCriticalSection(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827486B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x827486B8;
	__savegprlr_27(ctx, base);
	// addi r31,r1,-176
	ctx.r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r5,3
	ctx.r11.s64 = ctx.r5.s64 + 3;
	// stw r4,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r4.u32);
	// lis r27,-32256
	ctx.r27.s64 = -2113929216;
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r5,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r5.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r29,r11,3
	ctx.r29.s64 = ctx.r11.s64 + 3;
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// addi r11,r31,80
	ctx.r11.s64 = ctx.r31.s64 + 80;
	// stw r9,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r9.u32);
	// rlwinm r10,r29,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 24) & 0xFF000000;
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,1996(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 1996);
	// ori r10,r10,98
	ctx.r10.u64 = ctx.r10.u64 | 98;
	// stw r8,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r8.u32);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// stw r10,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82748734
	if (ctx.cr6.eq) goto loc_82748734;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// addi r4,r31,96
	ctx.r4.s64 = ctx.r31.s64 + 96;
	// li r3,94
	ctx.r3.s64 = 94;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82748730;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82748738
	goto loc_82748738;
loc_82748734:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82748738:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x82748748
	if (!ctx.cr6.gt) goto loc_82748748;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827487c4
	goto loc_827487C4;
loc_82748748:
	// blt cr6,0x827487c0
	if (ctx.cr6.lt) goto loc_827487C0;
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// rlwinm r12,r11,0,0,27
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x8273adc4
	ctx.lr = 0x8274875C;
	sub_8273ADC4(ctx, base);
	// lwz r11,0(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r9,88(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r8,80(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// stwux r11,r1,r12
	ea = ctx.r1.u32 + ctx.r12.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r1.u32 = ea;
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,12
	ctx.r3.s64 = ctx.r30.s64 + 12;
	// stw r8,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// stw r9,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// bl 0x8273a030
	ctx.lr = 0x82748790;
	sub_8273A030(ctx, base);
	// lwz r11,1996(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 1996);
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r29,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r29.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827487c0
	if (ctx.cr6.eq) goto loc_827487C0;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// addi r4,r31,96
	ctx.r4.s64 = ctx.r31.s64 + 96;
	// li r3,67
	ctx.r3.s64 = 67;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827487BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x827487c4
	goto loc_827487C4;
loc_827487C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827487C4:
	// addi r1,r31,176
	ctx.r1.s64 = ctx.r31.s64 + 176;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827516E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x827516F0;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af10
	ctx.lr = 0x827516F8;
	__savefpr_22(ctx, base);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r16,0
	ctx.r16.s64 = 0;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// li r19,0
	ctx.r19.s64 = 0;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// beq cr6,0x82751724
	if (ctx.cr6.eq) goto loc_82751724;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x82751c3c
	goto loc_82751C3C;
loc_82751724:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// not r9,r11
	ctx.r9.u64 = ~ctx.r11.u64;
	// lwz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// not r7,r11
	ctx.r7.u64 = ~ctx.r11.u64;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwinm r5,r9,16,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0x1;
	// rlwinm r30,r7,15,31,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 15) & 0x1;
	// lwz r3,104(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 104);
	// rlwinm r29,r11,14,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 14) & 0x1;
	// lwz r4,104(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 104);
	// bl 0x82751228
	ctx.lr = 0x82751750;
	sub_82751228(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// lwz r4,108(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r3,108(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 108);
	// bl 0x82751228
	ctx.lr = 0x8275176C;
	sub_82751228(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r14,r3
	ctx.r14.u64 = ctx.r3.u64;
	// lwz r4,112(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// lwz r3,112(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 112);
	// bl 0x82751228
	ctx.lr = 0x82751788;
	sub_82751228(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x82751c08
	if (ctx.cr6.eq) goto loc_82751C08;
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x82751c08
	if (ctx.cr6.eq) goto loc_82751C08;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82751c08
	if (ctx.cr6.eq) goto loc_82751C08;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,4095
	ctx.r10.s64 = 268369920;
	// li r17,-1
	ctx.r17.s64 = -1;
	// ori r30,r10,65535
	ctx.r30.u64 = ctx.r10.u64 | 65535;
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x827517cc
	if (!ctx.cr6.gt) goto loc_827517CC;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
loc_827517CC:
	// bl 0x825dfbe0
	ctx.lr = 0x827517D0;
	sub_825DFBE0(ctx, base);
	// mr r16,r3
	ctx.r16.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82751c08
	if (ctx.cr6.eq) goto loc_82751C08;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x827517f8
	if (!ctx.cr6.gt) goto loc_827517F8;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
loc_827517F8:
	// bl 0x825dfbe0
	ctx.lr = 0x827517FC;
	sub_825DFBE0(ctx, base);
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82751c08
	if (ctx.cr6.eq) goto loc_82751C08;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r18,0
	ctx.r18.s64 = 0;
	// lwz r8,104(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 104);
	// lwz r7,112(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r8,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// mulli r8,r8,48
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(48));
	// add r29,r10,r3
	ctx.r29.u64 = ctx.r10.u64 + ctx.r3.u64;
	// add r28,r9,r3
	ctx.r28.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r27,r8,r3
	ctx.r27.u64 = ctx.r8.u64 + ctx.r3.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// ble cr6,0x82751c00
	if (!ctx.cr6.gt) goto loc_82751C00;
	// addi r26,r25,8
	ctx.r26.s64 = ctx.r25.s64 + 8;
loc_82751844:
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// li r20,0
	ctx.r20.s64 = 0;
	// mr r21,r17
	ctx.r21.u64 = ctx.r17.u64;
	// mr r22,r17
	ctx.r22.u64 = ctx.r17.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82751bec
	if (!ctx.cr6.gt) goto loc_82751BEC;
	// addi r25,r14,8
	ctx.r25.s64 = ctx.r14.s64 + 8;
loc_82751860:
	// lwz r23,-8(r25)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r25.u32 + -8);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplw cr6,r23,r21
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r21.u32, ctx.xer);
	// beq cr6,0x827518e0
	if (ctx.cr6.eq) goto loc_827518E0;
	// cmplw cr6,r23,r22
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r22.u32, ctx.xer);
	// beq cr6,0x827518c0
	if (ctx.cr6.eq) goto loc_827518C0;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwz r5,-8(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + -8);
	// mr r21,r23
	ctx.r21.u64 = ctx.r23.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8275189C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwz r5,0(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827518BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x827518e0
	goto loc_827518E0;
loc_827518C0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// mr r21,r22
	ctx.r21.u64 = ctx.r22.u64;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// mr r22,r17
	ctx.r22.u64 = ctx.r17.u64;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
loc_827518E0:
	// lwz r23,0(r25)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// cmplw cr6,r23,r22
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r22.u32, ctx.xer);
	// beq cr6,0x82751930
	if (ctx.cr6.eq) goto loc_82751930;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwz r5,-8(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + -8);
	// mr r22,r23
	ctx.r22.u64 = ctx.r23.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82751910;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwz r5,0(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82751930;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82751930:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82751bb0
	if (!ctx.cr6.gt) goto loc_82751BB0;
	// addi r8,r15,-12
	ctx.r8.s64 = ctx.r15.s64 + -12;
	// mr r9,r16
	ctx.r9.u64 = ctx.r16.u64;
loc_82751948:
	// lwz r11,20(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 20);
	// lfs f13,24(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,12(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lfs f12,16(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f11,4(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f10,-4(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// add r7,r11,r27
	ctx.r7.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lfs f9,4(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// add r6,r10,r27
	ctx.r6.u64 = ctx.r10.u64 + ctx.r27.u64;
	// lfsu f0,16(r8)
	ea = 16 + ctx.r8.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r8.u32 = ea;
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// lfsx f8,r11,r27
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	ctx.f8.f64 = double(temp.f32);
	// lfsx f7,r10,r27
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r27.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f8,f8,f13
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// lfs f5,8(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f7,f7,f12
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// lfs f2,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f5,f5,f13
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// lfs f31,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f2,f2,f12
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f12.f64));
	// lfs f28,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f28.f64 = double(temp.f32);
	// fmuls f31,f31,f13
	ctx.f31.f64 = double(float(ctx.f31.f64 * ctx.f13.f64));
	// lfs f6,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f28,f28,f12
	ctx.f28.f64 = double(float(ctx.f28.f64 * ctx.f12.f64));
	// lfs f4,12(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f6,f6,f13
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// lfs f3,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f4,f4,f13
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// lfs f1,12(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f3,f3,f12
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// lfs f30,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f1,f1,f12
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// lfs f29,12(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f30,f30,f13
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// lfs f27,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f27.f64 = double(temp.f32);
	// fmuls f29,f29,f13
	ctx.f29.f64 = double(float(ctx.f29.f64 * ctx.f13.f64));
	// lfs f26,12(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f26.f64 = double(temp.f32);
	// fmuls f27,f27,f12
	ctx.f27.f64 = double(float(ctx.f27.f64 * ctx.f12.f64));
	// lfsx f25,r11,r28
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	ctx.f25.f64 = double(temp.f32);
	// fmuls f26,f26,f12
	ctx.f26.f64 = double(float(ctx.f26.f64 * ctx.f12.f64));
	// lfsx f24,r10,r28
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r28.u32);
	ctx.f24.f64 = double(temp.f32);
	// fmuls f25,f25,f13
	ctx.f25.f64 = double(float(ctx.f25.f64 * ctx.f13.f64));
	// fmuls f24,f24,f12
	ctx.f24.f64 = double(float(ctx.f24.f64 * ctx.f12.f64));
	// add r7,r11,r29
	ctx.r7.u64 = ctx.r11.u64 + ctx.r29.u64;
	// fadds f5,f2,f5
	ctx.f5.f64 = double(float(ctx.f2.f64 + ctx.f5.f64));
	// add r6,r10,r29
	ctx.r6.u64 = ctx.r10.u64 + ctx.r29.u64;
	// fadds f2,f28,f31
	ctx.f2.f64 = double(float(ctx.f28.f64 + ctx.f31.f64));
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// fadds f6,f3,f6
	ctx.f6.f64 = double(float(ctx.f3.f64 + ctx.f6.f64));
	// add r4,r10,r30
	ctx.r4.u64 = ctx.r10.u64 + ctx.r30.u64;
	// fadds f4,f1,f4
	ctx.f4.f64 = double(float(ctx.f1.f64 + ctx.f4.f64));
	// fadds f8,f7,f8
	ctx.f8.f64 = double(float(ctx.f7.f64 + ctx.f8.f64));
	// lfsx f7,r11,r29
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfs f3,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f7,f7,f13
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// fadds f31,f27,f30
	ctx.f31.f64 = double(float(ctx.f27.f64 + ctx.f30.f64));
	// lfs f1,8(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// fadds f29,f26,f29
	ctx.f29.f64 = double(float(ctx.f26.f64 + ctx.f29.f64));
	// lfs f30,12(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f3,f3,f13
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fadds f28,f24,f25
	ctx.f28.f64 = double(float(ctx.f24.f64 + ctx.f25.f64));
	// fmuls f5,f5,f11
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f11.f64));
	// fmuls f2,f2,f10
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// fmuls f6,f6,f11
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fmuls f4,f4,f11
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// fmuls f8,f8,f11
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f31,f31,f10
	ctx.f31.f64 = double(float(ctx.f31.f64 * ctx.f10.f64));
	// fmuls f29,f29,f10
	ctx.f29.f64 = double(float(ctx.f29.f64 * ctx.f10.f64));
	// fmuls f28,f28,f10
	ctx.f28.f64 = double(float(ctx.f28.f64 * ctx.f10.f64));
	// fadds f6,f2,f6
	ctx.f6.f64 = double(float(ctx.f2.f64 + ctx.f6.f64));
	// fadds f5,f31,f5
	ctx.f5.f64 = double(float(ctx.f31.f64 + ctx.f5.f64));
	// fadds f4,f29,f4
	ctx.f4.f64 = double(float(ctx.f29.f64 + ctx.f4.f64));
	// fadds f8,f28,f8
	ctx.f8.f64 = double(float(ctx.f28.f64 + ctx.f8.f64));
	// fmuls f6,f6,f9
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f9.f64));
	// fmuls f5,f5,f9
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f9.f64));
	// fmuls f4,f4,f9
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f9.f64));
	// fmuls f9,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// lfsx f8,r10,r29
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f31,f30,f13
	ctx.f31.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// lfs f30,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// lfs f29,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f8,f8,f12
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// lfs f28,12(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f28.f64 = double(temp.f32);
	// fmuls f30,f30,f12
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f12.f64));
	// fmuls f29,f29,f12
	ctx.f29.f64 = double(float(ctx.f29.f64 * ctx.f12.f64));
	// lfs f27,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f27.f64 = double(temp.f32);
	// fmuls f2,f1,f13
	ctx.f2.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// lfsx f1,r11,r30
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f12,f28,f12
	ctx.f12.f64 = double(float(ctx.f28.f64 * ctx.f12.f64));
	// lfs f28,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f28.f64 = double(temp.f32);
	// lfs f26,12(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f26.f64 = double(temp.f32);
	// fmuls f1,f13,f1
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// lfsx f25,r10,r30
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	ctx.f25.f64 = double(temp.f32);
	// fmuls f27,f27,f13
	ctx.f27.f64 = double(float(ctx.f27.f64 * ctx.f13.f64));
	// fmuls f28,f28,f13
	ctx.f28.f64 = double(float(ctx.f28.f64 * ctx.f13.f64));
	// lfs f24,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f24.f64 = double(temp.f32);
	// fmuls f13,f26,f13
	ctx.f13.f64 = double(float(ctx.f26.f64 * ctx.f13.f64));
	// lfs f26,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f26.f64 = double(temp.f32);
	// fmuls f25,f0,f25
	ctx.f25.f64 = double(float(ctx.f0.f64 * ctx.f25.f64));
	// lfs f23,12(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f23.f64 = double(temp.f32);
	// fmuls f24,f24,f0
	ctx.f24.f64 = double(float(ctx.f24.f64 * ctx.f0.f64));
	// lfs f22,-4(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -4);
	ctx.f22.f64 = double(temp.f32);
	// fmuls f26,f26,f0
	ctx.f26.f64 = double(float(ctx.f26.f64 * ctx.f0.f64));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f23,f0
	ctx.f0.f64 = double(float(ctx.f23.f64 * ctx.f0.f64));
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// fadds f8,f8,f7
	ctx.f8.f64 = double(float(ctx.f8.f64 + ctx.f7.f64));
	// fadds f7,f30,f3
	ctx.f7.f64 = double(float(ctx.f30.f64 + ctx.f3.f64));
	// fadds f3,f29,f2
	ctx.f3.f64 = double(float(ctx.f29.f64 + ctx.f2.f64));
	// fadds f12,f12,f31
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f31.f64));
	// fadds f2,f25,f1
	ctx.f2.f64 = double(float(ctx.f25.f64 + ctx.f1.f64));
	// fadds f1,f24,f27
	ctx.f1.f64 = double(float(ctx.f24.f64 + ctx.f27.f64));
	// fadds f31,f26,f28
	ctx.f31.f64 = double(float(ctx.f26.f64 + ctx.f28.f64));
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fmuls f13,f8,f11
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f8,f7,f11
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fmuls f7,f3,f11
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmuls f11,f2,f10
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// fmuls f3,f1,f10
	ctx.f3.f64 = double(float(ctx.f1.f64 * ctx.f10.f64));
	// fmuls f2,f31,f10
	ctx.f2.f64 = double(float(ctx.f31.f64 * ctx.f10.f64));
	// fmuls f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// fadds f11,f3,f8
	ctx.f11.f64 = double(float(ctx.f3.f64 + ctx.f8.f64));
	// fadds f10,f2,f7
	ctx.f10.f64 = double(float(ctx.f2.f64 + ctx.f7.f64));
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// fmuls f13,f13,f22
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f22.f64));
	// fmuls f12,f11,f22
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f22.f64));
	// fmuls f11,f10,f22
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f22.f64));
	// fmuls f0,f0,f22
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f22.f64));
	// fadds f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f9.f64));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fadds f13,f12,f6
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f6.f64));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fadds f13,f11,f5
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f5.f64));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fadds f0,f0,f4
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f4.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r7,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// stw r6,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r6.u32);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82751948
	if (ctx.cr6.lt) goto loc_82751948;
loc_82751BB0:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82751BD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r20,r20,1
	ctx.r20.s64 = ctx.r20.s64 + 1;
	// addi r25,r25,16
	ctx.r25.s64 = ctx.r25.s64 + 16;
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// cmplw cr6,r20,r10
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82751860
	if (ctx.cr6.lt) goto loc_82751860;
	// lwz r25,80(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82751BEC:
	// lwz r10,112(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r26,r26,16
	ctx.r26.s64 = ctx.r26.s64 + 16;
	// cmplw cr6,r18,r10
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82751844
	if (ctx.cr6.lt) goto loc_82751844;
loc_82751C00:
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x82751c10
	goto loc_82751C10;
loc_82751C08:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
loc_82751C10:
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x825ac978
	ctx.lr = 0x82751C18;
	sub_825AC978(ctx, base);
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// bl 0x825ac978
	ctx.lr = 0x82751C20;
	sub_825AC978(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x825ac978
	ctx.lr = 0x82751C28;
	sub_825AC978(ctx, base);
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x825ac978
	ctx.lr = 0x82751C30;
	sub_825AC978(ctx, base);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x825ac978
	ctx.lr = 0x82751C38;
	sub_825AC978(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82751C3C:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af5c
	ctx.lr = 0x82751C48;
	__restfpr_22(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82773758) {
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
	// beq 0x827737a0
	if (ctx.cr0.eq) goto loc_827737A0;
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
	// beq cr6,0x827737dc
	if (ctx.cr6.eq) goto loc_827737DC;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8277379C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x827737e0
	goto loc_827737E0;
loc_827737A0:
	// lwz r11,100(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827737ec
	if (ctx.cr6.eq) goto loc_827737EC;
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
	// beq cr6,0x827737dc
	if (ctx.cr6.eq) goto loc_827737DC;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827737D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x827737e0
	goto loc_827737E0;
loc_827737DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827737E0:
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// subfe r3,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x827737f0
	goto loc_827737F0;
loc_827737EC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827737F0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827772D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x827772D8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r26,r4,240
	ctx.r26.s64 = ctx.r4.s64 + 240;
loc_827772EC:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x82777304
	if (ctx.cr6.eq) goto loc_82777304;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r11,-20
	ctx.r11.s64 = ctx.r11.s64 + -20;
	// bne 0x82777308
	if (!ctx.cr0.eq) goto loc_82777308;
loc_82777304:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82777308:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827773c0
	if (ctx.cr6.eq) goto loc_827773C0;
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwinm. r9,r10,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8277732c
	if (!ctx.cr0.eq) goto loc_8277732C;
	// rlwinm. r9,r10,0,1,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8277732c
	if (!ctx.cr0.eq) goto loc_8277732C;
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
loc_8277732C:
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r27,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r27.u32);
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
loc_82777344:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r30
	ea = ctx.r30.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwcx. r9,0,r30
	ea = ctx.r30.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82777344
	if (!ctx.cr0.eq) goto loc_82777344;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8277737C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_82777380:
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
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r30
	ea = ctx.r30.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82777380
	if (!ctx.cr0.eq) goto loc_82777380;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827773b8
	if (!ctx.cr6.eq) goto loc_827773B8;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827773B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827773B8:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x827772ec
	if (ctx.cr6.eq) goto loc_827772EC;
loc_827773C0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82781058) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x82781060;
	__savegprlr_21(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r22,0
	ctx.r22.s64 = 0;
	// lis r11,4096
	ctx.r11.s64 = 268435456;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// stw r22,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r22.u32);
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// stw r22,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r22.u32);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// mr r21,r22
	ctx.r21.u64 = ctx.r22.u64;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x827810ac
	if (!ctx.cr6.gt) goto loc_827810AC;
loc_827810A0:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4102
	ctx.r30.u64 = ctx.r30.u64 | 4102;
	// b 0x82781480
	goto loc_82781480;
loc_827810AC:
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827810a0
	if (ctx.cr6.gt) goto loc_827810A0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82775ab0
	ctx.lr = 0x827810BC;
	sub_82775AB0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82781470
	if (ctx.cr0.lt) goto loc_82781470;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lwz r6,340(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 340);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x8277ec88
	ctx.lr = 0x827810D8;
	sub_8277EC88(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x827810ec
	if (!ctx.cr0.eq) goto loc_827810EC;
loc_827810E0:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x8278140c
	goto loc_8278140C;
loc_827810EC:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r22,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r22.u32);
	// beq cr6,0x82781138
	if (ctx.cr6.eq) goto loc_82781138;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r3,258
	ctx.r3.s64 = 258;
	// bl 0x82778158
	ctx.lr = 0x82781108;
	sub_82778158(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r3.u32);
	// beq 0x827810e0
	if (ctx.cr0.eq) goto loc_827810E0;
loc_82781114:
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
	// bne 0x82781114
	if (!ctx.cr0.eq) goto loc_82781114;
	// lwz r11,184(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
loc_82781138:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82781180
	if (ctx.cr6.eq) goto loc_82781180;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r3,257
	ctx.r3.s64 = 257;
	// bl 0x82778158
	ctx.lr = 0x82781150;
	sub_82778158(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r3.u32);
	// beq 0x827810e0
	if (ctx.cr0.eq) goto loc_827810E0;
loc_8278115C:
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
	// bne 0x8278115c
	if (!ctx.cr0.eq) goto loc_8278115C;
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// stw r11,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
loc_82781180:
	// addic r11,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// stw r31,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r31.u32);
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// ori r28,r10,14
	ctx.r28.u64 = ctx.r10.u64 | 14;
	// and. r30,r11,r28
	ctx.r30.u64 = ctx.r11.u64 & ctx.r28.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8278140c
	if (ctx.cr0.lt) goto loc_8278140C;
	// addi r27,r31,168
	ctx.r27.s64 = ctx.r31.s64 + 168;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x827889c0
	ctx.lr = 0x827811B0;
	sub_827889C0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8278140c
	if (ctx.cr0.lt) goto loc_8278140C;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x8278122c
	if (!ctx.cr6.eq) goto loc_8278122C;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x827889c8
	ctx.lr = 0x827811CC;
	sub_827889C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8278140c
	if (ctx.cr0.lt) goto loc_8278140C;
	// addi r30,r31,108
	ctx.r30.s64 = ctx.r31.s64 + 108;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x827811E0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// li r6,256
	ctx.r6.s64 = 256;
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r10,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r10.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r22,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r22.u32);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// bl 0x82786528
	ctx.lr = 0x82781210;
	sub_82786528(ctx, base);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// oris r11,r11,20480
	ctx.r11.u64 = ctx.r11.u64 | 1342177280;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// bl 0x827805e8
	ctx.lr = 0x82781224;
	sub_827805E8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x827814c8
	goto loc_827814C8;
loc_8278122C:
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82775d70
	ctx.lr = 0x8278123C;
	sub_82775D70(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8278140c
	if (!ctx.cr0.eq) goto loc_8278140C;
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lhz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 84);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// sth r11,84(r1)
	REX_STORE_U16(ctx.r1.u32 + 84, ctx.r11.u16);
	// bl 0x82784a90
	ctx.lr = 0x82781268;
	sub_82784A90(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x82781278
	if (!ctx.cr0.eq) goto loc_82781278;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// b 0x82781358
	goto loc_82781358;
loc_82781278:
	// addi r28,r31,108
	ctx.r28.s64 = ctx.r31.s64 + 108;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b44
	ctx.lr = 0x82781284;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,256
	ctx.r10.s64 = 256;
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
	// mr r21,r11
	ctx.r21.u64 = ctx.r11.u64;
	// sth r10,97(r1)
	REX_STORE_U16(ctx.r1.u32 + 97, ctx.r10.u16);
	// lhz r11,352(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 352);
	// sth r11,99(r1)
	REX_STORE_U16(ctx.r1.u32 + 99, ctx.r11.u16);
	// lwz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// stb r11,101(r1)
	REX_STORE_U8(ctx.r1.u32 + 101, ctx.r11.u8);
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// ble cr6,0x827812c4
	if (!ctx.cr6.gt) goto loc_827812C4;
	// li r11,128
	ctx.r11.s64 = 128;
	// b 0x827812c8
	goto loc_827812C8;
loc_827812C4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_827812C8:
	// stb r11,102(r1)
	REX_STORE_U8(ctx.r1.u32 + 102, ctx.r11.u8);
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827812e4
	if (ctx.cr6.eq) goto loc_827812E4;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,103(r1)
	REX_STORE_U32(ctx.r1.u32 + 103, ctx.r11.u32);
	// b 0x827812e8
	goto loc_827812E8;
loc_827812E4:
	// stw r22,103(r1)
	REX_STORE_U32(ctx.r1.u32 + 103, ctx.r22.u32);
loc_827812E8:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// li r6,11
	ctx.r6.s64 = 11;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x827889d0
	ctx.lr = 0x82781308;
	sub_827889D0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82781358
	if (ctx.cr0.lt) goto loc_82781358;
loc_82781310:
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
	// bne 0x82781310
	if (!ctx.cr0.eq) goto loc_82781310;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,72(r29)
	REX_STORE_U32(ctx.r29.u32 + 72, ctx.r11.u32);
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8278148c
	if (ctx.cr6.eq) goto loc_8278148C;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82776368
	ctx.lr = 0x82781350;
	sub_82776368(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8278148c
	if (ctx.cr0.eq) goto loc_8278148C;
loc_82781358:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8278140c
	if (ctx.cr6.eq) goto loc_8278140C;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827813e0
	if (ctx.cr6.eq) goto loc_827813E0;
loc_8278136C:
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
	// bne 0x8278136c
	if (!ctx.cr0.eq) goto loc_8278136C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82781398
	if (!ctx.cr6.eq) goto loc_82781398;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82784b48
	ctx.lr = 0x82781398;
	sub_82784B48(ctx, base);
loc_82781398:
	// stw r22,72(r29)
	REX_STORE_U32(ctx.r29.u32 + 72, ctx.r22.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82788a80
	ctx.lr = 0x827813A4;
	sub_82788A80(ctx, base);
	// stw r22,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r22.u32);
	// lwz r4,192(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x827813e0
	if (ctx.cr6.eq) goto loc_827813E0;
loc_827813B4:
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
	// bne 0x827813b4
	if (!ctx.cr0.eq) goto loc_827813B4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827813e0
	if (!ctx.cr6.eq) goto loc_827813E0;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x827813E0;
	sub_82772060(ctx, base);
loc_827813E0:
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
	// bne 0x827813e0
	if (!ctx.cr0.eq) goto loc_827813E0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8278140c
	if (!ctx.cr6.eq) goto loc_8278140C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82784b48
	ctx.lr = 0x8278140C;
	sub_82784B48(ctx, base);
loc_8278140C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82781470
	if (ctx.cr6.eq) goto loc_82781470;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// bne cr6,0x82781424
	if (!ctx.cr6.eq) goto loc_82781424;
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// bl 0x82855b44
	ctx.lr = 0x82781424;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_82781424:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// bl 0x82855b34
	ctx.lr = 0x82781438;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r3,168(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8278144c
	if (ctx.cr6.eq) goto loc_8278144C;
	// bl 0x82788a80
	ctx.lr = 0x82781448;
	sub_82788A80(ctx, base);
	// stw r22,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r22.u32);
loc_8278144C:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8278145c
	if (ctx.cr6.eq) goto loc_8278145C;
	// stw r22,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r22.u32);
loc_8278145C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82779998
	ctx.lr = 0x82781464;
	sub_82779998(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82772060
	ctx.lr = 0x82781470;
	sub_82772060(ctx, base);
loc_82781470:
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82781480
	if (ctx.cr6.eq) goto loc_82781480;
	// bl 0x82775930
	ctx.lr = 0x82781480;
	sub_82775930(ctx, base);
loc_82781480:
	// lwz r11,348(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 348);
	// stw r22,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r22.u32);
	// b 0x827814dc
	goto loc_827814DC;
loc_8278148C:
	// lwz r9,196(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// addi r10,r31,208
	ctx.r10.s64 = ctx.r31.s64 + 208;
	// addi r11,r29,4
	ctx.r11.s64 = ctx.r29.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r9.u32);
	// stw r10,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r10.u32);
	// lwz r10,212(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// stw r10,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r10.u32);
	// lwz r10,212(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// oris r11,r11,12288
	ctx.r11.u64 = ctx.r11.u64 | 805306368;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
loc_827814C8:
	// bl 0x82855b34
	ctx.lr = 0x827814CC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r11,348(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 348);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_827814DC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8279D500) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8279D508;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r3,232
	ctx.r29.s64 = ctx.r3.s64 + 232;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// bl 0x82855b44
	ctx.lr = 0x8279D524;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8279ca18
	ctx.lr = 0x8279D530;
	sub_8279CA18(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8279d544
	if (!ctx.cr0.eq) goto loc_8279D544;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,87
	ctx.r31.u64 = ctx.r31.u64 | 87;
	// b 0x8279d550
	goto loc_8279D550;
loc_8279D544:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x827a0950
	ctx.lr = 0x8279D54C;
	sub_827A0950(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8279D550:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x8279D558;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A0150) {
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
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// addi r3,r11,120
	ctx.r3.s64 = ctx.r11.s64 + 120;
	// bl 0x827a5780
	ctx.lr = 0x827A0168;
	sub_827A5780(ctx, base);
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// addi r3,r11,320
	ctx.r3.s64 = ctx.r11.s64 + 320;
	// bl 0x827a5798
	ctx.lr = 0x827A0174;
	sub_827A5798(ctx, base);
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// addi r3,r11,144
	ctx.r3.s64 = ctx.r11.s64 + 144;
	// bl 0x827a57b0
	ctx.lr = 0x827A0180;
	sub_827A57B0(ctx, base);
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// addi r3,r11,192
	ctx.r3.s64 = ctx.r11.s64 + 192;
	// bl 0x827a57c8
	ctx.lr = 0x827A018C;
	sub_827A57C8(ctx, base);
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// addi r3,r11,-29504
	ctx.r3.s64 = ctx.r11.s64 + -29504;
	// bl 0x827a57e0
	ctx.lr = 0x827A0198;
	sub_827A57E0(ctx, base);
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// addi r3,r11,-29728
	ctx.r3.s64 = ctx.r11.s64 + -29728;
	// bl 0x827a57f8
	ctx.lr = 0x827A01A4;
	sub_827A57F8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827A2930) {
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
	// beq cr6,0x827a298c
	if (ctx.cr6.eq) goto loc_827A298C;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827a2970
	if (ctx.cr6.eq) goto loc_827A2970;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x8263b710
	ctx.lr = 0x827A296C;
	sub_8263B710(ctx, base);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_827A2970:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x827a20d0
	ctx.lr = 0x827A2978;
	sub_827A20D0(ctx, base);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r4,r4,32787
	ctx.r4.u64 = ctx.r4.u64 | 32787;
	// bl 0x8263b710
	ctx.lr = 0x827A298C;
	sub_8263B710(ctx, base);
loc_827A298C:
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

DEFINE_REX_FUNC(sub_827A7578) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x827A7580;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8273af20
	ctx.lr = 0x827A7588;
	__savefpr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r28,r31,16
	ctx.r28.s64 = ctx.r31.s64 + 16;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f29,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f29.f64 = double(temp.f32);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lfs f28,36(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f28.f64 = double(temp.f32);
	// li r5,161
	ctx.r5.s64 = 161;
	// lfs f27,5864(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5864);
	ctx.f27.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lfs f26,10796(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10796);
	ctx.f26.f64 = double(temp.f32);
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// lfsx f31,r8,r31
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	ctx.f31.f64 = double(temp.f32);
	// li r27,0
	ctx.r27.s64 = 0;
	// lfsx f30,r8,r28
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r28.u32);
	ctx.f30.f64 = double(temp.f32);
	// addi r25,r11,-150
	ctx.r25.s64 = ctx.r11.s64 + -150;
	// bl 0x827a8338
	ctx.lr = 0x827A75E8;
	sub_827A8338(ctx, base);
	// li r10,80
	ctx.r10.s64 = 80;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r11,0
	ctx.r11.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lfs f11,-21192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21192);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,-21196(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -21196);
	ctx.f12.f64 = double(temp.f32);
loc_827A7604:
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f31,f12
	ctx.f13.f64 = double(float(ctx.f31.f64 * ctx.f12.f64));
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f9,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f30,f12
	ctx.f8.f64 = double(float(ctx.f30.f64 * ctx.f12.f64));
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r11,r25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r25.s32, ctx.xer);
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r30,r9,r10
	ctx.r30.u64 = ctx.r10.u64 - ctx.r9.u64;
	// fmadds f31,f0,f10,f13
	ctx.f31.f64 = double(float(std::fma(ctx.f0.f64, ctx.f10.f64, ctx.f13.f64)));
	// fmadds f30,f9,f10,f8
	ctx.f30.f64 = double(float(std::fma(ctx.f9.f64, ctx.f10.f64, ctx.f8.f64)));
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r10,r31
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f10,r10,r28
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r28.u32);
	ctx.f10.f64 = double(temp.f32);
	// stfsx f31,r10,r31
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, temp.u32);
	// stfsx f30,r10,r28
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r28.u32, temp.u32);
	// fmuls f9,f28,f31
	ctx.f9.f64 = double(float(ctx.f28.f64 * ctx.f31.f64));
	// fadds f8,f29,f31
	ctx.f8.f64 = double(float(ctx.f29.f64 + ctx.f31.f64));
	// fadds f7,f28,f30
	ctx.f7.f64 = double(float(ctx.f28.f64 + ctx.f30.f64));
	// fmuls f0,f29,f31
	ctx.f0.f64 = double(float(ctx.f29.f64 * ctx.f31.f64));
	// fmsubs f9,f29,f30,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f29.f64, ctx.f30.f64, -ctx.f9.f64)));
	// fsubs f29,f8,f13
	ctx.f29.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsubs f28,f7,f10
	ctx.f28.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// fabs f13,f9
	ctx.f13.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// blt cr6,0x827a769c
	if (ctx.cr6.lt) goto loc_827A769C;
	// fmuls f10,f13,f27
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f27.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f10,f0,f26
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f26.f64));
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x827a769c
	if (!ctx.cr6.gt) goto loc_827A769C;
	// fmr f27,f0
	ctx.f27.f64 = ctx.f0.f64;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// fmr f26,f13
	ctx.f26.f64 = ctx.f13.f64;
loc_827A769C:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// bdnz 0x827a7604
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A7604;
	// srawi r11,r24,1
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r24.s32 >> 1;
	// stfs f29,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stfs f28,36(r31)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// stw r27,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r27.u32);
	// stw r30,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// cmpwi cr6,r27,80
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 80, ctx.xer);
	// subf r11,r11,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r11.u64;
	// ble cr6,0x827a7728
	if (!ctx.cr6.gt) goto loc_827A7728;
	// subfic r10,r27,160
	ctx.xer.ca = ctx.r27.u32 <= 160;
	ctx.r10.u64 = static_cast<uint64_t>(160) - ctx.r27.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// frsp f11,f0
	ctx.f11.f64 = double(float(ctx.f0.f64));
	// lfs f0,-21200(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,7996(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7996);
	ctx.f13.f64 = double(temp.f32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r3,92(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r3,40
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 40, ctx.xer);
	// ble cr6,0x827a7770
	if (!ctx.cr6.gt) goto loc_827A7770;
	// li r3,40
	ctx.r3.s64 = 40;
	// b 0x827a7770
	goto loc_827A7770;
loc_827A7728:
	// mullw r11,r11,r27
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f12,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lfs f0,-21200(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -21200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,7996(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7996);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// neg r3,r11
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// cmpwi cr6,r3,-40
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -40, ctx.xer);
	// bge cr6,0x827a7770
	if (!ctx.cr6.lt) goto loc_827A7770;
	// li r3,-40
	ctx.r3.s64 = -40;
loc_827A7770:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8273af6c
	ctx.lr = 0x827A777C;
	__restfpr_26(ctx, base);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827B11A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8548(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8548, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1DD8) {
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
	// lfs f0,23288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8248);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8180(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2C70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7748(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7748);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7744(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3A70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7332(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B46F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6968(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6968, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B53F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6588(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6588, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6170) {
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
	// lfs f0,24072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6184(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6184, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7198) {
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
	// lfs f0,24248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5772(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5772);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5700(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5700, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8638) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-5124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5124);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5120(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5120, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9400) {
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
	// lfs f12,-4780(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4780);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4716(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4716, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA398) {
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
	// lfs f0,24840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4364(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4364);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4264(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB438) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-3752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC228) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3392);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3328(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD508) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2836(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2836);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2776(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2776, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BE5E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25932);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2288(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BF3C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1884);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1880(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0280) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C12B0) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1008(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1008);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-944(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C24E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-436(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -436);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-432(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C34A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,36(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 36, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C43A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,476(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 476);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,480(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5120) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,892(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5F30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1300(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1300);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1304(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1304, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6DD8) {
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
	// lfs f0,28120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1660(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1660);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1760(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1760, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8140) {
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
	// lfs f0,28512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2252(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2252);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2360(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9458) {
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
	// lfs f0,28704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2804(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2804);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2916(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CA7E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,3480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3484(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3484, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB5E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,3912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3916(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CC360) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,4308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4308);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4312(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD270) {
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
	// lfs f0,29352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4668(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4668);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4752(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CE5B0) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5224(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5224);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5312(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CF8A0) {
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
	// lfs f0,29736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5776(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5776);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5864(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5864, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0B70) {
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
	// lfs f0,29928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6336(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6336);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1E48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,6960(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6960);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,6964(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 6964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2838) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,7248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7252(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7252, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D35F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,7652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D46D8) {
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
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8028(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8028);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8144(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8144, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5998) {
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
	// lfs f0,30696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8584(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8584);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8692(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6BC8) {
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
	// lfs f12,9112(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9112);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9224(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9224, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7E98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,9664(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9664);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9772(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9772, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8D58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10200(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D9B18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DABE8) {
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
	// lfs f0,31560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10980(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10980);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11092(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DBE00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,11616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11616);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,11620(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 11620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DC750) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,31816
	ctx.r9.s64 = ctx.r11.s64 + 31816;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11892(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DDB80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,12500(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 12500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE3E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,12748(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12748);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DF398) {
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
	// lfs f12,13164(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13164);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13212(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0588) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E15D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-32760
	ctx.r9.s64 = ctx.r11.s64 + -32760;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-32760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,14228(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 14228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E26D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32484);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14736(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14736, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E37C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E47E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15668(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15668);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15672(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15672, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5938) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,16152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16152);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,16156(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 16156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6308) {
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
	// lfs f0,-30648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16336(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16336);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16452(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16452, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7838) {
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
	// lfs f0,-27480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16936(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16936);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17024(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8A68) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r8,17536
	ctx.r6.s64 = ctx.r8.s64 + 17536;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r5,97
	ctx.r5.s64 = 97;
	// lwz r11,17536(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 17536);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwimi r11,r7,1,24,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r11,17536(r8)
	REX_STORE_U32(ctx.r8.u32 + 17536, ctx.r11.u32);
	// stb r10,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r10.u8);
	// lwz r11,17536(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 17536);
	// rlwimi r11,r5,16,8,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF0000) | (ctx.r11.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r11,17536(r8)
	REX_STORE_U32(ctx.r8.u32 + 17536, ctx.r11.u32);
	// stb r9,17536(r8)
	REX_STORE_U8(ctx.r8.u32 + 17536, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA248) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-23656
	ctx.r9.s64 = ctx.r11.s64 + -23656;
	// lfs f0,-23656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18212(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 18212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB140) {
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
	// lfs f0,-22792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18520(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18520);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18636(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EC5A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-22040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22040);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,19200(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 19200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ED078) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,19492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19496(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EDFC8) {
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
	// lfs f0,-20776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19780(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19780);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19912(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19912, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF218) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,20412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20412);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20416(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F02F8) {
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
	// lfs f0,-19080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20824(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20824);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20884(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F14D8) {
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
	// lfs f0,-18360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,21272(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 21272);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,21380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 21380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2A10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21964(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21964);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21968(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21968, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F3A20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-16820(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16820);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22420(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22420, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F4C48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23116(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23116, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F59C8) {
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
	// lfs f0,-15896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23508(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23508);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,23564(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6C10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24068);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24072(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7DE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24524(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24524);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24528(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8EE0) {
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
	// lfs f0,-11960(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11960);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24920(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24920);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25004(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA070) {
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
	// lfs f13,25444(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 25444);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25496(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB0D8) {
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
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25852(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25852);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25968(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25968, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC478) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FD278) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26948(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26948);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26952(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FE110) {
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
	// lfs f0,-9176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27288(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27288);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27376(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FF4F0) {
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
	// lfs f0,-8984(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8984);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27852(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27852);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27956(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828007E0) {
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
	// lfs f0,-8792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28404(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28404);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28508(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801AA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-8600
	ctx.r9.s64 = ctx.r11.s64 + -8600;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-8600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29056(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802E60) {
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
	// lfs f12,29516(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29516);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29632(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29632, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804128) {
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
	// lfs f12,30068(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30068);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30180(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828054D8) {
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
	// lfs f0,-8024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30644(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30644);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30752(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82806868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7764(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7764);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31320(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807648) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31724(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31724);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31728(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808510) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32080(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32080);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32160(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32160, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809968) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7320(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,32644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 32644);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32348(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B690) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-31984(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -31984);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31932(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31932, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280C748) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-31436(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31436);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31432(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280D868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-30932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30932);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-30928(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -30928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E060) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30700);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30696(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F138) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-6304
	ctx.r9.s64 = ctx.r11.s64 + -6304;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-6304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30200(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810370) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29664(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29664, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811248) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29320(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29320);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29220(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812680) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28636(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28636);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28632(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28632, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813490) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28316(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28316);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27756(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27756, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815398) {
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
	// lfs f0,-4744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-27356(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -27356);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-27240(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -27240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828167A8) {
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
	// lfs f0,-4440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-26748(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -26748);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-26644(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -26644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817BA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26052(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26052);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26048(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818B70) {
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
	// lfs f0,-3816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25656(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25656);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25568(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25568, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819FD8) {
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
	// lfs f0,-24968(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -24968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1520(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1520);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24964(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281B008) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281C030) {
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
	// lfs f0,-3032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24100(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24100);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23996(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281D240) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-23448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23444(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23444, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281E370) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-22940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22940);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-22936(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -22936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281ED80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-22744(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -22744);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22636(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281FCE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-22192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82820E10) {
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
	// lfs f0,-1848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21764(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21764);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21680(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21680, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821FF8) {
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
	// lfs f0,-1640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21212(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21212);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21156(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828232A0) {
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
	// lfs f0,-1440(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,3504(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3504);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-20612(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82824620) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20024(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828254A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19596(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828264E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-600
	ctx.r9.s64 = ctx.r11.s64 + -600;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19100(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19100, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828279A0) {
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
	// lfs f0,-376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18604(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18604);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18496(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828DB8) {
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
	// lfs f0,-152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18020(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18020);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17904(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17904, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282A070) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-17360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17360);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-17356(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -17356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282AA48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-17072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17068(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282B8D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-16632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16632);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16628(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -16628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C590) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,568
	ctx.r9.s64 = ctx.r11.s64 + 568;
	// lfs f0,568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16256(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -16256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D3C0) {
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
	// lfs f0,712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15956(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15956);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15844(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E830) {
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
	// lfs f0,952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15360(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15360);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15240(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282FC30) {
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
	// lfs f0,1160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14656(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830F08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14092(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831D58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,1704
	ctx.r9.s64 = ctx.r11.s64 + 1704;
	// lfs f0,1704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13660(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -13660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832D38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,1912
	ctx.r9.s64 = ctx.r11.s64 + 1912;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,1912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13184(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13184, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828341E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-12576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12576);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-12572(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -12572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834C48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12268);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-12276(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12276);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,-12264(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835BB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-11808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11804(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11804, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836C38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-11428(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -11428);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11324(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11324, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837AC8) {
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
	// lfs f0,2872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11004(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11004);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10892(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838F20) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10412(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10412);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10300(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283A378) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-9708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283B200) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-9280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9276(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9276, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283C290) {
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
	// lfs f0,3712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8896(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8896);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8796(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283D6D8) {
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
	// lfs f0,3936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8324(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8324);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8204(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283EB08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283F908) {
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
	// lfs f0,4368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7300);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7200(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840F00) {
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
	// lfs f0,4688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6672(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6672);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6552(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6552, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842160) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,4912
	ctx.r9.s64 = ctx.r11.s64 + 4912;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,4912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6012(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828434D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-5448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5448);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-5444(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5444, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82843ED0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,5272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-5252(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -5252);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5148(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82844D28) {
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
	// lfs f0,5480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4820(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4820);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4716(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4716, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846400) {
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
	// lfs f0,5808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4116(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4116);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4032(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4032, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847618) {
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
	// lfs f0,6032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3552(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3552);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3504(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828488D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6292);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2944(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849AA8) {
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
	// lfs f0,6416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2544(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2544);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2428(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284AEA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284BD20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1420(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1420, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284CD40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,6992
	ctx.r9.s64 = ctx.r11.s64 + 6992;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,6992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-948(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284E160) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-336(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284F000) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,92(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,96(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 96, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284FFA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7880);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,564(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850FB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1060(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851FC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1508);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1512(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853050) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1956(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1956);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2008(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853F98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// addi r8,r9,12520
	ctx.r8.s64 = ctx.r9.s64 + 12520;
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

DEFINE_REX_FUNC(sub_82874130) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82874138;
	__savegprlr_27(ctx, base);
	// li r11,16
	ctx.r11.s64 = 16;
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v7,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// add r6,r3,r4
	ctx.r6.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lvx128 v62,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// vspltish v13,2
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x2)));
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lvx128 v61,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// vperm128 v11,v63,v61,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lvx128 v59,r6,r11
	ea = (ctx.r6.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// lvsl v5,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// vperm128 v10,v62,v59,v5
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// add r5,r9,r4
	ctx.r5.u64 = ctx.r9.u64 + ctx.r4.u64;
	// vmrghb v6,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsrah v12,v1,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vmrglb v4,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// add r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lvx128 v57,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,48
	ctx.r30.s64 = 48;
	// vmrglb v3,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// add r3,r7,r4
	ctx.r3.u64 = ctx.r7.u64 + ctx.r4.u64;
	// vor v11,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v6.u8));
	// vmrghb v10,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v53,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,96
	ctx.r6.s64 = 96;
	// lvsl v7,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r29,144
	ctx.r29.s64 = 144;
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v8,v57,v53,v7
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vsldoi v2,v11,v4,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8), 14));
	// lvx128 v58,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsldoi v31,v10,v3,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8), 14));
	// lvx128 v54,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r10,r11
	ea = (ctx.r10.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,192
	ctx.r28.s64 = 192;
	// lvsl v1,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r27,240
	ctx.r27.s64 = 240;
	// vsubshs v30,v2,v11
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// lvsl v6,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v7,v60,v52,v6
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvx128 v56,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v9,v58,v54,v1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// lvx128 v51,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v5,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r5,288
	ctx.r5.s64 = 288;
	// vaddshs v3,v30,v12
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// lvx128 v55,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r7,r11
	ea = (ctx.r7.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v6,v56,v51,v5
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// lvsl v4,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrglb v2,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v49,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v5,v55,v50,v4
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vsrah v29,v3,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// lvx128 v48,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v1,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrglb v30,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v28,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r4,336
	ctx.r4.s64 = 336;
	// vperm128 v4,v49,v48,v1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// vsubshs v25,v31,v10
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vmrghb v9,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddshs v24,v29,v11
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vmrghb v8,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v7,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v27,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v26,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvx128 v24,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v6,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v5,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v23,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v0,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsldoi v22,v9,v2,2
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8), 14));
	// vsldoi v21,v8,v30,2
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8), 14));
	// vsldoi v20,v7,v28,2
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8), 14));
	// vsldoi v17,v0,v23,2
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v23.u8), 14));
	// vsubshs v16,v22,v9
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vsldoi v19,v6,v27,2
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v27.u8), 14));
	// vsubshs v15,v21,v8
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vsldoi v18,v5,v26,2
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8), 14));
	// vsubshs v14,v20,v7
	simde_mm_store_si128((simde__m128i*)ctx.v14.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v2,v25,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vsubshs v3,v17,v0
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vsubshs v11,v19,v6
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vsubshs v4,v18,v5
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v1,v16,v12
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v31,v15,v12
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v30,v14,v12
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v14.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v29,v11,v12
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v28,v4,v12
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v27,v3,v12
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vsrah v26,v2,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v25,v1,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v24,v31,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v23,v30,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v22,v29,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v21,v28,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v20,v27,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v19,v26,v10
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v18,v25,v9
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vaddshs v17,v24,v8
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v16,v23,v7
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v15,v22,v6
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// stvx128 v19,r31,r30
	ea = (ctx.r31.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v14,v21,v5
	simde_mm_store_si128((simde__m128i*)ctx.v14.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// stvx128 v18,r31,r6
	ea = (ctx.r31.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v0,v20,v0
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// stvx128 v17,r31,r29
	ea = (ctx.r31.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v16,r31,r28
	ea = (ctx.r31.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v15,r31,r27
	ea = (ctx.r31.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v14,r31,r5
	ea = (ctx.r31.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r4
	ea = (ctx.r31.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

