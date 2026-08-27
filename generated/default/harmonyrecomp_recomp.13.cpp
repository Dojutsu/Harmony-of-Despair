#include "harmonyrecomp_funcs.13.h"

DEFINE_REX_FUNC(sub_82210928) {
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
	// lwz r11,-12856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82210948
	if (ctx.cr6.eq) goto loc_82210948;
	// bl 0x82577540
	ctx.lr = 0x82210948;
	sub_82577540(ctx, base);
loc_82210948:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12852(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12852);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221095c
	if (ctx.cr6.eq) goto loc_8221095C;
	// bl 0x8257b7a0
	ctx.lr = 0x8221095C;
	sub_8257B7A0(ctx, base);
loc_8221095C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12848(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12848);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82210970
	if (ctx.cr6.eq) goto loc_82210970;
	// bl 0x8257d5f8
	ctx.lr = 0x82210970;
	sub_8257D5F8(ctx, base);
loc_82210970:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r3,-12860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -12860);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82210984
	if (ctx.cr6.eq) goto loc_82210984;
	// bl 0x8246dcf0
	ctx.lr = 0x82210984;
	sub_8246DCF0(ctx, base);
loc_82210984:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8221C2F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8221C300;
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
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r27,1
	ctx.r27.s64 = 1;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82215e00
	ctx.lr = 0x8221C324;
	sub_82215E00(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8221c334
	if (!ctx.cr0.eq) goto loc_8221C334;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8221c86c
	goto loc_8221C86C;
loc_8221C334:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,60(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// addi r28,r10,13168
	ctx.r28.s64 = ctx.r10.s64 + 13168;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// addi r29,r9,624
	ctx.r29.s64 = ctx.r9.s64 + 624;
	// lfs f31,-700(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -700);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,-932(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -932);
	ctx.f30.f64 = double(temp.f32);
	// blt cr6,0x8221c538
	if (ctx.cr6.lt) goto loc_8221C538;
	// beq cr6,0x8221c3c4
	if (ctx.cr6.eq) goto loc_8221C3C4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8221c5c8
	if (!ctx.cr6.lt) goto loc_8221C5C8;
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// lfs f0,40(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,36(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f12,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,24(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221C3A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f13,64(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// lfs f0,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8221c5c8
	if (ctx.cr6.lt) goto loc_8221C5C8;
	// b 0x8221c5c4
	goto loc_8221C5C4;
loc_8221C3C4:
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,3816(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 3816);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// blt cr6,0x8221c488
	if (ctx.cr6.lt) goto loc_8221C488;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// ld r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 8);
	// lfs f11,1036(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1036);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,200(r11)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r11.u32 + 200);
	// fabs f12,f12
	ctx.f12.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x8221c408
	if (!ctx.cr6.lt) goto loc_8221C408;
	// lfs f0,1208(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1208);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8221c428
	goto loc_8221C428;
loc_8221C408:
	// fsubs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8221c41c
	if (!ctx.cr6.lt) goto loc_8221C41C;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// b 0x8221c428
	goto loc_8221C428;
loc_8221C41C:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x8221c428
	if (!ctx.cr6.gt) goto loc_8221C428;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
loc_8221C428:
	// lfs f11,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f13,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f12,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f10,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fsubs f10,f10,f12
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmadds f13,f11,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f0,f10,f0,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f10.f64, ctx.f0.f64, ctx.f12.f64)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bctrl 
	ctx.lr = 0x8221C468;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// blt cr6,0x8221c480
	if (ctx.cr6.lt) goto loc_8221C480;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
loc_8221C480:
	// stfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// b 0x8221c5c8
	goto loc_8221C5C8;
loc_8221C488:
	// lfs f13,2488(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 2488);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8221c50c
	if (!ctx.cr6.lt) goto loc_8221C50C;
	// lfs f0,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,76(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f13,f12,f0,f13
	ctx.f13.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// lfs f12,24(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,28(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f12,f0,f10
	ctx.f10.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f10.f64)));
	// lfs f9,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,32(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f9,f11,f0,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f9.f64)));
	// lfs f7,36(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f12,f8,f0,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f8.f64, ctx.f0.f64, ctx.f12.f64)));
	// fmadds f0,f7,f0,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f7.f64, ctx.f0.f64, ctx.f11.f64)));
	// stfs f10,16(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// stfs f9,20(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f12,24(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stfs f13,72(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// bgt cr6,0x8221c4f0
	if (ctx.cr6.gt) goto loc_8221C4F0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221C4F0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8221c4fc
	if (!ctx.cr0.eq) goto loc_8221C4FC;
	// stfs f31,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_8221C4FC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8221c524
	if (!ctx.cr6.eq) goto loc_8221C524;
	// li r27,0
	ctx.r27.s64 = 0;
	// b 0x8221c524
	goto loc_8221C524;
loc_8221C50C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221C524;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8221C524:
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,8(r30)
	REX_STORE_U64(ctx.r30.u32 + 8, ctx.r11.u64);
	// b 0x8221c5c8
	goto loc_8221C5C8;
loc_8221C538:
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,76(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f13,f12,f0,f13
	ctx.f13.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// lfs f12,24(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,28(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f12,f0,f10
	ctx.f10.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f10.f64)));
	// lfs f9,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,32(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f9,f11,f0,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f9.f64)));
	// lfs f7,36(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f12,f8,f0,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f8.f64, ctx.f0.f64, ctx.f12.f64)));
	// fmadds f0,f7,f0,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f7.f64, ctx.f0.f64, ctx.f11.f64)));
	// stfs f10,16(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// stfs f9,20(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f12,24(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stfs f13,72(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// bgt cr6,0x8221c594
	if (ctx.cr6.gt) goto loc_8221C594;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221C594:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8221c5a0
	if (!ctx.cr0.eq) goto loc_8221C5A0;
	// stfs f31,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_8221C5A0:
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// lfs f13,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// and r27,r11,r27
	ctx.r27.u64 = ctx.r11.u64 & ctx.r27.u64;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8221c5c8
	if (!ctx.cr6.lt) goto loc_8221C5C8;
loc_8221C5C4:
	// li r27,0
	ctx.r27.s64 = 0;
loc_8221C5C8:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,-12872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12872);
	// stw r10,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r10.u32);
	// beq cr6,0x8221c5f0
	if (ctx.cr6.eq) goto loc_8221C5F0;
	// lfs f12,664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8221c5f4
	goto loc_8221C5F4;
loc_8221C5F0:
	// fmr f12,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f30.f64;
loc_8221C5F4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221c608
	if (ctx.cr6.eq) goto loc_8221C608;
	// lfs f13,736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 736);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,740(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 740);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8221c610
	goto loc_8221C610;
loc_8221C608:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
	// fmr f13,f31
	ctx.f13.f64 = ctx.f31.f64;
loc_8221C610:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,-15432(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15432);
	// beq cr6,0x8221c648
	if (ctx.cr6.eq) goto loc_8221C648;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lfs f11,664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f11.f64 = double(temp.f32);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f10,88(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fdivs f11,f10,f11
	ctx.f11.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// fctidz f11,f11
	ctx.f11.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f11.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
loc_8221C648:
	// fdivs f11,f30,f12
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f30.f64 / ctx.f12.f64));
	// lfs f12,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fneg f10,f0
	ctx.f10.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f0,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f11,f10,f11
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fsubs f10,f13,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// blt cr6,0x8221c6c8
	if (ctx.cr6.lt) goto loc_8221C6C8;
	// extsw r11,r10
	ctx.r11.s64 = ctx.r10.s32;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f10,88(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fadds f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 + ctx.f13.f64));
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x8221c6c8
	if (ctx.cr6.gt) goto loc_8221C6C8;
	// fsubs f0,f11,f12
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lfs f10,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// blt cr6,0x8221c6c8
	if (ctx.cr6.lt) goto loc_8221C6C8;
	// bl 0x82459e00
	ctx.lr = 0x8221C6A4;
	sub_82459E00(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// ble cr6,0x8221c6cc
	if (!ctx.cr6.gt) goto loc_8221C6CC;
loc_8221C6C8:
	// li r27,0
	ctx.r27.s64 = 0;
loc_8221C6CC:
	// lbz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 84);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8221c868
	if (!ctx.cr0.eq) goto loc_8221C868;
	// bl 0x82444358
	ctx.lr = 0x8221C6DC;
	sub_82444358(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8221c868
	if (ctx.cr0.eq) goto loc_8221C868;
	// bl 0x824443c8
	ctx.lr = 0x8221C6E8;
	sub_824443C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8221c868
	if (ctx.cr0.eq) goto loc_8221C868;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82430958
	ctx.lr = 0x8221C6F8;
	sub_82430958(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8221c868
	if (ctx.cr0.eq) goto loc_8221C868;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x824310f8
	ctx.lr = 0x8221C710;
	sub_824310F8(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
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
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8221c74c
	if (!ctx.cr6.lt) goto loc_8221C74C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221C74C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8221c798
	if (ctx.cr0.eq) goto loc_8221C798;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
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
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8221c78c
	if (!ctx.cr6.gt) goto loc_8221C78C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221C78C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne 0x8221c79c
	if (!ctx.cr0.eq) goto loc_8221C79C;
loc_8221C798:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8221C79C:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
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
	// lfs f13,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8221c7d8
	if (!ctx.cr6.lt) goto loc_8221C7D8;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221C7D8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8221c824
	if (ctx.cr0.eq) goto loc_8221C824;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8221c818
	if (!ctx.cr6.gt) goto loc_8221C818;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221C818:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x8221c828
	if (!ctx.cr0.eq) goto loc_8221C828;
loc_8221C824:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221C828:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8221c868
	if (ctx.cr0.eq) goto loc_8221C868;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8221c868
	if (ctx.cr0.eq) goto loc_8221C868;
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222d88
	ctx.lr = 0x8221C848;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8221c868
	if (ctx.cr0.eq) goto loc_8221C868;
	// lfs f13,136(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,1112(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1112);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,136(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// stb r11,84(r31)
	REX_STORE_U8(ctx.r31.u32 + 84, ctx.r11.u8);
loc_8221C868:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_8221C86C:
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

DEFINE_REX_FUNC(sub_82256090) {
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
	// ori r4,r4,62904
	ctx.r4.u64 = ctx.r4.u64 | 62904;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x822560B8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822560c8
	if (ctx.cr0.eq) goto loc_822560C8;
	// bl 0x822557c8
	ctx.lr = 0x822560C4;
	sub_822557C8(ctx, base);
	// b 0x822560cc
	goto loc_822560CC;
loc_822560C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822560CC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8225E460) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8225E468;
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
	// beq 0x8225e4a0
	if (ctx.cr0.eq) goto loc_8225E4A0;
	// lwz r4,0(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// bl 0x8225e380
	ctx.lr = 0x8225E488;
	sub_8225E380(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8225e4a0
	if (!ctx.cr0.eq) goto loc_8225E4A0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,12(r30)
	REX_STORE_U8(ctx.r30.u32 + 12, ctx.r11.u8);
	// stb r11,13(r30)
	REX_STORE_U8(ctx.r30.u32 + 13, ctx.r11.u8);
	// b 0x8225e4c4
	goto loc_8225E4C4;
loc_8225E4A0:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r31,500
	ctx.r7.s64 = ctx.r31.s64 + 500;
	// addi r6,r31,472
	ctx.r6.s64 = ctx.r31.s64 + 472;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82236c80
	ctx.lr = 0x8225E4C4;
	sub_82236C80(ctx, base);
loc_8225E4C4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82260E68) {
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
	// lwz r5,4(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,10000
	ctx.r4.s64 = 10000;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x82260E90;
	sub_825A49B0(ctx, base);
	// li r30,10
	ctx.r30.s64 = 10;
	// divwu r11,r3,r30
	ctx.r11.u64 = uint32_t(ctx.r30.u32 ? ctx.r3.u32 / ctx.r30.u32 : 0);
	// mulli r11,r11,10
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(10));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x82260f40
	if (!ctx.cr6.lt) goto loc_82260F40;
	// li r4,10000
	ctx.r4.s64 = 10000;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x82260EB8;
	sub_825A49B0(ctx, base);
	// divwu r11,r3,r30
	ctx.r11.u64 = uint32_t(ctx.r30.u32 ? ctx.r3.u32 / ctx.r30.u32 : 0);
	// mulli r11,r11,10
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(10));
	// subf. r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82260ed4
	if (!ctx.cr0.eq) goto loc_82260ED4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,6712
	ctx.r3.s64 = ctx.r11.s64 + 6712;
	// b 0x82260f34
	goto loc_82260F34;
loc_82260ED4:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82260ee8
	if (!ctx.cr6.eq) goto loc_82260EE8;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,6724
	ctx.r3.s64 = ctx.r11.s64 + 6724;
	// b 0x82260f34
	goto loc_82260F34;
loc_82260EE8:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82260efc
	if (!ctx.cr6.eq) goto loc_82260EFC;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,6736
	ctx.r3.s64 = ctx.r11.s64 + 6736;
	// b 0x82260f34
	goto loc_82260F34;
loc_82260EFC:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82260f10
	if (!ctx.cr6.eq) goto loc_82260F10;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,6748
	ctx.r3.s64 = ctx.r11.s64 + 6748;
	// b 0x82260f34
	goto loc_82260F34;
loc_82260F10:
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82260f24
	if (!ctx.cr6.eq) goto loc_82260F24;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,6760
	ctx.r3.s64 = ctx.r11.s64 + 6760;
	// b 0x82260f34
	goto loc_82260F34;
loc_82260F24:
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x82260f40
	if (!ctx.cr6.eq) goto loc_82260F40;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,6772
	ctx.r3.s64 = ctx.r11.s64 + 6772;
loc_82260F34:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// bl 0x8257d4d8
	ctx.lr = 0x82260F40;
	sub_8257D4D8(ctx, base);
loc_82260F40:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lfs f0,240(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-2408
	ctx.r11.s64 = ctx.r11.s64 + -2408;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,0(r11)
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

DEFINE_REX_FUNC(sub_8226BE20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x8226BE28;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af14
	ctx.lr = 0x8226BE30;
	__savefpr_23(ctx, base);
	// stwu r1,-2352(r1)
	ea = -2352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addis r24,r3,1
	ctx.r24.s64 = ctx.r3.s64 + 65536;
	// addi r15,r11,15088
	ctx.r15.s64 = ctx.r11.s64 + 15088;
	// addi r24,r24,-3048
	ctx.r24.s64 = ctx.r24.s64 + -3048;
	// lis r11,0
	ctx.r11.s64 = 0;
	// stw r15,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r15.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// ori r10,r11,62500
	ctx.r10.u64 = ctx.r11.u64 | 62500;
	// lfs f30,-2852(r15)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + -2852);
	ctx.f30.f64 = double(temp.f32);
	// lfs f0,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// blt cr6,0x8226bf34
	if (ctx.cr6.lt) goto loc_8226BF34;
	// lbzx r11,r3,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8226bf34
	if (ctx.cr0.eq) goto loc_8226BF34;
	// lwz r11,248(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,148(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BE8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BEA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BEC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r11.u8);
	// stb r11,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r11.u8);
	// stb r11,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r11.u8);
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BEF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
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
	ctx.lr = 0x8226BF10;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,21(r25)
	REX_STORE_U8(ctx.r25.u32 + 21, ctx.r11.u8);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,68(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BF30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8226da88
	goto loc_8226DA88;
loc_8226BF34:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// blt cr6,0x8226c180
	if (ctx.cr6.lt) goto loc_8226C180;
	// lbzx r11,r25,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + ctx.r10.u32);
	// add r30,r25,r10
	ctx.r30.u64 = ctx.r25.u64 + ctx.r10.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8226c180
	if (!ctx.cr0.eq) goto loc_8226C180;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x8226BF54;
	sub_825A43F0(ctx, base);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BF74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r28,r25,1
	ctx.r28.s64 = ctx.r25.s64 + 65536;
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// addi r28,r28,-3032
	ctx.r28.s64 = ctx.r28.s64 + -3032;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,0(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BFA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,148(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BFC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BFDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BFF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r29,255
	ctx.r29.s64 = 255;
	// stb r29,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// stb r29,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r29.u8);
	// stb r29,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r29.u8);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stb r29,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r29.u8);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C028;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C040;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f12,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addis r31,r25,1
	ctx.r31.s64 = ctx.r25.s64 + 65536;
	// lfs f13,-2620(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + -2620);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-16684
	ctx.r11.s64 = ctx.r11.s64 + -16684;
	// addi r31,r31,-3028
	ctx.r31.s64 = ctx.r31.s64 + -3028;
	// lfs f0,-13444(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13444);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfs f0,-712(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + -712);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lha r11,0(r31)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 0));
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f12,f11
	ctx.f12.f64 = double(float(ctx.f11.f64));
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lhz r11,102(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// sth r11,0(r31)
	REX_STORE_U16(ctx.r31.u32 + 0, ctx.r11.u16);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x8226c0b8
	if (ctx.cr6.gt) goto loc_8226C0B8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r11.u8);
	// b 0x8226da88
	goto loc_8226DA88;
loc_8226C0B8:
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r10,r10,2500
	ctx.r10.s64 = ctx.r10.s64 + 2500;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lfs f0,30820(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 30820);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C0E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,248(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// stb r29,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r29.u8);
	// lhz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// stb r29,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// stb r29,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r29.u8);
	// lwz r3,8(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C110;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,148(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C12C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C148;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C160;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C17C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8226da88
	goto loc_8226DA88;
loc_8226C180:
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C198;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,248(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r14,r11,-11120
	ctx.r14.s64 = ctx.r11.s64 + -11120;
	// stw r14,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r14.u32);
	// lwz r3,8(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f0,12724(r14)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + 12724);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C1C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f24,11744(r14)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + 11744);
	ctx.f24.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f0,f24,f30
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f24.f64, -ctx.f30.f64)));
	// addi r16,r11,-16684
	ctx.r16.s64 = ctx.r11.s64 + -16684;
	// lfs f23,8932(r14)
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + 8932);
	ctx.f23.f64 = double(temp.f32);
	// stw r16,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r16.u32);
	// lfs f31,6828(r16)
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 6828);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lhz r11,102(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcmpu cr6,f0,f23
	ctx.cr6.compare(ctx.f0.f64, ctx.f23.f64);
	// bge cr6,0x8226c214
	if (!ctx.cr6.lt) goto loc_8226C214;
	// li r11,32
	ctx.r11.s64 = 32;
loc_8226C214:
	// lwz r10,248(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r17,255
	ctx.r17.s64 = 255;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// stb r17,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r17.u8);
	// stb r17,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r17.u8);
	// stb r17,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r17.u8);
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C244;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C260;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// fmuls f0,f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// stb r17,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r17.u8);
	// stb r17,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r17.u8);
	// stb r17,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r17.u8);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
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
	ctx.lr = 0x8226C2A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// lfs f31,-212(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + -212);
	ctx.f31.f64 = double(temp.f32);
	// lfs f27,-1920(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + -1920);
	ctx.f27.f64 = double(temp.f32);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f29,f0,f31,f27
	ctx.f29.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f27.f64)));
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bctrl 
	ctx.lr = 0x8226C2D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// fsubs f12,f30,f29
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f30.f64 - ctx.f29.f64));
	// lis r30,-32227
	ctx.r30.s64 = -2112028672;
	// addi r31,r11,32720
	ctx.r31.s64 = ctx.r11.s64 + 32720;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r18,r11,-30652
	ctx.r18.s64 = ctx.r11.s64 + -30652;
	// addi r11,r30,2500
	ctx.r11.s64 = ctx.r30.s64 + 2500;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r18,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// addi r4,r1,568
	ctx.r4.s64 = ctx.r1.s64 + 568;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,-17600(r18)
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + -17600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,30820(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30820);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
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
	// lfs f11,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stfs f0,572(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stfs f11,568(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C35C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C378;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,148(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C394;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C3B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226C3DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f0,-13448(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + -13448);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lfs f25,2500(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2500);
	ctx.f25.f64 = double(temp.f32);
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// lvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,-31744
	ctx.r10.s64 = ctx.r10.s64 + -31744;
	// lfs f13,2920(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2920);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// lfs f12,3840(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3840);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r1,464
	ctx.r5.s64 = ctx.r1.s64 + 464;
	// lfs f8,2880(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f8,152(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// li r21,0
	ctx.r21.s64 = 0;
	// stfs f8,148(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f8,144(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f11,2924(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2924);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f11,f11,f25
	ctx.f11.f64 = double(float(ctx.f11.f64 + ctx.f25.f64));
	// stfs f11,188(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f11,184(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// stfs f11,180(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f11,176(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fabs f4,f12
	ctx.f4.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// lfs f10,3844(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3844);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,5244(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5244);
	ctx.f9.f64 = double(temp.f32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f8,156(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// fsubs f10,f10,f9
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
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
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// fadds f0,f4,f13
	ctx.f0.f64 = double(float(ctx.f4.f64 + ctx.f13.f64));
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fabs f29,f10
	ctx.f29.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r19,r9,32256
	ctx.r19.s64 = ctx.r9.s64 + 32256;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stw r19,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r19.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,320(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f9.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f12,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lfs f0,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f10,288(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f10.f64 = double(temp.f32);
	// lfs f26,-2620(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + -2620);
	ctx.f26.f64 = double(temp.f32);
	// stw r10,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, ctx.r10.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f10,192(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lfs f28,1476(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1476);
	ctx.f28.f64 = double(temp.f32);
	// stfs f13,256(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f12,284(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f11,260(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f9,280(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// b 0x8226c518
	goto loc_8226C518;
loc_8226C514:
	// lwz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
loc_8226C518:
	// rlwinm r10,r21,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 3) & 0xFFFFFFF8;
	// li r22,0
	ctx.r22.s64 = 0;
	// mulli r20,r10,160
	ctx.r20.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(160));
	// stw r20,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r20.u32);
	// li r23,0
	ctx.r23.s64 = 0;
	// b 0x8226c534
	goto loc_8226C534;
loc_8226C530:
	// lwz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
loc_8226C534:
	// lwz r26,104(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// add r31,r20,r26
	ctx.r31.u64 = ctx.r20.u64 + ctx.r26.u64;
	// bne cr6,0x8226d1d8
	if (!ctx.cr6.eq) goto loc_8226D1D8;
	// addi r10,r1,1152
	ctx.r10.s64 = ctx.r1.s64 + 1152;
	// lfs f0,120(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1156, temp.u32);
	// addi r9,r1,1408
	ctx.r9.s64 = ctx.r1.s64 + 1408;
	// stfs f0,1164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1164, temp.u32);
	// stfs f0,1160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1160, temp.u32);
	// stfs f0,1152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1152, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,1
	ctx.r10.s64 = 1;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1408(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1408);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f26
	ctx.cr6.compare(ctx.f0.f64, ctx.f26.f64);
	// bgt cr6,0x8226c57c
	if (ctx.cr6.gt) goto loc_8226C57C;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8226C57C:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8226cba0
	if (ctx.cr0.eq) goto loc_8226CBA0;
	// cmplwi cr6,r22,5
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 5, ctx.xer);
	// bge cr6,0x8226c70c
	if (!ctx.cr6.lt) goto loc_8226C70C;
	// addi r28,r11,3840
	ctx.r28.s64 = ctx.r11.s64 + 3840;
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x8226c59c
	goto loc_8226C59C;
loc_8226C598:
	// lwz r26,104(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_8226C59C:
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// bge cr6,0x8226c6c0
	if (!ctx.cr6.lt) goto loc_8226C6C0;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq cr6,0x8226c5d0
	if (ctx.cr6.eq) goto loc_8226C5D0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8226c5d0
	if (!ctx.cr6.eq) goto loc_8226C5D0;
	// add r11,r23,r26
	ctx.r11.u64 = ctx.r23.u64 + ctx.r26.u64;
	// addi r10,r11,-160
	ctx.r10.s64 = ctx.r11.s64 + -160;
	// lfs f0,-120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -120);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfs f0,-116(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// b 0x8226c6fc
	goto loc_8226C6FC;
loc_8226C5D0:
	// mulli r11,r29,40
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// lfs f1,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfsx f0,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r28,r11
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,1308(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1308, temp.u32);
	// add r10,r28,r11
	ctx.r10.u64 = ctx.r28.u64 + ctx.r11.u64;
	// stfs f13,1300(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1300, temp.u32);
	// addi r8,r1,1264
	ctx.r8.s64 = ctx.r1.s64 + 1264;
	// stfs f0,1268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1268, temp.u32);
	// add r30,r31,r11
	ctx.r30.u64 = ctx.r31.u64 + ctx.r11.u64;
	// stfs f0,1276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1276, temp.u32);
	// stfs f0,1272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1272, temp.u32);
	// addi r11,r1,2080
	ctx.r11.s64 = ctx.r1.s64 + 2080;
	// stfs f0,1264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1264, temp.u32);
	// addi r6,r1,1776
	ctx.r6.s64 = ctx.r1.s64 + 1776;
	// lfs f12,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,592
	ctx.r10.s64 = ctx.r1.s64 + 592;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,1296
	ctx.r7.s64 = ctx.r1.s64 + 1296;
	// stfs f0,596(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 596, temp.u32);
	// addi r9,r1,1232
	ctx.r9.s64 = ctx.r1.s64 + 1232;
	// stfs f0,604(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 604, temp.u32);
	// addi r26,r1,2112
	ctx.r26.s64 = ctx.r1.s64 + 2112;
	// stfs f0,592(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 592, temp.u32);
	// addi r27,r1,1456
	ctx.r27.s64 = ctx.r1.s64 + 1456;
	// stfs f0,600(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 600, temp.u32);
	// addi r6,r1,376
	ctx.r6.s64 = ctx.r1.s64 + 376;
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stfs f13,1296(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1296, temp.u32);
	// addi r4,r1,360
	ctx.r4.s64 = ctx.r1.s64 + 360;
	// stfs f12,1236(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1236, temp.u32);
	// addi r3,r1,392
	ctx.r3.s64 = ctx.r1.s64 + 392;
	// stfs f13,1304(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1304, temp.u32);
	// stfs f12,1244(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1244, temp.u32);
	// stfs f12,1240(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1240, temp.u32);
	// stfs f12,1232(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1232, temp.u32);
	// lfs f0,2080(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2080);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,360(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,2112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1776(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1776);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,1456(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1456);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,376(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// stfs f12,364(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// stfs f0,380(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// bl 0x825a5eb8
	ctx.lr = 0x8226C6AC;
	sub_825A5EB8(ctx, base);
	// lfs f0,392(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 392);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,396(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 396);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// b 0x8226c6fc
	goto loc_8226C6FC;
loc_8226C6C0:
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mulli r10,r29,40
	ctx.r10.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// fsubs f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// add r11,r31,r10
	ctx.r11.u64 = ctx.r31.u64 + ctx.r10.u64;
	// add r9,r28,r10
	ctx.r9.u64 = ctx.r28.u64 + ctx.r10.u64;
	// subfic r8,r29,3
	ctx.xer.ca = ctx.r29.u32 <= 3;
	ctx.r8.u64 = static_cast<uint64_t>(3) - ctx.r29.u64;
	// mulli r8,r8,40
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(40));
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fsubs f12,f11,f23
	ctx.f12.f64 = double(float(ctx.f11.f64 - ctx.f23.f64));
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lfsx f0,r8,r31
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
loc_8226C6FC:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x8226c598
	if (ctx.cr6.lt) goto loc_8226C598;
	// b 0x8226d548
	goto loc_8226D548;
loc_8226C70C:
	// cmplwi cr6,r22,7
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 7, ctx.xer);
	// bge cr6,0x8226c8c8
	if (!ctx.cr6.lt) goto loc_8226C8C8;
	// add r11,r23,r11
	ctx.r11.u64 = ctx.r23.u64 + ctx.r11.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r28,r11,2720
	ctx.r28.s64 = ctx.r11.s64 + 2720;
	// b 0x8226c728
	goto loc_8226C728;
loc_8226C724:
	// lwz r26,104(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_8226C728:
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// bge cr6,0x8226c880
	if (!ctx.cr6.lt) goto loc_8226C880;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8226c864
	if (ctx.cr6.eq) goto loc_8226C864;
	// mulli r11,r29,40
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// lvx128 v63,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfsx f0,r28,r11
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,620(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 620, temp.u32);
	// stfs f0,616(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 616, temp.u32);
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stfs f0,612(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 612, temp.u32);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// stfs f0,608(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 608, temp.u32);
	// addi r7,r1,1360
	ctx.r7.s64 = ctx.r1.s64 + 1360;
	// addi r10,r1,1328
	ctx.r10.s64 = ctx.r1.s64 + 1328;
	// addi r15,r1,1520
	ctx.r15.s64 = ctx.r1.s64 + 1520;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,624
	ctx.r9.s64 = ctx.r1.s64 + 624;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,2032
	ctx.r8.s64 = ctx.r1.s64 + 2032;
	// stfs f13,1368(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1368, temp.u32);
	// addi r6,r1,1968
	ctx.r6.s64 = ctx.r1.s64 + 1968;
	// stfs f13,1364(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1364, temp.u32);
	// addi r27,r1,608
	ctx.r27.s64 = ctx.r1.s64 + 608;
	// stfs f0,1336(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1336, temp.u32);
	// stw r6,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stfs f0,1332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1332, temp.u32);
	// addi r16,r1,1808
	ctx.r16.s64 = ctx.r1.s64 + 1808;
	// stfs f0,1328(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1328, temp.u32);
	// addi r26,r1,1488
	ctx.r26.s64 = ctx.r1.s64 + 1488;
	// stfs f0,1340(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1340, temp.u32);
	// addi r14,r1,1280
	ctx.r14.s64 = ctx.r1.s64 + 1280;
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,424
	ctx.r6.s64 = ctx.r1.s64 + 424;
	// stfs f0,632(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 632, temp.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// stfs f13,1360(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1360, temp.u32);
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// stfs f13,1372(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1372, temp.u32);
	// addi r3,r1,440
	ctx.r3.s64 = ctx.r1.s64 + 440;
	// stfs f0,624(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 624, temp.u32);
	// stfs f0,628(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 628, temp.u32);
	// stfs f0,636(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 636, temp.u32);
	// lvx128 v61,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2032(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2032);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1292, temp.u32);
	// stfs f0,1288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1288, temp.u32);
	// stfs f0,1284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1284, temp.u32);
	// stfs f0,1280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1280, temp.u32);
	// lvx128 v62,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,1488(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1488);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1808(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1808);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,1520(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1520);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,1968(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1968);
	ctx.f10.f64 = double(temp.f32);
	// stfs f13,424(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 424, temp.u32);
	// stfs f0,408(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// stfs f12,412(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// stfs f11,428(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 428, temp.u32);
	// stfs f10,192(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// bl 0x825a5eb8
	ctx.lr = 0x8226C844;
	sub_825A5EB8(ctx, base);
	// lfs f0,440(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,444(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 444);
	ctx.f13.f64 = double(temp.f32);
	// lwz r16,84(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r14,112(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r15,116(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// b 0x8226c8b8
	goto loc_8226C8B8;
loc_8226C864:
	// add r11,r23,r26
	ctx.r11.u64 = ctx.r23.u64 + ctx.r26.u64;
	// addi r10,r11,-160
	ctx.r10.s64 = ctx.r11.s64 + -160;
	// lfs f0,-120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -120);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfs f0,-116(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// b 0x8226c8b8
	goto loc_8226C8B8;
loc_8226C880:
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mulli r10,r29,40
	ctx.r10.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// fsubs f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r9,r28,r10
	ctx.r9.u64 = ctx.r28.u64 + ctx.r10.u64;
	// subfic r8,r29,3
	ctx.xer.ca = ctx.r29.u32 <= 3;
	ctx.r8.u64 = static_cast<uint64_t>(3) - ctx.r29.u64;
	// mulli r8,r8,40
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(40));
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lfsx f0,r8,r31
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r10,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, temp.u32);
loc_8226C8B8:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x8226c724
	if (ctx.cr6.lt) goto loc_8226C724;
	// b 0x8226d548
	goto loc_8226D548;
loc_8226C8C8:
	// addi r9,r1,1040
	ctx.r9.s64 = ctx.r1.s64 + 1040;
	// lfs f13,5004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5004);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,1040(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1040, temp.u32);
	// addi r10,r1,672
	ctx.r10.s64 = ctx.r1.s64 + 672;
	// stfs f13,1048(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1048, temp.u32);
	// addi r8,r1,1056
	ctx.r8.s64 = ctx.r1.s64 + 1056;
	// stfs f13,1044(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1044, temp.u32);
	// addi r5,r1,2096
	ctx.r5.s64 = ctx.r1.s64 + 2096;
	// stfs f13,1052(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1052, temp.u32);
	// addi r7,r1,704
	ctx.r7.s64 = ctx.r1.s64 + 704;
	// lfs f0,3244(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3244);
	ctx.f0.f64 = double(temp.f32);
	// stw r5,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// stfs f0,684(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 684, temp.u32);
	// addi r30,r1,1552
	ctx.r30.s64 = ctx.r1.s64 + 1552;
	// stfs f0,680(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 680, temp.u32);
	// addi r29,r1,1840
	ctx.r29.s64 = ctx.r1.s64 + 1840;
	// stfs f0,672(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 672, temp.u32);
	// addi r6,r1,1584
	ctx.r6.s64 = ctx.r1.s64 + 1584;
	// stfs f0,676(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 676, temp.u32);
	// addi r5,r1,488
	ctx.r5.s64 = ctx.r1.s64 + 488;
	// lfs f0,3240(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3240);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,504
	ctx.r4.s64 = ctx.r1.s64 + 504;
	// stfs f0,1064(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1064, temp.u32);
	// addi r3,r1,232
	ctx.r3.s64 = ctx.r1.s64 + 232;
	// stfs f0,1060(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1060, temp.u32);
	// addi r28,r11,3200
	ctx.r28.s64 = ctx.r11.s64 + 3200;
	// stfs f0,1056(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1056, temp.u32);
	// addi r27,r11,4960
	ctx.r27.s64 = ctx.r11.s64 + 4960;
	// stfs f0,1068(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1068, temp.u32);
	// lfs f13,5000(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5000);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,704(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 704, temp.u32);
	// stfs f13,716(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 716, temp.u32);
	// stfs f13,712(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 712, temp.u32);
	// stfs f13,708(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 708, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1552(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1552);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,488(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// lfs f0,1840(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1584(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1584);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2096(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2096);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,492(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// stfs f0,508(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 508, temp.u32);
	// stfs f12,504(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x8226C998;
	sub_82322D08(ctx, base);
	// addi r4,r1,232
	ctx.r4.s64 = ctx.r1.s64 + 232;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// bl 0x8231e0d8
	ctx.lr = 0x8226C9A4;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// std r11,232(r1)
	REX_STORE_U64(ctx.r1.u32 + 232, ctx.r11.u64);
	// lfs f3,236(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 236);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,232(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 232);
	ctx.f2.f64 = double(temp.f32);
	// b 0x8226c9c0
	goto loc_8226C9C0;
loc_8226C9BC:
	// lwz r26,104(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_8226C9C0:
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// bge cr6,0x8226cb58
	if (!ctx.cr6.lt) goto loc_8226CB58;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8226cb3c
	if (ctx.cr6.eq) goto loc_8226CB3C;
	// mulli r11,r29,40
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// stfs f2,1228(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 1228, temp.u32);
	// stfs f2,1224(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 1224, temp.u32);
	// stfs f2,1220(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 1220, temp.u32);
	// stfs f2,1216(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 1216, temp.u32);
	// stfs f4,748(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 748, temp.u32);
	// lfsx f0,r11,r28
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f4,744(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 744, temp.u32);
	// stfs f4,740(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 740, temp.u32);
	// addi r9,r1,768
	ctx.r9.s64 = ctx.r1.s64 + 768;
	// stfs f0,780(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 780, temp.u32);
	// addi r8,r1,736
	ctx.r8.s64 = ctx.r1.s64 + 736;
	// stfs f0,776(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 776, temp.u32);
	// stfs f0,772(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 772, temp.u32);
	// addi r16,r1,800
	ctx.r16.s64 = ctx.r1.s64 + 800;
	// stfs f0,768(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 768, temp.u32);
	// addi r7,r1,1216
	ctx.r7.s64 = ctx.r1.s64 + 1216;
	// stfs f4,736(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 736, temp.u32);
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stfs f3,812(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 812, temp.u32);
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stfs f3,808(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 808, temp.u32);
	// addi r19,r1,1344
	ctx.r19.s64 = ctx.r1.s64 + 1344;
	// lfsx f0,r11,r31
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,2000
	ctx.r11.s64 = ctx.r1.s64 + 2000;
	// stfs f3,804(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 804, temp.u32);
	// addi r18,r1,832
	ctx.r18.s64 = ctx.r1.s64 + 832;
	// lfs f13,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r20,r1,1120
	ctx.r20.s64 = ctx.r1.s64 + 1120;
	// stfs f13,1356(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1356, temp.u32);
	// addi r26,r1,1088
	ctx.r26.s64 = ctx.r1.s64 + 1088;
	// stfs f13,1352(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1352, temp.u32);
	// addi r10,r1,1648
	ctx.r10.s64 = ctx.r1.s64 + 1648;
	// stfs f13,1348(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1348, temp.u32);
	// addi r17,r1,1616
	ctx.r17.s64 = ctx.r1.s64 + 1616;
	// stfs f13,1344(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1344, temp.u32);
	// addi r15,r1,1872
	ctx.r15.s64 = ctx.r1.s64 + 1872;
	// stfs f3,800(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 800, temp.u32);
	// addi r6,r1,536
	ctx.r6.s64 = ctx.r1.s64 + 536;
	// lvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,280
	ctx.r5.s64 = ctx.r1.s64 + 280;
	// lvx128 v11,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,520
	ctx.r4.s64 = ctx.r1.s64 + 520;
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,552
	ctx.r3.s64 = ctx.r1.s64 + 552;
	// stfs f13,844(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 844, temp.u32);
	// stfs f0,1128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1128, temp.u32);
	// stfs f0,1120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1120, temp.u32);
	// stfs f4,1100(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 1100, temp.u32);
	// stfs f4,1096(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 1096, temp.u32);
	// lvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stfs f4,1092(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 1092, temp.u32);
	// stfs f4,1088(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 1088, temp.u32);
	// stfs f13,840(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 840, temp.u32);
	// stfs f13,836(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 836, temp.u32);
	// stfs f13,832(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 832, temp.u32);
	// stfs f0,1132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1132, temp.u32);
	// stfs f0,1124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1124, temp.u32);
	// lfs f1,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v13,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lfs f0,1616(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1616);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,524(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// lfs f13,2000(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2000);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,536(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// stvx128 v0,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1872(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1872);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,540(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// lfs f0,1648(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1648);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,520(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// bl 0x825a5eb8
	ctx.lr = 0x8226CB0C;
	sub_825A5EB8(ctx, base);
	// lfs f0,552(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,556(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 556);
	ctx.f13.f64 = double(temp.f32);
	// lwz r20,88(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r19,120(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// lwz r15,116(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// li r17,255
	ctx.r17.s64 = 255;
	// lwz r14,112(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r16,84(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r18,80(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8226cb90
	goto loc_8226CB90;
loc_8226CB3C:
	// add r11,r23,r26
	ctx.r11.u64 = ctx.r23.u64 + ctx.r26.u64;
	// addi r10,r11,-160
	ctx.r10.s64 = ctx.r11.s64 + -160;
	// lfs f0,-120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -120);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfs f0,-116(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// b 0x8226cb90
	goto loc_8226CB90;
loc_8226CB58:
	// mulli r11,r29,40
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// subfic r9,r29,3
	ctx.xer.ca = ctx.r29.u32 <= 3;
	ctx.r9.u64 = static_cast<uint64_t>(3) - ctx.r29.u64;
	// mulli r9,r9,40
	ctx.r9.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(40));
	// lfs f12,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f13,f12,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, ctx.f0.f64)));
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lfsx f0,r9,r31
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_8226CB90:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x8226c9bc
	if (ctx.cr6.lt) goto loc_8226C9BC;
	// b 0x8226d548
	goto loc_8226D548;
loc_8226CBA0:
	// cmplwi cr6,r22,1
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 1, ctx.xer);
	// bge cr6,0x8226cd24
	if (!ctx.cr6.lt) goto loc_8226CD24;
	// addi r28,r11,3840
	ctx.r28.s64 = ctx.r11.s64 + 3840;
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x8226cbb8
	goto loc_8226CBB8;
loc_8226CBB4:
	// lwz r26,104(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_8226CBB8:
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// bge cr6,0x8226ccd8
	if (!ctx.cr6.lt) goto loc_8226CCD8;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq cr6,0x8226cbec
	if (ctx.cr6.eq) goto loc_8226CBEC;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8226cbec
	if (!ctx.cr6.eq) goto loc_8226CBEC;
	// add r11,r23,r26
	ctx.r11.u64 = ctx.r23.u64 + ctx.r26.u64;
	// addi r10,r11,-160
	ctx.r10.s64 = ctx.r11.s64 + -160;
	// lfs f0,-120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -120);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfs f0,-116(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// b 0x8226cd14
	goto loc_8226CD14;
loc_8226CBEC:
	// mulli r11,r29,40
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// lfs f1,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfsx f0,r28,r11
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,872(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 872, temp.u32);
	// stfs f0,868(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 868, temp.u32);
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stfs f0,864(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 864, temp.u32);
	// stfs f0,876(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 876, temp.u32);
	// addi r10,r1,1248
	ctx.r10.s64 = ctx.r1.s64 + 1248;
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r7,r1,864
	ctx.r7.s64 = ctx.r1.s64 + 864;
	// addi r9,r1,896
	ctx.r9.s64 = ctx.r1.s64 + 896;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,576
	ctx.r8.s64 = ctx.r1.s64 + 576;
	// stfs f0,1260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1260, temp.u32);
	// addi r14,r1,2064
	ctx.r14.s64 = ctx.r1.s64 + 2064;
	// stfs f0,1256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1256, temp.u32);
	// addi r27,r1,1904
	ctx.r27.s64 = ctx.r1.s64 + 1904;
	// stfs f0,1252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1252, temp.u32);
	// addi r26,r1,1712
	ctx.r26.s64 = ctx.r1.s64 + 1712;
	// stfs f0,1248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1248, temp.u32);
	// addi r6,r1,352
	ctx.r6.s64 = ctx.r1.s64 + 352;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,1680
	ctx.r11.s64 = ctx.r1.s64 + 1680;
	// lfs f12,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// stfs f13,908(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 908, temp.u32);
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// stfs f13,904(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 904, temp.u32);
	// addi r3,r1,544
	ctx.r3.s64 = ctx.r1.s64 + 544;
	// stfs f13,900(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 900, temp.u32);
	// stfs f13,896(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 896, temp.u32);
	// stfs f12,576(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 576, temp.u32);
	// stfs f12,588(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 588, temp.u32);
	// stfs f12,584(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 584, temp.u32);
	// stfs f12,580(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 580, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1680(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1680);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,1904(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1904);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1712(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1712);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,2064(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2064);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,340(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f0,336(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// stfs f13,356(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// stfs f11,352(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// bl 0x825a5eb8
	ctx.lr = 0x8226CCC0;
	sub_825A5EB8(ctx, base);
	// lfs f0,544(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,548(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 548);
	ctx.f13.f64 = double(temp.f32);
	// lwz r14,112(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// b 0x8226cd14
	goto loc_8226CD14;
loc_8226CCD8:
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mulli r10,r29,40
	ctx.r10.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// fsubs f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r9,r28,r10
	ctx.r9.u64 = ctx.r28.u64 + ctx.r10.u64;
	// subfic r8,r29,3
	ctx.xer.ca = ctx.r29.u32 <= 3;
	ctx.r8.u64 = static_cast<uint64_t>(3) - ctx.r29.u64;
	// mulli r8,r8,40
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(40));
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fsubs f12,f11,f23
	ctx.f12.f64 = double(float(ctx.f11.f64 - ctx.f23.f64));
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lfsx f0,r8,r31
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r10,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, temp.u32);
loc_8226CD14:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x8226cbb4
	if (ctx.cr6.lt) goto loc_8226CBB4;
	// b 0x8226d548
	goto loc_8226D548;
loc_8226CD24:
	// cmplwi cr6,r22,3
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 3, ctx.xer);
	// bge cr6,0x8226cee0
	if (!ctx.cr6.lt) goto loc_8226CEE0;
	// add r11,r23,r11
	ctx.r11.u64 = ctx.r23.u64 + ctx.r11.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r28,r11,2720
	ctx.r28.s64 = ctx.r11.s64 + 2720;
	// b 0x8226cd40
	goto loc_8226CD40;
loc_8226CD3C:
	// lwz r26,104(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_8226CD40:
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// bge cr6,0x8226ce98
	if (!ctx.cr6.lt) goto loc_8226CE98;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8226ce7c
	if (ctx.cr6.eq) goto loc_8226CE7C;
	// mulli r11,r29,40
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// lvx128 v63,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfsx f0,r11,r28
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,940(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 940, temp.u32);
	// stfs f0,936(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 936, temp.u32);
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stfs f0,932(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 932, temp.u32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stfs f0,928(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 928, temp.u32);
	// addi r10,r1,1312
	ctx.r10.s64 = ctx.r1.s64 + 1312;
	// addi r27,r1,960
	ctx.r27.s64 = ctx.r1.s64 + 960;
	// addi r16,r1,1184
	ctx.r16.s64 = ctx.r1.s64 + 1184;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,928
	ctx.r8.s64 = ctx.r1.s64 + 928;
	// stfs f0,1320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1320, temp.u32);
	// addi r7,r1,1744
	ctx.r7.s64 = ctx.r1.s64 + 1744;
	// stfs f0,1316(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1316, temp.u32);
	// addi r14,r1,1936
	ctx.r14.s64 = ctx.r1.s64 + 1936;
	// stfs f0,1312(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1312, temp.u32);
	// addi r9,r1,1424
	ctx.r9.s64 = ctx.r1.s64 + 1424;
	// stfs f0,1324(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1324, temp.u32);
	// addi r26,r1,992
	ctx.r26.s64 = ctx.r1.s64 + 992;
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,1472
	ctx.r6.s64 = ctx.r1.s64 + 1472;
	// stfs f0,972(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 972, temp.u32);
	// addi r15,r1,1440
	ctx.r15.s64 = ctx.r1.s64 + 1440;
	// stfs f0,968(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 968, temp.u32);
	// stw r6,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// stfs f0,964(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 964, temp.u32);
	// addi r6,r1,368
	ctx.r6.s64 = ctx.r1.s64 + 368;
	// stfs f0,960(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 960, temp.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// stfs f0,1196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1196, temp.u32);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// stfs f0,1192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1192, temp.u32);
	// stfs f0,1184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1184, temp.u32);
	// stfs f0,1188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1188, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1744(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1744);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,368(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// lfs f0,1424(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1424);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1004(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1004, temp.u32);
	// stfs f0,1000(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1000, temp.u32);
	// lvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,996(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 996, temp.u32);
	// stfs f0,992(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 992, temp.u32);
	// lvx128 v62,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,1936(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1936);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,372(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// stfs f0,480(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,1440(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1440);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1472(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1472);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,484(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// bl 0x825a5eb8
	ctx.lr = 0x8226CE5C;
	sub_825A5EB8(ctx, base);
	// lfs f0,384(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,388(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 388);
	ctx.f13.f64 = double(temp.f32);
	// lwz r16,84(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r14,112(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r15,116(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// b 0x8226ced0
	goto loc_8226CED0;
loc_8226CE7C:
	// add r11,r23,r26
	ctx.r11.u64 = ctx.r23.u64 + ctx.r26.u64;
	// addi r10,r11,-160
	ctx.r10.s64 = ctx.r11.s64 + -160;
	// lfs f0,-120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -120);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfs f0,-116(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// b 0x8226ced0
	goto loc_8226CED0;
loc_8226CE98:
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mulli r10,r29,40
	ctx.r10.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// fsubs f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r9,r10,r28
	ctx.r9.u64 = ctx.r10.u64 + ctx.r28.u64;
	// subfic r8,r29,3
	ctx.xer.ca = ctx.r29.u32 <= 3;
	ctx.r8.u64 = static_cast<uint64_t>(3) - ctx.r29.u64;
	// mulli r8,r8,40
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(40));
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lfsx f0,r8,r31
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r10,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, temp.u32);
loc_8226CED0:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x8226cd3c
	if (ctx.cr6.lt) goto loc_8226CD3C;
	// b 0x8226d548
	goto loc_8226D548;
loc_8226CEE0:
	// addi r10,r1,1024
	ctx.r10.s64 = ctx.r1.s64 + 1024;
	// lfs f0,3240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1036(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1036, temp.u32);
	// addi r5,r1,1536
	ctx.r5.s64 = ctx.r1.s64 + 1536;
	// stfs f0,1028(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1028, temp.u32);
	// addi r8,r1,688
	ctx.r8.s64 = ctx.r1.s64 + 688;
	// stfs f0,1032(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1032, temp.u32);
	// stw r5,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// stfs f0,1024(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1024, temp.u32);
	// addi r6,r1,656
	ctx.r6.s64 = ctx.r1.s64 + 656;
	// lfs f0,5000(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5000);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,1504
	ctx.r9.s64 = ctx.r1.s64 + 1504;
	// stfs f0,700(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 700, temp.u32);
	// addi r7,r1,640
	ctx.r7.s64 = ctx.r1.s64 + 640;
	// stfs f0,692(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 692, temp.u32);
	// addi r29,r1,1600
	ctx.r29.s64 = ctx.r1.s64 + 1600;
	// stfs f0,688(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 688, temp.u32);
	// addi r30,r1,1568
	ctx.r30.s64 = ctx.r1.s64 + 1568;
	// stfs f0,696(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 696, temp.u32);
	// addi r5,r1,528
	ctx.r5.s64 = ctx.r1.s64 + 528;
	// lfs f12,3244(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3244);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// stfs f12,668(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 668, temp.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// lfs f13,5004(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5004);
	ctx.f13.f64 = double(temp.f32);
	// addi r27,r11,4960
	ctx.r27.s64 = ctx.r11.s64 + 4960;
	// stfs f13,652(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 652, temp.u32);
	// addi r28,r11,3200
	ctx.r28.s64 = ctx.r11.s64 + 3200;
	// stfs f13,648(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 648, temp.u32);
	// stfs f13,644(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 644, temp.u32);
	// stfs f13,640(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 640, temp.u32);
	// stfs f12,664(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 664, temp.u32);
	// stfs f12,660(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 660, temp.u32);
	// stfs f12,656(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 656, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1504(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1504);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,528(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// lfs f13,1536(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1536);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,400(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// lfs f0,1568(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1600(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1600);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,532(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// stfs f0,404(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x8226CFB0;
	sub_82322D08(ctx, base);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8231e0d8
	ctx.lr = 0x8226CFBC;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// std r11,240(r1)
	REX_STORE_U64(ctx.r1.u32 + 240, ctx.r11.u64);
	// lfs f3,244(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 244);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f2.f64 = double(temp.f32);
	// b 0x8226cfd8
	goto loc_8226CFD8;
loc_8226CFD4:
	// lwz r26,104(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_8226CFD8:
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// bge cr6,0x8226d190
	if (!ctx.cr6.lt) goto loc_8226D190;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8226d174
	if (ctx.cr6.eq) goto loc_8226D174;
	// mulli r11,r29,40
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// stfs f3,732(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 732, temp.u32);
	// stfs f3,728(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 728, temp.u32);
	// stfs f3,724(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 724, temp.u32);
	// stfs f3,720(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 720, temp.u32);
	// stfs f2,764(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 764, temp.u32);
	// lfsx f0,r11,r28
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,828(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 828, temp.u32);
	// stfs f0,824(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 824, temp.u32);
	// addi r10,r22,-3
	ctx.r10.s64 = ctx.r22.s64 + -3;
	// stfs f0,820(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 820, temp.u32);
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stfs f0,816(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 816, temp.u32);
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// stfs f2,760(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 760, temp.u32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stfs f2,756(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 756, temp.u32);
	// std r10,264(r1)
	REX_STORE_U64(ctx.r1.u32 + 264, ctx.r10.u64);
	// addi r10,r1,784
	ctx.r10.s64 = ctx.r1.s64 + 784;
	// addi r8,r1,848
	ctx.r8.s64 = ctx.r1.s64 + 848;
	// stfs f2,752(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 752, temp.u32);
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,880
	ctx.r9.s64 = ctx.r1.s64 + 880;
	// stfs f13,796(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 796, temp.u32);
	// addi r6,r1,1696
	ctx.r6.s64 = ctx.r1.s64 + 1696;
	// stfs f13,792(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 792, temp.u32);
	// addi r18,r1,1664
	ctx.r18.s64 = ctx.r1.s64 + 1664;
	// stfs f13,788(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 788, temp.u32);
	// stw r6,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// stfs f13,784(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 784, temp.u32);
	// addi r26,r1,1632
	ctx.r26.s64 = ctx.r1.s64 + 1632;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,944
	ctx.r7.s64 = ctx.r1.s64 + 944;
	// stfs f13,856(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 856, temp.u32);
	// addi r17,r1,720
	ctx.r17.s64 = ctx.r1.s64 + 720;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r16,r1,912
	ctx.r16.s64 = ctx.r1.s64 + 912;
	// stfs f0,892(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 892, temp.u32);
	// addi r15,r1,752
	ctx.r15.s64 = ctx.r1.s64 + 752;
	// stfs f0,884(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 884, temp.u32);
	// addi r14,r1,816
	ctx.r14.s64 = ctx.r1.s64 + 816;
	// stfs f0,880(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 880, temp.u32);
	// addi r6,r1,416
	ctx.r6.s64 = ctx.r1.s64 + 416;
	// stfs f0,888(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 888, temp.u32);
	// addi r5,r1,280
	ctx.r5.s64 = ctx.r1.s64 + 280;
	// stfs f13,860(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 860, temp.u32);
	// addi r4,r1,496
	ctx.r4.s64 = ctx.r1.s64 + 496;
	// stfs f13,852(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 852, temp.u32);
	// addi r3,r1,560
	ctx.r3.s64 = ctx.r1.s64 + 560;
	// stfs f13,848(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 848, temp.u32);
	// lvx128 v0,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v10,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,264(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 264);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lvx128 v11,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// stvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f0,f4
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f4.f64));
	// lfs f13,1632(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1632);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1664(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1664);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,500(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// stfs f12,496(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,952(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 952, temp.u32);
	// stfs f0,916(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 916, temp.u32);
	// stfs f0,912(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 912, temp.u32);
	// stfs f0,924(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 924, temp.u32);
	// stfs f0,920(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 920, temp.u32);
	// lvx128 v12,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stfs f0,948(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 948, temp.u32);
	// stfs f0,956(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 956, temp.u32);
	// stfs f0,944(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 944, temp.u32);
	// lvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v11,v13,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// addi r11,r1,1728
	ctx.r11.s64 = ctx.r1.s64 + 1728;
	// lfs f0,1696(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1696);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,420(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1728(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1728);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,416(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// bl 0x825a5eb8
	ctx.lr = 0x8226D14C;
	sub_825A5EB8(ctx, base);
	// lfs f0,560(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,564(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 564);
	ctx.f13.f64 = double(temp.f32);
	// lwz r18,80(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r16,84(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r14,112(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// lwz r15,116(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// li r17,255
	ctx.r17.s64 = 255;
	// b 0x8226d1c8
	goto loc_8226D1C8;
loc_8226D174:
	// add r11,r23,r26
	ctx.r11.u64 = ctx.r23.u64 + ctx.r26.u64;
	// addi r10,r11,-160
	ctx.r10.s64 = ctx.r11.s64 + -160;
	// lfs f0,-120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -120);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfs f0,-116(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// b 0x8226d1c8
	goto loc_8226D1C8;
loc_8226D190:
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mulli r10,r29,40
	ctx.r10.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(40));
	// fsubs f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 + ctx.r27.u64;
	// subfic r8,r29,3
	ctx.xer.ca = ctx.r29.u32 <= 3;
	ctx.r8.u64 = static_cast<uint64_t>(3) - ctx.r29.u64;
	// mulli r8,r8,40
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(40));
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lfsx f0,r8,r31
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r10,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, temp.u32);
loc_8226D1C8:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x8226cfd4
	if (ctx.cr6.lt) goto loc_8226CFD4;
	// b 0x8226d548
	goto loc_8226D548;
loc_8226D1D8:
	// cmplwi cr6,r21,4
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 4, ctx.xer);
	// bne cr6,0x8226d484
	if (!ctx.cr6.eq) goto loc_8226D484;
	// lfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,1008
	ctx.r9.s64 = ctx.r1.s64 + 1008;
	// stfs f0,1016(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1016, temp.u32);
	// addi r10,r22,24
	ctx.r10.s64 = ctx.r22.s64 + 24;
	// stfs f0,1008(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1008, temp.u32);
	// add r30,r20,r11
	ctx.r30.u64 = ctx.r20.u64 + ctx.r11.u64;
	// mulli r11,r10,160
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(160));
	// stfs f0,1020(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1020, temp.u32);
	// stfs f0,1012(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1012, temp.u32);
	// lfs f13,80(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r28,r1,1760
	ctx.r28.s64 = ctx.r1.s64 + 1760;
	// addi r8,r1,976
	ctx.r8.s64 = ctx.r1.s64 + 976;
	// stfs f13,988(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 988, temp.u32);
	// stfs f13,984(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 984, temp.u32);
	// addi r27,r1,1792
	ctx.r27.s64 = ctx.r1.s64 + 1792;
	// stfs f13,980(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 980, temp.u32);
	// addi r10,r1,1072
	ctx.r10.s64 = ctx.r1.s64 + 1072;
	// lfs f12,120(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// addi r29,r1,1136
	ctx.r29.s64 = ctx.r1.s64 + 1136;
	// stfs f12,0(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// addi r7,r1,1104
	ctx.r7.s64 = ctx.r1.s64 + 1104;
	// lfs f0,124(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// addi r17,r1,1824
	ctx.r17.s64 = ctx.r1.s64 + 1824;
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// addi r16,r1,1856
	ctx.r16.s64 = ctx.r1.s64 + 1856;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r1,1168
	ctx.r26.s64 = ctx.r1.s64 + 1168;
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r15,r1,1888
	ctx.r15.s64 = ctx.r1.s64 + 1888;
	// stfs f13,976(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 976, temp.u32);
	// addi r14,r1,1920
	ctx.r14.s64 = ctx.r1.s64 + 1920;
	// lfs f0,1760(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1760);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,512
	ctx.r6.s64 = ctx.r1.s64 + 512;
	// stfs f0,436(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// addi r5,r1,448
	ctx.r5.s64 = ctx.r1.s64 + 448;
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,432
	ctx.r4.s64 = ctx.r1.s64 + 432;
	// stfs f0,40(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// addi r3,r1,344
	ctx.r3.s64 = ctx.r1.s64 + 344;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1792(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1792);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,432(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// lfs f0,84(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// lfs f13,84(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,1116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1116, temp.u32);
	// lfs f12,40(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,1084(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1084, temp.u32);
	// stfs f12,1080(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1080, temp.u32);
	// stfs f12,1076(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1076, temp.u32);
	// stfs f12,1072(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1072, temp.u32);
	// lfs f12,80(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,1148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1148, temp.u32);
	// stfs f12,1144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1144, temp.u32);
	// stfs f12,1140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1140, temp.u32);
	// stfs f13,1108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1108, temp.u32);
	// stfs f13,1112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1112, temp.u32);
	// stfs f13,1104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1104, temp.u32);
	// stfs f12,1136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 1136, temp.u32);
	// lfs f0,44(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1180, temp.u32);
	// stfs f0,1176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1176, temp.u32);
	// stfs f0,1172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1172, temp.u32);
	// stfs f0,1168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1168, temp.u32);
	// lfs f1,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1824(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1824);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,1856(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1856);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,1888(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1888);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,1920(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1920);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,516(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// stfs f13,512(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// stfs f12,452(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stfs f11,448(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// bl 0x825a5eb8
	ctx.lr = 0x8226D330;
	sub_825A5EB8(ctx, base);
	// lfs f13,348(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 348);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 84, temp.u32);
	// addi r10,r1,1200
	ctx.r10.s64 = ctx.r1.s64 + 1200;
	// lfs f0,344(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 344);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// stfs f0,80(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// addi r27,r1,1984
	ctx.r27.s64 = ctx.r1.s64 + 1984;
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// addi r29,r1,128
	ctx.r29.s64 = ctx.r1.s64 + 128;
	// addi r26,r1,2016
	ctx.r26.s64 = ctx.r1.s64 + 2016;
	// addi r17,r1,1392
	ctx.r17.s64 = ctx.r1.s64 + 1392;
	// addi r15,r1,1376
	ctx.r15.s64 = ctx.r1.s64 + 1376;
	// addi r11,r1,304
	ctx.r11.s64 = ctx.r1.s64 + 304;
	// addi r28,r1,1952
	ctx.r28.s64 = ctx.r1.s64 + 1952;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// addi r16,r1,2048
	ctx.r16.s64 = ctx.r1.s64 + 2048;
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// addi r5,r1,168
	ctx.r5.s64 = ctx.r1.s64 + 168;
	// addi r4,r1,248
	ctx.r4.s64 = ctx.r1.s64 + 248;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,124(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1212, temp.u32);
	// stfs f0,1208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1208, temp.u32);
	// stfs f0,1204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1204, temp.u32);
	// stfs f0,1200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1200, temp.u32);
	// lfs f0,120(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f0,328(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,324(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
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
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f13,124(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,316(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f13,312(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f13,304(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// stfs f13,308(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,216(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f13,220(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lfs f13,1984(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1984);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,252(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,1392(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1392);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,1376(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1376);
	ctx.f9.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,2048(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2048);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,172(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f0,1952(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,2016(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2016);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,248(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f10,224(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f9,168(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lfs f1,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a5eb8
	ctx.lr = 0x8226D460;
	sub_825A5EB8(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lwz r15,116(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stfs f0,120(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// lwz r14,112(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 124, temp.u32);
	// lwz r16,84(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r17,255
	ctx.r17.s64 = 255;
	// b 0x8226d548
	goto loc_8226D548;
loc_8226D484:
	// rlwinm r11,r21,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 3) & 0xFFFFFFF8;
	// lfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// clrldi r10,r21,32
	ctx.r10.u64 = ctx.r21.u64 & 0xFFFFFFFF;
	// std r10,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r10.u64);
	// add r11,r22,r11
	ctx.r11.u64 = ctx.r22.u64 + ctx.r11.u64;
	// lfs f13,84(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// lfs f11,124(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 124);
	ctx.f11.f64 = double(temp.f32);
	// mulli r11,r11,160
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(160));
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// lfs f10,120(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,0(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfs f10,124(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 124);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,4(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lfs f10,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,40(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// lfs f9,84(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,44(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// lfs f9,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,40(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f8,f30,f9
	ctx.f8.f64 = double(float(ctx.f30.f64 - ctx.f9.f64));
	// fmuls f9,f7,f9
	ctx.f9.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// lfd f10,176(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fmadds f0,f8,f0,f9
	ctx.f0.f64 = double(float(std::fma(ctx.f8.f64, ctx.f0.f64, ctx.f9.f64)));
	// stfs f0,80(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// lfs f8,44(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f10,f10,f28
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f28.f64));
	// lfs f0,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f9,f30,f0
	ctx.f9.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// fnmsubs f8,f10,f29,f8
	ctx.f8.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f29.f64, -ctx.f8.f64)));
	// fmuls f13,f9,f13
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fmadds f0,f8,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f8.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,84(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 84, temp.u32);
	// lfs f0,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f9,f30,f0
	ctx.f9.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmadds f0,f9,f12,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f9.f64, ctx.f12.f64, ctx.f0.f64)));
	// stfs f0,120(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f10,f29,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f29.f64, -ctx.f0.f64)));
	// lfs f13,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f30,f13
	ctx.f12.f64 = double(float(ctx.f30.f64 - ctx.f13.f64));
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,124(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 124, temp.u32);
loc_8226D548:
	// addi r23,r23,160
	ctx.r23.s64 = ctx.r23.s64 + 160;
	// addi r20,r20,160
	ctx.r20.s64 = ctx.r20.s64 + 160;
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// stw r20,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r20.u32);
	// cmplwi cr6,r23,1280
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 1280, ctx.xer);
	// blt cr6,0x8226c530
	if (ctx.cr6.lt) goto loc_8226C530;
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// cmplwi cr6,r21,5
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 5, ctx.xer);
	// blt cr6,0x8226c514
	if (ctx.cr6.lt) goto loc_8226C514;
	// addis r29,r25,1
	ctx.r29.s64 = ctx.r25.s64 + 65536;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r29,r29,-3068
	ctx.r29.s64 = ctx.r29.s64 + -3068;
	// ori r23,r11,62492
	ctx.r23.u64 = ctx.r11.u64 | 62492;
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bge cr6,0x8226d748
	if (!ctx.cr6.lt) goto loc_8226D748;
	// lbzx r11,r25,r23
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + ctx.r23.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8226d748
	if (ctx.cr0.eq) goto loc_8226D748;
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226D5B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,1292
	ctx.r4.s64 = 1292;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8226D5D4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8226d5f4
	if (ctx.cr0.eq) goto loc_8226D5F4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stfs f26,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r17,4(r3)
	REX_STORE_U8(ctx.r3.u32 + 4, ctx.r17.u8);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x8226d5f8
	goto loc_8226D5F8;
loc_8226D5F4:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8226D5F8:
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8226da88
	if (ctx.cr6.eq) goto loc_8226DA88;
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lfs f0,0(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// subfic r11,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r11.u64);
	// lfd f13,176(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f0,f13,f0,f31
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f0.f64, -ctx.f31.f64)));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226D654;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,12
	ctx.r10.s64 = ctx.r31.s64 + 12;
	// stb r9,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r9.u8);
loc_8226D664:
	// li r7,8
	ctx.r7.s64 = 8;
loc_8226D668:
	// lwz r8,104(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// li r9,4
	ctx.r9.s64 = 4;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r8,r8,-40
	ctx.r8.s64 = ctx.r8.s64 + -40;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8226D67C:
	// lfs f13,44(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfsu f0,40(r8)
	ea = 40 + ctx.r8.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r8.u32 = ea;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r5,r1,1376
	ctx.r5.s64 = ctx.r1.s64 + 1376;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r4,r1,1392
	ctx.r4.s64 = ctx.r1.s64 + 1392;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f13,216(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f13,220(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1376(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1376);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,1392(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1392);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r9,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x8226d67c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8226D67C;
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r11,r11,160
	ctx.r11.s64 = ctx.r11.s64 + 160;
	// bne 0x8226d668
	if (!ctx.cr0.eq) goto loc_8226D668;
	// cmplwi cr6,r11,6400
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6400, ctx.xer);
	// blt cr6,0x8226d664
	if (ctx.cr6.lt) goto loc_8226D664;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8226d70c
	if (!ctx.cr6.eq) goto loc_8226D70C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8226d718
	goto loc_8226D718;
loc_8226D70C:
	// lwz r11,12(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
loc_8226D718:
	// lwz r4,8(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// subf r10,r10,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r10.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8226d73c
	if (!ctx.cr6.lt) goto loc_8226D73C;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r31,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r31.u32);
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// b 0x8226d748
	goto loc_8226D748;
loc_8226D73C:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823849b0
	ctx.lr = 0x8226D748;
	sub_823849B0(ctx, base);
loc_8226D748:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,4(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// ori r27,r10,62496
	ctx.r27.u64 = ctx.r10.u64 | 62496;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8226d968
	if (ctx.cr0.eq) goto loc_8226D968;
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// li r26,0
	ctx.r26.s64 = 0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8226d968
	if (ctx.cr0.eq) goto loc_8226D968;
	// addis r30,r25,1
	ctx.r30.s64 = ctx.r25.s64 + 65536;
	// lfs f31,0(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// stb r17,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r17.u8);
	// add r28,r25,r27
	ctx.r28.u64 = ctx.r25.u64 + ctx.r27.u64;
	// stb r17,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r17.u8);
	// addi r30,r30,-3064
	ctx.r30.s64 = ctx.r30.s64 + -3064;
	// stb r17,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r17.u8);
	// li r31,0
	ctx.r31.s64 = 0;
loc_8226D79C:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// clrldi r10,r26,32
	ctx.r10.u64 = ctx.r26.u64 & 0xFFFFFFFF;
	// lwz r9,4(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// std r10,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r10.u64);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,264(r1)
	REX_STORE_U64(ctx.r1.u32 + 264, ctx.r11.u64);
	// lfd f0,176(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfd f13,264(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 264);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f13,f13,f24
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f24.f64));
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fcmpu cr6,f0,f26
	ctx.cr6.compare(ctx.f0.f64, ctx.f26.f64);
	// bge cr6,0x8226d7ec
	if (!ctx.cr6.lt) goto loc_8226D7EC;
	// fmr f0,f26
	ctx.f0.f64 = ctx.f26.f64;
loc_8226D7EC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// fsqrts f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(sqrt(ctx.f0.f64)));
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lbz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.f0.u64);
	// lhz r11,174(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 174);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// std r10,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r10.u64);
	// lfd f0,224(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 224);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcmpu cr6,f0,f23
	ctx.cr6.compare(ctx.f0.f64, ctx.f23.f64);
	// bge cr6,0x8226d83c
	if (!ctx.cr6.lt) goto loc_8226D83C;
	// li r11,32
	ctx.r11.s64 = 32;
loc_8226D83C:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lwz r10,248(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// std r11,248(r1)
	REX_STORE_U64(ctx.r1.u32 + 248, ctx.r11.u64);
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lfd f13,248(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 248);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.f0.u64);
	// lhz r22,174(r1)
	ctx.r22.u64 = REX_LOAD_U16(ctx.r1.u32 + 174);
	// bctrl 
	ctx.lr = 0x8226D888;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwzx r11,r31,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,120(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226D8AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226D8C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// stb r22,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r22.u8);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226D8E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,16
	ctx.r11.s64 = 16;
loc_8226D8F0:
	// li r7,8
	ctx.r7.s64 = 8;
loc_8226D8F4:
	// lwz r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// li r8,4
	ctx.r8.s64 = 4;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,-36
	ctx.r10.s64 = ctx.r10.s64 + -36;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8226D908:
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwzx r8,r31,r8
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lfs f0,-4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,36(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwzx r8,r31,r8
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// lfsx f0,r8,r11
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stfsu f0,40(r10)
	ea = 40 + ctx.r10.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8226d908
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8226D908;
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r9,r9,160
	ctx.r9.s64 = ctx.r9.s64 + 160;
	// bne 0x8226d8f4
	if (!ctx.cr0.eq) goto loc_8226D8F4;
	// cmplwi cr6,r11,1296
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1296, ctx.xer);
	// blt cr6,0x8226d8f0
	if (ctx.cr6.lt) goto loc_8226D8F0;
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8226d79c
	if (ctx.cr6.lt) goto loc_8226D79C;
loc_8226D968:
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// ble cr6,0x8226da78
	if (!ctx.cr6.gt) goto loc_8226DA78;
	// lfs f12,0(r14)
	temp.u32 = REX_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// li r31,32
	ctx.r31.s64 = 32;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8226d9b8
	if (!ctx.cr6.gt) goto loc_8226D9B8;
	// fsubs f11,f30,f0
	ctx.f11.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// lfs f13,0(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r25,r27
	ctx.r11.u64 = ctx.r25.u64 + ctx.r27.u64;
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfsx f13,r25,r27
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r25.u32 + ctx.r27.u32, temp.u32);
	// fcmpu cr6,f13,f26
	ctx.cr6.compare(ctx.f13.f64, ctx.f26.f64);
	// bge cr6,0x8226d9a4
	if (!ctx.cr6.lt) goto loc_8226D9A4;
	// stfs f26,0(r11)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_8226D9A4:
	// fsubs f13,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// fmadds f13,f13,f25,f23
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f25.f64, ctx.f23.f64)));
	// fctidz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.f13.u64);
	// lbz r31,183(r1)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r1.u32 + 183);
loc_8226D9B8:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,272(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// clrlwi r9,r31,24
	ctx.r9.u64 = ctx.r31.u32 & 0xFF;
	// lwz r8,248(r25)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// ori r10,r10,62508
	ctx.r10.u64 = ctx.r10.u64 | 62508;
	// lfd f13,920(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r11.u32 + 920);
	// fsub f12,f0,f13
	ctx.f12.f64 = ctx.f0.f64 - ctx.f13.f64;
	// lfd f0,1480(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 1480);
	// sthx r9,r25,r10
	REX_STORE_U16(ctx.r25.u32 + ctx.r10.u32, ctx.r9.u16);
	// lfd f13,1488(r11)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r11.u32 + 1488);
	// fnmsub f0,f12,f0,f13
	ctx.f0.f64 = -std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// lwz r3,8(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226D9FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// stb r31,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r31.u8);
	// stb r17,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r17.u8);
	// stb r17,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r17.u8);
	// stb r17,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r17.u8);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x8226DA28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,148(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226DA44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226DA60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226DA78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8226DA78:
	// lbzx r11,r25,r23
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + ctx.r23.u32);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stbx r11,r25,r23
	REX_STORE_U8(ctx.r25.u32 + ctx.r23.u32, ctx.r11.u8);
loc_8226DA88:
	// addi r1,r1,2352
	ctx.r1.s64 = ctx.r1.s64 + 2352;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af60
	ctx.lr = 0x8226DA94;
	__restfpr_23(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8236FBF8) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8236fc40
	if (ctx.cr6.eq) goto loc_8236FC40;
loc_8236FC1C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8236FC34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8236fc1c
	if (!ctx.cr6.eq) goto loc_8236FC1C;
loc_8236FC40:
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

DEFINE_REX_FUNC(sub_823708E8) {
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
	// lwz r4,228(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,21912
	ctx.r11.s64 = ctx.r11.s64 + 21912;
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82370928
	if (ctx.cr6.eq) goto loc_82370928;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r3,-12824(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x82370920;
	sub_82599798(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
loc_82370928:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82373be0
	ctx.lr = 0x82370930;
	sub_82373BE0(ctx, base);
	// lwz r3,256(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82370940
	if (ctx.cr6.eq) goto loc_82370940;
	// bl 0x8221bd98
	ctx.lr = 0x82370940;
	sub_8221BD98(ctx, base);
loc_82370940:
	// lwz r3,260(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82370950
	if (ctx.cr6.eq) goto loc_82370950;
	// bl 0x8221bd98
	ctx.lr = 0x82370950;
	sub_8221BD98(ctx, base);
loc_82370950:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4750
	ctx.lr = 0x82370958;
	sub_825A4750(ctx, base);
	// addi r3,r31,10284
	ctx.r3.s64 = ctx.r31.s64 + 10284;
	// bl 0x823edfb8
	ctx.lr = 0x82370960;
	sub_823EDFB8(ctx, base);
	// lwz r3,10284(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10284);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82370970
	if (ctx.cr6.eq) goto loc_82370970;
	// bl 0x825e0378
	ctx.lr = 0x82370970;
	sub_825E0378(ctx, base);
loc_82370970:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,2668
	ctx.r11.s64 = ctx.r11.s64 + 2668;
	// stw r11,10256(r31)
	REX_STORE_U32(ctx.r31.u32 + 10256, ctx.r11.u32);
	// bl 0x8235f568
	ctx.lr = 0x82370984;
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

DEFINE_REX_FUNC(sub_82376EA0) {
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
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82376f28
	if (!ctx.cr6.eq) goto loc_82376F28;
	// bl 0x8235fd60
	ctx.lr = 0x82376EC4;
	sub_8235FD60(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82376f28
	if (!ctx.cr6.eq) goto loc_82376F28;
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
	// bne 0x82376eec
	if (!ctx.cr0.eq) goto loc_82376EEC;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82376ef4
	goto loc_82376EF4;
loc_82376EEC:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82376EF4:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r9.u32);
	// lfs f0,5196(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5196);
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
	ctx.lr = 0x82376F1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,284(r31)
	REX_STORE_U8(ctx.r31.u32 + 284, ctx.r11.u8);
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
loc_82376F28:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82377778
	ctx.lr = 0x82376F30;
	sub_82377778(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82377468
	ctx.lr = 0x82376F38;
	sub_82377468(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82377108
	ctx.lr = 0x82376F40;
	sub_82377108(ctx, base);
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

DEFINE_REX_FUNC(sub_8237A3C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8237A3C8;
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8237b908
	ctx.lr = 0x8237A3DC;
	sub_8237B908(ctx, base);
	// li r9,1000
	ctx.r9.s64 = 1000;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// divwu r9,r3,r9
	ctx.r9.u64 = uint32_t(ctx.r9.u32 ? ctx.r3.u32 / ctx.r9.u32 : 0);
	// addi r29,r10,31580
	ctx.r29.s64 = ctx.r10.s64 + 31580;
	// mulli r10,r9,1000
	ctx.r10.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(1000));
	// lfs f0,25312(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 25312);
	ctx.f0.f64 = double(temp.f32);
	// subf r9,r10,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r10.u64;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// addi r30,r10,12236
	ctx.r30.s64 = ctx.r10.s64 + 12236;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lfs f31,232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8237a42c
	if (!ctx.cr6.lt) goto loc_8237A42C;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
loc_8237A42C:
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f0,108(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 108, temp.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stfs f31,104(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 104, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r9,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r9.u32);
	// sth r10,86(r11)
	REX_STORE_U16(ctx.r11.u32 + 86, ctx.r10.u16);
	// stb r8,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r8.u8);
	// stw r10,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// stw r9,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// bl 0x8237b908
	ctx.lr = 0x8237A458;
	sub_8237B908(ctx, base);
	// clrlwi r11,r3,29
	ctx.r11.u64 = ctx.r3.u32 & 0x7;
	// lis r28,-32227
	ctx.r28.s64 = -2112028672;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r28,-18548
	ctx.r11.s64 = ctx.r28.s64 + -18548;
	// frsp f11,f0
	ctx.f11.f64 = double(float(ctx.f0.f64));
	// lfs f12,-28608(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28608);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,2044(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2044);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f13,f11,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f11.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// stfs f0,40(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 40, temp.u32);
	// stfs f0,44(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 44, temp.u32);
	// bl 0x8237b908
	ctx.lr = 0x8237A498;
	sub_8237B908(ctx, base);
	// li r10,141
	ctx.r10.s64 = 141;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// divwu r8,r3,r10
	ctx.r8.u64 = uint32_t(ctx.r10.u32 ? ctx.r3.u32 / ctx.r10.u32 : 0);
	// lfs f30,-18548(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -18548);
	ctx.f30.f64 = double(temp.f32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// stfs f31,32(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// mulli r8,r8,141
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(141));
	// lfs f0,-29492(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// subf r9,r8,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r8.u64;
	// li r30,5
	ctx.r30.s64 = 5;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r28,r10,1608
	ctx.r28.s64 = ctx.r10.s64 + 1608;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,64(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// beq cr6,0x8237a5c4
	if (ctx.cr6.eq) goto loc_8237A5C4;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8237a5a4
	if (ctx.cr6.eq) goto loc_8237A5A4;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8237a584
	if (ctx.cr6.eq) goto loc_8237A584;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x8237a570
	if (ctx.cr6.eq) goto loc_8237A570;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x8237a5f4
	if (!ctx.cr6.eq) goto loc_8237A5F4;
	// bl 0x8237b908
	ctx.lr = 0x8237A510;
	sub_8237B908(ctx, base);
	// li r11,121
	ctx.r11.s64 = 121;
	// lfs f0,-3168(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -3168);
	ctx.f0.f64 = double(temp.f32);
	// divwu r11,r3,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r3.u32 / ctx.r11.u32 : 0);
	// mulli r11,r11,121
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(121));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,64(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// bl 0x8237b908
	ctx.lr = 0x8237A544;
	sub_8237B908(ctx, base);
	// li r11,19
	ctx.r11.s64 = 19;
	// divwu r11,r3,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r3.u32 / ctx.r11.u32 : 0);
	// mulli r11,r11,19
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(19));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_8237A560:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// b 0x8237a5f0
	goto loc_8237A5F0;
loc_8237A570:
	// bl 0x8237b908
	ctx.lr = 0x8237A574;
	sub_8237B908(ctx, base);
	// clrlwi r11,r3,30
	ctx.r11.u64 = ctx.r3.u32 & 0x3;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x8237a560
	goto loc_8237A560;
loc_8237A584:
	// bl 0x8237b908
	ctx.lr = 0x8237A588;
	sub_8237B908(ctx, base);
	// divwu r11,r3,r30
	ctx.r11.u64 = uint32_t(ctx.r30.u32 ? ctx.r3.u32 / ctx.r30.u32 : 0);
	// mulli r11,r11,5
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(5));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x8237a5e0
	goto loc_8237A5E0;
loc_8237A5A4:
	// bl 0x8237b908
	ctx.lr = 0x8237A5A8;
	sub_8237B908(ctx, base);
	// divwu r11,r3,r30
	ctx.r11.u64 = uint32_t(ctx.r30.u32 ? ctx.r3.u32 / ctx.r30.u32 : 0);
	// mulli r11,r11,5
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(5));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x8237a5e0
	goto loc_8237A5E0;
loc_8237A5C4:
	// bl 0x8237b908
	ctx.lr = 0x8237A5C8;
	sub_8237B908(ctx, base);
	// divwu r11,r3,r30
	ctx.r11.u64 = uint32_t(ctx.r30.u32 ? ctx.r3.u32 / ctx.r30.u32 : 0);
	// mulli r11,r11,5
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(5));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_8237A5E0:
	// fcfid f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f0,1208(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1208);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
loc_8237A5F0:
	// stfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
loc_8237A5F4:
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x8237a648
	if (!ctx.cr6.gt) goto loc_8237A648;
	// lfs f0,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8237a648
	if (ctx.cr6.lt) goto loc_8237A648;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f13,1680(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1680);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x8237a648
	if (ctx.cr6.gt) goto loc_8237A648;
	// bl 0x8237b908
	ctx.lr = 0x8237A628;
	sub_8237B908(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// divwu r11,r3,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r3.u32 / ctx.r11.u32 : 0);
	// mulli r11,r11,9
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(9));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x8237a664
	goto loc_8237A664;
loc_8237A648:
	// bl 0x8237b908
	ctx.lr = 0x8237A64C;
	sub_8237B908(ctx, base);
	// divwu r11,r3,r30
	ctx.r11.u64 = uint32_t(ctx.r30.u32 ? ctx.r3.u32 / ctx.r30.u32 : 0);
	// mulli r11,r11,5
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(5));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_8237A664:
	// fcfid f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82388F68) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,25000
	ctx.r3.s64 = ctx.r11.s64 + 25000;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82389328) {
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
	// lwz r11,164(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238934C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fb40
	ctx.lr = 0x82389354;
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

DEFINE_REX_FUNC(sub_8238A5E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8238A5F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,364
	ctx.r4.s64 = 364;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8238A618;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8238a678
	if (ctx.cr0.eq) goto loc_8238A678;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82389040
	ctx.lr = 0x8238A634;
	sub_82389040(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r9,r11,25888
	ctx.r9.s64 = ctx.r11.s64 + 25888;
	// addi r11,r31,328
	ctx.r11.s64 = ctx.r31.s64 + 328;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r10,-27424
	ctx.r10.s64 = ctx.r10.s64 + -27424;
loc_8238A658:
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// stwu r9,16(r11)
	ea = 16 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8238a658
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238A658;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x8238a67c
	goto loc_8238A67C;
loc_8238A678:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8238A67C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8238CA48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8238CA50;
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
	// li r4,380
	ctx.r4.s64 = 380;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8238CA78;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8238ca94
	if (ctx.cr0.eq) goto loc_8238CA94;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8238caa0
	ctx.lr = 0x8238CA90;
	sub_8238CAA0(ctx, base);
	// b 0x8238ca98
	goto loc_8238CA98;
loc_8238CA94:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8238CA98:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8238EB18) {
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
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8238eb80
	if (ctx.cr6.lt) goto loc_8238EB80;
	// beq cr6,0x8238eb4c
	if (ctx.cr6.eq) goto loc_8238EB4C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8238ec0c
	if (!ctx.cr6.lt) goto loc_8238EC0C;
	// bl 0x8238f1b0
	ctx.lr = 0x8238EB48;
	sub_8238F1B0(ctx, base);
	// b 0x8238ec0c
	goto loc_8238EC0C;
loc_8238EB4C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238EB60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8238ec0c
	if (!ctx.cr0.eq) goto loc_8238EC0C;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,2
	ctx.r10.s64 = 2;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stw r10,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r10.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// b 0x8238ec0c
	goto loc_8238EC0C;
loc_8238EB80:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fd60
	ctx.lr = 0x8238EB88;
	sub_8235FD60(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8238ec0c
	if (!ctx.cr6.eq) goto loc_8238EC0C;
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
	// bne 0x8238ebb0
	if (!ctx.cr0.eq) goto loc_8238EBB0;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8238ebb8
	goto loc_8238EBB8;
loc_8238EBB0:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8238EBB8:
	// li r10,3
	ctx.r10.s64 = 3;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stw r10,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r10.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lhz r8,6(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,9224(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9224);
	ctx.f13.f64 = double(temp.f32);
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfs f0,-8644(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
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
	ctx.lr = 0x8238EC04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
loc_8238EC0C:
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

DEFINE_REX_FUNC(sub_82394650) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,28204
	ctx.r3.s64 = ctx.r11.s64 + 28204;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82394A50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82394A58;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r6,396(r3)
	REX_STORE_U32(ctx.r3.u32 + 396, ctx.r6.u32);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r7,392(r3)
	REX_STORE_U32(ctx.r3.u32 + 392, ctx.r7.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r10,240(r3)
	REX_STORE_U32(ctx.r3.u32 + 240, ctx.r10.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r10,4(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r9,240(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 240);
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// stw r11,244(r3)
	REX_STORE_U32(ctx.r3.u32 + 244, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// stw r11,252(r3)
	REX_STORE_U32(ctx.r3.u32 + 252, ctx.r11.u32);
	// lwz r11,12(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stw r11,256(r3)
	REX_STORE_U32(ctx.r3.u32 + 256, ctx.r11.u32);
	// bne cr6,0x82394bc0
	if (!ctx.cr6.eq) goto loc_82394BC0;
	// extsw r11,r4
	ctx.r11.s64 = ctx.r4.s32;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// frsp f31,f13
	ctx.f31.f64 = double(float(ctx.f13.f64));
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// extsw r10,r5
	ctx.r10.s64 = ctx.r5.s32;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
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
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,232(r31)
	REX_STORE_U64(ctx.r31.u32 + 232, ctx.r11.u64);
	// bl 0x82363d90
	ctx.lr = 0x82394B40;
	sub_82363D90(ctx, base);
	// cmpw cr6,r3,r30
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r30.s32, ctx.xer);
	// bge cr6,0x82394b4c
	if (!ctx.cr6.lt) goto loc_82394B4C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82394B4C:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// stfs f31,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// li r7,0
	ctx.r7.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
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
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,356(r31)
	REX_STORE_U64(ctx.r31.u32 + 356, ctx.r11.u64);
	// b 0x82394c54
	goto loc_82394C54;
loc_82394BC0:
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82363d90
	ctx.lr = 0x82394BD0;
	sub_82363D90(ctx, base);
	// extsw r11,r29
	ctx.r11.s64 = ctx.r29.s32;
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r7,255
	ctx.r7.s64 = 255;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,232(r31)
	REX_STORE_U64(ctx.r31.u32 + 232, ctx.r11.u64);
loc_82394C54:
	// lwz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// stw r7,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r7.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82394c70
	if (ctx.cr6.eq) goto loc_82394C70;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// li r10,4
	ctx.r10.s64 = 4;
	// bne cr6,0x82394c74
	if (!ctx.cr6.eq) goto loc_82394C74;
loc_82394C70:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82394C74:
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r29,26
	ctx.r9.s64 = ctx.r29.s64 + 26;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r29,-26
	ctx.r8.s64 = ctx.r29.s64 + -26;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r10,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r10.u32);
	// addi r10,r3,-32
	ctx.r10.s64 = ctx.r3.s64 + -32;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r5,-32227
	ctx.r5.s64 = -2112028672;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r5,r5,21300
	ctx.r5.s64 = ctx.r5.s64 + 21300;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,96
	ctx.r30.s64 = ctx.r1.s64 + 96;
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f11,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lbzx r11,r4,r5
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r5.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r11,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r11.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
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
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,292(r31)
	REX_STORE_U64(ctx.r31.u32 + 292, ctx.r11.u64);
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
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
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,284(r31)
	REX_STORE_U64(ctx.r31.u32 + 284, ctx.r11.u64);
	// bne cr6,0x82394df8
	if (!ctx.cr6.eq) goto loc_82394DF8;
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,232(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// lfs f13,236(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 236);
	ctx.f13.f64 = double(temp.f32);
	// cntlzw r9,r11
	ctx.r9.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// lwz r11,-13068(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -13068);
	// rlwinm r6,r9,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82394de4
	if (ctx.cr6.eq) goto loc_82394DE4;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// li r8,0
	ctx.r8.s64 = 0;
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// addi r3,r11,4024
	ctx.r3.s64 = ctx.r11.s64 + 4024;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8223c688
	ctx.lr = 0x82394DE0;
	sub_8223C688(ctx, base);
	// b 0x82394de8
	goto loc_82394DE8;
loc_82394DE4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82394DE8:
	// lwz r11,344(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 344);
	// cmpwi cr6,r11,500
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 500, ctx.xer);
	// bge cr6,0x82394df8
	if (!ctx.cr6.lt) goto loc_82394DF8;
	// stw r3,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r3.u32);
loc_82394DF8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823B6CE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mulli r10,r4,144
	ctx.r10.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(144));
	// lwz r11,-12824(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12824);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r10,142(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 142);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r4,r11,17
	ctx.r4.s64 = ctx.r11.s64 + 17;
	// bl 0x8235ead8
	ctx.lr = 0x823B6D20;
	sub_8235EAD8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823b6dd0
	ctx.lr = 0x823B6D28;
	sub_823B6DD0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8235ec48
	ctx.lr = 0x823B6D3C;
	sub_8235EC48(ctx, base);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8235f0f0
	ctx.lr = 0x823B6D50;
	sub_8235F0F0(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235f0f0
	ctx.lr = 0x823B6D64;
	sub_8235F0F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8235ec48
	ctx.lr = 0x823B6D74;
	sub_8235EC48(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x823b6d88
	if (!ctx.cr6.lt) goto loc_823B6D88;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
loc_823B6D88:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-13024(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13024);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823b6da8
	if (ctx.cr6.eq) goto loc_823B6DA8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825a4160
	ctx.lr = 0x823B6DA0;
	sub_825A4160(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x823b9028
	ctx.lr = 0x823B6DA8;
	sub_823B9028(ctx, base);
loc_823B6DA8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235ec48
	ctx.lr = 0x823B6DB8;
	sub_8235EC48(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823B9A38) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lbz r9,25(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 25);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x823b9a58
	if (!ctx.cr0.eq) goto loc_823B9A58;
	// stw r4,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
loc_823B9A58:
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x823b9a78
	if (!ctx.cr6.eq) goto loc_823B9A78;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// b 0x823b9a94
	goto loc_823B9A94;
loc_823B9A78:
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x823b9a90
	if (!ctx.cr6.eq) goto loc_823B9A90;
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// b 0x823b9a94
	goto loc_823B9A94;
loc_823B9A90:
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_823B9A94:
	// stw r4,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823BB800) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r10,140(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r4.u32);
	// lwz r9,148(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// lbz r8,38(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 38);
	// rotlwi r10,r8,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// ble 0x823bb880
	if (!ctx.cr0.gt) goto loc_823BB880;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,-2
	ctx.r9.s64 = ctx.r9.s64 + -2;
loc_823BB838:
	// lwz r8,204(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lhz r7,2(r9)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r9.u32 + 2);
	// lwzx r6,r8,r10
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lhz r8,14(r6)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r6.u32 + 14);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r8,16(r6)
	REX_STORE_U16(ctx.r6.u32 + 16, ctx.r8.u16);
	// lbzu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// stb r8,20(r6)
	REX_STORE_U8(ctx.r6.u32 + 20, ctx.r8.u8);
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// sth r7,18(r6)
	REX_STORE_U16(ctx.r6.u32 + 18, ctx.r7.u16);
	// stb r8,21(r6)
	REX_STORE_U8(ctx.r6.u32 + 21, ctx.r8.u8);
	// lwz r8,140(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// lbz r8,38(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 38);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x823bb838
	if (ctx.cr6.lt) goto loc_823BB838;
loc_823BB880:
	// b 0x823bb888
	sub_823BB888(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823C1458) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x823C1460;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f1.f64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r23,r9
	ctx.r23.u64 = ctx.r9.u64;
	// clrlwi r25,r4,16
	ctx.r25.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c14b8
	if (ctx.cr6.eq) goto loc_823C14B8;
	// lhz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// clrlwi r11,r25,16
	ctx.r11.u64 = ctx.r25.u32 & 0xFFFF;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x823c14b8
	if (!ctx.cr6.gt) goto loc_823C14B8;
	// lwz r10,80(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 80);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// b 0x823c14bc
	goto loc_823C14BC;
loc_823C14B8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823C14BC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823c14cc
	if (!ctx.cr6.eq) goto loc_823C14CC;
loc_823C14C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823c15b4
	goto loc_823C15B4;
loc_823C14CC:
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r24,276(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x823c14f4
	if (ctx.cr6.eq) goto loc_823C14F4;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// lbz r6,28(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823bd8e8
	ctx.lr = 0x823C14F0;
	sub_823BD8E8(ctx, base);
	// stw r8,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
loc_823C14F4:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823be7d0
	ctx.lr = 0x823C1508;
	sub_823BE7D0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x823c1524
	if (!ctx.cr0.eq) goto loc_823C1524;
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x823c1534
	goto loc_823C1534;
loc_823C1524:
	// lha r10,5(r3)
	ctx.r10.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 5));
	// li r9,1
	ctx.r9.s64 = 1;
	// lha r8,7(r3)
	ctx.r8.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 7));
	// lhz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
loc_823C1534:
	// clrlwi. r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x823c14c4
	if (ctx.cr0.eq) goto loc_823C14C4;
	// lwz r3,284(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// clrlwi r30,r11,16
	ctx.r30.u64 = ctx.r11.u32 & 0xFFFF;
	// lbz r11,295(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 295);
	// add r6,r10,r28
	ctx.r6.u64 = ctx.r10.u64 + ctx.r28.u64;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// fmr f1,f10
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f10.f64;
	// add r7,r8,r27
	ctx.r7.u64 = ctx.r8.u64 + ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// bl 0x823c09e0
	ctx.lr = 0x823C1570;
	sub_823C09E0(ctx, base);
	// lha r11,86(r31)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 86));
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x823c158c
	if (ctx.cr6.eq) goto loc_823C158C;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// sth r30,86(r31)
	REX_STORE_U16(ctx.r31.u32 + 86, ctx.r30.u16);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
loc_823C158C:
	// clrlwi. r11,r23,24
	ctx.r11.u64 = ctx.r23.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823c15b0
	if (ctx.cr0.eq) goto loc_823C15B0;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// bl 0x825a43f0
	ctx.lr = 0x823C15A0;
	sub_825A43F0(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823bed08
	ctx.lr = 0x823C15AC;
	sub_823BED08(ctx, base);
	// b 0x823c15b4
	goto loc_823C15B4;
loc_823C15B0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_823C15B4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823C8308) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823C8310;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r11,22072
	ctx.r29.s64 = ctx.r11.s64 + 22072;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823C8330;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x823c83a4
	if (ctx.cr0.eq) goto loc_823C83A4;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r28,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r28.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,12472
	ctx.r10.s64 = ctx.r11.s64 + 12472;
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// li r4,188
	ctx.r4.s64 = 188;
	// lfs f13,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f13.f64 = double(temp.f32);
	// stb r30,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r30.u8);
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stb r30,17(r31)
	REX_STORE_U8(ctx.r31.u32 + 17, ctx.r30.u8);
	// lfs f0,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stfs f13,24(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823C8380;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823c8398
	if (ctx.cr0.eq) goto loc_823C8398;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r4,r11,31328
	ctx.r4.s64 = ctx.r11.s64 + 31328;
	// bl 0x823bdc58
	ctx.lr = 0x823C8394;
	sub_823BDC58(ctx, base);
	// b 0x823c839c
	goto loc_823C839C;
loc_823C8398:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_823C839C:
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// b 0x823c83a8
	goto loc_823C83A8;
loc_823C83A4:
	// li r31,0
	ctx.r31.s64 = 0;
loc_823C83A8:
	// stw r31,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r31.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823CCFA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x823CCFB0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// cmpwi cr6,r5,32
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 32, ctx.xer);
	// bgt cr6,0x823ccfdc
	if (ctx.cr6.gt) goto loc_823CCFDC;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// bl 0x823cde80
	ctx.lr = 0x823CCFD8;
	sub_823CDE80(ctx, base);
	// b 0x823cd078
	goto loc_823CD078;
loc_823CCFDC:
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r31,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r31.s64 = temp.s64;
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r26
	ctx.r29.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bl 0x825ad508
	ctx.lr = 0x823CCFF8;
	sub_825AD508(ctx, base);
	// cmpw cr6,r31,r3
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r3.s32, ctx.xer);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bgt cr6,0x823cd038
	if (ctx.cr6.gt) goto loc_823CD038;
	// bl 0x823cdf48
	ctx.lr = 0x823CD018;
	sub_823CDF48(ctx, base);
	// subf r27,r31,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r31.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823cdf48
	ctx.lr = 0x823CD034;
	sub_823CDF48(ctx, base);
	// b 0x823cd058
	goto loc_823CD058;
loc_823CD038:
	// bl 0x823ccfa8
	ctx.lr = 0x823CD03C;
	sub_823CCFA8(ctx, base);
	// subf r27,r31,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r31.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823ccfa8
	ctx.lr = 0x823CD058;
	sub_823CCFA8(ctx, base);
loc_823CD058:
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x823ce0a8
	ctx.lr = 0x823CD078;
	sub_823CE0A8(ctx, base);
loc_823CD078:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D0290) {
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
	ctx.lr = 0x823D02A0;
	sub_82213210(ctx, base);
	// lbz r11,4039(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4039);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823d02b4
	if (ctx.cr0.eq) goto loc_823D02B4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d02bc
	goto loc_823D02BC;
loc_823D02B4:
	// bl 0x82213210
	ctx.lr = 0x823D02B8;
	sub_82213210(ctx, base);
	// lbz r3,4033(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
loc_823D02BC:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82445010
	ctx.lr = 0x823D02C4;
	sub_82445010(ctx, base);
	// lfs f0,164(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 164);
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

DEFINE_REX_FUNC(sub_823D3880) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823d48c0
	sub_823D48C0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D48C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee8
	ctx.lr = 0x823D48C8;
	__savegprlr_16(ctx, base);
	// addi r12,r1,-136
	ctx.r12.s64 = ctx.r1.s64 + -136;
	// bl 0x8273af20
	ctx.lr = 0x823D48D0;
	__savefpr_26(ctx, base);
	// stwu r1,-848(r1)
	ea = -848 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,78
	ctx.r10.s64 = 78;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_823D48E4:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// lbz r9,436(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 436);
	// stb r9,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r9.u8);
	// bdnz 0x823d48e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823D48E4;
	// lbz r11,436(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 436);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823d55b0
	if (ctx.cr0.eq) goto loc_823D55B0;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r3,316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lwz r6,340(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// addi r19,r11,15088
	ctx.r19.s64 = ctx.r11.s64 + 15088;
	// addi r20,r10,2500
	ctx.r20.s64 = ctx.r10.s64 + 2500;
	// addi r18,r9,-30128
	ctx.r18.s64 = ctx.r9.s64 + -30128;
	// li r21,-1
	ctx.r21.s64 = -1;
	// li r17,0
	ctx.r17.s64 = 0;
	// lfs f26,-2616(r19)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + -2616);
	ctx.f26.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f31,-2852(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + -2852);
	ctx.f31.f64 = double(temp.f32);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// li r4,60
	ctx.r4.s64 = 60;
	// lfs f3,14744(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 14744);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,17780(r18)
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 17780);
	ctx.f2.f64 = double(temp.f32);
	// fmr f4,f26
	ctx.f4.f64 = ctx.f26.f64;
	// stb r17,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r17.u8);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c67c0
	ctx.lr = 0x823D4954;
	sub_823C67C0(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r11,-12972(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12972);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,676(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 676);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823d4990
	if (ctx.cr6.eq) goto loc_823D4990;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f3,14744(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 14744);
	ctx.f3.f64 = double(temp.f32);
	// lwz r5,340(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// fmr f5,f26
	ctx.f5.f64 = ctx.f26.f64;
	// fmr f4,f26
	ctx.f4.f64 = ctx.f26.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f2,-30616(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30616);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823c5a58
	ctx.lr = 0x823D498C;
	sub_823C5A58(ctx, base);
	// lwz r11,-12972(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12972);
loc_823D4990:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// addi r28,r10,1612
	ctx.r28.s64 = ctx.r10.s64 + 1612;
	// addi r23,r9,-4080
	ctx.r23.s64 = ctx.r9.s64 + -4080;
	// lwz r3,784(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 784);
	// lfs f29,17040(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 17040);
	ctx.f29.f64 = double(temp.f32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823d49d8
	if (ctx.cr6.eq) goto loc_823D49D8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f3,3432(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 3432);
	ctx.f3.f64 = double(temp.f32);
	// lwz r5,340(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// fmr f5,f26
	ctx.f5.f64 = ctx.f26.f64;
	// fmr f4,f26
	ctx.f4.f64 = ctx.f26.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// lfs f2,13784(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13784);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823c5a58
	ctx.lr = 0x823D49D4;
	sub_823C5A58(ctx, base);
	// lwz r11,-12972(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12972);
loc_823D49D8:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f31,-992(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -992);
	ctx.f31.f64 = double(temp.f32);
	// li r16,1
	ctx.r16.s64 = 1;
	// addi r22,r11,-30600
	ctx.r22.s64 = ctx.r11.s64 + -30600;
	// lwz r30,428(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 428);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823d4ba8
	if (ctx.cr6.eq) goto loc_823D4BA8;
	// lfs f0,4816(r18)
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 4816);
	ctx.f0.f64 = double(temp.f32);
	// stb r16,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r16.u8);
	// lfs f12,592(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 592);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lfs f13,4892(r18)
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 4892);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,596(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 596);
	ctx.f11.f64 = double(temp.f32);
	// addi r29,r11,-10736
	ctx.r29.s64 = ctx.r11.s64 + -10736;
	// lfs f12,600(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 600);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fsubs f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lfs f11,604(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 604);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,608(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 608);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f10,144(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f9,148(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// stfs f8,152(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,216
	ctx.r8.s64 = ctx.r1.s64 + 216;
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lfs f11,612(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 612);
	ctx.f11.f64 = double(temp.f32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lfs f10,616(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 616);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f9,620(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 620);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
	// fsubs f6,f9,f13
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f12,-3800(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -3800);
	ctx.f12.f64 = double(temp.f32);
	// lwz r5,340(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// lfs f11,22124(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 22124);
	ctx.f11.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// lfs f0,0(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14744(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 14744);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,-2620(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + -2620);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,236(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 236);
	ctx.f9.f64 = double(temp.f32);
	// stfs f8,164(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f7,168(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f6,172(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f10,208(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f12,212(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f31,216(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f11,220(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f31,224(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f12,228(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f11,236(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f12,244(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f13,248(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f11,252(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f13,256(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f12,260(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f9,264(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f11,268(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// bl 0x823c5c80
	ctx.lr = 0x823D4AE8;
	sub_823C5C80(ctx, base);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r5,340(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// addi r8,r1,232
	ctx.r8.s64 = ctx.r1.s64 + 232;
	// stb r16,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r16.u8);
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// addi r6,r1,152
	ctx.r6.s64 = ctx.r1.s64 + 152;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823c5c80
	ctx.lr = 0x823D4B10;
	sub_823C5C80(ctx, base);
	// lbz r11,473(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 473);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823d4b2c
	if (ctx.cr0.eq) goto loc_823D4B2C;
	// lbz r11,472(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 472);
	// mr r27,r16
	ctx.r27.u64 = ctx.r16.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823d4b30
	if (ctx.cr0.eq) goto loc_823D4B30;
loc_823D4B2C:
	// mr r27,r17
	ctx.r27.u64 = ctx.r17.u64;
loc_823D4B30:
	// clrlwi. r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d4b60
	if (ctx.cr0.eq) goto loc_823D4B60;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r5,340(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// addi r8,r1,248
	ctx.r8.s64 = ctx.r1.s64 + 248;
	// stb r16,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r16.u8);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823c5c80
	ctx.lr = 0x823D4B60;
	sub_823C5C80(ctx, base);
loc_823D4B60:
	// lwz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// stb r27,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r27.u8);
	// lbz r11,472(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 472);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm. r27,r11,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x823d4ba0
	if (ctx.cr0.eq) goto loc_823D4BA0;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r5,340(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// addi r8,r1,264
	ctx.r8.s64 = ctx.r1.s64 + 264;
	// stb r16,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r16.u8);
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// addi r6,r1,168
	ctx.r6.s64 = ctx.r1.s64 + 168;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823c5c80
	ctx.lr = 0x823D4BA0;
	sub_823C5C80(ctx, base);
loc_823D4BA0:
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// stb r27,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r27.u8);
loc_823D4BA8:
	// bl 0x82213210
	ctx.lr = 0x823D4BAC;
	sub_82213210(ctx, base);
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// addi r10,r20,11832
	ctx.r10.s64 = ctx.r20.s64 + 11832;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r3,4120
	ctx.r29.s64 = ctx.r3.s64 + 4120;
	// lwzx r30,r11,r10
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x82213210
	ctx.lr = 0x823D4BC4;
	sub_82213210(ctx, base);
	// lbz r11,4033(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// lfs f28,3304(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 3304);
	ctx.f28.f64 = double(temp.f32);
	// lfs f30,-10568(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -10568);
	ctx.f30.f64 = double(temp.f32);
	// lis r26,-32112
	ctx.r26.s64 = -2104492032;
	// lfs f27,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x823d4cf4
	if (!ctx.cr6.lt) goto loc_823D4CF4;
	// cmplwi cr6,r30,15
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 15, ctx.xer);
	// bge cr6,0x823d4cf4
	if (!ctx.cr6.lt) goto loc_823D4CF4;
	// mulli r11,r11,15
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(15));
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r11,r11,-5
	ctx.r11.s64 = ctx.r11.s64 + -5;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r11,r29
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823d4cf4
	if (ctx.cr6.eq) goto loc_823D4CF4;
	// lwz r11,-12856(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -12856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823d4cf4
	if (ctx.cr6.eq) goto loc_823D4CF4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8257a428
	ctx.lr = 0x823D4C18;
	sub_8257A428(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x823d4cf4
	if (ctx.cr0.eq) goto loc_823D4CF4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823b4f20
	ctx.lr = 0x823D4C28;
	sub_823B4F20(ctx, base);
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// lfs f0,-19588(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + -19588);
	ctx.f0.f64 = double(temp.f32);
	// stb r17,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r17.u8);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// srawi r10,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 4;
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// stfs f28,120(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// subf r10,r8,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r8.u64;
	// lwz r5,340(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r7,r7
	ctx.r7.s64 = ctx.r7.s32;
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r7,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f12,f12,f30
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f11,f11,f30
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f30.f64));
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x823c5c80
	ctx.lr = 0x823D4CF4;
	sub_823C5C80(ctx, base);
loc_823D4CF4:
	// lwz r11,428(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 428);
	// addi r27,r31,420
	ctx.r27.s64 = ctx.r31.s64 + 420;
	// lwz r10,424(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d4e20
	if (ctx.cr0.eq) goto loc_823D4E20;
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r11,88
	ctx.r11.s64 = ctx.r11.s64 + 88;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r11,r10
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823d4e20
	if (ctx.cr6.eq) goto loc_823D4E20;
	// lwz r11,-12856(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -12856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823d4e20
	if (ctx.cr6.eq) goto loc_823D4E20;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8257a428
	ctx.lr = 0x823D4D44;
	sub_8257A428(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x823d4e20
	if (ctx.cr0.eq) goto loc_823D4E20;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823b4f20
	ctx.lr = 0x823D4D54;
	sub_823B4F20(ctx, base);
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// lfs f0,3308(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 3308);
	ctx.f0.f64 = double(temp.f32);
	// stb r17,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r17.u8);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// srawi r10,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 4;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// stfs f28,112(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// subf r10,r8,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r8.u64;
	// lwz r5,340(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// extsw r7,r7
	ctx.r7.s64 = ctx.r7.s32;
	// std r8,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.r8.u64);
	// lfd f11,272(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 272);
	// std r7,384(r1)
	REX_STORE_U64(ctx.r1.u32 + 384, ctx.r7.u64);
	// lfd f12,384(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 384);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r11,392(r1)
	REX_STORE_U64(ctx.r1.u32 + 392, ctx.r11.u64);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// std r10,376(r1)
	REX_STORE_U64(ctx.r1.u32 + 376, ctx.r10.u64);
	// lfd f0,376(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 376);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfd f13,392(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 392);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmuls f0,f13,f30
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fmuls f0,f12,f30
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f0,f11,f30
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f30.f64));
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// bl 0x823c5c80
	ctx.lr = 0x823D4E20;
	sub_823C5C80(ctx, base);
loc_823D4E20:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823d6180
	ctx.lr = 0x823D4E28;
	sub_823D6180(ctx, base);
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// mr r28,r21
	ctx.r28.u64 = ctx.r21.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823d4e44
	if (ctx.cr6.lt) goto loc_823D4E44;
	// bne cr6,0x823d4e48
	if (!ctx.cr6.eq) goto loc_823D4E48;
	// mr r28,r16
	ctx.r28.u64 = ctx.r16.u64;
	// b 0x823d4e48
	goto loc_823D4E48;
loc_823D4E44:
	// mr r28,r17
	ctx.r28.u64 = ctx.r17.u64;
loc_823D4E48:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x823cfce0
	ctx.lr = 0x823D4E50;
	sub_823CFCE0(ctx, base);
	// stw r3,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r3.u32);
	// bl 0x823cfd68
	ctx.lr = 0x823D4E58;
	sub_823CFD68(ctx, base);
	// stw r3,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r3.u32);
	// bl 0x823cfdc0
	ctx.lr = 0x823D4E60;
	sub_823CFDC0(ctx, base);
	// stw r3,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r3.u32);
	// bl 0x823cfe18
	ctx.lr = 0x823D4E68;
	sub_823CFE18(ctx, base);
	// stw r3,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r3.u32);
	// bl 0x823cfe70
	ctx.lr = 0x823D4E70;
	sub_823CFE70(ctx, base);
	// stw r3,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r3.u32);
	// bl 0x823cfec8
	ctx.lr = 0x823D4E78;
	sub_823CFEC8(ctx, base);
	// stw r3,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// bl 0x823cff20
	ctx.lr = 0x823D4E80;
	sub_823CFF20(ctx, base);
	// stw r3,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r3.u32);
	// bl 0x823cff78
	ctx.lr = 0x823D4E88;
	sub_823CFF78(ctx, base);
	// stw r3,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r3.u32);
	// bl 0x823cffd0
	ctx.lr = 0x823D4E90;
	sub_823CFFD0(ctx, base);
	// stw r3,292(r1)
	REX_STORE_U32(ctx.r1.u32 + 292, ctx.r3.u32);
	// bl 0x823d0028
	ctx.lr = 0x823D4E98;
	sub_823D0028(ctx, base);
	// stw r3,296(r1)
	REX_STORE_U32(ctx.r1.u32 + 296, ctx.r3.u32);
	// bl 0x823d0080
	ctx.lr = 0x823D4EA0;
	sub_823D0080(ctx, base);
	// stw r3,300(r1)
	REX_STORE_U32(ctx.r1.u32 + 300, ctx.r3.u32);
	// bl 0x823d00d8
	ctx.lr = 0x823D4EA8;
	sub_823D00D8(ctx, base);
	// stw r3,304(r1)
	REX_STORE_U32(ctx.r1.u32 + 304, ctx.r3.u32);
	// bl 0x823d0130
	ctx.lr = 0x823D4EB0;
	sub_823D0130(ctx, base);
	// stw r3,308(r1)
	REX_STORE_U32(ctx.r1.u32 + 308, ctx.r3.u32);
	// bl 0x823d0188
	ctx.lr = 0x823D4EB8;
	sub_823D0188(ctx, base);
	// stw r3,312(r1)
	REX_STORE_U32(ctx.r1.u32 + 312, ctx.r3.u32);
	// bl 0x823d01e0
	ctx.lr = 0x823D4EC0;
	sub_823D01E0(ctx, base);
	// stw r3,316(r1)
	REX_STORE_U32(ctx.r1.u32 + 316, ctx.r3.u32);
	// bl 0x823d0238
	ctx.lr = 0x823D4EC8;
	sub_823D0238(ctx, base);
	// stw r3,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r3.u32);
	// bl 0x823d0290
	ctx.lr = 0x823D4ED0;
	sub_823D0290(ctx, base);
	// stw r3,324(r1)
	REX_STORE_U32(ctx.r1.u32 + 324, ctx.r3.u32);
	// bl 0x823d02e8
	ctx.lr = 0x823D4ED8;
	sub_823D02E8(ctx, base);
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// stw r3,328(r1)
	REX_STORE_U32(ctx.r1.u32 + 328, ctx.r3.u32);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823d4f2c
	if (!ctx.cr0.eq) goto loc_823D4F2C;
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r11,r1,140
	ctx.r11.s64 = ctx.r1.s64 + 140;
	// addi r10,r1,168
	ctx.r10.s64 = ctx.r1.s64 + 168;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_823D4F00:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x823d4f00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823D4F00;
	// li r11,11
	ctx.r11.s64 = 11;
	// addi r10,r1,284
	ctx.r10.s64 = ctx.r1.s64 + 284;
	// addi r9,r1,328
	ctx.r9.s64 = ctx.r1.s64 + 328;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_823D4F1C:
	// lwzu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x823d4f1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823D4F1C;
	// b 0x823d5090
	goto loc_823D5090;
loc_823D4F2C:
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// addi r27,r11,-4
	ctx.r27.s64 = ctx.r11.s64 + -4;
loc_823D4F38:
	// bl 0x82213210
	ctx.lr = 0x823D4F3C;
	sub_82213210(ctx, base);
	// lbz r29,4033(r3)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// bl 0x82213210
	ctx.lr = 0x823D4F44;
	sub_82213210(ctx, base);
	// addi r10,r3,4120
	ctx.r10.s64 = ctx.r3.s64 + 4120;
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// cmplwi cr6,r29,16
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 16, ctx.xer);
	// bge cr6,0x823d4f70
	if (!ctx.cr6.lt) goto loc_823D4F70;
	// cmplwi cr6,r30,15
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 15, ctx.xer);
	// bge cr6,0x823d4f70
	if (!ctx.cr6.lt) goto loc_823D4F70;
	// mulli r11,r29,15
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(15));
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r11,r11,-5
	ctx.r11.s64 = ctx.r11.s64 + -5;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_823D4F70:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stwu r11,4(r27)
	ea = 4 + ctx.r27.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r27.u32 = ea;
	// cmplwi cr6,r30,15
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 15, ctx.xer);
	// blt cr6,0x823d4f38
	if (ctx.cr6.lt) goto loc_823D4F38;
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// lwz r30,424(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// addi r11,r11,88
	ctx.r11.s64 = ctx.r11.s64 + 88;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82213210
	ctx.lr = 0x823D4F9C;
	sub_82213210(ctx, base);
	// lbz r27,4033(r3)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// bl 0x82213210
	ctx.lr = 0x823D4FA4;
	sub_82213210(ctx, base);
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// addi r10,r20,11832
	ctx.r10.s64 = ctx.r20.s64 + 11832;
	// addi r3,r3,4120
	ctx.r3.s64 = ctx.r3.s64 + 4120;
	// lwzx r6,r29,r30
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwzx r5,r11,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x82214848
	ctx.lr = 0x823D4FC4;
	sub_82214848(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x823cfce0
	ctx.lr = 0x823D4FCC;
	sub_823CFCE0(ctx, base);
	// stw r3,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r3.u32);
	// bl 0x823cfd68
	ctx.lr = 0x823D4FD4;
	sub_823CFD68(ctx, base);
	// stw r3,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r3.u32);
	// bl 0x823cfdc0
	ctx.lr = 0x823D4FDC;
	sub_823CFDC0(ctx, base);
	// stw r3,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r3.u32);
	// bl 0x823cfe18
	ctx.lr = 0x823D4FE4;
	sub_823CFE18(ctx, base);
	// stw r3,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r3.u32);
	// bl 0x823cfe70
	ctx.lr = 0x823D4FEC;
	sub_823CFE70(ctx, base);
	// stw r3,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r3.u32);
	// bl 0x823cfec8
	ctx.lr = 0x823D4FF4;
	sub_823CFEC8(ctx, base);
	// stw r3,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r3.u32);
	// bl 0x823cff20
	ctx.lr = 0x823D4FFC;
	sub_823CFF20(ctx, base);
	// stw r3,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r3.u32);
	// bl 0x823cff78
	ctx.lr = 0x823D5004;
	sub_823CFF78(ctx, base);
	// stw r3,332(r1)
	REX_STORE_U32(ctx.r1.u32 + 332, ctx.r3.u32);
	// bl 0x823cffd0
	ctx.lr = 0x823D500C;
	sub_823CFFD0(ctx, base);
	// stw r3,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, ctx.r3.u32);
	// bl 0x823d0028
	ctx.lr = 0x823D5014;
	sub_823D0028(ctx, base);
	// stw r3,340(r1)
	REX_STORE_U32(ctx.r1.u32 + 340, ctx.r3.u32);
	// bl 0x823d0080
	ctx.lr = 0x823D501C;
	sub_823D0080(ctx, base);
	// stw r3,344(r1)
	REX_STORE_U32(ctx.r1.u32 + 344, ctx.r3.u32);
	// bl 0x823d00d8
	ctx.lr = 0x823D5024;
	sub_823D00D8(ctx, base);
	// stw r3,348(r1)
	REX_STORE_U32(ctx.r1.u32 + 348, ctx.r3.u32);
	// bl 0x823d0130
	ctx.lr = 0x823D502C;
	sub_823D0130(ctx, base);
	// stw r3,352(r1)
	REX_STORE_U32(ctx.r1.u32 + 352, ctx.r3.u32);
	// bl 0x823d0188
	ctx.lr = 0x823D5034;
	sub_823D0188(ctx, base);
	// stw r3,356(r1)
	REX_STORE_U32(ctx.r1.u32 + 356, ctx.r3.u32);
	// bl 0x823d01e0
	ctx.lr = 0x823D503C;
	sub_823D01E0(ctx, base);
	// stw r3,360(r1)
	REX_STORE_U32(ctx.r1.u32 + 360, ctx.r3.u32);
	// bl 0x823d0238
	ctx.lr = 0x823D5044;
	sub_823D0238(ctx, base);
	// stw r3,364(r1)
	REX_STORE_U32(ctx.r1.u32 + 364, ctx.r3.u32);
	// bl 0x823d0290
	ctx.lr = 0x823D504C;
	sub_823D0290(ctx, base);
	// stw r3,368(r1)
	REX_STORE_U32(ctx.r1.u32 + 368, ctx.r3.u32);
	// bl 0x823d02e8
	ctx.lr = 0x823D5054;
	sub_823D02E8(ctx, base);
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// stw r3,372(r1)
	REX_STORE_U32(ctx.r1.u32 + 372, ctx.r3.u32);
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// addi r29,r11,-4
	ctx.r29.s64 = ctx.r11.s64 + -4;
loc_823D5064:
	// bl 0x82213210
	ctx.lr = 0x823D5068;
	sub_82213210(ctx, base);
	// lbz r28,4033(r3)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// bl 0x82213210
	ctx.lr = 0x823D5070;
	sub_82213210(ctx, base);
	// addi r3,r3,4120
	ctx.r3.s64 = ctx.r3.s64 + 4120;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwzu r6,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r6.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82214848
	ctx.lr = 0x823D5084;
	sub_82214848(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,15
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 15, ctx.xer);
	// blt cr6,0x823d5064
	if (ctx.cr6.lt) goto loc_823D5064;
loc_823D5090:
	// li r11,8
	ctx.r11.s64 = 8;
	// lfs f31,3420(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 3420);
	ctx.f31.f64 = double(temp.f32);
	// li r10,15
	ctx.r10.s64 = 15;
	// lfs f30,-264(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + -264);
	ctx.f30.f64 = double(temp.f32);
	// stw r11,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r11.u32);
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r10,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r10.u32);
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r11,220(r1)
	REX_STORE_U32(ctx.r1.u32 + 220, ctx.r11.u32);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r11,18
	ctx.r11.s64 = 18;
	// stw r9,216(r1)
	REX_STORE_U32(ctx.r1.u32 + 216, ctx.r9.u32);
	// stw r10,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r10.u32);
	// li r9,17
	ctx.r9.s64 = 17;
	// stw r11,236(r1)
	REX_STORE_U32(ctx.r1.u32 + 236, ctx.r11.u32);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r11,19
	ctx.r11.s64 = 19;
	// stw r9,228(r1)
	REX_STORE_U32(ctx.r1.u32 + 228, ctx.r9.u32);
	// stw r10,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r10.u32);
	// li r9,11
	ctx.r9.s64 = 11;
	// stw r11,244(r1)
	REX_STORE_U32(ctx.r1.u32 + 244, ctx.r11.u32);
	// li r10,13
	ctx.r10.s64 = 13;
	// li r11,14
	ctx.r11.s64 = 14;
	// stw r9,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r9.u32);
	// stw r10,248(r1)
	REX_STORE_U32(ctx.r1.u32 + 248, ctx.r10.u32);
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r11,256(r1)
	REX_STORE_U32(ctx.r1.u32 + 256, ctx.r11.u32);
	// li r10,21
	ctx.r10.s64 = 21;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r9,252(r1)
	REX_STORE_U32(ctx.r1.u32 + 252, ctx.r9.u32);
	// mr r25,r17
	ctx.r25.u64 = ctx.r17.u64;
	// stw r10,260(r1)
	REX_STORE_U32(ctx.r1.u32 + 260, ctx.r10.u32);
	// addi r26,r1,212
	ctx.r26.s64 = ctx.r1.s64 + 212;
	// addi r24,r1,172
	ctx.r24.s64 = ctx.r1.s64 + 172;
	// addi r27,r11,31384
	ctx.r27.s64 = ctx.r11.s64 + 31384;
loc_823D511C:
	// lwz r5,-28(r24)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r24.u32 + -28);
	// lwz r29,0(r24)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// cmpw cr6,r5,r29
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r29.s32, ctx.xer);
	// bge cr6,0x823d5134
	if (!ctx.cr6.lt) goto loc_823D5134;
	// mr r28,r17
	ctx.r28.u64 = ctx.r17.u64;
	// b 0x823d5140
	goto loc_823D5140;
loc_823D5134:
	// mr r28,r16
	ctx.r28.u64 = ctx.r16.u64;
	// bgt cr6,0x823d5140
	if (ctx.cr6.gt) goto loc_823D5140;
	// li r28,2
	ctx.r28.s64 = 2;
loc_823D5140:
	// cmplwi cr6,r28,1
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1, ctx.xer);
	// blt cr6,0x823d5164
	if (ctx.cr6.lt) goto loc_823D5164;
	// beq cr6,0x823d5158
	if (ctx.cr6.eq) goto loc_823D5158;
	// cmplwi cr6,r28,3
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 3, ctx.xer);
	// li r30,255
	ctx.r30.s64 = 255;
	// b 0x823d516c
	goto loc_823D516C;
loc_823D5158:
	// lis r30,-256
	ctx.r30.s64 = -16777216;
	// ori r30,r30,255
	ctx.r30.u64 = ctx.r30.u64 | 255;
	// b 0x823d516c
	goto loc_823D516C;
loc_823D5164:
	// lis r30,64
	ctx.r30.s64 = 4194304;
	// ori r30,r30,65535
	ctx.r30.u64 = ctx.r30.u64 | 65535;
loc_823D516C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x823d517c
	if (!ctx.cr6.lt) goto loc_823D517C;
	// mr r29,r17
	ctx.r29.u64 = ctx.r17.u64;
	// b 0x823d5188
	goto loc_823D5188;
loc_823D517C:
	// cmpwi cr6,r29,999
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 999, ctx.xer);
	// ble cr6,0x823d5188
	if (!ctx.cr6.gt) goto loc_823D5188;
	// li r29,999
	ctx.r29.s64 = 999;
loc_823D5188:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bge cr6,0x823d5198
	if (!ctx.cr6.lt) goto loc_823D5198;
	// mr r5,r17
	ctx.r5.u64 = ctx.r17.u64;
	// b 0x823d51a4
	goto loc_823D51A4;
loc_823D5198:
	// cmpwi cr6,r5,999
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 999, ctx.xer);
	// ble cr6,0x823d51a4
	if (!ctx.cr6.gt) goto loc_823D51A4;
	// li r5,999
	ctx.r5.s64 = 999;
loc_823D51A4:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x82738a28
	ctx.lr = 0x823D51B0;
	sub_82738A28(ctx, base);
	// lwz r11,-4(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -4);
	// li r5,1
	ctx.r5.s64 = 1;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
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
	ctx.lr = 0x823D51DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x82738a28
	ctx.lr = 0x823D51EC;
	sub_82738A28(ctx, base);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// lwzx r11,r29,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
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
	ctx.lr = 0x823D5218;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r30,16,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFF;
	// stb r30,111(r1)
	REX_STORE_U8(ctx.r1.u32 + 111, ctx.r30.u8);
	// rlwinm r10,r30,8,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 8) & 0xFF;
	// rlwinm r9,r30,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF;
	// stb r11,109(r1)
	REX_STORE_U8(ctx.r1.u32 + 109, ctx.r11.u8);
	// stb r10,108(r1)
	REX_STORE_U8(ctx.r1.u32 + 108, ctx.r10.u8);
	// addi r4,r1,108
	ctx.r4.s64 = ctx.r1.s64 + 108;
	// stb r9,110(r1)
	REX_STORE_U8(ctx.r1.u32 + 110, ctx.r9.u8);
	// lwzx r3,r29,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823D524C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r28,1
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1, ctx.xer);
	// blt cr6,0x823d5260
	if (ctx.cr6.lt) goto loc_823D5260;
	// bne cr6,0x823d52a0
	if (!ctx.cr6.eq) goto loc_823D52A0;
	// li r4,59
	ctx.r4.s64 = 59;
	// b 0x823d5264
	goto loc_823D5264;
loc_823D5260:
	// li r4,58
	ctx.r4.s64 = 58;
loc_823D5264:
	// extsw r11,r25
	ctx.r11.s64 = ctx.r25.s32;
	// lwz r6,340(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,320(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// std r11,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.r11.u64);
	// lfd f0,272(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 272);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stb r17,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r17.u8);
	// fmr f4,f26
	ctx.f4.f64 = ctx.f26.f64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// fadds f3,f0,f31
	ctx.f3.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bl 0x823c67c0
	ctx.lr = 0x823D52A0;
	sub_823C67C0(ctx, base);
loc_823D52A0:
	// addi r25,r25,40
	ctx.r25.s64 = ctx.r25.s64 + 40;
	// addi r24,r24,4
	ctx.r24.s64 = ctx.r24.s64 + 4;
	// addi r26,r26,8
	ctx.r26.s64 = ctx.r26.s64 + 8;
	// cmplwi cr6,r25,280
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 280, ctx.xer);
	// blt cr6,0x823d511c
	if (ctx.cr6.lt) goto loc_823D511C;
	// li r11,22
	ctx.r11.s64 = 22;
	// li r10,23
	ctx.r10.s64 = 23;
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// li r11,25
	ctx.r11.s64 = 25;
	// stw r10,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r11,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r11.u32);
	// li r10,26
	ctx.r10.s64 = 26;
	// li r11,28
	ctx.r11.s64 = 28;
	// stw r9,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// stw r10,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r10.u32);
	// li r9,27
	ctx.r9.s64 = 27;
	// stw r11,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// li r10,29
	ctx.r10.s64 = 29;
	// li r11,31
	ctx.r11.s64 = 31;
	// stw r9,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r9.u32);
	// stw r10,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// li r9,30
	ctx.r9.s64 = 30;
	// stw r11,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r11.u32);
	// li r10,32
	ctx.r10.s64 = 32;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r9,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// mr r28,r17
	ctx.r28.u64 = ctx.r17.u64;
	// stw r10,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r10.u32);
	// addi r27,r11,31500
	ctx.r27.s64 = ctx.r11.s64 + 31500;
loc_823D5318:
	// addi r11,r1,332
	ctx.r11.s64 = ctx.r1.s64 + 332;
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// lwz r10,-44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -44);
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x823d533c
	if (!ctx.cr6.lt) goto loc_823D533C;
	// lis r30,64
	ctx.r30.s64 = 4194304;
	// ori r30,r30,65535
	ctx.r30.u64 = ctx.r30.u64 | 65535;
	// b 0x823d5350
	goto loc_823D5350;
loc_823D533C:
	// ble cr6,0x823d534c
	if (!ctx.cr6.gt) goto loc_823D534C;
	// lis r30,-256
	ctx.r30.s64 = -16777216;
	// ori r30,r30,255
	ctx.r30.u64 = ctx.r30.u64 | 255;
	// b 0x823d5350
	goto loc_823D5350;
loc_823D534C:
	// li r30,255
	ctx.r30.s64 = 255;
loc_823D5350:
	// cmpwi cr6,r5,-999
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -999, ctx.xer);
	// bge cr6,0x823d5360
	if (!ctx.cr6.lt) goto loc_823D5360;
	// li r5,-999
	ctx.r5.s64 = -999;
	// b 0x823d536c
	goto loc_823D536C;
loc_823D5360:
	// cmpwi cr6,r5,999
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 999, ctx.xer);
	// ble cr6,0x823d536c
	if (!ctx.cr6.gt) goto loc_823D536C;
	// li r5,999
	ctx.r5.s64 = 999;
loc_823D536C:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x82738a28
	ctx.lr = 0x823D5378;
	sub_82738A28(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// lwzx r11,r28,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r29,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
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
	ctx.lr = 0x823D53A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r30,24,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF;
	// stb r30,107(r1)
	REX_STORE_U8(ctx.r1.u32 + 107, ctx.r30.u8);
	// rlwinm r10,r30,8,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 8) & 0xFF;
	// stb r11,106(r1)
	REX_STORE_U8(ctx.r1.u32 + 106, ctx.r11.u8);
	// rlwinm r11,r30,16,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFF;
	// stb r10,104(r1)
	REX_STORE_U8(ctx.r1.u32 + 104, ctx.r10.u8);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// stb r11,105(r1)
	REX_STORE_U8(ctx.r1.u32 + 105, ctx.r11.u8);
	// lwzx r3,r29,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823D53DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmplwi cr6,r28,44
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 44, ctx.xer);
	// blt cr6,0x823d5318
	if (ctx.cr6.lt) goto loc_823D5318;
	// lbz r11,472(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 472);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823d5400
	if (!ctx.cr0.eq) goto loc_823D5400;
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x823d5408
	if (!ctx.cr6.gt) goto loc_823D5408;
loc_823D5400:
	// lwz r3,332(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// bl 0x823c8528
	ctx.lr = 0x823D5408;
	sub_823C8528(ctx, base);
loc_823D5408:
	// li r10,11
	ctx.r10.s64 = 11;
	// addi r11,r20,11788
	ctx.r11.s64 = ctx.r20.s64 + 11788;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_823D5418:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// lbz r9,472(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 472);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwzx r10,r10,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// stb r9,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r9.u8);
	// bdnz 0x823d5418
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823D5418;
	// lbz r11,472(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 472);
	// lfs f31,0(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// lwz r10,188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// lfs f30,0(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stb r11,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r11.u8);
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// lbz r10,472(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 472);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r10,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r10.u8);
	// lwz r11,448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 448);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823d54b0
	if (ctx.cr6.eq) goto loc_823D54B0;
	// li r4,58
	ctx.r4.s64 = 58;
	// bgt cr6,0x823d5480
	if (ctx.cr6.gt) goto loc_823D5480;
	// li r4,59
	ctx.r4.s64 = 59;
loc_823D5480:
	// stb r17,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r17.u8);
	// lfs f0,332(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 332);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,328(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 328);
	ctx.f13.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// lwz r6,340(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// lwz r3,320(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// fmr f4,f26
	ctx.f4.f64 = ctx.f26.f64;
	// fadds f3,f0,f31
	ctx.f3.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// fsubs f2,f13,f30
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x823c67c0
	ctx.lr = 0x823D54B0;
	sub_823C67C0(ctx, base);
loc_823D54B0:
	// lwz r11,452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823d54f8
	if (ctx.cr6.eq) goto loc_823D54F8;
	// li r4,58
	ctx.r4.s64 = 58;
	// bgt cr6,0x823d54c8
	if (ctx.cr6.gt) goto loc_823D54C8;
	// li r4,59
	ctx.r4.s64 = 59;
loc_823D54C8:
	// stb r17,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r17.u8);
	// lfs f0,348(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 348);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,344(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 344);
	ctx.f13.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// lwz r6,340(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// lwz r3,320(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// fmr f4,f26
	ctx.f4.f64 = ctx.f26.f64;
	// fadds f3,f0,f31
	ctx.f3.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// fsubs f2,f13,f30
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x823c67c0
	ctx.lr = 0x823D54F8;
	sub_823C67C0(ctx, base);
loc_823D54F8:
	// lwz r3,460(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 460);
	// bl 0x823cb3a8
	ctx.lr = 0x823D5500;
	sub_823CB3A8(ctx, base);
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,28(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// lbz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x823d5550
	if (!ctx.cr0.eq) goto loc_823D5550;
	// lbz r10,25(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 25);
	// lfs f3,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lbz r8,24(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 24);
	// lfs f2,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// addic r6,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// lfs f1,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// rotlwi r8,r8,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// subfe r10,r6,r10
	temp.u8 = (~ctx.r6.u32 + ctx.r10.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r6.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r7,r20,14704
	ctx.r7.s64 = ctx.r20.s64 + 14704;
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lbzx r4,r11,r7
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r7.u32);
	// bl 0x823c66e8
	ctx.lr = 0x823D5550;
	sub_823C66E8(ctx, base);
loc_823D5550:
	// lbz r11,472(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 472);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823d5568
	if (ctx.cr0.eq) goto loc_823D5568;
	// lwz r11,480(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// lwz r10,488(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 488);
	// b 0x823d5570
	goto loc_823D5570;
loc_823D5568:
	// lwz r11,416(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// lwz r10,412(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
loc_823D5570:
	// neg r9,r11
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// cmpwi cr6,r10,11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 11, ctx.xer);
	// andc r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r11.u64;
	// rlwinm r9,r9,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// ble cr6,0x823d5594
	if (!ctx.cr6.gt) goto loc_823D5594;
	// addi r10,r10,-11
	ctx.r10.s64 = ctx.r10.s64 + -11;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// mr r11,r16
	ctx.r11.u64 = ctx.r16.u64;
	// blt cr6,0x823d5598
	if (ctx.cr6.lt) goto loc_823D5598;
loc_823D5594:
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_823D5598:
	// lwz r10,328(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// stb r11,9(r10)
	REX_STORE_U8(ctx.r10.u32 + 9, ctx.r11.u8);
	// stb r9,8(r10)
	REX_STORE_U8(ctx.r10.u32 + 8, ctx.r9.u8);
	// lwz r3,328(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// bl 0x823c7450
	ctx.lr = 0x823D55B0;
	sub_823C7450(ctx, base);
loc_823D55B0:
	// addi r1,r1,848
	ctx.r1.s64 = ctx.r1.s64 + 848;
	// addi r12,r1,-136
	ctx.r12.s64 = ctx.r1.s64 + -136;
	// bl 0x8273af6c
	ctx.lr = 0x823D55BC;
	__restfpr_26(ctx, base);
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8243BC40) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82363f08
	ctx.lr = 0x8243BC6C;
	sub_82363F08(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8243bd98
	if (ctx.cr0.eq) goto loc_8243BD98;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// beq 0x8243bd98
	if (ctx.cr0.eq) goto loc_8243BD98;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
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
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// beq 0x8243bd98
	if (ctx.cr0.eq) goto loc_8243BD98;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f13,4(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
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
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// beq 0x8243bd98
	if (ctx.cr0.eq) goto loc_8243BD98;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f13,4(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// li r3,1
	ctx.r3.s64 = 1;
	// bne 0x8243bd9c
	if (!ctx.cr0.eq) goto loc_8243BD9C;
loc_8243BD98:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8243BD9C:
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

DEFINE_REX_FUNC(sub_8244D430) {
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
	// bl 0x82222d88
	ctx.lr = 0x8244D454;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8244d474
	if (ctx.cr0.eq) goto loc_8244D474;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222d88
	ctx.lr = 0x8244D46C;
	sub_82222D88(ctx, base);
	// li r11,-21761
	ctx.r11.s64 = -21761;
	// stw r11,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
loc_8244D474:
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

DEFINE_REX_FUNC(sub_8244E9C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8244E9C8;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// clrlwi. r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244eb04
	if (ctx.cr0.eq) goto loc_8244EB04;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8244eb04
	if (ctx.cr6.eq) goto loc_8244EB04;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// addi r10,r10,22072
	ctx.r10.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,124
	ctx.r4.s64 = 124;
	// lfs f13,96(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-8792(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8792);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,48(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 48);
	// fadds f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// bl 0x825e02a0
	ctx.lr = 0x8244EA14;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8244ea48
	if (ctx.cr0.eq) goto loc_8244EA48;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,1340
	ctx.r4.s64 = ctx.r11.s64 + 1340;
	// bl 0x822237b8
	ctx.lr = 0x8244EA30;
	sub_822237B8(ctx, base);
	// li r11,523
	ctx.r11.s64 = 523;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// sth r11,96(r31)
	REX_STORE_U16(ctx.r31.u32 + 96, ctx.r11.u16);
	// addi r11,r10,1952
	ctx.r11.s64 = ctx.r10.s64 + 1952;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x8244ea4c
	goto loc_8244EA4C;
loc_8244EA48:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8244EA4C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8244eb04
	if (ctx.cr6.eq) goto loc_8244EB04;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r30,r11,-6700
	ctx.r30.s64 = ctx.r11.s64 + -6700;
	// lfs f31,-4440(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4440);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x824321a8
	ctx.lr = 0x8244EA68;
	sub_824321A8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// li r10,2
	ctx.r10.s64 = 2;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and. r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8244ea84
	if (ctx.cr0.eq) goto loc_8244EA84;
	// lfs f31,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
loc_8244EA84:
	// lwz r8,4(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r6,r7,15656
	ctx.r6.s64 = ctx.r7.s64 + 15656;
	// lfs f13,-2004(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2004);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lfs f12,15656(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 15656);
	ctx.f12.f64 = double(temp.f32);
	// stfs f31,104(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 104, temp.u32);
	// stb r10,91(r31)
	REX_STORE_U8(ctx.r31.u32 + 91, ctx.r10.u8);
	// lfs f0,-1280(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -1280);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,108(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// stfs f0,112(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 112, temp.u32);
	// stfs f12,116(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 116, temp.u32);
	// stw r8,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
	// stfs f0,120(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// beq cr6,0x8244ead0
	if (ctx.cr6.eq) goto loc_8244EAD0;
	// stb r10,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r10.u8);
loc_8244EAD0:
	// stb r9,90(r31)
	REX_STORE_U8(ctx.r31.u32 + 90, ctx.r9.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x8244EAE0;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8244eb04
	if (!ctx.cr6.eq) goto loc_8244EB04;
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
	ctx.lr = 0x8244EB04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8244EB04:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824577B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x824577C0;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r26,r11,22072
	ctx.r26.s64 = ctx.r11.s64 + 22072;
	// addi r11,r10,-16252
	ctx.r11.s64 = ctx.r10.s64 + -16252;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// lwz r30,8(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x825e02a0
	ctx.lr = 0x824577EC;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// li r29,0
	ctx.r29.s64 = 0;
	// beq 0x82457850
	if (ctx.cr0.eq) goto loc_82457850;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82457818;
	sub_825E02A0(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82457854
	if (!ctx.cr6.gt) goto loc_82457854;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_82457830:
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r29,r9,r10
	REX_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r29.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82457830
	if (ctx.cr6.lt) goto loc_82457830;
	// b 0x82457854
	goto loc_82457854;
loc_82457850:
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_82457854:
	// li r11,255
	ctx.r11.s64 = 255;
	// stw r31,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r31.u32);
	// stb r29,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r29.u8);
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// stb r29,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r29.u8);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stb r29,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r29.u8);
	// addi r27,r11,-25508
	ctx.r27.s64 = ctx.r11.s64 + -25508;
loc_8245787C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// li r4,48
	ctx.r4.s64 = 48;
	// bl 0x825e02a0
	ctx.lr = 0x8245788C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824578a4
	if (ctx.cr0.eq) goto loc_824578A4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwzx r5,r30,r27
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// bl 0x825af240
	ctx.lr = 0x824578A0;
	sub_825AF240(ctx, base);
	// b 0x824578a8
	goto loc_824578A8;
loc_824578A4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_824578A8:
	// lwz r31,0(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x824578f4
	if (!ctx.cr6.lt) goto loc_824578F4;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwzx r10,r11,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x824578f4
	if (!ctx.cr6.eq) goto loc_824578F4;
	// stwx r3,r11,r30
	REX_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r3.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwzx r3,r11,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bctrl 
	ctx.lr = 0x824578E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_824578F4:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplwi cr6,r30,12
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 12, ctx.xer);
	// blt cr6,0x8245787c
	if (ctx.cr6.lt) goto loc_8245787C;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82463770) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82463778;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82213210
	ctx.lr = 0x82463784;
	sub_82213210(ctx, base);
	// lwz r30,19228(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 19228);
	// lbz r11,235(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 235);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82463838
	if (!ctx.cr0.eq) goto loc_82463838;
	// lbz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lbz r8,1(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 1);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// lbz r6,2(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 2);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lbz r29,3(r31)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r31.u32 + 3);
	// li r5,16
	ctx.r5.s64 = 16;
	// lbz r31,4(r31)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r31.u32 + 4);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// stb r10,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r8,1(r9)
	REX_STORE_U8(ctx.r9.u32 + 1, ctx.r8.u8);
	// stb r6,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r6.u8);
	// stb r29,3(r9)
	REX_STORE_U8(ctx.r9.u32 + 3, ctx.r29.u8);
	// stb r31,0(r7)
	REX_STORE_U8(ctx.r7.u32 + 0, ctx.r31.u8);
	// bl 0x8273a030
	ctx.lr = 0x824637D8;
	sub_8273A030(ctx, base);
	// lwz r31,84(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825a48b0
	ctx.lr = 0x824637E8;
	sub_825A48B0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ed230
	ctx.lr = 0x824637F4;
	sub_823ED230(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r3,r30,264
	ctx.r3.s64 = ctx.r30.s64 + 264;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stb r11,235(r30)
	REX_STORE_U8(ctx.r30.u32 + 235, ctx.r11.u8);
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8273a030
	ctx.lr = 0x8246380C;
	sub_8273A030(ctx, base);
	// lbz r31,80(r1)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// clrlwi r3,r31,25
	ctx.r3.u64 = ctx.r31.u32 & 0x7F;
	// bl 0x82577128
	ctx.lr = 0x82463818;
	sub_82577128(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82213210
	ctx.lr = 0x82463820;
	sub_82213210(ctx, base);
	// stb r30,4035(r3)
	REX_STORE_U8(ctx.r3.u32 + 4035, ctx.r30.u8);
	// rlwinm r11,r31,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xFFFFFF80;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r31,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r31.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// bl 0x82213210
	ctx.lr = 0x82463834;
	sub_82213210(ctx, base);
	// stb r31,4036(r3)
	REX_STORE_U8(ctx.r3.u32 + 4036, ctx.r31.u8);
loc_82463838:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8246A4B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8246A4C0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// li r4,72
	ctx.r4.s64 = 72;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8246A4E8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8246a4fc
	if (ctx.cr0.eq) goto loc_8246A4FC;
	// bl 0x8222f700
	ctx.lr = 0x8246A4F4;
	sub_8222F700(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8246a500
	goto loc_8246A500;
loc_8246A4FC:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8246A500:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8246a514
	if (!ctx.cr6.eq) goto loc_8246A514;
loc_8246A50C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8246a634
	goto loc_8246A634;
loc_8246A514:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r3,-12860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -12860);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8246a53c
	if (ctx.cr6.eq) goto loc_8246A53C;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8246cfe0
	ctx.lr = 0x8246A534;
	sub_8246CFE0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8246a540
	goto loc_8246A540;
loc_8246A53C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8246A540:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bne cr6,0x8246a564
	if (!ctx.cr6.eq) goto loc_8246A564;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246A560;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8246a50c
	goto loc_8246A50C;
loc_8246A564:
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246A578;
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
	ctx.lr = 0x8246A590;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,268(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 268);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8246a5cc
	if (ctx.cr0.eq) goto loc_8246A5CC;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,260(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 260);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246A5B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,264(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246A5CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8246A5CC:
	// lwz r11,124(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 124);
	// addi r3,r28,120
	ctx.r3.s64 = ctx.r28.s64 + 120;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8246a5e4
	if (!ctx.cr6.eq) goto loc_8246A5E4;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8246a5f0
	goto loc_8246A5F0;
loc_8246A5E4:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_8246A5F0:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8246a614
	if (!ctx.cr6.lt) goto loc_8246A614;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r31,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r31.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x8246a61c
	goto loc_8246A61C;
loc_8246A614:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823849b0
	ctx.lr = 0x8246A61C;
	sub_823849B0(ctx, base);
loc_8246A61C:
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r28,152
	ctx.r3.s64 = ctx.r28.s64 + 152;
	// bl 0x82396cc8
	ctx.lr = 0x8246A628;
	sub_82396CC8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,253(r28)
	REX_STORE_U8(ctx.r28.u32 + 253, ctx.r11.u8);
loc_8246A634:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824742C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x824742C8;
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
	// bne cr6,0x824742f4
	if (!ctx.cr6.eq) goto loc_824742F4;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
loc_824742F4:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,-1560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1560);
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
	// addi r10,r10,32624
	ctx.r10.s64 = ctx.r10.s64 + 32624;
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
	ctx.lr = 0x82474350;
	sub_8255F918(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,3
	ctx.r3.s64 = 3;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// bl 0x82519328
	ctx.lr = 0x82474370;
	sub_82519328(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8247B708) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8247B710;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,20580
	ctx.r11.s64 = ctx.r11.s64 + 20580;
	// lis r30,-32240
	ctx.r30.s64 = -2112880640;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r29,r30,12468
	ctx.r29.s64 = ctx.r30.s64 + 12468;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lfs f31,-232(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lfs f1,1908(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1908);
	ctx.f1.f64 = double(temp.f32);
	// ld r11,-10736(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + -10736);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// std r11,12(r3)
	REX_STORE_U64(ctx.r3.u32 + 12, ctx.r11.u64);
	// ld r11,-10736(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + -10736);
	// std r11,20(r3)
	REX_STORE_U64(ctx.r3.u32 + 20, ctx.r11.u64);
	// bl 0x825a4a40
	ctx.lr = 0x8247B768;
	sub_825A4A40(ctx, base);
	// stfs f1,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f1,1812(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1812);
	ctx.f1.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,4440(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4440);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8247B780;
	sub_825A4A40(ctx, base);
	// stfs f1,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,2820(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2820);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8247B794;
	sub_825A4A40(ctx, base);
	// li r11,-218
	ctx.r11.s64 = -218;
	// li r10,2
	ctx.r10.s64 = 2;
	// lfs f0,12468(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f1,36(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// stw r10,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824817F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82481800;
	__savegprlr_26(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82223a50
	ctx.lr = 0x8248180C;
	sub_82223A50(ctx, base);
	// lfs f0,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,132(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// lfs f0,112(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,-31328
	ctx.r10.s64 = ctx.r10.s64 + -31328;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lfs f13,108(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r8,32720
	ctx.r11.s64 = ctx.r8.s64 + 32720;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,108
	ctx.r11.s64 = ctx.r31.s64 + 108;
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,108(r31)
	REX_STORE_U64(ctx.r31.u32 + 108, ctx.r10.u64);
	// lfs f0,116(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,108(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,112(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f10,172(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
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
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f10,168(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f10,164(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f10,160(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
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
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lfs f0,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// vmulfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v59,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v59,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r29,r1,160
	ctx.r29.s64 = ctx.r1.s64 + 160;
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lvx128 v59,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lwz r26,0(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r27,r1,160
	ctx.r27.s64 = ctx.r1.s64 + 160;
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,24(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 24);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v61,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bctrl 
	ctx.lr = 0x82481A74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f12,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,132(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-9856(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f12,f11,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f11.f64, -ctx.f0.f64)));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x82481aa0
	if (ctx.cr6.gt) goto loc_82481AA0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// li r30,0
	ctx.r30.s64 = 0;
loc_82481AA0:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// fctidz f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r11,87(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lbz r10,98(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 98);
	// lbz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// lbz r11,97(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 97);
	// stb r10,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r10.u8);
	// stb r9,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824AB8C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x824AB8C8;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,6(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lwz r8,100(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r11,255
	ctx.r11.s64 = 255;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// ori r8,r8,128
	ctx.r8.u64 = ctx.r8.u64 | 128;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-8644(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r8,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r8.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lis r28,-32111
	ctx.r28.s64 = -2104426496;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_824AB924:
	// extsw r11,r29
	ctx.r11.s64 = ctx.r29.s32;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f0,-25456(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -25456);
	ctx.f0.f64 = double(temp.f32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwzx r3,r30,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x824AB95C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824AB978;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824AB994;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r4,292(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824AB9B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824AB9CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// blt cr6,0x824ab924
	if (ctx.cr6.lt) goto loc_824AB924;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824B1520) {
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
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,36
	ctx.r4.s64 = 36;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824B154C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824b1558
	if (ctx.cr0.eq) goto loc_824B1558;
	// stw r3,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
loc_824B1558:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824b1564
	if (ctx.cr0.eq) goto loc_824B1564;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_824B1564:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_824B40C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x824B40C8;
	__savegprlr_26(ctx, base);
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f29.u64);
	// stfd f30,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,300(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 300);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x824b4838
	if (ctx.cr6.lt) goto loc_824B4838;
	// beq cr6,0x824b4500
	if (ctx.cr6.eq) goto loc_824B4500;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x824b4330
	if (ctx.cr6.lt) goto loc_824B4330;
	// beq cr6,0x824b4110
	if (ctx.cr6.eq) goto loc_824B4110;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x824b498c
	if (!ctx.cr6.lt) goto loc_824B498C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
	// b 0x824b498c
	goto loc_824B498C;
loc_824B4110:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,340(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// addi r29,r11,-19660
	ctx.r29.s64 = ctx.r11.s64 + -19660;
	// stb r30,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r30.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r30,344(r31)
	REX_STORE_U8(ctx.r31.u32 + 344, ctx.r30.u8);
	// lfs f0,-9148(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -9148);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f29,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f29.f64, ctx.f0.f64, -ctx.f13.f64)));
	// stfs f0,340(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B4150;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// lfs f0,340(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824b41b0
	if (!ctx.cr6.gt) goto loc_824B41B0;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lbz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r9,124(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
	// lbz r10,81(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r11,82(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r8,103(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// stb r10,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r10.u8);
	// stb r11,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r11.u8);
	// stb r8,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r8.u8);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B41AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x824b41f0
	goto loc_824B41F0;
loc_824B41B0:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r9,81(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r8,82(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// stb r30,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r30.u8);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stb r10,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r10.u8);
	// stb r9,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r9.u8);
	// stb r8,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r8.u8);
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B41E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r11.u32);
loc_824B41F0:
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// addi r30,r31,68
	ctx.r30.s64 = ctx.r31.s64 + 68;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x824b4210
	if (!ctx.cr6.eq) goto loc_824B4210;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,2012(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2012);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29492(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// b 0x824b4220
	goto loc_824B4220;
loc_824B4210:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r11,r11,27412
	ctx.r11.s64 = ctx.r11.s64 + 27412;
	// lfs f0,17672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10316(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10316);
	ctx.f13.f64 = double(temp.f32);
loc_824B4220:
	// stfs f0,320(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// stfs f13,68(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lfs f0,116(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// lfs f13,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B4254;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f13,320(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lfs f12,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r7,-30832
	ctx.r11.s64 = ctx.r7.s64 + -30832;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
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
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
	// b 0x824b498c
	goto loc_824B498C;
loc_824B4330:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r11,27412
	ctx.r29.s64 = ctx.r11.s64 + 27412;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,-2
	ctx.r3.s64 = -2;
	// lfs f0,-15464(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -15464);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x825a49b0
	ctx.lr = 0x824B4354;
	sub_825A49B0(ctx, base);
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r10,r3,5
	ctx.r10.s64 = ctx.r3.s64 + 5;
	// rotlwi r11,r9,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r8,r9,r10
	ctx.r8.u64 = uint32_t((ctx.r10.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r9.s32 / ctx.r10.s32 : 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mullw r8,r8,r10
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// andc r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ~ctx.r11.u64;
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// subf. r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// twlgei r11,-1
	if (ctx.r11.s32 == -1 || ctx.r11.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// bne 0x824b4394
	if (!ctx.cr0.eq) goto loc_824B4394;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,44(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// bl 0x824b4a88
	ctx.lr = 0x824B4394;
	sub_824B4A88(ctx, base);
loc_824B4394:
	// addi r4,r31,68
	ctx.r4.s64 = ctx.r31.s64 + 68;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8231e0d8
	ctx.lr = 0x824B43A0;
	sub_8231E0D8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lfs f12,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r11,32480
	ctx.r8.s64 = ctx.r11.s64 + 32480;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r30,r11,12472
	ctx.r30.s64 = ctx.r11.s64 + 12472;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,2616(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2616);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,52(r31)
	REX_STORE_U64(ctx.r31.u32 + 52, ctx.r11.u64);
	// ble cr6,0x824b44f0
	if (!ctx.cr6.gt) goto loc_824B44F0;
	// lfs f13,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f0,19700(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 19700);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fnmsubs f0,f29,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f29.f64, ctx.f0.f64, -ctx.f13.f64)));
	// stfs f0,340(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B4464;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,82(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// lfs f13,-4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,124(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f0,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// stb r9,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r9.u8);
	// lwz r3,0(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// ble cr6,0x824b44bc
	if (!ctx.cr6.gt) goto loc_824B44BC;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lbz r10,81(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// stb r10,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r10.u8);
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lbz r10,119(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 119);
	// stb r10,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r10.u8);
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// bctrl 
	ctx.lr = 0x824B44B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x824b44f0
	goto loc_824B44F0;
loc_824B44BC:
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r11,81(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// stb r10,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r10.u8);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// stb r11,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r11.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stb r10,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r10.u8);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// bctrl 
	ctx.lr = 0x824B44E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r11.u32);
loc_824B44F0:
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// b 0x824b498c
	goto loc_824B498C;
loc_824B4500:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,27412
	ctx.r30.s64 = ctx.r11.s64 + 27412;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,-2
	ctx.r3.s64 = -2;
	// lfs f0,-15464(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -15464);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x825a49b0
	ctx.lr = 0x824B4524;
	sub_825A49B0(ctx, base);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r3,5
	ctx.r11.s64 = ctx.r3.s64 + 5;
	// addi r28,r10,12472
	ctx.r28.s64 = ctx.r10.s64 + 12472;
	// lfs f0,1808(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1808);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824b457c
	if (!ctx.cr6.gt) goto loc_824B457C;
	// fctiwz f0,f31
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r9,116(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r8,r9,r11
	ctx.r8.u64 = uint32_t((ctx.r11.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r9.s32 / ctx.r11.s32 : 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mullw r8,r8,r11
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// andc r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r10.u64;
	// subf. r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// twlgei r11,-1
	if (ctx.r11.s32 == -1 || ctx.r11.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// bne 0x824b457c
	if (!ctx.cr0.eq) goto loc_824B457C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,44(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// bl 0x824b4a88
	ctx.lr = 0x824B457C;
	sub_824B4A88(ctx, base);
loc_824B457C:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1376(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1376);
	ctx.f13.f64 = double(temp.f32);
	// addi r26,r11,-9668
	ctx.r26.s64 = ctx.r11.s64 + -9668;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lfs f12,304(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-1180(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1180);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f12,f0
	ctx.f31.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bgt cr6,0x824b45b0
	if (ctx.cr6.gt) goto loc_824B45B0;
	// bl 0x82738cc0
	ctx.lr = 0x824B45A8;
	sub_82738CC0(ctx, base);
	// lfs f0,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 288);
	ctx.f0.f64 = double(temp.f32);
	// b 0x824b45b8
	goto loc_824B45B8;
loc_824B45B0:
	// bl 0x82738cc0
	ctx.lr = 0x824B45B4;
	sub_82738CC0(ctx, base);
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
loc_824B45B8:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r29,r11,-19660
	ctx.r29.s64 = ctx.r11.s64 + -19660;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f0,-10472(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -10472);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r27,0(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x82738be0
	ctx.lr = 0x824B4620;
	sub_82738BE0(ctx, base);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f13,-236(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -236);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lfs f0,2404(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 2404);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// fnmsubs f1,f12,f0,f13
	ctx.f1.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B4644;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r27,r11,-4080
	ctx.r27.s64 = ctx.r11.s64 + -4080;
	// lfs f0,236(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// bl 0x82738be0
	ctx.lr = 0x824B4658;
	sub_82738BE0(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f13,1532(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1532);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19352(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -19352);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f30,9804(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 9804);
	ctx.f30.f64 = double(temp.f32);
	// li r27,1
	ctx.r27.s64 = 1;
	// lfs f0,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fmadds f13,f11,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f11.f64, ctx.f13.f64, ctx.f12.f64)));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// stb r11,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r11.u8);
	// stb r11,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r11.u8);
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bge cr6,0x824b46d8
	if (!ctx.cr6.lt) goto loc_824B46D8;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lbz r10,119(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 119);
	// stb r10,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r10.u8);
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// bctrl 
	ctx.lr = 0x824B46C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,340(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f29,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,340(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// b 0x824b46ec
	goto loc_824B46EC;
loc_824B46D8:
	// li r9,255
	ctx.r9.s64 = 255;
	// stb r9,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r9.u8);
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// bctrl 
	ctx.lr = 0x824B46E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r27,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r27.u8);
loc_824B46EC:
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// lfs f0,1368(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1368);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,304(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824b476c
	if (!ctx.cr6.gt) goto loc_824B476C;
	// lfs f0,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// fmuls f13,f0,f29
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// lfs f0,-10356(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -10356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// lfs f0,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// b 0x824b47d0
	goto loc_824B47D0;
loc_824B476C:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82738be0
	ctx.lr = 0x824B4774;
	sub_82738BE0(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f12,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f11,284(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 284);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
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
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
loc_824B47D0:
	// lfs f13,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1376(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1376);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824b498c
	if (!ctx.cr6.gt) goto loc_824B498C;
	// lfs f12,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f12.f64 = double(temp.f32);
	// li r11,2
	ctx.r11.s64 = 2;
	// lfs f13,-21264(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -21264);
	ctx.f13.f64 = double(temp.f32);
	// li r3,500
	ctx.r3.s64 = 500;
	// lfs f0,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stfs f13,68(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stw r11,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r11.u32);
	// stfs f30,340(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f13,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82240a58
	ctx.lr = 0x824B4830;
	sub_82240A58(ctx, base);
	// stb r27,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r27.u8);
	// b 0x824b498c
	goto loc_824B498C;
loc_824B4838:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,348(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f0,-236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,324(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// bne cr6,0x824b485c
	if (!ctx.cr6.eq) goto loc_824B485C;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,324(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
loc_824B485C:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f31,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f31.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stfs f31,304(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// li r27,1
	ctx.r27.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r30,186(r31)
	REX_STORE_U8(ctx.r31.u32 + 186, ctx.r30.u8);
	// stb r27,344(r31)
	REX_STORE_U8(ctx.r31.u32 + 344, ctx.r27.u8);
	// lwz r11,-13032(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824b48b0
	if (ctx.cr6.eq) goto loc_824B48B0;
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lfs f13,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823aefa8
	ctx.lr = 0x824B48B0;
	sub_823AEFA8(ctx, base);
loc_824B48B0:
	// stb r3,312(r31)
	REX_STORE_U8(ctx.r31.u32 + 312, ctx.r3.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B48D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,324(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f0.f64 = double(temp.f32);
	// stw r30,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r30.u32);
	// stfs f31,316(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stw r30,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r30.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x824b48f4
	if (!ctx.cr6.lt) goto loc_824B48F4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,-19660(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19660);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
loc_824B48F4:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f13,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,116(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B4920;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r30,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r30.u8);
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
	// stb r11,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r11.u8);
	// stb r11,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r11.u8);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B4950;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// li r3,499
	ctx.r3.s64 = 499;
	// lwz r10,284(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stw r10,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82240a58
	ctx.lr = 0x824B4988;
	sub_82240A58(ctx, base);
	// stw r27,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r27.u32);
loc_824B498C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824FB940) {
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
	// addi r11,r11,-9400
	ctx.r11.s64 = ctx.r11.s64 + -9400;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469fb0
	ctx.lr = 0x824FB964;
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
	ctx.lr = 0x824FB978;
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

DEFINE_REX_FUNC(sub_824FD8D8) {
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
	ctx.lr = 0x824FD904;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824fd924
	if (!ctx.cr0.eq) goto loc_824FD924;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824FD924;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824FD924:
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

DEFINE_REX_FUNC(sub_824FF628) {
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
	// lwz r11,284(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 284);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r10,r10,15420
	ctx.r10.s64 = ctx.r10.s64 + 15420;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r9,-9092
	ctx.r4.s64 = ctx.r9.s64 + -9092;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhzx r5,r11,r10
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x8246a4b8
	ctx.lr = 0x824FF65C;
	sub_8246A4B8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,268(r31)
	REX_STORE_U8(ctx.r31.u32 + 268, ctx.r11.u8);
	// stb r10,193(r31)
	REX_STORE_U8(ctx.r31.u32 + 193, ctx.r10.u8);
	// stb r11,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r11.u8);
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

DEFINE_REX_FUNC(sub_825019C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x825019C8;
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
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82501c2c
	if (!ctx.cr0.eq) goto loc_82501C2C;
	// lbz r11,289(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82501a08
	if (ctx.cr0.eq) goto loc_82501A08;
	// lwz r11,316(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 316);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bge cr6,0x82501a08
	if (!ctx.cr6.lt) goto loc_82501A08;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,316(r3)
	REX_STORE_U32(ctx.r3.u32 + 316, ctx.r11.u32);
loc_82501A08:
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82501bc8
	if (ctx.cr6.lt) goto loc_82501BC8;
	// beq cr6,0x82501a90
	if (ctx.cr6.eq) goto loc_82501A90;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82501a68
	if (ctx.cr6.lt) goto loc_82501A68;
	// beq cr6,0x82501a38
	if (ctx.cr6.eq) goto loc_82501A38;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x82501c2c
	if (!ctx.cr6.lt) goto loc_82501C2C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x82501c2c
	goto loc_82501C2C;
loc_82501A38:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f12,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r11,12468
	ctx.r10.s64 = ctx.r11.s64 + 12468;
	// lfs f0,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1908(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f13,f31,f13,f12
	ctx.f13.f64 = double(float(-std::fma(ctx.f31.f64, ctx.f13.f64, -ctx.f12.f64)));
	// stfs f13,304(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82501c2c
	if (!ctx.cr6.lt) goto loc_82501C2C;
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x82501bc0
	goto loc_82501BC0;
loc_82501A68:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f13,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 484);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f1,f0,f31,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f13.f64)));
	// stfs f1,308(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// bl 0x82738be0
	ctx.lr = 0x82501A80;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// b 0x82501c2c
	goto loc_82501C2C;
loc_82501A90:
	// lfs f0,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f0,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// li r28,0
	ctx.r28.s64 = 0;
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f12,292(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// addi r29,r11,-6412
	ctx.r29.s64 = ctx.r11.s64 + -6412;
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// lfs f13,-6412(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x82501ac8
	if (!ctx.cr6.gt) goto loc_82501AC8;
	// li r27,1
	ctx.r27.s64 = 1;
loc_82501AC8:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// lfs f30,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x82501b2c
	if (!ctx.cr6.lt) goto loc_82501B2C;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r10,332(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// lfs f0,528(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 528);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// bge cr6,0x82501b2c
	if (!ctx.cr6.lt) goto loc_82501B2C;
	// lfs f0,32440(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 32440);
	ctx.f0.f64 = double(temp.f32);
	// stb r28,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r28.u8);
	// lfs f13,1908(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f12,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r31,336
	ctx.r3.s64 = ctx.r31.s64 + 336;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x82501de8
	ctx.lr = 0x82501B20;
	sub_82501DE8(ctx, base);
	// lwz r11,332(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
loc_82501B2C:
	// lwz r10,340(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82501c2c
	if (ctx.cr6.eq) goto loc_82501C2C;
	// lfs f13,1908(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,32440(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 32440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f12.f64 = double(temp.f32);
loc_82501B48:
	// lbz r9,24(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 24);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x82501ba4
	if (!ctx.cr0.eq) goto loc_82501BA4;
	// lfs f10,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f11,f10,f31,f11
	ctx.f11.f64 = double(float(std::fma(ctx.f10.f64, ctx.f31.f64, ctx.f11.f64)));
	// stfs f11,8(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// lfs f11,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// fnmsubs f11,f11,f31,f10
	ctx.f11.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f31.f64, -ctx.f10.f64)));
	// stfs f11,16(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// fcmpu cr6,f11,f30
	ctx.cr6.compare(ctx.f11.f64, ctx.f30.f64);
	// bge cr6,0x82501ba8
	if (!ctx.cr6.lt) goto loc_82501BA8;
	// clrlwi. r9,r27,24
	ctx.r9.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82501b98
	if (!ctx.cr0.eq) goto loc_82501B98;
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stfs f0,12(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stfs f12,16(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f0,20(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// b 0x82501ba8
	goto loc_82501BA8;
loc_82501B98:
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r9.u8);
	// b 0x82501ba8
	goto loc_82501BA8;
loc_82501BA4:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_82501BA8:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82501b48
	if (!ctx.cr6.eq) goto loc_82501B48;
	// cmpwi cr6,r28,10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 10, ctx.xer);
	// bne cr6,0x82501c2c
	if (!ctx.cr6.eq) goto loc_82501C2C;
	// li r11,2
	ctx.r11.s64 = 2;
loc_82501BC0:
	// stw r11,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r11.u32);
	// b 0x82501c2c
	goto loc_82501C2C;
loc_82501BC8:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// addi r10,r10,-6412
	ctx.r10.s64 = ctx.r10.s64 + -6412;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f12,1908(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1908);
	ctx.f12.f64 = double(temp.f32);
	// stb r28,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r28.u8);
	// lfs f13,528(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 528);
	ctx.f13.f64 = double(temp.f32);
	// stw r28,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r28.u32);
	// lfs f0,32440(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 32440);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r31,336
	ctx.r3.s64 = ctx.r31.s64 + 336;
	// lfs f11,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,296(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x82501de8
	ctx.lr = 0x82501C18;
	sub_82501DE8(ctx, base);
	// lwz r11,332(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r10.u32);
	// stw r11,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
loc_82501C2C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82511330) {
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
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r4,296(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 296);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82511360;
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
	ctx.lr = 0x8251137C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r11,r11,11676
	ctx.r11.s64 = ctx.r11.s64 + 11676;
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f1,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lbz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x8224a2a0
	ctx.lr = 0x825113B4;
	sub_8224A2A0(ctx, base);
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

DEFINE_REX_FUNC(sub_82514848) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82514850;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825148fc
	if (ctx.cr6.eq) goto loc_825148FC;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825148f4
	if (ctx.cr6.eq) goto loc_825148F4;
	// li r28,0
	ctx.r28.s64 = 0;
loc_82514878:
	// lwz r31,8(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825148b0
	if (ctx.cr6.eq) goto loc_825148B0;
	// bl 0x82249308
	ctx.lr = 0x8251488C;
	sub_82249308(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825148ac
	if (ctx.cr6.eq) goto loc_825148AC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825148AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825148AC:
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
loc_825148B0:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825148e4
	if (ctx.cr6.eq) goto loc_825148E4;
	// bl 0x82249308
	ctx.lr = 0x825148C0;
	sub_82249308(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825148e0
	if (ctx.cr6.eq) goto loc_825148E0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825148E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825148E0:
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
loc_825148E4:
	// lwz r30,0(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82514878
	if (!ctx.cr6.eq) goto loc_82514878;
loc_825148F4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82524ba8
	ctx.lr = 0x825148FC;
	sub_82524BA8(ctx, base);
loc_825148FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8251A4D8) {
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
	// bl 0x82468f80
	ctx.lr = 0x8251A4F0;
	sub_82468F80(ctx, base);
	// lbz r11,23(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 23);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8251a574
	if (!ctx.cr0.eq) goto loc_8251A574;
	// lbz r11,305(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 305);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8251a574
	if (!ctx.cr0.eq) goto loc_8251A574;
	// lwz r11,360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8251a564
	if (!ctx.cr6.eq) goto loc_8251A564;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8251ab60
	ctx.lr = 0x8251A51C;
	sub_8251AB60(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x8251a544
	if (ctx.cr6.eq) goto loc_8251A544;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8251a53c
	if (ctx.cr6.eq) goto loc_8251A53C;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x8251a54c
	if (!ctx.cr6.eq) goto loc_8251A54C;
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x8251a548
	goto loc_8251A548;
loc_8251A53C:
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x8251a548
	goto loc_8251A548;
loc_8251A544:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8251A548:
	// stw r11,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
loc_8251A54C:
	// lwz r11,360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8251a564
	if (ctx.cr6.eq) goto loc_8251A564;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
loc_8251A564:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// stw r11,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// stw r10,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r10.u32);
loc_8251A574:
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

DEFINE_REX_FUNC(sub_8251F080) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r4,r11,-4132
	ctx.r4.s64 = ctx.r11.s64 + -4132;
	// b 0x8246a4b8
	sub_8246A4B8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82520070) {
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
	// lwz r11,324(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 324);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,-3936
	ctx.r10.s64 = ctx.r10.s64 + -3936;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222c98
	ctx.lr = 0x825200A0;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825200b8
	if (ctx.cr0.eq) goto loc_825200B8;
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x825200B8;
	sub_82222BB0(ctx, base);
loc_825200B8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82469fb0
	ctx.lr = 0x825200C0;
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
	ctx.lr = 0x825200D4;
	sub_82469EE8(ctx, base);
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

DEFINE_REX_FUNC(sub_82522088) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82522090;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,-12860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -12860);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825220c0
	if (ctx.cr6.eq) goto loc_825220C0;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-3636
	ctx.r4.s64 = ctx.r11.s64 + -3636;
	// addi r5,r31,368
	ctx.r5.s64 = ctx.r31.s64 + 368;
	// bl 0x8246cfe0
	ctx.lr = 0x825220BC;
	sub_8246CFE0(ctx, base);
	// b 0x825220c4
	goto loc_825220C4;
loc_825220C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825220C4:
	// stw r3,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r3.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x825220d8
	if (!ctx.cr6.eq) goto loc_825220D8;
	// stb r29,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r29.u8);
loc_825220D8:
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r3,r11,3204
	ctx.r3.s64 = ctx.r11.s64 + 3204;
	// lwz r11,-15508(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825220F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x825220F8;
	sub_8245A220(ctx, base);
	// stw r3,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r3.u32);
	// lwz r11,-15508(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -15508);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r3,r10,1368
	ctx.r3.s64 = ctx.r10.s64 + 1368;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82522114;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x82522118;
	sub_8245A220(ctx, base);
	// stw r3,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r3.u32);
	// stb r29,332(r31)
	REX_STORE_U8(ctx.r31.u32 + 332, ctx.r29.u8);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,88
	ctx.r4.s64 = 88;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82522138;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8252214c
	if (ctx.cr0.eq) goto loc_8252214C;
	// bl 0x82524158
	ctx.lr = 0x82522144;
	sub_82524158(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82522150
	goto loc_82522150;
loc_8252214C:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82522150:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82522190
	if (ctx.cr6.eq) goto loc_82522190;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82522164;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82522190
	if (!ctx.cr6.eq) goto loc_82522190;
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
	ctx.lr = 0x82522190;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82522190:
	// stb r29,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r29.u8);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x825221A0;
	sub_825F8D38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x825221c8
	if (ctx.cr0.eq) goto loc_825221C8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8b88
	ctx.lr = 0x825221B0;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x825221C4;
	sub_825F8BF8(ctx, base);
	// b 0x825221cc
	goto loc_825221CC;
loc_825221C8:
	// li r30,0
	ctx.r30.s64 = 0;
loc_825221CC:
	// stw r30,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r30.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x825221DC;
	sub_825F8D38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82522204
	if (ctx.cr0.eq) goto loc_82522204;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8b88
	ctx.lr = 0x825221EC;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,26
	ctx.r5.s64 = 26;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x82522200;
	sub_825F8BF8(ctx, base);
	// b 0x82522208
	goto loc_82522208;
loc_82522204:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82522208:
	// stw r30,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r30.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x82522218;
	sub_825F8D38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82522240
	if (ctx.cr0.eq) goto loc_82522240;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8b88
	ctx.lr = 0x82522228;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,26
	ctx.r5.s64 = 26;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x8252223C;
	sub_825F8BF8(ctx, base);
	// b 0x82522244
	goto loc_82522244;
loc_82522240:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82522244:
	// stw r30,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8252BE38) {
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
	// lwz r9,140(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
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
	// lfs f13,2448(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2448);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11984(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -11984);
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
	ctx.lr = 0x8252BE9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8252BEB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r11.u8);
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

DEFINE_REX_FUNC(sub_8252F6C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8252F6C8;
	__savegprlr_26(ctx, base);
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// clrlwi r26,r7,24
	ctx.r26.u64 = ctx.r7.u32 & 0xFF;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// addi r4,r10,-9444
	ctx.r4.s64 = ctx.r10.s64 + -9444;
	// li r8,10
	ctx.r8.s64 = 10;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x8252F70C;
	sub_825190E8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r8,r11,-1496
	ctx.r8.s64 = ctx.r11.s64 + -1496;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stw r11,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r11.u32);
	// addi r10,r10,12472
	ctx.r10.s64 = ctx.r10.s64 + 12472;
	// stw r11,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r11.u32);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// stb r27,328(r31)
	REX_STORE_U8(ctx.r31.u32 + 328, ctx.r27.u8);
	// addi r9,r9,-4080
	ctx.r9.s64 = ctx.r9.s64 + -4080;
	// stb r26,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r26.u8);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f0,1128(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1128);
	ctx.f0.f64 = double(temp.f32);
	// li r29,0
	ctx.r29.s64 = 0;
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfs f31,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f31.f64 = double(temp.f32);
	// stw r29,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r29.u32);
	// lfs f13,-28808(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -28808);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f12,-29492(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -29492);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f11,1924(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1924);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f31,292(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stfs f31,296(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stfs f13,312(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stfs f12,304(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// lfs f0,-11492(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11492);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stfs f11,316(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
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
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,320(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// lfs f0,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,324(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// lbz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 328);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8252f7f0
	if (ctx.cr0.eq) goto loc_8252F7F0;
	// lfs f30,-236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -236);
	ctx.f30.f64 = double(temp.f32);
	// b 0x8252f7f4
	goto loc_8252F7F4;
loc_8252F7F0:
	// lfs f30,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
loc_8252F7F4:
	// lfs f1,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82738cc0
	ctx.lr = 0x8252F7FC;
	sub_82738CC0(ctx, base);
	// lfs f0,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// lfs f1,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82738be0
	ctx.lr = 0x8252F818;
	sub_82738BE0(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,320(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f0,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,312(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stb r29,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r29.u8);
	// stfs f31,332(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 332, temp.u32);
	// stb r7,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r7.u8);
	// stb r30,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r30.u8);
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r10.u64);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-72(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825402C0) {
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
	// lhz r11,6(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,140(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// lfs f13,-9532(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -9532);
	ctx.f13.f64 = double(temp.f32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// bctrl 
	ctx.lr = 0x8254031C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82540338;
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
	ctx.lr = 0x82540354;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82540384
	if (!ctx.cr6.gt) goto loc_82540384;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
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
	ctx.lr = 0x82540384;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82540384:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r10,r10,-32416
	ctx.r10.s64 = ctx.r10.s64 + -32416;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f0,1608(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1608);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r30,r11,1608
	ctx.r30.s64 = ctx.r11.s64 + 1608;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825403F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r9,312(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// addi r11,r30,2256
	ctx.r11.s64 = ctx.r30.s64 + 2256;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lbzx r4,r11,r9
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,108(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8254041C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,312(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// addi r11,r30,2260
	ctx.r11.s64 = ctx.r30.s64 + 2260;
	// lfs f0,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,76(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r10,r11
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f0,196(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 196, temp.u32);
	// lfsx f0,r10,r11
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// lfsx f0,r10,r11
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// stfs f0,76(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// stb r9,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r9.u8);
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

DEFINE_REX_FUNC(sub_8254B478) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8254B480;
	__savegprlr_25(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// fmr f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8254b768
	if (!ctx.cr0.eq) goto loc_8254B768;
	// lwz r11,344(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 344);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8254b4b0
	if (ctx.cr6.lt) goto loc_8254B4B0;
	// bne cr6,0x8254b768
	if (!ctx.cr6.eq) goto loc_8254B768;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
	// b 0x8254b768
	goto loc_8254B768;
loc_8254B4B0:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,292(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r11,1612
	ctx.r30.s64 = ctx.r11.s64 + 1612;
	// lfs f0,-76(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -76);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8254b750
	if (!ctx.cr6.lt) goto loc_8254B750;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r10,12236
	ctx.r9.s64 = ctx.r10.s64 + 12236;
	// lfs f0,17984(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17984);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f12,12236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12236);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8254b4f4
	if (!ctx.cr6.lt) goto loc_8254B4F4;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8254b500
	goto loc_8254B500;
loc_8254B4F4:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8254b500
	if (!ctx.cr6.gt) goto loc_8254B500;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8254B500:
	// li r27,20
	ctx.r27.s64 = 20;
	// addi r10,r1,268
	ctx.r10.s64 = ctx.r1.s64 + 268;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_8254B514:
	// li r9,10
	ctx.r9.s64 = 10;
	// addi r8,r30,-72
	ctx.r8.s64 = ctx.r30.s64 + -72;
	// divw r9,r11,r9
	ctx.r9.u64 = uint32_t((ctx.r9.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r11.s32 / ctx.r9.s32 : 0);
	// mulli r9,r9,10
	ctx.r9.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(10));
	// subf r9,r9,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfsu f13,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8254b514
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8254B514;
	// fsubs f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r9,-4080
	ctx.r9.s64 = ctx.r9.s64 + -4080;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r28,r10,12432
	ctx.r28.s64 = ctx.r10.s64 + 12432;
	// lfs f5,236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 236);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f9
	ctx.f8.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f9.f64)));
loc_8254B564:
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// stfs f8,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// divw r10,r11,r27
	ctx.r10.u64 = uint32_t((ctx.r27.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r11.s32 / ctx.r27.s32 : 0);
	// stfs f8,184(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// divw r9,r29,r27
	ctx.r9.u64 = uint32_t((ctx.r27.s32 && !(ctx.r29.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r29.s32 / ctx.r27.s32 : 0);
	// stfs f8,180(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// mulli r10,r10,20
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(20));
	// stfs f8,176(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f9,92(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f9,88(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mulli r9,r9,20
	ctx.r9.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(20));
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r10,r9,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r9.u64;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r10,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,272
	ctx.r11.s64 = ctx.r1.s64 + 272;
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// addi r7,r30,-32
	ctx.r7.s64 = ctx.r30.s64 + -32;
	// mulli r6,r5,12
	ctx.r6.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(12));
	// lfsx f7,r4,r11
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f6,r31,r10
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f6.f64 = double(temp.f32);
loc_8254B5C0:
	// lfsx f3,r4,r28
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + ctx.r28.u32);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fadds f1,f3,f5
	ctx.f1.f64 = double(float(ctx.f3.f64 + ctx.f5.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x8254B5D0;
	sub_822EA1A8(ctx, base);
	// fmuls f0,f1,f2
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// fmuls f3,f0,f7
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f7.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x8254B5E0;
	sub_822EA1A8(ctx, base);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f3,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stfs f3,168(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f3,164(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmuls f0,f1,f2
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// stfs f3,160(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r26,r1,208
	ctx.r26.s64 = ctx.r1.s64 + 208;
	// stfs f8,204(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f8,200(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f8,196(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lwz r25,332(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 332);
	// stfs f8,192(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// fmuls f0,f0,f7
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f7.f64));
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
	// stvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f0.f64 = double(temp.f32);
	// stfs f9,108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfsx f0,r6,r25
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + ctx.r25.u32, temp.u32);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// lwz r11,332(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 332);
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r6,12
	ctx.r6.s64 = ctx.r6.s64 + 12;
	// lfs f0,256(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lfsx f3,r31,r28
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	ctx.f3.f64 = double(temp.f32);
	// fadds f1,f3,f5
	ctx.f1.f64 = double(float(ctx.f3.f64 + ctx.f5.f64));
	// lfs f2,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822ea1a8
	ctx.lr = 0x8254B694;
	sub_822EA1A8(ctx, base);
	// fmuls f0,f1,f2
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// fmuls f3,f0,f6
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f6.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x8254B6A4;
	sub_822EA1A8(ctx, base);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// fmuls f0,f1,f2
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f3,156(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f3,152(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// stfs f3,148(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lwz r26,332(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 332);
	// stfs f3,144(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r11,r30,-32
	ctx.r11.s64 = ctx.r30.s64 + -32;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,224(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f6
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f6.f64));
	// stfsx f13,r6,r26
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + ctx.r26.u32, temp.u32);
	// lwz r11,332(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 332);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// cmpw cr6,r7,r10
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, ctx.xer);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// addi r6,r6,12
	ctx.r6.s64 = ctx.r6.s64 + 12;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// blt cr6,0x8254b5c0
	if (ctx.cr6.lt) goto loc_8254B5C0;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,20
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 20, ctx.xer);
	// blt cr6,0x8254b564
	if (ctx.cr6.lt) goto loc_8254B564;
	// lfs f0,292(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f4,f0
	ctx.f0.f64 = double(float(ctx.f4.f64 + ctx.f0.f64));
	// b 0x8254b764
	goto loc_8254B764;
loc_8254B750:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// stw r10,344(r3)
	REX_STORE_U32(ctx.r3.u32 + 344, ctx.r10.u32);
	// lfs f0,232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
loc_8254B764:
	// stfs f0,292(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 292, temp.u32);
loc_8254B768:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825617D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x825617E0;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,296(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 296);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r28,r11,14280
	ctx.r28.s64 = ctx.r11.s64 + 14280;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f0,-2044(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -2044);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,312(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 312, temp.u32);
	// bne cr6,0x82561814
	if (!ctx.cr6.eq) goto loc_82561814;
	// lfs f0,-1808(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1808);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,312(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 312, temp.u32);
loc_82561814:
	// lwz r11,332(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82561984
	if (ctx.cr6.lt) goto loc_82561984;
	// beq cr6,0x82561914
	if (ctx.cr6.eq) goto loc_82561914;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8256184c
	if (ctx.cr6.lt) goto loc_8256184C;
	// bne cr6,0x82561b74
	if (!ctx.cr6.eq) goto loc_82561B74;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82563620
	ctx.lr = 0x82561838;
	sub_82563620(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x825618e8
	if (ctx.cr0.eq) goto loc_825618E8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x825618e8
	goto loc_825618E8;
loc_8256184C:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,160(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256186C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x825618b0
	if (!ctx.cr6.eq) goto loc_825618B0;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r10,74(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 74);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x825618b0
	if (!ctx.cr0.eq) goto loc_825618B0;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r5,-16
	ctx.r5.s64 = -16;
	// stw r10,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,160(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825618B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825618B0:
	// lbz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 304);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825618c8
	if (!ctx.cr0.eq) goto loc_825618C8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,328(r31)
	REX_STORE_U8(ctx.r31.u32 + 328, ctx.r11.u8);
	// stb r11,304(r31)
	REX_STORE_U8(ctx.r31.u32 + 304, ctx.r11.u8);
loc_825618C8:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825618E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82561b74
	if (ctx.cr0.eq) goto loc_82561B74;
loc_825618E8:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r11,74(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82561b74
	if (!ctx.cr0.eq) goto loc_82561B74;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82561910;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82561b74
	goto loc_82561B74;
loc_82561914:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82561b90
	ctx.lr = 0x8256191C;
	sub_82561B90(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82561b74
	if (ctx.cr0.eq) goto loc_82561B74;
	// li r11,2
	ctx.r11.s64 = 2;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82561948;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r10,r10,-10848
	ctx.r10.s64 = ctx.r10.s64 + -10848;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f1,29228(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 29228);
	ctx.f1.f64 = double(temp.f32);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,76(r10)
	REX_STORE_U32(ctx.r10.u32 + 76, ctx.r11.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x82561980;
	sub_8224A2A0(ctx, base);
	// b 0x82561b74
	goto loc_82561B74;
loc_82561984:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r5,-16
	ctx.r5.s64 = -16;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,160(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825619A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f13,284(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 284);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r10,-31744
	ctx.r10.s64 = ctx.r10.s64 + -31744;
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
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,280(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,-64
	ctx.r30.s64 = -64;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lwz r10,316(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// mulli r10,r10,12
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(12));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,312(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subfic r11,r10,32
	ctx.xer.ca = ctx.r10.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r10.u64;
	// lfs f6,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,-1812(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1812);
	ctx.f4.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f6,48(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwz r29,-13032(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,44(r31)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
loc_82561A64:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82561aac
	if (ctx.cr6.eq) goto loc_82561AAC;
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// fctiwz f0,f5
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f0,f0,f6
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f6.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aebd8
	ctx.lr = 0x82561AAC;
	sub_823AEBD8(ctx, base);
loc_82561AAC:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcmpu cr6,f0,f4
	ctx.cr6.compare(ctx.f0.f64, ctx.f4.f64);
	// blt cr6,0x82561ae0
	if (ctx.cr6.lt) goto loc_82561AE0;
	// cmpwi cr6,r30,63
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 63, ctx.xer);
	// bge cr6,0x82561b0c
	if (!ctx.cr6.lt) goto loc_82561B0C;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,64
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 64, ctx.xer);
	// blt cr6,0x82561a64
	if (ctx.cr6.lt) goto loc_82561A64;
	// b 0x82561b28
	goto loc_82561B28;
loc_82561AE0:
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r10,-10848
	ctx.r11.s64 = ctx.r10.s64 + -10848;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,1892(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1892);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f6.f64));
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// b 0x82561b24
	goto loc_82561B24;
loc_82561B0C:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r10,r11,-10848
	ctx.r10.s64 = ctx.r11.s64 + -10848;
	// lfs f13,-10848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1892(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1892);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f6,f0
	ctx.f0.f64 = double(float(ctx.f6.f64 - ctx.f0.f64));
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
loc_82561B24:
	// stfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
loc_82561B28:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f0,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 288);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,288(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r27,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r27.u32);
	// lwa r11,316(r31)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r31.u32 + 316));
	// lfs f13,288(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 288);
	ctx.f13.f64 = double(temp.f32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// stw r27,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r27.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82561b74
	if (ctx.cr6.lt) goto loc_82561B74;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
loc_82561B74:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8257AD48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8257AD50;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmplw cr6,r4,r3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8257ade0
	if (ctx.cr6.eq) goto loc_8257ADE0;
	// lwz r28,4(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r27,4(r4)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r31,0(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r6,0(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// b 0x8257adb8
	goto loc_8257ADB8;
loc_8257AD78:
	// cmplw cr6,r6,r27
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8257ade0
	if (ctx.cr6.eq) goto loc_8257ADE0;
	// lwz r11,8(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8257adb4
	if (!ctx.cr6.lt) goto loc_8257ADB4;
	// lwz r30,0(r6)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8257ade8
	ctx.lr = 0x8257ADAC;
	sub_8257ADE8(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// b 0x8257adb8
	goto loc_8257ADB8;
loc_8257ADB4:
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_8257ADB8:
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x8257ad78
	if (!ctx.cr6.eq) goto loc_8257AD78;
	// cmplw cr6,r6,r27
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8257ade0
	if (ctx.cr6.eq) goto loc_8257ADE0;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// lwz r8,8(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8257ade8
	ctx.lr = 0x8257ADE0;
	sub_8257ADE8(ctx, base);
loc_8257ADE0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8257E298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8257E2A0;
	__savegprlr_23(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8257e7ac
	if (ctx.cr6.lt) goto loc_8257E7AC;
	// beq cr6,0x8257e6b8
	if (ctx.cr6.eq) goto loc_8257E6B8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8257e324
	if (ctx.cr6.eq) goto loc_8257E324;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x8257e86c
	if (!ctx.cr6.eq) goto loc_8257E86C;
	// lwz r3,64(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8257e2dc
	if (ctx.cr6.eq) goto loc_8257E2DC;
	// bl 0x825e0378
	ctx.lr = 0x8257E2DC;
	sub_825E0378(ctx, base);
loc_8257E2DC:
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r29,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8257e304
	if (ctx.cr6.eq) goto loc_8257E304;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8257e304
	if (ctx.cr6.eq) goto loc_8257E304;
	// bl 0x82639838
	ctx.lr = 0x8257E2FC;
	sub_82639838(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
loc_8257E304:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,36
	ctx.r10.s64 = 36;
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// divw r11,r11,r10
	ctx.r11.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stb r29,48(r30)
	REX_STORE_U8(ctx.r30.u32 + 48, ctx.r29.u8);
	// b 0x8257e86c
	goto loc_8257E86C;
loc_8257E324:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// addi r24,r30,20
	ctx.r24.s64 = ctx.r30.s64 + 20;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x8257e86c
	if (ctx.cr6.eq) goto loc_8257E86C;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82639e80
	ctx.lr = 0x8257E34C;
	sub_82639E80(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x8257e388
	if (ctx.cr0.eq) goto loc_8257E388;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82639f18
	ctx.lr = 0x8257E35C;
	sub_82639F18(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8257e370
	if (ctx.cr0.eq) goto loc_8257E370;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82639f18
	ctx.lr = 0x8257E36C;
	sub_82639F18(ctx, base);
	// clrlwi r28,r3,16
	ctx.r28.u64 = ctx.r3.u32 & 0xFFFF;
loc_8257E370:
	// stw r28,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r28.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// addi r3,r31,204
	ctx.r3.s64 = ctx.r31.s64 + 204;
	// bl 0x82396cc8
	ctx.lr = 0x8257E384;
	sub_82396CC8(ctx, base);
	// b 0x8257e864
	goto loc_8257E864;
loc_8257E388:
	// stw r29,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r29.u32);
	// addi r25,r30,64
	ctx.r25.s64 = ctx.r30.s64 + 64;
	// stw r29,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r29.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r29,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r29.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8263a4c0
	ctx.lr = 0x8257E3A8;
	sub_8263A4C0(ctx, base);
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// lwz r10,64(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// li r5,0
	ctx.r5.s64 = 0;
	// mulli r11,r11,308
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(308));
	// stw r29,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r29.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// stw r11,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r11.u32);
	// stw r29,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r29.u32);
	// bl 0x8257e878
	ctx.lr = 0x8257E3D4;
	sub_8257E878(ctx, base);
	// li r23,1
	ctx.r23.s64 = 1;
	// lwz r28,176(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8257e570
	if (ctx.cr6.eq) goto loc_8257E570;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8257fae8
	ctx.lr = 0x8257E3F0;
	sub_8257FAE8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8257e564
	if (!ctx.cr0.eq) goto loc_8257E564;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r26,36
	ctx.r26.s64 = 36;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// addi r4,r31,16
	ctx.r4.s64 = ctx.r31.s64 + 16;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// divw r11,r11,r26
	ctx.r11.u64 = uint32_t((ctx.r26.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r26.s32 == -1)) ? ctx.r11.s32 / ctx.r26.s32 : 0);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// bl 0x8258af80
	ctx.lr = 0x8257E424;
	sub_8258AF80(ctx, base);
	// lwz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// ld r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 48);
	// slw r10,r23,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r23.u32 << (ctx.r11.u8 & 0x3F));
	// lwz r8,152(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm. r9,r8,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r10,48(r31)
	REX_STORE_U64(ctx.r31.u32 + 48, ctx.r10.u64);
	// beq 0x8257e4f0
	if (ctx.cr0.eq) goto loc_8257E4F0;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// clrlwi r28,r11,24
	ctx.r28.u64 = ctx.r11.u32 & 0xFF;
	// lwz r11,-12836(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -12836);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257e48c
	if (ctx.cr6.eq) goto loc_8257E48C;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// clrlwi r9,r28,24
	ctx.r9.u64 = ctx.r28.u32 & 0xFF;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8257e48c
	if (!ctx.cr6.lt) goto loc_8257E48C;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x8257e490
	goto loc_8257E490;
loc_8257E48C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8257E490:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257e4f0
	if (!ctx.cr0.eq) goto loc_8257E4F0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82238f48
	ctx.lr = 0x8257E4A4;
	sub_82238F48(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r4,r11,13256
	ctx.r4.s64 = ctx.r11.s64 + 13256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x822390c0
	ctx.lr = 0x8257E4B8;
	sub_822390C0(ctx, base);
	// lwz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8257e4cc
	if (!ctx.cr6.lt) goto loc_8257E4CC;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
loc_8257E4CC:
	// lwz r11,-12836(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -12836);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257e4e0
	if (ctx.cr6.eq) goto loc_8257E4E0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825976d8
	ctx.lr = 0x8257E4E0;
	sub_825976D8(ctx, base);
loc_8257E4E0:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235ec48
	ctx.lr = 0x8257E4F0;
	sub_8235EC48(ctx, base);
loc_8257E4F0:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8257e504
	if (!ctx.cr6.eq) goto loc_8257E504;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x8257e510
	goto loc_8257E510;
loc_8257E504:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r26
	ctx.r11.u64 = uint32_t((ctx.r26.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r26.s32 == -1)) ? ctx.r11.s32 / ctx.r26.s32 : 0);
loc_8257E510:
	// lwz r28,8(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r10,r10,r28
	ctx.r10.u64 = ctx.r28.u64 - ctx.r10.u64;
	// divw r10,r10,r26
	ctx.r10.u64 = uint32_t((ctx.r26.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r26.s32 == -1)) ? ctx.r10.s32 / ctx.r26.s32 : 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8257e544
	if (!ctx.cr6.lt) goto loc_8257E544;
	// cmplwi r28,0
	ctx.cr0.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq 0x8257e538
	if (ctx.cr0.eq) goto loc_8257E538;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825803d8
	ctx.lr = 0x8257E538;
	sub_825803D8(ctx, base);
loc_8257E538:
	// addi r11,r28,36
	ctx.r11.s64 = ctx.r28.s64 + 36;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x8257e554
	goto loc_8257E554;
loc_8257E544:
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82580070
	ctx.lr = 0x8257E554;
	sub_82580070(ctx, base);
loc_8257E554:
	// lwz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,56(r30)
	REX_STORE_U32(ctx.r30.u32 + 56, ctx.r11.u32);
	// b 0x8257e570
	goto loc_8257E570;
loc_8257E564:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82639d68
	ctx.lr = 0x8257E570;
	sub_82639D68(ctx, base);
loc_8257E570:
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// li r5,28
	ctx.r5.s64 = 28;
	// lwz r10,60(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r28,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r28.u32);
	// cmplw cr6,r28,r10
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8257e610
	if (ctx.cr6.lt) goto loc_8257E610;
	// bl 0x82639688
	ctx.lr = 0x8257E598;
	sub_82639688(ctx, base);
	// lwz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8257e5a8
	if (ctx.cr6.eq) goto loc_8257E5A8;
	// bl 0x825e0378
	ctx.lr = 0x8257E5A8;
	sub_825E0378(ctx, base);
loc_8257E5A8:
	// stw r29,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,12(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8257E5C4;
	sub_825E02A0(ctx, base);
	// stw r3,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r3.u32);
	// stw r29,60(r30)
	REX_STORE_U32(ctx.r30.u32 + 60, ctx.r29.u32);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// stw r29,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r29.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,12(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r4,64(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x8263a878
	ctx.lr = 0x8257E5E8;
	sub_8263A878(ctx, base);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8257e608
	if (ctx.cr6.eq) goto loc_8257E608;
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// addi r3,r31,204
	ctx.r3.s64 = ctx.r31.s64 + 204;
	// bl 0x82396cc8
	ctx.lr = 0x8257E608;
	sub_82396CC8(ctx, base);
loc_8257E608:
	// stw r23,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r23.u32);
	// b 0x8257e690
	goto loc_8257E690;
loc_8257E610:
	// lwz r27,56(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// bl 0x82639688
	ctx.lr = 0x8257E618;
	sub_82639688(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r5,r11,13252
	ctx.r5.s64 = ctx.r11.s64 + 13252;
	// addi r4,r10,13268
	ctx.r4.s64 = ctx.r10.s64 + 13268;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82738a28
	ctx.lr = 0x8257E634;
	sub_82738A28(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// mulli r10,r28,308
	ctx.r10.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(308));
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r3,254
	ctx.r3.s64 = 254;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x82639e18
	ctx.lr = 0x8257E65C;
	sub_82639E18(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x825e0d50
	ctx.lr = 0x8257E664;
	sub_825E0D50(ctx, base);
	// stw r3,72(r30)
	REX_STORE_U32(ctx.r30.u32 + 72, ctx.r3.u32);
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// cmplwi cr6,r28,997
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 997, ctx.xer);
	// beq cr6,0x8257e688
	if (ctx.cr6.eq) goto loc_8257E688;
	// stw r28,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r28.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// addi r3,r31,204
	ctx.r3.s64 = ctx.r31.s64 + 204;
	// bl 0x82396cc8
	ctx.lr = 0x8257E688;
	sub_82396CC8(ctx, base);
loc_8257E688:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
loc_8257E690:
	// lwz r3,164(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8257e86c
	if (ctx.cr6.eq) goto loc_8257E86C;
	// lwz r4,168(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// bl 0x8257fce8
	ctx.lr = 0x8257E6A4;
	sub_8257FCE8(ctx, base);
	// lwz r3,164(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8257e86c
	if (ctx.cr6.eq) goto loc_8257E86C;
	// bl 0x825e0378
	ctx.lr = 0x8257E6B4;
	sub_825E0378(ctx, base);
	// b 0x8257e86c
	goto loc_8257E86C;
loc_8257E6B8:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// addi r28,r30,20
	ctx.r28.s64 = ctx.r30.s64 + 20;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x8257e86c
	if (ctx.cr6.eq) goto loc_8257E86C;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82639e80
	ctx.lr = 0x8257E6D8;
	sub_82639E80(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x8257e718
	if (ctx.cr0.eq) goto loc_8257E718;
	// cmplwi cr6,r29,18
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 18, ctx.xer);
	// beq cr6,0x8257e710
	if (ctx.cr6.eq) goto loc_8257E710;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82639f18
	ctx.lr = 0x8257E6F0;
	sub_82639F18(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8257e704
	if (ctx.cr0.eq) goto loc_8257E704;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82639f18
	ctx.lr = 0x8257E700;
	sub_82639F18(ctx, base);
	// clrlwi r29,r3,16
	ctx.r29.u64 = ctx.r3.u32 & 0xFFFF;
loc_8257E704:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r29,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r29.u32);
	// b 0x8257e868
	goto loc_8257E868;
loc_8257E710:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
loc_8257E718:
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,60(r30)
	REX_STORE_U32(ctx.r30.u32 + 60, ctx.r11.u32);
	// bne cr6,0x8257e730
	if (!ctx.cr6.eq) goto loc_8257E730;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x8257e868
	goto loc_8257E868;
loc_8257E730:
	// li r5,28
	ctx.r5.s64 = 28;
	// lwz r27,52(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r26,56(r30)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82639688
	ctx.lr = 0x8257E748;
	sub_82639688(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r29,r30,64
	ctx.r29.s64 = ctx.r30.s64 + 64;
	// addi r5,r11,13252
	ctx.r5.s64 = ctx.r11.s64 + 13252;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r10,13268
	ctx.r4.s64 = ctx.r10.s64 + 13268;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// bl 0x82738a28
	ctx.lr = 0x8257E768;
	sub_82738A28(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// mulli r10,r27,308
	ctx.r10.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(308));
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,254
	ctx.r3.s64 = 254;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x82639e18
	ctx.lr = 0x8257E790;
	sub_82639E18(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x825e0d50
	ctx.lr = 0x8257E798;
	sub_825E0D50(ctx, base);
	// stw r3,72(r30)
	REX_STORE_U32(ctx.r30.u32 + 72, ctx.r3.u32);
	// cmplwi cr6,r29,997
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 997, ctx.xer);
	// bne cr6,0x8257e704
	if (!ctx.cr6.eq) goto loc_8257E704;
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x8257e868
	goto loc_8257E868;
loc_8257E7AC:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r26,r30,8
	ctx.r26.s64 = ctx.r30.s64 + 8;
	// stw r29,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r29.u32);
	// addi r28,r30,12
	ctx.r28.s64 = ctx.r30.s64 + 12;
	// stw r29,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r29.u32);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// std r29,48(r31)
	REX_STORE_U64(ctx.r31.u32 + 48, ctx.r29.u64);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,254
	ctx.r3.s64 = 254;
	// bl 0x82639d80
	ctx.lr = 0x8257E7E4;
	sub_82639D80(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8257e7f8
	if (ctx.cr0.eq) goto loc_8257E7F8;
loc_8257E7EC:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// b 0x8257e868
	goto loc_8257E868;
loc_8257E7F8:
	// addi r27,r30,20
	ctx.r27.s64 = ctx.r30.s64 + 20;
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82639688
	ctx.lr = 0x8257E80C;
	sub_82639688(ctx, base);
	// lwz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8257e81c
	if (ctx.cr6.eq) goto loc_8257E81C;
	// bl 0x825e0378
	ctx.lr = 0x8257E81C;
	sub_825E0378(ctx, base);
loc_8257E81C:
	// stw r29,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r4,0(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x825e02a0
	ctx.lr = 0x8257E838;
	sub_825E02A0(ctx, base);
	// stw r3,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r3.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r29,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r29.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r29,60(r30)
	REX_STORE_U32(ctx.r30.u32 + 60, ctx.r29.u32);
	// lwz r3,0(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r4,64(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x8263a878
	ctx.lr = 0x8257E85C;
	sub_8263A878(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x8257e7ec
	if (!ctx.cr6.eq) goto loc_8257E7EC;
loc_8257E864:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8257E868:
	// stw r11,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
loc_8257E86C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825A3358) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825A3360;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,76(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r28,r3,48
	ctx.r28.s64 = ctx.r3.s64 + 48;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825a3380
	if (ctx.cr0.eq) goto loc_825A3380;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b44
	ctx.lr = 0x825A3380;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_825A3380:
	// lwz r11,220(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// addi r29,r31,212
	ctx.r29.s64 = ctx.r31.s64 + 212;
	// lwz r10,216(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825a33a0
	if (ctx.cr0.eq) goto loc_825A33A0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,128(r31)
	REX_STORE_U8(ctx.r31.u32 + 128, ctx.r11.u8);
loc_825A33A0:
	// lwz r30,216(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// b 0x825a3450
	goto loc_825A3450;
loc_825A33A8:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,172(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825a344c
	if (!ctx.cr6.eq) goto loc_825A344C;
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x825a344c
	if (ctx.cr6.eq) goto loc_825A344C;
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825a33ec
	if (ctx.cr6.eq) goto loc_825A33EC;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x825a33f0
	goto loc_825A33F0;
loc_825A33EC:
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
loc_825A33F0:
	// lwz r6,200(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// addi r4,r31,196
	ctx.r4.s64 = ctx.r31.s64 + 196;
	// lwz r10,16(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// lwz r11,4(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// b 0x825a3434
	goto loc_825A3434;
loc_825A3410:
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// subfc r9,r9,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r9.u32;
	ctx.r9.u64 = ctx.r10.u64 - ctx.r9.u64;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi. r5,r9,31
	ctx.r5.u64 = ctx.r9.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq 0x825a3430
	if (ctx.cr0.eq) goto loc_825A3430;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x825a3434
	goto loc_825A3434;
loc_825A3430:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
loc_825A3434:
	// lbz r9,21(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x825a3410
	if (ctx.cr0.eq) goto loc_825A3410;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825a1fd0
	ctx.lr = 0x825A344C;
	sub_825A1FD0(ctx, base);
loc_825A344C:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
loc_825A3450:
	// lwz r11,220(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825a33a8
	if (!ctx.cr6.eq) goto loc_825A33A8;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r5,8(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x825a348c
	if (ctx.cr6.eq) goto loc_825A348C;
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
	// ble 0x825a3488
	if (!ctx.cr0.gt) goto loc_825A3488;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x825A3488;
	sub_827388E8(ctx, base);
loc_825A3488:
	// stw r31,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
loc_825A348C:
	// lbz r11,28(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825a34a0
	if (ctx.cr0.eq) goto loc_825A34A0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b34
	ctx.lr = 0x825A34A0;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_825A34A0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825ACB80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825ACB88;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r7,r11,12236
	ctx.r7.s64 = ctx.r11.s64 + 12236;
	// addi r9,r9,25116
	ctx.r9.s64 = ctx.r9.s64 + 25116;
	// lfs f13,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32240
	ctx.r6.s64 = -2112880640;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r8,r8,17280
	ctx.r8.s64 = ctx.r8.s64 + 17280;
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// stb r11,13(r3)
	REX_STORE_U8(ctx.r3.u32 + 13, ctx.r11.u8);
	// lfs f0,232(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,14(r3)
	REX_STORE_U8(ctx.r3.u32 + 14, ctx.r11.u8);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stb r30,12(r3)
	REX_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// lfs f11,13780(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 13780);
	ctx.f11.f64 = double(temp.f32);
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// stw r30,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// mulli r4,r4,24
	ctx.r4.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(24));
	// stw r30,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// stw r30,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// stw r30,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r30.u32);
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f0,48(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stw r30,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r30.u32);
	// stfs f12,52(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stb r30,68(r3)
	REX_STORE_U8(ctx.r3.u32 + 68, ctx.r30.u8);
	// stfs f11,56(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stw r10,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// stfs f13,60(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f13,64(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// addi r11,r9,22072
	ctx.r11.s64 = ctx.r9.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r3,16
	ctx.r29.s64 = ctx.r3.s64 + 16;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x825ACC30;
	sub_825E02A0(ctx, base);
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// stw r3,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x825acc94
	if (!ctx.cr6.gt) goto loc_825ACC94;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_825ACC48:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r30,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r30.u32);
	// stb r30,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r30.u8);
	// lwz r8,4(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bne cr6,0x825acc74
	if (!ctx.cr6.eq) goto loc_825ACC74;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x825acc7c
	goto loc_825ACC7C;
loc_825ACC74:
	// lwz r8,4(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r11,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
loc_825ACC7C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x825acc48
	if (ctx.cr6.lt) goto loc_825ACC48;
loc_825ACC94:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B5648) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f30.u64);
	// stfd f31,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// fcmpu cr6,f1,f2
	ctx.cr6.compare(ctx.f1.f64, ctx.f2.f64);
	// bne cr6,0x825b5678
	if (!ctx.cr6.eq) goto loc_825B5678;
	// b 0x825b56b4
	goto loc_825B56B4;
loc_825B5678:
	// addi r3,r31,232
	ctx.r3.s64 = ctx.r31.s64 + 232;
	// bl 0x82748830
	ctx.lr = 0x825B5680;
	sub_82748830(ctx, base);
	// lwz r9,236(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// clrldi r10,r3,32
	ctx.r10.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// fsubs f0,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f31.f64));
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fdivs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 / ctx.f8.f64));
	// fmadds f1,f7,f0,f31
	ctx.f1.f64 = double(float(std::fma(ctx.f7.f64, ctx.f0.f64, ctx.f31.f64)));
loc_825B56B4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825B8390) {
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
	// lwz r11,472(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 472);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b83f0
	if (ctx.cr6.eq) goto loc_825B83F0;
	// clrlwi r9,r5,16
	ctx.r9.u64 = ctx.r5.u32 & 0xFFFF;
loc_825B83B8:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b83d0
	if (ctx.cr6.eq) goto loc_825B83D0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x825b83d4
	goto loc_825B83D4;
loc_825B83D0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_825B83D4:
	// lhz r7,8(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x825b83ec
	if (ctx.cr6.eq) goto loc_825B83EC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825b83b8
	if (!ctx.cr6.eq) goto loc_825B83B8;
	// b 0x825b83f0
	goto loc_825B83F0;
loc_825B83EC:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_825B83F0:
	// addi r4,r8,10
	ctx.r4.s64 = ctx.r8.s64 + 10;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x825B8400;
	sub_8273A030(ctx, base);
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

DEFINE_REX_FUNC(sub_825BB068) {
	REX_FUNC_PROLOGUE();
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// addi r3,r3,24
	ctx.r3.s64 = ctx.r3.s64 + 24;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_825BBB18) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// b 0x825b9e68
	sub_825B9E68(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825BBBE8) {
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
	ctx.lr = 0x825BBC0C;
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

DEFINE_REX_FUNC(sub_825BC9A8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// addi r3,r11,9
	ctx.r3.s64 = ctx.r11.s64 + 9;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825BD310) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x825BD318;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r26,r11,204
	ctx.r26.s64 = ctx.r11.s64 + 204;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82855b44
	ctx.lr = 0x825BD338;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r31,24(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825b5f98
	ctx.lr = 0x825BD350;
	sub_825B5F98(ctx, base);
	// addi r25,r31,204
	ctx.r25.s64 = ctx.r31.s64 + 204;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82855b44
	ctx.lr = 0x825BD35C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// addi r23,r31,88
	ctx.r23.s64 = ctx.r31.s64 + 88;
loc_825BD364:
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// beq cr6,0x825bd3e0
	if (ctx.cr6.eq) goto loc_825BD3E0;
	// clrlwi r10,r29,16
	ctx.r10.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r27,4(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r31,r11,-12
	ctx.r31.s64 = ctx.r11.s64 + -12;
	// cmplwi cr6,r10,65535
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65535, ctx.xer);
	// beq cr6,0x825bd38c
	if (ctx.cr6.eq) goto loc_825BD38C;
	// lhz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 316);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x825bd3d4
	if (!ctx.cr6.eq) goto loc_825BD3D4;
loc_825BD38C:
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825bd3d4
	if (!ctx.cr6.eq) goto loc_825BD3D4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BD3AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r9,r3,0,26,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x30;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x825bd3d4
	if (!ctx.cr6.eq) goto loc_825BD3D4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// clrlwi r4,r24,31
	ctx.r4.u64 = ctx.r24.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BD3D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_825BD3D4:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge cr6,0x825bd364
	if (!ctx.cr6.lt) goto loc_825BD364;
loc_825BD3E0:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82855b34
	ctx.lr = 0x825BD3E8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82855b34
	ctx.lr = 0x825BD3F0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C3390) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825C3398;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r29,r11,204
	ctx.r29.s64 = ctx.r11.s64 + 204;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b44
	ctx.lr = 0x825C33B8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825c33e8
	if (ctx.cr6.eq) goto loc_825C33E8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C33DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c3414
	if (ctx.cr6.lt) goto loc_825C3414;
loc_825C33E8:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c3414
	if (ctx.cr6.eq) goto loc_825C3414;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C3410;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_825C3414:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x825C341C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C86F0) {
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
	// bl 0x825c8350
	ctx.lr = 0x825C8708;
	sub_825C8350(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825c8738
	if (ctx.cr6.eq) goto loc_825C8738;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r10,3(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 3);
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x825c6aa0
	ctx.lr = 0x825C8724;
	sub_825C6AA0(ctx, base);
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
loc_825C8738:
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825c8768
	if (ctx.cr6.eq) goto loc_825C8768;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r10,3(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 3);
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x825c7f28
	ctx.lr = 0x825C8754;
	sub_825C7F28(ctx, base);
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
loc_825C8768:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825c8788
	ctx.lr = 0x825C8774;
	sub_825C8788(ctx, base);
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

DEFINE_REX_FUNC(sub_825CCE60) {
	REX_FUNC_PROLOGUE();
	// stw r4,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825CCEC8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r10,7(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// rlwinm r3,r10,29,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825CD758) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addic r11,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// lbz r9,40(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 40);
	// lwz r10,60(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// subfe r8,r11,r4
	temp.u8 = (~ctx.r11.u32 + ctx.r4.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r11.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rlwimi r9,r8,5,26,26
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0x20) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFDF);
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// stb r11,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r11.u8);
	// beq cr6,0x825cd790
	if (ctx.cr6.eq) goto loc_825CD790;
	// lhz r10,76(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 76);
	// rlwinm r9,r10,0,17,17
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x825cd794
	if (!ctx.cr6.eq) goto loc_825CD794;
loc_825CD790:
	// li r10,1
	ctx.r10.s64 = 1;
loc_825CD794:
	// addic r9,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// subfe r8,r9,r10
	temp.u8 = (~ctx.r9.u32 + ctx.r10.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r11,r8,6,25,25
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0x40) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r11,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825D0FA8) {
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
	// bl 0x825d1000
	ctx.lr = 0x825D0FC8;
	sub_825D1000(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d0fe8
	if (ctx.cr6.eq) goto loc_825D0FE8;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32783
	ctx.r4.u64 = ctx.r4.u64 | 32783;
	// bl 0x8263b710
	ctx.lr = 0x825D0FE4;
	sub_8263B710(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825D0FE8:
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

DEFINE_REX_FUNC(sub_825D4A00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x825D4A08;
	__savegprlr_22(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r23,0
	ctx.r23.s64 = 0;
	// subfic r10,r7,0
	ctx.xer.ca = ctx.r7.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r7.u64;
	// stw r23,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r23.u32);
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// li r8,16
	ctx.r8.s64 = 16;
	// subfe r7,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// and r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 & ctx.r8.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r5,r10,108
	ctx.r5.s64 = ctx.r10.s64 + 108;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
	// bl 0x825d41c0
	ctx.lr = 0x825D4A50;
	sub_825D41C0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d4b9c
	if (ctx.cr6.eq) goto loc_825D4B9C;
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r3,-8
	ctx.r11.s64 = ctx.r3.s64 + -8;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_825D4A6C:
	// stdu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U64(ea, ctx.r9.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x825d4a6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825D4A6C;
	// lwz r22,88(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r24,r31,60
	ctx.r24.s64 = ctx.r31.s64 + 60;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r22,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r22.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// addi r11,r31,80
	ctx.r11.s64 = ctx.r31.s64 + 80;
	// bne cr6,0x825d4aa0
	if (!ctx.cr6.eq) goto loc_825D4AA0;
	// stw r23,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r23.u32);
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// b 0x825d4acc
	goto loc_825D4ACC;
loc_825D4AA0:
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// addi r10,r31,96
	ctx.r10.s64 = ctx.r31.s64 + 96;
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r9,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// lwz r8,4(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r8,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r8.u32);
	// lwz r7,8(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stw r7,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r7.u32);
	// lwz r6,12(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stw r6,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r6.u32);
	// stw r10,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
loc_825D4ACC:
	// cmpwi cr6,r29,16
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 16, ctx.xer);
	// bge cr6,0x825d4adc
	if (!ctx.cr6.lt) goto loc_825D4ADC;
	// li r27,16
	ctx.r27.s64 = 16;
	// b 0x825d4aec
	goto loc_825D4AEC;
loc_825D4ADC:
	// lis r11,256
	ctx.r11.s64 = 16777216;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x825d4aec
	if (!ctx.cr6.gt) goto loc_825D4AEC;
	// lis r27,256
	ctx.r27.s64 = 16777216;
loc_825D4AEC:
	// lis r11,2047
	ctx.r11.s64 = 134152192;
	// ori r10,r11,65535
	ctx.r10.u64 = ctx.r11.u64 | 65535;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x825d4b74
	if (ctx.cr6.lt) goto loc_825D4B74;
	// lis r28,2047
	ctx.r28.s64 = 134152192;
	// ori r28,r28,65534
	ctx.r28.u64 = ctx.r28.u64 | 65534;
loc_825D4B04:
	// cmpw cr6,r27,r28
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r28.s32, ctx.xer);
	// ble cr6,0x825d4b10
	if (!ctx.cr6.gt) goto loc_825D4B10;
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
loc_825D4B10:
	// addi r29,r31,52
	ctx.r29.s64 = ctx.r31.s64 + 52;
	// stw r27,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// beq cr6,0x825d4ba8
	if (ctx.cr6.eq) goto loc_825D4BA8;
	// lis r5,32767
	ctx.r5.s64 = 2147418112;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,65535
	ctx.r5.u64 = ctx.r5.u64 | 65535;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827488d8
	ctx.lr = 0x825D4B3C;
	sub_827488D8(ctx, base);
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825d4ba8
	if (!ctx.cr6.eq) goto loc_825D4BA8;
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d4b88
	if (ctx.cr6.eq) goto loc_825D4B88;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D4B68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_825D4B74:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bgt cr6,0x825d4b04
	if (ctx.cr6.gt) goto loc_825D4B04;
	// li r28,-1
	ctx.r28.s64 = -1;
	// mr r25,r23
	ctx.r25.u64 = ctx.r23.u64;
	// b 0x825d4b10
	goto loc_825D4B10;
loc_825D4B88:
	// bl 0x82641188
	ctx.lr = 0x825D4B8C;
	sub_82641188(ctx, base);
	// bl 0x82641188
	ctx.lr = 0x825D4B90;
	sub_82641188(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// bl 0x826405b0
	ctx.lr = 0x825D4B9C;
	sub_826405B0(ctx, base);
loc_825D4B9C:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_825D4BA8:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x825d4c10
	if (ctx.cr6.eq) goto loc_825D4C10;
	// lis r5,32767
	ctx.r5.s64 = 2147418112;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,65535
	ctx.r5.u64 = ctx.r5.u64 | 65535;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827488d8
	ctx.lr = 0x825D4BC8;
	sub_827488D8(ctx, base);
	// stw r3,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825d4c10
	if (!ctx.cr6.eq) goto loc_825D4C10;
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d4be4
	if (ctx.cr6.eq) goto loc_825D4BE4;
	// bl 0x8263a978
	ctx.lr = 0x825D4BE4;
	sub_8263A978(ctx, base);
loc_825D4BE4:
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d4b88
	if (ctx.cr6.eq) goto loc_825D4B88;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D4C04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_825D4C10:
	// lwz r28,48(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
loc_825D4C14:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x825d4c70
	if (ctx.cr6.lt) goto loc_825D4C70;
	// beq cr6,0x825d4da8
	if (ctx.cr6.eq) goto loc_825D4DA8;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x825d4c30
	if (!ctx.cr6.gt) goto loc_825D4C30;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_825D4C30:
	// lwsync 
	// subf r10,r28,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r28.u64;
loc_825D4C38:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x825d4c5c
	if (!ctx.cr6.eq) goto loc_825D4C5C;
	// stwcx. r10,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d4c38
	if (!ctx.cr0.eq) goto loc_825D4C38;
	// b 0x825d4c64
	goto loc_825D4C64;
loc_825D4C5C:
	// stwcx. r9,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_825D4C64:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x825d4c14
	if (!ctx.cr6.eq) goto loc_825D4C14;
loc_825D4C70:
	// rlwinm r30,r28,4,0,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,40
	ctx.r4.s64 = ctx.r31.s64 + 40;
	// bl 0x825d4280
	ctx.lr = 0x825D4C88;
	sub_825D4280(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825d4c98
	if (!ctx.cr6.eq) goto loc_825D4C98;
	// stw r23,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r23.u32);
	// b 0x825d4da8
	goto loc_825D4DA8;
loc_825D4C98:
	// addi r11,r31,56
	ctx.r11.s64 = ctx.r31.s64 + 56;
loc_825D4C9C:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r28,r10
	ctx.r9.u64 = ctx.r28.u64 + ctx.r10.u64;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d4c9c
	if (!ctx.cr0.eq) goto loc_825D4C9C;
	// addi r7,r28,-1
	ctx.r7.s64 = ctx.r28.s64 + -1;
	// add r9,r30,r3
	ctx.r9.u64 = ctx.r30.u64 + ctx.r3.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x825d4d34
	if (ctx.cr6.eq) goto loc_825D4D34;
loc_825D4CCC:
	// addi r9,r9,-16
	ctx.r9.s64 = ctx.r9.s64 + -16;
	// rldicr r8,r9,32,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF00000000;
loc_825D4CD4:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lwsync 
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// clrldi r10,r5,33
	ctx.r10.u64 = ctx.r5.u64 & 0x7FFFFFFF;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
loc_825D4CF4:
	// mfmsr r3
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r3.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r4,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u64 = *(uint64_t*)REX_RAW_ADDR(ea);
	ctx.r4.u64 = __builtin_bswap64(ctx.reserved.u64);
	// cmpd cr6,r4,r11
	ctx.cr6.compare<int64_t>(ctx.r4.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d4d18
	if (!ctx.cr6.eq) goto loc_825D4D18;
	// stdcx. r10,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r10.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r3,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r3.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d4cf4
	if (!ctx.cr0.eq) goto loc_825D4CF4;
	// b 0x825d4d20
	goto loc_825D4D20;
loc_825D4D18:
	// stdcx. r4,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r4.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r3,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r3.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_825D4D20:
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmpd cr6,r4,r11
	ctx.cr6.compare<int64_t>(ctx.r4.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d4cd4
	if (!ctx.cr6.eq) goto loc_825D4CD4;
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x825d4ccc
	if (!ctx.cr0.eq) goto loc_825D4CCC;
loc_825D4D34:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// addi r30,r9,-16
	ctx.r30.s64 = ctx.r9.s64 + -16;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d4da0
	if (ctx.cr6.eq) goto loc_825D4DA0;
	// addi r11,r31,24
	ctx.r11.s64 = ctx.r31.s64 + 24;
loc_825D4D48:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r28,r10
	ctx.r9.u64 = ctx.r28.u64 + ctx.r10.u64;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d4d48
	if (!ctx.cr0.eq) goto loc_825D4D48;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bge cr6,0x825d4da0
	if (!ctx.cr6.lt) goto loc_825D4DA0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x825d4da0
	if (!ctx.cr6.gt) goto loc_825D4DA0;
	// not r4,r10
	ctx.r4.u64 = ~ctx.r10.u64;
	// cmpw cr6,r4,r7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x825d4d88
	if (!ctx.cr6.gt) goto loc_825D4D88;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
loc_825D4D88:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x82748970
	ctx.lr = 0x825D4D94;
	sub_82748970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825d4da0
	if (!ctx.cr6.eq) goto loc_825D4DA0;
	// bl 0x82639f50
	ctx.lr = 0x825D4DA0;
	sub_82639F50(ctx, base);
loc_825D4DA0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x825d4df4
	if (!ctx.cr6.eq) goto loc_825D4DF4;
loc_825D4DA8:
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d4db8
	if (ctx.cr6.eq) goto loc_825D4DB8;
	// bl 0x8263a978
	ctx.lr = 0x825D4DB8;
	sub_8263A978(ctx, base);
loc_825D4DB8:
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d4dc8
	if (ctx.cr6.eq) goto loc_825D4DC8;
	// bl 0x8263a978
	ctx.lr = 0x825D4DC8;
	sub_8263A978(ctx, base);
loc_825D4DC8:
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d4b88
	if (ctx.cr6.eq) goto loc_825D4B88;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D4DE8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_825D4DF4:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d4e0c
	if (ctx.cr6.eq) goto loc_825D4E0C;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_825D4E0C:
	// stw r23,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r23.u32);
	// lis r11,19558
	ctx.r11.s64 = 1281753088;
	// stw r23,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r23.u32);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// ori r10,r11,20853
	ctx.r10.u64 = ctx.r11.u64 | 20853;
	// stw r23,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r23.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stw r23,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r23.u32);
	// stw r10,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// lwsync 
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F6ED8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x825F6EE0;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// addi r27,r1,80
	ctx.r27.s64 = ctx.r1.s64 + 80;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// addi r11,r11,31
	ctx.r11.s64 = ctx.r11.s64 + 31;
	// rlwinm r31,r11,27,5,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// ble cr6,0x825f6f2c
	if (!ctx.cr6.gt) goto loc_825F6F2C;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8273c6c0
	ctx.lr = 0x825F6F18;
	sub_8273C6C0(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x825f6f2c
	if (!ctx.cr0.eq) goto loc_825F6F2C;
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// ori r3,r3,6
	ctx.r3.u64 = ctx.r3.u64 | 6;
	// b 0x825f6fe8
	goto loc_825F6FE8;
loc_825F6F2C:
	// rlwinm r5,r31,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82639688
	ctx.lr = 0x825F6F3C;
	sub_82639688(ctx, base);
loc_825F6F3C:
	// lwz r29,4(r26)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x825f6fbc
	goto loc_825F6FBC;
loc_825F6F4C:
	// rlwinm r30,r31,29,3,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r11,r31,27
	ctx.r11.u64 = ctx.r31.u32 & 0x1F;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r28,r10,r11
	ctx.r28.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// lwzx r11,r30,r27
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// and. r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 & ctx.r28.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825f6fb4
	if (!ctx.cr0.eq) goto loc_825F6FB4;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F6F80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-16381
	ctx.r11.s64 = -1073545216;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x825f6f98
	if (!ctx.cr6.eq) goto loc_825F6F98;
	// li r25,1
	ctx.r25.s64 = 1;
	// b 0x825f6fb4
	goto loc_825F6FB4;
loc_825F6F98:
	// lis r11,-16381
	ctx.r11.s64 = -1073545216;
	// ori r11,r11,5
	ctx.r11.u64 = ctx.r11.u64 | 5;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x825f6fb4
	if (ctx.cr6.eq) goto loc_825F6FB4;
	// lwzx r11,r30,r27
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// or r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 | ctx.r28.u64;
	// stwx r11,r30,r27
	REX_STORE_U32(ctx.r30.u32 + ctx.r27.u32, ctx.r11.u32);
loc_825F6FB4:
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_825F6FBC:
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825f6f4c
	if (!ctx.cr6.eq) goto loc_825F6F4C;
	// clrlwi. r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825f6f3c
	if (!ctx.cr0.eq) goto loc_825F6F3C;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825f6fe4
	if (ctx.cr6.eq) goto loc_825F6FE4;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273c660
	ctx.lr = 0x825F6FE4;
	sub_8273C660(ctx, base);
loc_825F6FE4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825F6FE8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FD5C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x825FD5D0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r26,r11,-15420
	ctx.r26.s64 = ctx.r11.s64 + -15420;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x825f8cb0
	ctx.lr = 0x825FD5EC;
	sub_825F8CB0(ctx, base);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// lwz r11,-11636(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -11636);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x825fd614
	goto loc_825FD614;
loc_825FD600:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// cmplw cr6,r8,r30
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x825fd61c
	if (ctx.cr6.eq) goto loc_825FD61C;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_825FD614:
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x825fd600
	if (!ctx.cr6.eq) goto loc_825FD600;
loc_825FD61C:
	// lwz r9,40(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// addi r10,r11,32
	ctx.r10.s64 = ctx.r11.s64 + 32;
	// lwz r8,36(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// li r27,0
	ctx.r27.s64 = 0;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// rlwinm. r9,r9,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x825fd640
	if (!ctx.cr0.eq) goto loc_825FD640;
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// b 0x825fd664
	goto loc_825FD664;
loc_825FD640:
	// lwz r9,40(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r8,4(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// subf r8,r8,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r8.u64;
	// lwz r31,-4(r9)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + -4);
	// rlwinm. r9,r8,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x825fd664
	if (ctx.cr0.eq) goto loc_825FD664;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
loc_825FD664:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x825fd698
	if (!ctx.cr6.eq) goto loc_825FD698;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_825FD674:
	// lwsync 
loc_825FD678:
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
	// stwcx. r27,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r27.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825fd678
	if (!ctx.cr0.eq) goto loc_825FD678;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
loc_825FD698:
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// bl 0x825f9c60
	ctx.lr = 0x825FD6A8;
	sub_825F9C60(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825fa250
	ctx.lr = 0x825FD6B0;
	sub_825FA250(ctx, base);
	// lhz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// sth r11,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r11.u16);
	// lhz r11,10(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 10);
	// sth r11,10(r31)
	REX_STORE_U16(ctx.r31.u32 + 10, ctx.r11.u16);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825f9cf8
	ctx.lr = 0x825FD6C8;
	sub_825F9CF8(ctx, base);
	// lwz r11,-11636(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -11636);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825fd6e0
	if (!ctx.cr6.eq) goto loc_825FD6E0;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// b 0x825fd6ec
	goto loc_825FD6EC;
loc_825FD6E0:
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// subf r9,r10,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r10.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
loc_825FD6EC:
	// lwz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r10,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r10.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x825fd710
	if (!ctx.cr6.lt) goto loc_825FD710;
	// addi r10,r4,4
	ctx.r10.s64 = ctx.r4.s64 + 4;
	// stw r31,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r31.u32);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// b 0x825fd720
	goto loc_825FD720;
loc_825FD710:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x825fda58
	ctx.lr = 0x825FD71C;
	sub_825FDA58(ctx, base);
	// lwz r11,-11636(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -11636);
loc_825FD720:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r27,64(r11)
	REX_STORE_U8(ctx.r11.u32 + 64, ctx.r27.u8);
	// b 0x825fd674
	goto loc_825FD674;
}

DEFINE_REX_FUNC(sub_8260C058) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8260C060;
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
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// ble cr6,0x8260c1b0
	if (!ctx.cr6.gt) goto loc_8260C1B0;
loc_8260C088:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8260c118
	if (!ctx.cr6.gt) goto loc_8260C118;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8260c250
	ctx.lr = 0x8260C0A4;
	sub_8260C250(ctx, base);
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
	// subf r11,r30,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r30.u64;
	// subf r10,r31,r28
	ctx.r10.u64 = ctx.r28.u64 - ctx.r31.u64;
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8260c0f4
	if (!ctx.cr6.lt) goto loc_8260C0F4;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8260c058
	ctx.lr = 0x8260C0EC;
	sub_8260C058(ctx, base);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// b 0x8260c104
	goto loc_8260C104;
loc_8260C0F4:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8260c058
	ctx.lr = 0x8260C100;
	sub_8260C058(ctx, base);
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
loc_8260C104:
	// subf r28,r31,r26
	ctx.r28.u64 = ctx.r26.u64 - ctx.r31.u64;
	// srawi r30,r28,2
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r28.s32 >> 2;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// bgt cr6,0x8260c088
	if (ctx.cr6.gt) goto loc_8260C088;
loc_8260C118:
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// ble cr6,0x8260c1b0
	if (!ctx.cr6.gt) goto loc_8260C1B0;
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// ble cr6,0x8260c244
	if (!ctx.cr6.gt) goto loc_8260C244;
	// srawi r11,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 1;
	// addze. r29,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r29.s64 = temp.s64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble 0x8260c160
	if (!ctx.cr0.gt) goto loc_8260C160;
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r27,r11,r31
	ctx.r27.u64 = ctx.r11.u64 + ctx.r31.u64;
loc_8260C13C:
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// lwzu r6,-4(r27)
	ea = -4 + ctx.r27.u32;
	ctx.r6.u64 = REX_LOAD_U32(ea);
	ctx.r27.u32 = ea;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8260c588
	ctx.lr = 0x8260C158;
	sub_8260C588(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bgt cr6,0x8260c13c
	if (ctx.cr6.gt) goto loc_8260C13C;
loc_8260C160:
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// ble cr6,0x8260c244
	if (!ctx.cr6.gt) goto loc_8260C244;
	// addi r29,r26,-4
	ctx.r29.s64 = ctx.r26.s64 + -4;
	// subfic r27,r31,4
	ctx.xer.ca = ctx.r31.u32 <= 4;
	ctx.r27.u64 = static_cast<uint64_t>(4) - ctx.r31.u64;
	// subf r28,r31,r29
	ctx.r28.u64 = ctx.r29.u64 - ctx.r31.u64;
loc_8260C174:
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
	// bl 0x8260c588
	ctx.lr = 0x8260C194;
	sub_8260C588(ctx, base);
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
	// bgt cr6,0x8260c174
	if (ctx.cr6.gt) goto loc_8260C174;
	// b 0x8260c244
	goto loc_8260C244;
loc_8260C1B0:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x8260c244
	if (!ctx.cr6.gt) goto loc_8260C244;
	// cmplw cr6,r31,r26
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x8260c244
	if (ctx.cr6.eq) goto loc_8260C244;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// b 0x8260c23c
	goto loc_8260C23C;
loc_8260C1C8:
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,4(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8260c20c
	if (!ctx.cr6.lt) goto loc_8260C20C;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8260c204
	if (ctx.cr6.eq) goto loc_8260C204;
	// li r9,4
	ctx.r9.s64 = 4;
loc_8260C1F4:
	// lwzu r8,-4(r10)
	ea = -4 + ctx.r10.u32;
	ctx.r8.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// stwx r8,r9,r10
	REX_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bne cr6,0x8260c1f4
	if (!ctx.cr6.eq) goto loc_8260C1F4;
loc_8260C204:
	// stw r6,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// b 0x8260c238
	goto loc_8260C238;
loc_8260C20C:
	// lwz r10,-4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// b 0x8260c228
	goto loc_8260C228;
loc_8260C218:
	// stw r10,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// lwzu r10,-4(r9)
	ea = -4 + ctx.r9.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// lwz r8,4(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
loc_8260C228:
	// lwz r5,4(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r8,r5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x8260c218
	if (ctx.cr6.lt) goto loc_8260C218;
	// stw r6,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
loc_8260C238:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_8260C23C:
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8260c1c8
	if (!ctx.cr6.eq) goto loc_8260C1C8;
loc_8260C244:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82618810) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82618818;
	__savegprlr_23(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,56(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lfs f13,48(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f12,60(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 60);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,52(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 52);
	ctx.f0.f64 = double(temp.f32);
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// fmuls f2,f12,f0
	ctx.f2.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// addi r25,r5,32
	ctx.r25.s64 = ctx.r5.s64 + 32;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82618868
	if (ctx.cr6.eq) goto loc_82618868;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82618870
	if (!ctx.cr6.eq) goto loc_82618870;
	// addi r3,r5,16
	ctx.r3.s64 = ctx.r5.s64 + 16;
	// bl 0x82617f58
	ctx.lr = 0x82618860;
	sub_82617F58(ctx, base);
	// stw r3,36(r29)
	REX_STORE_U32(ctx.r29.u32 + 36, ctx.r3.u32);
	// b 0x82618870
	goto loc_82618870;
loc_82618868:
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// stw r11,36(r29)
	REX_STORE_U32(ctx.r29.u32 + 36, ctx.r11.u32);
loc_82618870:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r26,r11,26104
	ctx.r26.s64 = ctx.r11.s64 + 26104;
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// addi r30,r26,4
	ctx.r30.s64 = ctx.r26.s64 + 4;
	// addi r28,r11,31600
	ctx.r28.s64 = ctx.r11.s64 + 31600;
loc_82618888:
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// sraw r10,r10,r27
	temp.u32 = ctx.r27.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82618970
	if (ctx.cr0.eq) goto loc_82618970;
	// lwa r11,88(r11)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r11.u32 + 88));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// li r10,0
	ctx.r10.s64 = 0;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r11,0
	ctx.r11.s64 = 0;
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lfs f13,-4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// li r10,64
	ctx.r10.s64 = 64;
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r5,44(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 44);
	// li r7,4
	ctx.r7.s64 = 4;
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// lvsr v7,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// addi r23,r1,128
	ctx.r23.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r28,r10
	ea = (ctx.r28.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vperm128 v12,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vor128 v62,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v13,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vsel128 v62,v0,v13,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// lvsr v6,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// lvsl v7,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v13,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// vperm128 v63,v62,v62,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stvx128 v62,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vaddfp128 v0,v63,v60
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vsel128 v13,v62,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82618198
	ctx.lr = 0x82618970;
	sub_82618198(ctx, base);
loc_82618970:
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r11,r26,36
	ctx.r11.s64 = ctx.r26.s64 + 36;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82618888
	if (ctx.cr6.lt) goto loc_82618888;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lwz r5,36(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82618198
	ctx.lr = 0x82618998;
	sub_82618198(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8262CAF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8262CAF8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r4,48(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r29,r6,-4
	ctx.r29.s64 = ctx.r6.s64 + -4;
loc_8262CB0C:
	// cntlzd r11,r31
	ctx.r11.u64 = ctx.r31.u64 == 0 ? 64 : __builtin_clzll(ctx.r31.u64);
	// lwz r9,52(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 52);
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// sld r31,r31,r8
	ctx.r31.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r31.u64 << (ctx.r8.u8 & 0x7F));
	// not r8,r31
	ctx.r8.u64 = ~ctx.r31.u64;
	// add r29,r10,r29
	ctx.r29.u64 = ctx.r10.u64 + ctx.r29.u64;
	// cntlzd r30,r8
	ctx.r30.u64 = ctx.r8.u64 == 0 ? 64 : __builtin_clzll(ctx.r8.u64);
	// add r28,r11,r5
	ctx.r28.u64 = ctx.r11.u64 + ctx.r5.u64;
	// rlwinm r27,r30,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// add r10,r27,r4
	ctx.r10.u64 = ctx.r27.u64 + ctx.r4.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8262cb74
	if (ctx.cr6.lt) goto loc_8262CB74;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8262c4a8
	ctx.lr = 0x8262CB5C;
	sub_8262C4A8(ctx, base);
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// add r29,r27,r29
	ctx.r29.u64 = ctx.r27.u64 + ctx.r29.u64;
	// add r5,r30,r28
	ctx.r5.u64 = ctx.r30.u64 + ctx.r28.u64;
	// sld r31,r31,r11
	ctx.r31.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r31.u64 << (ctx.r11.u8 & 0x7F));
	// b 0x8262cb9c
	goto loc_8262CB9C;
loc_8262CB74:
	// addi r10,r30,-1
	ctx.r10.s64 = ctx.r30.s64 + -1;
	// add r5,r30,r28
	ctx.r5.u64 = ctx.r30.u64 + ctx.r28.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// or r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 | ctx.r28.u64;
	// stwu r10,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r4.u32 = ea;
loc_8262CB88:
	// lwzu r10,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicr r31,r31,1,62
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// stwu r10,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r4.u32 = ea;
	// bne 0x8262cb88
	if (!ctx.cr0.eq) goto loc_8262CB88;
loc_8262CB9C:
	// cmpldi cr6,r31,0
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, 0, ctx.xer);
	// bne cr6,0x8262cb0c
	if (!ctx.cr6.eq) goto loc_8262CB0C;
	// stw r4,48(r26)
	REX_STORE_U32(ctx.r26.u32 + 48, ctx.r4.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82632048) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82632050;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24192(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24192);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x826321dc
	if (!ctx.cr0.eq) goto loc_826321DC;
	// lis r4,-19072
	ctx.r4.s64 = -1249902592;
	// li r3,200
	ctx.r3.s64 = 200;
	// bl 0x8263b678
	ctx.lr = 0x82632070;
	sub_8263B678(ctx, base);
	// stw r3,11976(r30)
	REX_STORE_U32(ctx.r30.u32 + 11976, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82632084
	if (!ctx.cr0.eq) goto loc_82632084;
loc_8263207C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x826321e0
	goto loc_826321E0;
loc_82632084:
	// li r11,6
	ctx.r11.s64 = 6;
	// lwz r10,24192(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 24192);
	// li r26,0
	ctx.r26.s64 = 0;
	// lis r23,256
	ctx.r23.s64 = 16777216;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// stw r26,11016(r30)
	REX_STORE_U32(ctx.r30.u32 + 11016, ctx.r26.u32);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826320A4:
	// slw r11,r23,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r23.u32 << (ctx.r9.u8 & 0x3F));
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826320b4
	if (ctx.cr0.eq) goto loc_826320B4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_826320B4:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x826320a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826320A4;
	// lwz r11,15104(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15104);
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// lwz r7,15108(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 15108);
	// rlwinm. r10,r10,0,5,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,11032(r30)
	REX_STORE_U32(ctx.r30.u32 + 11032, ctx.r9.u32);
	// li r25,-1
	ctx.r25.s64 = -1;
	// stw r8,10988(r30)
	REX_STORE_U32(ctx.r30.u32 + 10988, ctx.r8.u32);
	// stw r26,10992(r30)
	REX_STORE_U32(ctx.r30.u32 + 10992, ctx.r26.u32);
	// stw r11,10952(r30)
	REX_STORE_U32(ctx.r30.u32 + 10952, ctx.r11.u32);
	// stw r7,10960(r30)
	REX_STORE_U32(ctx.r30.u32 + 10960, ctx.r7.u32);
	// beq 0x826320f0
	if (ctx.cr0.eq) goto loc_826320F0;
	// li r25,2
	ctx.r25.s64 = 2;
	// stw r25,11324(r30)
	REX_STORE_U32(ctx.r30.u32 + 11324, ctx.r25.u32);
loc_826320F0:
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lis r27,32512
	ctx.r27.s64 = 2130706432;
	// addi r31,r30,11396
	ctx.r31.s64 = ctx.r30.s64 + 11396;
	// lis r24,-32256
	ctx.r24.s64 = -2113929216;
loc_82632100:
	// lwz r11,24192(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24192);
	// slw r10,r23,r29
	ctx.r10.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r23.u32 << (ctx.r29.u8 & 0x3F));
	// and. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826321c0
	if (ctx.cr0.eq) goto loc_826321C0;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x82632120
	if (!ctx.cr6.lt) goto loc_82632120;
	// mr r25,r29
	ctx.r25.u64 = ctx.r29.u64;
	// stw r29,11324(r30)
	REX_STORE_U32(ctx.r30.u32 + 11324, ctx.r29.u32);
loc_82632120:
	// addis r11,r27,16640
	ctx.r11.s64 = ctx.r27.s64 + 1090519040;
	// stw r29,-64(r31)
	REX_STORE_U32(ctx.r31.u32 + -64, ctx.r29.u32);
	// addi r10,r30,10948
	ctx.r10.s64 = ctx.r30.s64 + 10948;
	// stw r27,-40(r31)
	REX_STORE_U32(ctx.r31.u32 + -40, ctx.r27.u32);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stw r10,-68(r31)
	REX_STORE_U32(ctx.r31.u32 + -68, ctx.r10.u32);
	// addi r28,r31,-68
	ctx.r28.s64 = ctx.r31.s64 + -68;
	// stw r11,-44(r31)
	REX_STORE_U32(ctx.r31.u32 + -44, ctx.r11.u32);
	// lis r11,-32157
	ctx.r11.s64 = -2107441152;
	// stb r26,-8(r31)
	REX_STORE_U8(ctx.r31.u32 + -8, ctx.r26.u8);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// stw r26,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r26.u32);
	// addi r4,r11,7040
	ctx.r4.s64 = ctx.r11.s64 + 7040;
	// stw r31,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r31.u32);
	// addi r3,r31,-36
	ctx.r3.s64 = ctx.r31.s64 + -36;
	// stw r31,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r31.u32);
	// bl 0x828562b4
	ctx.lr = 0x82632164;
	__imp__KeInitializeDpc(ctx, base);
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// lis r10,-32157
	ctx.r10.s64 = -2107441152;
	// stb r11,-33(r31)
	REX_STORE_U8(ctx.r31.u32 + -33, ctx.r11.u8);
	// addi r8,r31,12
	ctx.r8.s64 = ctx.r31.s64 + 12;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r5,r10,6632
	ctx.r5.s64 = ctx.r10.s64 + 6632;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82639f40
	ctx.lr = 0x8263218C;
	sub_82639F40(ctx, base);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8263207c
	if (ctx.cr0.eq) goto loc_8263207C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,2008(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 2008);
	// bl 0x82855a84
	ctx.lr = 0x826321A4;
	__imp__ObReferenceObjectByHandle(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x826321c0
	if (ctx.cr0.lt) goto loc_826321C0;
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82855a74
	ctx.lr = 0x826321B8;
	__imp__KeSetBasePriorityThread(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82855a64
	ctx.lr = 0x826321C0;
	__imp__ObDereferenceObject(ctx, base);
loc_826321C0:
	// lis r11,32512
	ctx.r11.s64 = 2130706432;
	// addi r27,r27,128
	ctx.r27.s64 = ctx.r27.s64 + 128;
	// ori r11,r11,768
	ctx.r11.u64 = ctx.r11.u64 | 768;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,108
	ctx.r31.s64 = ctx.r31.s64 + 108;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82632100
	if (ctx.cr6.lt) goto loc_82632100;
loc_826321DC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_826321E0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8263BE38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8263BE40;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32116
	ctx.r11.s64 = -2104754176;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,12936
	ctx.r30.s64 = ctx.r11.s64 + 12936;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8263BE5C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x8263be84
	if (ctx.cr6.eq) goto loc_8263BE84;
	// lis r11,-32116
	ctx.r11.s64 = -2104754176;
	// addi r10,r11,12964
	ctx.r10.s64 = ctx.r11.s64 + 12964;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r31,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// b 0x8263be94
	goto loc_8263BE94;
loc_8263BE84:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8263BE94:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8263BE9C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82641154) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// ori r11,r11,23
	ctx.r11.u64 = ctx.r11.u64 | 23;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82642208) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// addi r10,r10,5984
	ctx.r10.s64 = ctx.r10.s64 + 5984;
	// addi r9,r4,16
	ctx.r9.s64 = ctx.r4.s64 + 16;
loc_82642224:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x82642244
	if (!ctx.cr0.eq) goto loc_82642244;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x82642224
	if (!ctx.cr6.eq) goto loc_82642224;
loc_82642244:
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x82642268
	if (!ctx.cr0.eq) goto loc_82642268;
	// stw r3,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82642260;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82642278
	goto loc_82642278;
loc_82642268:
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// ori r3,r3,16386
	ctx.r3.u64 = ctx.r3.u64 | 16386;
loc_82642278:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82643E08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82643E10;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// addi r29,r3,44
	ctx.r29.s64 = ctx.r3.s64 + 44;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82643E34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,176(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// addi r30,r31,176
	ctx.r30.s64 = ctx.r31.s64 + 176;
	// stw r28,532(r31)
	REX_STORE_U32(ctx.r31.u32 + 532, ctx.r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82643e54
	if (!ctx.cr6.eq) goto loc_82643E54;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82644a60
	ctx.lr = 0x82643E54;
	sub_82644A60(ctx, base);
loc_82643E54:
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82643f04
	if (ctx.cr6.lt) goto loc_82643F04;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// li r5,375
	ctx.r5.s64 = 375;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82643E80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82643f04
	if (ctx.cr0.lt) goto loc_82643F04;
	// addi r3,r31,592
	ctx.r3.s64 = ctx.r31.s64 + 592;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82644b20
	ctx.lr = 0x82643E98;
	sub_82644B20(ctx, base);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82643f04
	if (ctx.cr0.lt) goto loc_82643F04;
	// addi r5,r31,184
	ctx.r5.s64 = ctx.r31.s64 + 184;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82642880
	ctx.lr = 0x82643EB4;
	sub_82642880(ctx, base);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82643f04
	if (ctx.cr0.lt) goto loc_82643F04;
	// addi r5,r31,180
	ctx.r5.s64 = ctx.r31.s64 + 180;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82642880
	ctx.lr = 0x82643ED0;
	sub_82642880(ctx, base);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82643f04
	if (ctx.cr0.lt) goto loc_82643F04;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r31,16032
	ctx.r3.s64 = ctx.r31.s64 + 16032;
	// bl 0x82643c68
	ctx.lr = 0x82643EE8;
	sub_82643C68(ctx, base);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82643f04
	if (ctx.cr0.lt) goto loc_82643F04;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// stw r11,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// b 0x82643f0c
	goto loc_82643F0C;
loc_82643F04:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82642428
	ctx.lr = 0x82643F0C;
	sub_82642428(ctx, base);
loc_82643F0C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82643F20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826422f8
	ctx.lr = 0x82643F28;
	sub_826422F8(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264A9D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8264A9E0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,232(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 232);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r30,-1
	ctx.r30.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8264aa30
	goto loc_8264AA30;
loc_8264AA00:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x8264aa24
	if (ctx.cr6.lt) goto loc_8264AA24;
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8264aa24
	if (!ctx.cr6.lt) goto loc_8264AA24;
	// mr r28,r9
	ctx.r28.u64 = ctx.r9.u64;
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
loc_8264AA24:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8264aa38
	if (ctx.cr6.eq) goto loc_8264AA38;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_8264AA30:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8264aa00
	if (!ctx.cr6.eq) goto loc_8264AA00;
loc_8264AA38:
	// addi r29,r27,124
	ctx.r29.s64 = ctx.r27.s64 + 124;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82649a08
	ctx.lr = 0x8264AA44;
	sub_82649A08(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8264a360
	ctx.lr = 0x8264AA50;
	sub_8264A360(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8264aacc
	if (ctx.cr0.eq) goto loc_8264AACC;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8264aad8
	if (ctx.cr6.eq) goto loc_8264AAD8;
	// stw r31,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,13120
	ctx.r3.s64 = ctx.r11.s64 + 13120;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x82641ff8
	ctx.lr = 0x8264AA7C;
	sub_82641FF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8264aaa4
	if (ctx.cr0.eq) goto loc_8264AAA4;
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r9,r31,r30
	ctx.r9.u64 = ctx.r30.u64 - ctx.r31.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x8264aaa8
	goto loc_8264AAA8;
loc_8264AAA4:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8264AAA8:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8264aacc
	if (ctx.cr6.eq) goto loc_8264AACC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8264a360
	ctx.lr = 0x8264AABC;
	sub_8264A360(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8264aad8
	if (!ctx.cr0.eq) goto loc_8264AAD8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264cf40
	ctx.lr = 0x8264AACC;
	sub_8264CF40(ctx, base);
loc_8264AACC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8264AAD0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_8264AAD8:
	// lwz r11,260(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 260);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8264ab2c
	if (!ctx.cr6.eq) goto loc_8264AB2C;
	// lwz r9,232(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 232);
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8264ab20
	goto loc_8264AB20;
loc_8264AAF0:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8264ab08
	if (ctx.cr6.eq) goto loc_8264AB08;
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8264ab0c
	goto loc_8264AB0C;
loc_8264AB08:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8264AB0C:
	// lwz r11,260(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 260);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8264ab20
	if (ctx.cr6.gt) goto loc_8264AB20;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8264AB20:
	// stw r11,260(r27)
	REX_STORE_U32(ctx.r27.u32 + 260, ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8264aaf0
	if (!ctx.cr6.eq) goto loc_8264AAF0;
loc_8264AB2C:
	// lwz r3,0(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// b 0x8264aad0
	goto loc_8264AAD0;
}

DEFINE_REX_FUNC(sub_82652A98) {
	REX_FUNC_PROLOGUE();
	// lis r3,-30570
	ctx.r3.s64 = -2003435520;
	// ori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 | 1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82652DB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82652DB8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r29,r3,20
	ctx.r29.s64 = ctx.r3.s64 + 20;
	// b 0x82652de0
	goto loc_82652DE0;
loc_82652DC8:
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x826424a8
	ctx.lr = 0x82652DD8;
	sub_826424A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264cf40
	ctx.lr = 0x82652DE0;
	sub_8264CF40(ctx, base);
loc_82652DE0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82647fb8
	ctx.lr = 0x82652DE8;
	sub_82647FB8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82652dc8
	if (!ctx.cr0.eq) goto loc_82652DC8;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82652e20
	if (ctx.cr6.eq) goto loc_82652E20;
loc_82652DFC:
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
	// bne 0x82652dfc
	if (!ctx.cr0.eq) goto loc_82652DFC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
loc_82652E20:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826432c0
	ctx.lr = 0x82652E28;
	sub_826432C0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265BCB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8265BCB8;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8265bce4
	if (ctx.cr6.eq) goto loc_8265BCE4;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8265bcf0
	if (!ctx.cr6.eq) goto loc_8265BCF0;
loc_8265BCE4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// b 0x8265be30
	goto loc_8265BE30;
loc_8265BCF0:
	// lwz r10,368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// lwz r9,360(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// lhz r29,0(r27)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r27.u32 + 0);
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// sth r29,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r29.u16);
	// mullw r7,r8,r29
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r29.s32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// cmpw cr6,r7,r28
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r28.s32, ctx.xer);
	// bgt cr6,0x8265be44
	if (ctx.cr6.gt) goto loc_8265BE44;
	// cmpw cr6,r29,r28
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r28.s32, ctx.xer);
	// bgt cr6,0x8265be44
	if (ctx.cr6.gt) goto loc_8265BE44;
	// lwz r10,352(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8265bd9c
	if (!ctx.cr6.eq) goto loc_8265BD9C;
	// lwz r10,420(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8265bd44
	if (ctx.cr6.eq) goto loc_8265BD44;
	// lwz r10,424(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8265bd70
	if (!ctx.cr6.eq) goto loc_8265BD70;
loc_8265BD44:
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bne cr6,0x8265bd64
	if (!ctx.cr6.eq) goto loc_8265BD64;
	// bl 0x82657828
	ctx.lr = 0x8265BD60;
	sub_82657828(ctx, base);
	// b 0x8265bd68
	goto loc_8265BD68;
loc_8265BD64:
	// bl 0x826571c0
	ctx.lr = 0x8265BD68;
	sub_826571C0(ctx, base);
loc_8265BD68:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8265be30
	if (ctx.cr6.lt) goto loc_8265BE30;
loc_8265BD70:
	// lwz r11,420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8265bd9c
	if (!ctx.cr6.eq) goto loc_8265BD9C;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82657e20
	ctx.lr = 0x8265BD90;
	sub_82657E20(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8265be2c
	if (ctx.cr6.lt) goto loc_8265BE2C;
	// lhz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
loc_8265BD9C:
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265bdd4
	if (ctx.cr6.eq) goto loc_8265BDD4;
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8265bdd4
	if (ctx.cr6.eq) goto loc_8265BDD4;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82656c90
	ctx.lr = 0x8265BDC8;
	sub_82656C90(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8265be2c
	if (ctx.cr6.lt) goto loc_8265BE2C;
	// lhz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
loc_8265BDD4:
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265be0c
	if (ctx.cr6.eq) goto loc_8265BE0C;
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8265be0c
	if (ctx.cr6.eq) goto loc_8265BE0C;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82656e58
	ctx.lr = 0x8265BE00;
	sub_82656E58(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8265be2c
	if (ctx.cr6.lt) goto loc_8265BE2C;
	// lhz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
loc_8265BE0C:
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8265be30
	if (!ctx.cr6.eq) goto loc_8265BE30;
	// clrlwi r5,r29,16
	ctx.r5.u64 = ctx.r29.u32 & 0xFFFF;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8265b2e8
	ctx.lr = 0x8265BE28;
	sub_8265B2E8(ctx, base);
	// b 0x8265be30
	goto loc_8265BE30;
loc_8265BE2C:
	// lhz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
loc_8265BE30:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8265be4c
	if (ctx.cr6.eq) goto loc_8265BE4C;
	// sth r29,0(r27)
	REX_STORE_U16(ctx.r27.u32 + 0, ctx.r29.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_8265BE44:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
loc_8265BE4C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82669A38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x82669A40;
	__savegprlr_22(ctx, base);
	// stfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f29.u64);
	// stfd f30,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f30.u64);
	// stfd f31,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,16(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r24,24(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r22,0(r3)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f1,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// fctiwz f13,f1
	ctx.f13.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r28,84(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r7,r28
	ctx.r7.s64 = ctx.r28.s32;
	// std r7,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lwz r25,4(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lfs f30,24804(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24804);
	ctx.f30.f64 = double(temp.f32);
	// lwz r23,28(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r31,36(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// fsubs f29,f1,f10
	ctx.f29.f64 = double(float(ctx.f1.f64 - ctx.f10.f64));
	// beq cr6,0x82669ae4
	if (ctx.cr6.eq) goto loc_82669AE4;
	// lhz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r22.u32 + 0);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f30
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f30.f64));
	// stfs f10,0(r26)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
loc_82669AE4:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// lfs f31,5864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f31.f64 = double(temp.f32);
	// bge cr6,0x82669b4c
	if (!ctx.cr6.lt) goto loc_82669B4C;
	// addi r10,r25,-4
	ctx.r10.s64 = ctx.r25.s64 + -4;
loc_82669AF8:
	// cmplw cr6,r30,r23
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x82669b48
	if (!ctx.cr6.lt) goto loc_82669B48;
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r31,r28,r31
	ctx.r31.u64 = ctx.r28.u64 + ctx.r31.u64;
	// lfs f13,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f10,f11,f0,f13
	ctx.f10.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfsu f10,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fadds f0,f29,f0
	ctx.f0.f64 = double(float(ctx.f29.f64 + ctx.f0.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x82669b40
	if (ctx.cr6.lt) goto loc_82669B40;
loc_82669B30:
	// fsubs f0,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82669b30
	if (!ctx.cr6.lt) goto loc_82669B30;
loc_82669B40:
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// blt cr6,0x82669af8
	if (ctx.cr6.lt) goto loc_82669AF8;
loc_82669B48:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_82669B4C:
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 + ctx.r25.u64;
	// rlwinm r11,r10,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82669bf0
	if (ctx.cr6.eq) goto loc_82669BF0;
	// subf r11,r30,r23
	ctx.r11.u64 = ctx.r23.u64 - ctx.r30.u64;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// ble cr6,0x82669c2c
	if (!ctx.cr6.gt) goto loc_82669C2C;
loc_82669B6C:
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// add r31,r28,r31
	ctx.r31.u64 = ctx.r28.u64 + ctx.r31.u64;
	// lhz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r9,-2(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// std r4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fmuls f6,f8,f30
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f30.f64));
	// fmuls f7,f9,f30
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f30.f64));
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmadds f4,f5,f0,f6
	ctx.f4.f64 = double(float(std::fma(ctx.f5.f64, ctx.f0.f64, ctx.f6.f64)));
	// stfs f4,0(r10)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fadds f0,f29,f0
	ctx.f0.f64 = double(float(ctx.f29.f64 + ctx.f0.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x82669be0
	if (ctx.cr6.lt) goto loc_82669BE0;
loc_82669BD0:
	// fsubs f0,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82669bd0
	if (!ctx.cr6.lt) goto loc_82669BD0;
loc_82669BE0:
	// rlwinm r11,r10,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82669b6c
	if (!ctx.cr6.eq) goto loc_82669B6C;
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_82669BF0:
	// subf r10,r30,r23
	ctx.r10.u64 = ctx.r23.u64 - ctx.r30.u64;
	// cmplwi cr6,r10,15
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 15, ctx.xer);
	// ble cr6,0x82669c2c
	if (!ctx.cr6.gt) goto loc_82669C2C;
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r29,r10,0,0,27
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// add r4,r10,r25
	ctx.r4.u64 = ctx.r10.u64 + ctx.r25.u64;
	// addi r3,r11,-2
	ctx.r3.s64 = ctx.r11.s64 + -2;
	// bl 0x82669760
	ctx.lr = 0x82669C20;
	sub_82669760(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// add r30,r29,r30
	ctx.r30.u64 = ctx.r29.u64 + ctx.r30.u64;
	// add r31,r3,r31
	ctx.r31.u64 = ctx.r3.u64 + ctx.r31.u64;
loc_82669C2C:
	// cmplw cr6,r30,r23
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x82669cb4
	if (!ctx.cr6.lt) goto loc_82669CB4;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r30,r23
	ctx.r9.u64 = ctx.r23.u64 - ctx.r30.u64;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82669C48:
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r31,r28,r31
	ctx.r31.u64 = ctx.r28.u64 + ctx.r31.u64;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// lhz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r8,-2(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// std r5,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmuls f7,f9,f30
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f30.f64));
	// fmsubs f6,f8,f30,f7
	ctx.f6.f64 = double(float(std::fma(ctx.f8.f64, ctx.f30.f64, -ctx.f7.f64)));
	// fmadds f5,f6,f0,f7
	ctx.f5.f64 = double(float(std::fma(ctx.f6.f64, ctx.f0.f64, ctx.f7.f64)));
	// stfsu f5,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fadds f0,f29,f0
	ctx.f0.f64 = double(float(ctx.f29.f64 + ctx.f0.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x82669cb0
	if (ctx.cr6.lt) goto loc_82669CB0;
loc_82669CA0:
	// fsubs f0,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82669ca0
	if (!ctx.cr6.lt) goto loc_82669CA0;
loc_82669CB0:
	// bdnz 0x82669c48
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82669C48;
loc_82669CB4:
	// addi r11,r24,-1
	ctx.r11.s64 = ctx.r24.s64 + -1;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82669cc4
	if (!ctx.cr6.lt) goto loc_82669CC4;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_82669CC4:
	// subf r10,r24,r31
	ctx.r10.u64 = ctx.r31.u64 - ctx.r24.u64;
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// neg r9,r24
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r24.u64);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// stw r8,12(r27)
	REX_STORE_U32(ctx.r27.u32 + 12, ctx.r8.u32);
	// stw r10,36(r27)
	REX_STORE_U32(ctx.r27.u32 + 36, ctx.r10.u32);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x82669d8c
	if (!ctx.cr6.lt) goto loc_82669D8C;
	// subf r10,r11,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r11.u64;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// blt cr6,0x82669d50
	if (ctx.cr6.lt) goto loc_82669D50;
	// subf r10,r11,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r11.u64;
	// add r7,r11,r24
	ctx.r7.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r6,r10,-4
	ctx.r6.s64 = ctx.r10.s64 + -4;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r6,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r8,r8,r26
	ctx.r8.u64 = ctx.r8.u64 + ctx.r26.u64;
	// add r6,r7,r26
	ctx.r6.u64 = ctx.r7.u64 + ctx.r26.u64;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r8,-4
	ctx.r7.s64 = ctx.r8.s64 + -4;
	// addi r8,r6,-4
	ctx.r8.s64 = ctx.r6.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
loc_82669D2C:
	// lfs f0,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// lfs f13,8(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r7)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// lfs f12,12(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,12(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// lfsu f0,16(r8)
	ea = 16 + ctx.r8.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r8.u32 = ea;
	// stfsu f0,16(r7)
	ea = 16 + ctx.r7.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x82669d2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82669D2C;
loc_82669D50:
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x82669d8c
	if (!ctx.cr6.lt) goto loc_82669D8C;
	// add r7,r11,r24
	ctx.r7.u64 = ctx.r11.u64 + ctx.r24.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r11,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r11.u64;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r8,r26
	ctx.r9.u64 = ctx.r8.u64 + ctx.r26.u64;
	// add r8,r7,r26
	ctx.r8.u64 = ctx.r7.u64 + ctx.r26.u64;
	// addi r7,r9,-4
	ctx.r7.s64 = ctx.r9.s64 + -4;
	// addi r9,r8,-4
	ctx.r9.s64 = ctx.r8.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82669D80:
	// lfsu f0,4(r9)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r9.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r9.u32 = ea;
	// stfsu f0,4(r7)
	ea = 4 + ctx.r7.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x82669d80
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82669D80;
loc_82669D8C:
	// neg r10,r11
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// blt cr6,0x82669e50
	if (ctx.cr6.lt) goto loc_82669E50;
	// subfic r10,r11,-4
	ctx.xer.ca = ctx.r11.u32 <= 4294967292;
	ctx.r10.u64 = static_cast<uint64_t>(-4) - ctx.r11.u64;
	// add r8,r11,r24
	ctx.r8.u64 = ctx.r11.u64 + ctx.r24.u64;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r26
	ctx.r9.u64 = ctx.r9.u64 + ctx.r26.u64;
	// add r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 + ctx.r22.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r10,r8,-2
	ctx.r10.s64 = ctx.r8.s64 + -2;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
loc_82669DCC:
	// lhz r5,4(r10)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// lhz r4,2(r10)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// lhz r6,6(r10)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// extsh r7,r5
	ctx.r7.s64 = ctx.r5.s16;
	// lhzu r8,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r8.u64 = REX_LOAD_U16(ea);
	ctx.r10.u32 = ea;
	// extsh r5,r4
	ctx.r5.s64 = ctx.r4.s16;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// std r7,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// std r5,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// std r6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r4.u64);
	// lfd f9,104(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lfd f11,96(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// frsp f6,f12
	ctx.f6.f64 = double(float(ctx.f12.f64));
	// frsp f5,f10
	ctx.f5.f64 = double(float(ctx.f10.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// fmuls f2,f6,f30
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f30.f64));
	// stfs f2,8(r9)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// fmuls f1,f5,f30
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f30.f64));
	// stfs f1,12(r9)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// fmuls f0,f4,f30
	ctx.f0.f64 = double(float(ctx.f4.f64 * ctx.f30.f64));
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fmuls f13,f3,f30
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f30.f64));
	// stfsu f13,16(r9)
	ea = 16 + ctx.r9.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82669dcc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82669DCC;
loc_82669E50:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82669ea0
	if (!ctx.cr6.lt) goto loc_82669EA0;
	// add r9,r11,r24
	ctx.r9.u64 = ctx.r11.u64 + ctx.r24.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r8,r11
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r26
	ctx.r11.u64 = ctx.r10.u64 + ctx.r26.u64;
	// add r9,r9,r22
	ctx.r9.u64 = ctx.r9.u64 + ctx.r22.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// addi r11,r9,-2
	ctx.r11.s64 = ctx.r9.s64 + -2;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82669E7C:
	// lhzu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// std r8,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r8.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// stfsu f11,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82669e7c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82669E7C;
loc_82669EA0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
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

DEFINE_REX_FUNC(sub_82695808) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82695810;
	__savegprlr_23(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r23,28(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r30,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// addi r24,r4,-24
	ctx.r24.s64 = ctx.r4.s64 + -24;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// stw r24,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r24.u32);
	// lwz r3,0(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// std r30,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r30.u64);
	// sth r30,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r30.u16);
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8269585C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82695a10
	if (ctx.cr6.lt) goto loc_82695A10;
	// cmplwi cr6,r24,16
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 16, ctx.xer);
	// blt cr6,0x82695a08
	if (ctx.cr6.lt) goto loc_82695A08;
	// addi r7,r1,92
	ctx.r7.s64 = ctx.r1.s64 + 92;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r25,16
	ctx.r25.s64 = 16;
	// bl 0x82691508
	ctx.lr = 0x8269588C;
	sub_82691508(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82695a10
	if (ctx.cr6.lt) goto loc_82695A10;
	// cmplwi cr6,r24,32
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 32, ctx.xer);
	// blt cr6,0x82695a08
	if (ctx.cr6.lt) goto loc_82695A08;
	// addi r7,r1,92
	ctx.r7.s64 = ctx.r1.s64 + 92;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r25,32
	ctx.r25.s64 = 32;
	// bl 0x82691338
	ctx.lr = 0x826958BC;
	sub_82691338(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82695a10
	if (ctx.cr6.lt) goto loc_82695A10;
	// ld r9,104(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// li r10,10000
	ctx.r10.s64 = 10000;
	// addi r7,r1,92
	ctx.r7.s64 = ctx.r1.s64 + 92;
	// divwu r8,r9,r10
	ctx.r8.u64 = uint32_t(ctx.r10.u32 ? ctx.r9.u32 / ctx.r10.u32 : 0);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// stw r8,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r8.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826911a0
	ctx.lr = 0x826958F0;
	sub_826911A0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82695a10
	if (ctx.cr6.lt) goto loc_82695A10;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r7,r1,92
	ctx.r7.s64 = ctx.r1.s64 + 92;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
	// bl 0x826911a0
	ctx.lr = 0x8269591C;
	sub_826911A0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82695a10
	if (ctx.cr6.lt) goto loc_82695A10;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stb r29,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r29.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,12(r27)
	REX_STORE_U32(ctx.r27.u32 + 12, ctx.r11.u32);
	// beq cr6,0x82695a10
	if (ctx.cr6.eq) goto loc_82695A10;
	// addi r29,r27,16
	ctx.r29.s64 = ctx.r27.s64 + 16;
	// lwz r3,224(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 224);
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x8268f7e0
	ctx.lr = 0x82695954;
	sub_8268F7E0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82695a10
	if (ctx.cr6.lt) goto loc_82695A10;
	// lwz r11,12(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8273a590
	ctx.lr = 0x82695974;
	sub_8273A590(ctx, base);
	// lwz r10,12(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82695a10
	if (!ctx.cr6.gt) goto loc_82695A10;
	// li r29,38
	ctx.r29.s64 = 38;
	// addi r26,r11,-4
	ctx.r26.s64 = ctx.r11.s64 + -4;
loc_8269598C:
	// cmplw cr6,r29,r24
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r24.u32, ctx.xer);
	// bgt cr6,0x82695a08
	if (ctx.cr6.gt) goto loc_82695A08;
	// addi r7,r1,92
	ctx.r7.s64 = ctx.r1.s64 + 92;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r25,r25,6
	ctx.r25.s64 = ctx.r25.s64 + 6;
	// addi r29,r29,6
	ctx.r29.s64 = ctx.r29.s64 + 6;
	// bl 0x826911a0
	ctx.lr = 0x826959B4;
	sub_826911A0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82695a10
	if (ctx.cr6.lt) goto loc_82695A10;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r7,r1,92
	ctx.r7.s64 = ctx.r1.s64 + 92;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// bl 0x82691020
	ctx.lr = 0x826959E0;
	sub_82691020(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82695a10
	if (ctx.cr6.lt) goto loc_82695A10;
	// lhz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// sthu r11,8(r26)
	ea = 8 + ctx.r26.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r26.u32 = ea;
	// lwz r10,12(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8269598c
	if (ctx.cr6.lt) goto loc_8269598C;
	// b 0x82695a10
	goto loc_82695A10;
loc_82695A08:
	// lis r31,-32688
	ctx.r31.s64 = -2142240768;
	// ori r31,r31,12
	ctx.r31.u64 = ctx.r31.u64 | 12;
loc_82695A10:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r10,r11,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r11.u64;
	// subf. r30,r25,r10
	ctx.r30.u64 = ctx.r10.u64 - ctx.r25.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82695a54
	if (ctx.cr0.eq) goto loc_82695A54;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82695A38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82695a10
	if (ctx.cr6.lt) goto loc_82695A10;
	// ld r11,8(r23)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r23.u32 + 8);
	// clrldi r10,r30,32
	ctx.r10.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r11,8(r23)
	REX_STORE_U64(ctx.r23.u32 + 8, ctx.r11.u64);
loc_82695A54:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8269F778) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8269F780;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r29,-1
	ctx.r29.s64 = -1;
	// std r30,20672(r3)
	REX_STORE_U64(ctx.r3.u32 + 20672, ctx.r30.u64);
	// std r30,20680(r3)
	REX_STORE_U64(ctx.r3.u32 + 20680, ctx.r30.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,20652(r3)
	REX_STORE_U32(ctx.r3.u32 + 20652, ctx.r11.u32);
	// stw r30,20696(r3)
	REX_STORE_U32(ctx.r3.u32 + 20696, ctx.r30.u32);
	// stw r30,20700(r3)
	REX_STORE_U32(ctx.r3.u32 + 20700, ctx.r30.u32);
	// stw r30,20752(r3)
	REX_STORE_U32(ctx.r3.u32 + 20752, ctx.r30.u32);
	// stw r30,3444(r3)
	REX_STORE_U32(ctx.r3.u32 + 3444, ctx.r30.u32);
	// stw r30,20756(r3)
	REX_STORE_U32(ctx.r3.u32 + 20756, ctx.r30.u32);
	// std r30,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r30.u64);
	// stw r29,20852(r3)
	REX_STORE_U32(ctx.r3.u32 + 20852, ctx.r29.u32);
	// bl 0x82748820
	ctx.lr = 0x8269F7C4;
	sub_82748820(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,-150
	ctx.r10.s64 = ctx.r11.s64 + -150;
	// stw r11,20864(r31)
	REX_STORE_U32(ctx.r31.u32 + 20864, ctx.r11.u32);
	// stw r10,20860(r31)
	REX_STORE_U32(ctx.r31.u32 + 20860, ctx.r10.u32);
	// bl 0x827484f0
	ctx.lr = 0x8269F7DC;
	sub_827484F0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8269f7e8
	if (!ctx.cr6.eq) goto loc_8269F7E8;
	// stw r30,20652(r31)
	REX_STORE_U32(ctx.r31.u32 + 20652, ctx.r30.u32);
loc_8269F7E8:
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r8,1000
	ctx.r8.s64 = 1000;
	// lwz r11,3680(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3680);
	// divd r9,r10,r8
	ctx.r9.s64 = (ctx.r8.s64 && !(ctx.r10.s64 == INT64_MIN && ctx.r8.s64 == -1)) ? ctx.r10.s64 / ctx.r8.s64 : 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,20856(r31)
	REX_STORE_U32(ctx.r31.u32 + 20856, ctx.r9.u32);
	// bgt cr6,0x8269f808
	if (ctx.cr6.gt) goto loc_8269F808;
	// li r11,30
	ctx.r11.s64 = 30;
loc_8269F808:
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rotldi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 1);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// divw. r3,r8,r11
	ctx.r3.u64 = uint32_t((ctx.r11.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r8.s32 / ctx.r11.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r3,20748(r31)
	REX_STORE_U32(ctx.r31.u32 + 20748, ctx.r3.u32);
	// divd r4,r10,r6
	ctx.r4.s64 = (ctx.r6.s64 && !(ctx.r10.s64 == INT64_MIN && ctx.r6.s64 == -1)) ? ctx.r10.s64 / ctx.r6.s64 : 0;
	// andc r11,r6,r5
	ctx.r11.u64 = ctx.r6.u64 & ~ctx.r5.u64;
	// tdllei r6,0
	if (ctx.r6.s64 == 0ll || ctx.r6.u64 < 0ull) ppc_trap(ctx, base, 0);
	// stw r4,20760(r31)
	REX_STORE_U32(ctx.r31.u32 + 20760, ctx.r4.u32);
	// tdlgei r11,-1
	if (ctx.r11.s64 == -1ll || ctx.r11.u64 > 18446744073709551615ull) ppc_trap(ctx, base, 0);
	// bgt 0x8269f844
	if (ctx.cr0.gt) goto loc_8269F844;
	// li r11,33
	ctx.r11.s64 = 33;
	// stw r11,20748(r31)
	REX_STORE_U32(ctx.r31.u32 + 20748, ctx.r11.u32);
loc_8269F844:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,114
	ctx.r4.s64 = 114;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x825be980
	ctx.lr = 0x8269F854;
	sub_825BE980(ctx, base);
	// cmpwi cr6,r3,100
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 100, ctx.xer);
	// blt cr6,0x8269f864
	if (ctx.cr6.lt) goto loc_8269F864;
	// cmpwi cr6,r3,32000
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 32000, ctx.xer);
	// ble cr6,0x8269f868
	if (!ctx.cr6.gt) goto loc_8269F868;
loc_8269F864:
	// li r3,100
	ctx.r3.s64 = 100;
loc_8269F868:
	// lwz r11,20856(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20856);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lwz r9,188(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// extsw r7,r11
	ctx.r7.s64 = ctx.r11.s32;
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// std r7,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r6,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// lwz r5,180(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// extsw r3,r5
	ctx.r3.s64 = ctx.r5.s32;
	// lfs f0,7420(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 7420);
	ctx.f0.f64 = double(temp.f32);
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// std r3,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// lfd f7,88(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// frsp f5,f10
	ctx.f5.f64 = double(float(ctx.f10.f64));
	// lfs f13,7416(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 7416);
	ctx.f13.f64 = double(temp.f32);
	// frsp f4,f9
	ctx.f4.f64 = double(float(ctx.f9.f64));
	// lfs f12,7412(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7412);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f3,f12,f8
	ctx.f3.f64 = double(float(ctx.f12.f64 / ctx.f8.f64));
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,114
	ctx.r4.s64 = 114;
	// li r3,5
	ctx.r3.s64 = 5;
	// fmuls f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// lfs f0,7408(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7408);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f4,f13
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fmuls f12,f2,f0
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// fmuls f11,f1,f13
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// fmuls f10,f11,f3
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f3.f64));
	// fmuls f31,f10,f12
	ctx.f31.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// bl 0x825be980
	ctx.lr = 0x8269F910;
	sub_825BE980(ctx, base);
	// stw r29,20664(r31)
	REX_STORE_U32(ctx.r31.u32 + 20664, ctx.r29.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r3,20660(r31)
	REX_STORE_U32(ctx.r31.u32 + 20660, ctx.r3.u32);
	// bne cr6,0x8269f928
	if (!ctx.cr6.eq) goto loc_8269F928;
	// stw r30,20652(r31)
	REX_STORE_U32(ctx.r31.u32 + 20652, ctx.r30.u32);
	// b 0x8269f974
	goto loc_8269F974;
loc_8269F928:
	// cmpwi cr6,r3,15
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 15, ctx.xer);
	// ble cr6,0x8269f974
	if (!ctx.cr6.gt) goto loc_8269F974;
	// lwz r10,20760(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20760);
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// clrlwi r6,r11,16
	ctx.r6.u64 = ctx.r11.u32 & 0xFFFF;
	// std r7,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r6,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lfd f0,7400(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 7400);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// fmul f9,f10,f0
	ctx.f9.f64 = ctx.f10.f64 * ctx.f0.f64;
	// fmul f8,f9,f11
	ctx.f8.f64 = ctx.f9.f64 * ctx.f11.f64;
	// fctiwz f7,f8
	ctx.f7.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// li r12,20760
	ctx.r12.s64 = 20760;
	// stfiwx f7,r31,r12
	REX_STORE_U32(ctx.r31.u32 + ctx.r12.u32, ctx.f7.u32);
loc_8269F974:
	// lwz r11,20760(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20760);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r9,20764
	ctx.r9.s64 = 20764;
	// stw r30,20740(r31)
	REX_STORE_U32(ctx.r31.u32 + 20740, ctx.r30.u32);
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfd f0,7392(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 7392);
	// fmul f12,f13,f0
	ctx.f12.f64 = ctx.f13.f64 * ctx.f0.f64;
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.f11.u32);
loc_8269F9A4:
	// lwz r11,20740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20740);
	// lwz r10,20760(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20760);
	// addi r9,r11,5176
	ctx.r9.s64 = ctx.r11.s64 + 5176;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,20740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20740);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// rotlwi r6,r7,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,20740(r31)
	REX_STORE_U32(ctx.r31.u32 + 20740, ctx.r7.u32);
	// cmpwi cr6,r6,8
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 8, ctx.xer);
	// blt cr6,0x8269f9a4
	if (ctx.cr6.lt) goto loc_8269F9A4;
	// li r10,5
	ctx.r10.s64 = 5;
	// lwz r9,20760(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20760);
	// stw r30,20740(r31)
	REX_STORE_U32(ctx.r31.u32 + 20740, ctx.r30.u32);
	// addi r11,r31,20832
	ctx.r11.s64 = ctx.r31.s64 + 20832;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r31,20784
	ctx.r9.s64 = ctx.r31.s64 + 20784;
	// stw r8,20736(r31)
	REX_STORE_U32(ctx.r31.u32 + 20736, ctx.r8.u32);
	// subfic r8,r31,-20832
	ctx.xer.ca = ctx.r31.u32 <= 4294946464;
	ctx.r8.u64 = static_cast<uint64_t>(-20832) - ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r7,-64
	ctx.r7.s64 = -64;
	// addi r6,r10,7312
	ctx.r6.s64 = ctx.r10.s64 + 7312;
loc_8269FA00:
	// lwz r10,3948(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3948);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r10,r6,20
	ctx.r10.s64 = ctx.r6.s64 + 20;
	// bne cr6,0x8269fa14
	if (!ctx.cr6.eq) goto loc_8269FA14;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
loc_8269FA14:
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwzx r4,r5,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfiwx f10,r11,r7
	REX_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.f10.u32);
	// stdu r30,8(r9)
	ea = 8 + ctx.r9.u32;
	REX_STORE_U64(ea, ctx.r30.u64);
	ctx.r9.u32 = ea;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8269fa00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8269FA00;
	// lwz r11,20784(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20784);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,188(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r4,180(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// stw r11,20788(r31)
	REX_STORE_U32(ctx.r31.u32 + 20788, ctx.r11.u32);
	// bl 0x826c8370
	ctx.lr = 0x8269FA64;
	sub_826C8370(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826CDB30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r9,15364(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 15364);
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// lwz r7,15360(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 15360);
	// addi r5,r1,-16
	ctx.r5.s64 = ctx.r1.s64 + -16;
	// lwz r11,3800(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 3800);
	// ori r4,r8,128
	ctx.r4.u64 = ctx.r8.u64 | 128;
	// lwz r10,3812(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 3812);
	// mullw r6,r9,r7
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// vspltisb v0,-1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0xFF)));
	// stw r4,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r4.u32);
	// vspltisw v12,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// srawi r9,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 4;
	// vmrghb v0,v12,v0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// or r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 | ctx.r11.u64;
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi r4,r8,28
	ctx.r4.u64 = ctx.r8.u32 & 0xF;
	// li r5,16
	ctx.r5.s64 = 16;
	// subf r7,r7,r6
	ctx.r7.u64 = ctx.r6.u64 - ctx.r7.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x826cdbd0
	if (ctx.cr6.eq) goto loc_826CDBD0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826cdbf8
	if (!ctx.cr6.gt) goto loc_826CDBF8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_826CDB9C:
	// lvrx128 v62,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lvrx128 v60,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v12,v61,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lvlx128 v59,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v11,v59,v60
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// vaddubs v10,v11,v12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_adds_epu8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// stvlx v10,0,r11
	ea = ctx.r11.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v10.u8[15 - i]);
	// stvrx v10,r11,r5
	ea = ctx.r11.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v10.u8[i]);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x826cdb9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDB9C;
	// b 0x826cdbf8
	goto loc_826CDBF8;
loc_826CDBD0:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826cdbf8
	if (!ctx.cr6.gt) goto loc_826CDBF8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CDBDC:
	// lvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// vaddubs v10,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_adds_epu8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// stvx128 v10,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x826cdbdc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDBDC;
loc_826CDBF8:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x826cdc2c
	if (!ctx.cr6.gt) goto loc_826CDC2C;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
loc_826CDC08:
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r7,1(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// add r11,r8,r7
	ctx.r11.u64 = ctx.r8.u64 + ctx.r7.u64;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x826cdc20
	if (!ctx.cr6.gt) goto loc_826CDC20;
	// li r11,255
	ctx.r11.s64 = 255;
loc_826CDC20:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826cdc08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDC08;
loc_826CDC2C:
	// srawi r9,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 2;
	// lwz r11,3804(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 3804);
	// lwz r10,3816(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 3816);
	// addze r6,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r6.s64 = temp.s64;
	// or r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 | ctx.r11.u64;
	// srawi r9,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 4;
	// clrlwi r7,r8,28
	ctx.r7.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r4,r9,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// subf r7,r4,r6
	ctx.r7.u64 = ctx.r6.u64 - ctx.r4.u64;
	// beq cr6,0x826cdcd0
	if (ctx.cr6.eq) goto loc_826CDCD0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826cdd28
	if (!ctx.cr6.gt) goto loc_826CDD28;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_826CDC6C:
	// lvrx128 v58,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v57,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v56,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v55,v57,v58
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// lvlx128 v54,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// vor128 v53,v54,v56
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8)));
	// vupklsb128 v52,v55,v0
	simde_mm_store_si128((simde__m128i*)ctx.v52.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v55.s16)));
	// vupkhsb128 v51,v55,v0
	simde_mm_store_si128((simde__m128i*)ctx.v51.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v55.s8), simde_mm_load_si128((simde__m128i*)ctx.v55.s8))));
	// vupklsb128 v50,v53,v0
	simde_mm_store_si128((simde__m128i*)ctx.v50.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v53.s16)));
	// vupkhsb128 v49,v53,v0
	simde_mm_store_si128((simde__m128i*)ctx.v49.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v53.s8), simde_mm_load_si128((simde__m128i*)ctx.v53.s8))));
	// vand128 v12,v52,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v11,v51,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v10,v50,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v9,v49,v0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddshs v8,v12,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v7,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v7.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vsubshs v6,v8,v13
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vsubshs v5,v7,v13
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vpkshus128 v48,v5,v6
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// stvlx128 v48,r0,r11
	ea = ctx.r11.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v48.u8[15 - i]);
	// stvrx128 v48,r11,r5
	ea = ctx.r11.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v48.u8[i]);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x826cdc6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDC6C;
	// b 0x826cdd28
	goto loc_826CDD28;
loc_826CDCD0:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826cdd28
	if (!ctx.cr6.gt) goto loc_826CDD28;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CDCDC:
	// lvx128 v47,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupklsb128 v45,v47,v0
	simde_mm_store_si128((simde__m128i*)ctx.v45.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v47.s16)));
	// vupklsb128 v44,v46,v0
	simde_mm_store_si128((simde__m128i*)ctx.v44.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v46.s16)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// vupkhsb128 v43,v46,v0
	simde_mm_store_si128((simde__m128i*)ctx.v43.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v46.s8), simde_mm_load_si128((simde__m128i*)ctx.v46.s8))));
	// vupkhsb128 v42,v47,v0
	simde_mm_store_si128((simde__m128i*)ctx.v42.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v47.s8), simde_mm_load_si128((simde__m128i*)ctx.v47.s8))));
	// vand128 v12,v45,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v11,v44,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v10,v43,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v9,v42,v0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddshs v8,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v7,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v7.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vsubshs v6,v8,v13
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vsubshs v5,v7,v13
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vpkshus128 v41,v5,v6
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// stvx128 v41,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x826cdcdc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDCDC;
loc_826CDD28:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x826cdd70
	if (!ctx.cr6.gt) goto loc_826CDD70;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
loc_826CDD38:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r7,1(r8)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r8.u32 + 1);
	// add r11,r9,r7
	ctx.r11.u64 = ctx.r9.u64 + ctx.r7.u64;
	// addi r11,r11,-128
	ctx.r11.s64 = ctx.r11.s64 + -128;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x826cdd58
	if (!ctx.cr6.gt) goto loc_826CDD58;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x826cdd64
	goto loc_826CDD64;
loc_826CDD58:
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
loc_826CDD64:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbu r11,1(r8)
	ea = 1 + ctx.r8.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r8.u32 = ea;
	// bdnz 0x826cdd38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDD38;
loc_826CDD70:
	// lwz r11,3808(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 3808);
	// srawi r9,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 4;
	// lwz r10,3820(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 3820);
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// or r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 | ctx.r11.u64;
	// subf r7,r8,r6
	ctx.r7.u64 = ctx.r6.u64 - ctx.r8.u64;
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826cde0c
	if (ctx.cr6.eq) goto loc_826CDE0C;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826cde64
	if (!ctx.cr6.gt) goto loc_826CDE64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_826CDDA8:
	// lvrx128 v40,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v39,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v38,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v37,v39,v40
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v40.u8)));
	// lvlx128 v36,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// vor128 v35,v36,v38
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)ctx.v38.u8)));
	// vupklsb128 v34,v37,v0
	simde_mm_store_si128((simde__m128i*)ctx.v34.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v37.s16)));
	// vupkhsb128 v33,v37,v0
	simde_mm_store_si128((simde__m128i*)ctx.v33.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v37.s8), simde_mm_load_si128((simde__m128i*)ctx.v37.s8))));
	// vupklsb128 v32,v35,v0
	simde_mm_store_si128((simde__m128i*)ctx.v32.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v35.s16)));
	// vupkhsb128 v63,v35,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v35.s8), simde_mm_load_si128((simde__m128i*)ctx.v35.s8))));
	// vand128 v12,v34,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v34.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v11,v33,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v33.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v10,v32,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v32.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v9,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddshs v8,v12,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v7,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v7.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vsubshs v6,v8,v13
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vsubshs v5,v7,v13
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vpkshus128 v62,v5,v6
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// stvlx128 v62,r0,r11
	ea = ctx.r11.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v62.u8[15 - i]);
	// stvrx128 v62,r11,r5
	ea = ctx.r11.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v62.u8[i]);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x826cdda8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDDA8;
	// b 0x826cde64
	goto loc_826CDE64;
loc_826CDE0C:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826cde64
	if (!ctx.cr6.gt) goto loc_826CDE64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CDE18:
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupklsb128 v59,v61,v0
	simde_mm_store_si128((simde__m128i*)ctx.v59.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v61.s16)));
	// vupklsb128 v58,v60,v0
	simde_mm_store_si128((simde__m128i*)ctx.v58.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v60.s16)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// vupkhsb128 v57,v60,v0
	simde_mm_store_si128((simde__m128i*)ctx.v57.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v60.s8), simde_mm_load_si128((simde__m128i*)ctx.v60.s8))));
	// vupkhsb128 v56,v61,v0
	simde_mm_store_si128((simde__m128i*)ctx.v56.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v61.s8), simde_mm_load_si128((simde__m128i*)ctx.v61.s8))));
	// vand128 v12,v59,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v11,v58,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v10,v57,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v9,v56,v0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddshs v8,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v7,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v7.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vsubshs v6,v8,v13
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vsubshs v5,v7,v13
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vpkshus128 v55,v5,v6
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// stvx128 v55,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x826cde18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDE18;
loc_826CDE64:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
loc_826CDE74:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r7,1(r8)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r8.u32 + 1);
	// add r11,r9,r7
	ctx.r11.u64 = ctx.r9.u64 + ctx.r7.u64;
	// addi r11,r11,-128
	ctx.r11.s64 = ctx.r11.s64 + -128;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x826cde94
	if (!ctx.cr6.gt) goto loc_826CDE94;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x826cdea0
	goto loc_826CDEA0;
loc_826CDE94:
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
loc_826CDEA0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbu r11,1(r8)
	ea = 1 + ctx.r8.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r8.u32 = ea;
	// bdnz 0x826cde74
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDE74;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826FE548) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x826FE550;
	__savegprlr_14(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r8,3740(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 3740);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,224(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 224);
	// lwz r15,128(r3)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r14,132(r3)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// lwz r9,220(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 220);
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r6,22368(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 22368);
	// add r16,r7,r11
	ctx.r16.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// add r17,r9,r10
	ctx.r17.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r27,156(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// lwz r26,160(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 160);
	// add r25,r8,r11
	ctx.r25.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r15,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r15.u32);
	// stw r14,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r14.u32);
	// stw r16,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r16.u32);
	// bne cr6,0x826fe5d8
	if (!ctx.cr6.eq) goto loc_826FE5D8;
	// lwz r29,22384(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 22384);
	// lwz r30,22388(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 22388);
	// lwz r28,22392(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 22392);
	// rlwinm r11,r29,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r30,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r22,22372(r3)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r3.u32 + 22372);
	// rlwinm r9,r28,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r21,22376(r3)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r3.u32 + 22376);
	// lwz r20,22380(r3)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r3.u32 + 22380);
	// stw r11,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// stw r10,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// stw r9,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// b 0x826fe618
	goto loc_826FE618;
loc_826FE5D8:
	// lwz r9,15652(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 15652);
	// lwz r10,15660(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15660);
	// lwz r11,15684(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15684);
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// lwz r7,15676(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 15676);
	// add r22,r10,r4
	ctx.r22.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lwz r9,15608(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 15608);
	// addze r30,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r30.s64 = temp.s64;
	// lwz r10,15612(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15612);
	// lwz r29,15652(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 15652);
	// add r21,r9,r22
	ctx.r21.u64 = ctx.r9.u64 + ctx.r22.u64;
	// stw r11,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// add r20,r10,r22
	ctx.r20.u64 = ctx.r10.u64 + ctx.r22.u64;
	// stw r7,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// stw r11,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
loc_826FE618:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269e6f0
	ctx.lr = 0x826FE620;
	sub_8269E6F0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826fe630
	if (ctx.cr6.eq) goto loc_826FE630;
	// lwz r27,15340(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// lwz r26,15344(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
loc_826FE630:
	// lwz r11,15928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15928);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826fe6b8
	if (ctx.cr6.eq) goto loc_826FE6B8;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// lwz r7,96(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bctrl 
	ctx.lr = 0x826FE65C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,15928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15928);
	// rlwinm r29,r27,31,1,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r7,108(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// rlwinm r27,r26,31,1,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bctrl 
	ctx.lr = 0x826FE688;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,15928(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15928);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// lwz r7,108(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FE6AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_826FE6B8:
	// li r19,0
	ctx.r19.s64 = 0;
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x826fe8ac
	if (ctx.cr6.eq) goto loc_826FE8AC;
loc_826FE6C4:
	// mr r28,r17
	ctx.r28.u64 = ctx.r17.u64;
	// li r18,0
	ctx.r18.s64 = 0;
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x826fe870
	if (ctx.cr6.eq) goto loc_826FE870;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// subf r27,r25,r16
	ctx.r27.u64 = ctx.r16.u64 - ctx.r25.u64;
	// subf r26,r25,r20
	ctx.r26.u64 = ctx.r20.u64 - ctx.r25.u64;
	// subf r24,r25,r21
	ctx.r24.u64 = ctx.r21.u64 - ctx.r25.u64;
	// subf r23,r17,r22
	ctx.r23.u64 = ctx.r22.u64 - ctx.r17.u64;
loc_826FE6E8:
	// addi r29,r15,-1
	ctx.r29.s64 = ctx.r15.s64 + -1;
	// cmplw cr6,r18,r29
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x826fe750
	if (ctx.cr6.eq) goto loc_826FE750;
	// addi r11,r14,-1
	ctx.r11.s64 = ctx.r14.s64 + -1;
	// cmplw cr6,r19,r11
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x826fe750
	if (ctx.cr6.eq) goto loc_826FE750;
	// lwz r11,15656(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15656);
	// add r9,r27,r30
	ctx.r9.u64 = ctx.r27.u64 + ctx.r30.u64;
	// lwz r10,15916(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15916);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r29,15652(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 15652);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// lwz r14,108(r31)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// add r6,r26,r30
	ctx.r6.u64 = ctx.r26.u64 + ctx.r30.u64;
	// add r5,r24,r30
	ctx.r5.u64 = ctx.r24.u64 + ctx.r30.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// add r4,r23,r28
	ctx.r4.u64 = ctx.r23.u64 + ctx.r28.u64;
	// stw r10,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,148(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// stw r14,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r14.u32);
	// bctrl 
	ctx.lr = 0x826FE74C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x826fe858
	goto loc_826FE858;
loc_826FE750:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269e6f0
	ctx.lr = 0x826FE758;
	sub_8269E6F0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826fe7a0
	if (ctx.cr6.eq) goto loc_826FE7A0;
	// cmplw cr6,r18,r29
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x826fe770
	if (ctx.cr6.eq) goto loc_826FE770;
	// li r29,16
	ctx.r29.s64 = 16;
	// b 0x826fe780
	goto loc_826FE780;
loc_826FE770:
	// lwz r11,15340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// lwz r10,15348(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15348);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r29,r11,16
	ctx.r29.s64 = ctx.r11.s64 + 16;
loc_826FE780:
	// addi r11,r14,-1
	ctx.r11.s64 = ctx.r14.s64 + -1;
	// cmplw cr6,r19,r11
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x826fe794
	if (ctx.cr6.eq) goto loc_826FE794;
	// li r11,16
	ctx.r11.s64 = 16;
	// b 0x826fe7fc
	goto loc_826FE7FC;
loc_826FE794:
	// lwz r11,15352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15352);
	// lwz r10,15344(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// b 0x826fe7dc
	goto loc_826FE7DC;
loc_826FE7A0:
	// cmplw cr6,r18,r29
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x826fe7b0
	if (ctx.cr6.eq) goto loc_826FE7B0;
	// li r29,16
	ctx.r29.s64 = 16;
	// b 0x826fe7c0
	goto loc_826FE7C0;
loc_826FE7B0:
	// lwz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r10,180(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r29,r11,16
	ctx.r29.s64 = ctx.r11.s64 + 16;
loc_826FE7C0:
	// addi r11,r14,-1
	ctx.r11.s64 = ctx.r14.s64 + -1;
	// cmplw cr6,r19,r11
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x826fe7d4
	if (ctx.cr6.eq) goto loc_826FE7D4;
	// li r11,16
	ctx.r11.s64 = 16;
	// b 0x826fe7fc
	goto loc_826FE7FC;
loc_826FE7D4:
	// lwz r11,188(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r10,160(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
loc_826FE7DC:
	// srawi r9,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 31;
	// xor r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 ^ ctx.r9.u64;
	// subf r7,r9,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r9.u64;
	// subfic r11,r7,16
	ctx.xer.ca = ctx.r7.u32 <= 16;
	ctx.r11.u64 = static_cast<uint64_t>(16) - ctx.r7.u64;
	// srawi r6,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 31;
	// xor r5,r10,r6
	ctx.r5.u64 = ctx.r10.u64 ^ ctx.r6.u64;
	// subf r10,r6,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r6.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_826FE7FC:
	// lwz r16,15656(r31)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r31.u32 + 15656);
	// add r9,r27,r30
	ctx.r9.u64 = ctx.r27.u64 + ctx.r30.u64;
	// lwz r10,15920(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15920);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r15,15652(r31)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r31.u32 + 15652);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// lwz r14,108(r31)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// add r6,r26,r30
	ctx.r6.u64 = ctx.r26.u64 + ctx.r30.u64;
	// add r5,r24,r30
	ctx.r5.u64 = ctx.r24.u64 + ctx.r30.u64;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// stw r16,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r16.u32);
	// add r4,r23,r28
	ctx.r4.u64 = ctx.r23.u64 + ctx.r28.u64;
	// stw r10,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r16,148(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// mtctr r16
	ctx.ctr.u64 = ctx.r16.u64;
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// stw r29,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// stw r15,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r15.u32);
	// stw r14,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r14.u32);
	// bctrl 
	ctx.lr = 0x826FE850;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r16,144(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r15,152(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
loc_826FE858:
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// lwz r14,128(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// addi r28,r28,16
	ctx.r28.s64 = ctx.r28.s64 + 16;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmplw cr6,r18,r15
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r15.u32, ctx.xer);
	// blt cr6,0x826fe6e8
	if (ctx.cr6.lt) goto loc_826FE6E8;
loc_826FE870:
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// lwz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r9,132(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// add r16,r11,r16
	ctx.r16.u64 = ctx.r11.u64 + ctx.r16.u64;
	// lwz r8,136(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// lwz r7,140(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// add r22,r9,r22
	ctx.r22.u64 = ctx.r9.u64 + ctx.r22.u64;
	// add r17,r17,r10
	ctx.r17.u64 = ctx.r17.u64 + ctx.r10.u64;
	// stw r16,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r16.u32);
	// add r21,r8,r21
	ctx.r21.u64 = ctx.r8.u64 + ctx.r21.u64;
	// add r20,r7,r20
	ctx.r20.u64 = ctx.r7.u64 + ctx.r20.u64;
	// cmplw cr6,r19,r14
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r14.u32, ctx.xer);
	// blt cr6,0x826fe6c4
	if (ctx.cr6.lt) goto loc_826FE6C4;
loc_826FE8AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82712778) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82712780;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,24(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,8(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r29,32
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 32, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// ble cr6,0x827127ac
	if (!ctx.cr6.gt) goto loc_827127AC;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8271285c
	goto loc_8271285C;
loc_827127AC:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x827127bc
	if (!ctx.cr6.eq) goto loc_827127BC;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8271285c
	goto loc_8271285C;
loc_827127BC:
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8271281c
	if (!ctx.cr6.gt) goto loc_8271281C;
loc_827127C4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8271281c
	if (ctx.cr6.eq) goto loc_8271281C;
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
	// bge 0x8271280c
	if (!ctx.cr0.lt) goto loc_8271280C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8271280C;
	sub_826C8B78(ctx, base);
loc_8271280C:
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827127c4
	if (ctx.cr6.gt) goto loc_827127C4;
loc_8271281C:
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
	// bge 0x82712858
	if (!ctx.cr0.lt) goto loc_82712858;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82712858;
	sub_826C8B78(ctx, base);
loc_82712858:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8271285C:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lwz r7,32(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// mullw r11,r6,r11
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8271288c
	if (!ctx.cr6.eq) goto loc_8271288C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
loc_8271288C:
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82712900
	if (!ctx.cr6.gt) goto loc_82712900;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
loc_827128A4:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// lbzu r8,1(r7)
	ea = 1 + ctx.r7.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r7.u32 = ea;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r6,r8,28
	ctx.r6.u64 = ctx.r8.u32 & 0xF;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r5,r6,1
	ctx.r5.s64 = ctx.r6.s64 + 1;
	// rlwinm r6,r8,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFFFF;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// addi r3,r6,1
	ctx.r3.s64 = ctx.r6.s64 + 1;
	// rlwimi r5,r4,0,0,25
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFC0) | (ctx.r5.u64 & 0xFFFFFFFF0000003F);
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwimi r3,r8,0,0,25
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFC0) | (ctx.r3.u64 & 0xFFFFFFFF0000003F);
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x827128a4
	if (ctx.cr6.lt) goto loc_827128A4;
loc_82712900:
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x82712128
	ctx.lr = 0x8271290C;
	sub_82712128(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r6,6
	ctx.r6.s64 = 6;
	// lwz r5,44(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r3,40(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8270c808
	ctx.lr = 0x82712924;
	sub_8270C808(ctx, base);
	// subfic r10,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// li r8,2
	ctx.r8.s64 = 2;
	// subfe r7,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r7,r8
	ctx.r3.u64 = ctx.r7.u64 & ctx.r8.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82725860) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x82725868;
	__savegprlr_14(ctx, base);
	// lis r11,-32121
	ctx.r11.s64 = -2105081856;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// stw r11,-160(r1)
	REX_STORE_U32(ctx.r1.u32 + -160, ctx.r11.u32);
	// rotlwi r7,r11,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32121
	ctx.r11.s64 = -2105081856;
	// addi r9,r9,-20792
	ctx.r9.s64 = ctx.r9.s64 + -20792;
	// addi r10,r10,8640
	ctx.r10.s64 = ctx.r10.s64 + 8640;
	// addi r8,r8,9000
	ctx.r8.s64 = ctx.r8.s64 + 9000;
	// stw r9,708(r4)
	REX_STORE_U32(ctx.r4.u32 + 708, ctx.r9.u32);
	// lis r30,-32121
	ctx.r30.s64 = -2105081856;
	// stw r10,704(r4)
	REX_STORE_U32(ctx.r4.u32 + 704, ctx.r10.u32);
	// addi r7,r7,9080
	ctx.r7.s64 = ctx.r7.s64 + 9080;
	// stw r8,712(r4)
	REX_STORE_U32(ctx.r4.u32 + 712, ctx.r8.u32);
	// addi r6,r6,9160
	ctx.r6.s64 = ctx.r6.s64 + 9160;
	// addi r5,r5,9280
	ctx.r5.s64 = ctx.r5.s64 + 9280;
	// stw r7,716(r4)
	REX_STORE_U32(ctx.r4.u32 + 716, ctx.r7.u32);
	// addi r3,r3,10208
	ctx.r3.s64 = ctx.r3.s64 + 10208;
	// stw r6,720(r4)
	REX_STORE_U32(ctx.r4.u32 + 720, ctx.r6.u32);
	// addi r11,r11,10320
	ctx.r11.s64 = ctx.r11.s64 + 10320;
	// stw r5,724(r4)
	REX_STORE_U32(ctx.r4.u32 + 724, ctx.r5.u32);
	// lis r31,-32121
	ctx.r31.s64 = -2105081856;
	// stw r3,728(r4)
	REX_STORE_U32(ctx.r4.u32 + 728, ctx.r3.u32);
	// lis r29,-32121
	ctx.r29.s64 = -2105081856;
	// stw r11,732(r4)
	REX_STORE_U32(ctx.r4.u32 + 732, ctx.r11.u32);
	// lis r28,-32121
	ctx.r28.s64 = -2105081856;
	// lis r27,-32121
	ctx.r27.s64 = -2105081856;
	// lis r26,-32121
	ctx.r26.s64 = -2105081856;
	// lis r25,-32121
	ctx.r25.s64 = -2105081856;
	// lis r24,-32121
	ctx.r24.s64 = -2105081856;
	// addi r9,r30,11384
	ctx.r9.s64 = ctx.r30.s64 + 11384;
	// addi r10,r31,11272
	ctx.r10.s64 = ctx.r31.s64 + 11272;
	// addi r8,r29,12320
	ctx.r8.s64 = ctx.r29.s64 + 12320;
	// stw r9,740(r4)
	REX_STORE_U32(ctx.r4.u32 + 740, ctx.r9.u32);
	// lis r22,-32121
	ctx.r22.s64 = -2105081856;
	// stw r10,736(r4)
	REX_STORE_U32(ctx.r4.u32 + 736, ctx.r10.u32);
	// addi r7,r28,12432
	ctx.r7.s64 = ctx.r28.s64 + 12432;
	// stw r8,744(r4)
	REX_STORE_U32(ctx.r4.u32 + 744, ctx.r8.u32);
	// addi r6,r27,13384
	ctx.r6.s64 = ctx.r27.s64 + 13384;
	// addi r5,r26,13504
	ctx.r5.s64 = ctx.r26.s64 + 13504;
	// stw r7,748(r4)
	REX_STORE_U32(ctx.r4.u32 + 748, ctx.r7.u32);
	// addi r3,r25,14440
	ctx.r3.s64 = ctx.r25.s64 + 14440;
	// stw r6,752(r4)
	REX_STORE_U32(ctx.r4.u32 + 752, ctx.r6.u32);
	// addi r11,r24,14552
	ctx.r11.s64 = ctx.r24.s64 + 14552;
	// stw r5,756(r4)
	REX_STORE_U32(ctx.r4.u32 + 756, ctx.r5.u32);
	// lis r23,-32121
	ctx.r23.s64 = -2105081856;
	// stw r3,760(r4)
	REX_STORE_U32(ctx.r4.u32 + 760, ctx.r3.u32);
	// lis r21,-32121
	ctx.r21.s64 = -2105081856;
	// stw r11,764(r4)
	REX_STORE_U32(ctx.r4.u32 + 764, ctx.r11.u32);
	// lis r20,-32121
	ctx.r20.s64 = -2105081856;
	// lis r19,-32121
	ctx.r19.s64 = -2105081856;
	// lis r18,-32121
	ctx.r18.s64 = -2105081856;
	// lis r17,-32120
	ctx.r17.s64 = -2105016320;
	// lis r16,-32120
	ctx.r16.s64 = -2105016320;
	// lis r14,-32120
	ctx.r14.s64 = -2105016320;
	// addi r9,r22,30776
	ctx.r9.s64 = ctx.r22.s64 + 30776;
	// addi r10,r23,28280
	ctx.r10.s64 = ctx.r23.s64 + 28280;
	// stw r14,-160(r1)
	REX_STORE_U32(ctx.r1.u32 + -160, ctx.r14.u32);
	// addi r8,r21,30968
	ctx.r8.s64 = ctx.r21.s64 + 30968;
	// stw r9,836(r4)
	REX_STORE_U32(ctx.r4.u32 + 836, ctx.r9.u32);
	// lis r15,-32120
	ctx.r15.s64 = -2105016320;
	// lwz r9,-160(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -160);
	// addi r7,r20,30872
	ctx.r7.s64 = ctx.r20.s64 + 30872;
	// stw r10,832(r4)
	REX_STORE_U32(ctx.r4.u32 + 832, ctx.r10.u32);
	// addi r6,r19,31056
	ctx.r6.s64 = ctx.r19.s64 + 31056;
	// stw r8,840(r4)
	REX_STORE_U32(ctx.r4.u32 + 840, ctx.r8.u32);
	// addi r5,r18,32320
	ctx.r5.s64 = ctx.r18.s64 + 32320;
	// stw r7,844(r4)
	REX_STORE_U32(ctx.r4.u32 + 844, ctx.r7.u32);
	// addi r3,r17,-27856
	ctx.r3.s64 = ctx.r17.s64 + -27856;
	// stw r6,848(r4)
	REX_STORE_U32(ctx.r4.u32 + 848, ctx.r6.u32);
	// addi r11,r16,-31880
	ctx.r11.s64 = ctx.r16.s64 + -31880;
	// stw r5,852(r4)
	REX_STORE_U32(ctx.r4.u32 + 852, ctx.r5.u32);
	// lis r14,-32120
	ctx.r14.s64 = -2105016320;
	// stw r3,856(r4)
	REX_STORE_U32(ctx.r4.u32 + 856, ctx.r3.u32);
	// addi r10,r15,-26624
	ctx.r10.s64 = ctx.r15.s64 + -26624;
	// stw r11,860(r4)
	REX_STORE_U32(ctx.r4.u32 + 860, ctx.r11.u32);
	// addi r8,r9,-26144
	ctx.r8.s64 = ctx.r9.s64 + -26144;
	// addi r7,r14,-23688
	ctx.r7.s64 = ctx.r14.s64 + -23688;
	// stw r10,864(r4)
	REX_STORE_U32(ctx.r4.u32 + 864, ctx.r10.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r8,868(r4)
	REX_STORE_U32(ctx.r4.u32 + 868, ctx.r8.u32);
	// stw r7,872(r4)
	REX_STORE_U32(ctx.r4.u32 + 872, ctx.r7.u32);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// stw r6,-160(r1)
	REX_STORE_U32(ctx.r1.u32 + -160, ctx.r6.u32);
	// rotlwi r10,r6,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// lis r11,-32120
	ctx.r11.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// addi r5,r5,-24928
	ctx.r5.s64 = ctx.r5.s64 + -24928;
	// addi r3,r3,31688
	ctx.r3.s64 = ctx.r3.s64 + 31688;
	// addi r11,r11,-30536
	ctx.r11.s64 = ctx.r11.s64 + -30536;
	// stw r5,876(r4)
	REX_STORE_U32(ctx.r4.u32 + 876, ctx.r5.u32);
	// addi r10,r10,-27240
	ctx.r10.s64 = ctx.r10.s64 + -27240;
	// stw r3,880(r4)
	REX_STORE_U32(ctx.r4.u32 + 880, ctx.r3.u32);
	// addi r9,r9,-29200
	ctx.r9.s64 = ctx.r9.s64 + -29200;
	// stw r11,884(r4)
	REX_STORE_U32(ctx.r4.u32 + 884, ctx.r11.u32);
	// addi r8,r8,-2024
	ctx.r8.s64 = ctx.r8.s64 + -2024;
	// stw r10,888(r4)
	REX_STORE_U32(ctx.r4.u32 + 888, ctx.r10.u32);
	// addi r7,r7,-1552
	ctx.r7.s64 = ctx.r7.s64 + -1552;
	// stw r9,892(r4)
	REX_STORE_U32(ctx.r4.u32 + 892, ctx.r9.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r8,964(r4)
	REX_STORE_U32(ctx.r4.u32 + 964, ctx.r8.u32);
	// lis r31,-32120
	ctx.r31.s64 = -2105016320;
	// stw r7,968(r4)
	REX_STORE_U32(ctx.r4.u32 + 968, ctx.r7.u32);
	// lis r30,-32120
	ctx.r30.s64 = -2105016320;
	// lis r29,-32120
	ctx.r29.s64 = -2105016320;
	// lis r28,-32120
	ctx.r28.s64 = -2105016320;
	// lis r27,-32120
	ctx.r27.s64 = -2105016320;
	// lis r26,-32120
	ctx.r26.s64 = -2105016320;
	// lis r25,-32120
	ctx.r25.s64 = -2105016320;
	// addi r6,r6,-1464
	ctx.r6.s64 = ctx.r6.s64 + -1464;
	// addi r5,r31,-1376
	ctx.r5.s64 = ctx.r31.s64 + -1376;
	// addi r3,r30,-1288
	ctx.r3.s64 = ctx.r30.s64 + -1288;
	// stw r6,972(r4)
	REX_STORE_U32(ctx.r4.u32 + 972, ctx.r6.u32);
	// addi r11,r29,-672
	ctx.r11.s64 = ctx.r29.s64 + -672;
	// stw r5,976(r4)
	REX_STORE_U32(ctx.r4.u32 + 976, ctx.r5.u32);
	// addi r10,r28,688
	ctx.r10.s64 = ctx.r28.s64 + 688;
	// stw r3,980(r4)
	REX_STORE_U32(ctx.r4.u32 + 980, ctx.r3.u32);
	// addi r9,r27,1328
	ctx.r9.s64 = ctx.r27.s64 + 1328;
	// stw r11,984(r4)
	REX_STORE_U32(ctx.r4.u32 + 984, ctx.r11.u32);
	// addi r8,r26,2704
	ctx.r8.s64 = ctx.r26.s64 + 2704;
	// stw r10,988(r4)
	REX_STORE_U32(ctx.r4.u32 + 988, ctx.r10.u32);
	// addi r7,r25,3192
	ctx.r7.s64 = ctx.r25.s64 + 3192;
	// stw r9,992(r4)
	REX_STORE_U32(ctx.r4.u32 + 992, ctx.r9.u32);
	// lis r24,-32120
	ctx.r24.s64 = -2105016320;
	// stw r8,996(r4)
	REX_STORE_U32(ctx.r4.u32 + 996, ctx.r8.u32);
	// lis r23,-32120
	ctx.r23.s64 = -2105016320;
	// stw r7,1000(r4)
	REX_STORE_U32(ctx.r4.u32 + 1000, ctx.r7.u32);
	// lis r22,-32120
	ctx.r22.s64 = -2105016320;
	// lis r21,-32120
	ctx.r21.s64 = -2105016320;
	// lis r20,-32120
	ctx.r20.s64 = -2105016320;
	// lis r19,-32120
	ctx.r19.s64 = -2105016320;
	// lis r18,-32121
	ctx.r18.s64 = -2105081856;
	// lis r17,-32120
	ctx.r17.s64 = -2105016320;
	// addi r6,r24,4440
	ctx.r6.s64 = ctx.r24.s64 + 4440;
	// addi r5,r23,4952
	ctx.r5.s64 = ctx.r23.s64 + 4952;
	// addi r3,r22,6224
	ctx.r3.s64 = ctx.r22.s64 + 6224;
	// stw r6,1004(r4)
	REX_STORE_U32(ctx.r4.u32 + 1004, ctx.r6.u32);
	// lis r16,-32120
	ctx.r16.s64 = -2105016320;
	// stw r5,1008(r4)
	REX_STORE_U32(ctx.r4.u32 + 1008, ctx.r5.u32);
	// lis r15,-32120
	ctx.r15.s64 = -2105016320;
	// stw r3,1012(r4)
	REX_STORE_U32(ctx.r4.u32 + 1012, ctx.r3.u32);
	// addi r11,r21,6840
	ctx.r11.s64 = ctx.r21.s64 + 6840;
	// addi r10,r20,8200
	ctx.r10.s64 = ctx.r20.s64 + 8200;
	// addi r9,r19,8840
	ctx.r9.s64 = ctx.r19.s64 + 8840;
	// stw r11,1016(r4)
	REX_STORE_U32(ctx.r4.u32 + 1016, ctx.r11.u32);
	// addi r8,r18,28280
	ctx.r8.s64 = ctx.r18.s64 + 28280;
	// stw r10,1020(r4)
	REX_STORE_U32(ctx.r4.u32 + 1020, ctx.r10.u32);
	// addi r7,r17,-17296
	ctx.r7.s64 = ctx.r17.s64 + -17296;
	// stw r9,1024(r4)
	REX_STORE_U32(ctx.r4.u32 + 1024, ctx.r9.u32);
	// lis r14,-32120
	ctx.r14.s64 = -2105016320;
	// stw r8,896(r4)
	REX_STORE_U32(ctx.r4.u32 + 896, ctx.r8.u32);
	// addi r6,r16,-17264
	ctx.r6.s64 = ctx.r16.s64 + -17264;
	// stw r7,900(r4)
	REX_STORE_U32(ctx.r4.u32 + 900, ctx.r7.u32);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// addi r3,r15,-17232
	ctx.r3.s64 = ctx.r15.s64 + -17232;
	// addi r11,r14,-17200
	ctx.r11.s64 = ctx.r14.s64 + -17200;
	// stw r6,904(r4)
	REX_STORE_U32(ctx.r4.u32 + 904, ctx.r6.u32);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// stw r3,908(r4)
	REX_STORE_U32(ctx.r4.u32 + 908, ctx.r3.u32);
	// addi r5,r5,-17168
	ctx.r5.s64 = ctx.r5.s64 + -17168;
	// stw r11,912(r4)
	REX_STORE_U32(ctx.r4.u32 + 912, ctx.r11.u32);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// stw r5,916(r4)
	REX_STORE_U32(ctx.r4.u32 + 916, ctx.r5.u32);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// addi r10,r10,-16600
	ctx.r10.s64 = ctx.r10.s64 + -16600;
	// addi r8,r8,-15096
	ctx.r8.s64 = ctx.r8.s64 + -15096;
	// lis r11,-32120
	ctx.r11.s64 = -2105016320;
	// stw r10,920(r4)
	REX_STORE_U32(ctx.r4.u32 + 920, ctx.r10.u32);
	// lis r30,-32120
	ctx.r30.s64 = -2105016320;
	// stw r8,928(r4)
	REX_STORE_U32(ctx.r4.u32 + 928, ctx.r8.u32);
	// addi r5,r3,-13080
	ctx.r5.s64 = ctx.r3.s64 + -13080;
	// addi r9,r9,-15184
	ctx.r9.s64 = ctx.r9.s64 + -15184;
	// addi r7,r7,-15064
	ctx.r7.s64 = ctx.r7.s64 + -15064;
	// stw r5,940(r4)
	REX_STORE_U32(ctx.r4.u32 + 940, ctx.r5.u32);
	// addi r6,r6,-14496
	ctx.r6.s64 = ctx.r6.s64 + -14496;
	// stw r9,924(r4)
	REX_STORE_U32(ctx.r4.u32 + 924, ctx.r9.u32);
	// lis r31,-32120
	ctx.r31.s64 = -2105016320;
	// stw r7,932(r4)
	REX_STORE_U32(ctx.r4.u32 + 932, ctx.r7.u32);
	// lis r28,-32121
	ctx.r28.s64 = -2105081856;
	// stw r6,936(r4)
	REX_STORE_U32(ctx.r4.u32 + 936, ctx.r6.u32);
	// lis r29,-32120
	ctx.r29.s64 = -2105016320;
	// lis r27,-32121
	ctx.r27.s64 = -2105081856;
	// lis r26,-32121
	ctx.r26.s64 = -2105081856;
	// lis r25,-32121
	ctx.r25.s64 = -2105081856;
	// addi r3,r11,-12992
	ctx.r3.s64 = ctx.r11.s64 + -12992;
	// addi r10,r30,-12392
	ctx.r10.s64 = ctx.r30.s64 + -12392;
	// addi r11,r31,-12960
	ctx.r11.s64 = ctx.r31.s64 + -12960;
	// stw r3,944(r4)
	REX_STORE_U32(ctx.r4.u32 + 944, ctx.r3.u32);
	// addi r8,r28,8640
	ctx.r8.s64 = ctx.r28.s64 + 8640;
	// stw r10,952(r4)
	REX_STORE_U32(ctx.r4.u32 + 952, ctx.r10.u32);
	// lis r22,-32121
	ctx.r22.s64 = -2105081856;
	// stw r11,948(r4)
	REX_STORE_U32(ctx.r4.u32 + 948, ctx.r11.u32);
	// addi r9,r29,-10976
	ctx.r9.s64 = ctx.r29.s64 + -10976;
	// stw r8,768(r4)
	REX_STORE_U32(ctx.r4.u32 + 768, ctx.r8.u32);
	// addi r7,r27,19408
	ctx.r7.s64 = ctx.r27.s64 + 19408;
	// addi r6,r26,19896
	ctx.r6.s64 = ctx.r26.s64 + 19896;
	// stw r9,956(r4)
	REX_STORE_U32(ctx.r4.u32 + 956, ctx.r9.u32);
	// addi r5,r25,19920
	ctx.r5.s64 = ctx.r25.s64 + 19920;
	// stw r7,772(r4)
	REX_STORE_U32(ctx.r4.u32 + 772, ctx.r7.u32);
	// lis r24,-32121
	ctx.r24.s64 = -2105081856;
	// stw r6,776(r4)
	REX_STORE_U32(ctx.r4.u32 + 776, ctx.r6.u32);
	// lis r23,-32121
	ctx.r23.s64 = -2105081856;
	// stw r5,780(r4)
	REX_STORE_U32(ctx.r4.u32 + 780, ctx.r5.u32);
	// lis r20,-32121
	ctx.r20.s64 = -2105081856;
	// lis r21,-32121
	ctx.r21.s64 = -2105081856;
	// lis r19,-32121
	ctx.r19.s64 = -2105081856;
	// lis r18,-32121
	ctx.r18.s64 = -2105081856;
	// lis r17,-32121
	ctx.r17.s64 = -2105081856;
	// lis r14,-32121
	ctx.r14.s64 = -2105081856;
	// addi r10,r22,21384
	ctx.r10.s64 = ctx.r22.s64 + 21384;
	// addi r3,r24,20408
	ctx.r3.s64 = ctx.r24.s64 + 20408;
	// stw r14,-160(r1)
	REX_STORE_U32(ctx.r1.u32 + -160, ctx.r14.u32);
	// addi r11,r23,20440
	ctx.r11.s64 = ctx.r23.s64 + 20440;
	// stw r10,792(r4)
	REX_STORE_U32(ctx.r4.u32 + 792, ctx.r10.u32);
	// addi r8,r20,23600
	ctx.r8.s64 = ctx.r20.s64 + 23600;
	// lwz r10,-160(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -160);
	// lis r16,-32121
	ctx.r16.s64 = -2105081856;
	// stw r3,784(r4)
	REX_STORE_U32(ctx.r4.u32 + 784, ctx.r3.u32);
	// lis r15,-32121
	ctx.r15.s64 = -2105081856;
	// stw r11,788(r4)
	REX_STORE_U32(ctx.r4.u32 + 788, ctx.r11.u32);
	// addi r9,r21,23152
	ctx.r9.s64 = ctx.r21.s64 + 23152;
	// stw r8,800(r4)
	REX_STORE_U32(ctx.r4.u32 + 800, ctx.r8.u32);
	// addi r7,r19,23632
	ctx.r7.s64 = ctx.r19.s64 + 23632;
	// addi r6,r18,24216
	ctx.r6.s64 = ctx.r18.s64 + 24216;
	// stw r9,796(r4)
	REX_STORE_U32(ctx.r4.u32 + 796, ctx.r9.u32);
	// addi r5,r17,25632
	ctx.r5.s64 = ctx.r17.s64 + 25632;
	// stw r7,804(r4)
	REX_STORE_U32(ctx.r4.u32 + 804, ctx.r7.u32);
	// lis r14,-32121
	ctx.r14.s64 = -2105081856;
	// stw r6,808(r4)
	REX_STORE_U32(ctx.r4.u32 + 808, ctx.r6.u32);
	// addi r3,r16,25712
	ctx.r3.s64 = ctx.r16.s64 + 25712;
	// stw r5,812(r4)
	REX_STORE_U32(ctx.r4.u32 + 812, ctx.r5.u32);
	// addi r11,r15,25744
	ctx.r11.s64 = ctx.r15.s64 + 25744;
	// addi r8,r10,26328
	ctx.r8.s64 = ctx.r10.s64 + 26328;
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r11,820(r4)
	REX_STORE_U32(ctx.r4.u32 + 820, ctx.r11.u32);
	// addi r7,r14,27744
	ctx.r7.s64 = ctx.r14.s64 + 27744;
	// stw r3,816(r4)
	REX_STORE_U32(ctx.r4.u32 + 816, ctx.r3.u32);
	// addi r10,r4,1032
	ctx.r10.s64 = ctx.r4.s64 + 1032;
	// stw r8,824(r4)
	REX_STORE_U32(ctx.r4.u32 + 824, ctx.r8.u32);
	// stw r7,828(r4)
	REX_STORE_U32(ctx.r4.u32 + 828, ctx.r7.u32);
	// addi r11,r10,-8
	ctx.r11.s64 = ctx.r10.s64 + -8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82725C58:
	// lis r9,-32142
	ctx.r9.s64 = -2106458112;
	// lis r8,-32142
	ctx.r8.s64 = -2106458112;
	// lis r7,-32142
	ctx.r7.s64 = -2106458112;
	// lis r6,-32142
	ctx.r6.s64 = -2106458112;
	// addi r5,r9,20968
	ctx.r5.s64 = ctx.r9.s64 + 20968;
	// addi r3,r8,20968
	ctx.r3.s64 = ctx.r8.s64 + 20968;
	// addi r9,r7,20968
	ctx.r9.s64 = ctx.r7.s64 + 20968;
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// addi r8,r6,20968
	ctx.r8.s64 = ctx.r6.s64 + 20968;
	// stw r3,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// stwu r8,16(r11)
	ea = 16 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82725c58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82725C58;
	// lis r11,-32120
	ctx.r11.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r11,r11,-10072
	ctx.r11.s64 = ctx.r11.s64 + -10072;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// stw r11,1028(r4)
	REX_STORE_U32(ctx.r4.u32 + 1028, ctx.r11.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// lis r31,-32120
	ctx.r31.s64 = -2105016320;
	// addi r9,r9,-9512
	ctx.r9.s64 = ctx.r9.s64 + -9512;
	// addi r8,r8,-9408
	ctx.r8.s64 = ctx.r8.s64 + -9408;
	// addi r7,r7,-9304
	ctx.r7.s64 = ctx.r7.s64 + -9304;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r6,r6,-9200
	ctx.r6.s64 = ctx.r6.s64 + -9200;
	// stw r8,1036(r4)
	REX_STORE_U32(ctx.r4.u32 + 1036, ctx.r8.u32);
	// addi r5,r5,-9096
	ctx.r5.s64 = ctx.r5.s64 + -9096;
	// stw r7,1040(r4)
	REX_STORE_U32(ctx.r4.u32 + 1040, ctx.r7.u32);
	// addi r3,r3,-8480
	ctx.r3.s64 = ctx.r3.s64 + -8480;
	// stw r6,1044(r4)
	REX_STORE_U32(ctx.r4.u32 + 1044, ctx.r6.u32);
	// addi r11,r31,-6936
	ctx.r11.s64 = ctx.r31.s64 + -6936;
	// stw r5,1048(r4)
	REX_STORE_U32(ctx.r4.u32 + 1048, ctx.r5.u32);
	// lis r30,-32120
	ctx.r30.s64 = -2105016320;
	// stw r3,1052(r4)
	REX_STORE_U32(ctx.r4.u32 + 1052, ctx.r3.u32);
	// lis r29,-32120
	ctx.r29.s64 = -2105016320;
	// stw r11,1056(r4)
	REX_STORE_U32(ctx.r4.u32 + 1056, ctx.r11.u32);
	// lis r28,-32120
	ctx.r28.s64 = -2105016320;
	// lis r27,-32120
	ctx.r27.s64 = -2105016320;
	// lis r26,-32120
	ctx.r26.s64 = -2105016320;
	// lis r25,-32120
	ctx.r25.s64 = -2105016320;
	// lis r24,-32120
	ctx.r24.s64 = -2105016320;
	// lis r23,-32120
	ctx.r23.s64 = -2105016320;
	// addi r10,r30,-6808
	ctx.r10.s64 = ctx.r30.s64 + -6808;
	// addi r9,r29,-6704
	ctx.r9.s64 = ctx.r29.s64 + -6704;
	// addi r8,r28,-6088
	ctx.r8.s64 = ctx.r28.s64 + -6088;
	// stw r10,1060(r4)
	REX_STORE_U32(ctx.r4.u32 + 1060, ctx.r10.u32);
	// addi r7,r27,-4544
	ctx.r7.s64 = ctx.r27.s64 + -4544;
	// stw r9,1064(r4)
	REX_STORE_U32(ctx.r4.u32 + 1064, ctx.r9.u32);
	// addi r6,r26,-4416
	ctx.r6.s64 = ctx.r26.s64 + -4416;
	// stw r8,1068(r4)
	REX_STORE_U32(ctx.r4.u32 + 1068, ctx.r8.u32);
	// addi r5,r25,-4312
	ctx.r5.s64 = ctx.r25.s64 + -4312;
	// stw r7,1072(r4)
	REX_STORE_U32(ctx.r4.u32 + 1072, ctx.r7.u32);
	// addi r3,r24,-3696
	ctx.r3.s64 = ctx.r24.s64 + -3696;
	// stw r6,1076(r4)
	REX_STORE_U32(ctx.r4.u32 + 1076, ctx.r6.u32);
	// addi r11,r23,-2152
	ctx.r11.s64 = ctx.r23.s64 + -2152;
	// stw r5,1080(r4)
	REX_STORE_U32(ctx.r4.u32 + 1080, ctx.r5.u32);
	// stw r3,1084(r4)
	REX_STORE_U32(ctx.r4.u32 + 1084, ctx.r3.u32);
	// stw r11,1088(r4)
	REX_STORE_U32(ctx.r4.u32 + 1088, ctx.r11.u32);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82739B18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lhz r11,16(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r11,r11,0,17,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FF0;
	// addi r11,r11,-32752
	ctx.r11.s64 = ctx.r11.s64 + -32752;
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

DEFINE_REX_FUNC(__savegprlr_27) {
	REX_FUNC_PROLOGUE();
	// std r27,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(__restgprlr_25) {
	REX_FUNC_PROLOGUE();
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

DEFINE_REX_FUNC(sub_8273ADC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// neg r12,r3
	ctx.r12.s64 = static_cast<int64_t>(-ctx.r3.u64);
	// neg r11,r12
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r12.u64);
	// addi r0,r11,4095
	ctx.r0.s64 = ctx.r11.s64 + 4095;
	// srawi. r0,r0,12
	ctx.xer.ca = (ctx.r0.s32 < 0) & ((ctx.r0.u32 & 0xFFF) != 0);
	ctx.r0.s64 = ctx.r0.s32 >> 12;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// blelr 
	if (!ctx.cr0.gt) return;
	// mr r11,r1
	ctx.r11.u64 = ctx.r1.u64;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
loc_8273ADDC:
	// lwzu r0,-4096(r11)
	ea = -4096 + ctx.r11.u32;
	ctx.r0.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// bdnz 0x8273addc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273ADDC;
	// blr 
	return;
}

DEFINE_REX_FUNC(__restfpr_16) {
	REX_FUNC_PROLOGUE();
	// lfd f16,-128(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f16.u64 = REX_LOAD_U64(ctx.r12.u32 + -128);
	// lfd f17,-120(r12)
	ctx.f17.u64 = REX_LOAD_U64(ctx.r12.u32 + -120);
	// lfd f18,-112(r12)
	ctx.f18.u64 = REX_LOAD_U64(ctx.r12.u32 + -112);
	// lfd f19,-104(r12)
	ctx.f19.u64 = REX_LOAD_U64(ctx.r12.u32 + -104);
	// lfd f20,-96(r12)
	ctx.f20.u64 = REX_LOAD_U64(ctx.r12.u32 + -96);
	// lfd f21,-88(r12)
	ctx.f21.u64 = REX_LOAD_U64(ctx.r12.u32 + -88);
	// lfd f22,-80(r12)
	ctx.f22.u64 = REX_LOAD_U64(ctx.r12.u32 + -80);
	// lfd f23,-72(r12)
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

DEFINE_REX_FUNC(__savevmx_78) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(__restvmx_124) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(sub_8273B8A0) {
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
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8273b8cc
	if (ctx.cr6.lt) goto loc_8273B8CC;
	// bl 0x82741d08
	ctx.lr = 0x8273B8C0;
	sub_82741D08(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8273b8d4
	if (ctx.cr6.lt) goto loc_8273B8D4;
loc_8273B8CC:
	// bl 0x82741d08
	ctx.lr = 0x8273B8D0;
	sub_82741D08(ctx, base);
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
loc_8273B8D4:
	// bl 0x82741d18
	ctx.lr = 0x8273B8D8;
	sub_82741D18(ctx, base);
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r3,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_8273C8E0) {
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
	// bl 0x8261bf80
	ctx.lr = 0x8273C8F8;
	sub_8261BF80(ctx, base);
	// bl 0x8273a940
	ctx.lr = 0x8273C8FC;
	sub_8273A940(ctx, base);
	// bl 0x8273a938
	ctx.lr = 0x8273C900;
	sub_8273A938(ctx, base);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8273c930
	if (!ctx.cr0.eq) goto loc_8273C930;
	// bl 0x8273a940
	ctx.lr = 0x8273C90C;
	sub_8273A940(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8273a950
	ctx.lr = 0x8273C914;
	sub_8273A950(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8273c924
	if (!ctx.cr0.eq) goto loc_8273C924;
	// bl 0x82639f50
	ctx.lr = 0x8273C920;
	sub_82639F50(ctx, base);
	// bl 0x82639f58
	ctx.lr = 0x8273C924;
	sub_82639F58(ctx, base);
loc_8273C924:
	// bl 0x827484a0
	ctx.lr = 0x8273C928;
	sub_827484A0(ctx, base);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// b 0x8273c950
	goto loc_8273C950;
loc_8273C930:
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r10.u32);
	// lwz r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stw r10,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x8273aac8
	ctx.lr = 0x8273C950;
	sub_8273AAC8(ctx, base);
loc_8273C950:
	// bl 0x8273c860
	ctx.lr = 0x8273C954;
	sub_8273C860(ctx, base);
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

DEFINE_REX_FUNC(sub_8273EB08) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lfd f0,24136(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 24136);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bne cr6,0x8273eb24
	if (!ctx.cr6.eq) goto loc_8273EB24;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8273ebf4
	goto loc_8273EBF4;
loc_8273EB24:
	// lhz r11,16(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm. r9,r11,0,17,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FF0;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8273ebcc
	if (!ctx.cr0.eq) goto loc_8273EBCC;
	// lwz r8,16(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 16);
	// lwz r10,20(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// clrlwi. r7,r8,12
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8273eb48
	if (!ctx.cr0.eq) goto loc_8273EB48;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8273ebcc
	if (ctx.cr6.eq) goto loc_8273EBCC;
loc_8273EB48:
	// li r9,-1021
	ctx.r9.s64 = -1021;
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// li r7,1
	ctx.r7.s64 = 1;
	// blt cr6,0x8273eb5c
	if (ctx.cr6.lt) goto loc_8273EB5C;
	// li r7,0
	ctx.r7.s64 = 0;
loc_8273EB5C:
	// rlwinm. r6,r11,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x8273eb94
	if (!ctx.cr0.eq) goto loc_8273EB94;
loc_8273EB64:
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm. r11,r10,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,16(r1)
	REX_STORE_U32(ctx.r1.u32 + 16, ctx.r8.u32);
	// beq 0x8273eb7c
	if (ctx.cr0.eq) goto loc_8273EB7C;
	// ori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 | 1;
	// stw r8,16(r1)
	REX_STORE_U32(ctx.r1.u32 + 16, ctx.r8.u32);
loc_8273EB7C:
	// lhz r11,16(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwinm. r6,r11,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x8273eb64
	if (ctx.cr0.eq) goto loc_8273EB64;
	// stw r10,20(r1)
	REX_STORE_U32(ctx.r1.u32 + 20, ctx.r10.u32);
loc_8273EB94:
	// andi. r11,r11,65519
	ctx.r11.u64 = ctx.r11.u64 & 65519;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// sth r11,16(r1)
	REX_STORE_U16(ctx.r1.u32 + 16, ctx.r11.u16);
	// beq cr6,0x8273ebac
	if (ctx.cr6.eq) goto loc_8273EBAC;
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// sth r11,16(r1)
	REX_STORE_U16(ctx.r1.u32 + 16, ctx.r11.u16);
loc_8273EBAC:
	// lfd f0,16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 16);
	// stfd f0,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lhz r11,-16(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + -16);
	// andi. r11,r11,32783
	ctx.r11.u64 = ctx.r11.u64 & 32783;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stfd f0,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// ori r11,r11,16352
	ctx.r11.u64 = ctx.r11.u64 | 16352;
	// sth r11,-16(r1)
	REX_STORE_U16(ctx.r1.u32 + -16, ctx.r11.u16);
	// b 0x8273ebf0
	goto loc_8273EBF0;
loc_8273EBCC:
	// stfd f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// lhz r11,-16(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + -16);
	// andi. r11,r11,32783
	ctx.r11.u64 = ctx.r11.u64 & 32783;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stfd f1,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// ori r11,r11,16352
	ctx.r11.u64 = ctx.r11.u64 | 16352;
	// rlwinm r10,r9,28,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFF;
	// sth r11,-16(r1)
	REX_STORE_U16(ctx.r1.u32 + -16, ctx.r11.u16);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// addi r9,r10,-1022
	ctx.r9.s64 = ctx.r10.s64 + -1022;
loc_8273EBF0:
	// lfd f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
loc_8273EBF4:
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82748A60) {
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
	// bl 0x828560e4
	ctx.lr = 0x82748A70;
	__imp__NtClearEvent(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82748a80
	if (ctx.cr0.lt) goto loc_82748A80;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82748a88
	goto loc_82748A88;
loc_82748A80:
	// bl 0x8263bc90
	ctx.lr = 0x82748A84;
	sub_8263BC90(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82748A88:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8274A0F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8274A0F8;
	__savegprlr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lwz r9,300(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 300);
	// lwz r31,292(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// lwz r30,284(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lwz r29,276(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// li r28,3
	ctx.r28.s64 = 3;
	// stw r9,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r31,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r30,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r28,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// stw r29,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r27,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// bl 0x82749ee8
	ctx.lr = 0x8274A154;
	sub_82749EE8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8274BED8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8274BEE0;
	__savegprlr_29(ctx, base);
	// li r12,-80
	ctx.r12.s64 = -80;
	// stvx128 v125,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-64
	ctx.r12.s64 = -64;
	// stvx128 v126,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-48
	ctx.r12.s64 = -48;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vmaxfp128 v63,v5,v1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_max_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v1.f32)));
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// vor128 v127,v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// vor128 v126,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// rlwinm r5,r11,29,3,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// vminfp128 v0,v6,v63
	simde_mm_store_ps(ctx.v0.f32, simde_mm_min_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v0,v0,v3,v4
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vor128 v125,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// bl 0x8273a590
	ctx.lr = 0x8274BF30;
	sub_8273A590(ctx, base);
	// vrfin128 v63,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_round_ps(simde_mm_load_ps(ctx.v125.f32), SIMDE_MM_FROUND_TO_NEAREST_INT | SIMDE_MM_FROUND_NO_EXC));
	// vor128 v0,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v125.u8));
	// vor128 v12,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
	// vcfpuxws128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, rex::ppc::simde_mm_vctuxs(simde_mm_load_ps(ctx.v63.f32)));
	// vsel128 v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vxor128 v1,v12,v126
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v126.u8)));
	// bctrl 
	ctx.lr = 0x8274BF58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// li r0,-80
	ctx.r0.s64 = -80;
	// lvx128 v125,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-64
	ctx.r0.s64 = -64;
	// lvx128 v126,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-48
	ctx.r0.s64 = -48;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827591E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x827591E8;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8273af20
	ctx.lr = 0x827591F0;
	__savefpr_26(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8275921c
	if (ctx.cr6.eq) goto loc_8275921C;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82753110
	ctx.lr = 0x82759218;
	sub_82753110(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_8275921C:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82759238
	if (ctx.cr6.eq) goto loc_82759238;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82755cf8
	ctx.lr = 0x82759234;
	sub_82755CF8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_82759238:
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// clrlwi. r4,r30,31
	ctx.r4.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// rlwinm r7,r30,3,27,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0x18;
	// mullw r9,r9,r4
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// lwz r6,32(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r5,52(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r8,r29,30
	ctx.r8.u64 = ctx.r29.u32 & 0x3;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lis r30,-32256
	ctx.r30.s64 = -2113929216;
	// mullw r10,r3,r29
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r29.s32);
	// lfs f31,2524(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2524);
	ctx.f31.f64 = double(temp.f32);
	// fmr f30,f31
	ctx.f30.f64 = ctx.f31.f64;
	// fmr f29,f31
	ctx.f29.f64 = ctx.f31.f64;
	// fmr f28,f31
	ctx.f28.f64 = ctx.f31.f64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r10,r6
	ctx.r28.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r24,r9,r5
	ctx.r24.u64 = ctx.r9.u64 + ctx.r5.u64;
	// bne 0x827592a8
	if (!ctx.cr0.eq) goto loc_827592A8;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,1
	ctx.r30.s64 = 1;
	// b 0x827592b0
	goto loc_827592B0;
loc_827592A8:
	// addi r29,r11,-1
	ctx.r29.s64 = ctx.r11.s64 + -1;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_827592B0:
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827592c8
	if (ctx.cr6.eq) goto loc_827592C8;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82756298
	ctx.lr = 0x827592C8;
	sub_82756298(ctx, base);
loc_827592C8:
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82759660
	if (!ctx.cr6.gt) goto loc_82759660;
	// rlwinm r10,r29,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r30,r29
	ctx.r9.u64 = ctx.r30.u64 + ctx.r29.u64;
	// subf r7,r30,r29
	ctx.r7.u64 = ctx.r29.u64 - ctx.r30.u64;
	// add r11,r10,r27
	ctx.r11.u64 = ctx.r10.u64 + ctx.r27.u64;
	// rlwinm r25,r30,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r29,r30,4,0,27
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// lis r4,-32249
	ctx.r4.s64 = -2113470464;
	// lfs f4,10788(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10788);
	ctx.f4.f64 = double(temp.f32);
	// lis r3,-32249
	ctx.r3.s64 = -2113470464;
	// lfd f11,25856(r7)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r7.u32 + 25856);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lfs f12,28428(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 28428);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-30548(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -30548);
	ctx.f13.f64 = double(temp.f32);
	// subf r28,r25,r28
	ctx.r28.u64 = ctx.r28.u64 - ctx.r25.u64;
	// lfs f0,-30552(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -30552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f10,-30512(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -30512);
	ctx.f10.f64 = double(temp.f32);
	// lfs f3,24184(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24184);
	ctx.f3.f64 = double(temp.f32);
	// lfs f5,-30516(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -30516);
	ctx.f5.f64 = double(temp.f32);
loc_82759340:
	// lfs f9,-8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -8);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r11,r26,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xC;
	// lfs f8,-4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f8.f64 = double(temp.f32);
	// fadds f9,f9,f31
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f31.f64));
	// lfs f7,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fadds f8,f8,f30
	ctx.f8.f64 = double(float(ctx.f8.f64 + ctx.f30.f64));
	// lfs f6,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fadds f7,f7,f29
	ctx.f7.f64 = double(float(ctx.f7.f64 + ctx.f29.f64));
	// fadds f6,f6,f28
	ctx.f6.f64 = double(float(ctx.f6.f64 + ctx.f28.f64));
	// lwz r7,92(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// lfsx f2,r11,r24
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	ctx.f2.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// fmuls f9,f9,f5
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f5.f64));
	// fmuls f8,f8,f5
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f5.f64));
	// fmuls f7,f7,f5
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f5.f64));
	// fmuls f6,f6,f3
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f3.f64));
	// fadds f1,f9,f2
	ctx.f1.f64 = double(float(ctx.f9.f64 + ctx.f2.f64));
	// fadds f27,f8,f2
	ctx.f27.f64 = double(float(ctx.f8.f64 + ctx.f2.f64));
	// fadds f26,f7,f2
	ctx.f26.f64 = double(float(ctx.f7.f64 + ctx.f2.f64));
	// fadds f2,f6,f2
	ctx.f2.f64 = double(float(ctx.f6.f64 + ctx.f2.f64));
	// fctiwz f1,f1
	ctx.f1.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f1,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// fctiwz f1,f27
	ctx.f1.s64 = std::isnan(ctx.f27.f64) ? int64_t(0x80000000U) : (ctx.f27.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f27.f64));
	// stfd f1,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f1.u64);
	// fctiwz f1,f26
	ctx.f1.s64 = std::isnan(ctx.f26.f64) ? int64_t(0x80000000U) : (ctx.f26.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f26.f64));
	// stfd f1,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f1.u64);
	// fctiwz f2,f2
	ctx.f2.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f2,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f2.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// beq cr6,0x82759574
	if (ctx.cr6.eq) goto loc_82759574;
	// extsw r7,r4
	ctx.r7.s64 = ctx.r4.s32;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// extsw r27,r3
	ctx.r27.s64 = ctx.r3.s32;
	// std r7,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f2,112(r1)
	ctx.f2.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r27,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r27.u64);
	// lfd f1,120(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f1,f1
	ctx.f1.f64 = double(ctx.f1.s64);
	// extsw r7,r5
	ctx.r7.s64 = ctx.r5.s32;
	// frsp f1,f1
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// std r7,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r7.u64);
	// fcfid f2,f2
	ctx.f2.f64 = double(ctx.f2.s64);
	// lfd f31,128(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// extsw r27,r6
	ctx.r27.s64 = ctx.r6.s32;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// std r27,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r27.u64);
	// lfs f30,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f30.f64 = double(temp.f32);
	// fsubs f9,f9,f1
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f1.f64));
	// frsp f2,f2
	ctx.f2.f64 = double(float(ctx.f2.f64));
	// fmuls f9,f9,f10
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fsubs f8,f8,f2
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f2.f64));
	// fmadds f2,f9,f0,f30
	ctx.f2.f64 = double(float(std::fma(ctx.f9.f64, ctx.f0.f64, ctx.f30.f64)));
	// stfs f2,16(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lfs f2,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// fmadds f2,f9,f13,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f9.f64, ctx.f13.f64, ctx.f2.f64)));
	// stfs f2,16(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// fcfid f2,f31
	ctx.f2.f64 = double(ctx.f31.s64);
	// lfs f1,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f8,f8,f10
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// fmadds f1,f9,f12,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f9.f64, ctx.f12.f64, ctx.f1.f64)));
	// stfs f1,16(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// frsp f2,f2
	ctx.f2.f64 = double(float(ctx.f2.f64));
	// lfs f1,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f1,f8,f0,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f8.f64, ctx.f0.f64, ctx.f1.f64)));
	// stfs f1,20(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// addi r7,r11,20
	ctx.r7.s64 = ctx.r11.s64 + 20;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// fsubs f7,f7,f2
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f2.f64));
	// lfs f2,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f2,f8,f13,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f8.f64, ctx.f13.f64, ctx.f2.f64)));
	// stfs f2,20(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// addi r7,r11,20
	ctx.r7.s64 = ctx.r11.s64 + 20;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lfs f2,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f7,f7,f10
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// fmadds f2,f8,f12,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f8.f64, ctx.f12.f64, ctx.f2.f64)));
	// stfs f2,20(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// addi r7,r11,20
	ctx.r7.s64 = ctx.r11.s64 + 20;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// fmul f9,f9,f11
	ctx.f9.f64 = ctx.f9.f64 * ctx.f11.f64;
	// lfs f2,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f2,f7,f0,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f7.f64, ctx.f0.f64, ctx.f2.f64)));
	// stfs f2,24(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// addi r7,r11,24
	ctx.r7.s64 = ctx.r11.s64 + 24;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// fmul f8,f8,f11
	ctx.f8.f64 = ctx.f8.f64 * ctx.f11.f64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// frsp f31,f9
	ctx.f31.f64 = double(float(ctx.f9.f64));
	// lfs f9,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f9,f7,f13,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f7.f64, ctx.f13.f64, ctx.f9.f64)));
	// stfs f9,24(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// addi r7,r11,24
	ctx.r7.s64 = ctx.r11.s64 + 24;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// frsp f30,f8
	ctx.f30.f64 = double(float(ctx.f8.f64));
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lfd f8,136(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// fmul f9,f7,f11
	ctx.f9.f64 = ctx.f7.f64 * ctx.f11.f64;
	// addi r7,r11,24
	ctx.r7.s64 = ctx.r11.s64 + 24;
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// lfs f2,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f2.f64 = double(temp.f32);
	// frsp f29,f9
	ctx.f29.f64 = double(float(ctx.f9.f64));
	// fmadds f7,f7,f12,f2
	ctx.f7.f64 = double(float(std::fma(ctx.f7.f64, ctx.f12.f64, ctx.f2.f64)));
	// stfs f7,24(r11)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// fsubs f9,f6,f8
	ctx.f9.f64 = double(float(ctx.f6.f64 - ctx.f8.f64));
	// lfs f8,28(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// addi r7,r11,28
	ctx.r7.s64 = ctx.r11.s64 + 28;
	// fmuls f9,f9,f4
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f4.f64));
	// fmadds f8,f9,f0,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f9.f64, ctx.f0.f64, ctx.f8.f64)));
	// stfs f8,28(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lfs f8,28(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f8,f9,f13,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f9.f64, ctx.f13.f64, ctx.f8.f64)));
	// fmul f7,f9,f11
	ctx.f7.f64 = ctx.f9.f64 * ctx.f11.f64;
	// stfs f8,28(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// addi r7,r11,28
	ctx.r7.s64 = ctx.r11.s64 + 28;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lfs f8,28(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f9,f9,f12,f8
	ctx.f9.f64 = double(float(std::fma(ctx.f9.f64, ctx.f12.f64, ctx.f8.f64)));
	// stfs f9,28(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// frsp f28,f7
	ctx.f28.f64 = double(float(ctx.f7.f64));
	// addi r7,r11,28
	ctx.r7.s64 = ctx.r11.s64 + 28;
loc_82759574:
	// cmpwi cr6,r3,1023
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1023, ctx.xer);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// blt cr6,0x82759584
	if (ctx.cr6.lt) goto loc_82759584;
	// li r11,1023
	ctx.r11.s64 = 1023;
loc_82759584:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8275959c
	if (!ctx.cr6.gt) goto loc_8275959C;
	// cmpwi cr6,r3,1023
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1023, ctx.xer);
	// blt cr6,0x827595a0
	if (ctx.cr6.lt) goto loc_827595A0;
	// li r3,1023
	ctx.r3.s64 = 1023;
	// b 0x827595a0
	goto loc_827595A0;
loc_8275959C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827595A0:
	// cmpwi cr6,r4,1023
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1023, ctx.xer);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// blt cr6,0x827595b0
	if (ctx.cr6.lt) goto loc_827595B0;
	// li r11,1023
	ctx.r11.s64 = 1023;
loc_827595B0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x827595c8
	if (!ctx.cr6.gt) goto loc_827595C8;
	// cmpwi cr6,r4,1023
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1023, ctx.xer);
	// blt cr6,0x827595cc
	if (ctx.cr6.lt) goto loc_827595CC;
	// li r4,1023
	ctx.r4.s64 = 1023;
	// b 0x827595cc
	goto loc_827595CC;
loc_827595C8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_827595CC:
	// cmpwi cr6,r5,1023
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1023, ctx.xer);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// blt cr6,0x827595dc
	if (ctx.cr6.lt) goto loc_827595DC;
	// li r11,1023
	ctx.r11.s64 = 1023;
loc_827595DC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x827595f4
	if (!ctx.cr6.gt) goto loc_827595F4;
	// cmpwi cr6,r5,1023
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1023, ctx.xer);
	// blt cr6,0x827595f8
	if (ctx.cr6.lt) goto loc_827595F8;
	// li r5,1023
	ctx.r5.s64 = 1023;
	// b 0x827595f8
	goto loc_827595F8;
loc_827595F4:
	// li r5,0
	ctx.r5.s64 = 0;
loc_827595F8:
	// cmpwi cr6,r6,3
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 3, ctx.xer);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// blt cr6,0x82759608
	if (ctx.cr6.lt) goto loc_82759608;
	// li r11,3
	ctx.r11.s64 = 3;
loc_82759608:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82759620
	if (!ctx.cr6.gt) goto loc_82759620;
	// cmpwi cr6,r6,3
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 3, ctx.xer);
	// blt cr6,0x82759624
	if (ctx.cr6.lt) goto loc_82759624;
	// li r6,3
	ctx.r6.s64 = 3;
	// b 0x82759624
	goto loc_82759624;
loc_82759620:
	// li r6,0
	ctx.r6.s64 = 0;
loc_82759624:
	// rlwinm r11,r6,10,0,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0xFFFFFC00;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// or r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 | ctx.r3.u64;
	// add r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 + ctx.r10.u64;
	// rlwinm r11,r11,10,0,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 10) & 0xFFFFFC00;
	// add r30,r29,r30
	ctx.r30.u64 = ctx.r29.u64 + ctx.r30.u64;
	// or r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 | ctx.r4.u64;
	// add r9,r29,r9
	ctx.r9.u64 = ctx.r29.u64 + ctx.r9.u64;
	// rlwinm r11,r11,10,0,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 10) & 0xFFFFFC00;
	// add r8,r29,r8
	ctx.r8.u64 = ctx.r29.u64 + ctx.r8.u64;
	// or r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 | ctx.r5.u64;
	// stwux r11,r28,r25
	ea = ctx.r28.u32 + ctx.r25.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r28.u32 = ea;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82759340
	if (ctx.cr6.lt) goto loc_82759340;
loc_82759660:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8273af6c
	ctx.lr = 0x8275966C;
	__restfpr_26(ctx, base);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82772C80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82772C88;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r3,r3,40
	ctx.r3.s64 = ctx.r3.s64 + 40;
	// addi r11,r11,-29304
	ctx.r11.s64 = ctx.r11.s64 + -29304;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x827844a0
	ctx.lr = 0x82772CB4;
	sub_827844A0(ctx, base);
	// addi r3,r31,52
	ctx.r3.s64 = ctx.r31.s64 + 52;
	// bl 0x82770d20
	ctx.lr = 0x82772CBC;
	sub_82770D20(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x827646e8
	ctx.lr = 0x82772CCC;
	sub_827646E8(ctx, base);
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// addi r11,r31,12
	ctx.r11.s64 = ctx.r31.s64 + 12;
	// ori r10,r10,996
	ctx.r10.u64 = ctx.r10.u64 | 996;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r3,r31,60
	ctx.r3.s64 = ctx.r31.s64 + 60;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// stw r28,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r28.u32);
	// stw r27,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r27.u32);
	// stw r30,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// bl 0x8273a590
	ctx.lr = 0x82772D0C;
	sub_8273A590(ctx, base);
	// stw r30,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r30,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// stw r30,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// stw r30,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82775C50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,10(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 10);
	// lhz r10,14(r4)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r4.u32 + 14);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82775c68
	if (!ctx.cr6.eq) goto loc_82775C68;
	// clrlwi. r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82775ca4
	if (ctx.cr0.eq) goto loc_82775CA4;
loc_82775C68:
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82775c7c
	if (!ctx.cr6.eq) goto loc_82775C7C;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// beq cr6,0x82775ca4
	if (ctx.cr6.eq) goto loc_82775CA4;
loc_82775C7C:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82775ca4
	if (ctx.cr6.eq) goto loc_82775CA4;
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82775ca4
	if (ctx.cr6.eq) goto loc_82775CA4;
	// lhz r11,36(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 36);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// blr 
	return;
loc_82775CA4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827786D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x827786E0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r3,108
	ctx.r29.s64 = ctx.r3.s64 + 108;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// bl 0x82855b44
	ctx.lr = 0x827786FC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82775cb0
	ctx.lr = 0x82778708;
	sub_82775CB0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82778718
	if (ctx.cr0.eq) goto loc_82778718;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82778728
	if (!ctx.cr6.eq) goto loc_82778728;
loc_82778718:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r31,r31,4105
	ctx.r31.u64 = ctx.r31.u64 | 4105;
	// b 0x82778730
	goto loc_82778730;
loc_82778728:
	// lwz r11,76(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// li r31,0
	ctx.r31.s64 = 0;
loc_82778730:
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x8277873C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8277C558) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8277C560;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,396(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 396);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// rlwinm. r11,r10,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8277c584
	if (ctx.cr0.eq) goto loc_8277C584;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// b 0x8277c9e4
	goto loc_8277C9E4;
loc_8277C584:
	// lwz r29,144(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r30,148(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// bne cr6,0x8277c5dc
	if (!ctx.cr6.eq) goto loc_8277C5DC;
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// bne cr6,0x8277c5e4
	if (!ctx.cr6.eq) goto loc_8277C5E4;
	// lwz r9,208(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// addi r11,r31,208
	ctx.r11.s64 = ctx.r31.s64 + 208;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8277c684
	if (!ctx.cr6.eq) goto loc_8277C684;
	// lwz r9,224(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// addi r11,r31,224
	ctx.r11.s64 = ctx.r31.s64 + 224;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8277c684
	if (!ctx.cr6.eq) goto loc_8277C684;
	// li r30,3
	ctx.r30.s64 = 3;
	// rlwinm. r11,r10,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r30,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// beq 0x8277c5e4
	if (ctx.cr0.eq) goto loc_8277C5E4;
	// rlwinm r11,r10,0,7,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFDFFFFFF;
	// addi r3,r31,356
	ctx.r3.s64 = ctx.r31.s64 + 356;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// bl 0x82784f68
	ctx.lr = 0x8277C5DC;
	sub_82784F68(ctx, base);
loc_8277C5DC:
	// cmpw cr6,r29,r30
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x8277c684
	if (ctx.cr6.eq) goto loc_8277C684;
loc_8277C5E4:
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// beq cr6,0x8277c624
	if (ctx.cr6.eq) goto loc_8277C624;
loc_8277C5F8:
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
	// bne 0x8277c5f8
	if (!ctx.cr0.eq) goto loc_8277C5F8;
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8277c62c
	goto loc_8277C62C;
loc_8277C624:
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
loc_8277C62C:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// li r8,36
	ctx.r8.s64 = 36;
	// lwz r7,140(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r6,7
	ctx.r6.s64 = 7;
	// lwz r5,136(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// oris r4,r11,32768
	ctx.r4.u64 = ctx.r11.u64 | 2147483648;
	// lwz r26,152(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// addi r11,r31,236
	ctx.r11.s64 = ctx.r31.s64 + 236;
	// stw r6,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r6.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r8,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r8.u32);
	// stw r7,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r7.u32);
	// stw r5,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r5.u32);
	// stw r29,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r29.u32);
	// stw r30,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r30.u32);
	// stw r26,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r26.u32);
	// stw r10,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r10.u32);
	// stw r9,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r9.u32);
	// stw r4,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r4.u32);
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// stw r30,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
	// b 0x8277c9e8
	goto loc_8277C9E8;
loc_8277C684:
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// addi r29,r31,224
	ctx.r29.s64 = ctx.r31.s64 + 224;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8277c760
	if (ctx.cr6.eq) goto loc_8277C760;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
loc_8277C6AC:
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// addi r30,r10,-12
	ctx.r30.s64 = ctx.r10.s64 + -12;
	// addic. r11,r11,1
	ctx.xer.ca = ctx.r11.u32 > 4294967294;
	ctx.r11.s64 = ctx.r11.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8277c6cc
	if (!ctx.cr0.eq) goto loc_8277C6CC;
	// li r11,1
	ctx.r11.s64 = 1;
loc_8277C6CC:
	// lwz r9,36(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8277c704
	if (ctx.cr6.eq) goto loc_8277C704;
	// lwz r11,148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x8277c748
	if (ctx.cr6.lt) goto loc_8277C748;
	// lwz r8,208(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// addi r11,r31,208
	ctx.r11.s64 = ctx.r31.s64 + 208;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8277c700
	if (ctx.cr6.eq) goto loc_8277C700;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// rlwinm. r11,r11,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8277c748
	if (ctx.cr0.eq) goto loc_8277C748;
loc_8277C700:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_8277C704:
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lbz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 56);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8277c82c
	if (!ctx.cr0.eq) goto loc_8277C82C;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82786970
	ctx.lr = 0x8277C720;
	sub_82786970(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8277c760
	if (ctx.cr6.eq) goto loc_8277C760;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// b 0x8277c6ac
	goto loc_8277C6AC;
loc_8277C748:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r29,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r29.u32);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
loc_8277C760:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// li r28,0
	ctx.r28.s64 = 0;
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8277c9e0
	if (!ctx.cr0.eq) goto loc_8277C9E0;
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// addi r30,r31,216
	ctx.r30.s64 = ctx.r31.s64 + 216;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8277c9e0
	if (ctx.cr6.eq) goto loc_8277C9E0;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_8277C798:
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// rlwinm. r9,r10,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8277c7d4
	if (!ctx.cr0.eq) goto loc_8277C7D4;
	// rlwinm. r9,r10,0,3,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8277c7d4
	if (!ctx.cr0.eq) goto loc_8277C7D4;
	// rlwinm. r9,r10,0,9,9
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8277c84c
	if (!ctx.cr0.eq) goto loc_8277C84C;
	// rlwinm. r9,r10,0,4,4
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8277c900
	if (!ctx.cr0.eq) goto loc_8277C900;
	// rlwinm. r10,r10,0,5,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8277c96c
	if (!ctx.cr0.eq) goto loc_8277C96C;
loc_8277C7D4:
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
	// bne 0x8277c7d4
	if (!ctx.cr0.eq) goto loc_8277C7D4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8277c800
	if (!ctx.cr6.eq) goto loc_8277C800;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82784b48
	ctx.lr = 0x8277C800;
	sub_82784B48(ctx, base);
loc_8277C800:
	// stw r28,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r28.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8277c9e0
	if (ctx.cr6.eq) goto loc_8277C9E0;
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
	// b 0x8277c798
	goto loc_8277C798;
loc_8277C82C:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82779bb8
	ctx.lr = 0x8277C838;
	sub_82779BB8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82786970
	ctx.lr = 0x8277C844;
	sub_82786970(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8277c9e8
	goto loc_8277C9E8;
loc_8277C84C:
	// lwz r4,92(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8277c874
	if (ctx.cr6.eq) goto loc_8277C874;
loc_8277C858:
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
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
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
	// bne 0x8277c858
	if (!ctx.cr0.eq) goto loc_8277C858;
loc_8277C874:
	// stw r4,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r4.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// bl 0x82779490
	ctx.lr = 0x8277C880;
	sub_82779490(ctx, base);
	// li r9,12
	ctx.r9.s64 = 12;
	// lwz r8,136(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r9,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r9.u32);
	// lwz r7,308(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// stw r10,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r10.u32);
	// addi r10,r31,236
	ctx.r10.s64 = ctx.r31.s64 + 236;
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// stw r8,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r8.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// stw r9,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r9.u32);
	// lwz r9,60(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 60);
	// stw r9,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r9.u32);
	// lwz r9,76(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 76);
	// stw r9,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r9.u32);
	// beq cr6,0x8277c8d8
	if (ctx.cr6.eq) goto loc_8277C8D8;
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// stw r9,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r9.u32);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r11.u32);
	// b 0x8277c8e0
	goto loc_8277C8E0;
loc_8277C8D8:
	// stw r28,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r28.u32);
	// stw r28,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r28.u32);
loc_8277C8E0:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// rlwinm r10,r10,0,10,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFBFFFFF;
	// b 0x8277c9d4
	goto loc_8277C9D4;
loc_8277C900:
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r10,28
	ctx.r10.s64 = 28;
	// lwz r8,136(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r7,9
	ctx.r7.s64 = 9;
	// stw r10,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r10.u32);
	// addi r10,r31,236
	ctx.r10.s64 = ctx.r31.s64 + 236;
	// stw r7,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r7.u32);
	// lwz r7,396(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// stw r9,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r9.u32);
	// stw r8,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r8.u32);
	// oris r9,r7,32768
	ctx.r9.u64 = ctx.r7.u64 | 2147483648;
	// lwz r8,60(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r8,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r8.u32);
	// lwz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// stw r8,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r8.u32);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// stw r11,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
	// stw r9,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r9.u32);
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// rlwinm r10,r10,0,5,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// stw r10,288(r11)
	REX_STORE_U32(ctx.r11.u32 + 288, ctx.r10.u32);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// oris r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 131072;
	// b 0x8277c9d4
	goto loc_8277C9D4;
loc_8277C96C:
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r10,28
	ctx.r10.s64 = 28;
	// lwz r8,136(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r7,10
	ctx.r7.s64 = 10;
	// stw r10,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r10.u32);
	// addi r10,r31,236
	ctx.r10.s64 = ctx.r31.s64 + 236;
	// stw r7,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r7.u32);
	// lwz r7,396(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// stw r9,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r9.u32);
	// stw r8,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r8.u32);
	// oris r9,r7,32768
	ctx.r9.u64 = ctx.r7.u64 | 2147483648;
	// lwz r8,60(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r8,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r8.u32);
	// lwz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// stw r8,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r8.u32);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// stw r11,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
	// stw r9,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r9.u32);
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// rlwinm r10,r10,0,6,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFBFFFFFF;
	// stw r10,288(r11)
	REX_STORE_U32(ctx.r11.u32 + 288, ctx.r10.u32);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// oris r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 65536;
loc_8277C9D4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r10,288(r11)
	REX_STORE_U32(ctx.r11.u32 + 288, ctx.r10.u32);
	// b 0x8277c9e8
	goto loc_8277C9E8;
loc_8277C9E0:
	// stw r28,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r28.u32);
loc_8277C9E4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8277C9E8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82799C70) {
	REX_FUNC_PROLOGUE();
	// lhz r10,36(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 36);
	// extsh r9,r4
	ctx.r9.s64 = ctx.r4.s16;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// extsh. r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble 0x82799cbc
	if (!ctx.cr0.gt) goto loc_82799CBC;
	// lhz r10,38(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 38);
	// rlwinm. r8,r10,0,0,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x82799cac
	if (!ctx.cr0.eq) goto loc_82799CAC;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// sth r4,32(r3)
	REX_STORE_U16(ctx.r3.u32 + 32, ctx.r4.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 32768;
	// sth r9,38(r3)
	REX_STORE_U16(ctx.r3.u32 + 38, ctx.r9.u16);
	// b 0x82799ce4
	goto loc_82799CE4;
loc_82799CAC:
	// lhz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 32);
	// subf r8,r10,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r10.u64;
	// extsh. r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge 0x82799cc4
	if (!ctx.cr0.lt) goto loc_82799CC4;
loc_82799CBC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82799CC4:
	// lhz r8,34(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 34);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r7,r4,16
	ctx.r7.u64 = ctx.r4.u32 & 0xFFFF;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// subf r10,r10,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r10.u64;
	// extsh. r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ble 0x82799ce8
	if (!ctx.cr0.gt) goto loc_82799CE8;
loc_82799CE4:
	// sth r4,34(r11)
	REX_STORE_U16(ctx.r11.u32 + 34, ctx.r4.u16);
loc_82799CE8:
	// rlwinm r7,r10,29,19,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFF;
	// rlwinm r9,r10,29,19,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFF;
	// clrlwi r6,r10,29
	ctx.r6.u64 = ctx.r10.u32 & 0x7;
	// li r8,1
	ctx.r8.s64 = 1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// lbzx r7,r7,r11
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r11.u32);
	// slw r6,r8,r6
	ctx.r6.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// slw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// lbzx r5,r9,r11
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// and r8,r6,r7
	ctx.r8.u64 = ctx.r6.u64 & ctx.r7.u64;
	// or r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 | ctx.r5.u64;
	// cntlzw r8,r8
	ctx.r8.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stbx r10,r9,r11
	REX_STORE_U8(ctx.r9.u32 + ctx.r11.u32, ctx.r10.u8);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8279E920) {
	REX_FUNC_PROLOGUE();
	// clrlwi. r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x8279e930
	if (!ctx.cr0.eq) goto loc_8279E930;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8279e840
	sub_8279E840(ctx, base);
	return;
loc_8279E930:
	// b 0x8279e840
	sub_8279E840(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8279F1C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x8279F1D0;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r22,0
	ctx.r22.s64 = 0;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// li r20,1
	ctx.r20.s64 = 1;
	// li r21,2
	ctx.r21.s64 = 2;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// addi r23,r3,84
	ctx.r23.s64 = ctx.r3.s64 + 84;
loc_8279F1F4:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r23
	ea = ctx.r23.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r11,r20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r20.s32, ctx.xer);
	// bne cr6,0x8279f218
	if (!ctx.cr6.eq) goto loc_8279F218;
	// stwcx. r21,0,r23
	ea = ctx.r23.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r21.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279f1f4
	if (!ctx.cr0.eq) goto loc_8279F1F4;
	// b 0x8279f220
	goto loc_8279F220;
loc_8279F218:
	// stwcx. r11,0,r23
	ea = ctx.r23.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_8279F220:
	// mr r11,r11
	ctx.r11.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8279f3a4
	if (!ctx.cr6.eq) goto loc_8279F3A4;
	// lwz r11,12(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279f3a0
	if (ctx.cr6.eq) goto loc_8279F3A0;
	// lwz r11,208(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 208);
	// rlwinm. r11,r11,0,12,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xF0000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8279f3a0
	if (ctx.cr0.eq) goto loc_8279F3A0;
	// addi r26,r27,80
	ctx.r26.s64 = ctx.r27.s64 + 80;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
	// bl 0x82856164
	ctx.lr = 0x8279F258;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,64(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 64);
	// addi r28,r27,64
	ctx.r28.s64 = ctx.r27.s64 + 64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8279f288
	goto loc_8279F288;
loc_8279F268:
	// cmplw cr6,r31,r25
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r25.u32, ctx.xer);
	// bge cr6,0x8279f290
	if (!ctx.cr6.lt) goto loc_8279F290;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// add r31,r10,r31
	ctx.r31.u64 = ctx.r10.u64 + ctx.r31.u64;
loc_8279F288:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8279f268
	if (!ctx.cr6.eq) goto loc_8279F268;
loc_8279F290:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82856184
	ctx.lr = 0x8279F298;
	__imp__KfReleaseSpinLock(ctx, base);
	// cmplw cr6,r31,r25
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x8279f3a4
	if (ctx.cr6.lt) goto loc_8279F3A4;
	// lwz r31,0(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// b 0x8279f394
	goto loc_8279F394;
loc_8279F2A8:
	// cmplw cr6,r29,r25
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r25.u32, ctx.xer);
	// bge cr6,0x8279f3a4
	if (!ctx.cr6.lt) goto loc_8279F3A4;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8279f3a4
	if (ctx.cr6.eq) goto loc_8279F3A4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// subf r9,r29,r25
	ctx.r9.u64 = ctx.r25.u64 - ctx.r29.u64;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// subf r8,r10,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r10.u64;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8279f2e0
	if (ctx.cr6.lt) goto loc_8279F2E0;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
loc_8279F2E0:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// add r4,r29,r24
	ctx.r4.u64 = ctx.r29.u64 + ctx.r24.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x8273a030
	ctx.lr = 0x8279F2F4;
	sub_8273A030(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8279f310
	if (!ctx.cr6.lt) goto loc_8279F310;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8279F310:
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8279f390
	if (!ctx.cr6.eq) goto loc_8279F390;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82856164
	ctx.lr = 0x8279F32C;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279f358
	if (ctx.cr6.eq) goto loc_8279F358;
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8279f34c
	if (!ctx.cr6.eq) goto loc_8279F34C;
	// stw r22,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r22.u32);
loc_8279F34C:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// stw r22,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r22.u32);
loc_8279F358:
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8279f384
	if (!ctx.cr6.eq) goto loc_8279F384;
	// stw r22,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r22.u32);
	// addi r11,r27,72
	ctx.r11.s64 = ctx.r27.s64 + 72;
	// lwz r10,76(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 76);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8279f37c
	if (ctx.cr6.eq) goto loc_8279F37C;
	// stw r31,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// b 0x8279f380
	goto loc_8279F380;
loc_8279F37C:
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
loc_8279F380:
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
loc_8279F384:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82856184
	ctx.lr = 0x8279F38C;
	__imp__KfReleaseSpinLock(ctx, base);
	// lwz r31,0(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
loc_8279F390:
	// add r29,r30,r29
	ctx.r29.u64 = ctx.r30.u64 + ctx.r29.u64;
loc_8279F394:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8279f2a8
	if (!ctx.cr6.eq) goto loc_8279F2A8;
	// b 0x8279f3a4
	goto loc_8279F3A4;
loc_8279F3A0:
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
loc_8279F3A4:
	// li r10,3
	ctx.r10.s64 = 3;
loc_8279F3A8:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r23
	ea = ctx.r23.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x8279f3cc
	if (!ctx.cr6.eq) goto loc_8279F3CC;
	// stwcx. r22,0,r23
	ea = ctx.r23.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r22.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279f3a8
	if (!ctx.cr0.eq) goto loc_8279F3A8;
	// b 0x8279f44c
	goto loc_8279F44C;
loc_8279F3CC:
	// stwcx. r11,0,r23
	ea = ctx.r23.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// b 0x8279f44c
	goto loc_8279F44C;
loc_8279F3D8:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r23
	ea = ctx.r23.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r11,r21
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r21.s32, ctx.xer);
	// bne cr6,0x8279f3fc
	if (!ctx.cr6.eq) goto loc_8279F3FC;
	// stwcx. r20,0,r23
	ea = ctx.r23.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r20.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279f3d8
	if (!ctx.cr0.eq) goto loc_8279F3D8;
	// b 0x8279f404
	goto loc_8279F404;
loc_8279F3FC:
	// stwcx. r11,0,r23
	ea = ctx.r23.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_8279F404:
	// mr r11,r11
	ctx.r11.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8279f458
	if (ctx.cr6.eq) goto loc_8279F458;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8279f458
	if (ctx.cr6.eq) goto loc_8279F458;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8279f458
	if (ctx.cr6.eq) goto loc_8279F458;
loc_8279F420:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r23
	ea = ctx.r23.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x8279f444
	if (!ctx.cr6.eq) goto loc_8279F444;
	// stwcx. r22,0,r23
	ea = ctx.r23.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r22.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279f420
	if (!ctx.cr0.eq) goto loc_8279F420;
	// b 0x8279f44c
	goto loc_8279F44C;
loc_8279F444:
	// stwcx. r11,0,r23
	ea = ctx.r23.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_8279F44C:
	// mr r11,r11
	ctx.r11.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8279f3d8
	if (!ctx.cr6.eq) goto loc_8279F3D8;
loc_8279F458:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827B1628) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,23176
	ctx.r9.s64 = ctx.r11.s64 + 23176;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,23176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8412(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2400) {
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
	// lfs f0,23352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8064(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8064);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8000(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B33A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7532(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7532, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B4140) {
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
	// lfs f0,23720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7180(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7180);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7132(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5130) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6776(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6776);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6672(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6672, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5E00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6292);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6288(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6CA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24220);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14376(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14376);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12348(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12348);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5856(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B80A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-5256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5256);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-5252(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5252, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8928) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-5144(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -5144);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5036(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B96D8) {
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
	// lfs f0,24664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4744(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4744);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4636(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA900) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25028(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25028);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4096(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4096, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB758) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-3656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3652(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC640) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-3216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD2B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2852);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2848(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BDFB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BED78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2068);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2064(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BFCA0) {
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
	// lfs f0,26200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1724(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1724);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1608(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1608, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0EC8) {
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
	// lfs f0,26504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1180(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1180);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1060(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2368) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26868(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26868);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-480(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C32A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3F70) {
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
	// lfs f12,236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,352(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C54C8) {
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
	// lfs f0,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,896(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 896);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1000(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C65C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1516(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7530) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
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

DEFINE_REX_FUNC(sub_827C8380) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2428(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C90E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2768(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2768);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2820(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2820, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9F60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,3236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,3240(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 3240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CAA00) {
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
	// lfs f12,3504(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3504);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3552(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3552, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CBBD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,3940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3940);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4088(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4088, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CC7F0) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4336(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4336);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4444(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4444, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD9B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,29416
	ctx.r9.s64 = ctx.r11.s64 + 29416;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,29416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4964(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CEC28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,29608
	ctx.r9.s64 = ctx.r11.s64 + 29608;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,29608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5500(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CFED0) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5968(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5968);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6048(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D11A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,6592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6592);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,6596(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 6596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1B98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6880);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6884(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,7288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7292(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D3A60) {
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
	// lfs f0,30376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7660(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7660);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7780(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7780, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4CD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8216);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8320(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5AF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6918) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9100(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9100);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9148(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7BA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,9684(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9684);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9688(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8C68) {
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
	// lfs f0,31224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10056(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10056);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10172(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D9EC0) {
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
	// lfs f0,31432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10608(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10608);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10708(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10708, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB130) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,11140(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 11140);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11248(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DBFE8) {
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
	// lfs f0,31752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11552(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11552);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11672(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11672, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD3D0) {
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
	// lfs f0,31944(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31944);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12168(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12168);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12280(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,12784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DF560) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,13256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13256);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,13260(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 13260, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DFDA8) {
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
	// lfs f0,32376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13384(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13384);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13500(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14100(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14100, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2250) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E32B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-32316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32316);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,15072(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 15072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3AC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15292);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15296(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15296, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4A48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-32008
	ctx.r9.s64 = ctx.r11.s64 + -32008;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-32008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,15740(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 15740, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6058) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,16372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16372);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,16376(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 16376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6920) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-29320
	ctx.r9.s64 = ctx.r11.s64 + -29320;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-29320(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16624(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16624, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7E60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17200(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8DC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17644(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9C60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18044(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EAC28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-22788(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22788);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18484(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18484, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EBA10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-22504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2460(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2460);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18880(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EC860) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-21792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19272(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19272, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ED8E8) {
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
	// lfs f0,-21000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21000);
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
	// stfs f0,19728(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EEDD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-19920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20296(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20296, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EFEA8) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20648(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20648);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20768(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20768, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F1330) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,21328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21328);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,21332(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 21332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F1C68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21588);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21592(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21592, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2D80) {
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
	// lfs f0,-17416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,21980(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 21980);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,22064(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 22064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F3E50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-16840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,22436(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 22436);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5008) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-16008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5FF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23724(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23724);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23728(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6EF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24144(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24144, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7FD8) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24496(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24496);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,24584(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 24584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F94A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25164(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25164, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA370) {
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
	// lfs f0,-9832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25480(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25480);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25580(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB700) {
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
	// lfs f0,-9624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26036(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26036);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26148(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FCA40) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26588(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26588);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26708(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26708, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FDCB8) {
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
	// lfs f0,-9240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27140(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27140);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27248(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FEFF8) {
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
	// lfs f0,-9048(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9048);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27692(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27692);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27808(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800338) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8788(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8788);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801138) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28780(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28780, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801FF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,29208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29208);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,29212(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 29212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802A48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29508);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29512(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803870) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29872(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29872);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29928(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804B88) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30424(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30424);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30484(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30484, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805F30) {
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
	// lfs f0,-7896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30976(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30976);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31056(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807360) {
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
	// lfs f0,-7704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31540);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31644(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828086E8) {
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
	// lfs f12,32092(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32092);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32212(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809A98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-7320(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32668(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32668);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-32752(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -32752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280AE38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-32184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32180(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280BC58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-31768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31764(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31764, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280CAB0) {
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
	// lfs f0,-6744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31400(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31400);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31328(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280DE40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30764(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30764, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280EE60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30284(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280FD80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29836(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29836, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810E60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29332(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811E00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-5720
	ctx.r9.s64 = ctx.r11.s64 + -5720;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-5720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28876(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28876, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828130C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28324);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28320(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828140C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5028(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5028);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27816(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27816, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828150E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-27320(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27320);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-27316(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -27316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815AD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27028(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828168B0) {
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
	// lfs f0,-4440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-26724(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -26724);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-26616(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -26616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817C48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26028(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818C38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-3816
	ctx.r9.s64 = ctx.r11.s64 + -3816;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-3816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25544(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281A108) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24932);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24928(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281AE50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-3232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-24524(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -24524, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281BBE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24124(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281C980) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23784(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23784);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23712(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281DC58) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23196(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23196);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23140(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23140, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281EF40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22588(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22588, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281FF58) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22204(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22204);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22116(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22116, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821338) {
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
	// lfs f13,-21580(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -21580);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21528(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828223C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1556(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1556);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21052(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82823240) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-20628(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20628);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20624(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20624, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828242D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-20232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -20232);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20124(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828252C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826060) {
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
	// lfs f0,-664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19340(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19340);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19232(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19232, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82827610) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18596(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828500) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-232
	ctx.r9.s64 = ctx.r11.s64 + -232;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18160(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18160, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829A18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17540(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282AD48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,216
	ctx.r9.s64 = ctx.r11.s64 + 216;
	// lfs f0,216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16980(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -16980, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282BCA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-16520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16516(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282CC10) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16152(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16152);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16068(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282DF60) {
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
	// lfs f0,872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15580(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15580);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15500(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282F378) {
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
	// lfs f0,1096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14992(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14992);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14908(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14908, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830768) {
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
	// lfs f0,1352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14432(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14432);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14316(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831B18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13724(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832B90) {
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
	// lfs f0,1912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13296(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -13296);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13232(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13232, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833DB0) {
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
	// lfs f12,-12796(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12796);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12696(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828352B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,2368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2368);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-12076(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -12076, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835E10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,2520
	ctx.r9.s64 = ctx.r11.s64 + 2520;
	// lfs f0,2520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11736(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -11736, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836DA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11284(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837B68) {
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
	// lfs f13,-10980(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10980);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10876(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10876, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838A88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10436(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10436);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10432(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839BC8) {
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
	// lfs f0,3232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10036(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10036);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9928(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283B040) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-9336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9332(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283BEE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8904(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8904);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8900(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283CEF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8540(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8540);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8432(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283DE70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7984(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7984);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7980(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7980, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283ED08) {
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
	// lfs f0,4224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7600(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7600);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7552(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7552, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283FFE0) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6992(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6992, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82841568) {
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
	// lfs f0,4752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6484(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6484);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6364(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842A08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,5040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5040);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-5764(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5764, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828432B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5508);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5504(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828443D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4996(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4996);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4992(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4992, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845498) {
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
	// lfs f0,5624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4560(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4560);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4488(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846648) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4080(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4080);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3968(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3968, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847AD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6124);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3356(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848998) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2924);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2920(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2920, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849BB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2396(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2396, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284AA38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-2020(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2020);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1968(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1968, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284BA58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1608);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1500(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284C9C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1052(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D848) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7220);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-624(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -624, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284E970) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-100(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -100);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-96(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -96, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284F890) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 356);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,360(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828502C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 660);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,664(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 664, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828512F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,8200
	ctx.r9.s64 = ctx.r11.s64 + 8200;
	// lfs f0,8200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1156(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852348) {
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
	// lfs f0,8360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1492(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1492);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1612(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828537B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// lfs f0,2196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2196);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8664(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8664);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,2220(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 2220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828745D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x828745E0;
	__savegprlr_28(ctx, base);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// vspltish v13,2
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x2)));
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lvx128 v62,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,16
	ctx.r11.s64 = 16;
	// lvsl v7,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// vsrah v11,v1,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// add r6,r3,r4
	ctx.r6.u64 = ctx.r3.u64 + ctx.r4.u64;
	// vspltish v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_set1_epi16(short(0x1)));
	// add r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lvx128 v58,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r5,r9,r4
	ctx.r5.u64 = ctx.r9.u64 + ctx.r4.u64;
	// vperm128 v10,v63,v58,v7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// add r31,r7,r4
	ctx.r31.u64 = ctx.r7.u64 + ctx.r4.u64;
	// lvx128 v56,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r6,r11
	ea = (ctx.r6.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,48
	ctx.r3.s64 = 48;
	// lvsl v6,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r29,96
	ctx.r29.s64 = 96;
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v9,v62,v57,v6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvsl v1,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrglb v2,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v54,r10,r11
	ea = (ctx.r10.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v8,v60,v56,v1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// lvx128 v51,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v10,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v59,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglb v1,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v55,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v9,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v53,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglb v31,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v52,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v8,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v50,r7,r11
	ea = (ctx.r7.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,144
	ctx.r28.s64 = 144;
	// lvsl v6,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r10,240
	ctx.r10.s64 = 240;
	// lvsl v5,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v6,v61,v54,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvsl v7,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v5,v53,v51,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// lvsl v4,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v7,v59,v55,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v48,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v4,v52,v50,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// lvx128 v49,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglb v29,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v3,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrglb v28,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v3,v49,v48,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// li r11,192
	ctx.r11.s64 = 192;
	// vmrglb v30,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r9,288
	ctx.r9.s64 = 288;
	// vmrglb v27,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r8,336
	ctx.r8.s64 = 336;
	// vmrghb v7,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v26,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v6,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v5,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v4,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v0,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsldoi v3,v10,v2,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8), 14));
	// vsldoi v2,v9,v1,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8), 14));
	// vsldoi v1,v8,v31,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8), 14));
	// vsldoi v31,v7,v30,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8), 14));
	// vsldoi v30,v6,v29,2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8), 14));
	// vslh v25,v3,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsldoi v29,v5,v28,2
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8), 14));
	// vslh v24,v2,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsldoi v28,v4,v27,2
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v27.u8), 14));
	// vslh v23,v1,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsldoi v27,v0,v26,2
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8), 14));
	// vslh v22,v31,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v20,v29,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v19,v28,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v18,v27,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v21,v30,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v17,v25,v3
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v16,v24,v2
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vaddshs v15,v23,v1
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vaddshs v14,v22,v31
	simde_mm_store_si128((simde__m128i*)ctx.v14.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vaddshs v12,v21,v30
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vaddshs v3,v20,v29
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vaddshs v2,v19,v28
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vaddshs v1,v18,v27
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vaddshs v31,v17,v10
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v30,v16,v9
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vaddshs v29,v15,v8
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v28,v14,v7
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v14.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v27,v12,v6
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v24,v1,v0
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vaddshs v26,v3,v5
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v25,v2,v4
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v23,v31,v11
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v22,v30,v11
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v21,v29,v11
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v20,v28,v11
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v18,v26,v11
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v17,v25,v11
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v16,v24,v11
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v19,v27,v11
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsrah v15,v23,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v23.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v14,v22,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v22.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v0,v21,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v0.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v12,v20,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v11,v19,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v15,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v10,v18,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v18.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v14,r30,r3
	ea = (ctx.r30.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v9,v17,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v17.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v0,r30,r29
	ea = (ctx.r30.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v8,v16,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v16.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v12,r30,r28
	ea = (ctx.r30.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r30,r11
	ea = (ctx.r30.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r30,r10
	ea = (ctx.r30.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r30,r9
	ea = (ctx.r30.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v8,r30,r8
	ea = (ctx.r30.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

