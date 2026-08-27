#include "harmonyrecomp_funcs.7.h"

DEFINE_REX_FUNC(sub_82210550) {
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
	// bl 0x825a8b50
	ctx.lr = 0x82210560;
	sub_825A8B50(ctx, base);
	// bl 0x825a87a0
	ctx.lr = 0x82210564;
	sub_825A87A0(ctx, base);
	// bl 0x8242d498
	ctx.lr = 0x82210568;
	sub_8242D498(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12864(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12864);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822105b4
	if (ctx.cr6.eq) goto loc_822105B4;
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822105b4
	if (ctx.cr6.eq) goto loc_822105B4;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x822105b4
	if (!ctx.cr6.eq) goto loc_822105B4;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x822105b4
	if (!ctx.cr6.eq) goto loc_822105B4;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r3,r11,60
	ctx.r3.s64 = ctx.r11.s64 + 60;
	// li r5,40
	ctx.r5.s64 = 40;
	// lwz r11,-12956(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -12956);
	// addi r4,r11,48
	ctx.r4.s64 = ctx.r11.s64 + 48;
	// bl 0x8273a030
	ctx.lr = 0x822105B4;
	sub_8273A030(ctx, base);
loc_822105B4:
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

DEFINE_REX_FUNC(sub_8221CD28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8221CD30;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,108(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221d0d4
	if (ctx.cr6.eq) goto loc_8221D0D4;
	// bl 0x82218310
	ctx.lr = 0x8221CD48;
	sub_82218310(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8221d0d4
	if (ctx.cr0.eq) goto loc_8221D0D4;
	// lwz r3,108(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// bl 0x823bdef8
	ctx.lr = 0x8221CD58;
	sub_823BDEF8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8221cd68
	if (ctx.cr0.eq) goto loc_8221CD68;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8221d0d8
	goto loc_8221D0D8;
loc_8221CD68:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f9,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 72);
	// addi r9,r11,15324
	ctx.r9.s64 = ctx.r11.s64 + 15324;
	// lfs f13,68(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f9,f0
	ctx.f0.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// stfs f0,64(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// fadds f0,f9,f13
	ctx.f0.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// li r23,0
	ctx.r23.s64 = 0;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f10,-2856(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2856);
	ctx.f10.f64 = double(temp.f32);
	// beq 0x8221cdb4
	if (ctx.cr0.eq) goto loc_8221CDB4;
	// lfs f0,80(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stw r23,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r23.u32);
	// stfs f10,64(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stb r23,72(r31)
	REX_STORE_U8(ctx.r31.u32 + 72, ctx.r23.u8);
	// stfs f0,76(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
loc_8221CDB4:
	// lbz r11,73(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 73);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8221cdec
	if (ctx.cr0.eq) goto loc_8221CDEC;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8221cdd0
	if (!ctx.cr6.eq) goto loc_8221CDD0;
	// stfs f10,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
loc_8221CDD0:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8221cde8
	if (!ctx.cr6.eq) goto loc_8221CDE8;
	// lfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stw r23,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r23.u32);
	// stfs f10,64(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stfs f0,76(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
loc_8221CDE8:
	// stb r23,73(r31)
	REX_STORE_U8(ctx.r31.u32 + 73, ctx.r23.u8);
loc_8221CDEC:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lbz r7,74(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 74);
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r8,r11,-8956
	ctx.r8.s64 = ctx.r11.s64 + -8956;
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lfs f0,27336(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 27336);
	ctx.f0.f64 = double(temp.f32);
	// beq 0x8221ce30
	if (ctx.cr0.eq) goto loc_8221CE30;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221ce1c
	if (ctx.cr6.eq) goto loc_8221CE1C;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8221ce2c
	if (!ctx.cr6.eq) goto loc_8221CE2C;
loc_8221CE1C:
	// lfs f13,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,64(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
loc_8221CE2C:
	// stb r23,74(r31)
	REX_STORE_U8(ctx.r31.u32 + 74, ctx.r23.u8);
loc_8221CE30:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lfs f6,-3088(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3088);
	ctx.f6.f64 = double(temp.f32);
	// li r24,1
	ctx.r24.s64 = 1;
	// li r25,3
	ctx.r25.s64 = 3;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8221cebc
	if (ctx.cr6.lt) goto loc_8221CEBC;
	// beq cr6,0x8221cea0
	if (ctx.cr6.eq) goto loc_8221CEA0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8221cf18
	if (!ctx.cr6.lt) goto loc_8221CF18;
	// lfs f13,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,332(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 332);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fdivs f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 / ctx.f0.f64));
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x8221ce7c
	if (!ctx.cr6.lt) goto loc_8221CE7C;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x8221ce88
	goto loc_8221CE88;
loc_8221CE7C:
	// fcmpu cr6,f0,f6
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// ble cr6,0x8221ce88
	if (!ctx.cr6.gt) goto loc_8221CE88;
	// fmr f0,f6
	ctx.f0.f64 = ctx.f6.f64;
loc_8221CE88:
	// stfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x8221cf18
	if (ctx.cr6.lt) goto loc_8221CF18;
	// mr r24,r23
	ctx.r24.u64 = ctx.r23.u64;
	// stw r25,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r25.u32);
	// b 0x8221cf18
	goto loc_8221CF18;
loc_8221CEA0:
	// lfs f13,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f13,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8221cf18
	if (ctx.cr6.lt) goto loc_8221CF18;
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// b 0x8221cf18
	goto loc_8221CF18;
loc_8221CEBC:
	// lfs f0,332(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 332);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f11,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f0,f11,f12
	ctx.f0.f64 = double(float(ctx.f11.f64 / ctx.f12.f64));
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x8221cee0
	if (!ctx.cr6.lt) goto loc_8221CEE0;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x8221ceec
	goto loc_8221CEEC;
loc_8221CEE0:
	// fcmpu cr6,f0,f6
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// ble cr6,0x8221ceec
	if (!ctx.cr6.gt) goto loc_8221CEEC;
	// fmr f0,f6
	ctx.f0.f64 = ctx.f6.f64;
loc_8221CEEC:
	// stfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// addi r11,r31,80
	ctx.r11.s64 = ctx.r31.s64 + 80;
	// lfs f0,76(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x8221cf08
	if (ctx.cr6.gt) goto loc_8221CF08;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_8221CF08:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f11,f12
	ctx.cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// blt cr6,0x8221cf18
	if (ctx.cr6.lt) goto loc_8221CF18;
	// stw r24,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r24.u32);
loc_8221CF18:
	// lfs f13,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-948(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -948);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f13,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8221cf40
	if (ctx.cr6.lt) goto loc_8221CF40;
	// lfs f13,124(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,13396(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 13396);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f9,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f9.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,124(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 124, temp.u32);
loc_8221CF40:
	// lwz r26,104(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x8221cf50
	if (ctx.cr6.eq) goto loc_8221CF50;
	// addi r25,r26,-1
	ctx.r25.s64 = ctx.r26.s64 + -1;
loc_8221CF50:
	// cmplwi cr6,r26,3
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 3, ctx.xer);
	// bne cr6,0x8221cf60
	if (!ctx.cr6.eq) goto loc_8221CF60;
	// mr r28,r23
	ctx.r28.u64 = ctx.r23.u64;
	// b 0x8221cf70
	goto loc_8221CF70;
loc_8221CF60:
	// addi r28,r26,1
	ctx.r28.s64 = ctx.r26.s64 + 1;
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
	// cmplwi cr6,r28,3
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 3, ctx.xer);
	// beq cr6,0x8221cf74
	if (ctx.cr6.eq) goto loc_8221CF74;
loc_8221CF70:
	// addi r27,r28,1
	ctx.r27.s64 = ctx.r28.s64 + 1;
loc_8221CF74:
	// lfs f5,-448(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -448);
	ctx.f5.f64 = double(temp.f32);
	// lfs f0,124(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f5
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f5.f64));
	// lfs f13,68(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x8221cf98
	if (!ctx.cr6.lt) goto loc_8221CF98;
	// fmr f6,f10
	ctx.f6.f64 = ctx.f10.f64;
	// b 0x8221cfa4
	goto loc_8221CFA4;
loc_8221CF98:
	// fcmpu cr6,f0,f6
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// bgt cr6,0x8221cfa4
	if (ctx.cr6.gt) goto loc_8221CFA4;
	// fmr f6,f0
	ctx.f6.f64 = ctx.f0.f64;
loc_8221CFA4:
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// lfs f13,80(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f0,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mulli r8,r11,3
	ctx.r8.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(3));
	// fmr f1,f6
	ctx.f1.f64 = ctx.f6.f64;
	// addi r11,r10,-8636
	ctx.r11.s64 = ctx.r10.s64 + -8636;
	// fctidz f13,f12
	ctx.f13.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lbz r10,95(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lbz r6,95(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// lbzx r11,r8,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r11.u32);
	// stb r6,91(r1)
	REX_STORE_U8(ctx.r1.u32 + 91, ctx.r6.u8);
	// lbzx r9,r8,r9
	ctx.r9.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// lbzx r8,r8,r7
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r7.u32);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// stb r11,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r11.u8);
	// stb r9,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// stb r8,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r8.u8);
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stb r9,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r9.u8);
	// stb r8,90(r1)
	REX_STORE_U8(ctx.r1.u32 + 90, ctx.r8.u8);
	// lwz r29,88(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8222c580
	ctx.lr = 0x8221D02C;
	sub_8222C580(ctx, base);
	// addi r11,r26,22
	ctx.r11.s64 = ctx.r26.s64 + 22;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// fmr f1,f6
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f6.f64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8222c580
	ctx.lr = 0x8221D048;
	sub_8222C580(ctx, base);
	// addi r11,r28,22
	ctx.r11.s64 = ctx.r28.s64 + 22;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// fmr f1,f6
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f6.f64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8222c580
	ctx.lr = 0x8221D064;
	sub_8222C580(ctx, base);
	// addi r11,r27,22
	ctx.r11.s64 = ctx.r27.s64 + 22;
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f1,f6
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f6.f64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8222c580
	ctx.lr = 0x8221D080;
	sub_8222C580(ctx, base);
	// addi r11,r25,22
	ctx.r11.s64 = ctx.r25.s64 + 22;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r3.u32);
	// lfs f13,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,124(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f5
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f5.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8221d0c4
	if (ctx.cr6.lt) goto loc_8221D0C4;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x8221d0bc
	if (!ctx.cr6.eq) goto loc_8221D0BC;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// b 0x8221d0c0
	goto loc_8221D0C0;
loc_8221D0BC:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8221D0C0:
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
loc_8221D0C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8221d0e0
	ctx.lr = 0x8221D0CC;
	sub_8221D0E0(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// b 0x8221d0d8
	goto loc_8221D0D8;
loc_8221D0D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8221D0D8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822423D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x822423E0;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,278(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 278);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8224274c
	if (ctx.cr0.eq) goto loc_8224274C;
	// bl 0x82232628
	ctx.lr = 0x82242400;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8224274c
	if (!ctx.cr0.eq) goto loc_8224274C;
	// addis r25,r26,1
	ctx.r25.s64 = ctx.r26.s64 + 65536;
	// addi r25,r25,-3100
	ctx.r25.s64 = ctx.r25.s64 + -3100;
	// lwz r3,0(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82242424;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blt 0x82242460
	if (ctx.cr0.lt) goto loc_82242460;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82242460
	if (ctx.cr6.eq) goto loc_82242460;
	// bl 0x82444358
	ctx.lr = 0x82242440;
	sub_82444358(ctx, base);
	// bl 0x824443c8
	ctx.lr = 0x82242444;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82242460
	if (ctx.cr0.eq) goto loc_82242460;
	// cntlzw r11,r5
	ctx.r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// addi r4,r11,16
	ctx.r4.s64 = ctx.r11.s64 + 16;
	// bl 0x8243b8b8
	ctx.lr = 0x82242460;
	sub_8243B8B8(ctx, base);
loc_82242460:
	// lbz r11,236(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 236);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8224250c
	if (ctx.cr0.eq) goto loc_8224250C;
	// addis r31,r26,1
	ctx.r31.s64 = ctx.r26.s64 + 65536;
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r31,r31,-3068
	ctx.r31.s64 = ctx.r31.s64 + -3068;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lbz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822424c8
	if (!ctx.cr0.eq) goto loc_822424C8;
	// lwz r3,0(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224249C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822424c8
	if (ctx.cr0.eq) goto loc_822424C8;
	// lwz r11,-12848(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12848);
	// stb r29,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822424bc
	if (ctx.cr6.eq) goto loc_822424BC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8257e030
	ctx.lr = 0x822424BC;
	sub_8257E030(ctx, base);
loc_822424BC:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x822140d0
	ctx.lr = 0x822424C8;
	sub_822140D0(ctx, base);
loc_822424C8:
	// addis r31,r26,1
	ctx.r31.s64 = ctx.r26.s64 + 65536;
	// addi r31,r31,-3067
	ctx.r31.s64 = ctx.r31.s64 + -3067;
	// lbz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8224250c
	if (!ctx.cr0.eq) goto loc_8224250C;
	// lwz r3,0(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822424F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224250c
	if (ctx.cr0.eq) goto loc_8224250C;
	// lwz r11,-12848(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12848);
	// stb r29,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8224250c
	if (ctx.cr6.eq) goto loc_8224250C;
	// stb r29,36(r11)
	REX_STORE_U8(ctx.r11.u32 + 36, ctx.r29.u8);
loc_8224250C:
	// lbz r11,544(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 544);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8224274c
	if (!ctx.cr0.eq) goto loc_8224274C;
	// lwz r3,0(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224252C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,8(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,60
	ctx.r11.s64 = 60;
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// subf r10,r31,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r31.u64;
	// divw. r11,r10,r11
	ctx.r11.u64 = uint32_t((ctx.r11.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r10.s32 / ctx.r11.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82242668
	if (ctx.cr0.eq) goto loc_82242668;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82242628
	if (ctx.cr6.eq) goto loc_82242628;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// addi r28,r11,22072
	ctx.r28.s64 = ctx.r11.s64 + 22072;
loc_82242558:
	// lbz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// lwz r4,20(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822425e4
	if (ctx.cr0.eq) goto loc_822425E4;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r30,r1,128
	ctx.r30.s64 = ctx.r1.s64 + 128;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r24,r1,144
	ctx.r24.s64 = ctx.r1.s64 + 144;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r8,32(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lwz r7,24(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r5,4(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8246ed28
	ctx.lr = 0x822425E0;
	sub_8246ED28(ctx, base);
	// b 0x8224261c
	goto loc_8224261C;
loc_822425E4:
	// lwz r30,4(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x8246d448
	ctx.lr = 0x822425F0;
	sub_8246D448(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8224261c
	if (ctx.cr0.lt) goto loc_8224261C;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// li r4,348
	ctx.r4.s64 = 348;
	// bl 0x825e02a0
	ctx.lr = 0x82242608;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8224261c
	if (ctx.cr0.eq) goto loc_8224261C;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x824749e8
	ctx.lr = 0x8224261C;
	sub_824749E8(ctx, base);
loc_8224261C:
	// addi r31,r31,60
	ctx.r31.s64 = ctx.r31.s64 + 60;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82242558
	if (!ctx.cr6.eq) goto loc_82242558;
loc_82242628:
	// lwz r31,8(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r29,4(r27)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82242668
	if (ctx.cr6.eq) goto loc_82242668;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r31
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82242664
	if (ctx.cr6.eq) goto loc_82242664;
loc_82242644:
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x82242654;
	sub_8273A030(ctx, base);
	// addi r30,r30,60
	ctx.r30.s64 = ctx.r30.s64 + 60;
	// addi r29,r29,60
	ctx.r29.s64 = ctx.r29.s64 + 60;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x82242644
	if (!ctx.cr6.eq) goto loc_82242644;
loc_82242664:
	// stw r29,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r29.u32);
loc_82242668:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82231190
	ctx.lr = 0x82242674;
	sub_82231190(ctx, base);
	// lwz r11,252(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 252);
	// lwz r10,248(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 248);
	// addi r31,r26,244
	ctx.r31.s64 = ctx.r26.s64 + 244;
	// li r30,0
	ctx.r30.s64 = 0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822426e0
	if (ctx.cr0.eq) goto loc_822426E0;
loc_82242690:
	// lwz r3,0(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,904(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 904);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822426A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822426c4
	if (ctx.cr0.eq) goto loc_822426C4;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82247e28
	ctx.lr = 0x822426C4;
	sub_82247E28(ctx, base);
loc_822426C4:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82242690
	if (ctx.cr6.lt) goto loc_82242690;
loc_822426E0:
	// lwz r11,268(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 268);
	// addi r31,r26,260
	ctx.r31.s64 = ctx.r26.s64 + 260;
	// lwz r10,264(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 264);
	// li r30,0
	ctx.r30.s64 = 0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224274c
	if (ctx.cr0.eq) goto loc_8224274C;
loc_822426FC:
	// lwz r3,0(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,792(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 792);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82242714;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82242730
	if (ctx.cr0.eq) goto loc_82242730;
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82247e28
	ctx.lr = 0x82242730;
	sub_82247E28(ctx, base);
loc_82242730:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x822426fc
	if (ctx.cr6.lt) goto loc_822426FC;
loc_8224274C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82266B48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82266B50;
	__savegprlr_23(ctx, base);
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f30.u64);
	// stfd f31,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r23,r3,1
	ctx.r23.s64 = ctx.r3.s64 + 65536;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r23,r23,-2455
	ctx.r23.s64 = ctx.r23.s64 + -2455;
	// lbz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82266e24
	if (ctx.cr0.eq) goto loc_82266E24;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,26028
	ctx.r9.s64 = ctx.r11.s64 + 26028;
	// addi r8,r10,12468
	ctx.r8.s64 = ctx.r10.s64 + 12468;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lfs f2,26028(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26028);
	ctx.f2.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// lfs f30,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f30.f64 = double(temp.f32);
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// lfs f5,21084(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 21084);
	ctx.f5.f64 = double(temp.f32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f4,-232(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -232);
	ctx.f4.f64 = double(temp.f32);
	// lfs f6,13784(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 13784);
	ctx.f6.f64 = double(temp.f32);
	// addi r31,r31,-2660
	ctx.r31.s64 = ctx.r31.s64 + -2660;
	// lwz r28,-13032(r6)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r6.u32 + -13032);
	// lfs f3,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f31,1908(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 1908);
	ctx.f31.f64 = double(temp.f32);
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// li r24,8
	ctx.r24.s64 = 8;
	// lis r27,-32111
	ctx.r27.s64 = -2104426496;
	// addi r29,r11,23536
	ctx.r29.s64 = ctx.r11.s64 + 23536;
loc_82266BCC:
	// lbz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 4);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82266dd8
	if (ctx.cr0.eq) goto loc_82266DD8;
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfs f0,-8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// stfs f1,156(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r4,r31,-20
	ctx.r4.s64 = ctx.r31.s64 + -20;
	// stfs f1,152(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f1,148(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// stfs f1,144(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// li r25,1
	ctx.r25.s64 = 1;
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
	// lfs f13,-12(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -12);
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
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,208(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,272(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82266C6C;
	sub_8255F918(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmuls f0,f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f5.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lfs f0,-8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -8);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,224(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// ble cr6,0x82266cd0
	if (!ctx.cr6.gt) goto loc_82266CD0;
	// fmr f0,f6
	ctx.f0.f64 = ctx.f6.f64;
loc_82266CD0:
	// lfs f13,-12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,-8(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + -8, temp.u32);
	// fcmpu cr6,f13,f4
	ctx.cr6.compare(ctx.f13.f64, ctx.f4.f64);
	// ble cr6,0x82266cec
	if (!ctx.cr6.gt) goto loc_82266CEC;
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// b 0x82266cfc
	goto loc_82266CFC;
loc_82266CEC:
	// fcmpu cr6,f13,f3
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f3.f64);
	// bge cr6,0x82266d00
	if (!ctx.cr6.lt) goto loc_82266D00;
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
loc_82266CFC:
	// stfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
loc_82266D00:
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f2
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// ble cr6,0x82266d10
	if (!ctx.cr6.gt) goto loc_82266D10;
	// stfs f2,0(r31)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
loc_82266D10:
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82266d20
	if (!ctx.cr6.lt) goto loc_82266D20;
	// stfs f31,0(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
loc_82266D20:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,-8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lfs f0,256(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f13,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.f13.u64);
	// lwz r5,196(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bgt cr6,0x82266d78
	if (ctx.cr6.gt) goto loc_82266D78;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82266D78:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82266dd8
	if (ctx.cr0.eq) goto loc_82266DD8;
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// ld r11,3456(r27)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r27.u32 + 3456);
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// stw r30,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r30,292(r1)
	REX_STORE_U32(ctx.r1.u32 + 292, ctx.r30.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// vslw128 v62,v62,v62
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stw r30,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r30.u32);
	// std r11,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r11.u64);
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82266dcc
	if (ctx.cr6.eq) goto loc_82266DCC;
	// addi r7,r5,1
	ctx.r7.s64 = ctx.r5.s64 + 1;
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x823af5b0
	ctx.lr = 0x82266DCC;
	sub_823AF5B0(ctx, base);
loc_82266DCC:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82266dd8
	if (ctx.cr0.eq) goto loc_82266DD8;
	// stb r30,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r30.u8);
loc_82266DD8:
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// addi r31,r31,28
	ctx.r31.s64 = ctx.r31.s64 + 28;
	// bne 0x82266bcc
	if (!ctx.cr0.eq) goto loc_82266BCC;
	// clrlwi. r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82266e24
	if (!ctx.cr0.eq) goto loc_82266E24;
	// stb r30,0(r23)
	REX_STORE_U8(ctx.r23.u32 + 0, ctx.r30.u8);
	// lwz r11,248(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 248);
	// lwz r10,252(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 252);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82266e24
	if (!ctx.cr6.gt) goto loc_82266E24;
	// lwz r11,248(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 248);
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
	ctx.lr = 0x82266E24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82266E24:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8228D870) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x8228D878;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af00
	ctx.lr = 0x8228D880;
	__savefpr_18(ctx, base);
	// stwu r1,-1744(r1)
	ea = -1744 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3080
	ctx.r30.s64 = ctx.r30.s64 + -3080;
	// stw r30,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r30.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8228e958
	if (ctx.cr6.eq) goto loc_8228E958;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8228e958
	if (!ctx.cr6.eq) goto loc_8228E958;
	// bl 0x82232628
	ctx.lr = 0x8228D8B0;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8228e958
	if (!ctx.cr0.eq) goto loc_8228E958;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62500
	ctx.r11.u64 = ctx.r11.u64 | 62500;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8228d9d4
	if (ctx.cr0.eq) goto loc_8228D9D4;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r28,r1,128
	ctx.r28.s64 = ctx.r1.s64 + 128;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// ld r6,60(r3)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r3.u32 + 60);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r29,r1,176
	ctx.r29.s64 = ctx.r1.s64 + 176;
	// lfs f12,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stfs f12,252(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// std r6,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r6.u64);
	// lfs f13,156(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,152(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,236(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f12,248(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f12,244(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f12,240(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
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
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
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
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// bl 0x823ba820
	ctx.lr = 0x8228D9C0;
	sub_823BA820(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8228d9d4
	if (!ctx.cr6.eq) goto loc_8228D9D4;
	// bl 0x823bb888
	ctx.lr = 0x8228D9D4;
	sub_823BB888(ctx, base);
loc_8228D9D4:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62718
	ctx.r11.u64 = ctx.r11.u64 | 62718;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8228e930
	if (ctx.cr0.eq) goto loc_8228E930;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// addi r20,r11,17984
	ctx.r20.s64 = ctx.r11.s64 + 17984;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r20,32288
	ctx.r11.s64 = ctx.r20.s64 + 32288;
	// addi r7,r8,12236
	ctx.r7.s64 = ctx.r8.s64 + 12236;
	// addi r15,r11,4
	ctx.r15.s64 = ctx.r11.s64 + 4;
	// lfs f20,12236(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12236);
	ctx.f20.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// lfs f19,-9856(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9856);
	ctx.f19.f64 = double(temp.f32);
	// li r17,0
	ctx.r17.s64 = 0;
	// addi r9,r9,-2253
	ctx.r9.s64 = ctx.r9.s64 + -2253;
	// lfs f27,232(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 232);
	ctx.f27.f64 = double(temp.f32);
	// addis r22,r31,1
	ctx.r22.s64 = ctx.r31.s64 + 65536;
	// lfs f21,2044(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2044);
	ctx.f21.f64 = double(temp.f32);
	// lfs f18,-6412(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6412);
	ctx.f18.f64 = double(temp.f32);
	// mr r14,r17
	ctx.r14.u64 = ctx.r17.u64;
	// stw r9,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// addi r22,r22,-2448
	ctx.r22.s64 = ctx.r22.s64 + -2448;
	// stw r9,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
	// li r29,-1
	ctx.r29.s64 = -1;
	// stw r17,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r17.u32);
	// li r18,255
	ctx.r18.s64 = 255;
	// addi r16,r11,-6412
	ctx.r16.s64 = ctx.r11.s64 + -6412;
	// addi r21,r10,-9856
	ctx.r21.s64 = ctx.r10.s64 + -9856;
loc_8228DA50:
	// lfs f0,-156(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -156);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,23696(r16)
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 23696);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8228e90c
	if (!ctx.cr6.lt) goto loc_8228E90C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// add r10,r14,r31
	ctx.r10.u64 = ctx.r14.u64 + ctx.r31.u64;
	// ori r11,r11,63244
	ctx.r11.u64 = ctx.r11.u64 | 63244;
	// lbzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8228e90c
	if (ctx.cr0.eq) goto loc_8228E90C;
	// lbzx r11,r9,r14
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r14.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8228e90c
	if (!ctx.cr0.eq) goto loc_8228E90C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r23,-4(r15)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r15.u32 + -4);
	// lwz r19,0(r15)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r15.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x8228dacc
	if (!ctx.cr6.eq) goto loc_8228DACC;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// blt cr6,0x8228dacc
	if (ctx.cr6.lt) goto loc_8228DACC;
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// lbz r10,38(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 38);
	// cmpw cr6,r23,r10
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8228dacc
	if (!ctx.cr6.lt) goto loc_8228DACC;
	// lwz r11,204(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// rlwinm r10,r23,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8228DACC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r23,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,204(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// lwzx r27,r10,r11
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8228e90c
	if (ctx.cr6.eq) goto loc_8228E90C;
	// lwz r30,24(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// clrlwi r28,r19,16
	ctx.r28.u64 = ctx.r19.u32 & 0xFFFF;
	// addi r6,r1,118
	ctx.r6.s64 = ctx.r1.s64 + 118;
	// sth r17,116(r1)
	REX_STORE_U16(ctx.r1.u32 + 116, ctx.r17.u16);
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// sth r17,118(r1)
	REX_STORE_U16(ctx.r1.u32 + 118, ctx.r17.u16);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823c2c38
	ctx.lr = 0x8228DB08;
	sub_823C2C38(ctx, base);
	// lhz r10,116(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 116);
	// lhz r11,118(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 118);
	// lfs f0,17424(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 17424);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r23,24
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 24, ctx.xer);
	// std r10,912(r1)
	REX_STORE_U64(ctx.r1.u32 + 912, ctx.r10.u64);
	// std r11,880(r1)
	REX_STORE_U64(ctx.r1.u32 + 880, ctx.r11.u64);
	// lfd f13,880(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 880);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfd f12,912(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 912);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f12,f12
	ctx.f12.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f12,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lhz r11,110(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 110);
	// rlwinm r25,r11,31,1,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r11,102(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// rlwinm r26,r11,31,1,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// bne cr6,0x8228dc88
	if (!ctx.cr6.eq) goto loc_8228DC88;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r3,r1,1152
	ctx.r3.s64 = ctx.r1.s64 + 1152;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8228DB80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,816
	ctx.r9.s64 = ctx.r1.s64 + 816;
	// lfs f13,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,828(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 828, temp.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// lfs f0,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,824(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 824, temp.u32);
	// addi r8,r1,1312
	ctx.r8.s64 = ctx.r1.s64 + 1312;
	// stfs f13,816(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 816, temp.u32);
	// addi r3,r1,1216
	ctx.r3.s64 = ctx.r1.s64 + 1216;
	// stfs f13,820(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 820, temp.u32);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stfs f0,344(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f0,348(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// stfs f0,340(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f0,336(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8228DBE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r10,r1,592
	ctx.r10.s64 = ctx.r1.s64 + 592;
	// lfs f13,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f13,604(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 604, temp.u32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// stfs f13,600(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 600, temp.u32);
	// addi r8,r1,1184
	ctx.r8.s64 = ctx.r1.s64 + 1184;
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stfs f0,372(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stfs f0,368(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// stfs f0,380(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// stfs f0,376(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// stfs f13,596(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 596, temp.u32);
	// stfs f13,592(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 592, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,1312(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1312);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1184(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1184);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// bctrl 
	ctx.lr = 0x8228DC58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r9,r1,120
	ctx.r9.s64 = ctx.r1.s64 + 120;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x823c00a0
	ctx.lr = 0x8228DC7C;
	sub_823C00A0(ctx, base);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8228e008
	goto loc_8228E008;
loc_8228DC88:
	// cmplwi cr6,r23,21
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 21, ctx.xer);
	// bne cr6,0x8228ddb4
	if (!ctx.cr6.eq) goto loc_8228DDB4;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r3,r1,992
	ctx.r3.s64 = ctx.r1.s64 + 992;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8228DCAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,400
	ctx.r11.s64 = ctx.r1.s64 + 400;
	// addi r10,r1,720
	ctx.r10.s64 = ctx.r1.s64 + 720;
	// lfs f13,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,728(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 728, temp.u32);
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,408(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// addi r8,r1,1440
	ctx.r8.s64 = ctx.r1.s64 + 1440;
	// stfs f13,720(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 720, temp.u32);
	// addi r3,r1,1344
	ctx.r3.s64 = ctx.r1.s64 + 1344;
	// stfs f0,404(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f13,732(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 732, temp.u32);
	// lwz r4,4(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stfs f13,724(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 724, temp.u32);
	// stfs f0,412(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// stfs f0,400(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,60(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bctrl 
	ctx.lr = 0x8228DD0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// addi r9,r1,624
	ctx.r9.s64 = ctx.r1.s64 + 624;
	// lfs f13,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,440(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 440, temp.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,436(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// addi r8,r1,960
	ctx.r8.s64 = ctx.r1.s64 + 960;
	// stfs f0,444(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 444, temp.u32);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stfs f0,432(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// stfs f13,636(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 636, temp.u32);
	// stfs f13,632(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 632, temp.u32);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f13,628(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 628, temp.u32);
	// stfs f13,624(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 624, temp.u32);
	// lfs f0,1440(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1440);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,960(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 960);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// bctrl 
	ctx.lr = 0x8228DD84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r9,r1,120
	ctx.r9.s64 = ctx.r1.s64 + 120;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x823c00a0
	ctx.lr = 0x8228DDA8;
	sub_823C00A0(ctx, base);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8228e008
	goto loc_8228E008;
loc_8228DDB4:
	// cmplwi cr6,r23,25
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 25, ctx.xer);
	// bne cr6,0x8228dee0
	if (!ctx.cr6.eq) goto loc_8228DEE0;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r3,r1,1024
	ctx.r3.s64 = ctx.r1.s64 + 1024;
	// lwz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8228DDD8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,784
	ctx.r11.s64 = ctx.r1.s64 + 784;
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// lfs f13,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,796(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 796, temp.u32);
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,792(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 792, temp.u32);
	// addi r8,r1,976
	ctx.r8.s64 = ctx.r1.s64 + 976;
	// stfs f0,788(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 788, temp.u32);
	// addi r3,r1,1056
	ctx.r3.s64 = ctx.r1.s64 + 1056;
	// stfs f0,784(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 784, temp.u32);
	// stfs f13,268(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f13,264(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// lwz r4,8(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// stfs f13,256(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f13,260(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,60(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bctrl 
	ctx.lr = 0x8228DE38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r10,r1,656
	ctx.r10.s64 = ctx.r1.s64 + 656;
	// lfs f13,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,656(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 656, temp.u32);
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r11,r1,464
	ctx.r11.s64 = ctx.r1.s64 + 464;
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,476(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 476, temp.u32);
	// addi r8,r1,1008
	ctx.r8.s64 = ctx.r1.s64 + 1008;
	// stfs f0,472(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stfs f0,468(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// lwz r3,8(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// stfs f0,464(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// stfs f13,668(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 668, temp.u32);
	// stfs f13,660(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 660, temp.u32);
	// stfs f13,664(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 664, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,976(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 976);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r9,152(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 152);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lfs f0,1008(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1008);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// bctrl 
	ctx.lr = 0x8228DEB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// addi r9,r1,120
	ctx.r9.s64 = ctx.r1.s64 + 120;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x823c00a0
	ctx.lr = 0x8228DED4;
	sub_823C00A0(ctx, base);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8228e008
	goto loc_8228E008;
loc_8228DEE0:
	// cmplwi cr6,r23,27
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 27, ctx.xer);
	// bne cr6,0x8228e020
	if (!ctx.cr6.eq) goto loc_8228E020;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r3,r1,1408
	ctx.r3.s64 = ctx.r1.s64 + 1408;
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8228DF04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,496
	ctx.r11.s64 = ctx.r1.s64 + 496;
	// addi r10,r1,752
	ctx.r10.s64 = ctx.r1.s64 + 752;
	// lfs f13,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,508(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 508, temp.u32);
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,504(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// addi r8,r1,1040
	ctx.r8.s64 = ctx.r1.s64 + 1040;
	// stfs f0,496(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// stfs f0,500(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// stfs f13,764(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 764, temp.u32);
	// stfs f13,760(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 760, temp.u32);
	// lwz r4,12(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// stfs f13,756(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 756, temp.u32);
	// stfs f13,752(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 752, temp.u32);
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,60(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bctrl 
	ctx.lr = 0x8228DF64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,688
	ctx.r10.s64 = ctx.r1.s64 + 688;
	// addi r11,r1,528
	ctx.r11.s64 = ctx.r1.s64 + 528;
	// lfs f13,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,700(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 700, temp.u32);
	// lwz r8,248(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,696(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 696, temp.u32);
	// addi r9,r1,1072
	ctx.r9.s64 = ctx.r1.s64 + 1072;
	// stfs f0,688(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 688, temp.u32);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stfs f0,692(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 692, temp.u32);
	// stfs f13,540(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// stfs f13,536(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// lwz r3,12(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// stfs f13,532(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// stfs f13,528(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// lfs f0,1040(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1040);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,152(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 152);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1072(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1072);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// bctrl 
	ctx.lr = 0x8228DFDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r9,r1,120
	ctx.r9.s64 = ctx.r1.s64 + 120;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x823c00a0
	ctx.lr = 0x8228E000;
	sub_823C00A0(ctx, base);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
loc_8228E008:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8228E01C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8228e04c
	goto loc_8228E04C;
loc_8228E020:
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r1,120
	ctx.r9.s64 = ctx.r1.s64 + 120;
	// lwz r6,36(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 36);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,32(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 32);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// bl 0x823c00a0
	ctx.lr = 0x8228E04C;
	sub_823C00A0(ctx, base);
loc_8228E04C:
	// lwz r10,0(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// clrlwi r24,r25,16
	ctx.r24.u64 = ctx.r25.u32 & 0xFFFF;
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// clrlwi r30,r26,16
	ctx.r30.u64 = ctx.r26.u32 & 0xFFFF;
	// extsw r9,r24
	ctx.r9.s64 = ctx.r24.s32;
	// lfs f0,0(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// std r9,896(r1)
	REX_STORE_U64(ctx.r1.u32 + 896, ctx.r9.u64);
	// lfd f13,896(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 896);
	// std r10,920(r1)
	REX_STORE_U64(ctx.r1.u32 + 920, ctx.r10.u64);
	// lfd f12,920(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 920);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f29,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f29.f64 = double(temp.f32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lfs f24,84(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 84);
	ctx.f24.f64 = double(temp.f32);
	// frsp f26,f13
	ctx.f26.f64 = double(float(ctx.f13.f64));
	// lfs f28,36(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f28.f64 = double(temp.f32);
	// lfs f23,116(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 116);
	ctx.f23.f64 = double(temp.f32);
	// fsubs f11,f29,f24
	ctx.f11.f64 = double(float(ctx.f29.f64 - ctx.f24.f64));
	// fsubs f10,f23,f28
	ctx.f10.f64 = double(float(ctx.f23.f64 - ctx.f28.f64));
	// extsw r10,r30
	ctx.r10.s64 = ctx.r30.s32;
	// std r10,936(r1)
	REX_STORE_U64(ctx.r1.u32 + 936, ctx.r10.u64);
	// lfd f9,936(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 936);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// fdivs f13,f12,f26
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f26.f64));
	// fnmsubs f12,f11,f13,f29
	ctx.f12.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f13.f64, -ctx.f29.f64)));
	// stfs f12,4(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f12,44(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// fmadds f13,f10,f13,f28
	ctx.f13.f64 = double(float(std::fma(ctx.f10.f64, ctx.f13.f64, ctx.f28.f64)));
	// stfs f13,36(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 36, temp.u32);
	// stfs f13,76(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 76, temp.u32);
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// lfs f13,96(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// std r11,864(r1)
	REX_STORE_U64(ctx.r1.u32 + 864, ctx.r11.u64);
	// lfs f12,-156(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -156);
	ctx.f12.f64 = double(temp.f32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lfd f13,864(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 864);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f11,f13,f9
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f9.f64));
	// fmsubs f0,f12,f0,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f11.f64)));
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// bge cr6,0x8228e108
	if (!ctx.cr6.lt) goto loc_8228E108;
	// fmr f0,f27
	ctx.f0.f64 = ctx.f27.f64;
loc_8228E108:
	// fmuls f22,f0,f18
	ctx.fpscr.disableFlushMode();
	ctx.f22.f64 = double(float(ctx.f0.f64 * ctx.f18.f64));
	// fcmpu cr6,f22,f13
	ctx.cr6.compare(ctx.f22.f64, ctx.f13.f64);
	// ble cr6,0x8228e11c
	if (!ctx.cr6.gt) goto loc_8228E11C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
loc_8228E11C:
	// lfs f3,23508(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 23508);
	ctx.f3.f64 = double(temp.f32);
	// mr r26,r17
	ctx.r26.u64 = ctx.r17.u64;
	// mr r25,r17
	ctx.r25.u64 = ctx.r17.u64;
loc_8228E128:
	// clrldi r11,r26,32
	ctx.r11.u64 = ctx.r26.u64 & 0xFFFFFFFF;
	// lfs f0,-20276(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -20276);
	ctx.f0.f64 = double(temp.f32);
	// std r11,848(r1)
	REX_STORE_U64(ctx.r1.u32 + 848, ctx.r11.u64);
	// lfd f13,848(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 848);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f31,f13
	ctx.f31.f64 = double(float(ctx.f13.f64));
	// fsubs f30,f22,f31
	ctx.f30.f64 = double(float(ctx.f22.f64 - ctx.f31.f64));
	// fmuls f25,f30,f0
	ctx.f25.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// fcmpu cr6,f25,f3
	ctx.cr6.compare(ctx.f25.f64, ctx.f3.f64);
	// blt cr6,0x8228e164
	if (ctx.cr6.lt) goto loc_8228E164;
	// cmplw cr6,r26,r24
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r24.u32, ctx.xer);
	// blt cr6,0x8228e164
	if (ctx.cr6.lt) goto loc_8228E164;
	// lwz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
loc_8228E164:
	// fcmpu cr6,f25,f3
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f25.f64, ctx.f3.f64);
	// bge cr6,0x8228e8f0
	if (!ctx.cr6.lt) goto loc_8228E8F0;
	// cmplwi cr6,r23,24
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 24, ctx.xer);
	// bne cr6,0x8228e28c
	if (!ctx.cr6.eq) goto loc_8228E28C;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r3,r1,1280
	ctx.r3.s64 = ctx.r1.s64 + 1280;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8228E190;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,560
	ctx.r11.s64 = ctx.r1.s64 + 560;
	// stfs f0,572(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// stfs f0,568(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,564(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 564, temp.u32);
	// addi r8,r1,1104
	ctx.r8.s64 = ctx.r1.s64 + 1104;
	// stfs f0,560(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 560, temp.u32);
	// addi r3,r1,944
	ctx.r3.s64 = ctx.r1.s64 + 944;
	// lfs f0,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,60(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bctrl 
	ctx.lr = 0x8228E1F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// lfs f13,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,320
	ctx.r11.s64 = ctx.r1.s64 + 320;
	// stfs f13,284(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// addi r9,r1,1136
	ctx.r9.s64 = ctx.r1.s64 + 1136;
	// stfs f13,280(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// lwz r8,248(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f13,276(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f13,272(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f0,332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f0,328(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f0,324(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// lwz r3,0(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// lfs f0,1104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1104);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,152(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 152);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
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
	// lfs f0,1136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1136);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// bctrl 
	ctx.lr = 0x8228E264;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x823c00a0
	ctx.lr = 0x8228E288;
	sub_823C00A0(ctx, base);
	// b 0x8228e618
	goto loc_8228E618;
loc_8228E28C:
	// cmplwi cr6,r23,21
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 21, ctx.xer);
	// bne cr6,0x8228e3ac
	if (!ctx.cr6.eq) goto loc_8228E3AC;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r3,r1,1120
	ctx.r3.s64 = ctx.r1.s64 + 1120;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8228E2B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// lfs f13,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,384
	ctx.r11.s64 = ctx.r1.s64 + 384;
	// stfs f13,364(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f13,360(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// addi r8,r1,1168
	ctx.r8.s64 = ctx.r1.s64 + 1168;
	// stfs f13,356(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// addi r3,r1,1248
	ctx.r3.s64 = ctx.r1.s64 + 1248;
	// stfs f13,352(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// stfs f0,396(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// stfs f0,392(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// lwz r4,4(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stfs f0,388(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// stfs f0,384(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,60(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bctrl 
	ctx.lr = 0x8228E310;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,416
	ctx.r11.s64 = ctx.r1.s64 + 416;
	// lfs f13,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
	// stfs f0,428(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 428, temp.u32);
	// addi r9,r1,1200
	ctx.r9.s64 = ctx.r1.s64 + 1200;
	// stfs f0,424(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 424, temp.u32);
	// lwz r8,248(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,420(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// stfs f0,416(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// stfs f13,460(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 460, temp.u32);
	// stfs f13,456(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// stfs f13,452(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// lwz r3,4(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stfs f13,448(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// lfs f0,1168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1168);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,152(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 152);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1200(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1200);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// bctrl 
	ctx.lr = 0x8228E384;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x823c00a0
	ctx.lr = 0x8228E3A8;
	sub_823C00A0(ctx, base);
	// b 0x8228e618
	goto loc_8228E618;
loc_8228E3AC:
	// cmplwi cr6,r23,25
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 25, ctx.xer);
	// bne cr6,0x8228e4cc
	if (!ctx.cr6.eq) goto loc_8228E4CC;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r3,r1,1376
	ctx.r3.s64 = ctx.r1.s64 + 1376;
	// lwz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8228E3D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,480
	ctx.r11.s64 = ctx.r1.s64 + 480;
	// addi r10,r1,512
	ctx.r10.s64 = ctx.r1.s64 + 512;
	// lfs f13,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,492(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,488(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// addi r8,r1,1232
	ctx.r8.s64 = ctx.r1.s64 + 1232;
	// stfs f0,484(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// stfs f0,480(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// stfs f13,524(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// stfs f13,520(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// lwz r4,8(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// stfs f13,512(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// stfs f13,516(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,60(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bctrl 
	ctx.lr = 0x8228E430;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,544
	ctx.r11.s64 = ctx.r1.s64 + 544;
	// addi r10,r1,576
	ctx.r10.s64 = ctx.r1.s64 + 576;
	// lfs f13,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,556(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 556, temp.u32);
	// lwz r8,248(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,552(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 552, temp.u32);
	// addi r9,r1,1264
	ctx.r9.s64 = ctx.r1.s64 + 1264;
	// stfs f0,548(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 548, temp.u32);
	// stfs f0,544(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 544, temp.u32);
	// stfs f13,588(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 588, temp.u32);
	// stfs f13,584(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 584, temp.u32);
	// lwz r3,8(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// stfs f13,580(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 580, temp.u32);
	// stfs f13,576(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 576, temp.u32);
	// lfs f0,1232(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1232);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,152(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 152);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
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
	// lfs f0,1264(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1264);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// bctrl 
	ctx.lr = 0x8228E4A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x823c00a0
	ctx.lr = 0x8228E4C8;
	sub_823C00A0(ctx, base);
	// b 0x8228e618
	goto loc_8228E618;
loc_8228E4CC:
	// cmplwi cr6,r23,27
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 27, ctx.xer);
	// bne cr6,0x8228e5ec
	if (!ctx.cr6.eq) goto loc_8228E5EC;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8228E4F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,608
	ctx.r11.s64 = ctx.r1.s64 + 608;
	// addi r9,r1,640
	ctx.r9.s64 = ctx.r1.s64 + 640;
	// lfs f13,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,620(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 620, temp.u32);
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,616(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 616, temp.u32);
	// addi r8,r1,1296
	ctx.r8.s64 = ctx.r1.s64 + 1296;
	// stfs f0,612(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 612, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,608(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 608, temp.u32);
	// stfs f13,652(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 652, temp.u32);
	// stfs f13,648(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 648, temp.u32);
	// lwz r4,12(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// stfs f13,644(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 644, temp.u32);
	// stfs f13,640(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 640, temp.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,60(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bctrl 
	ctx.lr = 0x8228E550;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,672
	ctx.r11.s64 = ctx.r1.s64 + 672;
	// addi r10,r1,704
	ctx.r10.s64 = ctx.r1.s64 + 704;
	// lfs f13,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,684(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 684, temp.u32);
	// addi r9,r1,1328
	ctx.r9.s64 = ctx.r1.s64 + 1328;
	// stfs f0,680(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 680, temp.u32);
	// lwz r8,248(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,676(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 676, temp.u32);
	// stfs f0,672(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 672, temp.u32);
	// stfs f13,716(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 716, temp.u32);
	// stfs f13,708(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 708, temp.u32);
	// stfs f13,712(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 712, temp.u32);
	// lwz r3,12(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// stfs f13,704(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 704, temp.u32);
	// lfs f0,1296(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1296);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,152(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 152);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
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
	// lfs f0,1328(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1328);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// bctrl 
	ctx.lr = 0x8228E5C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x823c00a0
	ctx.lr = 0x8228E5E8;
	sub_823C00A0(ctx, base);
	// b 0x8228e618
	goto loc_8228E618;
loc_8228E5EC:
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r6,36(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 36);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r5,32(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,24(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// bl 0x823c00a0
	ctx.lr = 0x8228E618;
	sub_823C00A0(ctx, base);
loc_8228E618:
	// lfs f3,23508(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 23508);
	ctx.f3.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8228e8f0
	if (ctx.cr6.eq) goto loc_8228E8F0;
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// lwz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// clrldi r9,r25,32
	ctx.r9.u64 = ctx.r25.u64 & 0xFFFFFFFF;
	// lfs f2,-22360(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -22360);
	ctx.f2.f64 = double(temp.f32);
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// fsubs f10,f29,f24
	ctx.f10.f64 = double(float(ctx.f29.f64 - ctx.f24.f64));
	// std r9,928(r1)
	REX_STORE_U64(ctx.r1.u32 + 928, ctx.r9.u64);
	// lfd f0,928(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 928);
	// std r11,856(r1)
	REX_STORE_U64(ctx.r1.u32 + 856, ctx.r11.u64);
	// lfd f13,856(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 856);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stb r18,144(r1)
	REX_STORE_U8(ctx.r1.u32 + 144, ctx.r18.u8);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// stb r18,145(r1)
	REX_STORE_U8(ctx.r1.u32 + 145, ctx.r18.u8);
	// frsp f5,f0
	ctx.f5.f64 = double(float(ctx.f0.f64));
	// stb r18,146(r1)
	REX_STORE_U8(ctx.r1.u32 + 146, ctx.r18.u8);
	// fsubs f9,f23,f28
	ctx.f9.f64 = double(float(ctx.f23.f64 - ctx.f28.f64));
	// mr r7,r17
	ctx.r7.u64 = ctx.r17.u64;
	// fdivs f8,f31,f26
	ctx.f8.f64 = double(float(ctx.f31.f64 / ctx.f26.f64));
	// addi r11,r10,44
	ctx.r11.s64 = ctx.r10.s64 + 44;
	// fmuls f4,f30,f21
	ctx.f4.f64 = double(float(ctx.f30.f64 * ctx.f21.f64));
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// fdivs f7,f0,f26
	ctx.f7.f64 = double(float(ctx.f0.f64 / ctx.f26.f64));
loc_8228E684:
	// lwa r10,36(r27)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r27.u32 + 36));
	// lfs f13,-12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// std r10,888(r1)
	REX_STORE_U64(ctx.r1.u32 + 888, ctx.r10.u64);
	// lfs f0,-44(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -44);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lwa r8,32(r27)
	ctx.r8.s64 = int32_t(REX_LOAD_U32(ctx.r27.u32 + 32));
	// std r8,872(r1)
	REX_STORE_U64(ctx.r1.u32 + 872, ctx.r8.u64);
	// lfd f11,872(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 872);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lfs f12,8(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfd f1,888(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + 888);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fcfid f13,f1
	ctx.f13.f64 = double(ctx.f1.s64);
	// clrldi r9,r7,32
	ctx.r9.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// lfs f6,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// li r5,20
	ctx.r5.s64 = 20;
	// std r9,904(r1)
	REX_STORE_U64(ctx.r1.u32 + 904, ctx.r9.u64);
	// lfd f1,904(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + 904);
	// fcfid f1,f1
	ctx.f1.f64 = double(ctx.f1.s64);
	// addi r10,r21,-4968
	ctx.r10.s64 = ctx.r21.s64 + -4968;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// addi r4,r10,8
	ctx.r4.s64 = ctx.r10.s64 + 8;
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// frsp f11,f1
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// addi r9,r21,-4968
	ctx.r9.s64 = ctx.r21.s64 + -4968;
	// addi r10,r21,-4968
	ctx.r10.s64 = ctx.r21.s64 + -4968;
	// addi r8,r21,-4968
	ctx.r8.s64 = ctx.r21.s64 + -4968;
	// addi r3,r21,-4968
	ctx.r3.s64 = ctx.r21.s64 + -4968;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmuls f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// fmadds f0,f0,f5,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f5.f64, ctx.f13.f64)));
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r14,100(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// divwu r5,r14,r5
	ctx.r5.u64 = uint32_t(ctx.r5.u32 ? ctx.r14.u32 / ctx.r5.u32 : 0);
	// mulli r5,r5,20
	ctx.r5.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(20));
	// subf r5,r5,r14
	ctx.r5.u64 = ctx.r14.u64 - ctx.r5.u64;
	// mulli r5,r5,20
	ctx.r5.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(20));
	// lfsx f0,r5,r4
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f0,f3
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f3.f64));
	// lfsx f13,r5,r3
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r5,r9
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f6,r5,r10
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfsx f0,r5,r8
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f11,f25,f11
	ctx.f11.f64 = double(float(ctx.f25.f64 / ctx.f11.f64));
	// fsubs f11,f20,f11
	ctx.f11.f64 = double(float(ctx.f20.f64 - ctx.f11.f64));
	// fcmpu cr6,f11,f27
	ctx.cr6.compare(ctx.f11.f64, ctx.f27.f64);
	// bge cr6,0x8228e75c
	if (!ctx.cr6.lt) goto loc_8228E75C;
	// fmr f11,f27
	ctx.f11.f64 = ctx.f27.f64;
loc_8228E75C:
	// fsubs f0,f4,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f4.f64 - ctx.f0.f64));
	// addi r10,r11,-40
	ctx.r10.s64 = ctx.r11.s64 + -40;
	// fnmsubs f1,f8,f10,f29
	ctx.f1.f64 = double(float(-std::fma(ctx.f8.f64, ctx.f10.f64, -ctx.f29.f64)));
	// stfs f1,-40(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + -40, temp.u32);
	// stfs f1,0(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fmadds f1,f8,f9,f28
	ctx.f1.f64 = double(float(std::fma(ctx.f8.f64, ctx.f9.f64, ctx.f28.f64)));
	// stfs f1,-8(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + -8, temp.u32);
	// fnmsubs f31,f7,f10,f29
	ctx.f31.f64 = double(float(-std::fma(ctx.f7.f64, ctx.f10.f64, -ctx.f29.f64)));
	// stfs f1,32(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// fmadds f1,f7,f9,f28
	ctx.f1.f64 = double(float(std::fma(ctx.f7.f64, ctx.f9.f64, ctx.f28.f64)));
	// stfs f31,40(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// stfs f31,80(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// stfs f1,72(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 72, temp.u32);
	// stfs f1,112(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 112, temp.u32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// bgt cr6,0x8228e7a0
	if (ctx.cr6.gt) goto loc_8228E7A0;
	// fmr f0,f27
	ctx.f0.f64 = ctx.f27.f64;
loc_8228E7A0:
	// fmuls f6,f0,f6
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f6.f64));
	// addi r8,r1,736
	ctx.r8.s64 = ctx.r1.s64 + 736;
	// stfs f12,736(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 736, temp.u32);
	// addi r5,r1,768
	ctx.r5.s64 = ctx.r1.s64 + 768;
	// stfs f12,740(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 740, temp.u32);
	// addi r4,r1,800
	ctx.r4.s64 = ctx.r1.s64 + 800;
	// stfs f12,748(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 748, temp.u32);
	// addi r3,r1,1360
	ctx.r3.s64 = ctx.r1.s64 + 1360;
	// stfs f12,744(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 744, temp.u32);
	// fmuls f11,f11,f19
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f19.f64));
	// lfs f12,23696(r16)
	temp.u32 = REX_LOAD_U32(ctx.r16.u32 + 23696);
	ctx.f12.f64 = double(temp.f32);
	// addi r14,r1,1392
	ctx.r14.s64 = ctx.r1.s64 + 1392;
	// stfs f13,780(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 780, temp.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f13,776(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 776, temp.u32);
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// stfs f13,768(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 768, temp.u32);
	// stfs f13,772(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 772, temp.u32);
	// fmadds f13,f6,f12,f2
	ctx.f13.f64 = double(float(std::fma(ctx.f6.f64, ctx.f12.f64, ctx.f2.f64)));
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// fctidz f12,f11
	ctx.f12.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f12,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// lbz r9,103(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// stb r9,147(r1)
	REX_STORE_U8(ctx.r1.u32 + 147, ctx.r9.u8);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,800(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 800, temp.u32);
	// stfs f0,804(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 804, temp.u32);
	// lvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,812(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 812, temp.u32);
	// stfs f0,808(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 808, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,1392(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1392);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,316(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// lfs f0,1360(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1360);
	ctx.f0.f64 = double(temp.f32);
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
	// stfs f13,312(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f13,308(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// stfs f13,304(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
loc_8228E858:
	// lfs f0,16(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// addi r5,r1,832
	ctx.r5.s64 = ctx.r1.s64 + 832;
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r3,r1,1424
	ctx.r3.s64 = ctx.r1.s64 + 1424;
	// lfs f0,12(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// addi r14,r1,1456
	ctx.r14.s64 = ctx.r1.s64 + 1456;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lwz r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v60,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1424(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1424);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,12(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// lfs f0,1456(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1456);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,16(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// stwu r11,40(r10)
	ea = 40 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// bdnz 0x8228e858
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8228E858;
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// add r7,r7,r23
	ctx.r7.u64 = ctx.r7.u64 + ctx.r23.u64;
	// addi r11,r11,160
	ctx.r11.s64 = ctx.r11.s64 + 160;
	// bne 0x8228e684
	if (!ctx.cr0.eq) goto loc_8228E684;
	// lwz r14,164(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
loc_8228E8F0:
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// add r25,r25,r19
	ctx.r25.u64 = ctx.r25.u64 + ctx.r19.u64;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8228e128
	if (!ctx.cr6.gt) goto loc_8228E128;
	// lwz r9,152(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r30,192(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
loc_8228E90C:
	// lwz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addi r22,r22,4
	ctx.r22.s64 = ctx.r22.s64 + 4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r14,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r14.u32);
	// addi r15,r15,8
	ctx.r15.s64 = ctx.r15.s64 + 8;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// cmplwi cr6,r14,25
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 25, ctx.xer);
	// blt cr6,0x8228da50
	if (ctx.cr6.lt) goto loc_8228DA50;
loc_8228E930:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82231a30
	ctx.lr = 0x8228E938;
	sub_82231A30(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8228e958
	if (!ctx.cr6.eq) goto loc_8228E958;
	// lbz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 20);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8228e958
	if (ctx.cr0.eq) goto loc_8228E958;
	// bl 0x823bba60
	ctx.lr = 0x8228E958;
	sub_823BBA60(ctx, base);
loc_8228E958:
	// addi r1,r1,1744
	ctx.r1.s64 = ctx.r1.s64 + 1744;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af4c
	ctx.lr = 0x8228E964;
	__restfpr_18(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8232CD08) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x8232CD38;
	sub_8222FF78(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
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
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x8232CD8C;
	sub_8222FF78(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
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
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// li r3,0
	ctx.r3.s64 = 0;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lwz r11,-13032(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8232cdfc
	if (ctx.cr6.eq) goto loc_8232CDFC;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	ctx.lr = 0x8232CDFC;
	sub_823AEFA8(ctx, base);
loc_8232CDFC:
	// lbz r11,228(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 228);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

DEFINE_REX_FUNC(sub_82336D28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82336D30;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,466(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 466);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82336db0
	if (!ctx.cr0.eq) goto loc_82336DB0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82336db0
	if (ctx.cr6.eq) goto loc_82336DB0;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// addi r30,r30,-3084
	ctx.r30.s64 = ctx.r30.s64 + -3084;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82336d6c
	if (ctx.cr0.eq) goto loc_82336D6C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x82336D6C;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_82336D6C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,62436
	ctx.r11.u64 = ctx.r11.u64 | 62436;
	// addi r10,r10,-3096
	ctx.r10.s64 = ctx.r10.s64 + -3096;
	// li r9,1
	ctx.r9.s64 = 1;
	// stbx r9,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u8);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82336db0
	if (ctx.cr0.eq) goto loc_82336DB0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x82336DB0;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82336DB0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8233A900) {
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
	// ori r4,r4,62572
	ctx.r4.u64 = ctx.r4.u64 | 62572;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8233A928;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8233a938
	if (ctx.cr0.eq) goto loc_8233A938;
	// bl 0x8233a528
	ctx.lr = 0x8233A934;
	sub_8233A528(ctx, base);
	// b 0x8233a93c
	goto loc_8233A93C;
loc_8233A938:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8233A93C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8233B020) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x8233B028;
	__savegprlr_20(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r21,r3,1
	ctx.r21.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r21,r21,-3160
	ctx.r21.s64 = ctx.r21.s64 + -3160;
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8233b650
	if (ctx.cr6.eq) goto loc_8233B650;
	// addis r8,r3,1
	ctx.r8.s64 = ctx.r3.s64 + 65536;
	// lis r7,0
	ctx.r7.s64 = 0;
	// addi r8,r8,-2980
	ctx.r8.s64 = ctx.r8.s64 + -2980;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lbz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// ori r23,r7,62552
	ctx.r23.u64 = ctx.r7.u64 | 62552;
	// li r20,1
	ctx.r20.s64 = 1;
	// lis r28,-32228
	ctx.r28.s64 = -2112094208;
	// li r22,0
	ctx.r22.s64 = 0;
	// ori r30,r6,62400
	ctx.r30.u64 = ctx.r6.u64 | 62400;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// addi r29,r11,32688
	ctx.r29.s64 = ctx.r11.s64 + 32688;
	// cmplwi r5,0
	ctx.cr0.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// addi r26,r10,32720
	ctx.r26.s64 = ctx.r10.s64 + 32720;
	// addi r25,r9,1272
	ctx.r25.s64 = ctx.r9.s64 + 1272;
	// beq 0x8233b210
	if (ctx.cr0.eq) goto loc_8233B210;
	// lwzx r11,r3,r23
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r23.u32);
	// add r24,r3,r23
	ctx.r24.u64 = ctx.r3.u64 + ctx.r23.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8233b0dc
	if (ctx.cr6.eq) goto loc_8233B0DC;
	// lwz r10,-12816(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + -12816);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8233b0d8
	if (!ctx.cr6.eq) goto loc_8233B0D8;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8233b0d8
	if (ctx.cr6.eq) goto loc_8233B0D8;
	// lbz r10,23(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8233b0d8
	if (!ctx.cr0.eq) goto loc_8233B0D8;
	// stb r20,23(r11)
	REX_STORE_U8(ctx.r11.u32 + 23, ctx.r20.u8);
loc_8233B0D8:
	// stw r22,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r22.u32);
loc_8233B0DC:
	// stb r22,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r22.u8);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x8233B118;
	sub_8255F918(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfsx f13,r31,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,1608(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1608);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x8233B174;
	sub_8255F918(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r10,r10,22072
	ctx.r10.s64 = ctx.r10.s64 + 22072;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r4,5312
	ctx.r4.s64 = 5312;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,44(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x8233B1C0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8233b1e0
	if (ctx.cr0.eq) goto loc_8233B1E0;
	// li r7,5
	ctx.r7.s64 = 5;
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x824e7748
	ctx.lr = 0x8233B1DC;
	sub_824E7748(ctx, base);
	// b 0x8233b1e4
	goto loc_8233B1E4;
loc_8233B1E0:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
loc_8233B1E4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233b210
	if (ctx.cr6.eq) goto loc_8233B210;
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f13,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stb r22,80(r3)
	REX_STORE_U8(ctx.r3.u32 + 80, ctx.r22.u8);
	// lfs f0,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,5292(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 5292, temp.u32);
	// stw r9,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r9.u32);
loc_8233B210:
	// addis r21,r31,1
	ctx.r21.s64 = ctx.r31.s64 + 65536;
	// addi r21,r21,-2979
	ctx.r21.s64 = ctx.r21.s64 + -2979;
	// lbz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r21.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8233b5d4
	if (ctx.cr0.eq) goto loc_8233B5D4;
	// add r23,r31,r23
	ctx.r23.u64 = ctx.r31.u64 + ctx.r23.u64;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8233b5d0
	if (ctx.cr6.eq) goto loc_8233B5D0;
	// lwz r10,-12816(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + -12816);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8233b5cc
	if (!ctx.cr6.eq) goto loc_8233B5CC;
	// lwz r24,4(r10)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8233b5cc
	if (ctx.cr6.eq) goto loc_8233B5CC;
	// lbz r11,23(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 23);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8233b5cc
	if (!ctx.cr0.eq) goto loc_8233B5CC;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8255f918
	ctx.lr = 0x8233B278;
	sub_8255F918(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfsx f13,r31,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,1608(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1608);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x8233B2D4;
	sub_8255F918(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
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
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8233f680
	ctx.lr = 0x8233B32C;
	sub_8233F680(ctx, base);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r10,32496
	ctx.r10.s64 = ctx.r10.s64 + 32496;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,32256
	ctx.r8.s64 = ctx.r8.s64 + 32256;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v53,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v52,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_load_si128((simde__m128i*)ctx.v53.u8));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f6,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f6.f64 = double(temp.f32);
	// lwz r27,-13032(r10)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
loc_8233B3CC:
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8255f918
	ctx.lr = 0x8233B3DC;
	sub_8255F918(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// vaddfp128 v63,v63,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v52.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v53
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v53.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r29,100(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r30,100(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// beq cr6,0x8233b474
	if (ctx.cr6.eq) goto loc_8233B474;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823aebd8
	ctx.lr = 0x8233B474;
	sub_823AEBD8(ctx, base);
loc_8233B474:
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
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// blt cr6,0x8233b4a0
	if (ctx.cr6.lt) goto loc_8233B4A0;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpwi cr6,r28,50
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 50, ctx.xer);
	// blt cr6,0x8233b3cc
	if (ctx.cr6.lt) goto loc_8233B3CC;
	// b 0x8233b524
	goto loc_8233B524;
loc_8233B4A0:
	// add r11,r3,r29
	ctx.r11.u64 = ctx.r3.u64 + ctx.r29.u64;
	// extsw r9,r30
	ctx.r9.s64 = ctx.r30.s32;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r9,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfd f13,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
loc_8233B524:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8230d580
	ctx.lr = 0x8233B534;
	sub_8230D580(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// ld r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lbz r9,5309(r24)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r24.u32 + 5309);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// std r10,5008(r24)
	REX_STORE_U64(ctx.r24.u32 + 5008, ctx.r10.u64);
	// std r11,5000(r24)
	REX_STORE_U64(ctx.r24.u32 + 5000, ctx.r11.u64);
	// beq 0x8233b558
	if (ctx.cr0.eq) goto loc_8233B558;
	// stw r20,5016(r24)
	REX_STORE_U32(ctx.r24.u32 + 5016, ctx.r20.u32);
loc_8233B558:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r10,r10,-32176
	ctx.r10.s64 = ctx.r10.s64 + -32176;
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_8233B5CC:
	// stw r22,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r22.u32);
loc_8233B5D0:
	// stb r22,0(r21)
	REX_STORE_U8(ctx.r21.u32 + 0, ctx.r22.u8);
loc_8233B5D4:
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x8233B60C;
	sub_8255F918(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8255f918
	ctx.lr = 0x8233B61C;
	sub_8255F918(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62328
	ctx.r11.u64 = ctx.r11.u64 | 62328;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8233b648
	if (ctx.cr0.eq) goto loc_8233B648;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r10,-3204
	ctx.r10.s64 = ctx.r10.s64 + -3204;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
loc_8233B648:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8233b658
	ctx.lr = 0x8233B650;
	sub_8233B658(ctx, base);
loc_8233B650:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8236C870) {
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
	// bl 0x8236cdb8
	ctx.lr = 0x8236C888;
	sub_8236CDB8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fb40
	ctx.lr = 0x8236C890;
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

DEFINE_REX_FUNC(sub_8236CF90) {
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
	// bl 0x8236cfe8
	ctx.lr = 0x8236CFB0;
	sub_8236CFE8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8236cfc8
	if (ctx.cr0.eq) goto loc_8236CFC8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8236cfc8
	if (ctx.cr6.eq) goto loc_8236CFC8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8236CFC8;
	sub_825E0378(ctx, base);
loc_8236CFC8:
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

DEFINE_REX_FUNC(sub_8236E258) {
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
	// lwz r5,356(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 356);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8236e308
	if (ctx.cr6.eq) goto loc_8236E308;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,324(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 324);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,328(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 328);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,-13060(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -13060);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
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
	// beq cr6,0x8236e304
	if (ctx.cr6.eq) goto loc_8236E304;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82364a90
	ctx.lr = 0x8236E304;
	sub_82364A90(ctx, base);
loc_8236E304:
	// stw r30,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r30.u32);
loc_8236E308:
	// lbz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 260);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8236e398
	if (ctx.cr0.eq) goto loc_8236E398;
	// stb r30,260(r31)
	REX_STORE_U8(ctx.r31.u32 + 260, ctx.r30.u8);
	// stb r30,261(r31)
	REX_STORE_U8(ctx.r31.u32 + 261, ctx.r30.u8);
	// bl 0x82444358
	ctx.lr = 0x8236E320;
	sub_82444358(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8236e398
	if (ctx.cr0.eq) goto loc_8236E398;
	// bl 0x824443c8
	ctx.lr = 0x8236E32C;
	sub_824443C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8236e398
	if (ctx.cr0.eq) goto loc_8236E398;
	// lwz r11,236(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8236e38c
	if (!ctx.cr0.eq) goto loc_8236E38C;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,664(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 664);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8236E354;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,700(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 700);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8236E36C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// bge cr6,0x8236e38c
	if (!ctx.cr6.lt) goto loc_8236E38C;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r11,261(r31)
	REX_STORE_U8(ctx.r31.u32 + 261, ctx.r11.u8);
	// bl 0x8236f878
	ctx.lr = 0x8236E384;
	sub_8236F878(ctx, base);
	// stw r3,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r3.u32);
	// b 0x8236e398
	goto loc_8236E398;
loc_8236E38C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8236f920
	ctx.lr = 0x8236E394;
	sub_8236F920(ctx, base);
	// stw r3,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r3.u32);
loc_8236E398:
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

DEFINE_REX_FUNC(sub_823790A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823790B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8235f428
	ctx.lr = 0x823790BC;
	sub_8235F428(ctx, base);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,22616
	ctx.r10.s64 = ctx.r10.s64 + 22616;
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// addi r29,r31,244
	ctx.r29.s64 = ctx.r31.s64 + 244;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r30,r31,284
	ctx.r30.s64 = ctx.r31.s64 + 284;
	// stw r11,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
	// stw r11,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r11.u32);
	// stw r11,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r11.u32);
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// stw r11,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// stb r11,232(r31)
	REX_STORE_U8(ctx.r31.u32 + 232, ctx.r11.u8);
	// stb r11,233(r31)
	REX_STORE_U8(ctx.r31.u32 + 233, ctx.r11.u8);
	// stw r11,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r11.u32);
	// stw r11,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// lwz r5,252(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// lwz r3,248(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x82379130
	if (ctx.cr6.eq) goto loc_82379130;
	// subf r11,r5,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r5.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r6,r3
	ctx.r28.u64 = ctx.r6.u64 + ctx.r3.u64;
	// ble 0x8237912c
	if (!ctx.cr0.gt) goto loc_8237912C;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x8237912C;
	sub_827388E8(ctx, base);
loc_8237912C:
	// stw r28,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r28.u32);
loc_82379130:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r5,8(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x82379160
	if (ctx.cr6.eq) goto loc_82379160;
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
	// ble 0x8237915c
	if (!ctx.cr0.gt) goto loc_8237915C;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x8237915C;
	sub_827388E8(ctx, base);
loc_8237915C:
	// stw r29,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r29.u32);
loc_82379160:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8237DCE8) {
	REX_FUNC_PROLOGUE();
	// stw r4,236(r3)
	REX_STORE_U32(ctx.r3.u32 + 236, ctx.r4.u32);
	// stw r5,240(r3)
	REX_STORE_U32(ctx.r3.u32 + 240, ctx.r5.u32);
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// stw r11,252(r3)
	REX_STORE_U32(ctx.r3.u32 + 252, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8237E360) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,516
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 516, ctx.xer);
	// beq cr6,0x8237e374
	if (ctx.cr6.eq) goto loc_8237E374;
	// b 0x8235f668
	sub_8235F668(ctx, base);
	return;
loc_8237E374:
	// lwz r11,256(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 256);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,256(r3)
	REX_STORE_U32(ctx.r3.u32 + 256, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8237E6A0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,23340
	ctx.r3.s64 = ctx.r11.s64 + 23340;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8237EA18) {
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
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8237ebf4
	if (ctx.cr6.lt) goto loc_8237EBF4;
	// beq cr6,0x8237eb78
	if (ctx.cr6.eq) goto loc_8237EB78;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8237eb14
	if (ctx.cr6.lt) goto loc_8237EB14;
	// beq cr6,0x8237eab4
	if (ctx.cr6.eq) goto loc_8237EAB4;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x8237eca8
	if (!ctx.cr6.lt) goto loc_8237ECA8;
	// lfs f0,248(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 248);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f13,248(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 248, temp.u32);
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// lfs f0,2620(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2620);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x8237eaa4
	if (ctx.cr6.lt) goto loc_8237EAA4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,253(r3)
	REX_STORE_U8(ctx.r3.u32 + 253, ctx.r11.u8);
	// bl 0x8237ee08
	ctx.lr = 0x8237EA90;
	sub_8237EE08(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// stfs f13,248(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 248, temp.u32);
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
loc_8237EAA4:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,-8704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8704);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// b 0x8237ebec
	goto loc_8237EBEC;
loc_8237EAB4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8237EAC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8237eca8
	if (!ctx.cr0.eq) goto loc_8237ECA8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lbz r10,236(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 236);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// bne 0x8237eb0c
	if (!ctx.cr0.eq) goto loc_8237EB0C;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8237eb0c
	if (!ctx.cr6.eq) goto loc_8237EB0C;
	// li r11,4
	ctx.r11.s64 = 4;
	// stfs f31,248(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 248, temp.u32);
	// li r3,232
	ctx.r3.s64 = 232;
	// lwz r5,244(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// lwz r4,240(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// bl 0x82240a58
	ctx.lr = 0x8237EB0C;
	sub_82240A58(ctx, base);
loc_8237EB0C:
	// stfs f31,256(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 256, temp.u32);
	// b 0x8237eca8
	goto loc_8237ECA8;
loc_8237EB14:
	// lfs f0,248(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 248);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f13,248(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 248, temp.u32);
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// lfs f0,2620(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2620);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x8237eb64
	if (ctx.cr6.lt) goto loc_8237EB64;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r11,253(r31)
	REX_STORE_U8(ctx.r31.u32 + 253, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8237ee08
	ctx.lr = 0x8237EB50;
	sub_8237EE08(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// stfs f13,248(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 248, temp.u32);
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
loc_8237EB64:
	// fsubs f13,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,-8704(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8704);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x8237ebec
	goto loc_8237EBEC;
loc_8237EB78:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8237EB8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8237eca8
	if (!ctx.cr0.eq) goto loc_8237ECA8;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237ebdc
	if (ctx.cr6.eq) goto loc_8237EBDC;
	// lbz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 252);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8237ebe4
	if (!ctx.cr0.eq) goto loc_8237EBE4;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r5,244(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r4,240(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r10,252(r31)
	REX_STORE_U8(ctx.r31.u32 + 252, ctx.r10.u8);
	// li r3,232
	ctx.r3.s64 = 232;
	// stw r9,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r9.u32);
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,248(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 248, temp.u32);
	// bl 0x82240a58
	ctx.lr = 0x8237EBD8;
	sub_82240A58(ctx, base);
	// b 0x8237ebe4
	goto loc_8237EBE4;
loc_8237EBDC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,252(r31)
	REX_STORE_U8(ctx.r31.u32 + 252, ctx.r11.u8);
loc_8237EBE4:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,-8704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8704);
	ctx.f0.f64 = double(temp.f32);
loc_8237EBEC:
	// stfs f0,256(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 256, temp.u32);
	// b 0x8237eca8
	goto loc_8237ECA8;
loc_8237EBF4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fd60
	ctx.lr = 0x8237EBFC;
	sub_8235FD60(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8237eca8
	if (!ctx.cr6.eq) goto loc_8237ECA8;
	// lwz r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r11,r31,80
	ctx.r11.s64 = ctx.r31.s64 + 80;
	// lwz r9,84(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// li r8,0
	ctx.r8.s64 = 0;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi. r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8237ec2c
	if (!ctx.cr0.eq) goto loc_8237EC2C;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// b 0x8237ec34
	goto loc_8237EC34;
loc_8237EC2C:
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_8237EC34:
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// stb r8,164(r10)
	REX_STORE_U8(ctx.r10.u32 + 164, ctx.r8.u8);
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r9,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r9.u32);
	// lfs f13,6188(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 6188);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x8237ec6c
	if (ctx.cr6.gt) goto loc_8237EC6C;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// b 0x8237ec74
	goto loc_8237EC74;
loc_8237EC6C:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_8237EC74:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stb r8,164(r11)
	REX_STORE_U8(ctx.r11.u32 + 164, ctx.r8.u8);
	// stw r9,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,29864(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 29864);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
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
	ctx.lr = 0x8237ECA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
loc_8237ECA8:
	// addi r3,r31,260
	ctx.r3.s64 = ctx.r31.s64 + 260;
	// bl 0x823edfb8
	ctx.lr = 0x8237ECB0;
	sub_823EDFB8(ctx, base);
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

DEFINE_REX_FUNC(sub_8238C1A0) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238C1CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8238c380
	if (ctx.cr0.eq) goto loc_8238C380;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238C1E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8238c380
	if (!ctx.cr0.eq) goto loc_8238C380;
	// lfs f0,284(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 284);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f13,280(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,280
	ctx.r11.s64 = ctx.r31.s64 + 280;
	// fmadds f12,f0,f31,f13
	ctx.f12.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f13.f64)));
	// addi r11,r10,-4080
	ctx.r11.s64 = ctx.r10.s64 + -4080;
	// lfs f9,268(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 268);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fctid f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fnmsubs f1,f0,f13,f12
	ctx.f1.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
	// stfs f1,280(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 280, temp.u32);
	// bl 0x822ea1a8
	ctx.lr = 0x8238C230;
	sub_822EA1A8(ctx, base);
	// fmuls f2,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f2,272(r31)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r31.u32 + 272, temp.u32);
	// addi r4,r31,240
	ctx.r4.s64 = ctx.r31.s64 + 240;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,264(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 264);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8238c608
	ctx.lr = 0x8238C248;
	sub_8238C608(ctx, base);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f12,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 252);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f13,248(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 248);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r31,248
	ctx.r11.s64 = ctx.r31.s64 + 248;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
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
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
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
	// bl 0x8238c8a0
	ctx.lr = 0x8238C2F8;
	sub_8238C8A0(ctx, base);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,248(r31)
	REX_STORE_U64(ctx.r31.u32 + 248, ctx.r11.u64);
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8238c380
	if (ctx.cr6.eq) goto loc_8238C380;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r9,r9,2688
	ctx.r9.s64 = ctx.r9.s64 + 2688;
	// stw r8,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r8.u32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// ld r11,3456(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stw r9,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r10,3128(r10)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r10.u32 + 3128);
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// std r10,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r10.u64);
	// bl 0x8238c6e0
	ctx.lr = 0x8238C344;
	sub_8238C6E0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238c360
	if (ctx.cr6.eq) goto loc_8238C360;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,288(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// bl 0x823aff18
	ctx.lr = 0x8238C360;
	sub_823AFF18(ctx, base);
loc_8238C360:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238C374;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,288(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// bl 0x823af140
	ctx.lr = 0x8238C380;
	sub_823AF140(ctx, base);
loc_8238C380:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

DEFINE_REX_FUNC(sub_8239F170) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8239F178;
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
	// li r4,968
	ctx.r4.s64 = 968;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8239F1A0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8239f1bc
	if (ctx.cr0.eq) goto loc_8239F1BC;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8239f1c8
	ctx.lr = 0x8239F1B8;
	sub_8239F1C8(ctx, base);
	// b 0x8239f1c0
	goto loc_8239F1C0;
loc_8239F1BC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8239F1C0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823A1150) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823A1158;
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
	// li r4,372
	ctx.r4.s64 = 372;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823A1180;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823a119c
	if (ctx.cr0.eq) goto loc_823A119C;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x823a11a8
	ctx.lr = 0x823A1198;
	sub_823A11A8(ctx, base);
	// b 0x823a11a0
	goto loc_823A11A0;
loc_823A119C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823A11A0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823A3490) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823A3498;
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
	// li r4,900
	ctx.r4.s64 = 900;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823A34C0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823a34dc
	if (ctx.cr0.eq) goto loc_823A34DC;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x823a34e8
	ctx.lr = 0x823A34D8;
	sub_823A34E8(ctx, base);
	// b 0x823a34e0
	goto loc_823A34E0;
loc_823A34DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823A34E0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823A51E0) {
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823a5270
	if (!ctx.cr6.eq) goto loc_823A5270;
	// li r11,1
	ctx.r11.s64 = 1;
loc_823A5270:
	// stw r11,244(r3)
	REX_STORE_U32(ctx.r3.u32 + 244, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823AD4E8) {
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
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,522
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 522, ctx.xer);
	// beq cr6,0x823ad51c
	if (ctx.cr6.eq) goto loc_823AD51C;
	// bl 0x8235f668
	ctx.lr = 0x823AD518;
	sub_8235F668(ctx, base);
	// b 0x823ad560
	goto loc_823AD560;
loc_823AD51C:
	// bl 0x824281d8
	ctx.lr = 0x823AD520;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823ad548
	if (ctx.cr0.eq) goto loc_823AD548;
	// bl 0x8242a5e0
	ctx.lr = 0x823AD52C;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823ad53c
	if (!ctx.cr0.eq) goto loc_823AD53C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823ad540
	goto loc_823AD540;
loc_823AD53C:
	// bl 0x8242aa28
	ctx.lr = 0x823AD540;
	sub_8242AA28(ctx, base);
loc_823AD540:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823ad560
	if (ctx.cr0.eq) goto loc_823AD560;
loc_823AD548:
	// lbz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 20);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r11,388(r30)
	REX_STORE_U8(ctx.r30.u32 + 388, ctx.r11.u8);
	// beq 0x823ad560
	if (ctx.cr0.eq) goto loc_823AD560;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,389(r30)
	REX_STORE_U8(ctx.r30.u32 + 389, ctx.r11.u8);
loc_823AD560:
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

DEFINE_REX_FUNC(sub_823AFA38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x823AFA40;
	__savegprlr_21(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r22,r4
	ctx.r22.u64 = ctx.r4.u64;
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mr r21,r8
	ctx.r21.u64 = ctx.r8.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x823afc18
	if (!ctx.cr6.lt) goto loc_823AFC18;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// vspltisw128 v53,-1
	simde_mm_store_si128((simde__m128i*)ctx.v53.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,23536
	ctx.r28.s64 = ctx.r10.s64 + 23536;
	// lis r27,-32111
	ctx.r27.s64 = -2104426496;
	// vslw128 v63,v53,v53
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v53.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v53.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// li r31,0
	ctx.r31.s64 = 0;
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// ld r9,3456(r27)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r27.u32 + 3456);
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stw r31,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r31.u32);
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// stw r31,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r31.u32);
	// lwz r29,20(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r25,24(r11)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r9,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r9.u64);
	// cmplw cr6,r29,r25
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x823afc18
	if (ctx.cr6.eq) goto loc_823AFC18;
loc_823AFAC4:
	// lwz r30,0(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// rlwinm. r10,r11,0,0,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x823afbe0
	if (!ctx.cr0.eq) goto loc_823AFBE0;
	// clrlwi r10,r21,24
	ctx.r10.u64 = ctx.r21.u32 & 0xFF;
	// and. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823afbe0
	if (ctx.cr0.eq) goto loc_823AFBE0;
	// vslw128 v63,v53,v53
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v53.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v53.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lwz r6,8(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// ld r9,3456(r27)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r27.u32 + 3456);
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lwz r11,4(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// stw r31,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// beq cr6,0x823afb58
	if (ctx.cr6.eq) goto loc_823AFB58;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x823afb44
	if (ctx.cr6.eq) goto loc_823AFB44;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x823afb30
	if (ctx.cr6.eq) goto loc_823AFB30;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x823afb68
	goto loc_823AFB68;
loc_823AFB30:
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b1e78
	ctx.lr = 0x823AFB40;
	sub_823B1E78(ctx, base);
	// b 0x823afb68
	goto loc_823AFB68;
loc_823AFB44:
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b1d68
	ctx.lr = 0x823AFB54;
	sub_823B1D68(ctx, base);
	// b 0x823afb68
	goto loc_823AFB68;
loc_823AFB58:
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b1b18
	ctx.lr = 0x823AFB68;
	sub_823B1B18(ctx, base);
loc_823AFB68:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823afb80
	if (ctx.cr0.eq) goto loc_823AFB80;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
loc_823AFB80:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823afbe0
	if (ctx.cr6.eq) goto loc_823AFBE0;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x823afbb0
	if (ctx.cr6.eq) goto loc_823AFBB0;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823afbd8
	if (ctx.cr0.eq) goto loc_823AFBD8;
loc_823AFBB0:
	// li r11,6
	ctx.r11.s64 = 6;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-8
	ctx.r8.s64 = ctx.r10.s64 + -8;
	// addi r10,r9,-8
	ctx.r10.s64 = ctx.r9.s64 + -8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_823AFBC8:
	// ldu r11,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdu r11,8(r8)
	ea = 8 + ctx.r8.u32;
	REX_STORE_U64(ea, ctx.r11.u64);
	ctx.r8.u32 = ea;
	// bdnz 0x823afbc8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823AFBC8;
	// lwz r26,128(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
loc_823AFBD8:
	// cmpwi cr6,r26,1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 1, ctx.xer);
	// beq cr6,0x823afbec
	if (ctx.cr6.eq) goto loc_823AFBEC;
loc_823AFBE0:
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplw cr6,r29,r25
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x823afac4
	if (!ctx.cr6.eq) goto loc_823AFAC4;
loc_823AFBEC:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x823afc18
	if (ctx.cr6.eq) goto loc_823AFC18;
	// li r11,6
	ctx.r11.s64 = 6;
	// addi r10,r1,120
	ctx.r10.s64 = ctx.r1.s64 + 120;
	// addi r9,r22,-8
	ctx.r9.s64 = ctx.r22.s64 + -8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_823AFC04:
	// ldu r11,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdu r11,8(r9)
	ea = 8 + ctx.r9.u32;
	REX_STORE_U64(ea, ctx.r11.u64);
	ctx.r9.u32 = ea;
	// bdnz 0x823afc04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823AFC04;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823afc1c
	goto loc_823AFC1C;
loc_823AFC18:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823AFC1C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823B9C70) {
	REX_FUNC_PROLOGUE();
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r9,25(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 25);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x823b9c90
	if (!ctx.cr0.eq) goto loc_823B9C90;
	// stw r4,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
loc_823B9C90:
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
	// bne cr6,0x823b9cb0
	if (!ctx.cr6.eq) goto loc_823B9CB0;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// b 0x823b9ccc
	goto loc_823B9CCC;
loc_823B9CB0:
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x823b9cc8
	if (!ctx.cr6.eq) goto loc_823B9CC8;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// b 0x823b9ccc
	goto loc_823B9CCC;
loc_823B9CC8:
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
loc_823B9CCC:
	// stw r4,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823BBA60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x823BBA68;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af18
	ctx.lr = 0x823BBA70;
	__savefpr_24(ctx, base);
	// stwu r1,-1344(r1)
	ea = -1344 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,140(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lwz r8,44(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r26,r11,22072
	ctx.r26.s64 = ctx.r11.s64 + 22072;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,148(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// li r4,12
	ctx.r4.s64 = 12;
	// rlwinm r25,r11,1,30,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// lfs f31,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f31.f64 = double(temp.f32);
	// lbz r9,38(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 38);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// rotlwi r11,r9,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// mullw r11,r11,r8
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r23,r11,2
	ctx.r23.s64 = ctx.r11.s64 + 2;
	// bl 0x825e02a0
	ctx.lr = 0x823BBAC0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823bbacc
	if (ctx.cr0.eq) goto loc_823BBACC;
	// stw r3,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
loc_823BBACC:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823bbad8
	if (ctx.cr0.eq) goto loc_823BBAD8;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_823BBAD8:
	// lwz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// li r20,0
	ctx.r20.s64 = 0;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// stw r3,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// stw r20,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r20.u32);
	// mr r27,r20
	ctx.r27.u64 = ctx.r20.u64;
	// lbz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 40);
	// addic. r29,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r29.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x823bc6c8
	if (ctx.cr0.lt) goto loc_823BC6C8;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r22,32
	ctx.r22.s64 = 32;
	// li r24,36
	ctx.r24.s64 = 36;
	// addi r21,r11,-31476
	ctx.r21.s64 = ctx.r11.s64 + -31476;
loc_823BBB0C:
	// lwz r11,160(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 160);
	// lwz r9,204(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// lwz r10,144(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 144);
	// lbzx r11,r11,r29
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r10,r11,r23
	ctx.r10.u64 = ctx.r11.u64 + ctx.r23.u64;
	// lwzx r31,r9,r11
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm. r9,r11,0,29,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x6;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x823bbd20
	if (!ctx.cr0.eq) goto loc_823BBD20;
	// lbz r10,3(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// bne cr6,0x823bbb4c
	if (!ctx.cr6.eq) goto loc_823BBB4C;
	// lbz r28,1(r8)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r8.u32 + 1);
loc_823BBB4C:
	// andi. r10,r11,40
	ctx.r10.u64 = ctx.r11.u64 & 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x823bbca0
	if (!ctx.cr0.eq) goto loc_823BBCA0;
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823bbb7c
	if (ctx.cr0.eq) goto loc_823BBB7C;
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,r31,r22
	REX_STORE_U32(ctx.r31.u32 + ctx.r22.u32, ctx.f0.u32);
	// stfiwx f13,r31,r24
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, ctx.f13.u32);
	// b 0x823bbc18
	goto loc_823BBC18;
loc_823BBB7C:
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f0,60(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// lfs f12,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f0,280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
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
	// stfs f12,252(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f12,248(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f12,244(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f12,240(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,r31,r22
	REX_STORE_U32(ctx.r31.u32 + ctx.r22.u32, ctx.f0.u32);
	// lfs f0,64(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 64);
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,r31,r24
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, ctx.f0.u32);
loc_823BBC18:
	// lhz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// bl 0x82301230
	ctx.lr = 0x823BBC20;
	sub_82301230(ctx, base);
	// lbz r10,3(r8)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r8.u32 + 3);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// lhz r11,58(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 58);
	// stb r25,40(r31)
	REX_STORE_U8(ctx.r31.u32 + 40, ctx.r25.u8);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r9,2(r8)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r8.u32 + 2);
	// rlwinm. r10,r9,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// beq 0x823bbc4c
	if (ctx.cr0.eq) goto loc_823BBC4C;
	// xori r10,r25,2
	ctx.r10.u64 = ctx.r25.u64 ^ 2;
	// stb r10,40(r31)
	REX_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
loc_823BBC4C:
	// lbz r10,2(r8)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r8.u32 + 2);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x823bbc64
	if (ctx.cr0.eq) goto loc_823BBC64;
	// lbz r10,40(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 40);
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// stb r10,40(r31)
	REX_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
loc_823BBC64:
	// lwz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// sth r11,84(r10)
	REX_STORE_U16(ctx.r10.u32 + 84, ctx.r11.u16);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stfs f0,56(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 56, temp.u32);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stfs f31,96(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lbz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 56);
	// lwz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stw r11,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r11.u32);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lfs f0,32(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lfs f0,36(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
loc_823BBCA0:
	// lwz r11,216(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823bbd00
	if (ctx.cr6.eq) goto loc_823BBD00;
	// lwz r11,220(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823bbd00
	if (ctx.cr6.eq) goto loc_823BBD00;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// bl 0x825e02a0
	ctx.lr = 0x823BBCCC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823bbcec
	if (ctx.cr0.eq) goto loc_823BBCEC;
	// addi r11,r31,24
	ctx.r11.s64 = ctx.r31.s64 + 24;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r10,r28,24
	ctx.r10.u64 = ctx.r28.u32 & 0xFF;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// sth r10,4(r3)
	REX_STORE_U16(ctx.r3.u32 + 4, ctx.r10.u16);
	// b 0x823bbcf0
	goto loc_823BBCF0;
loc_823BBCEC:
	// stw r20,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r20.u32);
loc_823BBCF0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823bce68
	ctx.lr = 0x823BBCFC;
	sub_823BCE68(ctx, base);
	// b 0x823bbd20
	goto loc_823BBD20;
loc_823BBD00:
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,28(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// clrlwi r4,r28,24
	ctx.r4.u64 = ctx.r28.u32 & 0xFF;
	// lbz r7,40(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 40);
	// lwz r6,36(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r5,32(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x823be020
	ctx.lr = 0x823BBD20;
	sub_823BE020(ctx, base);
loc_823BBD20:
	// lfs f0,22832(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 22832);
	ctx.f0.f64 = double(temp.f32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// fsubs f31,f31,f0
	ctx.f31.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// bge 0x823bbb0c
	if (!ctx.cr0.lt) goto loc_823BBB0C;
	// lwz r11,168(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823bc6c4
	if (ctx.cr6.eq) goto loc_823BC6C4;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x823BBD48;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x823bbd74
	if (ctx.cr0.eq) goto loc_823BBD74;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b88
	ctx.lr = 0x823BBD58;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r5,r27,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x823BBD6C;
	sub_825F8BF8(ctx, base);
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// b 0x823bbd78
	goto loc_823BBD78;
loc_823BBD74:
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
loc_823BBD78:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r9,r1,736
	ctx.r9.s64 = ctx.r1.s64 + 736;
	// addi r8,r1,752
	ctx.r8.s64 = ctx.r1.s64 + 752;
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
	// addi r7,r1,768
	ctx.r7.s64 = ctx.r1.s64 + 768;
	// addi r6,r1,784
	ctx.r6.s64 = ctx.r1.s64 + 784;
	// lwz r10,-12872(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12872);
	// addi r11,r11,14376
	ctx.r11.s64 = ctx.r11.s64 + 14376;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// lfs f31,-2140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2140);
	ctx.f31.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823bbdd8
	if (ctx.cr6.eq) goto loc_823BBDD8;
	// lfs f27,664(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 664);
	ctx.f27.f64 = double(temp.f32);
	// b 0x823bbddc
	goto loc_823BBDDC;
loc_823BBDD8:
	// fmr f27,f31
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f31.f64;
loc_823BBDDC:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f28,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// vspltw128 v57,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// fdivs f13,f31,f27
	ctx.f13.f64 = double(float(ctx.f31.f64 / ctx.f27.f64));
	// vspltw128 v56,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lwz r11,-15432(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -15432);
	// vspltw128 v54,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// lwz r10,-15444(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -15444);
	// vmulfp128 v9,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vmulfp128 v11,v56,v58
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vmulfp128 v7,v55,v58
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v10,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vmulfp128 v5,v54,v58
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// vspltw128 v8,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// vspltw128 v6,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// vmaddfp v10,v10,v0,v9
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// fcfid f12,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(ctx.f12.s64);
	// vmaddfp v11,v12,v0,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v9,v8,v0,v7
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// frsp f11,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(ctx.f0.f64));
	// vmaddfp v0,v6,v0,v5
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// vspltw128 v4,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// vspltw128 v3,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// lfs f0,0(r21)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// vspltw128 v2,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// addi r10,r1,736
	ctx.r10.s64 = ctx.r1.s64 + 736;
	// vspltw128 v1,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// addi r9,r1,752
	ctx.r9.s64 = ctx.r1.s64 + 752;
	// vspltw128 v31,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// addi r8,r1,768
	ctx.r8.s64 = ctx.r1.s64 + 768;
	// vspltw128 v30,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// addi r7,r1,784
	ctx.r7.s64 = ctx.r1.s64 + 784;
	// vspltw128 v29,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// addi r4,r1,736
	ctx.r4.s64 = ctx.r1.s64 + 736;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// vspltw128 v12,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// fmuls f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// vmaddfp v10,v3,v13,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v11,v4,v13,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// li r5,64
	ctx.r5.s64 = 64;
	// vmaddfp v9,v2,v13,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// vmaddfp v13,v1,v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f10,52(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,412(r29)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r29.u32 + 412, temp.u32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f12,f11,f28
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f28.f64));
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v31,v0,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v10,v30,v0,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v11,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v9,v29,v0,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v0,v12,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v10,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273a030
	ctx.lr = 0x823BBF04;
	sub_8273A030(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r5,216(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r6,r11,-10736
	ctx.r6.s64 = ctx.r11.s64 + -10736;
	// lwz r24,164(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x823bd310
	ctx.lr = 0x823BBF34;
	sub_823BD310(ctx, base);
	// lwz r10,216(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// mr r21,r24
	ctx.r21.u64 = ctx.r24.u64;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lhz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// lwz r25,424(r29)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + 424);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f29,f0
	ctx.f29.f64 = double(float(ctx.f0.f64));
	// fcfid f0,f13
	ctx.f0.f64 = double(ctx.f13.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// beq cr6,0x823bc688
	if (ctx.cr6.eq) goto loc_823BC688;
	// stfs f31,620(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 620, temp.u32);
	// addi r31,r25,80
	ctx.r31.s64 = ctx.r25.s64 + 80;
	// stfs f31,348(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// fdivs f25,f31,f29
	ctx.f25.f64 = double(float(ctx.f31.f64 / ctx.f29.f64));
	// stfs f31,204(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// fdivs f26,f31,f0
	ctx.f26.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
loc_823BBF98:
	// lwz r10,4(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// lwz r11,220(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// lwz r28,8(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r6,0(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lhz r4,4(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 4);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lwz r7,0(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// mulli r10,r10,12
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(12));
	// lbz r20,16(r6)
	ctx.r20.u64 = REX_LOAD_U8(ctx.r6.u32 + 16);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x823bd038
	ctx.lr = 0x823BBFC8;
	sub_823BD038(ctx, base);
	// lha r4,33(r3)
	ctx.r4.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 33));
	// lha r3,35(r3)
	ctx.r3.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 35));
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lha r23,6(r8)
	ctx.r23.s64 = int16_t(REX_LOAD_U16(ctx.r8.u32 + 6));
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lha r22,10(r8)
	ctx.r22.s64 = int16_t(REX_LOAD_U16(ctx.r8.u32 + 10));
	// lfs f31,40(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 40);
	ctx.f31.f64 = double(temp.f32);
	// lha r27,4(r8)
	ctx.r27.s64 = int16_t(REX_LOAD_U16(ctx.r8.u32 + 4));
	// lfs f30,44(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 44);
	ctx.f30.f64 = double(temp.f32);
	// lha r26,8(r8)
	ctx.r26.s64 = int16_t(REX_LOAD_U16(ctx.r8.u32 + 8));
	// rlwinm. r29,r20,0,30,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// lha r11,0(r8)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r8.u32 + 0));
	// subf r9,r23,r22
	ctx.r9.u64 = ctx.r22.u64 - ctx.r23.u64;
	// lha r5,2(r8)
	ctx.r5.s64 = int16_t(REX_LOAD_U16(ctx.r8.u32 + 2));
	// subf r8,r27,r26
	ctx.r8.u64 = ctx.r26.u64 - ctx.r27.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// beq 0x823bc018
	if (ctx.cr0.eq) goto loc_823BC018;
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// b 0x823bc01c
	goto loc_823BC01C;
loc_823BC018:
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
loc_823BC01C:
	// clrlwi. r20,r3,31
	ctx.r20.u64 = ctx.r3.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq 0x823bc030
	if (ctx.cr0.eq) goto loc_823BC030;
	// subf r11,r4,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r4.u64;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// b 0x823bc034
	goto loc_823BC034;
loc_823BC030:
	// subf r11,r5,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r5.u64;
loc_823BC034:
	// extsw r5,r11
	ctx.r5.s64 = ctx.r11.s32;
	// lwz r4,12(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// lwa r6,8(r6)
	ctx.r6.s64 = int32_t(REX_LOAD_U32(ctx.r6.u32 + 8));
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// std r5,688(r1)
	REX_STORE_U64(ctx.r1.u32 + 688, ctx.r5.u64);
	// neg r5,r4
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r4.u64);
	// std r6,680(r1)
	REX_STORE_U64(ctx.r1.u32 + 680, ctx.r6.u64);
	// lfd f10,680(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 680);
	// extsw r5,r5
	ctx.r5.s64 = ctx.r5.s32;
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// std r5,664(r1)
	REX_STORE_U64(ctx.r1.u32 + 664, ctx.r5.u64);
	// addi r9,r1,592
	ctx.r9.s64 = ctx.r1.s64 + 592;
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// stfs f10,596(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 596, temp.u32);
	// stfs f10,592(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 592, temp.u32);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// stfs f10,604(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 604, temp.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f10,600(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 600, temp.u32);
	// std r10,648(r1)
	REX_STORE_U64(ctx.r1.u32 + 648, ctx.r10.u64);
	// addi r10,r1,368
	ctx.r10.s64 = ctx.r1.s64 + 368;
	// std r11,672(r1)
	REX_STORE_U64(ctx.r1.u32 + 672, ctx.r11.u64);
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// lfs f0,52(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 52);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,496
	ctx.r11.s64 = ctx.r1.s64 + 496;
	// std r8,640(r1)
	REX_STORE_U64(ctx.r1.u32 + 640, ctx.r8.u64);
	// lfs f13,96(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f24,f0,f13
	ctx.f24.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfd f13,688(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 688);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r8,r1,976
	ctx.r8.s64 = ctx.r1.s64 + 976;
	// lfd f11,664(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 664);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,648(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 648);
	// addi r6,r1,848
	ctx.r6.s64 = ctx.r1.s64 + 848;
	// lfd f9,672(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 672);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// lfd f12,640(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 640);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// addi r5,r1,1104
	ctx.r5.s64 = ctx.r1.s64 + 1104;
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// fmuls f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// stfs f13,508(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 508, temp.u32);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stfs f11,380(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// stfs f11,376(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// stfs f11,372(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f11,368(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f13,504(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// stfs f13,500(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// stfs f13,496(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,320
	ctx.r11.s64 = ctx.r1.s64 + 320;
	// stvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,412(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// fmuls f11,f9,f30
	ctx.f11.f64 = double(float(ctx.f9.f64 * ctx.f30.f64));
	// stfs f0,408(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// stfs f0,404(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f0,400(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// stfs f11,572(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// stfs f11,568(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// stfs f11,564(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 564, temp.u32);
	// stfs f11,560(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 560, temp.u32);
	// stfs f0,444(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 444, temp.u32);
	// stfs f0,440(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 440, temp.u32);
	// stfs f0,436(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// stfs f0,432(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// stfs f11,300(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f11,296(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f11,292(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,800
	ctx.r3.s64 = ctx.r1.s64 + 800;
	// lfs f0,56(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// fmuls f12,f12,f31
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// stfs f0,328(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// addi r6,r1,528
	ctx.r6.s64 = ctx.r1.s64 + 528;
	// stfs f0,324(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stw r3,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r3.u32);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// addi r10,r1,464
	ctx.r10.s64 = ctx.r1.s64 + 464;
	// stfs f11,288(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// addi r17,r1,352
	ctx.r17.s64 = ctx.r1.s64 + 352;
	// stfs f12,540(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// addi r5,r1,1008
	ctx.r5.s64 = ctx.r1.s64 + 1008;
	// stfs f12,536(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// addi r7,r1,288
	ctx.r7.s64 = ctx.r1.s64 + 288;
	// stfs f12,532(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// addi r16,r1,944
	ctx.r16.s64 = ctx.r1.s64 + 944;
	// stfs f12,528(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// addi r15,r1,1040
	ctx.r15.s64 = ctx.r1.s64 + 1040;
	// stfs f13,476(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 476, temp.u32);
	// addi r14,r1,816
	ctx.r14.s64 = ctx.r1.s64 + 816;
	// stfs f13,472(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// addi r9,r1,560
	ctx.r9.s64 = ctx.r1.s64 + 560;
	// stfs f13,468(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// addi r19,r1,912
	ctx.r19.s64 = ctx.r1.s64 + 912;
	// stfs f13,464(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// addi r8,r1,432
	ctx.r8.s64 = ctx.r1.s64 + 432;
	// stfs f12,364(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// addi r18,r1,1072
	ctx.r18.s64 = ctx.r1.s64 + 1072;
	// stfs f12,360(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// addi r3,r1,704
	ctx.r3.s64 = ctx.r1.s64 + 704;
	// stfs f12,356(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// stfs f12,352(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,976(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 976);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,172(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,944(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 944);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,1040(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1040);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,848(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 848);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,816(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 816);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,1104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1104);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,800(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 800);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stvx128 v61,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,912(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 912);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1072(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1072);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f0,1008(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1008);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f9,108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// bl 0x8221ada0
	ctx.lr = 0x823BC294;
	sub_8221ADA0(ctx, base);
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// addi r4,r1,704
	ctx.r4.s64 = ctx.r1.s64 + 704;
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// bl 0x823bcf40
	ctx.lr = 0x823BC2A4;
	sub_823BCF40(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// addi r3,r1,1120
	ctx.r3.s64 = ctx.r1.s64 + 1120;
	// bl 0x8255f918
	ctx.lr = 0x823BC2B4;
	sub_8255F918(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,704
	ctx.r4.s64 = ctx.r1.s64 + 704;
	// std r11,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r11.u64);
	// addi r3,r1,880
	ctx.r3.s64 = ctx.r1.s64 + 880;
	// bl 0x823bcf40
	ctx.lr = 0x823BC2CC;
	sub_823BCF40(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8255f918
	ctx.lr = 0x823BC2DC;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,704
	ctx.r4.s64 = ctx.r1.s64 + 704;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x823bcf40
	ctx.lr = 0x823BC2F8;
	sub_823BCF40(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x8255f918
	ctx.lr = 0x823BC308;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,704
	ctx.r4.s64 = ctx.r1.s64 + 704;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// bl 0x823bcf40
	ctx.lr = 0x823BC324;
	sub_823BCF40(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8255f918
	ctx.lr = 0x823BC334;
	sub_8255F918(ctx, base);
	// addi r11,r1,384
	ctx.r11.s64 = ctx.r1.s64 + 384;
	// lfs f13,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,416
	ctx.r8.s64 = ctx.r1.s64 + 416;
	// stfs f13,396(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// addi r10,r1,832
	ctx.r10.s64 = ctx.r1.s64 + 832;
	// stfs f13,392(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// addi r7,r1,864
	ctx.r7.s64 = ctx.r1.s64 + 864;
	// stfs f13,388(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// ld r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// stfs f13,384(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// addi r6,r31,-40
	ctx.r6.s64 = ctx.r31.s64 + -40;
	// lfs f0,140(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,608
	ctx.r6.s64 = ctx.r1.s64 + 608;
	// stfs f0,428(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 428, temp.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// stfs f0,424(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 424, temp.u32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// stfs f0,416(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// std r9,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// stfs f0,420(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// lfs f12,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,460(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 460, temp.u32);
	// stfs f12,456(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// stfs f12,452(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stfs f12,448(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f9.f64 = double(temp.f32);
	// stfs f11,316(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f11,312(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f11,308(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// stfs f11,304(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// stfs f10,492(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// stfs f10,488(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,512
	ctx.r11.s64 = ctx.r1.s64 + 512;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,832(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 832);
	ctx.f13.f64 = double(temp.f32);
	// stfs f10,484(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// lfs f0,108(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,864(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 864);
	ctx.f12.f64 = double(temp.f32);
	// stfs f10,480(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// stfs f9,556(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 556, temp.u32);
	// stfs f9,552(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 552, temp.u32);
	// stfs f9,548(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 548, temp.u32);
	// stfs f9,544(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 544, temp.u32);
	// stfs f13,608(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 608, temp.u32);
	// stfs f12,612(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 612, temp.u32);
	// stfs f0,524(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
	// stfs f0,520(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// addi r8,r1,480
	ctx.r8.s64 = ctx.r1.s64 + 480;
	// stfs f0,512(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// addi r17,r1,304
	ctx.r17.s64 = ctx.r1.s64 + 304;
	// stfs f0,516(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// addi r7,r1,896
	ctx.r7.s64 = ctx.r1.s64 + 896;
	// addi r3,r1,928
	ctx.r3.s64 = ctx.r1.s64 + 928;
	// stfs f24,616(r1)
	temp.f32 = float(ctx.f24.f64);
	REX_STORE_U32(ctx.r1.u32 + 616, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,544
	ctx.r10.s64 = ctx.r1.s64 + 544;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,992
	ctx.r8.s64 = ctx.r1.s64 + 992;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,1024
	ctx.r7.s64 = ctx.r1.s64 + 1024;
	// lvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r19,r1,576
	ctx.r19.s64 = ctx.r1.s64 + 576;
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r18,r1,960
	ctx.r18.s64 = ctx.r1.s64 + 960;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,1056
	ctx.r3.s64 = ctx.r1.s64 + 1056;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f31,f29
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f29.f64));
	// lfs f13,104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,584(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 584, temp.u32);
	// stfs f13,588(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 588, temp.u32);
	// stfs f13,576(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 576, temp.u32);
	// stfs f13,580(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 580, temp.u32);
	// stfs f24,344(r1)
	temp.f32 = float(ctx.f24.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f24,200(r1)
	temp.f32 = float(ctx.f24.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f24,184(r1)
	temp.f32 = float(ctx.f24.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,12(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stvx128 v63,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,8(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lvx128 v63,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,4(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,928(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 928);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,12(r25)
	REX_STORE_U32(ctx.r25.u32 + 12, ctx.r11.u32);
	// stfs f12,196(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stw r8,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r8.u32);
	// lfs f12,1024(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1024);
	ctx.f12.f64 = double(temp.f32);
	// stw r10,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r10.u32);
	// stfs f12,192(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lwz r3,4(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// lfs f13,896(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 896);
	ctx.f13.f64 = double(temp.f32);
	// stw r7,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r7.u32);
	// stfs f13,340(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// lfs f13,992(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 992);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,960(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 960);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,336(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// lwz r19,8(r9)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// stfs f11,180(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stw r19,-32(r31)
	REX_STORE_U32(ctx.r31.u32 + -32, ctx.r19.u32);
	// lfs f11,1056(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1056);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,12(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r10,8(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// stfs f11,176(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lwz r8,12(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// fmuls f13,f30,f29
	ctx.f13.f64 = double(float(ctx.f30.f64 * ctx.f29.f64));
	// lwz r19,0(r9)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,0(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r6,4(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r5,0(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r18,12(r4)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// stw r19,-40(r31)
	REX_STORE_U32(ctx.r31.u32 + -40, ctx.r19.u32);
	// lwz r4,8(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,-28(r31)
	REX_STORE_U32(ctx.r31.u32 + -28, ctx.r11.u32);
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// stw r9,-36(r31)
	REX_STORE_U32(ctx.r31.u32 + -36, ctx.r9.u32);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r8,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// stw r7,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r7.u32);
	// stw r6,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// stw r4,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r4.u32);
	// fmuls f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f27.f64));
	// stw r18,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r18.u32);
	// fmuls f13,f13,f27
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f27.f64));
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// fdivs f0,f28,f0
	ctx.f0.f64 = double(float(ctx.f28.f64 / ctx.f0.f64));
	// fdivs f13,f28,f13
	ctx.f13.f64 = double(float(ctx.f28.f64 / ctx.f13.f64));
	// bne cr6,0x823bc568
	if (!ctx.cr6.eq) goto loc_823BC568;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_823BC568:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// std r11,696(r1)
	REX_STORE_U64(ctx.r1.u32 + 696, ctx.r11.u64);
	// lfd f12,696(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 696);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f11,f12,f25,f0
	ctx.f11.f64 = double(float(std::fma(ctx.f12.f64, ctx.f25.f64, ctx.f0.f64)));
	// bne cr6,0x823bc58c
	if (!ctx.cr6.eq) goto loc_823BC58C;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
loc_823BC58C:
	// extsw r11,r27
	ctx.r11.s64 = ctx.r27.s32;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// std r11,656(r1)
	REX_STORE_U64(ctx.r1.u32 + 656, ctx.r11.u64);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// lfd f12,656(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 656);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f12,f12,f25,f0
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f25.f64, ctx.f0.f64)));
	// bne cr6,0x823bc5b4
	if (!ctx.cr6.eq) goto loc_823BC5B4;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_823BC5B4:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// std r11,624(r1)
	REX_STORE_U64(ctx.r1.u32 + 624, ctx.r11.u64);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// lfd f0,624(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 624);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmadds f0,f0,f26,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f26.f64, ctx.f13.f64)));
	// bne cr6,0x823bc5dc
	if (!ctx.cr6.eq) goto loc_823BC5DC;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_823BC5DC:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f0,260(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// addi r25,r25,160
	ctx.r25.s64 = ctx.r25.s64 + 160;
	// std r11,632(r1)
	REX_STORE_U64(ctx.r1.u32 + 632, ctx.r11.u64);
	// lfd f10,632(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 632);
	// stfs f11,256(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f12,208(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,256(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 256);
	// std r11,-48(r31)
	REX_STORE_U64(ctx.r31.u32 + -48, ctx.r11.u64);
	// fcfid f0,f10
	ctx.f0.f64 = double(ctx.f10.s64);
	// ld r11,208(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 208);
	// std r11,72(r31)
	REX_STORE_U64(ctx.r31.u32 + 72, ctx.r11.u64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmadds f0,f0,f26,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f26.f64, ctx.f13.f64)));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,-8(r31)
	REX_STORE_U64(ctx.r31.u32 + -8, ctx.r10.u64);
	// std r11,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r11.u64);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r11,-12(r31)
	REX_STORE_U32(ctx.r31.u32 + -12, ctx.r11.u32);
	// stw r11,-52(r31)
	REX_STORE_U32(ctx.r31.u32 + -52, ctx.r11.u32);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// addi r31,r31,160
	ctx.r31.s64 = ctx.r31.s64 + 160;
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823bc668
	if (ctx.cr6.eq) goto loc_823BC668;
	// bl 0x825e0378
	ctx.lr = 0x823BC668;
	sub_825E0378(ctx, base);
loc_823BC668:
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r21,4(r21)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// cmplw cr6,r21,r11
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823bbf98
	if (!ctx.cr6.eq) goto loc_823BBF98;
	// lwz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_823BC688:
	// stw r24,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r24.u32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stw r24,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r24.u32);
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x823bc6b0
	if (ctx.cr6.eq) goto loc_823BC6B0;
loc_823BC69C:
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825e0378
	ctx.lr = 0x823BC6A4;
	sub_825E0378(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r24
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x823bc69c
	if (!ctx.cr6.eq) goto loc_823BC69C;
loc_823BC6B0:
	// li r5,1
	ctx.r5.s64 = 1;
	// lbz r4,56(r30)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r30.u32 + 56);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82459d08
	ctx.lr = 0x823BC6C0;
	sub_82459D08(ctx, base);
	// b 0x823bc6c8
	goto loc_823BC6C8;
loc_823BC6C4:
	// lwz r24,164(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
loc_823BC6C8:
	// lwz r3,0(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// stw r24,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r24.u32);
	// stw r24,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r24.u32);
	// cmplw cr6,r3,r24
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x823bc6f0
	if (ctx.cr6.eq) goto loc_823BC6F0;
loc_823BC6DC:
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825e0378
	ctx.lr = 0x823BC6E4;
	sub_825E0378(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r24
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x823bc6dc
	if (!ctx.cr6.eq) goto loc_823BC6DC;
loc_823BC6F0:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x825e0378
	ctx.lr = 0x823BC6F8;
	sub_825E0378(ctx, base);
	// addi r1,r1,1344
	ctx.r1.s64 = ctx.r1.s64 + 1344;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af64
	ctx.lr = 0x823BC704;
	__restfpr_24(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8243C2F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8243C2F8;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// li r27,20
	ctx.r27.s64 = 20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8243c320
	if (!ctx.cr6.eq) goto loc_8243C320;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8243c32c
	goto loc_8243C32C;
loc_8243C320:
	// lwz r10,12(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r9,r10,r27
	ctx.r9.u64 = uint32_t((ctx.r27.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r10.s32 / ctx.r27.s32 : 0);
loc_8243C32C:
	// lwz r8,8(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lis r10,3276
	ctx.r10.s64 = 214695936;
	// subf r11,r11,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r11.u64;
	// ori r10,r10,52428
	ctx.r10.u64 = ctx.r10.u64 | 52428;
	// divw r11,r11,r27
	ctx.r11.u64 = uint32_t((ctx.r27.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r11.s32 / ctx.r27.s32 : 0);
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// bge cr6,0x8243c394
	if (!ctx.cr6.lt) goto loc_8243C394;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,56
	ctx.r4.s64 = ctx.r11.s64 + 56;
	// bl 0x822167f8
	ctx.lr = 0x8243C35C;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82216678
	ctx.lr = 0x8243C368;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x8243C36C;
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
	ctx.lr = 0x8243C380;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8243C390;
	sub_8235EC48(ctx, base);
	// b 0x8243c694
	goto loc_8243C694;
loc_8243C394:
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8243c4f4
	if (!ctx.cr6.lt) goto loc_8243C4F4;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8243c3b8
	if (!ctx.cr6.lt) goto loc_8243C3B8;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8243c3bc
	goto loc_8243C3BC;
loc_8243C3B8:
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_8243C3BC:
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8243c3c8
	if (!ctx.cr6.lt) goto loc_8243C3C8;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_8243C3C8:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mulli r28,r11,20
	ctx.r28.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(20));
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8243C3E4;
	sub_825E02A0(ctx, base);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// divw r6,r11,r27
	ctx.r6.u64 = uint32_t((ctx.r27.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r11.s32 / ctx.r27.s32 : 0);
	// mulli r5,r6,20
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(20));
	// add. r11,r5,r3
	ctx.r11.u64 = ctx.r5.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8243c41c
	if (ctx.cr0.eq) goto loc_8243C41C;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r26,-4
	ctx.r9.s64 = ctx.r26.s64 + -4;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8243C410:
	// lwzu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8243c410
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8243C410;
loc_8243C41C:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// b 0x8243c454
	goto loc_8243C454;
loc_8243C428:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8243c44c
	if (ctx.cr6.eq) goto loc_8243C44C;
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// addi r7,r10,-4
	ctx.r7.s64 = ctx.r10.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8243C440:
	// lwzu r9,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// stwu r9,4(r7)
	ea = 4 + ctx.r7.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x8243c440
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8243C440;
loc_8243C44C:
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
loc_8243C454:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8243c428
	if (!ctx.cr6.eq) goto loc_8243C428;
	// addi r11,r6,1
	ctx.r11.s64 = ctx.r6.s64 + 1;
	// lwz r6,8(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// mulli r11,r11,20
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(20));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplw cr6,r30,r6
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x8243c4b8
	if (ctx.cr6.eq) goto loc_8243C4B8;
	// subf r10,r5,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r5.u64;
	// subf r10,r31,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r31.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r10,r10,-20
	ctx.r10.s64 = ctx.r10.s64 + -20;
loc_8243C484:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8243c4a8
	if (ctx.cr6.eq) goto loc_8243C4A8;
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r8,r10,-4
	ctx.r8.s64 = ctx.r10.s64 + -4;
	// addi r7,r11,-4
	ctx.r7.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8243C49C:
	// lwzu r9,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// stwu r9,4(r7)
	ea = 4 + ctx.r7.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x8243c49c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8243C49C;
loc_8243C4A8:
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8243c484
	if (!ctx.cr6.eq) goto loc_8243C484;
loc_8243C4B8:
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// divw r11,r11,r27
	ctx.r11.u64 = uint32_t((ctx.r27.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r11.s32 / ctx.r27.s32 : 0);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x8243c4d8
	if (ctx.cr6.eq) goto loc_8243C4D8;
	// bl 0x825e0378
	ctx.lr = 0x8243C4D8;
	sub_825E0378(ctx, base);
loc_8243C4D8:
	// mulli r11,r30,20
	ctx.r11.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(20));
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// add r10,r28,r31
	ctx.r10.u64 = ctx.r28.u64 + ctx.r31.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r10,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r10.u32);
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// b 0x8243c694
	goto loc_8243C694;
loc_8243C4F4:
	// subf r11,r30,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r30.u64;
	// divw r11,r11,r27
	ctx.r11.u64 = uint32_t((ctx.r27.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r11.s32 / ctx.r27.s32 : 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8243c5d8
	if (!ctx.cr6.lt) goto loc_8243C5D8;
	// addi r11,r30,20
	ctx.r11.s64 = ctx.r30.s64 + 20;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8243c548
	if (ctx.cr6.eq) goto loc_8243C548;
	// addi r10,r11,-20
	ctx.r10.s64 = ctx.r11.s64 + -20;
loc_8243C514:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8243c538
	if (ctx.cr6.eq) goto loc_8243C538;
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r7,r10,-4
	ctx.r7.s64 = ctx.r10.s64 + -4;
	// addi r6,r11,-4
	ctx.r6.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8243C52C:
	// lwzu r9,4(r7)
	ea = 4 + ctx.r7.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r7.u32 = ea;
	// stwu r9,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r6.u32 = ea;
	// bdnz 0x8243c52c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8243C52C;
loc_8243C538:
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8243c514
	if (!ctx.cr6.eq) goto loc_8243C514;
loc_8243C548:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// divw r10,r10,r27
	ctx.r10.u64 = uint32_t((ctx.r27.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r10.s32 / ctx.r27.s32 : 0);
	// subfic r10,r10,1
	ctx.xer.ca = ctx.r10.u32 <= 1;
	ctx.r10.u64 = static_cast<uint64_t>(1) - ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8243c590
	if (ctx.cr6.eq) goto loc_8243C590;
loc_8243C560:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8243c584
	if (ctx.cr6.eq) goto loc_8243C584;
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r8,r26,-4
	ctx.r8.s64 = ctx.r26.s64 + -4;
	// addi r7,r11,-4
	ctx.r7.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8243C578:
	// lwzu r9,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// stwu r9,4(r7)
	ea = 4 + ctx.r7.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x8243c578
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8243C578;
loc_8243C584:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// bne 0x8243c560
	if (!ctx.cr0.eq) goto loc_8243C560;
loc_8243C590:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// addi r7,r11,-20
	ctx.r7.s64 = ctx.r11.s64 + -20;
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// cmplw cr6,r30,r7
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8243c694
	if (ctx.cr6.eq) goto loc_8243C694;
loc_8243C5AC:
	// li r11,5
	ctx.r11.s64 = 5;
	// addi r9,r26,-4
	ctx.r9.s64 = ctx.r26.s64 + -4;
	// addi r8,r10,-4
	ctx.r8.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8243C5BC:
	// lwzu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r11,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x8243c5bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8243C5BC;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8243c5ac
	if (!ctx.cr6.eq) goto loc_8243C5AC;
	// b 0x8243c694
	goto loc_8243C694;
loc_8243C5D8:
	// addi r11,r8,-20
	ctx.r11.s64 = ctx.r8.s64 + -20;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8243c620
	if (ctx.cr6.eq) goto loc_8243C620;
loc_8243C5EC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8243c610
	if (ctx.cr6.eq) goto loc_8243C610;
	// li r7,5
	ctx.r7.s64 = 5;
	// addi r6,r9,-4
	ctx.r6.s64 = ctx.r9.s64 + -4;
	// addi r5,r10,-4
	ctx.r5.s64 = ctx.r10.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8243C604:
	// lwzu r7,4(r6)
	ea = 4 + ctx.r6.u32;
	ctx.r7.u64 = REX_LOAD_U32(ea);
	ctx.r6.u32 = ea;
	// stwu r7,4(r5)
	ea = 4 + ctx.r5.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r5.u32 = ea;
	// bdnz 0x8243c604
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8243C604;
loc_8243C610:
	// addi r9,r9,20
	ctx.r9.s64 = ctx.r9.s64 + 20;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8243c5ec
	if (!ctx.cr6.eq) goto loc_8243C5EC;
loc_8243C620:
	// stw r10,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r10.u32);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8243c65c
	if (ctx.cr6.eq) goto loc_8243C65C;
	// addi r10,r11,20
	ctx.r10.s64 = ctx.r11.s64 + 20;
loc_8243C630:
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r11,r11,-20
	ctx.r11.s64 = ctx.r11.s64 + -20;
	// addi r10,r10,-20
	ctx.r10.s64 = ctx.r10.s64 + -20;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// addi r7,r10,-4
	ctx.r7.s64 = ctx.r10.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8243C648:
	// lwzu r9,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// stwu r9,4(r7)
	ea = 4 + ctx.r7.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x8243c648
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8243C648;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8243c630
	if (!ctx.cr6.eq) goto loc_8243C630;
loc_8243C65C:
	// addi r7,r30,20
	ctx.r7.s64 = ctx.r30.s64 + 20;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r7
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8243c694
	if (ctx.cr6.eq) goto loc_8243C694;
loc_8243C66C:
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r26,-4
	ctx.r9.s64 = ctx.r26.s64 + -4;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8243C67C:
	// lwzu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r10,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x8243c67c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8243C67C;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8243c66c
	if (!ctx.cr6.eq) goto loc_8243C66C;
loc_8243C694:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82455E30) {
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
	// bl 0x82453d80
	ctx.lr = 0x82455E40;
	sub_82453D80(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-12900(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12900);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82456BB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82456BB8;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82455138
	ctx.lr = 0x82456BC8;
	sub_82455138(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82457438
	ctx.lr = 0x82456BD4;
	sub_82457438(ctx, base);
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r31,140(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// lwz r29,144(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 144);
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82456c6c
	if (ctx.cr6.eq) goto loc_82456C6C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f31,14280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14280);
	ctx.f31.f64 = double(temp.f32);
loc_82456BF4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r27,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r27.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82456C14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-12816(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -12816);
	// lwz r9,316(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 316);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82456c40
	if (ctx.cr6.eq) goto loc_82456C40;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// b 0x82456c44
	goto loc_82456C44;
loc_82456C40:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82456C44:
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r10,120(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 120);
	// lfs f0,96(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82456C60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82456bf4
	if (!ctx.cr6.eq) goto loc_82456BF4;
loc_82456C6C:
	// lwz r11,-12816(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -12816);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,316(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 316);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// stb r10,283(r30)
	REX_STORE_U8(ctx.r30.u32 + 283, ctx.r10.u8);
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// stw r27,324(r30)
	REX_STORE_U32(ctx.r30.u32 + 324, ctx.r27.u32);
	// lwz r10,172(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// rlwinm r11,r9,4,12,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82456ca8
	if (ctx.cr6.eq) goto loc_82456CA8;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// b 0x82456cac
	goto loc_82456CAC;
loc_82456CA8:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82456CAC:
	// lwz r3,2340(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,932(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 932);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82456CC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82456d5c
	if (ctx.cr0.eq) goto loc_82456D5C;
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lwz r5,312(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 312);
	// lwz r11,-12944(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12944);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82456cfc
	if (ctx.cr6.eq) goto loc_82456CFC;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82456cfc
	if (ctx.cr6.eq) goto loc_82456CFC;
	// li r6,150
	ctx.r6.s64 = 150;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// bl 0x82454970
	ctx.lr = 0x82456CF4;
	sub_82454970(ctx, base);
	// lwz r11,-12944(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12944);
	// b 0x82456d00
	goto loc_82456D00;
loc_82456CFC:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_82456D00:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82456d10
	if (ctx.cr6.eq) goto loc_82456D10;
	// lhz r10,64(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 64);
	// b 0x82456d14
	goto loc_82456D14;
loc_82456D10:
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_82456D14:
	// lwz r5,312(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 312);
	// clrlwi r29,r10,16
	ctx.r29.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82456d40
	if (ctx.cr6.eq) goto loc_82456D40;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82456d40
	if (ctx.cr6.eq) goto loc_82456D40;
	// li r6,150
	ctx.r6.s64 = 150;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// bl 0x82454970
	ctx.lr = 0x82456D3C;
	sub_82454970(ctx, base);
	// b 0x82456d44
	goto loc_82456D44;
loc_82456D40:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_82456D44:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82456d54
	if (ctx.cr6.eq) goto loc_82456D54;
	// lhz r11,66(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 66);
	// b 0x82456d58
	goto loc_82456D58;
loc_82456D54:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_82456D58:
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
loc_82456D5C:
	// clrlwi. r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82456ddc
	if (!ctx.cr0.eq) goto loc_82456DDC;
	// lwz r11,-12816(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -12816);
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// lwz r9,316(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 316);
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
	// bne cr6,0x82456d8c
	if (!ctx.cr6.eq) goto loc_82456D8C;
	// lwz r31,4(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82456D8C:
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r4,312(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 312);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,936(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 936);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82456DA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82456dd8
	if (ctx.cr0.eq) goto loc_82456DD8;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r4,312(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 312);
	// lhz r31,88(r31)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r31.u32 + 88);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,936(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 936);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82456DC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// mullw r11,r3,r11
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x82456ddc
	goto loc_82456DDC;
loc_82456DD8:
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
loc_82456DDC:
	// sth r29,328(r30)
	REX_STORE_U16(ctx.r30.u32 + 328, ctx.r29.u16);
	// sth r31,184(r30)
	REX_STORE_U16(ctx.r30.u32 + 184, ctx.r31.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8246CB78) {
	REX_FUNC_PROLOGUE();
	// lwz r11,144(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// lwz r10,140(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8246cb98
	if (ctx.cr6.lt) goto loc_8246CB98;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8246CB98:
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8246DE50) {
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
	// lwz r6,4(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// li r30,1
	ctx.r30.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r11,4(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// lbz r10,21(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8246debc
	if (!ctx.cr0.eq) goto loc_8246DEBC;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
loc_8246DE8C:
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
	// clrlwi. r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8246deac
	if (ctx.cr0.eq) goto loc_8246DEAC;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8246deb0
	goto loc_8246DEB0;
loc_8246DEAC:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
loc_8246DEB0:
	// lbz r9,21(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8246de8c
	if (ctx.cr0.eq) goto loc_8246DE8C;
loc_8246DEBC:
	// clrlwi. r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// beq 0x8246df78
	if (ctx.cr0.eq) goto loc_8246DF78;
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8246def8
	if (!ctx.cr6.eq) goto loc_8246DEF8;
	// li r5,1
	ctx.r5.s64 = 1;
loc_8246DEDC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8257ab00
	ctx.lr = 0x8246DEE4;
	sub_8257AB00(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stb r30,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r30.u8);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x8246df9c
	goto loc_8246DF9C;
loc_8246DEF8:
	// lbz r11,21(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 21);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8246df0c
	if (ctx.cr0.eq) goto loc_8246DF0C;
	// lwz r10,8(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// b 0x8246df78
	goto loc_8246DF78;
loc_8246DF0C:
	// lwz r9,0(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lbz r11,21(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 21);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8246df40
	if (!ctx.cr0.eq) goto loc_8246DF40;
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// b 0x8246df30
	goto loc_8246DF30;
loc_8246DF28:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
loc_8246DF30:
	// lbz r9,21(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8246df28
	if (ctx.cr0.eq) goto loc_8246DF28;
	// b 0x8246df78
	goto loc_8246DF78;
loc_8246DF40:
	// lwz r11,4(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// b 0x8246df5c
	goto loc_8246DF5C;
loc_8246DF48:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8246df68
	if (!ctx.cr6.eq) goto loc_8246DF68;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_8246DF5C:
	// lbz r9,21(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8246df48
	if (ctx.cr0.eq) goto loc_8246DF48;
loc_8246DF68:
	// lbz r9,21(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 21);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x8246df78
	if (!ctx.cr0.eq) goto loc_8246DF78;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8246DF78:
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r9,0(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8246df90
	if (!ctx.cr6.lt) goto loc_8246DF90;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// b 0x8246dedc
	goto loc_8246DEDC;
loc_8246DF90:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stb r11,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
loc_8246DF9C:
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

DEFINE_REX_FUNC(sub_82476CA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82476CA8;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// rlwinm. r30,r4,0,24,25
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xC0;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// clrlwi r28,r29,24
	ctx.r28.u64 = ctx.r29.u32 & 0xFF;
	// beq 0x82476cd8
	if (ctx.cr0.eq) goto loc_82476CD8;
	// rlwinm r11,r28,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x2;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
loc_82476CD8:
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,364(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 364);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82476CEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82476d08
	if (ctx.cr6.eq) goto loc_82476D08;
	// rlwinm r11,r28,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x4;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r4,r11,3
	ctx.r4.s64 = ctx.r11.s64 + 3;
loc_82476D08:
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,368(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 368);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82476D1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8246a8a8
	ctx.lr = 0x82476D28;
	sub_8246A8A8(ctx, base);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,244(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 244);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82476D54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82477b40
	ctx.lr = 0x82476D5C;
	sub_82477B40(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82477930
	ctx.lr = 0x82476D64;
	sub_82477930(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82477a58
	ctx.lr = 0x82476D6C;
	sub_82477A58(ctx, base);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82476D84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82477d80
	ctx.lr = 0x82476D8C;
	sub_82477D80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82478070
	ctx.lr = 0x82476D94;
	sub_82478070(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82478530
	ctx.lr = 0x82476D9C;
	sub_82478530(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8247E658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,14376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,352(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8247FD40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8247FD48;
	__savegprlr_25(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247FD6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,361(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 361);
	// li r29,-1
	ctx.r29.s64 = -1;
	// stw r29,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r29.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8247ff7c
	if (ctx.cr0.eq) goto loc_8247FF7C;
	// lbz r11,99(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 99);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfd f13,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f0,-17036(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17036);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8247ff7c
	if (ctx.cr6.lt) goto loc_8247FF7C;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f12,328(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 328);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r28,r1,160
	ctx.r28.s64 = ctx.r1.s64 + 160;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r27,r1,160
	ctx.r27.s64 = ctx.r1.s64 + 160;
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lfs f0,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// addi r26,r1,144
	ctx.r26.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lis r25,-32226
	ctx.r25.s64 = -2111963136;
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lwz r30,-13032(r5)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r5.u32 + -13032);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r5,r25,2688
	ctx.r5.s64 = ctx.r25.s64 + 2688;
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// li r25,1
	ctx.r25.s64 = 1;
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r5.u32);
	// stfs f12,172(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stw r25,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r25.u32);
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v58,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v57,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// vsubfp128 v63,v57,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,148(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// vaddfp128 v62,v62,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v57,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// stfs f12,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// vaddfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f10,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f10.f64 = double(temp.f32);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// std r10,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.r10.u64);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r11.u64);
	// beq cr6,0x8247ff30
	if (ctx.cr6.eq) goto loc_8247FF30;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x823aefa8
	ctx.lr = 0x8247FF2C;
	sub_823AEFA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_8247FF30:
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
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r8,132(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// beq cr6,0x8247ff78
	if (ctx.cr6.eq) goto loc_8247FF78;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r31,68
	ctx.r10.s64 = ctx.r31.s64 + 68;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823b0938
	ctx.lr = 0x8247FF74;
	sub_823B0938(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_8247FF78:
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
loc_8247FF7C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8249FCA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8249FCA8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r8,296(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 296);
	// lwz r6,300(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 300);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,-22096
	ctx.r11.s64 = ctx.r11.s64 + -22096;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x8249fd50
	if (ctx.cr6.eq) goto loc_8249FD50;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r7,-12816(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
loc_8249FCD8:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r9,172(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 172);
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8249fd04
	if (!ctx.cr6.eq) goto loc_8249FD04;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x8249fd08
	if (!ctx.cr6.eq) goto loc_8249FD08;
loc_8249FD04:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8249FD08:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8249fd44
	if (ctx.cr0.eq) goto loc_8249FD44;
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8249fd44
	if (!ctx.cr6.eq) goto loc_8249FD44;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8249fd44
	if (ctx.cr6.eq) goto loc_8249FD44;
	// lbz r10,23(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8249fd44
	if (!ctx.cr0.eq) goto loc_8249FD44;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,23(r11)
	REX_STORE_U8(ctx.r11.u32 + 23, ctx.r10.u8);
loc_8249FD44:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8249fcd8
	if (!ctx.cr6.eq) goto loc_8249FCD8;
loc_8249FD50:
	// addi r31,r30,292
	ctx.r31.s64 = ctx.r30.s64 + 292;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82217698
	ctx.lr = 0x8249FD5C;
	sub_82217698(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82469fb0
	ctx.lr = 0x8249FD64;
	sub_82469FB0(ctx, base);
	// lwz r3,296(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 296);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8249fd74
	if (ctx.cr6.eq) goto loc_8249FD74;
	// bl 0x825e0378
	ctx.lr = 0x8249FD74;
	sub_825E0378(ctx, base);
loc_8249FD74:
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// bl 0x82469ee8
	ctx.lr = 0x8249FD88;
	sub_82469EE8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824A6AD0) {
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
	// addi r11,r11,-20792
	ctx.r11.s64 = ctx.r11.s64 + -20792;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x824A6AFC;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824a6b0c
	if (ctx.cr0.eq) goto loc_824A6B0C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x824A6B0C;
	sub_825E0378(ctx, base);
loc_824A6B0C:
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

DEFINE_REX_FUNC(sub_824A8848) {
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
	// addi r3,r3,316
	ctx.r3.s64 = ctx.r3.s64 + 316;
	// bl 0x82217698
	ctx.lr = 0x824A8864;
	sub_82217698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82469fb0
	ctx.lr = 0x824A886C;
	sub_82469FB0(ctx, base);
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

DEFINE_REX_FUNC(sub_824AA4E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x824AA4F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-20336
	ctx.r11.s64 = ctx.r11.s64 + -20336;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// bl 0x825a4750
	ctx.lr = 0x824AA50C;
	sub_825A4750(ctx, base);
	// lwz r3,372(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 372);
	// addi r30,r28,368
	ctx.r30.s64 = ctx.r28.s64 + 368;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824aa520
	if (ctx.cr6.eq) goto loc_824AA520;
	// bl 0x825e0378
	ctx.lr = 0x824AA520;
	sub_825E0378(ctx, base);
loc_824AA520:
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r29,r28,352
	ctx.r29.s64 = ctx.r28.s64 + 352;
	// stw r31,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// stw r31,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r31.u32);
	// stw r31,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
	// lwz r3,356(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 356);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824aa544
	if (ctx.cr6.eq) goto loc_824AA544;
	// bl 0x825e0378
	ctx.lr = 0x824AA544;
	sub_825E0378(ctx, base);
loc_824AA544:
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r31,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
	// stw r31,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// bl 0x82469ee8
	ctx.lr = 0x824AA558;
	sub_82469EE8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824ACCE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lwz r11,328(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 328);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// rlwinm. r10,r4,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// bnelr 
	if (!ctx.cr0.eq) return;
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r10,116(r3)
	REX_STORE_U8(ctx.r3.u32 + 116, ctx.r10.u8);
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f0,72(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stw r9,328(r3)
	REX_STORE_U32(ctx.r3.u32 + 328, ctx.r9.u32);
	// stfs f0,296(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824AE6A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824AE6A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,-19524
	ctx.r30.s64 = ctx.r11.s64 + -19524;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x824AE6C4;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r29,1
	ctx.r29.s64 = 1;
	// bne 0x824ae6d4
	if (!ctx.cr0.eq) goto loc_824AE6D4;
	// stb r29,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r29.u8);
loc_824AE6D4:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x824AE6E4;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824ae6f0
	if (!ctx.cr0.eq) goto loc_824AE6F0;
	// stb r29,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r29.u8);
loc_824AE6F0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824B0878) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-32181
	ctx.r10.s64 = -2109014016;
	// lwz r11,288(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 288);
	// addi r10,r10,2400
	ctx.r10.s64 = ctx.r10.s64 + 2400;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r10,-32181
	ctx.r10.s64 = -2109014016;
	// addi r10,r10,2704
	ctx.r10.s64 = ctx.r10.s64 + 2704;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32181
	ctx.r10.s64 = -2109014016;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r10,r10,2704
	ctx.r10.s64 = ctx.r10.s64 + 2704;
	// stb r9,292(r3)
	REX_STORE_U8(ctx.r3.u32 + 292, ctx.r9.u8);
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,288(r3)
	REX_STORE_U32(ctx.r3.u32 + 288, ctx.r10.u32);
	// stfs f0,280(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824B32B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x824B32C0;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f0,328(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 328);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lfs f13,332(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 332);
	ctx.f13.f64 = double(temp.f32);
	// addi r26,r11,22072
	ctx.r26.s64 = ctx.r11.s64 + 22072;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r4,100
	ctx.r4.s64 = 100;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f31,-3324(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -3324);
	ctx.f31.f64 = double(temp.f32);
	// lwz r3,48(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x824B32FC;
	sub_825E02A0(ctx, base);
	// li r25,25
	ctx.r25.s64 = 25;
	// lis r29,-32228
	ctx.r29.s64 = -2112094208;
	// lis r28,-32226
	ctx.r28.s64 = -2111963136;
	// lis r27,-32111
	ctx.r27.s64 = -2104426496;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824b3364
	if (ctx.cr0.eq) goto loc_824B3364;
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lfs f0,17288(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 17288);
	ctx.f0.f64 = double(temp.f32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r25,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// lfs f0,-8644(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f13,-24784(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -24784);
	ctx.f13.f64 = double(temp.f32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// bl 0x8221b560
	ctx.lr = 0x824B335C;
	sub_8221B560(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x824b3368
	goto loc_824B3368;
loc_824B3364:
	// li r30,0
	ctx.r30.s64 = 0;
loc_824B3368:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824b33cc
	if (ctx.cr6.eq) goto loc_824B33CC;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B3388;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32181
	ctx.r11.s64 = -2109014016;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r11,r11,13512
	ctx.r11.s64 = ctx.r11.s64 + 13512;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,76(r30)
	REX_STORE_U32(ctx.r30.u32 + 76, ctx.r11.u32);
	// bl 0x82222ad8
	ctx.lr = 0x824B33A0;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x824b33cc
	if (!ctx.cr6.eq) goto loc_824B33CC;
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
	ctx.lr = 0x824B33CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824B33CC:
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,100
	ctx.r4.s64 = 100;
	// lwz r3,48(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 48);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x824B33FC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824b3454
	if (ctx.cr0.eq) goto loc_824B3454;
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lfs f0,17288(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 17288);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r25,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,-8644(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfs f13,-24784(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -24784);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x8221b560
	ctx.lr = 0x824B344C;
	sub_8221B560(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x824b3458
	goto loc_824B3458;
loc_824B3454:
	// li r30,0
	ctx.r30.s64 = 0;
loc_824B3458:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824b34bc
	if (ctx.cr6.eq) goto loc_824B34BC;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B3478;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32181
	ctx.r11.s64 = -2109014016;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r11,r11,13512
	ctx.r11.s64 = ctx.r11.s64 + 13512;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,76(r30)
	REX_STORE_U32(ctx.r30.u32 + 76, ctx.r11.u32);
	// bl 0x82222ad8
	ctx.lr = 0x824B3490;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x824b34bc
	if (!ctx.cr6.eq) goto loc_824B34BC;
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
	ctx.lr = 0x824B34BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824B34BC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824BDCC0) {
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
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r10,14876
	ctx.r9.s64 = ctx.r10.s64 + 14876;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// ld r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f13,14876(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14876);
	ctx.f13.f64 = double(temp.f32);
	// li r4,100
	ctx.r4.s64 = 100;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,212(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 212);
	ctx.f0.f64 = double(temp.f32);
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// bl 0x825e02a0
	ctx.lr = 0x824BDD20;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824bdd40
	if (ctx.cr0.eq) goto loc_824BDD40;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f1,-23552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23552);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82218490
	ctx.lr = 0x824BDD38;
	sub_82218490(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x824bdd44
	goto loc_824BDD44;
loc_824BDD40:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824BDD44:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824bdda0
	if (ctx.cr6.eq) goto loc_824BDDA0;
	// lis r11,-32180
	ctx.r11.s64 = -2108948480;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r11,r11,-9248
	ctx.r11.s64 = ctx.r11.s64 + -9248;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// lwz r11,56(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824BDD70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x824BDD7C;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x824bdda0
	if (!ctx.cr6.eq) goto loc_824BDDA0;
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
	ctx.lr = 0x824BDDA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824BDDA0:
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

DEFINE_REX_FUNC(sub_824C46C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x824C46D0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x824c5510
	ctx.lr = 0x824C46DC;
	sub_824C5510(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c55d0
	ctx.lr = 0x824C46E4;
	sub_824C55D0(ctx, base);
	// addi r27,r31,4052
	ctx.r27.s64 = ctx.r31.s64 + 4052;
	// lwz r30,4060(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 4060);
	// lwz r28,4056(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 4056);
	// cmplw cr6,r28,r30
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x824c4728
	if (ctx.cr6.eq) goto loc_824C4728;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r30
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x824c4724
	if (ctx.cr6.eq) goto loc_824C4724;
loc_824C4704:
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8273a030
	ctx.lr = 0x824C4714;
	sub_8273A030(ctx, base);
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// addi r28,r28,48
	ctx.r28.s64 = ctx.r28.s64 + 48;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x824c4704
	if (!ctx.cr6.eq) goto loc_824C4704;
loc_824C4724:
	// stw r28,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r28.u32);
loc_824C4728:
	// lwz r4,4116(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4116);
	// li r28,-1
	ctx.r28.s64 = -1;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x824c4750
	if (ctx.cr6.eq) goto loc_824C4750;
	// lwz r3,-12824(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x824C4748;
	sub_82599798(ctx, base);
	// stw r28,4116(r31)
	REX_STORE_U32(ctx.r31.u32 + 4116, ctx.r28.u32);
	// stw r29,4120(r31)
	REX_STORE_U32(ctx.r31.u32 + 4120, ctx.r29.u32);
loc_824C4750:
	// lwz r4,4108(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4108);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x824c476c
	if (ctx.cr6.eq) goto loc_824C476C;
	// lwz r3,-12824(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x824C4764;
	sub_82599798(ctx, base);
	// stw r28,4108(r31)
	REX_STORE_U32(ctx.r31.u32 + 4108, ctx.r28.u32);
	// stw r29,4112(r31)
	REX_STORE_U32(ctx.r31.u32 + 4112, ctx.r29.u32);
loc_824C476C:
	// lwz r4,4100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4100);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x824c4788
	if (ctx.cr6.eq) goto loc_824C4788;
	// lwz r3,-12824(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x824C4780;
	sub_82599798(ctx, base);
	// stw r28,4100(r31)
	REX_STORE_U32(ctx.r31.u32 + 4100, ctx.r28.u32);
	// stw r29,4104(r31)
	REX_STORE_U32(ctx.r31.u32 + 4104, ctx.r29.u32);
loc_824C4788:
	// lwz r4,4092(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4092);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x824c47a4
	if (ctx.cr6.eq) goto loc_824C47A4;
	// lwz r3,-12824(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x824C479C;
	sub_82599798(ctx, base);
	// stw r28,4092(r31)
	REX_STORE_U32(ctx.r31.u32 + 4092, ctx.r28.u32);
	// stw r29,4096(r31)
	REX_STORE_U32(ctx.r31.u32 + 4096, ctx.r29.u32);
loc_824C47A4:
	// lwz r4,4084(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4084);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x824c47c0
	if (ctx.cr6.eq) goto loc_824C47C0;
	// lwz r3,-12824(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x824C47B8;
	sub_82599798(ctx, base);
	// stw r28,4084(r31)
	REX_STORE_U32(ctx.r31.u32 + 4084, ctx.r28.u32);
	// stw r29,4088(r31)
	REX_STORE_U32(ctx.r31.u32 + 4088, ctx.r29.u32);
loc_824C47C0:
	// lwz r4,4076(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4076);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x824c47dc
	if (ctx.cr6.eq) goto loc_824C47DC;
	// lwz r3,-12824(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x824C47D4;
	sub_82599798(ctx, base);
	// stw r28,4076(r31)
	REX_STORE_U32(ctx.r31.u32 + 4076, ctx.r28.u32);
	// stw r29,4080(r31)
	REX_STORE_U32(ctx.r31.u32 + 4080, ctx.r29.u32);
loc_824C47DC:
	// lwz r3,4048(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4048);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824c4800
	if (ctx.cr6.eq) goto loc_824C4800;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824C47FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,4048(r31)
	REX_STORE_U32(ctx.r31.u32 + 4048, ctx.r29.u32);
loc_824C4800:
	// lwz r3,364(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824c4824
	if (ctx.cr6.eq) goto loc_824C4824;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824C4820;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r29.u32);
loc_824C4824:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82469fb0
	ctx.lr = 0x824C482C;
	sub_82469FB0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824D3328) {
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
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8246a270
	ctx.lr = 0x824D3344;
	sub_8246A270(ctx, base);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824D335C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r11.u8);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824D3380;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,24
	ctx.r4.s64 = 24;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r5,88(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x82517858
	ctx.lr = 0x824D3394;
	sub_82517858(ctx, base);
	// stw r3,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// li r4,24
	ctx.r4.s64 = 24;
	// lbz r6,80(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r5,88(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x82517f98
	ctx.lr = 0x824D33AC;
	sub_82517F98(ctx, base);
	// stfs f1,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 196, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,24
	ctx.r4.s64 = 24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82518388
	ctx.lr = 0x824D33C0;
	sub_82518388(ctx, base);
	// stfs f1,200(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 200, temp.u32);
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

DEFINE_REX_FUNC(sub_824D5660) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x824D5668;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// clrlwi r9,r6,24
	ctx.r9.u64 = ctx.r6.u32 & 0xFF;
	// addi r4,r10,-15028
	ctx.r4.s64 = ctx.r10.s64 + -15028;
	// li r8,11
	ctx.r8.s64 = 11;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x824D56A0;
	sub_825190E8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r29,r11,12236
	ctx.r29.s64 = ctx.r11.s64 + 12236;
	// addi r11,r10,-14720
	ctx.r11.s64 = ctx.r10.s64 + -14720;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// clrlwi r30,r30,24
	ctx.r30.u64 = ctx.r30.u32 & 0xFF;
	// lfs f0,232(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stw r11,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// stw r27,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r27.u32);
	// stw r10,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r10.u32);
	// stb r10,316(r31)
	REX_STORE_U8(ctx.r31.u32 + 316, ctx.r10.u8);
	// stb r30,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r30.u8);
	// bl 0x825a4640
	ctx.lr = 0x824D56EC;
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
	ctx.lr = 0x824D5708;
	sub_825A48B0(ctx, base);
	// lwz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// ble cr6,0x824d571c
	if (!ctx.cr6.gt) goto loc_824D571C;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r11,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r11.u32);
loc_824D571C:
	// lwz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f12,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subfic r11,r11,8
	ctx.xer.ca = ctx.r11.u32 <= 8;
	ctx.r11.u64 = static_cast<uint64_t>(8) - ctx.r11.u64;
	// stb r30,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r30.u8);
	// addi r9,r10,17132
	ctx.r9.s64 = ctx.r10.s64 + 17132;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f0,17132(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17132);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfs f13,1248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1248);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f11,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f13.f64)));
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824DC008) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824DC010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x824DC018;
	__savegprlr_21(ctx, base);
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8273af28
	ctx.lr = 0x824DC020;
	__savefpr_28(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,436(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 436);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824dcc38
	if (!ctx.cr0.eq) goto loc_824DCC38;
	// lbz r11,437(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 437);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824dc060
	if (ctx.cr0.eq) goto loc_824DC060;
	// lwz r11,344(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 344);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x824dc060
	if (ctx.cr6.eq) goto loc_824DC060;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,136(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824DC060;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824DC060:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r22,r11,14280
	ctx.r22.s64 = ctx.r11.s64 + 14280;
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// li r23,1
	ctx.r23.s64 = 1;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r27,r31,68
	ctx.r27.s64 = ctx.r31.s64 + 68;
	// lfs f31,-2044(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2044);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,364(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 364, temp.u32);
	// lfs f0,68(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
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
	// lfs f0,-1812(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -1812);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x824dc0b8
	if (ctx.cr6.lt) goto loc_824DC0B8;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_824DC0B8:
	// lfs f30,-1808(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -1808);
	ctx.f30.f64 = double(temp.f32);
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824dc0c8
	if (ctx.cr0.eq) goto loc_824DC0C8;
	// stfs f30,364(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 364, temp.u32);
loc_824DC0C8:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f11,376(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// addi r24,r11,-30652
	ctx.r24.s64 = ctx.r11.s64 + -30652;
	// addi r25,r10,32256
	ctx.r25.s64 = ctx.r10.s64 + 32256;
	// bgt cr6,0x824dc100
	if (ctx.cr6.gt) goto loc_824DC100;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,376(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// b 0x824dc1ec
	goto loc_824DC1EC;
loc_824DC100:
	// ld r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r27.u32 + 0);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v6,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lfs f12,-17600(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -17600);
	ctx.f12.f64 = double(temp.f32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f0,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x824dc1b0
	if (!ctx.cr6.lt) goto loc_824DC1B0;
	// li r11,50
	ctx.r11.s64 = 50;
	// b 0x824dc1e8
	goto loc_824DC1E8;
loc_824DC1B0:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// li r11,-1
	ctx.r11.s64 = -1;
	// ble cr6,0x824dc1cc
	if (!ctx.cr6.gt) goto loc_824DC1CC;
	// fctidz f0,f11
	ctx.f0.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r10,116(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// b 0x824dc1d8
	goto loc_824DC1D8;
loc_824DC1CC:
	// fctidz f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r10,116(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
loc_824DC1D8:
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
loc_824DC1E8:
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_824DC1EC:
	// addi r9,r31,284
	ctx.r9.s64 = ctx.r31.s64 + 284;
	// li r8,7
	ctx.r8.s64 = 7;
loc_824DC1F4:
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824dc208
	if (ctx.cr6.eq) goto loc_824DC208;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x8223ace0
	ctx.lr = 0x824DC208;
	sub_8223ACE0(ctx, base);
loc_824DC208:
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x824dc1f4
	if (!ctx.cr0.eq) goto loc_824DC1F4;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x824dc420
	if (ctx.cr6.eq) goto loc_824DC420;
	// lbz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 116);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824dc420
	if (ctx.cr0.eq) goto loc_824DC420;
	// lbz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 404);
	// stw r30,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r30.u32);
	// stw r30,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r30,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r30.u32);
	// stb r30,140(r1)
	REX_STORE_U8(ctx.r1.u32 + 140, ctx.r30.u8);
	// stb r30,141(r1)
	REX_STORE_U8(ctx.r1.u32 + 141, ctx.r30.u8);
	// beq 0x824dc420
	if (ctx.cr0.eq) goto loc_824DC420;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r4,336(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// stw r30,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r30,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r30.u32);
	// stb r30,140(r1)
	REX_STORE_U8(ctx.r1.u32 + 140, ctx.r30.u8);
	// lwz r10,-13032(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// stb r30,141(r1)
	REX_STORE_U8(ctx.r1.u32 + 141, ctx.r30.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824dc28c
	if (ctx.cr6.eq) goto loc_824DC28C;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823b0af8
	ctx.lr = 0x824DC288;
	sub_823B0AF8(ctx, base);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
loc_824DC28C:
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824dc420
	if (ctx.cr0.eq) goto loc_824DC420;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
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
	// bne cr6,0x824dc2cc
	if (!ctx.cr6.eq) goto loc_824DC2CC;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// bne cr6,0x824dc2d0
	if (!ctx.cr6.eq) goto loc_824DC2D0;
loc_824DC2CC:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_824DC2D0:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824dc420
	if (ctx.cr0.eq) goto loc_824DC420;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824dc420
	if (!ctx.cr6.eq) goto loc_824DC420;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824dc420
	if (ctx.cr6.eq) goto loc_824DC420;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824dc420
	if (ctx.cr0.eq) goto loc_824DC420;
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824dc420
	if (ctx.cr6.eq) goto loc_824DC420;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 960);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824DC324;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10, ctx.xer);
	// beq cr6,0x824dc338
	if (ctx.cr6.eq) goto loc_824DC338;
	// cmpwi cr6,r3,22
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 22, ctx.xer);
	// bne cr6,0x824dc420
	if (!ctx.cr6.eq) goto loc_824DC420;
loc_824DC338:
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824dd900
	ctx.lr = 0x824DC344;
	sub_824DD900(ctx, base);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,32
	ctx.r4.s64 = ctx.r11.s64 + 32;
	// bl 0x8231e0d8
	ctx.lr = 0x824DC354;
	sub_8231E0D8(ctx, base);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stb r23,354(r31)
	REX_STORE_U8(ctx.r31.u32 + 354, ctx.r23.u8);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-28800
	ctx.r11.s64 = ctx.r11.s64 + -28800;
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r29,10
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 10, ctx.xer);
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
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
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
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,0(r27)
	REX_STORE_U64(ctx.r27.u32 + 0, ctx.r11.u64);
	// bne cr6,0x824dc420
	if (!ctx.cr6.eq) goto loc_824DC420;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r11,r11,-32544
	ctx.r11.s64 = ctx.r11.s64 + -32544;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r9,32720
	ctx.r9.s64 = ctx.r9.s64 + 32720;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x8254bb70
	ctx.lr = 0x824DC420;
	sub_8254BB70(ctx, base);
loc_824DC420:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r26,r11,-11120
	ctx.r26.s64 = ctx.r11.s64 + -11120;
	// lwz r11,344(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 344);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x824dc810
	if (ctx.cr6.lt) goto loc_824DC810;
	// beq cr6,0x824dc448
	if (ctx.cr6.eq) goto loc_824DC448;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x824dc910
	if (!ctx.cr6.lt) goto loc_824DC910;
	// stb r23,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r23.u8);
	// b 0x824dc910
	goto loc_824DC910;
loc_824DC448:
	// lfs f0,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f0.f64 = double(temp.f32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// stfs f0,356(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 356, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8231e0d8
	ctx.lr = 0x824DC460;
	sub_8231E0D8(ctx, base);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r9,348(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r29,r11,32400
	ctx.r29.s64 = ctx.r11.s64 + 32400;
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfs f30,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f31.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r28,r11,-32216
	ctx.r28.s64 = ctx.r11.s64 + -32216;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f30,112(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f30,124(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
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
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,52(r31)
	REX_STORE_U64(ctx.r31.u32 + 52, ctx.r11.u64);
	// ble cr6,0x824dc55c
	if (!ctx.cr6.gt) goto loc_824DC55C;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r10,-28816
	ctx.r10.s64 = ctx.r10.s64 + -28816;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,-4080
	ctx.r8.s64 = ctx.r8.s64 + -4080;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,3012(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 3012);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,372(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x824dc550
	if (ctx.cr6.lt) goto loc_824DC550;
	// lfs f13,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824dc55c
	if (!ctx.cr6.gt) goto loc_824DC55C;
loc_824DC550:
	// lfs f13,6852(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 6852);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,372(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
loc_824DC55C:
	// lfs f0,368(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f13,372(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 372);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f1,368(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824DC584;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f31,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,3408(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 3408);
	ctx.f0.f64 = double(temp.f32);
	// vor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// fmuls f13,f29,f0
	ctx.f13.f64 = double(float(ctx.f29.f64 * ctx.f0.f64));
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f0,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f30,108(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r29,r1,176
	ctx.r29.s64 = ctx.r1.s64 + 176;
	// lvx128 v6,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r21,r1,176
	ctx.r21.s64 = ctx.r1.s64 + 176;
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// vmulfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fadds f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// std r11,52(r31)
	REX_STORE_U64(ctx.r31.u32 + 52, ctx.r11.u64);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lfs f0,808(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 808);
	ctx.f0.f64 = double(temp.f32);
	// ld r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r8,0(r27)
	REX_STORE_U64(ctx.r27.u32 + 0, ctx.r8.u64);
	// lfs f12,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
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
	// lfs f12,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f12,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// vmulfp128 v12,v0,v6
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vcmpeqfp128 v10,v0,v60
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vcmpeqfp128 v8,v0,v60
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vmulfp128 v11,v13,v13
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vor v9,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vcmpeqfp128 v5,v13,v60
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v60.f32)));
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
	// vcmpeqfp128 v12,v63,v60
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vmulfp128 v13,v0,v63
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsel v12,v8,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vsel v0,v13,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x824dc750
	if (!ctx.cr6.lt) goto loc_824DC750;
	// stb r30,354(r31)
	REX_STORE_U8(ctx.r31.u32 + 354, ctx.r30.u8);
	// stw r30,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r30.u32);
	// stb r30,405(r31)
	REX_STORE_U8(ctx.r31.u32 + 405, ctx.r30.u8);
	// b 0x824dc754
	goto loc_824DC754;
loc_824DC750:
	// stb r23,405(r31)
	REX_STORE_U8(ctx.r31.u32 + 405, ctx.r23.u8);
loc_824DC754:
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x824dc7d8
	if (!ctx.cr6.eq) goto loc_824DC7D8;
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824dc7d8
	if (!ctx.cr6.eq) goto loc_824DC7D8;
	// lfs f0,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f0,-7472(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -7472);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,392(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x824dc788
	if (ctx.cr6.lt) goto loc_824DC788;
	// stfs f0,392(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
loc_824DC788:
	// lfs f0,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f29,f0
	ctx.f0.f64 = double(float(ctx.f29.f64 * ctx.f0.f64));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f13,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_824DC7D8:
	// lbz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 404);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824dc910
	if (ctx.cr0.eq) goto loc_824DC910;
	// lfs f13,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824dc910
	if (!ctx.cr6.gt) goto loc_824DC910;
	// stb r30,404(r31)
	REX_STORE_U8(ctx.r31.u32 + 404, ctx.r30.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,136(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824DC80C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x824dc910
	goto loc_824DC910;
loc_824DC810:
	// lbz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 404);
	// stb r23,355(r31)
	REX_STORE_U8(ctx.r31.u32 + 355, ctx.r23.u8);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824dc90c
	if (ctx.cr0.eq) goto loc_824DC90C;
	// lwz r11,340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x824dc834
	if (ctx.cr6.eq) goto loc_824DC834;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
loc_824DC834:
	// lfs f0,31464(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 31464);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r11,r11,-30576
	ctx.r11.s64 = ctx.r11.s64 + -30576;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r11,r11,-31664
	ctx.r11.s64 = ctx.r11.s64 + -31664;
	// li r3,411
	ctx.r3.s64 = 411;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,0(r27)
	REX_STORE_U64(ctx.r27.u32 + 0, ctx.r11.u64);
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82240a58
	ctx.lr = 0x824DC90C;
	sub_82240A58(ctx, base);
loc_824DC90C:
	// stw r23,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r23.u32);
loc_824DC910:
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x824dc924
	if (ctx.cr6.eq) goto loc_824DC924;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x824dcc38
	if (!ctx.cr6.eq) goto loc_824DCC38;
loc_824DC924:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8231e0d8
	ctx.lr = 0x824DC930;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f29,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f29.f64 = double(temp.f32);
	// lfs f30,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f30.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// bl 0x825a7c80
	ctx.lr = 0x824DC94C;
	sub_825A7C80(ctx, base);
	// fneg f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x82738cc0
	ctx.lr = 0x824DC958;
	sub_82738CC0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f31,4708(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4708);
	ctx.f31.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f13,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
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
	// bl 0x82738be0
	ctx.lr = 0x824DC9AC;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
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
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x824DCA0C;
	sub_82738CC0(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f13,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82738be0
	ctx.lr = 0x824DCA5C;
	sub_82738BE0(ctx, base);
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lwz r11,332(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
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
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bne cr6,0x824dcc00
	if (!ctx.cr6.eq) goto loc_824DCC00;
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f30,164(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f30,160(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f30,172(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f30,168(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824dcc38
	if (!ctx.cr0.eq) goto loc_824DCC38;
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f29,172(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f29,168(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f29,164(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f29,160(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824dcc38
	if (!ctx.cr0.eq) goto loc_824DCC38;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,100
	ctx.r4.s64 = 100;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x824DCB30;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824dcb44
	if (ctx.cr0.eq) goto loc_824DCB44;
	// lfs f1,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82225038
	ctx.lr = 0x824DCB40;
	sub_82225038(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_824DCB44:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824dcc38
	if (ctx.cr6.eq) goto loc_824DCC38;
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x824dcb78
	if (!ctx.cr6.eq) goto loc_824DCB78;
	// lis r11,-24416
	ctx.r11.s64 = -1600126976;
	// lis r9,-24416
	ctx.r9.s64 = -1600126976;
	// ori r10,r11,41120
	ctx.r10.u64 = ctx.r11.u64 | 41120;
	// ori r11,r9,40960
	ctx.r11.u64 = ctx.r9.u64 | 40960;
	// stw r10,60(r30)
	REX_STORE_U32(ctx.r30.u32 + 60, ctx.r10.u32);
	// stw r11,64(r30)
	REX_STORE_U32(ctx.r30.u32 + 64, ctx.r11.u32);
	// stw r10,68(r30)
	REX_STORE_U32(ctx.r30.u32 + 68, ctx.r10.u32);
	// b 0x824dcba4
	goto loc_824DCBA4;
loc_824DCB78:
	// lis r11,-24576
	ctx.r11.s64 = -1610612736;
	// lis r10,-24576
	ctx.r10.s64 = -1610612736;
	// lis r9,-256
	ctx.r9.s64 = -16777216;
	// ori r11,r11,41120
	ctx.r11.u64 = ctx.r11.u64 | 41120;
	// lis r8,-256
	ctx.r8.s64 = -16777216;
	// ori r10,r10,40960
	ctx.r10.u64 = ctx.r10.u64 | 40960;
	// stw r11,60(r30)
	REX_STORE_U32(ctx.r30.u32 + 60, ctx.r11.u32);
	// ori r9,r9,41120
	ctx.r9.u64 = ctx.r9.u64 | 41120;
	// ori r11,r8,40960
	ctx.r11.u64 = ctx.r8.u64 | 40960;
	// stw r10,64(r30)
	REX_STORE_U32(ctx.r30.u32 + 64, ctx.r10.u32);
	// stw r9,68(r30)
	REX_STORE_U32(ctx.r30.u32 + 68, ctx.r9.u32);
loc_824DCBA4:
	// lfs f0,0(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,72(r30)
	REX_STORE_U32(ctx.r30.u32 + 72, ctx.r11.u32);
	// stfs f0,84(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 84, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f0,80(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 80, temp.u32);
	// ld r5,96(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// ld r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// bl 0x82225278
	ctx.lr = 0x824DCBC4;
	sub_82225278(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x824DCBD0;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x824dcc38
	if (!ctx.cr6.eq) goto loc_824DCC38;
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
	ctx.lr = 0x824DCBFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x824dcc38
	goto loc_824DCC38;
loc_824DCC00:
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x824DCC0C;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824dcc38
	if (ctx.cr0.eq) goto loc_824DCC38;
	// lwz r11,332(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222d88
	ctx.lr = 0x824DCC24;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824dcc38
	if (ctx.cr0.eq) goto loc_824DCC38;
	// ld r5,96(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// ld r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// bl 0x82225278
	ctx.lr = 0x824DCC38;
	sub_82225278(ctx, base);
loc_824DCC38:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8273af74
	ctx.lr = 0x824DCC44;
	__restfpr_28(ctx, base);
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82546E10) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r30,r11,3668
	ctx.r30.s64 = ctx.r11.s64 + 3668;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x82546E3C;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82546e50
	if (!ctx.cr0.eq) goto loc_82546E50;
loc_82546E44:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x82546eac
	goto loc_82546EAC;
loc_82546E50:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x82546E60;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82546e44
	if (ctx.cr0.eq) goto loc_82546E44;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r30,r11,1340
	ctx.r30.s64 = ctx.r11.s64 + 1340;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x82546E80;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82546e44
	if (ctx.cr0.eq) goto loc_82546E44;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,15
	ctx.r5.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x82546E98;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82546e44
	if (ctx.cr0.eq) goto loc_82546E44;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
loc_82546EAC:
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

DEFINE_REX_FUNC(sub_8254C188) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8254C190;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
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
	// bne 0x8254c3e8
	if (!ctx.cr0.eq) goto loc_8254C3E8;
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
	// bne cr6,0x8254c290
	if (!ctx.cr6.eq) goto loc_8254C290;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8254c290
	if (ctx.cr6.eq) goto loc_8254C290;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8254c290
	if (ctx.cr0.eq) goto loc_8254C290;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x8254C1F0;
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
loc_8254C290:
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// li r29,-1
	ctx.r29.s64 = -1;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8254c2e4
	if (ctx.cr6.lt) goto loc_8254C2E4;
	// bne cr6,0x8254c36c
	if (!ctx.cr6.eq) goto loc_8254C36C;
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8254c2dc
	if (ctx.cr6.eq) goto loc_8254C2DC;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x8254C2C0;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8254c2d8
	if (ctx.cr0.eq) goto loc_8254C2D8;
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x8254C2D8;
	sub_82222BB0(ctx, base);
loc_8254C2D8:
	// stw r29,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r29.u32);
loc_8254C2DC:
	// stb r28,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r28.u8);
	// b 0x8254c36c
	goto loc_8254C36C;
loc_8254C2E4:
	// lfs f0,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// lfs f13,-3024(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3024);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8254c36c
	if (ctx.cr6.lt) goto loc_8254C36C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,-25368(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25368);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8254c35c
	if (!ctx.cr6.lt) goto loc_8254C35C;
	// lbz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 312);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8254c36c
	if (!ctx.cr0.eq) goto loc_8254C36C;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// li r3,376
	ctx.r3.s64 = 376;
	// stb r28,312(r31)
	REX_STORE_U8(ctx.r31.u32 + 312, ctx.r28.u8);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x82240a58
	ctx.lr = 0x8254C358;
	sub_82240A58(ctx, base);
	// b 0x8254c36c
	goto loc_8254C36C;
loc_8254C35C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r28,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r28.u32);
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
loc_8254C36C:
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8254c3d8
	if (ctx.cr6.eq) goto loc_8254C3D8;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x8254C384;
	sub_82222D88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8254c3d4
	if (ctx.cr0.eq) goto loc_8254C3D4;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
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
	ctx.lr = 0x8254C3A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8254C3D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8254c3d8
	goto loc_8254C3D8;
loc_8254C3D4:
	// stw r29,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r29.u32);
loc_8254C3D8:
	// lbz r11,289(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8254c3e8
	if (ctx.cr0.eq) goto loc_8254C3E8;
	// stb r28,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r28.u8);
loc_8254C3E8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8255B588) {
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
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8255b684
	if (!ctx.cr0.eq) goto loc_8255B684;
	// lbz r11,289(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8255b5bc
	if (ctx.cr0.eq) goto loc_8255B5BC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
loc_8255B5BC:
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x824443c8
	ctx.lr = 0x8255B5C4;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8255b684
	if (ctx.cr0.eq) goto loc_8255B684;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x8255B5D4;
	sub_82430A88(ctx, base);
	// lbz r11,332(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 332);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// beq 0x8255b5f0
	if (ctx.cr0.eq) goto loc_8255B5F0;
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// lfs f12,236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8255b5f4
	goto loc_8255B5F4;
loc_8255B5F0:
	// lfs f12,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f12.f64 = double(temp.f32);
loc_8255B5F4:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r11,r11,-31344
	ctx.r11.s64 = ctx.r11.s64 + -31344;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,1608(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f11,340(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// stfs f0,336(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 336, temp.u32);
loc_8255B684:
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

DEFINE_REX_FUNC(sub_825658C8) {
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
	// lhz r10,6(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r9,140(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// addi r30,r11,-8644
	ctx.r30.s64 = ctx.r11.s64 + -8644;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-8644(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,-3580(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -3580);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256592C;
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
	ctx.lr = 0x82565948;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82565978
	if (!ctx.cr6.lt) goto loc_82565978;
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
	ctx.lr = 0x82565978;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82565978:
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,-20164(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -20164);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f31,72(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stb r11,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r11.u8);
	// lfs f0,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,52(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r3,280(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// bl 0x82453a68
	ctx.lr = 0x825659CC;
	sub_82453A68(ctx, base);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,92(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82240a58
	ctx.lr = 0x825659D8;
	sub_82240A58(ctx, base);
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

DEFINE_REX_FUNC(sub_82570508) {
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
	// bl 0x82570560
	ctx.lr = 0x82570528;
	sub_82570560(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82570540
	if (ctx.cr0.eq) goto loc_82570540;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82570540
	if (ctx.cr6.eq) goto loc_82570540;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82570540;
	sub_825E0378(ctx, base);
loc_82570540:
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

DEFINE_REX_FUNC(sub_82571778) {
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
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f11,300(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 300);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addi r8,r10,9476
	ctx.r8.s64 = ctx.r10.s64 + 9476;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f12,9476(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9476);
	ctx.f12.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f13,12468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f0,-19744(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -19744);
	ctx.f0.f64 = double(temp.f32);
	// li r3,109
	ctx.r3.s64 = 109;
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f0,68(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 68, temp.u32);
	// stfs f13,72(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 72, temp.u32);
	// stb r7,116(r11)
	REX_STORE_U8(ctx.r11.u32 + 116, ctx.r7.u8);
	// lfs f0,300(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// stfs f0,52(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 52, temp.u32);
	// ld r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 44);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8257d438
	ctx.lr = 0x825717DC;
	sub_8257D438(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825736F8) {
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
	// lhz r10,6(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r9,124(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// addi r30,r11,-8644
	ctx.r30.s64 = ctx.r11.s64 + -8644;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-8644(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,-900(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -900);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8257375C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
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
	ctx.lr = 0x82573778;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x825737a8
	if (!ctx.cr6.lt) goto loc_825737A8;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
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
	ctx.lr = 0x825737A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825737A8:
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f31,72(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lfs f0,-20164(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -20164);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// lfs f0,-21484(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -21484);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r11.u8);
	// lfs f13,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,52(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lwz r3,280(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// bl 0x82453a68
	ctx.lr = 0x82573804;
	sub_82453A68(ctx, base);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,92(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82240a58
	ctx.lr = 0x82573810;
	sub_82240A58(ctx, base);
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

DEFINE_REX_FUNC(sub_8257AF58) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-12852(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12852);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257af88
	if (ctx.cr6.eq) goto loc_8257AF88;
	// bl 0x8257c0b0
	ctx.lr = 0x8257AF80;
	sub_8257C0B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x8257af94
	goto loc_8257AF94;
loc_8257AF88:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// ld r11,3456(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_8257AF94:
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

DEFINE_REX_FUNC(sub_8257CBF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r12,r1,-16
	ctx.r12.s64 = ctx.r1.s64 + -16;
	// bl 0x8273af28
	ctx.lr = 0x8257CC04;
	__savefpr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-15444(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15444);
	// lwz r10,-15432(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15432);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f31,f13
	ctx.f31.f64 = double(float(ctx.f13.f64));
	// frsp f30,f0
	ctx.f30.f64 = double(float(ctx.f0.f64));
	// bl 0x82577228
	ctx.lr = 0x8257CC44;
	sub_82577228(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f29,f0,f28
	ctx.f29.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// bl 0x82577290
	ctx.lr = 0x8257CC60;
	sub_82577290(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// fsubs f13,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f29.f64));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// fsubs f12,f30,f0
	ctx.f12.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x8257ccac
	if (!ctx.cr6.gt) goto loc_8257CCAC;
	// fsubs f13,f29,f31
	ctx.f13.f64 = double(float(ctx.f29.f64 - ctx.f31.f64));
	// lfs f0,14376(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// b 0x8257ccbc
	goto loc_8257CCBC;
loc_8257CCAC:
	// fsubs f13,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// lfs f0,14376(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
loc_8257CCBC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-16
	ctx.r12.s64 = ctx.r1.s64 + -16;
	// bl 0x8273af74
	ctx.lr = 0x8257CCCC;
	__restfpr_28(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82583180) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82583188;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r28,r3,28
	ctx.r28.s64 = ctx.r3.s64 + 28;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,25
	ctx.r30.s64 = 25;
	// addi r29,r28,-4
	ctx.r29.s64 = ctx.r28.s64 + -4;
loc_825831A4:
	// lwzu r3,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// bl 0x823bdef8
	ctx.lr = 0x825831AC;
	sub_823BDEF8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x825831a4
	if (!ctx.cr0.eq) goto loc_825831A4;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_825831C4:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r8,0(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne 0x825831e8
	if (!ctx.cr0.eq) goto loc_825831E8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplwi cr6,r10,25
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 25, ctx.xer);
	// blt cr6,0x825831c4
	if (ctx.cr6.lt) goto loc_825831C4;
	// b 0x825831ec
	goto loc_825831EC;
loc_825831E8:
	// li r9,1
	ctx.r9.s64 = 1;
loc_825831EC:
	// clrlwi. r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825833ac
	if (!ctx.cr0.eq) goto loc_825833AC;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82583208;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825833ac
	if (ctx.cr0.eq) goto loc_825833AC;
	// lwz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r30,r11,12472
	ctx.r30.s64 = ctx.r11.s64 + 12472;
	// lwz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f0,-4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,20(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82583298
	if (ctx.cr6.eq) goto loc_82583298;
	// bl 0x82444358
	ctx.lr = 0x82583234;
	sub_82444358(ctx, base);
	// cmplw cr6,r5,r3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x82583248
	if (!ctx.cr6.eq) goto loc_82583248;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,-23056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23056);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82583298
	goto loc_82583298;
loc_82583248:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258327c
	if (ctx.cr6.eq) goto loc_8258327C;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82583260:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x82583280
	if (ctx.cr6.eq) goto loc_82583280;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// blt cr6,0x82583260
	if (ctx.cr6.lt) goto loc_82583260;
loc_8258327C:
	// li r11,-1
	ctx.r11.s64 = -1;
loc_82583280:
	// mulli r11,r11,10
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(10));
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
loc_82583298:
	// stfs f0,28(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 28, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82583a38
	ctx.lr = 0x825832A4;
	sub_82583A38(ctx, base);
	// lbz r11,393(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 393);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8258334c
	if (ctx.cr6.lt) goto loc_8258334C;
	// beq cr6,0x82583320
	if (ctx.cr6.eq) goto loc_82583320;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x825832fc
	if (ctx.cr6.lt) goto loc_825832FC;
	// beq cr6,0x825832c8
	if (ctx.cr6.eq) goto loc_825832C8;
	// stb r29,393(r31)
	REX_STORE_U8(ctx.r31.u32 + 393, ctx.r29.u8);
	// b 0x825833ac
	goto loc_825833AC;
loc_825832C8:
	// lfs f0,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f13,132(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// stb r29,363(r31)
	REX_STORE_U8(ctx.r31.u32 + 363, ctx.r29.u8);
	// lfs f0,7528(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7528);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x825833ac
	if (ctx.cr6.lt) goto loc_825833AC;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stb r29,393(r31)
	REX_STORE_U8(ctx.r31.u32 + 393, ctx.r29.u8);
	// stfs f13,128(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// stfs f0,132(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// b 0x825833ac
	goto loc_825833AC;
loc_825832FC:
	// lbz r11,363(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 363);
	// stb r29,362(r31)
	REX_STORE_U8(ctx.r31.u32 + 362, ctx.r29.u8);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825833ac
	if (ctx.cr0.eq) goto loc_825833AC;
	// lfs f0,-4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// li r11,3
	ctx.r11.s64 = 3;
	// stfs f0,132(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// stb r29,363(r31)
	REX_STORE_U8(ctx.r31.u32 + 363, ctx.r29.u8);
	// b 0x82583344
	goto loc_82583344;
loc_82583320:
	// lfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stb r29,362(r31)
	REX_STORE_U8(ctx.r31.u32 + 362, ctx.r29.u8);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// lfs f0,3184(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 3184);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,128(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x825833ac
	if (ctx.cr6.lt) goto loc_825833AC;
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// li r11,2
	ctx.r11.s64 = 2;
loc_82583344:
	// stb r11,393(r31)
	REX_STORE_U8(ctx.r31.u32 + 393, ctx.r11.u8);
	// b 0x825833ac
	goto loc_825833AC;
loc_8258334C:
	// lbz r11,362(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 362);
	// stb r29,363(r31)
	REX_STORE_U8(ctx.r31.u32 + 363, ctx.r29.u8);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825833ac
	if (ctx.cr0.eq) goto loc_825833AC;
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,-4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stb r29,362(r31)
	REX_STORE_U8(ctx.r31.u32 + 362, ctx.r29.u8);
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// stb r11,393(r31)
	REX_STORE_U8(ctx.r31.u32 + 393, ctx.r11.u8);
	// stfs f13,132(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// bl 0x82213210
	ctx.lr = 0x8258337C;
	sub_82213210(ctx, base);
	// lwz r10,356(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r3,4132
	ctx.r11.s64 = ctx.r3.s64 + 4132;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8258339c
	if (!ctx.cr6.eq) goto loc_8258339C;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x825833a8
	goto loc_825833A8;
loc_8258339C:
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
loc_825833A8:
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
loc_825833AC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82591B08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82591B10;
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
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r30,r3,16
	ctx.r30.s64 = ctx.r3.s64 + 16;
	// li r31,2
	ctx.r31.s64 = 2;
loc_82591B28:
	// lwzu r3,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// bl 0x823bdef8
	ctx.lr = 0x82591B30;
	sub_823BDEF8(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82591b28
	if (!ctx.cr0.eq) goto loc_82591B28;
	// lwz r3,16(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82591B4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82591c90
	if (ctx.cr0.eq) goto loc_82591C90;
	// bl 0x82213210
	ctx.lr = 0x82591B58;
	sub_82213210(ctx, base);
	// lbz r11,4157(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4157);
	// lwz r10,16(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addic r8,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// subfe r11,r8,r11
	temp.u8 = (~ctx.r8.u32 + ctx.r11.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r8.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,53(r29)
	REX_STORE_U8(ctx.r29.u32 + 53, ctx.r11.u8);
	// lfs f0,1640(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1640);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r5,20(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82591bf0
	if (ctx.cr6.eq) goto loc_82591BF0;
	// bl 0x82444358
	ctx.lr = 0x82591B88;
	sub_82444358(ctx, base);
	// cmplw cr6,r5,r3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x82591b9c
	if (!ctx.cr6.eq) goto loc_82591B9C;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f0,1644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1644);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82591bf0
	goto loc_82591BF0;
loc_82591B9C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82591bd0
	if (ctx.cr6.eq) goto loc_82591BD0;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// li r11,0
	ctx.r11.s64 = 0;
loc_82591BB4:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x82591bd4
	if (ctx.cr6.eq) goto loc_82591BD4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// blt cr6,0x82591bb4
	if (ctx.cr6.lt) goto loc_82591BB4;
loc_82591BD0:
	// li r11,-1
	ctx.r11.s64 = -1;
loc_82591BD4:
	// mulli r11,r11,10
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(10));
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
loc_82591BF0:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stfs f0,28(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 28, temp.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lwa r8,-15432(r10)
	ctx.r8.s64 = int32_t(REX_LOAD_U32(ctx.r10.u32 + -15432));
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lwz r10,-12872(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -12872);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lfs f0,1772(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1772);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// beq cr6,0x82591c34
	if (ctx.cr6.eq) goto loc_82591C34;
	// lfs f0,664(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 664);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82591c38
	goto loc_82591C38;
loc_82591C34:
	// lfs f0,-232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
loc_82591C38:
	// fmuls f12,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,28(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,40(r29)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r29.u32 + 40, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82591c68
	if (ctx.cr6.lt) goto loc_82591C68;
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f0,1812(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1812);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,28(r29)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r29.u32 + 28, temp.u32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// ble cr6,0x82591c68
	if (!ctx.cr6.gt) goto loc_82591C68;
	// stfs f0,28(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 28, temp.u32);
loc_82591C68:
	// lfs f0,32(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82591c90
	if (ctx.cr6.lt) goto loc_82591C90;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// stfs f13,32(r29)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r29.u32 + 32, temp.u32);
	// lfs f0,8392(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8392);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82591c90
	if (!ctx.cr6.gt) goto loc_82591C90;
	// stfs f0,32(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 32, temp.u32);
loc_82591C90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8259E828) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r3,64
	ctx.r3.s64 = ctx.r3.s64 + 64;
	// addi r11,r11,15900
	ctx.r11.s64 = ctx.r11.s64 + 15900;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x825d7d20
	ctx.lr = 0x8259E850;
	sub_825D7D20(ctx, base);
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

DEFINE_REX_FUNC(sub_825A1040) {
	REX_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,9(r3)
	REX_STORE_U8(ctx.r3.u32 + 9, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825A1208) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x825e02a0
	ctx.lr = 0x825A1238;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x825a1274
	if (ctx.cr0.eq) goto loc_825A1274;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,15948
	ctx.r10.s64 = ctx.r10.s64 + 15948;
	// stb r11,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stb r11,9(r31)
	REX_STORE_U8(ctx.r31.u32 + 9, ctx.r11.u8);
	// stb r11,10(r31)
	REX_STORE_U8(ctx.r31.u32 + 10, ctx.r11.u8);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// bl 0x825a1050
	ctx.lr = 0x825A126C;
	sub_825A1050(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x825a1278
	goto loc_825A1278;
loc_825A1274:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825A1278:
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

DEFINE_REX_FUNC(sub_825A4750) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x825A4758;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// lwz r31,-12792(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + -12792);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x825a478c
	goto loc_825A478C;
loc_825A4770:
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpw cr6,r9,r3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x825a4784
	if (!ctx.cr6.lt) goto loc_825A4784;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x825a478c
	goto loc_825A478C;
loc_825A4784:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_825A478C:
	// lbz r9,21(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x825a4770
	if (ctx.cr0.eq) goto loc_825A4770;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825a47bc
	if (ctx.cr6.eq) goto loc_825A47BC;
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmpw cr6,r3,r10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x825a47bc
	if (ctx.cr6.lt) goto loc_825A47BC;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// b 0x825a47c4
	goto loc_825A47C4;
loc_825A47BC:
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
loc_825A47C4:
	// lwz r30,0(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825a4810
	if (ctx.cr6.eq) goto loc_825A4810;
	// lwz r3,16(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825a47f8
	if (ctx.cr6.eq) goto loc_825A47F8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A47F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r31,-12792(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + -12792);
loc_825A47F8:
	// stw r28,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r28.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x825a1bd8
	ctx.lr = 0x825A480C;
	sub_825A1BD8(ctx, base);
	// lwz r31,-12792(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + -12792);
loc_825A4810:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825a48a4
	if (!ctx.cr6.eq) goto loc_825A48A4;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lbz r11,21(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 21);
	// b 0x825a4858
	goto loc_825A4858;
loc_825A4830:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,8(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// bl 0x82360500
	ctx.lr = 0x825A483C;
	sub_82360500(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r29,0(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// beq cr6,0x825a4850
	if (ctx.cr6.eq) goto loc_825A4850;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825e0378
	ctx.lr = 0x825A4850;
	sub_825E0378(ctx, base);
loc_825A4850:
	// lbz r11,21(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 21);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_825A4858:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825a4830
	if (ctx.cr0.eq) goto loc_825A4830;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
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
	// beq cr6,0x825a488c
	if (ctx.cr6.eq) goto loc_825A488C;
	// bl 0x825e0378
	ctx.lr = 0x825A488C;
	sub_825E0378(ctx, base);
loc_825A488C:
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// bl 0x825e0378
	ctx.lr = 0x825A489C;
	sub_825E0378(ctx, base);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,-12792(r27)
	REX_STORE_U32(ctx.r27.u32 + -12792, ctx.r28.u32);
loc_825A48A4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825AE720) {
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
	// bl 0x825ae808
	ctx.lr = 0x825AE740;
	sub_825AE808(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825ae758
	if (ctx.cr0.eq) goto loc_825AE758;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825ae758
	if (ctx.cr6.eq) goto loc_825AE758;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x825AE758;
	sub_825E0378(ctx, base);
loc_825AE758:
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

DEFINE_REX_FUNC(sub_825AF578) {
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
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// lfs f0,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,19(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 19);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r8,16(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 16);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lbz r7,17(r3)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r3.u32 + 17);
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lwz r6,44(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lbz r11,18(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 18);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwz r5,12(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// stfs f13,36(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stb r10,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r10.u8);
	// stb r11,22(r3)
	REX_STORE_U8(ctx.r3.u32 + 22, ctx.r11.u8);
	// stb r9,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// stb r8,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r8.u8);
	// stb r7,21(r3)
	REX_STORE_U8(ctx.r3.u32 + 21, ctx.r7.u8);
	// fctidz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lbz r4,87(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// stb r4,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r4.u8);
	// stw r5,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r5.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825AF5FC;
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

DEFINE_REX_FUNC(sub_825B4270) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee4
	ctx.lr = 0x825B4278;
	__savegprlr_15(ctx, base);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r16,r3,204
	ctx.r16.s64 = ctx.r3.s64 + 204;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// mr r20,r8
	ctx.r20.u64 = ctx.r8.u64;
	// mr r19,r9
	ctx.r19.u64 = ctx.r9.u64;
	// mr r15,r10
	ctx.r15.u64 = ctx.r10.u64;
	// bl 0x82855b44
	ctx.lr = 0x825B42A8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x825b3350
	ctx.lr = 0x825B42B0;
	sub_825B3350(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// bl 0x82763e80
	ctx.lr = 0x825B42BC;
	sub_82763E80(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x825b42e4
	if (ctx.cr6.lt) goto loc_825B42E4;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,1
	ctx.r6.s64 = 1;
	// lis r5,-32768
	ctx.r5.s64 = -2147483648;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// bl 0x82763f10
	ctx.lr = 0x825B42E0;
	sub_82763F10(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_825B42E4:
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x827627b8
	ctx.lr = 0x825B42EC;
	sub_827627B8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// mr r17,r29
	ctx.r17.u64 = ctx.r29.u64;
	// blt cr6,0x825b430c
	if (ctx.cr6.lt) goto loc_825B430C;
	// addi r4,r1,200
	ctx.r4.s64 = ctx.r1.s64 + 200;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82763918
	ctx.lr = 0x825B4308;
	sub_82763918(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_825B430C:
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// stw r29,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// stw r29,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// stw r29,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r29.u32);
	// sth r29,16(r11)
	REX_STORE_U16(ctx.r11.u32 + 16, ctx.r29.u16);
	// blt cr6,0x825b437c
	if (ctx.cr6.lt) goto loc_825B437C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,18
	ctx.r5.s64 = 18;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// li r17,1
	ctx.r17.s64 = 1;
	// bl 0x82762810
	ctx.lr = 0x825B4344;
	sub_82762810(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b437c
	if (ctx.cr6.lt) goto loc_825B437C;
	// lhz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 176);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x825b437c
	if (ctx.cr6.eq) goto loc_825B437C;
	// cmplwi cr6,r11,357
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 357, ctx.xer);
	// beq cr6,0x825b437c
	if (ctx.cr6.eq) goto loc_825B437C;
	// cmplwi cr6,r11,353
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 353, ctx.xer);
	// beq cr6,0x825b437c
	if (ctx.cr6.eq) goto loc_825B437C;
	// cmplwi cr6,r11,354
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 354, ctx.xer);
	// beq cr6,0x825b437c
	if (ctx.cr6.eq) goto loc_825B437C;
	// lis r31,-30009
	ctx.r31.s64 = -1966669824;
	// ori r31,r31,7
	ctx.r31.u64 = ctx.r31.u64 | 7;
loc_825B437C:
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x825b4390
	if (ctx.cr6.lt) goto loc_825B4390;
	// lwz r28,276(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_825B4390:
	// addi r11,r1,132
	ctx.r11.s64 = ctx.r1.s64 + 132;
	// stw r29,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
	// lis r10,8324
	ctx.r10.s64 = 545521664;
	// stw r29,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r29.u32);
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
	// ori r18,r10,6
	ctx.r18.u64 = ctx.r10.u64 | 6;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// stw r29,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// stw r29,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// stw r29,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r29.u32);
	// stw r29,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r29.u32);
	// blt cr6,0x825b4928
	if (ctx.cr6.lt) goto loc_825B4928;
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r29,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// addi r11,r1,143
	ctx.r11.s64 = ctx.r1.s64 + 143;
	// stw r28,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r28.u32);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_825B43DC:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x825b43dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825B43DC;
	// lhz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 176);
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// ori r26,r10,14
	ctx.r26.u64 = ctx.r10.u64 | 14;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x825b4480
	if (!ctx.cr6.eq) goto loc_825B4480;
	// lhz r11,190(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 190);
	// addi r5,r1,148
	ctx.r5.s64 = ctx.r1.s64 + 148;
	// lwz r10,180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lhz r9,188(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 188);
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// clrlwi r8,r10,14
	ctx.r8.u64 = ctx.r10.u32 & 0x3FFFF;
	// lwz r7,128(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lhz r6,178(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 178);
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// divwu r3,r28,r10
	ctx.r3.u64 = uint32_t(ctx.r10.u32 ? ctx.r28.u32 / ctx.r10.u32 : 0);
	// subfe r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r7,r3,4,0,27
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0) | (ctx.r7.u64 & 0xFFFFFFFF0000000F);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// stw r7,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r7.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// or r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 | ctx.r8.u64;
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// rlwimi r8,r10,18,6,13
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 18) & 0x3FC0000) | (ctx.r8.u64 & 0xFFFFFFFFFC03FFFF);
	// rlwimi r6,r8,3,0,28
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8) | (ctx.r6.u64 & 0xFFFFFFFF00000007);
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r7,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// bl 0x82763ce0
	ctx.lr = 0x825B4458;
	sub_82763CE0(ctx, base);
	// lhz r3,188(r1)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r1.u32 + 188);
	// lwz r5,144(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// twllei r3,0
	if (ctx.r3.s32 == 0 || ctx.r3.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r11,r5,r3
	ctx.r11.u64 = uint32_t(ctx.r3.u32 ? ctx.r5.u32 / ctx.r3.u32 : 0);
	// divwu r10,r4,r3
	ctx.r10.u64 = uint32_t(ctx.r3.u32 ? ctx.r4.u32 / ctx.r3.u32 : 0);
	// twllei r3,0
	if (ctx.r3.s32 == 0 || ctx.r3.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// stw r10,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// b 0x825b4790
	goto loc_825B4790;
loc_825B4480:
	// cmplwi cr6,r11,353
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 353, ctx.xer);
	// beq cr6,0x825b4610
	if (ctx.cr6.eq) goto loc_825B4610;
	// cmplwi cr6,r11,354
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 354, ctx.xer);
	// beq cr6,0x825b4610
	if (ctx.cr6.eq) goto loc_825B4610;
	// cmplwi cr6,r11,357
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 357, ctx.xer);
	// bne cr6,0x825b4790
	if (!ctx.cr6.eq) goto loc_825B4790;
	// stw r29,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r29.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82762e68
	ctx.lr = 0x825B44A8;
	sub_82762E68(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b4928
	if (ctx.cr6.lt) goto loc_825B4928;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// lwz r3,160(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// bl 0x8263b678
	ctx.lr = 0x825B44C4;
	sub_8263B678(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825b44d8
	if (!ctx.cr6.eq) goto loc_825B44D8;
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// b 0x825b45f4
	goto loc_825B45F4;
loc_825B44D8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r5,160(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82762ee0
	ctx.lr = 0x825B44E8;
	sub_82762EE0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b45f4
	if (ctx.cr6.lt) goto loc_825B45F4;
	// lbz r8,1(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 1);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x825b4530
	if (ctx.cr6.eq) goto loc_825B4530;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_825B4508:
	// addi r9,r11,10
	ctx.r9.s64 = ctx.r11.s64 + 10;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// lbzx r9,r6,r30
	ctx.r9.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r30.u32);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// blt cr6,0x825b4508
	if (ctx.cr6.lt) goto loc_825B4508;
loc_825B4530:
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// rlwinm r9,r10,24,0,7
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF000000;
	// rlwinm r8,r10,2,27,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x1C;
	// lwz r7,128(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// rlwinm r6,r11,0,9,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FFFE0;
	// stw r29,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r29.u32);
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// or r11,r5,r6
	ctx.r11.u64 = ctx.r5.u64 | ctx.r6.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stw r11,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// rlwimi r11,r10,5,9,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0x7FFFE0) | (ctx.r11.u64 & 0xFFFFFFFFFF80001F);
	// stw r11,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// lwz r9,28(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// rlwimi r7,r9,4,0,27
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0) | (ctx.r7.u64 & 0xFFFFFFFF0000000F);
	// stw r7,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r7.u32);
	// lwz r8,4(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r8,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// lwz r7,8(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r6,4(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r5,r6,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r6.u64;
	// stw r5,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r5.u32);
	// bl 0x82762f60
	ctx.lr = 0x825B4598;
	sub_82762F60(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b45f4
	if (ctx.cr6.lt) goto loc_825B45F4;
	// lwz r11,156(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b45d4
	if (ctx.cr6.eq) goto loc_825B45D4;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// stw r3,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r3.u32);
	// bl 0x8263b678
	ctx.lr = 0x825B45C0;
	sub_8263B678(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825b45d4
	if (!ctx.cr6.eq) goto loc_825B45D4;
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// b 0x825b45f4
	goto loc_825B45F4;
loc_825B45D4:
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// addi r4,r27,4
	ctx.r4.s64 = ctx.r27.s64 + 4;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// lwz r10,156(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// addi r5,r10,-4
	ctx.r5.s64 = ctx.r10.s64 + -4;
	// bl 0x82762fd8
	ctx.lr = 0x825B45F0;
	sub_82762FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_825B45F4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825b4790
	if (ctx.cr6.eq) goto loc_825B4790;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// bl 0x8263b710
	ctx.lr = 0x825B460C;
	sub_8263B710(ctx, base);
	// b 0x825b4790
	goto loc_825B4790;
loc_825B4610:
	// addi r11,r11,-353
	ctx.r11.s64 = ctx.r11.s64 + -353;
	// lwz r10,180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lhz r8,188(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 188);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addic r7,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// lhz r6,178(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 178);
	// clrlwi r5,r10,14
	ctx.r5.u64 = ctx.r10.u32 & 0x3FFFF;
	// lwz r4,128(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// subfe r3,r7,r11
	temp.u8 = (~ctx.r7.u32 + ctx.r11.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r7.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r29,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r29.u32);
	// rlwinm r8,r3,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 26) & 0xFC000000;
	// rlwinm r3,r11,0,1,8
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7F800000;
	// or r5,r8,r5
	ctx.r5.u64 = ctx.r8.u64 | ctx.r5.u64;
	// divwu r7,r28,r10
	ctx.r7.u64 = uint32_t(ctx.r10.u32 ? ctx.r28.u32 / ctx.r10.u32 : 0);
	// rlwimi r6,r5,3,0,28
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8) | (ctx.r6.u64 & 0xFFFFFFFF00000007);
	// rlwimi r4,r7,4,0,27
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0) | (ctx.r4.u64 & 0xFFFFFFFF0000000F);
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,7460
	ctx.r9.s64 = ctx.r9.s64 + 7460;
	// stw r4,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r4.u32);
	// or r8,r11,r3
	ctx.r8.u64 = ctx.r11.u64 | ctx.r3.u64;
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// ori r6,r8,3
	ctx.r6.u64 = ctx.r8.u64 | 3;
	// addi r11,r9,28
	ctx.r11.s64 = ctx.r9.s64 + 28;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
loc_825B4680:
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x825b46a0
	if (ctx.cr6.eq) goto loc_825B46A0;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplwi cr6,r7,17
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 17, ctx.xer);
	// blt cr6,0x825b4680
	if (ctx.cr6.lt) goto loc_825B4680;
	// b 0x825b46dc
	goto loc_825B46DC;
loc_825B46A0:
	// cmplwi cr6,r7,17
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 17, ctx.xer);
	// bge cr6,0x825b46dc
	if (!ctx.cr6.lt) goto loc_825B46DC;
	// lwz r11,184(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
loc_825B46AC:
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x825b46cc
	if (ctx.cr6.eq) goto loc_825B46CC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplwi cr6,r8,7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 7, ctx.xer);
	// blt cr6,0x825b46ac
	if (ctx.cr6.lt) goto loc_825B46AC;
	// b 0x825b46dc
	goto loc_825B46DC;
loc_825B46CC:
	// cmplwi cr6,r8,7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 7, ctx.xer);
	// bge cr6,0x825b46dc
	if (!ctx.cr6.lt) goto loc_825B46DC;
	// rlwinm r11,r8,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// or r5,r11,r7
	ctx.r5.u64 = ctx.r11.u64 | ctx.r7.u64;
loc_825B46DC:
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// addi r5,r1,148
	ctx.r5.s64 = ctx.r1.s64 + 148;
	// rlwimi r6,r11,23,1,8
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 23) & 0x7F800000) | (ctx.r6.u64 & 0xFFFFFFFF807FFFFF);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stw r6,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r6.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82763ce0
	ctx.lr = 0x825B46F8;
	sub_82763CE0(ctx, base);
	// lhz r7,188(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 188);
	// lwz r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// lwz r8,148(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// divwu r6,r9,r7
	ctx.r6.u64 = uint32_t(ctx.r7.u32 ? ctx.r9.u32 / ctx.r7.u32 : 0);
	// divwu r5,r8,r7
	ctx.r5.u64 = uint32_t(ctx.r7.u32 ? ctx.r8.u32 / ctx.r7.u32 : 0);
	// stw r6,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// twllei r7,0
	if (ctx.r7.s32 == 0 || ctx.r7.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r5,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r5.u32);
	// twllei r7,0
	if (ctx.r7.s32 == 0 || ctx.r7.u32 < 0u) ppc_trap(ctx, base, 0);
	// bl 0x82762f60
	ctx.lr = 0x825B4728;
	sub_82762F60(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b4928
	if (ctx.cr6.lt) goto loc_825B4928;
	// lwz r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b476c
	if (ctx.cr6.eq) goto loc_825B476C;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// stw r3,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r3.u32);
	// bl 0x8263b678
	ctx.lr = 0x825B4750;
	sub_8263B678(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825b4768
	if (!ctx.cr6.eq) goto loc_825B4768;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x825b4928
	goto loc_825B4928;
loc_825B4768:
	// lwz r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
loc_825B476C:
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// addi r4,r27,4
	ctx.r4.s64 = ctx.r27.s64 + 4;
	// rlwinm r10,r11,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// lwz r9,152(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// addi r5,r9,-4
	ctx.r5.s64 = ctx.r9.s64 + -4;
	// bl 0x82762fd8
	ctx.lr = 0x825B478C;
	sub_82762FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_825B4790:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x825b4928
	if (ctx.cr6.lt) goto loc_825B4928;
	// clrlwi r11,r23,16
	ctx.r11.u64 = ctx.r23.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825b4858
	if (!ctx.cr6.eq) goto loc_825B4858;
	// lis r4,-21628
	ctx.r4.s64 = -1417412608;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// ori r4,r4,5
	ctx.r4.u64 = ctx.r4.u64 | 5;
	// bl 0x8263b678
	ctx.lr = 0x825B47B4;
	sub_8263B678(ctx, base);
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r29,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r29.u32);
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r31,r9,r26
	ctx.r31.u64 = ctx.r9.u64 & ctx.r26.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x825b483c
	if (ctx.cr6.lt) goto loc_825B483C;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r7,r1,196
	ctx.r7.s64 = ctx.r1.s64 + 196;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82763d60
	ctx.lr = 0x825B47E8;
	sub_82763D60(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b483c
	if (ctx.cr6.lt) goto loc_825B483C;
	// lwz r3,256(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 256);
	// addi r11,r1,164
	ctx.r11.s64 = ctx.r1.s64 + 164;
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
	// ld r5,128(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// ld r6,136(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// ori r4,r21,1
	ctx.r4.u64 = ctx.r21.u64 | 1;
	// ld r7,144(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stb r19,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r19.u8);
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825B4830;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x825b4910
	if (!ctx.cr6.lt) goto loc_825B4910;
loc_825B483C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825b4908
	if (ctx.cr6.eq) goto loc_825B4908;
	// lis r4,-21628
	ctx.r4.s64 = -1417412608;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r4,r4,5
	ctx.r4.u64 = ctx.r4.u64 | 5;
	// bl 0x8263b710
	ctx.lr = 0x825B4854;
	sub_8263B710(ctx, base);
	// b 0x825b4908
	goto loc_825B4908;
loc_825B4858:
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lwz r31,272(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// bl 0x82762888
	ctx.lr = 0x825B4864;
	sub_82762888(ctx, base);
	// lis r8,24576
	ctx.r8.s64 = 1610612736;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r8,r8,128
	ctx.r8.u64 = ctx.r8.u64 | 128;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mr r17,r29
	ctx.r17.u64 = ctx.r29.u64;
	// bl 0x8263a9c0
	ctx.lr = 0x825B488C;
	sub_8263A9C0(ctx, base);
	// stw r31,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r31.u32);
	// stw r3,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r3.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,260(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 260);
	// addi r11,r1,164
	ctx.r11.s64 = ctx.r1.s64 + 164;
	// stw r29,216(r1)
	REX_STORE_U32(ctx.r1.u32 + 216, ctx.r29.u32);
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// ori r4,r21,17
	ctx.r4.u64 = ctx.r21.u64 | 17;
	// sth r23,220(r1)
	REX_STORE_U16(ctx.r1.u32 + 220, ctx.r23.u16);
	// ld r9,216(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 216);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// ld r5,128(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// ld r6,136(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// ld r7,144(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// stb r19,111(r1)
	REX_STORE_U8(ctx.r1.u32 + 111, ctx.r19.u8);
	// lwz r11,148(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 148);
	// stw r20,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r20.u32);
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// ld r8,208(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 208);
	// bctrl 
	ctx.lr = 0x825B48E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x825b4910
	if (!ctx.cr6.lt) goto loc_825B4910;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825b4908
	if (ctx.cr6.eq) goto loc_825B4908;
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x825b4908
	if (ctx.cr6.eq) goto loc_825B4908;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8263a978
	ctx.lr = 0x825B4908;
	sub_8263A978(ctx, base);
loc_825B4908:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x825b4928
	if (ctx.cr6.lt) goto loc_825B4928;
loc_825B4910:
	// lwz r11,164(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// bne cr6,0x825b4924
	if (!ctx.cr6.eq) goto loc_825B4924;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_825B4924:
	// stw r11,0(r15)
	REX_STORE_U32(ctx.r15.u32 + 0, ctx.r11.u32);
loc_825B4928:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x825b4938
	if (ctx.cr6.eq) goto loc_825B4938;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82762888
	ctx.lr = 0x825B4938;
	sub_82762888(ctx, base);
loc_825B4938:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge cr6,0x825b4954
	if (!ctx.cr6.lt) goto loc_825B4954;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x825b4954
	if (ctx.cr6.eq) goto loc_825B4954;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8263b710
	ctx.lr = 0x825B4954;
	sub_8263B710(ctx, base);
loc_825B4954:
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82762958
	ctx.lr = 0x825B495C;
	sub_82762958(ctx, base);
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// bl 0x82763eb8
	ctx.lr = 0x825B4964;
	sub_82763EB8(ctx, base);
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x82855b34
	ctx.lr = 0x825B496C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x82739f34
	__restgprlr_15(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E8960) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825E8968;
	__savegprlr_29(ctx, base);
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
	// addi r10,r10,23560
	ctx.r10.s64 = ctx.r10.s64 + 23560;
	// stw r8,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// addi r9,r9,23612
	ctx.r9.s64 = ctx.r9.s64 + 23612;
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
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x825e54c0
	ctx.lr = 0x825E89AC;
	sub_825E54C0(ctx, base);
	// addi r11,r31,92
	ctx.r11.s64 = ctx.r31.s64 + 92;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r9,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// lwz r9,8(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// stw r9,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// lhz r9,4(r29)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r29.u32 + 4);
	// sth r9,76(r31)
	REX_STORE_U16(ctx.r31.u32 + 76, ctx.r9.u16);
	// lbz r9,6(r29)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r29.u32 + 6);
	// stb r9,78(r31)
	REX_STORE_U8(ctx.r31.u32 + 78, ctx.r9.u8);
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// stw r10,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// beq cr6,0x825e8a08
	if (ctx.cr6.eq) goto loc_825E8A08;
	// addi r10,r30,4
	ctx.r10.s64 = ctx.r30.s64 + 4;
loc_825E89EC:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r10
	ea = ctx.r10.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwcx. r9,0,r10
	ea = ctx.r10.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825e89ec
	if (!ctx.cr0.eq) goto loc_825E89EC;
loc_825E8A08:
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r10,r10,23904
	ctx.r10.s64 = ctx.r10.s64 + 23904;
	// addi r9,r9,23956
	ctx.r9.s64 = ctx.r9.s64 + 23956;
	// addi r8,r8,23640
	ctx.r8.s64 = ctx.r8.s64 + 23640;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825ED798) {
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
	// bl 0x825ec180
	ctx.lr = 0x825ED7B8;
	sub_825EC180(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825ed7d0
	if (ctx.cr0.eq) goto loc_825ED7D0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825ed7d0
	if (ctx.cr6.eq) goto loc_825ED7D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x825ED7D0;
	sub_825E0378(ctx, base);
loc_825ED7D0:
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

DEFINE_REX_FUNC(sub_825F1950) {
	REX_FUNC_PROLOGUE();
	// stw r4,200(r3)
	REX_STORE_U32(ctx.r3.u32 + 200, ctx.r4.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825F19B0) {
	REX_FUNC_PROLOGUE();
	// stw r4,204(r3)
	REX_STORE_U32(ctx.r3.u32 + 204, ctx.r4.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825F1E38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825F1E40;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// beq cr6,0x825f1e88
	if (ctx.cr6.eq) goto loc_825F1E88;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,56(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1E70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1E84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
loc_825F1E88:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f1ea8
	if (ctx.cr6.eq) goto loc_825F1EA8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1EA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_825F1EA8:
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f1ee0
	if (ctx.cr6.eq) goto loc_825F1EE0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,56(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1EC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F1EDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
loc_825F1EE0:
	// addi r11,r31,48
	ctx.r11.s64 = ctx.r31.s64 + 48;
loc_825F1EE4:
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
	// stwcx. r29,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r29.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825f1ee4
	if (!ctx.cr0.eq) goto loc_825F1EE4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F6FF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x825F6FF8;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r26,r1,80
	ctx.r26.s64 = ctx.r1.s64 + 80;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// addi r11,r11,31
	ctx.r11.s64 = ctx.r11.s64 + 31;
	// rlwinm r31,r11,27,5,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// ble cr6,0x825f7048
	if (!ctx.cr6.gt) goto loc_825F7048;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8273c6c0
	ctx.lr = 0x825F7034;
	sub_8273C6C0(ctx, base);
	// mr. r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x825f7048
	if (!ctx.cr0.eq) goto loc_825F7048;
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// ori r3,r3,6
	ctx.r3.u64 = ctx.r3.u64 | 6;
	// b 0x825f7108
	goto loc_825F7108;
loc_825F7048:
	// rlwinm r5,r31,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82639688
	ctx.lr = 0x825F7058;
	sub_82639688(ctx, base);
loc_825F7058:
	// lwz r31,4(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x825f70dc
	goto loc_825F70DC;
loc_825F7068:
	// rlwinm r29,r30,29,3,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r11,r30,27
	ctx.r11.u64 = ctx.r30.u32 & 0x1F;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r27,r10,r11
	ctx.r27.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// lwzx r11,r29,r26
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r26.u32);
	// and. r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 & ctx.r27.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825f70d4
	if (!ctx.cr0.eq) goto loc_825F70D4;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F70A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-16381
	ctx.r11.s64 = -1073545216;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x825f70b8
	if (!ctx.cr6.eq) goto loc_825F70B8;
	// li r25,1
	ctx.r25.s64 = 1;
	// b 0x825f70d4
	goto loc_825F70D4;
loc_825F70B8:
	// lis r11,-16381
	ctx.r11.s64 = -1073545216;
	// ori r11,r11,5
	ctx.r11.u64 = ctx.r11.u64 | 5;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x825f70d4
	if (ctx.cr6.eq) goto loc_825F70D4;
	// lwzx r11,r29,r26
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r26.u32);
	// or r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 | ctx.r27.u64;
	// stwx r11,r29,r26
	REX_STORE_U32(ctx.r29.u32 + ctx.r26.u32, ctx.r11.u32);
loc_825F70D4:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_825F70DC:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825f7068
	if (!ctx.cr6.eq) goto loc_825F7068;
	// clrlwi. r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825f7058
	if (!ctx.cr0.eq) goto loc_825F7058;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825f7104
	if (ctx.cr6.eq) goto loc_825F7104;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8273c660
	ctx.lr = 0x825F7104;
	sub_8273C660(ctx, base);
loc_825F7104:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825F7108:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FD7A0) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15420
	ctx.r31.s64 = ctx.r11.s64 + -15420;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8cb0
	ctx.lr = 0x825FD7C8;
	sub_825F8CB0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825fd0e8
	ctx.lr = 0x825FD7D0;
	sub_825FD0E8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x825fd7e0
	if (!ctx.cr0.eq) goto loc_825FD7E0;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r3,-11632(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -11632);
loc_825FD7E0:
	// lwsync 
	// li r11,0
	ctx.r11.s64 = 0;
loc_825FD7E8:
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
	// stwcx. r11,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825fd7e8
	if (!ctx.cr0.eq) goto loc_825FD7E8;
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

DEFINE_REX_FUNC(sub_82603588) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x82603590;
	__savegprlr_19(ctx, base);
	// stfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f31.u64);
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8273b36c
	ctx.lr = 0x8260359C;
	__savevmx_123(ctx, base);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,132(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 132);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x826035cc
	if (!ctx.cr0.eq) goto loc_826035CC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,136(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 136);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x826035d0
	if (!ctx.cr0.eq) goto loc_826035D0;
loc_826035CC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_826035D0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826039c8
	if (ctx.cr0.eq) goto loc_826039C8;
	// li r29,16
	ctx.r29.s64 = 16;
	// lvlx128 v63,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r23,32
	ctx.r23.s64 = 32;
	// lwz r11,96(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 96);
	// li r24,48
	ctx.r24.s64 = 48;
	// li r19,64
	ctx.r19.s64 = 64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvrx128 v62,r29,r30
	temp.u32 = ctx.r29.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// vor128 v127,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lvrx128 v61,r23,r30
	temp.u32 = ctx.r23.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v60,r29,r30
	temp.u32 = ctx.r29.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvrx128 v59,r24,r30
	temp.u32 = ctx.r24.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lvlx128 v58,r23,r30
	temp.u32 = ctx.r23.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v126,v60,v61
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// lvrx128 v63,r19,r30
	temp.u32 = ctx.r19.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v125,v58,v59
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// lvlx128 v62,r24,r30
	temp.u32 = ctx.r24.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r7,28(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// vor128 v124,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// addi r21,r30,96
	ctx.r21.s64 = ctx.r30.s64 + 96;
	// clrlwi. r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stvx128 v127,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x826037f4
	if (!ctx.cr0.eq) goto loc_826037F4;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// lwz r10,112(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 112);
	// lvrx128 v62,r29,r11
	temp.u32 = ctx.r29.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v63,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v62,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v62,v61,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lvlx128 v60,r29,r11
	temp.u32 = ctx.r29.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v61,r23,r11
	temp.u32 = ctx.r23.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v57,r23,r11
	temp.u32 = ctx.r23.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v61,v60,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// lvrx128 v58,r24,r11
	temp.u32 = ctx.r24.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vspltw128 v59,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vor128 v58,v57,v58
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// lvlx128 v57,r24,r11
	temp.u32 = ctx.r24.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v60,r19,r11
	temp.u32 = ctx.r19.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vspltw128 v11,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vor128 v60,v57,v60
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// vspltw128 v57,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vmulfp128 v10,v59,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvrx128 v59,r23,r10
	temp.u32 = ctx.r23.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v56,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v55,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xFF));
	// vor128 v0,v56,v59
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// vspltw128 v1,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vmulfp128 v30,v57,v62
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vspltw128 v56,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// lvrx128 v59,r24,r10
	temp.u32 = ctx.r24.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vspltw128 v2,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vmulfp128 v28,v55,v62
	simde_mm_store_ps(ctx.v28.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvlx128 v54,r23,r10
	temp.u32 = ctx.r23.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v13,v54,v59
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// vspltw128 v29,v58,1
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xAA));
	// vmulfp128 v4,v56,v62
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vspltw128 v3,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vspltw128 v5,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// lvrx128 v59,r19,r10
	temp.u32 = ctx.r19.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v62,r24,r10
	temp.u32 = ctx.r24.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v7,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vor128 v12,v62,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// vspltw128 v6,v58,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0x55));
	// vspltw128 v8,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vmaddfp v31,v11,v0,v10
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vspltw128 v9,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vspltw128 v10,v58,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0x0));
	// vspltw128 v11,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v30,v1,v0,v30
	simde_mm_store_ps(ctx.v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddfp v1,v29,v0,v28
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v28.f32)));
	// vmaddfp v0,v3,v0,v4
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v2,v2,v13,v31
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v5,v5,v13,v30
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddfp v6,v6,v13,v1
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vor128 v1,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v125.u8));
	// vmaddfp v0,v8,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v7,v7,v12,v2
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v9,v9,v12,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v10,v10,v12,v6
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v12,v11,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vor128 v63,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// vor128 v61,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vor128 v60,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vspltw128 v13,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vspltw128 v59,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vmulfp128 v0,v62,v127
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vor128 v62,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vspltw128 v58,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vspltw128 v2,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vmulfp128 v3,v59,v127
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vspltw128 v4,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vspltw128 v57,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vmulfp128 v5,v58,v127
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vspltw128 v6,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vspltw128 v9,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vspltw128 v10,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vmulfp128 v7,v57,v127
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vspltw128 v11,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vmaddcfp128 v13,v126,v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vspltw128 v0,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vmaddfp128 v3,v2,v126,v3
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v126.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp128 v5,v4,v126,v5
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v126.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vor128 v127,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v124.u8));
	// vmaddfp128 v7,v6,v126,v7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v126.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vor128 v126,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v124.u8));
	// vmaddcfp128 v1,v0,v1,v13
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vspltw128 v8,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vmaddcfp128 v9,v125,v9,v3
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v125.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vspltw128 v12,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vspltw128 v13,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// vspltw128 v0,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// vmaddcfp128 v10,v125,v10,v5
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v125.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddcfp128 v11,v125,v11,v7
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v125.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vor128 v125,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_load_si128((simde__m128i*)ctx.v124.u8));
	// vmaddcfp128 v127,v8,v127,v1
	simde_mm_store_ps(ctx.v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v127.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddcfp128 v126,v12,v126,v9
	simde_mm_store_ps(ctx.v126.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v126.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddcfp128 v125,v13,v125,v10
	simde_mm_store_ps(ctx.v125.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v125.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddcfp128 v124,v0,v124,v11
	simde_mm_store_ps(ctx.v124.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v124.f32)), simde_mm_load_ps(ctx.v11.f32)));
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
loc_826037F4:
	// ld r11,168(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 168);
	// addi r22,r26,4
	ctx.r22.s64 = ctx.r26.s64 + 4;
	// ld r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// ld r5,120(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// ld r6,128(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// ld r7,136(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// ld r8,144(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// lwz r3,4(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// ld r9,152(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// ld r10,160(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// bl 0x825fc508
	ctx.lr = 0x82603824;
	sub_825FC508(ctx, base);
	// addi r11,r30,80
	ctx.r11.s64 = ctx.r30.s64 + 80;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r9,0(r21)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// li r25,0
	ctx.r25.s64 = 0;
	// li r20,0
	ctx.r20.s64 = 0;
	// lvrx128 v63,r29,r11
	temp.u32 = ctx.r29.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v62,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v123,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v123.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r9,36(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 36);
	// mulli r10,r10,72
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(72));
	// lwz r28,104(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ble cr6,0x826039c8
	if (!ctx.cr6.gt) goto loc_826039C8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f31,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f31.f64 = double(temp.f32);
loc_82603870:
	// lwz r11,28(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82603894
	if (!ctx.cr0.eq) goto loc_82603894;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,32(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 32);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x82603898
	if (!ctx.cr0.eq) goto loc_82603898;
loc_82603894:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82603898:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8260395c
	if (ctx.cr0.eq) goto loc_8260395C;
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r4,0(r22)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// lwz r3,12(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826038C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8260395c
	if (ctx.cr0.eq) goto loc_8260395C;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r28,20(r27)
	REX_STORE_U32(ctx.r27.u32 + 20, ctx.r28.u32);
	// stw r31,16(r27)
	REX_STORE_U32(ctx.r27.u32 + 16, ctx.r31.u32);
	// lvrx128 v63,r29,r28
	temp.u32 = ctx.r29.u32 + ctx.r28.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v62,r0,r28
	temp.u32 = ctx.r28.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vmulfp128 v63,v63,v123
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v123.f32)));
	// stvlx128 v63,r10,r11
	ea = ctx.r10.u32 + ctx.r11.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvrx128 v63,r27,r29
	ea = ctx.r27.u32 + ctx.r29.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v63.u8[i]);
	// lwz r11,28(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// rlwinm. r10,r11,0,24,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82603924
	if (!ctx.cr0.eq) goto loc_82603924;
	// lfs f0,12(r27)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82603924
	if (!ctx.cr6.lt) goto loc_82603924;
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,5,24,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xE0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF1F);
loc_82603924:
	// stw r11,24(r27)
	REX_STORE_U32(ctx.r27.u32 + 24, ctx.r11.u32);
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// ld r3,256(r11)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r11.u32 + 256);
	// ld r4,264(r11)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r11.u32 + 264);
	// ld r5,272(r11)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r11.u32 + 272);
	// ld r8,296(r11)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r11.u32 + 296);
	// ld r9,304(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 304);
	// ld r10,312(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 312);
	// ld r6,280(r11)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r11.u32 + 280);
	// ld r7,288(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 288);
	// bl 0x826039e0
	ctx.lr = 0x82603954;
	sub_826039E0(ctx, base);
	// stfs f1,28(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r27.u32 + 28, temp.u32);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
loc_8260395C:
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// addi r20,r20,1
	ctx.r20.s64 = ctx.r20.s64 + 1;
	// addi r28,r28,36
	ctx.r28.s64 = ctx.r28.s64 + 36;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// cmplw cr6,r20,r11
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82603870
	if (ctx.cr6.lt) goto loc_82603870;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x826039c8
	if (ctx.cr6.eq) goto loc_826039C8;
	// stvlx128 v127,r0,r31
	ea = ctx.r31.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v127.u8[15 - i]);
	// li r11,0
	ctx.r11.s64 = 0;
	// stvrx128 v127,r31,r29
	ea = ctx.r31.u32 + ctx.r29.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v127.u8[i]);
	// stvlx128 v126,r31,r29
	ea = ctx.r31.u32 + ctx.r29.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v126.u8[15 - i]);
	// stvrx128 v126,r31,r23
	ea = ctx.r31.u32 + ctx.r23.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v126.u8[i]);
	// stvlx128 v125,r31,r23
	ea = ctx.r31.u32 + ctx.r23.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v125.u8[15 - i]);
	// stvrx128 v125,r31,r24
	ea = ctx.r31.u32 + ctx.r24.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v125.u8[i]);
	// stvlx128 v124,r31,r24
	ea = ctx.r31.u32 + ctx.r24.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v124.u8[15 - i]);
	// stvrx128 v124,r31,r19
	ea = ctx.r31.u32 + ctx.r19.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v124.u8[i]);
	// stw r30,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// add r10,r25,r10
	ctx.r10.u64 = ctx.r25.u64 + ctx.r10.u64;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
loc_826039C8:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8273b604
	ctx.lr = 0x826039D4;
	__restvmx_123(ctx, base);
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82642E28) {
	REX_FUNC_PROLOGUE();
	// li r10,16
	ctx.r10.s64 = 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// stw r10,216(r3)
	REX_STORE_U32(ctx.r3.u32 + 216, ctx.r10.u32);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,204(r3)
	REX_STORE_U32(ctx.r3.u32 + 204, ctx.r11.u32);
	// stw r11,208(r3)
	REX_STORE_U32(ctx.r3.u32 + 208, ctx.r11.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,212(r3)
	REX_STORE_U32(ctx.r3.u32 + 212, ctx.r11.u32);
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
loc_82642E54:
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// stw r8,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// bdnz 0x82642e54
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82642E54;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82644A60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82644A68;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r28,r11,13120
	ctx.r28.s64 = ctx.r11.s64 + 13120;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82641ee0
	ctx.lr = 0x82644A80;
	sub_82641EE0(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82644a94
	if (!ctx.cr6.eq) goto loc_82644A94;
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16387
	ctx.r30.u64 = ctx.r30.u64 | 16387;
	// b 0x82644b0c
	goto loc_82644B0C;
loc_82644A94:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,388
	ctx.r4.s64 = 388;
	// bl 0x82641ff8
	ctx.lr = 0x82644AAC;
	sub_82641FF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82644ac0
	if (ctx.cr0.eq) goto loc_82644AC0;
	// bl 0x8264de68
	ctx.lr = 0x82644AB8;
	sub_8264DE68(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82644ac4
	goto loc_82644AC4;
loc_82644AC0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82644AC4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82644ad8
	if (!ctx.cr6.eq) goto loc_82644AD8;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x82644b0c
	goto loc_82644B0C;
loc_82644AD8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264cc48
	ctx.lr = 0x82644AE0;
	sub_8264CC48(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82644af0
	if (ctx.cr0.lt) goto loc_82644AF0;
	// stw r31,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// b 0x82644b0c
	goto loc_82644B0C;
loc_82644AF0:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82644B08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8264cf40
	ctx.lr = 0x82644B0C;
	sub_8264CF40(ctx, base);
loc_82644B0C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82641f78
	ctx.lr = 0x82644B14;
	sub_82641F78(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826493A0) {
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
	// lwz r11,184(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 184);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x826493ec
	if (!ctx.cr6.gt) goto loc_826493EC;
loc_826493C8:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,284(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 284);
	// bl 0x82645888
	ctx.lr = 0x826493D4;
	sub_82645888(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82649408
	if (ctx.cr0.eq) goto loc_82649408;
	// lwz r11,184(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x826493c8
	if (ctx.cr6.lt) goto loc_826493C8;
loc_826493EC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826493F0:
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
loc_82649408:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x826493f0
	goto loc_826493F0;
}

DEFINE_REX_FUNC(sub_8264B128) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8264B130;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,204(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// b 0x8264b170
	goto loc_8264B170;
loc_8264B148:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8264b160
	if (ctx.cr6.eq) goto loc_8264B160;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8264b164
	goto loc_8264B164;
loc_8264B160:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8264B164:
	// lwz r10,260(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 260);
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x8264b17c
	if (!ctx.cr6.lt) goto loc_8264B17C;
loc_8264B170:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8264b148
	if (!ctx.cr6.eq) goto loc_8264B148;
	// b 0x8264b18c
	goto loc_8264B18C;
loc_8264B17C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8264a9d8
	ctx.lr = 0x8264B184;
	sub_8264A9D8(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8264b238
	if (!ctx.cr0.eq) goto loc_8264B238;
loc_8264B18C:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,13120
	ctx.r3.s64 = ctx.r11.s64 + 13120;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r4,264
	ctx.r4.s64 = 264;
	// bl 0x82641ff8
	ctx.lr = 0x8264B1A4;
	sub_82641FF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8264b1bc
	if (ctx.cr0.eq) goto loc_8264B1BC;
	// lwz r4,220(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 220);
	// bl 0x8264a8d0
	ctx.lr = 0x8264B1B4;
	sub_8264A8D0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8264b1c0
	goto loc_8264B1C0;
loc_8264B1BC:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8264B1C0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8264b238
	if (ctx.cr6.eq) goto loc_8264B238;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82643240
	ctx.lr = 0x8264B1D4;
	sub_82643240(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8264b228
	if (ctx.cr0.eq) goto loc_8264B228;
	// lwz r11,224(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 224);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x8264b1ec
	if (ctx.cr6.gt) goto loc_8264B1EC;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8264B1EC:
	// addi r11,r11,4095
	ctx.r11.s64 = ctx.r11.s64 + 4095;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r4,r11,0,0,19
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFF000;
	// bl 0x8264a928
	ctx.lr = 0x8264B1FC;
	sub_8264A928(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8264b218
	if (ctx.cr0.lt) goto loc_8264B218;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264a9d8
	ctx.lr = 0x8264B210;
	sub_8264A9D8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// b 0x8264b220
	goto loc_8264B220;
loc_8264B218:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82649a78
	ctx.lr = 0x8264B220;
	sub_82649A78(ctx, base);
loc_8264B220:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x8264b238
	if (!ctx.cr6.lt) goto loc_8264B238;
loc_8264B228:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82643d10
	ctx.lr = 0x8264B230;
	sub_82643D10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264cf40
	ctx.lr = 0x8264B238;
	sub_8264CF40(ctx, base);
loc_8264B238:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82651AA4) {
	REX_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82651C80) {
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
	// lis r11,-32116
	ctx.r11.s64 = -2104754176;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,17712
	ctx.r4.s64 = ctx.r11.s64 + 17712;
	// bl 0x82663988
	ctx.lr = 0x82651CA0;
	sub_82663988(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,8156
	ctx.r10.s64 = ctx.r10.s64 + 8156;
	// addi r9,r9,8136
	ctx.r9.s64 = ctx.r9.s64 + 8136;
	// sth r11,36(r31)
	REX_STORE_U16(ctx.r31.u32 + 36, ctx.r11.u16);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// stw r9,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// sth r11,38(r31)
	REX_STORE_U16(ctx.r31.u32 + 38, ctx.r11.u16);
	// addi r3,r10,13120
	ctx.r3.s64 = ctx.r10.s64 + 13120;
	// sth r11,40(r31)
	REX_STORE_U16(ctx.r31.u32 + 40, ctx.r11.u16);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bl 0x82641ee0
	ctx.lr = 0x82651CE4;
	sub_82641EE0(ctx, base);
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

DEFINE_REX_FUNC(sub_82655488) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826554c4
	if (ctx.cr6.eq) goto loc_826554C4;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82597cc0
	ctx.lr = 0x826554B4;
	sub_82597CC0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82655290
	ctx.lr = 0x826554BC;
	sub_82655290(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82673628
	ctx.lr = 0x826554C4;
	sub_82673628(ctx, base);
loc_826554C4:
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

DEFINE_REX_FUNC(sub_8265B908) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x8265B910;
	__savegprlr_21(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r21,r5
	ctx.r21.u64 = ctx.r5.u64;
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// beq cr6,0x8265bb5c
	if (ctx.cr6.eq) goto loc_8265BB5C;
	// lwz r24,0(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8265bb5c
	if (ctx.cr6.eq) goto loc_8265BB5C;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8265bb5c
	if (ctx.cr6.eq) goto loc_8265BB5C;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8265bb5c
	if (ctx.cr6.eq) goto loc_8265BB5C;
	// lwz r11,692(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 692);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8265b968
	if (ctx.cr6.eq) goto loc_8265B968;
	// lis r30,-32764
	ctx.r30.s64 = -2147221504;
	// ori r30,r30,10
	ctx.r30.u64 = ctx.r30.u64 | 10;
	// b 0x8265bb64
	goto loc_8265BB64;
loc_8265B968:
	// stw r23,692(r31)
	REX_STORE_U32(ctx.r31.u32 + 692, ctx.r23.u32);
	// stw r23,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r23.u32);
	// lwz r11,72(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8265bb70
	if (ctx.cr6.eq) goto loc_8265BB70;
	// lwz r11,820(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 820);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8265b98c
	if (!ctx.cr6.eq) goto loc_8265B98C;
	// stw r23,696(r31)
	REX_STORE_U32(ctx.r31.u32 + 696, ctx.r23.u32);
loc_8265B98C:
	// lwz r11,696(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 696);
	// lis r10,-32764
	ctx.r10.s64 = -2147221504;
	// lis r9,-32764
	ctx.r9.s64 = -2147221504;
	// ori r27,r10,2
	ctx.r27.u64 = ctx.r10.u64 | 2;
	// ori r25,r9,4
	ctx.r25.u64 = ctx.r9.u64 | 4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265ba6c
	if (ctx.cr6.eq) goto loc_8265BA6C;
	// lwz r11,704(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 704);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265b9cc
	if (ctx.cr6.eq) goto loc_8265B9CC;
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// addi r3,r31,224
	ctx.r3.s64 = ctx.r31.s64 + 224;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8265b9cc
	if (ctx.cr6.eq) goto loc_8265B9CC;
	// bl 0x82678120
	ctx.lr = 0x8265B9CC;
	sub_82678120(ctx, base);
loc_8265B9CC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82655f80
	ctx.lr = 0x8265B9D4;
	sub_82655F80(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r27
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8265ba10
	if (!ctx.cr6.eq) goto loc_8265BA10;
	// lis r11,15
	ctx.r11.s64 = 983040;
	// ori r28,r11,16960
	ctx.r28.u64 = ctx.r11.u64 | 16960;
loc_8265B9E8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82655c80
	ctx.lr = 0x8265B9F0;
	sub_82655C80(ctx, base);
	// cmpw cr6,r29,r28
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r28.s32, ctx.xer);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bgt cr6,0x8265ba18
	if (ctx.cr6.gt) goto loc_8265BA18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82655f80
	ctx.lr = 0x8265BA04;
	sub_82655F80(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r27
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8265b9e8
	if (ctx.cr6.eq) goto loc_8265B9E8;
loc_8265BA10:
	// cmplw cr6,r30,r25
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x8265ba60
	if (!ctx.cr6.eq) goto loc_8265BA60;
loc_8265BA18:
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265ba40
	if (ctx.cr6.eq) goto loc_8265BA40;
	// lwz r11,704(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 704);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265ba40
	if (!ctx.cr6.eq) goto loc_8265BA40;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// stw r23,692(r31)
	REX_STORE_U32(ctx.r31.u32 + 692, ctx.r23.u32);
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// b 0x8265bb70
	goto loc_8265BB70;
loc_8265BA40:
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	ctx.r11.u64 = ctx.r9.u64 ^ 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,692(r31)
	REX_STORE_U32(ctx.r31.u32 + 692, ctx.r11.u32);
	// b 0x8265bb70
	goto loc_8265BB70;
loc_8265BA60:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8265bb64
	if (ctx.cr6.lt) goto loc_8265BB64;
	// stw r23,696(r31)
	REX_STORE_U32(ctx.r31.u32 + 696, ctx.r23.u32);
loc_8265BA6C:
	// sth r23,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r23.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82656328
	ctx.lr = 0x8265BA80;
	sub_82656328(ctx, base);
	// lhz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r4,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r4.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,336(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// lwz r8,452(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 452);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x8265baac
	if (ctx.cr6.eq) goto loc_8265BAAC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82656c38
	ctx.lr = 0x8265BAA8;
	sub_82656C38(ctx, base);
	// stw r3,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r3.u32);
loc_8265BAAC:
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8265bac4
	if (!ctx.cr6.eq) goto loc_8265BAC4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82655c80
	ctx.lr = 0x8265BABC;
	sub_82655C80(ctx, base);
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// b 0x8265bb70
	goto loc_8265BB70;
loc_8265BAC4:
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// bne cr6,0x8265bb18
	if (!ctx.cr6.eq) goto loc_8265BB18;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r11,696(r31)
	REX_STORE_U32(ctx.r31.u32 + 696, ctx.r11.u32);
	// stw r10,72(r24)
	REX_STORE_U32(ctx.r24.u32 + 72, ctx.r10.u32);
	// lwz r9,704(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 704);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8265bb70
	if (ctx.cr6.eq) goto loc_8265BB70;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x8265bb70
	if (ctx.cr6.eq) goto loc_8265BB70;
	// addi r3,r31,224
	ctx.r3.s64 = ctx.r31.s64 + 224;
	// bl 0x82678518
	ctx.lr = 0x8265BAF8;
	sub_82678518(ctx, base);
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// lwz r10,244(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// srawi r9,r3,3
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 3;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// subf r7,r10,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r6,r8,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r8.u64;
	// stw r6,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r6.u32);
	// b 0x8265bb70
	goto loc_8265BB70;
loc_8265BB18:
	// cmplw cr6,r30,r25
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x8265bb48
	if (!ctx.cr6.eq) goto loc_8265BB48;
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265ba40
	if (ctx.cr6.eq) goto loc_8265BA40;
	// lwz r11,704(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 704);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265ba40
	if (!ctx.cr6.eq) goto loc_8265BA40;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// stw r23,692(r31)
	REX_STORE_U32(ctx.r31.u32 + 692, ctx.r23.u32);
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// b 0x8265bb70
	goto loc_8265BB70;
loc_8265BB48:
	// li r11,7
	ctx.r11.s64 = 7;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r11,72(r24)
	REX_STORE_U32(ctx.r24.u32 + 72, ctx.r11.u32);
	// blt cr6,0x8265bb64
	if (ctx.cr6.lt) goto loc_8265BB64;
	// b 0x8265bb70
	goto loc_8265BB70;
loc_8265BB5C:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,87
	ctx.r30.u64 = ctx.r30.u64 | 87;
loc_8265BB64:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8265bbd8
	if (ctx.cr6.eq) goto loc_8265BBD8;
	// stw r23,692(r31)
	REX_STORE_U32(ctx.r31.u32 + 692, ctx.r23.u32);
loc_8265BB70:
	// lwz r11,704(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 704);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265bb8c
	if (!ctx.cr6.eq) goto loc_8265BB8C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,820(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 820);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8265bbbc
	if (ctx.cr6.eq) goto loc_8265BBBC;
loc_8265BB8C:
	// lwz r11,696(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 696);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265bbbc
	if (ctx.cr6.eq) goto loc_8265BBBC;
	// lwz r11,692(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 692);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8265bbbc
	if (!ctx.cr6.eq) goto loc_8265BBBC;
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	ctx.r11.u64 = ctx.r9.u64 ^ 1;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,692(r31)
	REX_STORE_U32(ctx.r31.u32 + 692, ctx.r8.u32);
loc_8265BBBC:
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// beq cr6,0x8265bbdc
	if (ctx.cr6.eq) goto loc_8265BBDC;
	// lwz r11,692(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 692);
	// stw r11,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
loc_8265BBD8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8265BBDC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82675B50) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r5,78
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 78, ctx.xer);
	// bgt cr6,0x82675bc0
	if (ctx.cr6.gt) goto loc_82675BC0;
	// beq cr6,0x82675ba4
	if (ctx.cr6.eq) goto loc_82675BA4;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x82675b88
	if (ctx.cr6.eq) goto loc_82675B88;
	// cmpwi cr6,r5,61
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 61, ctx.xer);
	// bne cr6,0x82675bc8
	if (!ctx.cr6.eq) goto loc_82675BC8;
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// lis r10,-32153
	ctx.r10.s64 = -2107179008;
	// addi r9,r11,21008
	ctx.r9.s64 = ctx.r11.s64 + 21008;
	// addi r8,r10,20840
	ctx.r8.s64 = ctx.r10.s64 + 20840;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_82675B88:
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// lis r10,-32153
	ctx.r10.s64 = -2107179008;
	// addi r9,r11,21104
	ctx.r9.s64 = ctx.r11.s64 + 21104;
	// addi r8,r10,21176
	ctx.r8.s64 = ctx.r10.s64 + 21176;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_82675BA4:
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// lis r10,-32153
	ctx.r10.s64 = -2107179008;
	// addi r9,r11,21064
	ctx.r9.s64 = ctx.r11.s64 + 21064;
	// addi r8,r10,20880
	ctx.r8.s64 = ctx.r10.s64 + 20880;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_82675BC0:
	// cmpwi cr6,r5,94
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 94, ctx.xer);
	// beq cr6,0x82675be4
	if (ctx.cr6.eq) goto loc_82675BE4;
loc_82675BC8:
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// lis r10,-32153
	ctx.r10.s64 = -2107179008;
	// addi r9,r11,20920
	ctx.r9.s64 = ctx.r11.s64 + 20920;
	// addi r8,r10,20248
	ctx.r8.s64 = ctx.r10.s64 + 20248;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_82675BE4:
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// lis r10,-32153
	ctx.r10.s64 = -2107179008;
	// addi r9,r11,21024
	ctx.r9.s64 = ctx.r11.s64 + 21024;
	// addi r8,r10,20856
	ctx.r8.s64 = ctx.r10.s64 + 20856;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826786E8) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r11,76(r3)
	REX_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r10,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// lwz r8,0(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r7,212(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 212);
	// stw r7,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r7.u32);
	// stw r9,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r9.u32);
	// stw r11,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// stw r11,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// stw r11,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// stw r11,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// lwz r6,704(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 704);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x82678768
	if (ctx.cr6.eq) goto loc_82678768;
	// stw r11,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// stw r11,76(r3)
	REX_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r11,80(r3)
	REX_STORE_U32(ctx.r3.u32 + 80, ctx.r11.u32);
loc_82678768:
	// lis r11,-32167
	ctx.r11.s64 = -2108096512;
	// addi r10,r11,31936
	ctx.r10.s64 = ctx.r11.s64 + 31936;
	// stw r10,84(r3)
	REX_STORE_U32(ctx.r3.u32 + 84, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8267F750) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x8267F758;
	__savegprlr_19(ctx, base);
	// stfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f29.u64);
	// stfd f30,-128(r1)
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.f30.u64);
	// stfd f31,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r8,284(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 284);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r22,r4
	ctx.r22.u64 = ctx.r4.u64;
	// li r19,0
	ctx.r19.s64 = 0;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// blt cr6,0x8267fc6c
	if (ctx.cr6.lt) goto loc_8267FC6C;
	// beq cr6,0x8267f7b0
	if (ctx.cr6.eq) goto loc_8267F7B0;
	// cmplwi cr6,r6,3
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 3, ctx.xer);
	// blt cr6,0x8267f7a8
	if (ctx.cr6.lt) goto loc_8267F7A8;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f29,-136(r1)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f30,-128(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
loc_8267F7A8:
	// li r20,1
	ctx.r20.s64 = 1;
	// b 0x8267f7b4
	goto loc_8267F7B4;
loc_8267F7B0:
	// li r20,0
	ctx.r20.s64 = 0;
loc_8267F7B4:
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8267f7cc
	if (!ctx.cr6.eq) goto loc_8267F7CC;
	// lwz r11,36(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8267fc6c
	if (ctx.cr6.eq) goto loc_8267FC6C;
loc_8267F7CC:
	// lwz r11,36(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8267f7e0
	if (!ctx.cr6.eq) goto loc_8267F7E0;
	// lis r23,16
	ctx.r23.s64 = 1048576;
	// b 0x8267f7f0
	goto loc_8267F7F0;
loc_8267F7E0:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// rlwinm r10,r5,2,22,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FC;
	// addi r9,r11,14768
	ctx.r9.s64 = ctx.r11.s64 + 14768;
	// lwzx r23,r10,r9
	ctx.r23.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_8267F7F0:
	// lwz r25,120(r27)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + 120);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x8267f828
	if (!ctx.cr6.gt) goto loc_8267F828;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8267F808:
	// lwz r9,320(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 320);
	// lwz r6,388(r22)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r22.u32 + 388);
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r11,r11,1776
	ctx.r11.s64 = ctx.r11.s64 + 1776;
	// lwz r4,60(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 60);
	// stwx r4,r10,r6
	REX_STORE_U32(ctx.r10.u32 + ctx.r6.u32, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267f808
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267F808;
loc_8267F828:
	// srawi r11,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r7.s32 >> 8;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bge cr6,0x8267f840
	if (!ctx.cr6.lt) goto loc_8267F840;
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x8267f84c
	goto loc_8267F84C;
loc_8267F840:
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// ble cr6,0x8267f84c
	if (!ctx.cr6.gt) goto loc_8267F84C;
	// li r10,16
	ctx.r10.s64 = 16;
loc_8267F84C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x8267fc6c
	if (ctx.cr6.lt) goto loc_8267FC6C;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r9,r1,92
	ctx.r9.s64 = ctx.r1.s64 + 92;
	// li r11,0
	ctx.r11.s64 = 0;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8267F864:
	// divw r8,r11,r10
	ctx.r8.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8267f864
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267F864;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8267fc6c
	if (!ctx.cr6.gt) goto loc_8267FC6C;
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,127
	ctx.r8.s64 = 8323072;
	// addi r26,r1,100
	ctx.r26.s64 = ctx.r1.s64 + 100;
	// lfs f29,-28368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28368);
	ctx.f29.f64 = double(temp.f32);
	// ori r21,r8,65535
	ctx.r21.u64 = ctx.r8.u64 | 65535;
	// lfs f30,7996(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7996);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,2524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2524);
	ctx.f31.f64 = double(temp.f32);
loc_8267F8A4:
	// lwz r31,-4(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + -4);
	// fmr f12,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f31.f64;
	// lwz r29,0(r26)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x8267f9c8
	if (!ctx.cr6.gt) goto loc_8267F9C8;
	// lwz r8,388(r22)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r22.u32 + 388);
	// rlwinm r7,r31,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
loc_8267F8C4:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + ctx.r11.u64;
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// bge cr6,0x8267f9b0
	if (!ctx.cr6.lt) goto loc_8267F9B0;
	// subf r11,r31,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r31.u64;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// blt cr6,0x8267f97c
	if (ctx.cr6.lt) goto loc_8267F97C;
	// subf r11,r31,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r31.u64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8267F904:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8267f914
	if (ctx.cr6.gt) goto loc_8267F914;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8267F914:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8267f920
	if (!ctx.cr6.gt) goto loc_8267F920;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_8267F920:
	// lfs f0,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8267f930
	if (ctx.cr6.gt) goto loc_8267F930;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8267F930:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8267f93c
	if (!ctx.cr6.gt) goto loc_8267F93C;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_8267F93C:
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8267f94c
	if (ctx.cr6.gt) goto loc_8267F94C;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8267F94C:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8267f958
	if (!ctx.cr6.gt) goto loc_8267F958;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_8267F958:
	// lfs f0,12(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8267f968
	if (ctx.cr6.gt) goto loc_8267F968;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8267F968:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8267f974
	if (!ctx.cr6.gt) goto loc_8267F974;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_8267F974:
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bdnz 0x8267f904
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267F904;
loc_8267F97C:
	// cmpw cr6,r10,r29
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r29.s32, ctx.xer);
	// bge cr6,0x8267f9b0
	if (!ctx.cr6.lt) goto loc_8267F9B0;
	// subf r11,r10,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r10.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8267F98C:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8267f99c
	if (ctx.cr6.gt) goto loc_8267F99C;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8267F99C:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8267f9a8
	if (!ctx.cr6.gt) goto loc_8267F9A8;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_8267F9A8:
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x8267f98c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267F98C;
loc_8267F9B0:
	// fcmpu cr6,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x8267f9bc
	if (!ctx.cr6.gt) goto loc_8267F9BC;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
loc_8267F9BC:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8267f8c4
	if (!ctx.cr0.eq) goto loc_8267F8C4;
loc_8267F9C8:
	// lfs f0,128(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8267f9ec
	if (!ctx.cr6.lt) goto loc_8267F9EC;
	// fsubs f13,f0,f30
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x8267f9fc
	goto loc_8267F9FC;
loc_8267F9EC:
	// fadds f13,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_8267F9FC:
	// cmpw cr6,r11,r21
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r21.s32, ctx.xer);
	// bge cr6,0x8267fa34
	if (!ctx.cr6.lt) goto loc_8267FA34;
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8267fa20
	if (!ctx.cr6.lt) goto loc_8267FA20;
	// fsubs f13,f0,f30
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x8267fa38
	goto loc_8267FA38;
loc_8267FA20:
	// fadds f13,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x8267fa38
	goto loc_8267FA38;
loc_8267FA34:
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
loc_8267FA38:
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8267fae4
	if (ctx.cr6.eq) goto loc_8267FAE4;
	// lwz r9,196(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 196);
	// rlwinm r11,r20,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// extsw r9,r23
	ctx.r9.s64 = ctx.r23.s32;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8267fac0
	if (ctx.cr6.eq) goto loc_8267FAC0;
	// lwz r5,296(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 296);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// lwz r8,264(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 264);
	// mulld r4,r7,r9
	ctx.r4.s64 = static_cast<int64_t>(ctx.r7.u64 * ctx.r9.u64);
	// lwz r6,260(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 260);
	// lwz r3,280(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 280);
	// lwzx r7,r5,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// lwzx r10,r8,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// lwzx r8,r6,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// lwzx r6,r3,r11
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// sradi r5,r4,20
	ctx.xer.ca = (ctx.r4.s64 < 0) & ((ctx.r4.u64 & 0xFFFFF) != 0);
	ctx.r5.s64 = ctx.r4.s64 >> 20;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// srawi r11,r4,13
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1FFF) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 13;
	// clrlwi r3,r4,19
	ctx.r3.u64 = ctx.r4.u32 & 0x1FFF;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r11,r8,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// mullw r8,r10,r3
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// sraw r10,r8,r7
	temp.u32 = ctx.r7.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r10.s64 = ctx.r8.s32 >> temp.u32;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// mulld r4,r5,r9
	ctx.r4.s64 = static_cast<int64_t>(ctx.r5.u64 * ctx.r9.u64);
	// sradi r3,r4,20
	ctx.xer.ca = (ctx.r4.s64 < 0) & ((ctx.r4.u64 & 0xFFFFF) != 0);
	ctx.r3.s64 = ctx.r4.s64 >> 20;
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// b 0x8267faf0
	goto loc_8267FAF0;
loc_8267FAC0:
	// lwz r10,192(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 192);
	// lwz r8,280(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 280);
	// lwzx r7,r10,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r6,r8,r11
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// mulld r4,r5,r9
	ctx.r4.s64 = static_cast<int64_t>(ctx.r5.u64 * ctx.r9.u64);
	// sradi r3,r4,20
	ctx.xer.ca = (ctx.r4.s64 < 0) & ((ctx.r4.u64 & 0xFFFFF) != 0);
	ctx.r3.s64 = ctx.r4.s64 >> 20;
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// b 0x8267faf0
	goto loc_8267FAF0;
loc_8267FAE4:
	// lis r6,127
	ctx.r6.s64 = 8323072;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// ori r6,r6,65534
	ctx.r6.u64 = ctx.r6.u64 | 65534;
loc_8267FAF0:
	// lwz r30,172(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 172);
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8267fb10
	if (!ctx.cr6.lt) goto loc_8267FB10;
	// fsubs f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x8267fb20
	goto loc_8267FB20;
loc_8267FB10:
	// fadds f0,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_8267FB20:
	// subf r28,r31,r29
	ctx.r28.u64 = ctx.r29.u64 - ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// bl 0x8267f118
	ctx.lr = 0x8267FB30;
	sub_8267F118(ctx, base);
	// srawi. r11,r28,2
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r28.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8267fb54
	if (ctx.cr0.eq) goto loc_8267FB54;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8267fb54
	if (!ctx.cr6.gt) goto loc_8267FB54;
loc_8267FB44:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// srw r9,r11,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bgt cr6,0x8267fb44
	if (ctx.cr6.gt) goto loc_8267FB44;
loc_8267FB54:
	// cmpw cr6,r3,r30
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r30.s32, ctx.xer);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// bgt cr6,0x8267fb64
	if (ctx.cr6.gt) goto loc_8267FB64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8267FB64:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bgt cr6,0x8267fb70
	if (ctx.cr6.gt) goto loc_8267FB70;
	// li r11,2
	ctx.r11.s64 = 2;
loc_8267FB70:
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// ble cr6,0x8267fb90
	if (!ctx.cr6.gt) goto loc_8267FB90;
loc_8267FB80:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r9,r10,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r11.u8 & 0x3F));
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bgt cr6,0x8267fb80
	if (ctx.cr6.gt) goto loc_8267FB80;
loc_8267FB90:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f12,f29
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f29.f64));
	// ble cr6,0x8267fc5c
	if (!ctx.cr6.gt) goto loc_8267FC5C;
	// lwz r8,388(r22)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r22.u32 + 388);
	// rlwinm r7,r31,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
loc_8267FBBC:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// bge cr6,0x8267fc50
	if (!ctx.cr6.lt) goto loc_8267FC50;
	// cmpwi cr6,r28,4
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 4, ctx.xer);
	// blt cr6,0x8267fc2c
	if (ctx.cr6.lt) goto loc_8267FC2C;
	// subf r10,r31,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r31.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8267FBF4:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f10,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f8,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f9,4(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f7,8(r11)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stfs f6,12(r11)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x8267fbf4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267FBF4;
loc_8267FC2C:
	// cmpw cr6,r9,r29
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r29.s32, ctx.xer);
	// bge cr6,0x8267fc50
	if (!ctx.cr6.lt) goto loc_8267FC50;
	// subf r10,r9,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r9.u64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8267FC40:
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f12,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8267fc40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267FC40;
loc_8267FC50:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8267fbbc
	if (!ctx.cr0.eq) goto loc_8267FBBC;
loc_8267FC5C:
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// stw r3,172(r27)
	REX_STORE_U32(ctx.r27.u32 + 172, ctx.r3.u32);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// bne 0x8267f8a4
	if (!ctx.cr0.eq) goto loc_8267F8A4;
loc_8267FC6C:
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f30,-128(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826BC7E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x826BC7E8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,22632(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 22632);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r29,268(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826bc810
	if (!ctx.cr6.eq) goto loc_826BC810;
	// bl 0x826aa4b8
	ctx.lr = 0x826BC808;
	sub_826AA4B8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_826BC810:
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
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
	// rldicl r25,r10,1,63
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826bc838
	if (!ctx.cr0.lt) goto loc_826BC838;
	// bl 0x826c8b78
	ctx.lr = 0x826BC838;
	sub_826C8B78(ctx, base);
loc_826BC838:
	// lwz r30,84(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// li r28,3
	ctx.r28.s64 = 3;
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x826bc8ac
	if (!ctx.cr6.lt) goto loc_826BC8AC;
loc_826BC854:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826bc8ac
	if (ctx.cr6.eq) goto loc_826BC8AC;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r28,r11,r28
	ctx.r28.u64 = ctx.r28.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r28
	ctx.r11.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r28.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// add r27,r11,r27
	ctx.r27.u64 = ctx.r11.u64 + ctx.r27.u64;
	// std r10,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r10.u64);
	// bge 0x826bc89c
	if (!ctx.cr0.lt) goto loc_826BC89C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826BC89C;
	sub_826C8B78(ctx, base);
loc_826BC89C:
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826bc854
	if (ctx.cr6.gt) goto loc_826BC854;
loc_826BC8AC:
	// subfic r11,r28,64
	ctx.xer.ca = ctx.r28.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r28.u64;
	// ld r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// clrldi r8,r28,32
	ctx.r8.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r28,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r28.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r28,r11,r27
	ctx.r28.u64 = ctx.r11.u64 + ctx.r27.u64;
	// std r4,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r4.u64);
	// bge 0x826bc8e8
	if (!ctx.cr0.lt) goto loc_826BC8E8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826BC8E8;
	sub_826C8B78(ctx, base);
loc_826BC8E8:
	// cmplwi cr6,r28,7
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 7, ctx.xer);
	// bgt cr6,0x826bcc88
	if (ctx.cr6.gt) goto loc_826BCC88;
	// mtctr r28
	ctx.ctr.u64 = ctx.r28.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x826bc91c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_826BC91C;
	// bdzf 4*cr6+eq,0x826bc934
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_826BC934;
	// bdzf 4*cr6+eq,0x826bc988
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_826BC988;
	// bdzf 4*cr6+eq,0x826bc9a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_826BC9A4;
	// bdzf 4*cr6+eq,0x826bc9c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_826BC9C0;
	// bdzf 4*cr6+eq,0x826bcacc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_826BCACC;
	// bne cr6,0x826bcbd8
	if (!ctx.cr6.eq) goto loc_826BCBD8;
	// li r26,0
	ctx.r26.s64 = 0;
	// b 0x826bcc8c
	goto loc_826BCC8C;
loc_826BC91C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,84(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r4,144(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// li r26,1
	ctx.r26.s64 = 1;
	// bl 0x826a9b80
	ctx.lr = 0x826BC930;
	sub_826A9B80(ctx, base);
	// b 0x826bcc8c
	goto loc_826BCC8C;
loc_826BC934:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,84(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r4,144(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// li r26,2
	ctx.r26.s64 = 2;
	// bl 0x826a9b80
	ctx.lr = 0x826BC948;
	sub_826A9B80(ctx, base);
loc_826BC948:
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826bccc8
	if (!ctx.cr6.gt) goto loc_826BCCC8;
loc_826BC95C:
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826bcc74
	if (!ctx.cr6.gt) goto loc_826BCC74;
loc_826BC96C:
	// add. r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 + ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x826bcc48
	if (ctx.cr0.eq) goto loc_826BCC48;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x826bcbf4
	if (!ctx.cr6.eq) goto loc_826BCBF4;
	// lwz r10,-24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -24);
	// rlwinm r10,r10,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// b 0x826bcc4c
	goto loc_826BCC4C;
loc_826BC988:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r26,3
	ctx.r26.s64 = 3;
	// bl 0x826aa020
	ctx.lr = 0x826BC994;
	sub_826AA020(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826bcc8c
	if (ctx.cr6.eq) goto loc_826BCC8C;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_826BC9A4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r26,4
	ctx.r26.s64 = 4;
	// bl 0x826aa020
	ctx.lr = 0x826BC9B0;
	sub_826AA020(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826bc948
	if (ctx.cr6.eq) goto loc_826BC948;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_826BC9C0:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r26,5
	ctx.r26.s64 = 5;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826bcc8c
	if (!ctx.cr6.gt) goto loc_826BCC8C;
loc_826BC9D4:
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
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
	// bge 0x826bc9fc
	if (!ctx.cr0.lt) goto loc_826BC9FC;
	// bl 0x826c8b78
	ctx.lr = 0x826BC9FC;
	sub_826C8B78(ctx, base);
loc_826BC9FC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826bca74
	if (ctx.cr6.eq) goto loc_826BCA74;
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826bcab8
	if (!ctx.cr6.gt) goto loc_826BCAB8;
loc_826BCA14:
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
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
	// rldicl r28,r10,1,63
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826bca3c
	if (!ctx.cr0.lt) goto loc_826BCA3C;
	// bl 0x826c8b78
	ctx.lr = 0x826BCA3C;
	sub_826C8B78(ctx, base);
loc_826BCA3C:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mullw r11,r11,r27
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r9,r11,r29
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// rlwimi r9,r28,31,0,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 31) & 0x80000000) | (ctx.r9.u64 & 0xFFFFFFFF7FFFFFFF);
	// stwx r9,r11,r29
	REX_STORE_U32(ctx.r11.u32 + ctx.r29.u32, ctx.r9.u32);
	// lwz r8,136(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmpw cr6,r30,r8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x826bca14
	if (ctx.cr6.lt) goto loc_826BCA14;
	// b 0x826bcab8
	goto loc_826BCAB8;
loc_826BCA74:
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826bcab8
	if (!ctx.cr6.gt) goto loc_826BCAB8;
loc_826BCA84:
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mullw r10,r10,r27
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r27.s32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r10,r29
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// clrlwi r7,r8,1
	ctx.r7.u64 = ctx.r8.u32 & 0x7FFFFFFF;
	// stwx r7,r10,r29
	REX_STORE_U32(ctx.r10.u32 + ctx.r29.u32, ctx.r7.u32);
	// lwz r6,136(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x826bca84
	if (ctx.cr6.lt) goto loc_826BCA84;
loc_826BCAB8:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826bc9d4
	if (ctx.cr6.lt) goto loc_826BC9D4;
	// b 0x826bcc8c
	goto loc_826BCC8C;
loc_826BCACC:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r26,6
	ctx.r26.s64 = 6;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826bcc8c
	if (!ctx.cr6.gt) goto loc_826BCC8C;
loc_826BCAE0:
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
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
	// bge 0x826bcb08
	if (!ctx.cr0.lt) goto loc_826BCB08;
	// bl 0x826c8b78
	ctx.lr = 0x826BCB08;
	sub_826C8B78(ctx, base);
loc_826BCB08:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826bcb80
	if (ctx.cr6.eq) goto loc_826BCB80;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826bcbc4
	if (!ctx.cr6.gt) goto loc_826BCBC4;
loc_826BCB20:
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
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
	// rldicl r28,r10,1,63
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826bcb48
	if (!ctx.cr0.lt) goto loc_826BCB48;
	// bl 0x826c8b78
	ctx.lr = 0x826BCB48;
	sub_826C8B78(ctx, base);
loc_826BCB48:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r9,r11,r29
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// rlwimi r9,r28,31,0,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 31) & 0x80000000) | (ctx.r9.u64 & 0xFFFFFFFF7FFFFFFF);
	// stwx r9,r11,r29
	REX_STORE_U32(ctx.r11.u32 + ctx.r29.u32, ctx.r9.u32);
	// lwz r8,140(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// cmpw cr6,r30,r8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x826bcb20
	if (ctx.cr6.lt) goto loc_826BCB20;
	// b 0x826bcbc4
	goto loc_826BCBC4;
loc_826BCB80:
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826bcbc4
	if (!ctx.cr6.gt) goto loc_826BCBC4;
loc_826BCB90:
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r10,r29
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// clrlwi r7,r8,1
	ctx.r7.u64 = ctx.r8.u32 & 0x7FFFFFFF;
	// stwx r7,r10,r29
	REX_STORE_U32(ctx.r10.u32 + ctx.r29.u32, ctx.r7.u32);
	// lwz r6,140(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x826bcb90
	if (ctx.cr6.lt) goto loc_826BCB90;
loc_826BCBC4:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826bcae0
	if (ctx.cr6.lt) goto loc_826BCAE0;
	// b 0x826bcc8c
	goto loc_826BCC8C;
loc_826BCBD8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r26,7
	ctx.r26.s64 = 7;
	// bl 0x826bba18
	ctx.lr = 0x826BCBE4;
	sub_826BBA18(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826bcc8c
	if (ctx.cr6.eq) goto loc_826BCC8C;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_826BCBF4:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x826bcc1c
	if (!ctx.cr6.eq) goto loc_826BCC1C;
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r8,r9,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lwz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// rlwinm r10,r5,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// b 0x826bcc4c
	goto loc_826BCC4C;
loc_826BCC1C:
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r10,-24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -24);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r10,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r5,r8,r11
	ctx.r5.u64 = ctx.r11.u64 - ctx.r8.u64;
	// lwz r4,0(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r3,r4,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1;
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x826bcc4c
	if (ctx.cr6.eq) goto loc_826BCC4C;
loc_826BCC48:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_826BCC4C:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r10,31,0,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x80000000;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// xor r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// rlwimi r5,r9,0,1,31
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x7FFFFFFF) | (ctx.r5.u64 & 0xFFFFFFFF80000000);
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// lwz r4,136(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmpw cr6,r7,r4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x826bc96c
	if (ctx.cr6.lt) goto loc_826BC96C;
loc_826BCC74:
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826bc95c
	if (ctx.cr6.lt) goto loc_826BC95C;
	// b 0x826bccc8
	goto loc_826BCCC8;
loc_826BCC88:
	// lwz r26,80(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_826BCC8C:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x826bccc8
	if (ctx.cr6.eq) goto loc_826BCCC8;
	// lwz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826bccc8
	if (!ctx.cr6.gt) goto loc_826BCCC8;
	// addi r11,r29,-24
	ctx.r11.s64 = ctx.r29.s64 + -24;
loc_826BCCA8:
	// lwz r9,24(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// not r8,r9
	ctx.r8.u64 = ~ctx.r9.u64;
	// rlwimi r8,r9,0,1,31
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x7FFFFFFF) | (ctx.r8.u64 & 0xFFFFFFFF80000000);
	// stwu r8,24(r11)
	ea = 24 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// lwz r7,144(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x826bcca8
	if (ctx.cr6.lt) goto loc_826BCCA8;
loc_826BCCC8:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne cr6,0x826bcce0
	if (!ctx.cr6.eq) goto loc_826BCCE0;
	// stw r26,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r26.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_826BCCE0:
	// cmpwi cr6,r24,5
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 5, ctx.xer);
	// bne cr6,0x826bccf8
	if (!ctx.cr6.eq) goto loc_826BCCF8;
	// stw r26,21868(r31)
	REX_STORE_U32(ctx.r31.u32 + 21868, ctx.r26.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_826BCCF8:
	// cmpwi cr6,r24,4
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 4, ctx.xer);
	// bne cr6,0x826bcd10
	if (!ctx.cr6.eq) goto loc_826BCD10;
	// stw r26,20932(r31)
	REX_STORE_U32(ctx.r31.u32 + 20932, ctx.r26.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_826BCD10:
	// cmpwi cr6,r24,3
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 3, ctx.xer);
	// bne cr6,0x826bcd28
	if (!ctx.cr6.eq) goto loc_826BCD28;
	// stw r26,14836(r31)
	REX_STORE_U32(ctx.r31.u32 + 14836, ctx.r26.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_826BCD28:
	// cmpwi cr6,r24,2
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 2, ctx.xer);
	// bne cr6,0x826bcd40
	if (!ctx.cr6.eq) goto loc_826BCD40;
	// stw r26,20916(r31)
	REX_STORE_U32(ctx.r31.u32 + 20916, ctx.r26.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_826BCD40:
	// stw r26,348(r31)
	REX_STORE_U32(ctx.r31.u32 + 348, ctx.r26.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826EC5D0) {
	REX_FUNC_PROLOGUE();
	// li r9,8
	ctx.r9.s64 = 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r3,6
	ctx.r11.s64 = ctx.r3.s64 + 6;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826EC5E0:
	// lbz r8,-5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + -5);
	// lbz r9,-6(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + -6);
	// lbz r7,-4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + -4);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,-3(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + -3);
	// lbz r3,-2(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + -2);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lbz r6,-1(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + -1);
	// lbz r7,1(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bdnz 0x826ec5e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826EC5E0;
	// addi r11,r10,4
	ctx.r11.s64 = ctx.r10.s64 + 4;
	// twllei r5,0
	if (ctx.r5.s32 == 0 || ctx.r5.u32 < 0u) ppc_trap(ctx, base, 0);
	// srawi r10,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 3;
	// rotlwi r11,r10,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r3,r10,r5
	ctx.r3.u64 = uint32_t((ctx.r5.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r5.s32 == -1)) ? ctx.r10.s32 / ctx.r5.s32 : 0);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// andc r8,r5,r9
	ctx.r8.u64 = ctx.r5.u64 & ~ctx.r9.u64;
	// twlgei r8,-1
	if (ctx.r8.s32 == -1 || ctx.r8.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826EE508) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x826EE510;
	__savegprlr_14(ctx, base);
	// lwz r23,136(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 136);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r6,44(r1)
	REX_STORE_U32(ctx.r1.u32 + 44, ctx.r6.u32);
	// addi r6,r23,1
	ctx.r6.s64 = ctx.r23.s64 + 1;
	// stw r4,-220(r1)
	REX_STORE_U32(ctx.r1.u32 + -220, ctx.r4.u32);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r22,r6,31,1,31
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r5,36(r1)
	REX_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r23,-184(r1)
	REX_STORE_U32(ctx.r1.u32 + -184, ctx.r23.u32);
	// add r3,r22,r7
	ctx.r3.u64 = ctx.r22.u64 + ctx.r7.u64;
	// stw r22,-200(r1)
	REX_STORE_U32(ctx.r1.u32 + -200, ctx.r22.u32);
	// add r4,r22,r4
	ctx.r4.u64 = ctx.r22.u64 + ctx.r4.u64;
	// stw r3,-208(r1)
	REX_STORE_U32(ctx.r1.u32 + -208, ctx.r3.u32);
	// stw r4,-216(r1)
	REX_STORE_U32(ctx.r1.u32 + -216, ctx.r4.u32);
	// beq cr6,0x826ee8dc
	if (ctx.cr6.eq) goto loc_826EE8DC;
	// li r6,1
	ctx.r6.s64 = 1;
	// srawi. r11,r23,2
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r23.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// ble 0x826ee728
	if (!ctx.cr0.gt) goto loc_826EE728;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826EE564:
	// lbz r11,1(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r6,6(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 6);
	// extsb r4,r11
	ctx.r4.s64 = ctx.r11.s8;
	// lbz r5,7(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 7);
	// lbz r11,9(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 9);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// lbz r30,8(r10)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r10.u32 + 8);
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// lbz r29,3(r10)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// srawi r4,r4,2
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 2;
	// extsb r28,r11
	ctx.r28.s64 = ctx.r11.s8;
	// lbz r27,13(r10)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r10.u32 + 13);
	// srawi r6,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 4;
	// lbz r26,18(r10)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r10.u32 + 18);
	// extsb r24,r30
	ctx.r24.s64 = ctx.r30.s8;
	// lbz r25,19(r10)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r10.u32 + 19);
	// srawi r5,r5,6
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3F) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 6;
	// lbz r22,21(r10)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r10.u32 + 21);
	// extsb r20,r29
	ctx.r20.s64 = ctx.r29.s8;
	// lbz r21,20(r10)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r10.u32 + 20);
	// srawi r28,r28,6
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3F) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 6;
	// lbz r18,15(r10)
	ctx.r18.u64 = REX_LOAD_U8(ctx.r10.u32 + 15);
	// rlwinm r11,r11,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC;
	// lbz r19,2(r10)
	ctx.r19.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// extsb r27,r27
	ctx.r27.s64 = ctx.r27.s8;
	// lbz r17,0(r10)
	ctx.r17.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// srawi r24,r24,4
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0xF) != 0);
	ctx.r24.s64 = ctx.r24.s32 >> 4;
	// lbz r15,14(r10)
	ctx.r15.u64 = REX_LOAD_U8(ctx.r10.u32 + 14);
	// extsb r26,r26
	ctx.r26.s64 = ctx.r26.s8;
	// lbz r16,12(r10)
	ctx.r16.u64 = REX_LOAD_U8(ctx.r10.u32 + 12);
	// srawi r20,r20,2
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x3) != 0);
	ctx.r20.s64 = ctx.r20.s32 >> 2;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// srawi r27,r27,2
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 2;
	// srawi r26,r26,4
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0xF) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 4;
	// rlwimi r4,r6,0,28,29
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xC) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFF3);
	// extsb r25,r25
	ctx.r25.s64 = ctx.r25.s8;
	// rlwimi r28,r24,0,28,29
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0xC) | (ctx.r28.u64 & 0xFFFFFFFFFFFFFFF3);
	// extsb r6,r22
	ctx.r6.s64 = ctx.r22.s8;
	// rlwimi r27,r26,0,28,29
	ctx.r27.u64 = (__builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0xC) | (ctx.r27.u64 & 0xFFFFFFFFFFFFFFF3);
	// extsb r24,r21
	ctx.r24.s64 = ctx.r21.s8;
	// srawi r26,r25,6
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3F) != 0);
	ctx.r26.s64 = ctx.r25.s32 >> 6;
	// srawi r6,r6,6
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 6;
	// srawi r25,r24,4
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0xF) != 0);
	ctx.r25.s64 = ctx.r24.s32 >> 4;
	// rlwimi r4,r5,0,30,31
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x3) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFFC);
	// rlwimi r6,r25,0,28,29
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xC) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFF3);
	// extsb r25,r18
	ctx.r25.s64 = ctx.r18.s8;
	// rlwimi r29,r19,2,22,27
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0x3F0) | (ctx.r29.u64 & 0xFFFFFFFFFFFFFC0F);
	// mr r5,r19
	ctx.r5.u64 = ctx.r19.u64;
	// rlwimi r4,r17,0,24,25
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 0) & 0xC0) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFF3F);
	// srawi r5,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r25.s32 >> 2;
	// lbz r25,4(r10)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// rlwinm r29,r29,2,24,27
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xF0;
	// stb r4,0(r7)
	REX_STORE_U8(ctx.r7.u32 + 0, ctx.r4.u8);
	// rlwimi r6,r5,0,26,27
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x30) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFCF);
	// or r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 | ctx.r11.u64;
	// lbz r29,22(r10)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + 22);
	// rlwimi r28,r20,0,26,27
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x30) | (ctx.r28.u64 & 0xFFFFFFFFFFFFFFCF);
	// rlwinm r4,r30,0,28,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xC;
	// rlwimi r27,r26,0,30,31
	ctx.r27.u64 = (__builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x3) | (ctx.r27.u64 & 0xFFFFFFFFFFFFFFFC);
	// lbz r26,23(r10)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r10.u32 + 23);
	// rlwimi r6,r15,0,24,25
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 0) & 0xC0) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFF3F);
	// or r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 | ctx.r4.u64;
	// rlwimi r28,r19,0,24,25
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 0) & 0xC0) | (ctx.r28.u64 & 0xFFFFFFFFFFFFFF3F);
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// lbz r5,10(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 10);
	// rlwimi r27,r16,0,24,25
	ctx.r27.u64 = (__builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 0) & 0xC0) | (ctx.r27.u64 & 0xFFFFFFFFFFFFFF3F);
	// stb r28,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r28.u8);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// stb r4,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r4.u8);
	// rlwinm r6,r22,0,28,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0xC;
	// lbz r4,16(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 16);
	// stbu r27,1(r7)
	ea = 1 + ctx.r7.u32;
	REX_STORE_U8(ea, ctx.r27.u8);
	ctx.r7.u32 = ea;
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// srawi r6,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 2;
	// lbz r28,11(r10)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r10.u32 + 11);
	// lbz r27,17(r10)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r10.u32 + 17);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// mr r30,r15
	ctx.r30.u64 = ctx.r15.u64;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// extsb r29,r29
	ctx.r29.s64 = ctx.r29.s8;
	// srawi r5,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 2;
	// stbu r11,1(r3)
	ea = 1 + ctx.r3.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r3.u32 = ea;
	// extsb r28,r28
	ctx.r28.s64 = ctx.r28.s8;
	// srawi r4,r4,4
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 4;
	// lbz r24,5(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 5);
	// extsb r11,r27
	ctx.r11.s64 = ctx.r27.s8;
	// srawi r29,r29,6
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x3F) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 6;
	// srawi r28,r28,2
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 2;
	// rlwimi r5,r4,0,28,29
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xC) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFF3);
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
	// extsb r4,r26
	ctx.r4.s64 = ctx.r26.s8;
	// rlwimi r18,r15,2,22,27
	ctx.r18.u64 = (__builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x3F0) | (ctx.r18.u64 & 0xFFFFFFFFFFFFFC0F);
	// rlwimi r28,r11,0,28,29
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC) | (ctx.r28.u64 & 0xFFFFFFFFFFFFFFF3);
	// srawi r11,r4,6
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3F) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 6;
	// rlwinm r4,r18,2,24,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xF0;
	// rlwimi r28,r11,0,30,31
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x3) | (ctx.r28.u64 & 0xFFFFFFFFFFFFFFFC);
	// or r11,r4,r6
	ctx.r11.u64 = ctx.r4.u64 | ctx.r6.u64;
	// rlwinm r6,r21,0,28,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0xC;
	// rlwimi r5,r29,0,30,31
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x3) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFFC);
	// or r4,r11,r6
	ctx.r4.u64 = ctx.r11.u64 | ctx.r6.u64;
	// rlwimi r5,r25,0,24,25
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xC0) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFF3F);
	// rlwimi r28,r24,0,24,25
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0xC0) | (ctx.r28.u64 & 0xFFFFFFFFFFFFFF3F);
	// stbu r4,1(r31)
	ea = 1 + ctx.r31.u32;
	REX_STORE_U8(ea, ctx.r4.u8);
	ctx.r31.u32 = ea;
	// stb r5,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r5.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stb r28,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r28.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// bdnz 0x826ee564
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826EE564;
	// lwz r22,-200(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -200);
	// stw r31,-220(r1)
	REX_STORE_U32(ctx.r1.u32 + -220, ctx.r31.u32);
loc_826EE728:
	// clrlwi r6,r23,30
	ctx.r6.u64 = ctx.r23.u32 & 0x3;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x826ee8c8
	if (ctx.cr6.eq) goto loc_826EE8C8;
	// lbz r11,1(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// rlwinm r5,r23,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 0) & 0x2;
	// lbz r4,3(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// lbz r30,2(r10)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// extsb r29,r4
	ctx.r29.s64 = ctx.r4.s8;
	// lbz r28,0(r10)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// lbz r27,4(r10)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// lbz r25,5(r10)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r10.u32 + 5);
	// srawi r29,r29,2
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x3) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 2;
	// rlwimi r11,r28,0,24,25
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xC0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF3F);
	// rlwimi r4,r30,2,22,27
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x3F0) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFC0F);
	// rlwimi r26,r29,0,26,27
	ctx.r26.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x30) | (ctx.r26.u64 & 0xFFFFFFFFFFFFFFCF);
	// rlwinm r30,r11,0,24,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xF0;
	// rlwinm r28,r4,2,24,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xF0;
	// rlwinm r29,r26,0,24,27
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0xF0;
	// rlwinm r11,r27,0,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFFFFC0;
	// rlwinm r4,r25,0,0,25
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xFFFFFFC0;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// cmplwi cr6,r5,2
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 2, ctx.xer);
	// bne cr6,0x826ee818
	if (!ctx.cr6.eq) goto loc_826EE818;
	// lbz r5,1(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r26,0(r10)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r25,2(r10)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// lbz r27,3(r10)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// extsb r26,r26
	ctx.r26.s64 = ctx.r26.s8;
	// extsb r20,r25
	ctx.r20.s64 = ctx.r25.s8;
	// lbz r21,4(r10)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// rlwinm r24,r27,0,28,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xC;
	// lbz r19,5(r10)
	ctx.r19.u64 = REX_LOAD_U8(ctx.r10.u32 + 5);
	// srawi r5,r5,6
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3F) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 6;
	// extsb r27,r27
	ctx.r27.s64 = ctx.r27.s8;
	// srawi r26,r26,4
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0xF) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 4;
	// srawi r20,r20,4
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0xF) != 0);
	ctx.r20.s64 = ctx.r20.s32 >> 4;
	// srawi r27,r27,6
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3F) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 6;
	// extsb r21,r21
	ctx.r21.s64 = ctx.r21.s8;
	// extsb r19,r19
	ctx.r19.s64 = ctx.r19.s8;
	// srawi r24,r24,2
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x3) != 0);
	ctx.r24.s64 = ctx.r24.s32 >> 2;
	// rlwimi r20,r27,0,30,31
	ctx.r20.u64 = (__builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x3) | (ctx.r20.u64 & 0xFFFFFFFFFFFFFFFC);
	// rlwimi r5,r26,0,28,29
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0xC) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFF3);
	// srawi r21,r21,2
	ctx.xer.ca = (ctx.r21.s32 < 0) & ((ctx.r21.u32 & 0x3) != 0);
	ctx.r21.s64 = ctx.r21.s32 >> 2;
	// rlwinm r27,r25,0,28,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xC;
	// srawi r26,r19,2
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x3) != 0);
	ctx.r26.s64 = ctx.r19.s32 >> 2;
	// or r27,r24,r27
	ctx.r27.u64 = ctx.r24.u64 | ctx.r27.u64;
	// clrlwi r5,r5,28
	ctx.r5.u64 = ctx.r5.u32 & 0xF;
	// clrlwi r25,r20,28
	ctx.r25.u64 = ctx.r20.u32 & 0xF;
	// rlwinm r24,r21,0,26,27
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x30;
	// rlwinm r26,r26,0,26,27
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x30;
	// or r30,r5,r30
	ctx.r30.u64 = ctx.r5.u64 | ctx.r30.u64;
	// or r29,r25,r29
	ctx.r29.u64 = ctx.r25.u64 | ctx.r29.u64;
	// or r28,r27,r28
	ctx.r28.u64 = ctx.r27.u64 | ctx.r28.u64;
	// or r11,r24,r11
	ctx.r11.u64 = ctx.r24.u64 | ctx.r11.u64;
	// or r4,r26,r4
	ctx.r4.u64 = ctx.r26.u64 | ctx.r4.u64;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
loc_826EE818:
	// stb r28,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stb r30,0(r7)
	REX_STORE_U8(ctx.r7.u32 + 0, ctx.r30.u8);
	// cmplwi cr6,r6,3
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 3, ctx.xer);
	// stb r29,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r29.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stw r31,-220(r1)
	REX_STORE_U32(ctx.r1.u32 + -220, ctx.r31.u32);
	// bne cr6,0x826ee8b8
	if (!ctx.cr6.eq) goto loc_826EE8B8;
	// lbz r6,1(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r5,3(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// lbz r30,2(r10)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r29,4(r10)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// extsb r28,r5
	ctx.r28.s64 = ctx.r5.s8;
	// lbz r25,0(r10)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// srawi r6,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 2;
	// lbz r26,5(r10)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r10.u32 + 5);
	// rlwimi r5,r30,2,22,27
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x3F0) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFC0F);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// srawi r28,r28,2
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 2;
	// extsb r29,r29
	ctx.r29.s64 = ctx.r29.s8;
	// rlwimi r6,r25,0,24,25
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xC0) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFF3F);
	// extsb r27,r26
	ctx.r27.s64 = ctx.r26.s8;
	// rlwinm r5,r5,2,24,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xF0;
	// rlwimi r30,r28,0,26,27
	ctx.r30.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x30) | (ctx.r30.u64 & 0xFFFFFFFFFFFFFFCF);
	// srawi r29,r29,4
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 4;
	// stb r5,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r5.u8);
	// rlwinm r6,r6,0,24,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xF0;
	// srawi r28,r27,4
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0xF) != 0);
	ctx.r28.s64 = ctx.r27.s32 >> 4;
	// rlwinm r5,r30,0,24,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xF0;
	// stb r6,1(r7)
	REX_STORE_U8(ctx.r7.u32 + 1, ctx.r6.u8);
	// rlwinm r30,r29,0,28,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xC;
	// rlwinm r7,r28,0,28,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xC;
	// stb r5,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r5.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// or r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 | ctx.r11.u64;
	// or r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 | ctx.r4.u64;
	// stw r31,-220(r1)
	REX_STORE_U32(ctx.r1.u32 + -220, ctx.r31.u32);
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_826EE8B8:
	// stb r11,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r11.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stb r4,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r4.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_826EE8C8:
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// add r4,r22,r31
	ctx.r4.u64 = ctx.r22.u64 + ctx.r31.u64;
	// add r3,r22,r3
	ctx.r3.u64 = ctx.r22.u64 + ctx.r3.u64;
	// stw r4,-216(r1)
	REX_STORE_U32(ctx.r1.u32 + -216, ctx.r4.u32);
	// stw r3,-208(r1)
	REX_STORE_U32(ctx.r1.u32 + -208, ctx.r3.u32);
loc_826EE8DC:
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826eee8c
	if (!ctx.cr6.lt) goto loc_826EEE8C;
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// lwz r30,36(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 36);
	// lwz r5,44(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 44);
	// srawi r6,r23,2
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r23.s32 >> 2;
	// addi r27,r30,-1
	ctx.r27.s64 = ctx.r30.s64 + -1;
	// stw r11,-180(r1)
	REX_STORE_U32(ctx.r1.u32 + -180, ctx.r11.u32);
	// addi r26,r5,-1
	ctx.r26.s64 = ctx.r5.s64 + -1;
	// stw r6,-176(r1)
	REX_STORE_U32(ctx.r1.u32 + -176, ctx.r6.u32);
	// addi r25,r8,-1
	ctx.r25.s64 = ctx.r8.s64 + -1;
	// stw r27,36(r1)
	REX_STORE_U32(ctx.r1.u32 + 36, ctx.r27.u32);
	// addi r24,r9,-1
	ctx.r24.s64 = ctx.r9.s64 + -1;
	// stw r26,44(r1)
	REX_STORE_U32(ctx.r1.u32 + 44, ctx.r26.u32);
	// stw r25,60(r1)
	REX_STORE_U32(ctx.r1.u32 + 60, ctx.r25.u32);
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// stw r24,68(r1)
	REX_STORE_U32(ctx.r1.u32 + 68, ctx.r24.u32);
	// b 0x826ee930
	goto loc_826EE930;
loc_826EE92C:
	// lwz r6,-176(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -176);
loc_826EE930:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble cr6,0x826eec08
	if (!ctx.cr6.gt) goto loc_826EEC08;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_826EE93C:
	// lbz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 8);
	// lbz r9,7(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// extsb r6,r10
	ctx.r6.s64 = ctx.r10.s8;
	// lbz r5,10(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 10);
	// extsb r4,r9
	ctx.r4.s64 = ctx.r9.s8;
	// lbz r31,9(r11)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// extsb r30,r8
	ctx.r30.s64 = ctx.r8.s8;
	// lbz r29,4(r11)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// srawi r6,r6,6
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 6;
	// lbz r26,19(r11)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r11.u32 + 19);
	// extsb r28,r5
	ctx.r28.s64 = ctx.r5.s8;
	// srawi r4,r4,4
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 4;
	// lbz r27,20(r11)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r11.u32 + 20);
	// extsb r24,r31
	ctx.r24.s64 = ctx.r31.s8;
	// lbz r22,3(r11)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// srawi r30,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 2;
	// lbz r25,14(r11)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 14);
	// extsb r20,r29
	ctx.r20.s64 = ctx.r29.s8;
	// lbz r23,1(r11)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// srawi r28,r28,6
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3F) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 6;
	// stb r26,-224(r1)
	REX_STORE_U8(ctx.r1.u32 + -224, ctx.r26.u8);
	// rlwinm r10,r10,0,28,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xC;
	// lbz r21,13(r11)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r11.u32 + 13);
	// rlwinm r5,r5,0,28,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xC;
	// lbz r16,22(r11)
	ctx.r16.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
	// srawi r24,r24,4
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0xF) != 0);
	ctx.r24.s64 = ctx.r24.s32 >> 4;
	// lwz r19,-220(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + -220);
	// rlwimi r6,r4,0,28,29
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xC) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFF3);
	// lbz r17,21(r11)
	ctx.r17.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// srawi r20,r20,2
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x3) != 0);
	ctx.r20.s64 = ctx.r20.s32 >> 2;
	// lbz r18,16(r11)
	ctx.r18.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
	// extsb r14,r27
	ctx.r14.s64 = ctx.r27.s8;
	// lbz r15,15(r11)
	ctx.r15.u64 = REX_LOAD_U8(ctx.r11.u32 + 15);
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// extsb r26,r26
	ctx.r26.s64 = ctx.r26.s8;
	// srawi r5,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 2;
	// rlwimi r6,r30,0,26,27
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x30) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFCF);
	// srawi r14,r14,6
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x3F) != 0);
	ctx.r14.s64 = ctx.r14.s32 >> 6;
	// srawi r26,r26,4
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0xF) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 4;
	// rlwimi r28,r24,0,28,29
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0xC) | (ctx.r28.u64 & 0xFFFFFFFFFFFFFFF3);
	// rlwimi r29,r22,2,22,27
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 2) & 0x3F0) | (ctx.r29.u64 & 0xFFFFFFFFFFFFFC0F);
	// extsb r4,r25
	ctx.r4.s64 = ctx.r25.s8;
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// rlwimi r6,r23,0,24,25
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 0) & 0xC0) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFF3F);
	// rlwimi r8,r23,2,22,27
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0x3F0) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFC0F);
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// stb r6,0(r7)
	REX_STORE_U8(ctx.r7.u32 + 0, ctx.r6.u8);
	// rlwimi r14,r26,0,28,29
	ctx.r14.u64 = (__builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0xC) | (ctx.r14.u64 & 0xFFFFFFFFFFFFFFF3);
	// srawi r4,r4,2
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 2;
	// rlwimi r28,r20,0,26,27
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x30) | (ctx.r28.u64 & 0xFFFFFFFFFFFFFFCF);
	// rlwinm r30,r29,2,24,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xF0;
	// lbz r29,5(r11)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rlwinm r8,r8,2,24,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xF0;
	// or r6,r30,r5
	ctx.r6.u64 = ctx.r30.u64 | ctx.r5.u64;
	// lbz r30,11(r11)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r11.u32 + 11);
	// rlwimi r14,r4,0,26,27
	ctx.r14.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x30) | (ctx.r14.u64 & 0xFFFFFFFFFFFFFFCF);
	// rlwimi r28,r22,0,24,25
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0xC0) | (ctx.r28.u64 & 0xFFFFFFFFFFFFFF3F);
	// rlwinm r5,r31,0,28,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xC;
	// lbz r31,24(r11)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r11.u32 + 24);
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// stb r28,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r28.u8);
	// rlwinm r9,r9,0,28,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xC;
	// lbz r28,17(r11)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r11.u32 + 17);
	// rlwimi r14,r21,0,24,25
	ctx.r14.u64 = (__builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0xC0) | (ctx.r14.u64 & 0xFFFFFFFFFFFFFF3F);
	// or r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 | ctx.r5.u64;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// stbu r14,1(r7)
	ea = 1 + ctx.r7.u32;
	REX_STORE_U8(ea, ctx.r14.u8);
	ctx.r7.u32 = ea;
	// or r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 | ctx.r9.u64;
	// extsb r5,r16
	ctx.r5.s64 = ctx.r16.s8;
	// extsb r10,r17
	ctx.r10.s64 = ctx.r17.s8;
	// stb r4,0(r19)
	REX_STORE_U8(ctx.r19.u32 + 0, ctx.r4.u8);
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// lbz r4,23(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// srawi r5,r5,6
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3F) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 6;
	// rlwinm r20,r27,0,28,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xC;
	// lbz r27,6(r11)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// addi r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 1;
	// srawi r10,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 4;
	// rlwinm r14,r16,0,28,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 0) & 0xC;
	// extsb r26,r18
	ctx.r26.s64 = ctx.r18.s8;
	// lwz r22,-216(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -216);
	// rlwimi r5,r10,0,28,29
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xC) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFF3);
	// lbz r24,12(r11)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 12);
	// rlwinm r23,r4,0,28,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xC;
	// mr r8,r22
	ctx.r8.u64 = ctx.r22.u64;
	// stw r6,-192(r1)
	REX_STORE_U32(ctx.r1.u32 + -192, ctx.r6.u32);
	// rotlwi r10,r19,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r19.u32, 0);
	// lbz r19,18(r11)
	ctx.r19.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// rlwimi r25,r21,2,22,27
	ctx.r25.u64 = (__builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0x3F0) | (ctx.r25.u64 & 0xFFFFFFFFFFFFFC0F);
	// std r11,-168(r1)
	REX_STORE_U64(ctx.r1.u32 + -168, ctx.r11.u64);
	// stb r3,0(r22)
	REX_STORE_U8(ctx.r22.u32 + 0, ctx.r3.u8);
	// mr r22,r30
	ctx.r22.u64 = ctx.r30.u64;
	// srawi r3,r26,2
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r26.s32 >> 2;
	// stb r27,-223(r1)
	REX_STORE_U8(ctx.r1.u32 + -223, ctx.r27.u8);
	// mr r21,r27
	ctx.r21.u64 = ctx.r27.u64;
	// lwz r9,-208(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -208);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r7,36(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 36);
	// rlwimi r22,r29,2,22,27
	ctx.r22.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0x3F0) | (ctx.r22.u64 & 0xFFFFFFFFFFFFFC0F);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// srawi r20,r20,2
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x3) != 0);
	ctx.r20.s64 = ctx.r20.s32 >> 2;
	// srawi r14,r14,2
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x3) != 0);
	ctx.r14.s64 = ctx.r14.s32 >> 2;
	// mr r23,r29
	ctx.r23.u64 = ctx.r29.u64;
	// rlwinm r16,r31,0,28,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xC;
	// srawi r6,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 2;
	// rlwinm r23,r22,2,24,27
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 2) & 0xF0;
	// lbz r22,-224(r1)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r1.u32 + -224);
	// rlwimi r11,r21,2,22,27
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0x3F0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFC0F);
	// rlwimi r5,r3,0,26,27
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x30) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFCF);
	// extsb r27,r28
	ctx.r27.s64 = ctx.r28.s8;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// or r6,r23,r6
	ctx.r6.u64 = ctx.r23.u64 | ctx.r6.u64;
	// srawi r3,r16,2
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r16.s32 >> 2;
	// rlwinm r21,r11,2,24,27
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xF0;
	// rlwinm r28,r28,0,28,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xC;
	// rlwimi r5,r15,0,24,25
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 0) & 0xC0) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFF3F);
	// mr r26,r15
	ctx.r26.u64 = ctx.r15.u64;
	// or r3,r21,r3
	ctx.r3.u64 = ctx.r21.u64 | ctx.r3.u64;
	// stbu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r5.u8);
	ctx.r9.u32 = ea;
	// srawi r4,r4,6
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3F) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 6;
	// rlwinm r26,r25,2,24,27
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xF0;
	// or r6,r6,r28
	ctx.r6.u64 = ctx.r6.u64 | ctx.r28.u64;
	// rlwinm r23,r19,0,28,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 0) & 0xC;
	// srawi r27,r27,4
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0xF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 4;
	// stb r6,1(r7)
	REX_STORE_U8(ctx.r7.u32 + 1, ctx.r6.u8);
	// extsb r30,r30
	ctx.r30.s64 = ctx.r30.s8;
	// lwz r6,44(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 44);
	// or r5,r3,r23
	ctx.r5.u64 = ctx.r3.u64 | ctx.r23.u64;
	// or r26,r26,r20
	ctx.r26.u64 = ctx.r26.u64 | ctx.r20.u64;
	// rlwinm r22,r22,0,28,29
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0xC;
	// srawi r30,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 2;
	// rlwimi r4,r27,0,28,29
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xC) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFF3);
	// stb r5,1(r6)
	REX_STORE_U8(ctx.r6.u32 + 1, ctx.r5.u8);
	// extsb r3,r31
	ctx.r3.s64 = ctx.r31.s8;
	// extsb r31,r19
	ctx.r31.s64 = ctx.r19.s8;
	// or r26,r26,r22
	ctx.r26.u64 = ctx.r26.u64 | ctx.r22.u64;
	// rlwimi r4,r30,0,26,27
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x30) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFCF);
	// srawi r3,r3,6
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3F) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 6;
	// stbu r26,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r26.u8);
	ctx.r10.u32 = ea;
	// rlwimi r18,r15,2,22,27
	ctx.r18.u64 = (__builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x3F0) | (ctx.r18.u64 & 0xFFFFFFFFFFFFFC0F);
	// srawi r31,r31,4
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0xF) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 4;
	// extsb r30,r24
	ctx.r30.s64 = ctx.r24.s8;
	// rlwinm r25,r18,2,24,27
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xF0;
	// srawi r5,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r30.s32 >> 2;
	// rlwimi r3,r31,0,28,29
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xC) | (ctx.r3.u64 & 0xFFFFFFFFFFFFFFF3);
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
	// lwz r10,60(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 60);
	// or r27,r25,r14
	ctx.r27.u64 = ctx.r25.u64 | ctx.r14.u64;
	// rlwimi r3,r5,0,26,27
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x30) | (ctx.r3.u64 & 0xFFFFFFFFFFFFFFCF);
	// lbz r5,-223(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -223);
	// rlwinm r25,r17,0,28,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 0) & 0xC;
	// stw r31,-220(r1)
	REX_STORE_U32(ctx.r1.u32 + -220, ctx.r31.u32);
	// rlwimi r4,r29,0,24,25
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xC0) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFF3F);
	// or r27,r27,r25
	ctx.r27.u64 = ctx.r27.u64 | ctx.r25.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stb r4,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r4.u8);
	// addi r25,r10,1
	ctx.r25.s64 = ctx.r10.s64 + 1;
	// lwz r10,68(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 68);
	// stbu r27,1(r8)
	ea = 1 + ctx.r8.u32;
	REX_STORE_U8(ea, ctx.r27.u8);
	ctx.r8.u32 = ea;
	// rlwimi r30,r5,0,24,25
	ctx.r30.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xC0) | (ctx.r30.u64 & 0xFFFFFFFFFFFFFF3F);
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// ld r11,-168(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -168);
	// addi r27,r7,1
	ctx.r27.s64 = ctx.r7.s64 + 1;
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// lwz r7,-192(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -192);
	// addi r26,r6,1
	ctx.r26.s64 = ctx.r6.s64 + 1;
	// stw r25,60(r1)
	REX_STORE_U32(ctx.r1.u32 + 60, ctx.r25.u32);
	// addi r24,r10,1
	ctx.r24.s64 = ctx.r10.s64 + 1;
	// stw r3,-208(r1)
	REX_STORE_U32(ctx.r1.u32 + -208, ctx.r3.u32);
	// stw r4,-216(r1)
	REX_STORE_U32(ctx.r1.u32 + -216, ctx.r4.u32);
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// stw r27,36(r1)
	REX_STORE_U32(ctx.r1.u32 + 36, ctx.r27.u32);
	// stw r26,44(r1)
	REX_STORE_U32(ctx.r1.u32 + 44, ctx.r26.u32);
	// stb r30,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r30.u8);
	// stw r24,68(r1)
	REX_STORE_U32(ctx.r1.u32 + 68, ctx.r24.u32);
	// bdnz 0x826ee93c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826EE93C;
	// lwz r22,-200(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -200);
	// lwz r23,-184(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -184);
loc_826EEC08:
	// clrlwi r10,r23,30
	ctx.r10.u64 = ctx.r23.u32 & 0x3;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x826eee60
	if (ctx.cr6.eq) goto loc_826EEE60;
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r21,r23,0,30,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 0) & 0x2;
	// lbz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r6,1(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// lbz r5,3(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// extsb r30,r9
	ctx.r30.s64 = ctx.r9.s8;
	// srawi r8,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 2;
	// lbz r20,5(r11)
	ctx.r20.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lbz r19,6(r11)
	ctx.r19.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// srawi r30,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 2;
	// rlwimi r29,r8,0,26,27
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x30) | (ctx.r29.u64 & 0xFFFFFFFFFFFFFFCF);
	// rlwimi r28,r30,0,26,27
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x30) | (ctx.r28.u64 & 0xFFFFFFFFFFFFFFCF);
	// rlwimi r10,r6,2,22,27
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3F0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFC0F);
	// rlwimi r9,r5,2,22,27
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3F0) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFC0F);
	// rlwinm r5,r29,0,24,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xF0;
	// rlwinm r29,r28,0,24,27
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xF0;
	// rlwinm r30,r10,2,24,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xF0;
	// rlwinm r28,r9,2,24,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xF0;
	// rlwinm r10,r20,0,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0xFFFFFFC0;
	// rlwinm r9,r19,0,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 0) & 0xFFFFFFC0;
	// rlwinm r8,r20,4,24,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 4) & 0xC0;
	// rlwinm r6,r19,4,24,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 4) & 0xC0;
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
	// cmplwi cr6,r21,2
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 2, ctx.xer);
	// bne cr6,0x826eed7c
	if (!ctx.cr6.eq) goto loc_826EED7C;
	// lbz r21,1(r11)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// lbz r25,2(r11)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// extsb r23,r21
	ctx.r23.s64 = ctx.r21.s8;
	// std r7,-168(r1)
	REX_STORE_U64(ctx.r1.u32 + -168, ctx.r7.u64);
	// rlwinm r16,r25,0,28,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xC;
	// std r4,-192(r1)
	REX_STORE_U64(ctx.r1.u32 + -192, ctx.r4.u64);
	// extsb r18,r25
	ctx.r18.s64 = ctx.r25.s8;
	// std r31,-216(r1)
	REX_STORE_U64(ctx.r1.u32 + -216, ctx.r31.u64);
	// srawi r25,r23,4
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0xF) != 0);
	ctx.r25.s64 = ctx.r23.s32 >> 4;
	// std r3,-208(r1)
	REX_STORE_U64(ctx.r1.u32 + -208, ctx.r3.u64);
	// lbz r19,3(r11)
	ctx.r19.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// srawi r18,r18,6
	ctx.xer.ca = (ctx.r18.s32 < 0) & ((ctx.r18.u32 & 0x3F) != 0);
	ctx.r18.s64 = ctx.r18.s32 >> 6;
	// stb r25,-224(r1)
	REX_STORE_U8(ctx.r1.u32 + -224, ctx.r25.u8);
	// srawi r16,r16,2
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x3) != 0);
	ctx.r16.s64 = ctx.r16.s32 >> 2;
	// lbz r20,4(r11)
	ctx.r20.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi r7,r19,24
	ctx.r7.u64 = ctx.r19.u32 & 0xFF;
	// lbz r17,5(r11)
	ctx.r17.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rlwinm r21,r21,0,28,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0xC;
	// rlwinm r14,r20,0,28,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0xC;
	// lbz r15,6(r11)
	ctx.r15.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// extsb r20,r20
	ctx.r20.s64 = ctx.r20.s8;
	// stb r19,-223(r1)
	REX_STORE_U8(ctx.r1.u32 + -223, ctx.r19.u8);
	// srawi r7,r7,4
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 4;
	// lwz r24,68(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 68);
	// srawi r20,r20,6
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x3F) != 0);
	ctx.r20.s64 = ctx.r20.s32 >> 6;
	// lwz r25,60(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 60);
	// extsb r4,r17
	ctx.r4.s64 = ctx.r17.s8;
	// lwz r22,-200(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -200);
	// extsb r3,r15
	ctx.r3.s64 = ctx.r15.s8;
	// lwz r23,-184(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -184);
	// rlwimi r7,r20,0,30,31
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x3) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFFC);
	// srawi r14,r14,2
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x3) != 0);
	ctx.r14.s64 = ctx.r14.s32 >> 2;
	// srawi r4,r4,2
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 2;
	// rlwinm r20,r19,0,28,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 0) & 0xC;
	// srawi r19,r3,2
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	ctx.r19.s64 = ctx.r3.s32 >> 2;
	// or r21,r16,r21
	ctx.r21.u64 = ctx.r16.u64 | ctx.r21.u64;
	// or r20,r14,r20
	ctx.r20.u64 = ctx.r14.u64 | ctx.r20.u64;
	// clrlwi r16,r7,28
	ctx.r16.u64 = ctx.r7.u32 & 0xF;
	// ld r7,-168(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + -168);
	// rlwinm r14,r4,0,26,27
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x30;
	// ld r4,-192(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + -192);
	// rlwinm r19,r19,0,26,27
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 0) & 0x30;
	// ld r3,-208(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + -208);
	// or r30,r21,r30
	ctx.r30.u64 = ctx.r21.u64 | ctx.r30.u64;
	// lbz r31,-224(r1)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r1.u32 + -224);
	// or r29,r16,r29
	ctx.r29.u64 = ctx.r16.u64 | ctx.r29.u64;
	// or r28,r20,r28
	ctx.r28.u64 = ctx.r20.u64 | ctx.r28.u64;
	// rlwimi r31,r18,0,30,31
	ctx.r31.u64 = (__builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 0) & 0x3) | (ctx.r31.u64 & 0xFFFFFFFFFFFFFFFC);
	// rlwinm r18,r17,2,26,27
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x30;
	// rlwinm r17,r15,2,26,27
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x30;
	// clrlwi r15,r31,28
	ctx.r15.u64 = ctx.r31.u32 & 0xF;
	// ld r31,-216(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -216);
	// or r8,r18,r8
	ctx.r8.u64 = ctx.r18.u64 | ctx.r8.u64;
	// or r6,r17,r6
	ctx.r6.u64 = ctx.r17.u64 | ctx.r6.u64;
	// or r5,r15,r5
	ctx.r5.u64 = ctx.r15.u64 | ctx.r5.u64;
	// or r10,r14,r10
	ctx.r10.u64 = ctx.r14.u64 | ctx.r10.u64;
	// or r9,r19,r9
	ctx.r9.u64 = ctx.r19.u64 | ctx.r9.u64;
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
loc_826EED7C:
	// stb r5,0(r7)
	REX_STORE_U8(ctx.r7.u32 + 0, ctx.r5.u8);
	// clrlwi r5,r23,30
	ctx.r5.u64 = ctx.r23.u32 & 0x3;
	// stb r30,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r30.u8);
	// stb r29,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r29.u8);
	// cmplwi cr6,r5,3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 3, ctx.xer);
	// stb r28,0(r4)
	REX_STORE_U8(ctx.r4.u32 + 0, ctx.r28.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// bne cr6,0x826eee40
	if (!ctx.cr6.eq) goto loc_826EEE40;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// clrlwi r30,r8,24
	ctx.r30.u64 = ctx.r8.u32 & 0xFF;
	// lbz r29,4(r11)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// lbz r28,1(r11)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r8,r5
	ctx.r8.s64 = ctx.r5.s8;
	// lbz r21,3(r11)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// extsb r20,r29
	ctx.r20.s64 = ctx.r29.s8;
	// srawi r18,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r18.s64 = ctx.r8.s32 >> 2;
	// lbz r19,5(r11)
	ctx.r19.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// mr r17,r28
	ctx.r17.u64 = ctx.r28.u64;
	// lbzu r8,6(r11)
	ea = 6 + ctx.r11.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// srawi r20,r20,2
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x3) != 0);
	ctx.r20.s64 = ctx.r20.s32 >> 2;
	// mr r16,r21
	ctx.r16.u64 = ctx.r21.u64;
	// rlwimi r17,r18,0,26,27
	ctx.r17.u64 = (__builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 0) & 0x30) | (ctx.r17.u64 & 0xFFFFFFFFFFFFFFCF);
	// rlwimi r5,r28,2,22,27
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0x3F0) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFC0F);
	// rlwimi r16,r20,0,26,27
	ctx.r16.u64 = (__builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x30) | (ctx.r16.u64 & 0xFFFFFFFFFFFFFFCF);
	// rlwinm r20,r17,0,24,27
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 0) & 0xF0;
	// rlwimi r29,r21,2,22,27
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0x3F0) | (ctx.r29.u64 & 0xFFFFFFFFFFFFFC0F);
	// extsb r15,r19
	ctx.r15.s64 = ctx.r19.s8;
	// stb r20,1(r7)
	REX_STORE_U8(ctx.r7.u32 + 1, ctx.r20.u8);
	// extsb r14,r8
	ctx.r14.s64 = ctx.r8.s8;
	// rlwinm r5,r5,2,24,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xF0;
	// srawi r28,r15,4
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0xF) != 0);
	ctx.r28.s64 = ctx.r15.s32 >> 4;
	// rlwinm r7,r29,2,24,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xF0;
	// stb r5,1(r31)
	REX_STORE_U8(ctx.r31.u32 + 1, ctx.r5.u8);
	// srawi r21,r14,4
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0xF) != 0);
	ctx.r21.s64 = ctx.r14.s32 >> 4;
	// rlwinm r5,r8,0,28,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xC;
	// stb r7,0(r4)
	REX_STORE_U8(ctx.r4.u32 + 0, ctx.r7.u8);
	// rlwinm r8,r28,0,28,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xC;
	// rlwinm r18,r16,0,24,27
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 0) & 0xF0;
	// rlwinm r7,r21,0,28,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0xC;
	// rlwinm r31,r19,0,28,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 0) & 0xC;
	// stb r18,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r18.u8);
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// or r8,r31,r30
	ctx.r8.u64 = ctx.r31.u64 | ctx.r30.u64;
	// or r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 | ctx.r6.u64;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
loc_826EEE40:
	// stbu r8,1(r27)
	ea = 1 + ctx.r27.u32;
	REX_STORE_U8(ea, ctx.r8.u8);
	ctx.r27.u32 = ea;
	// stbu r6,1(r26)
	ea = 1 + ctx.r26.u32;
	REX_STORE_U8(ea, ctx.r6.u8);
	ctx.r26.u32 = ea;
	// stbu r10,1(r25)
	ea = 1 + ctx.r25.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r25.u32 = ea;
	// stbu r9,1(r24)
	ea = 1 + ctx.r24.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r24.u32 = ea;
	// stw r27,36(r1)
	REX_STORE_U32(ctx.r1.u32 + 36, ctx.r27.u32);
	// stw r26,44(r1)
	REX_STORE_U32(ctx.r1.u32 + 44, ctx.r26.u32);
	// stw r25,60(r1)
	REX_STORE_U32(ctx.r1.u32 + 60, ctx.r25.u32);
	// stw r24,68(r1)
	REX_STORE_U32(ctx.r1.u32 + 68, ctx.r24.u32);
loc_826EEE60:
	// lwz r10,-180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -180);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// stw r4,-220(r1)
	REX_STORE_U32(ctx.r1.u32 + -220, ctx.r4.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r3,r22,r3
	ctx.r3.u64 = ctx.r22.u64 + ctx.r3.u64;
	// add r4,r22,r4
	ctx.r4.u64 = ctx.r22.u64 + ctx.r4.u64;
	// stw r10,-180(r1)
	REX_STORE_U32(ctx.r1.u32 + -180, ctx.r10.u32);
	// stw r3,-208(r1)
	REX_STORE_U32(ctx.r1.u32 + -208, ctx.r3.u32);
	// stw r4,-216(r1)
	REX_STORE_U32(ctx.r1.u32 + -216, ctx.r4.u32);
	// bne 0x826ee92c
	if (!ctx.cr0.eq) goto loc_826EE92C;
loc_826EEE8C:
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827394C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lbz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// cmpw r5,r4
	ctx.cr0.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, ctx.xer);
	// beq cr6,0x82739504
	if (ctx.cr6.eq) goto loc_82739504;
	// li r3,0
	ctx.r3.s64 = 0;
	// beq 0x827394f0
	if (ctx.cr0.eq) goto loc_827394F0;
loc_827394DC:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x82739514
	if (ctx.cr6.eq) goto loc_82739514;
	// lbzu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r5.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// cmpw r4,r5
	ctx.cr0.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// bne 0x827394dc
	if (!ctx.cr0.eq) goto loc_827394DC;
loc_827394F0:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lbzu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r5.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// cmpw r4,r5
	ctx.cr0.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// beq 0x827394f0
	if (ctx.cr0.eq) goto loc_827394F0;
	// b 0x827394dc
	goto loc_827394DC;
loc_82739504:
	// beq 0x82739514
	if (ctx.cr0.eq) goto loc_82739514;
	// lbzu r5,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r5.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// cmpwi r5,0
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// b 0x82739504
	goto loc_82739504;
loc_82739514:
	// blr 
	return;
}

DEFINE_REX_FUNC(__savegprlr_29) {
	REX_FUNC_PROLOGUE();
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

DEFINE_REX_FUNC(__restgprlr_23) {
	REX_FUNC_PROLOGUE();
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

DEFINE_REX_FUNC(sub_8273AED8) {
	REX_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x8273ade8
	sub_8273ADE8(ctx, base);
	return;
}

DEFINE_REX_FUNC(__savefpr_18) {
	REX_FUNC_PROLOGUE();
	// stfd f18,-112(r12)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r12.u32 + -112, ctx.f18.u64);
	// stfd f19,-104(r12)
	REX_STORE_U64(ctx.r12.u32 + -104, ctx.f19.u64);
	// stfd f20,-96(r12)
	REX_STORE_U64(ctx.r12.u32 + -96, ctx.f20.u64);
	// stfd f21,-88(r12)
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

DEFINE_REX_FUNC(__savevmx_20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(__savevmx_110) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(__restvmx_69) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-944
	ctx.r11.s64 = -944;
	// lvx128 v69,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v69.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-928
	ctx.r11.s64 = -928;
	// lvx128 v70,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v70.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-912
	ctx.r11.s64 = -912;
	// lvx128 v71,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v71.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-896
	ctx.r11.s64 = -896;
	// lvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v72.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-880
	ctx.r11.s64 = -880;
	// lvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v73.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-864
	ctx.r11.s64 = -864;
	// lvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v74.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-848
	ctx.r11.s64 = -848;
	// lvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v75.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-832
	ctx.r11.s64 = -832;
	// lvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v76.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v77.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v78.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v79.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v80.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v81.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v82.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v83.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v84.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v85.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v86.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v87.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v88.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v89.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v90.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v91.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v92.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v93.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v94.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v95.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v96.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v97.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v98.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

DEFINE_REX_FUNC(sub_8274A1D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8274A1E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// lwz r30,268(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// lwz r29,260(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 260);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// li r4,20
	ctx.r4.s64 = 20;
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// stw r4,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r4.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r30,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r30.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r29,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x82749ee8
	ctx.lr = 0x8274A238;
	sub_82749EE8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8274BDC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8274BDC8;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r31,r4,12
	ctx.r31.s64 = ctx.r4.s64 + 12;
	// addi r29,r11,-4
	ctx.r29.s64 = ctx.r11.s64 + -4;
	// li r30,4
	ctx.r30.s64 = 4;
	// stvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8274BDE8:
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lis r5,4
	ctx.r5.s64 = 262144;
	// lwzu r11,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// slw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// and r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ctx.r9.u64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8274a620
	ctx.lr = 0x8274BE14;
	sub_8274A620(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// lwzx r9,r11,r28
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stwx r10,r11,r28
	REX_STORE_U32(ctx.r11.u32 + ctx.r28.u32, ctx.r10.u32);
	// bne 0x8274bde8
	if (!ctx.cr0.eq) goto loc_8274BDE8;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82754820) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82754828;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lwz r10,244(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 244);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-29940
	ctx.r11.s64 = ctx.r11.s64 + -29940;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82754898
	if (ctx.cr6.eq) goto loc_82754898;
	// lwz r11,248(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82754898
	if (ctx.cr6.eq) goto loc_82754898;
	// lwz r28,212(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 212);
	// lwz r10,216(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 216);
	// cmplw cr6,r28,r10
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82754898
	if (!ctx.cr6.lt) goto loc_82754898;
	// addi r29,r11,-4
	ctx.r29.s64 = ctx.r11.s64 + -4;
loc_82754868:
	// lwz r30,200(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// b 0x8275487c
	goto loc_8275487C;
loc_82754870:
	// lwzu r3,8(r29)
	ea = 8 + ctx.r29.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// bl 0x825ac978
	ctx.lr = 0x82754878;
	sub_825AC978(ctx, base);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
loc_8275487C:
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82754870
	if (ctx.cr6.lt) goto loc_82754870;
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82754868
	if (ctx.cr6.lt) goto loc_82754868;
loc_82754898:
	// lwz r3,240(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// bl 0x825ac978
	ctx.lr = 0x827548A0;
	sub_825AC978(ctx, base);
	// lwz r3,248(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// bl 0x825ac978
	ctx.lr = 0x827548A8;
	sub_825AC978(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827530c0
	ctx.lr = 0x827548B0;
	sub_827530C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82759670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82759678;
	__savegprlr_23(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af28
	ctx.lr = 0x82759680;
	__savefpr_28(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
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
	// beq cr6,0x827596ac
	if (ctx.cr6.eq) goto loc_827596AC;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82753110
	ctx.lr = 0x827596A8;
	sub_82753110(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_827596AC:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827596c8
	if (ctx.cr6.eq) goto loc_827596C8;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82755cf8
	ctx.lr = 0x827596C4;
	sub_82755CF8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_827596C8:
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
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
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
	// bne 0x82759738
	if (!ctx.cr0.eq) goto loc_82759738;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,1
	ctx.r30.s64 = 1;
	// b 0x82759740
	goto loc_82759740;
loc_82759738:
	// addi r29,r11,-1
	ctx.r29.s64 = ctx.r11.s64 + -1;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_82759740:
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82759758
	if (ctx.cr6.eq) goto loc_82759758;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82756298
	ctx.lr = 0x82759758;
	sub_82756298(ctx, base);
loc_82759758:
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82759af8
	if (!ctx.cr6.gt) goto loc_82759AF8;
	// rlwinm r10,r29,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r30,r29
	ctx.r9.u64 = ctx.r30.u64 + ctx.r29.u64;
	// add r11,r10,r27
	ctx.r11.u64 = ctx.r10.u64 + ctx.r27.u64;
	// subf r7,r30,r29
	ctx.r7.u64 = ctx.r29.u64 - ctx.r30.u64;
	// rlwinm r25,r30,3,0,28
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r27,r30,4,0,27
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// lfd f10,25856(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = REX_LOAD_U64(ctx.r11.u32 + 25856);
	// lis r4,-32249
	ctx.r4.s64 = -2113470464;
	// lis r3,-32249
	ctx.r3.s64 = -2113470464;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f11,28428(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 28428);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,-30548(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -30548);
	ctx.f12.f64 = double(temp.f32);
	// subf r28,r25,r28
	ctx.r28.u64 = ctx.r28.u64 - ctx.r25.u64;
	// lfs f13,-30552(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -30552);
	ctx.f13.f64 = double(temp.f32);
	// ori r29,r11,65535
	ctx.r29.u64 = ctx.r11.u64 | 65535;
	// lfs f0,-32720(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -32720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f5,-30508(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -30508);
	ctx.f5.f64 = double(temp.f32);
loc_827597C8:
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
	// lfsx f4,r11,r24
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	ctx.f4.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// fmuls f9,f9,f5
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f5.f64));
	// fmuls f8,f8,f5
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f5.f64));
	// fmuls f7,f7,f5
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f5.f64));
	// fmuls f6,f6,f5
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f5.f64));
	// fadds f3,f9,f4
	ctx.f3.f64 = double(float(ctx.f9.f64 + ctx.f4.f64));
	// fadds f2,f8,f4
	ctx.f2.f64 = double(float(ctx.f8.f64 + ctx.f4.f64));
	// fadds f1,f7,f4
	ctx.f1.f64 = double(float(ctx.f7.f64 + ctx.f4.f64));
	// fadds f4,f6,f4
	ctx.f4.f64 = double(float(ctx.f6.f64 + ctx.f4.f64));
	// fctiwz f3,f3
	ctx.f3.s64 = std::isnan(ctx.f3.f64) ? int64_t(0x80000000U) : (ctx.f3.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f3,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// fctiwz f3,f2
	ctx.f3.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f3,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f3.u64);
	// fctiwz f3,f1
	ctx.f3.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f3,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f3.u64);
	// fctiwz f4,f4
	ctx.f4.s64 = std::isnan(ctx.f4.f64) ? int64_t(0x80000000U) : (ctx.f4.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f4,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f4.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// beq cr6,0x827599fc
	if (ctx.cr6.eq) goto loc_827599FC;
	// extsw r7,r4
	ctx.r7.s64 = ctx.r4.s32;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// extsw r23,r3
	ctx.r23.s64 = ctx.r3.s32;
	// std r7,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f4,112(r1)
	ctx.f4.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r23,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r23.u64);
	// lfd f3,120(r1)
	ctx.f3.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f3,f3
	ctx.f3.f64 = double(ctx.f3.s64);
	// extsw r7,r5
	ctx.r7.s64 = ctx.r5.s32;
	// frsp f3,f3
	ctx.f3.f64 = double(float(ctx.f3.f64));
	// std r7,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r7.u64);
	// fcfid f4,f4
	ctx.f4.f64 = double(ctx.f4.s64);
	// lfd f2,128(r1)
	ctx.f2.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// extsw r23,r6
	ctx.r23.s64 = ctx.r6.s32;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// std r23,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r23.u64);
	// lfs f1,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f9,f9,f3
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f3.f64));
	// frsp f4,f4
	ctx.f4.f64 = double(float(ctx.f4.f64));
	// fmuls f9,f9,f0
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fsubs f8,f8,f4
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f4.f64));
	// fmadds f4,f9,f13,f1
	ctx.f4.f64 = double(float(std::fma(ctx.f9.f64, ctx.f13.f64, ctx.f1.f64)));
	// stfs f4,16(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lfs f4,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// fmadds f4,f9,f12,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f9.f64, ctx.f12.f64, ctx.f4.f64)));
	// stfs f4,16(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// fcfid f4,f2
	ctx.f4.f64 = double(ctx.f2.s64);
	// lfs f3,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f8,f8,f0
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// fmadds f3,f9,f11,f3
	ctx.f3.f64 = double(float(std::fma(ctx.f9.f64, ctx.f11.f64, ctx.f3.f64)));
	// stfs f3,16(r11)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// frsp f4,f4
	ctx.f4.f64 = double(float(ctx.f4.f64));
	// lfs f3,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f3,f8,f13,f3
	ctx.f3.f64 = double(float(std::fma(ctx.f8.f64, ctx.f13.f64, ctx.f3.f64)));
	// stfs f3,20(r11)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// addi r7,r11,20
	ctx.r7.s64 = ctx.r11.s64 + 20;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// fsubs f7,f7,f4
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f4.f64));
	// lfs f4,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f4,f8,f12,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f8.f64, ctx.f12.f64, ctx.f4.f64)));
	// stfs f4,20(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// addi r7,r11,20
	ctx.r7.s64 = ctx.r11.s64 + 20;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lfs f4,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f7,f7,f0
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fmadds f4,f8,f11,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f8.f64, ctx.f11.f64, ctx.f4.f64)));
	// stfs f4,20(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// addi r7,r11,20
	ctx.r7.s64 = ctx.r11.s64 + 20;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// fmul f9,f9,f10
	ctx.f9.f64 = ctx.f9.f64 * ctx.f10.f64;
	// lfs f4,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f4,f7,f13,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f7.f64, ctx.f13.f64, ctx.f4.f64)));
	// stfs f4,24(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// addi r7,r11,24
	ctx.r7.s64 = ctx.r11.s64 + 24;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// fmul f8,f8,f10
	ctx.f8.f64 = ctx.f8.f64 * ctx.f10.f64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// frsp f31,f9
	ctx.f31.f64 = double(float(ctx.f9.f64));
	// lfs f9,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f9,f7,f12,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f7.f64, ctx.f12.f64, ctx.f9.f64)));
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
	// fmul f9,f7,f10
	ctx.f9.f64 = ctx.f7.f64 * ctx.f10.f64;
	// addi r7,r11,24
	ctx.r7.s64 = ctx.r11.s64 + 24;
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// lfs f4,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// frsp f29,f9
	ctx.f29.f64 = double(float(ctx.f9.f64));
	// fmadds f7,f7,f11,f4
	ctx.f7.f64 = double(float(std::fma(ctx.f7.f64, ctx.f11.f64, ctx.f4.f64)));
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
	// fmuls f9,f9,f0
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fmadds f8,f9,f13,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f9.f64, ctx.f13.f64, ctx.f8.f64)));
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
	// fmadds f8,f9,f12,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f9.f64, ctx.f12.f64, ctx.f8.f64)));
	// fmul f7,f9,f10
	ctx.f7.f64 = ctx.f9.f64 * ctx.f10.f64;
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
	// fmadds f9,f9,f11,f8
	ctx.f9.f64 = double(float(std::fma(ctx.f9.f64, ctx.f11.f64, ctx.f8.f64)));
	// stfs f9,28(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// frsp f28,f7
	ctx.f28.f64 = double(float(ctx.f7.f64));
	// addi r7,r11,28
	ctx.r7.s64 = ctx.r11.s64 + 28;
loc_827599FC:
	// cmpw cr6,r3,r29
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r29.s32, ctx.xer);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// blt cr6,0x82759a0c
	if (ctx.cr6.lt) goto loc_82759A0C;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82759A0C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82759a24
	if (!ctx.cr6.gt) goto loc_82759A24;
	// cmpw cr6,r3,r29
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x82759a28
	if (ctx.cr6.lt) goto loc_82759A28;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// b 0x82759a28
	goto loc_82759A28;
loc_82759A24:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82759A28:
	// cmpw cr6,r4,r29
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r29.s32, ctx.xer);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// blt cr6,0x82759a38
	if (ctx.cr6.lt) goto loc_82759A38;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82759A38:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82759a50
	if (!ctx.cr6.gt) goto loc_82759A50;
	// cmpw cr6,r4,r29
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x82759a54
	if (ctx.cr6.lt) goto loc_82759A54;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// b 0x82759a54
	goto loc_82759A54;
loc_82759A50:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82759A54:
	// cmpw cr6,r5,r29
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r29.s32, ctx.xer);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// blt cr6,0x82759a64
	if (ctx.cr6.lt) goto loc_82759A64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82759A64:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82759a7c
	if (!ctx.cr6.gt) goto loc_82759A7C;
	// cmpw cr6,r5,r29
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x82759a80
	if (ctx.cr6.lt) goto loc_82759A80;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// b 0x82759a80
	goto loc_82759A80;
loc_82759A7C:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82759A80:
	// cmpw cr6,r6,r29
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r29.s32, ctx.xer);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// blt cr6,0x82759a90
	if (ctx.cr6.lt) goto loc_82759A90;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82759A90:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82759aa8
	if (!ctx.cr6.gt) goto loc_82759AA8;
	// cmpw cr6,r6,r29
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x82759aac
	if (ctx.cr6.lt) goto loc_82759AAC;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// b 0x82759aac
	goto loc_82759AAC;
loc_82759AA8:
	// li r6,0
	ctx.r6.s64 = 0;
loc_82759AAC:
	// extsw r11,r6
	ctx.r11.s64 = ctx.r6.s32;
	// extsw r7,r5
	ctx.r7.s64 = ctx.r5.s32;
	// rldicr r11,r11,16,47
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 16) & 0xFFFFFFFFFFFF0000;
	// extsw r6,r4
	ctx.r6.s64 = ctx.r4.s32;
	// or r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 | ctx.r7.u64;
	// extsw r7,r3
	ctx.r7.s64 = ctx.r3.s32;
	// rldicr r11,r11,16,47
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 16) & 0xFFFFFFFFFFFF0000;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// or r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 | ctx.r6.u64;
	// add r10,r27,r10
	ctx.r10.u64 = ctx.r27.u64 + ctx.r10.u64;
	// rldicr r11,r11,16,47
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 16) & 0xFFFFFFFFFFFF0000;
	// add r30,r27,r30
	ctx.r30.u64 = ctx.r27.u64 + ctx.r30.u64;
	// or r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 | ctx.r7.u64;
	// add r9,r27,r9
	ctx.r9.u64 = ctx.r27.u64 + ctx.r9.u64;
	// stdux r11,r28,r25
	ea = ctx.r28.u32 + ctx.r25.u32;
	REX_STORE_U64(ea, ctx.r11.u64);
	ctx.r28.u32 = ea;
	// add r8,r27,r8
	ctx.r8.u64 = ctx.r27.u64 + ctx.r8.u64;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x827597c8
	if (ctx.cr6.lt) goto loc_827597C8;
loc_82759AF8:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af74
	ctx.lr = 0x82759B04;
	__restfpr_28(ctx, base);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82773438) {
	REX_FUNC_PROLOGUE();
	// lwz r3,80(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827734B8) {
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
	// b 0x827665a8
	sub_827665A8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82773980) {
	REX_FUNC_PROLOGUE();
	// lwz r11,396(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 396);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8277399c
	if (ctx.cr0.eq) goto loc_8277399C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
loc_8277399C:
	// lwz r3,8(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// b 0x827702f0
	sub_827702F0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82774168) {
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
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// beq cr6,0x827741b8
	if (ctx.cr6.eq) goto loc_827741B8;
	// stw r4,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82768bc0
	ctx.lr = 0x82774194;
	sub_82768BC0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x827741b8
	if (ctx.cr0.lt) goto loc_827741B8;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82768cf0
	ctx.lr = 0x827741A4;
	sub_82768CF0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x827741b8
	if (ctx.cr0.lt) goto loc_827741B8;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82765ad0
	ctx.lr = 0x827741B8;
	sub_82765AD0(ctx, base);
loc_827741B8:
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

DEFINE_REX_FUNC(sub_827762B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x827762C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r4,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r31,48(r4)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r4.u32 + 48);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r8,r1,140
	ctx.r8.s64 = ctx.r1.s64 + 140;
	// lwz r5,12(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,32(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// lwz r6,28(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82776300;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r9,r31,4
	ctx.r9.s64 = ctx.r31.s64 + 4;
loc_82776308:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82776308
	if (!ctx.cr0.eq) goto loc_82776308;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82776340
	if (!ctx.cr6.eq) goto loc_82776340;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82776340;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82776340:
	// lwz r3,140(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82776358
	if (ctx.cr6.eq) goto loc_82776358;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82776358
	if (ctx.cr6.eq) goto loc_82776358;
	// bl 0x82788a40
	ctx.lr = 0x82776358;
	sub_82788A40(ctx, base);
loc_82776358:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8277CF80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8277CF88;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,232(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 232);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r23,r1,80
	ctx.r23.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8277cfb4
	if (ctx.cr6.eq) goto loc_8277CFB4;
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x8277d4a0
	goto loc_8277D4A0;
loc_8277CFB4:
	// lwz r11,172(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// lwz r10,228(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 228);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bne cr6,0x8277cfe8
	if (!ctx.cr6.eq) goto loc_8277CFE8;
	// lwz r10,204(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8277cfd8
	if (!ctx.cr6.lt) goto loc_8277CFD8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8277CFD8:
	// lwz r10,216(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8277cfe8
	if (!ctx.cr6.lt) goto loc_8277CFE8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8277CFE8:
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// ble cr6,0x8277d010
	if (!ctx.cr6.gt) goto loc_8277D010;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,265
	ctx.r3.s64 = 265;
	// bl 0x82772048
	ctx.lr = 0x8277CFFC;
	sub_82772048(ctx, base);
	// mr. r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bne 0x8277d010
	if (!ctx.cr0.eq) goto loc_8277D010;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x8277d488
	goto loc_8277D488;
loc_8277D010:
	// lwz r11,192(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 192);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8277d074
	if (ctx.cr6.eq) goto loc_8277D074;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r23,-4
	ctx.r9.s64 = ctx.r23.s64 + -4;
loc_8277D028:
	// lwz r11,184(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwz r7,232(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 232);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8277d060
	if (ctx.cr6.eq) goto loc_8277D060;
loc_8277D03C:
	// mfmsr r6
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r6.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r7,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r7.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stwcx. r7,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r7.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8277d03c
	if (!ctx.cr0.eq) goto loc_8277D03C;
	// stwu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_8277D060:
	// lwz r11,192(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 192);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8277d028
	if (ctx.cr6.lt) goto loc_8277D028;
loc_8277D074:
	// lwz r11,228(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 228);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8277d0d4
	if (ctx.cr6.eq) goto loc_8277D0D4;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r23
	ctx.r10.u64 = ctx.r11.u64 + ctx.r23.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
loc_8277D094:
	// lwz r8,220(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// lwzx r8,r11,r8
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
loc_8277D09C:
	// mfmsr r6
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r6.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r7,0,r8
	ea = ctx.r8.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r7.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stwcx. r7,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r7.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8277d09c
	if (!ctx.cr0.eq) goto loc_8277D09C;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// lwz r8,228(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 228);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8277d094
	if (ctx.cr6.lt) goto loc_8277D094;
loc_8277D0D4:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8277d22c
	if (ctx.cr6.eq) goto loc_8277D22C;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r26,r11,r23
	ctx.r26.u64 = ctx.r11.u64 + ctx.r23.u64;
loc_8277D0E4:
	// lwzu r27,-4(r26)
	ea = -4 + ctx.r26.u32;
	ctx.r27.u64 = REX_LOAD_U32(ea);
	ctx.r26.u32 = ea;
	// addi r28,r28,-1
	ctx.r28.s64 = ctx.r28.s64 + -1;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8277d124
	if (ctx.cr6.eq) goto loc_8277D124;
	// lwz r11,288(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 288);
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8277d198
	if (!ctx.cr0.eq) goto loc_8277D198;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8277b600
	ctx.lr = 0x8277D10C;
	sub_8277B600(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8277d1a4
	if (ctx.cr0.eq) goto loc_8277D1A4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82784d20
	ctx.lr = 0x8277D120;
	sub_82784D20(ctx, base);
	// b 0x8277d144
	goto loc_8277D144;
loc_8277D124:
	// lwz r31,232(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 232);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8277d198
	if (ctx.cr6.eq) goto loc_8277D198;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8277b280
	ctx.lr = 0x8277D144;
	sub_8277B280(ctx, base);
loc_8277D144:
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x8277d19c
	if (ctx.cr0.eq) goto loc_8277D19C;
loc_8277D14C:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8277d488
	if (ctx.cr6.eq) goto loc_8277D488;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r23
	ctx.r31.u64 = ctx.r11.u64 + ctx.r23.u64;
loc_8277D15C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// addi r28,r28,-1
	ctx.r28.s64 = ctx.r28.s64 + -1;
loc_8277D164:
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
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
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
	// bne 0x8277d164
	if (!ctx.cr0.eq) goto loc_8277D164;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8277d18c
	if (!ctx.cr6.eq) goto loc_8277D18C;
	// bl 0x82784b48
	ctx.lr = 0x8277D18C;
	sub_82784B48(ctx, base);
loc_8277D18C:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8277d15c
	if (!ctx.cr6.eq) goto loc_8277D15C;
	// b 0x8277d488
	goto loc_8277D488;
loc_8277D198:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8277D19C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8277d1f8
	if (!ctx.cr6.eq) goto loc_8277D1F8;
loc_8277D1A4:
	// lwz r11,172(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 172);
	// lwz r10,64(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 64);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8277d1d8
	if (!ctx.cr6.lt) goto loc_8277D1D8;
	// lwz r11,148(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 148);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bge cr6,0x8277d1d8
	if (!ctx.cr6.lt) goto loc_8277D1D8;
	// lis r5,-32646
	ctx.r5.s64 = -2139488256;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,4120
	ctx.r5.u64 = ctx.r5.u64 | 4120;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8277a830
	ctx.lr = 0x8277D1D8;
	sub_8277A830(ctx, base);
loc_8277D1D8:
	// lis r5,-32646
	ctx.r5.s64 = -2139488256;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,4120
	ctx.r5.u64 = ctx.r5.u64 | 4120;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82780a38
	ctx.lr = 0x8277D1F0;
	sub_82780A38(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8277d14c
	if (!ctx.cr0.eq) goto loc_8277D14C;
loc_8277D1F8:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r27
	ea = ctx.r27.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r27
	ea = ctx.r27.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8277d1f8
	if (!ctx.cr0.eq) goto loc_8277D1F8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8277d224
	if (!ctx.cr6.eq) goto loc_8277D224;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82784b48
	ctx.lr = 0x8277D224;
	sub_82784B48(ctx, base);
loc_8277D224:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8277d0e4
	if (!ctx.cr6.eq) goto loc_8277D0E4;
loc_8277D22C:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x8277d484
	if (!ctx.cr6.eq) goto loc_8277D484;
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8277d36c
	if (ctx.cr6.eq) goto loc_8277D36C;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r26,r30,196
	ctx.r26.s64 = ctx.r30.s64 + 196;
	// add r10,r11,r23
	ctx.r10.u64 = ctx.r11.u64 + ctx.r23.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
loc_8277D258:
	// lwz r8,0(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwzx r8,r11,r8
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
loc_8277D260:
	// mfmsr r6
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r6.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r7,0,r8
	ea = ctx.r8.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r7.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stwcx. r7,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r7.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8277d260
	if (!ctx.cr0.eq) goto loc_8277D260;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// lwz r8,204(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8277d258
	if (ctx.cr6.lt) goto loc_8277D258;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8277d36c
	if (ctx.cr6.eq) goto loc_8277D36C;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r25,r11,r23
	ctx.r25.u64 = ctx.r11.u64 + ctx.r23.u64;
loc_8277D2A8:
	// lwzu r31,-4(r25)
	ea = -4 + ctx.r25.u32;
	ctx.r31.u64 = REX_LOAD_U32(ea);
	ctx.r25.u32 = ea;
	// addi r28,r28,-1
	ctx.r28.s64 = ctx.r28.s64 + -1;
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8277d32c
	if (!ctx.cr6.eq) goto loc_8277D32C;
	// addi r27,r31,184
	ctx.r27.s64 = ctx.r31.s64 + 184;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827844d0
	ctx.lr = 0x8277D2CC;
	sub_827844D0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8277d32c
	if (ctx.cr0.eq) goto loc_8277D32C;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x827764d8
	ctx.lr = 0x8277D2E4;
	sub_827764D8(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8277d14c
	if (ctx.cr0.lt) goto loc_8277D14C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82784630
	ctx.lr = 0x8277D2F8;
	sub_82784630(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82784630
	ctx.lr = 0x8277D304;
	sub_82784630(ctx, base);
	// lwz r11,176(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// lwz r10,396(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 396);
	// oris r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 16777216;
	// lwz r11,320(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 320);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,320(r24)
	REX_STORE_U32(ctx.r24.u32 + 320, ctx.r11.u32);
	// stw r10,396(r24)
	REX_STORE_U32(ctx.r24.u32 + 396, ctx.r10.u32);
	// b 0x8277d338
	goto loc_8277D338;
loc_8277D32C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82784630
	ctx.lr = 0x8277D338;
	sub_82784630(ctx, base);
loc_8277D338:
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
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
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
	// bne 0x8277d338
	if (!ctx.cr0.eq) goto loc_8277D338;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8277d364
	if (!ctx.cr6.eq) goto loc_8277D364;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82784b48
	ctx.lr = 0x8277D364;
	sub_82784B48(ctx, base);
loc_8277D364:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8277d2a8
	if (!ctx.cr6.eq) goto loc_8277D2A8;
loc_8277D36C:
	// lwz r11,216(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8277d484
	if (ctx.cr6.eq) goto loc_8277D484;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r27,r30,208
	ctx.r27.s64 = ctx.r30.s64 + 208;
	// add r10,r11,r23
	ctx.r10.u64 = ctx.r11.u64 + ctx.r23.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
loc_8277D390:
	// lwz r8,0(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwzx r8,r11,r8
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
loc_8277D398:
	// mfmsr r6
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r6.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r7,0,r8
	ea = ctx.r8.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r7.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stwcx. r7,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r7.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8277d398
	if (!ctx.cr0.eq) goto loc_8277D398;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// lwz r8,216(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8277d390
	if (ctx.cr6.lt) goto loc_8277D390;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8277d484
	if (ctx.cr6.eq) goto loc_8277D484;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r23
	ctx.r30.u64 = ctx.r11.u64 + ctx.r23.u64;
loc_8277D3E0:
	// lwzu r31,-4(r30)
	ea = -4 + ctx.r30.u32;
	ctx.r31.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r28,r28,-1
	ctx.r28.s64 = ctx.r28.s64 + -1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82784630
	ctx.lr = 0x8277D3F4;
	sub_82784630(ctx, base);
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// bne 0x8277d450
	if (!ctx.cr0.eq) goto loc_8277D450;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// rlwinm. r10,r11,0,6,6
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8277d450
	if (ctx.cr0.eq) goto loc_8277D450;
	// rlwinm. r11,r11,0,7,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8277d450
	if (!ctx.cr0.eq) goto loc_8277D450;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82784c88
	ctx.lr = 0x8277D424;
	sub_82784C88(ctx, base);
	// lwz r11,324(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 324);
	// lis r5,-32646
	ctx.r5.s64 = -2139488256;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,324(r24)
	REX_STORE_U32(ctx.r24.u32 + 324, ctx.r11.u32);
	// ori r5,r5,4099
	ctx.r5.u64 = ctx.r5.u64 | 4099;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8277ee40
	ctx.lr = 0x8277D448;
	sub_8277EE40(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8277d14c
	if (!ctx.cr0.eq) goto loc_8277D14C;
loc_8277D450:
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
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
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
	// bne 0x8277d450
	if (!ctx.cr0.eq) goto loc_8277D450;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8277d47c
	if (!ctx.cr6.eq) goto loc_8277D47C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82784b48
	ctx.lr = 0x8277D47C;
	sub_82784B48(ctx, base);
loc_8277D47C:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8277d3e0
	if (!ctx.cr6.eq) goto loc_8277D3E0;
loc_8277D484:
	// li r29,0
	ctx.r29.s64 = 0;
loc_8277D488:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8277d4a0
	if (ctx.cr6.eq) goto loc_8277D4A0;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,265
	ctx.r3.s64 = 265;
	// bl 0x82772060
	ctx.lr = 0x8277D4A0;
	sub_82772060(ctx, base);
loc_8277D4A0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A0238) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x827A0240;
	__savegprlr_20(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r24,0
	ctx.r24.s64 = 0;
	// addi r23,r3,8
	ctx.r23.s64 = ctx.r3.s64 + 8;
	// addi r9,r3,28
	ctx.r9.s64 = ctx.r3.s64 + 28;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r25,8(r10)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mr r20,r24
	ctx.r20.u64 = ctx.r24.u64;
	// stw r24,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// li r22,1
	ctx.r22.s64 = 1;
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
loc_827A0280:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x827a02bc
	if (ctx.cr6.eq) goto loc_827A02BC;
	// lwz r8,8(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x827a02a4
	if (!ctx.cr6.eq) goto loc_827A02A4;
	// lwz r9,8(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// b 0x827a02a8
	goto loc_827A02A8;
loc_827A02A4:
	// stw r24,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r24.u32);
loc_827A02A8:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x827a02c0
	if (ctx.cr6.eq) goto loc_827A02C0;
	// addi r20,r20,1
	ctx.r20.s64 = ctx.r20.s64 + 1;
	// b 0x827a02c0
	goto loc_827A02C0;
loc_827A02BC:
	// stw r24,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r24.u32);
loc_827A02C0:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x827a0280
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A0280;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x827a042c
	if (ctx.cr6.eq) goto loc_827A042C;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x827a042c
	if (ctx.cr6.eq) goto loc_827A042C;
	// mr r22,r24
	ctx.r22.u64 = ctx.r24.u64;
	// b 0x827a0424
	goto loc_827A0424;
loc_827A02E4:
	// addi r21,r21,-1
	ctx.r21.s64 = ctx.r21.s64 + -1;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x827a042c
	if (ctx.cr6.eq) goto loc_827A042C;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x827a042c
	if (ctx.cr6.eq) goto loc_827A042C;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r9,24(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r31,64
	ctx.r4.s64 = ctx.r31.s64 + 64;
	// addi r3,r31,400
	ctx.r3.s64 = ctx.r31.s64 + 400;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,24(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 24);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r6,r9,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x827a5810
	ctx.lr = 0x827A0324;
	sub_827A5810(ctx, base);
	// stb r24,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r24.u8);
	// sth r24,46(r31)
	REX_STORE_U16(ctx.r31.u32 + 46, ctx.r24.u16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r31,52
	ctx.r3.s64 = ctx.r31.s64 + 52;
	// bl 0x827a50b0
	ctx.lr = 0x827A033C;
	sub_827A50B0(ctx, base);
	// clrlwi. r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x827a042c
	if (!ctx.cr0.eq) goto loc_827A042C;
	// lhz r29,46(r31)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r31.u32 + 46);
	// mr r22,r24
	ctx.r22.u64 = ctx.r24.u64;
	// addi r28,r1,88
	ctx.r28.s64 = ctx.r1.s64 + 88;
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
	// li r26,2
	ctx.r26.s64 = 2;
loc_827A0358:
	// lwz r30,0(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x827a03cc
	if (ctx.cr6.eq) goto loc_827A03CC;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r31,384
	ctx.r4.s64 = ctx.r31.s64 + 384;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x8273a030
	ctx.lr = 0x827A0380;
	sub_8273A030(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + ctx.r29.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x827a039c
	if (!ctx.cr6.lt) goto loc_827A039C;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_827A039C:
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x827a03cc
	if (!ctx.cr6.eq) goto loc_827A03CC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x827a1f50
	ctx.lr = 0x827A03BC;
	sub_827A1F50(ctx, base);
	// stw r3,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x827a03cc
	if (!ctx.cr0.eq) goto loc_827A03CC;
	// addi r20,r20,-1
	ctx.r20.s64 = ctx.r20.s64 + -1;
loc_827A03CC:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// bne 0x827a0358
	if (!ctx.cr0.eq) goto loc_827A0358;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x827a0400
	if (!ctx.cr6.lt) goto loc_827A0400;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_827A0400:
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x827a0424
	if (!ctx.cr6.eq) goto loc_827A0424;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x827a1f50
	ctx.lr = 0x827A0420;
	sub_827A1F50(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_827A0424:
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// bne cr6,0x827a02e4
	if (!ctx.cr6.eq) goto loc_827A02E4;
loc_827A042C:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827AD4E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-10368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10364(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ADA70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-10208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10204(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE010) {
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
	// lfs f0,22312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10156(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10156);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10040(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE970) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9748(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9748);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9744(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AF248) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-9532(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9532);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9480(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AFAD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-9276(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9276);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9224(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9224, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0618) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22972(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22972);
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

DEFINE_REX_FUNC(sub_827B0E88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8648(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8316(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2568) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-7964(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7964);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-7960(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -7960, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2E98) {
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
	// lfs f0,23496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7732(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7732);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7676(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7676, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3DA0) {
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
	// lfs f0,23624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7352(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7352);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7240(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B4F30) {
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
	// lfs f0,23848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6812(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6812);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6728(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5EA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6268(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6268, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6D28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-5844(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5844);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-5836(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5836, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B78C8) {
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
	// lfs f0,24312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5548(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5548);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5480(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B89C0) {
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
	// lfs f0,24504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5120(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5120);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5020(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9B00) {
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
	// lfs f0,24760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4592(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4592);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4512(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BAB00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4036(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4036);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4032(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4032, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB9B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3576(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3576, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC930) {
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
	// lfs f0,25560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3208(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3208);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3124(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD950) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2660);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BE870) {
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
	// lfs f0,25928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2264(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2264);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2208(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2208, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BF928) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1708(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1708, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C08E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1236(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1236, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C19F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-764(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -764, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2800) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-400(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -400);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-336(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C38D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,52(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,160(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 160, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4748) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,596(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5738) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1064);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1068(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C65A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28044(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28044);
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

DEFINE_REX_FUNC(sub_827C7550) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1992(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1992, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C83C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2436(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9108) {
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
	// lfs f0,28704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2824(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CA390) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,3360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3364(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB340) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,3836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3836);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,3840(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 3840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CBC10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,4092(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4092);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4096(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4096, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CCAF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4484);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4536(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4536, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CDBC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5020(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CE948) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,5412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5412);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5416(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CF770) {
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
	// lfs f0,29736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5776(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5776);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5832(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0A08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1AF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30124);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6864(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6864, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2898) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,7260(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7260);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7264(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D3710) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7624(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7624);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7688(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4948) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5A38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30764(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30764);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8708(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8708, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D67D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,9104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9108(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7650) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9468);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9532(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9532, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D88D0) {
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
	// lfs f13,10020(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 10020);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10072(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D9998) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10556(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10556, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA730) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10956(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB628) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,11388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11388);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,11392(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 11392, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DC010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,31752
	ctx.r9.s64 = ctx.r11.s64 + 31752;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11676(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11676, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD3F8) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12168(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12168);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12284(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE598) {
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
	// lfs f0,32152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12744(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12744);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12804(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12804, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DF7A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32380(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32380);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13324(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13324, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E06D0) {
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
	// lfs f0,32504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13716(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13716);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13772(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13772, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1948) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14328(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E29A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14812(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14812, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3920) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15252(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15252);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15256(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E49E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-32008
	ctx.r9.s64 = ctx.r11.s64 + -32008;
	// lfs f0,-32008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15728(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 15728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E59A0) {
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
	// lfs f0,-31160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16064(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16064);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16168(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16168, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6EC0) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16724(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16724);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16780(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16780, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8150) {
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
	// lfs f12,17172(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17172);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17284(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E96B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17892(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA3D8) {
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
	// lfs f0,-23656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18148(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18148);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18256(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB868) {
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
	// lfs f0,-22536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18732(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18732);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18836(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18836, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ECD48) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19256(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19256);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19404(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19404, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EE120) {
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
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19804(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19804);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19948(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF398) {
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
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20392);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20460(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F05F8) {
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
	// lfs f12,20860(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20860);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20968(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20968, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F1B08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21548(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21548, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2B10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-17396(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17396);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22000(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F3B48) {
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
	// lfs f0,-16840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,22400(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 22400);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,22456(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 22456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F4EA0) {
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
	// lfs f0,-16296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16296);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23164(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23164);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,23184(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 23184, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6A50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-14704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24016(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24016, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7998) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,24440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24440);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,24444(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 24444, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-12324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12324);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24728(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9468) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25156(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA320) {
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
	// lfs f0,-9832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25456(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25456);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25572(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB668) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26012(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26012);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26132(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC980) {
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
	// lfs f0,-9432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26588(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26588);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26688(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FDC20) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27116(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27116);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27232(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27232, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FEF88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9048(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9048);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,27692(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 27692);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27796(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FFE08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800C38) {
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
	// lfs f0,-8728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28576(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28576);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28636(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801FA8) {
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
	// lfs f0,-8536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29136(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29136);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29204(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828032E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,29760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29760);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,29764(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 29764, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803D38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
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
	// stfs f0,30064(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804B60) {
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
	// lfs f0,-8088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30424(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30424);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30480(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805EF0) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30976(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30976);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31048(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828072C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,31620(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31620);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,31624(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 31624, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807D18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31924);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31928(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808C00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,32356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32356);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,32360(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 32360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828095F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7300(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7300);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32652(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A4C8) {
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
	// lfs f0,-7192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32536);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-32452(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -32452, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B880) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-7000
	ctx.r9.s64 = ctx.r11.s64 + -7000;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-7000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31876(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31876, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280CC58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-31388(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -31388);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31280(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280DBE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30844(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30844);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30840(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280EA20) {
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
	// lfs f0,-6360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30492(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30492);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30408(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280FE28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-29868(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -29868);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29816(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29816, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810EE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29320(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29316(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811F10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28952(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28952);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28848(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812C88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-5592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5592);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-28456(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -28456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813690) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28156);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28152(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28152, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814468) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-4968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4968);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-27696(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -27696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828151B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-4744
	ctx.r9.s64 = ctx.r11.s64 + -4744;
	// lfs f0,-4744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27292(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -27292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815EE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-26952(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -26952);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26900(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817060) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26396(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26396);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26392(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26392, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817DE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-25980(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25980);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25976(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25976, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818EC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-25476(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25476);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25472(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819CF8) {
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
	// lfs f0,-3512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25128(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25128);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25044(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281B2A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-24396(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24396);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-24392(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -24392, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281BCE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3012);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24092(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281CBC0) {
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
	// lfs f0,-2840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23748(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23748);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23648(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281DF80) {
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
	// lfs f12,-23160(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23160);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23052(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281F358) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-2200
	ctx.r9.s64 = ctx.r11.s64 + -2200;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-2200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22464(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22464, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82820798) {
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
	// lfs f0,-1912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21948(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21948);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21868(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21868, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821B78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-1720
	ctx.r9.s64 = ctx.r11.s64 + -1720;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-1720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21288(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82822F28) {
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
	// lfs f0,-1496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20832(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20832);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20716(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20716, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82824190) {
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
	// lfs f0,-1160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20244);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20160(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20160, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828255F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19552(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19552, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826690) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-19156(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -19156);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19052(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828274B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18640(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828330) {
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
	// lfs f0,-232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18212(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829800) {
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
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17648(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17648);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17600(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17600, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282AB68) {
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
	// lfs f0,216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17080(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17080);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17032(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17032, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282BED8) {
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
	// lfs f0,488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16540);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16452(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16452, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D410) {
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
	// lfs f0,712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15956(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15956);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15836(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15836, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E858) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15336(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15336);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15236(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15236, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282FC80) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14648(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830F68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14084);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14080(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14080, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831DB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,1704
	ctx.r9.s64 = ctx.r11.s64 + 1704;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,1704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13648(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833278) {
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
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13096(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -13096);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13028(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834550) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-12476(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12476);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12472(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835520) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828365A8) {
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
	// lfs f0,2600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11616(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11616);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11516(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828379B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,2872
	ctx.r9.s64 = ctx.r11.s64 + 2872;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,2872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10924(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10924, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838CB0) {
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
	// lfs f0,3088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10448(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10448);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10368(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283A1C0) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9868(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9868);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9752(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283B588) {
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
	// lfs f0,3552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9276(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9276);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9176(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9176, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283C9E8) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8704(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8704);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8584(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283DDD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8004);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8000(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283EC88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7572);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7568(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7568, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283FB98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7124(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840AE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6676(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6676);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6672(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6672, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82841AF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-6204(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6204);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-6200(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -6200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828424B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5916(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82843538) {
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
	// lfs f0,5144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5536);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5432(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82844868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,5392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5392);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4860(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -4860, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845500) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4560(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4560);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4476(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846698) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4080(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4080);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3960(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3960, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847B30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3344(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828489B8) {
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
	// lfs f0,6272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2964(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2964);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2916(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849D50) {
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
	// lfs f0,6512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2392);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2344(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284B0E8) {
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
	// lfs f0,6704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1820(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1820);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1772(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1772, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284C4B0) {
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
	// lfs f0,6928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1244);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1196(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1196, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D8E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284EA30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-76(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -76);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-72(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -72, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284FA00) {
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
	// lfs f0,7720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,292(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 292);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,400(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 400, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850C48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,956(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 956);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,960(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 960, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851970) {
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
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1336(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852B78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,8504
	ctx.r9.s64 = ctx.r11.s64 + 8504;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,8504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1864(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1864, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853FF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// addi r7,r9,3456
	ctx.r7.s64 = ctx.r9.s64 + 3456;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f13,3456(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 3456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82876420) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82876428;
	__savegprlr_29(ctx, base);
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// rlwinm r29,r11,3,0,28
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// bl 0x82873f18
	ctx.lr = 0x8287644C;
	sub_82873F18(ctx, base);
	// li r10,1104
	ctx.r10.s64 = 1104;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v1,r30,r10
	ea = (ctx.r30.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x828747e0
	ctx.lr = 0x82876468;
	sub_828747E0(ctx, base);
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8287BA40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8287BA48;
	__savegprlr_29(ctx, base);
	// li r11,48
	ctx.r11.s64 = 48;
	// lvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// vspltish v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_set1_epi16(short(0x1)));
	// li r9,64
	ctx.r9.s64 = 64;
	// vspltish v13,4
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x4)));
	// li r8,96
	ctx.r8.s64 = 96;
	// li r31,144
	ctx.r31.s64 = 144;
	// lvx128 v11,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,112
	ctx.r30.s64 = 112;
	// li r11,160
	ctx.r11.s64 = 160;
	// lvx128 v63,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsldoi128 v8,v12,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 14));
	// lvx128 v10,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsldoi128 v7,v11,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), 14));
	// lvx128 v9,r3,r31
	ea = (ctx.r3.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,-64
	ctx.r31.s64 = ctx.r1.s64 + -64;
	// lvx128 v61,r3,r30
	ea = (ctx.r3.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,-48
	ctx.r30.s64 = ctx.r1.s64 + -48;
	// lvx128 v60,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsldoi128 v6,v10,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), 14));
	// vsldoi128 v5,v9,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), 14));
	// vslh v4,v8,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v3,v7,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// cmpwi cr6,r6,8
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 8, ctx.xer);
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// vslh v2,v6,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// add r10,r4,r5
	ctx.r10.u64 = ctx.r4.u64 + ctx.r5.u64;
	// vslh v31,v5,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// add r11,r8,r5
	ctx.r11.u64 = ctx.r8.u64 + ctx.r5.u64;
	// vaddshs v30,v4,v12
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v29,v3,v11
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// vaddshs v28,v2,v10
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v27,v31,v9
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vaddshs v26,v30,v8
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v25,v29,v7
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v24,v28,v6
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v23,v27,v5
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v22,v26,v1
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vaddshs v21,v25,v1
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vaddshs v20,v24,v1
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vaddshs v19,v23,v1
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
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
	// vsrah v15,v19,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkshus128 v59,v18,v17
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v18.s16)));
	// vpkshus128 v58,v16,v15
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// stvx128 v59,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,-56(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -56);
	// lwz r31,-64(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// stvx128 v58,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-48(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r29,-40(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -40);
	// stw r31,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r31.u32);
	// stwx r6,r4,r5
	REX_STORE_U32(ctx.r4.u32 + ctx.r5.u32, ctx.r6.u32);
	// stwx r30,r8,r5
	REX_STORE_U32(ctx.r8.u32 + ctx.r5.u32, ctx.r30.u32);
	// stwx r29,r11,r4
	REX_STORE_U32(ctx.r11.u32 + ctx.r4.u32, ctx.r29.u32);
	// bne cr6,0x8287bb5c
	if (!ctx.cr6.eq) goto loc_8287BB5C;
	// lwz r6,-60(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -60);
	// lwz r31,-52(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + -52);
	// lwz r30,-44(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -44);
	// lwz r29,-36(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -36);
	// stw r6,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r6.u32);
	// stw r31,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stw r29,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r29.u32);
loc_8287BB5C:
	// cmpwi cr6,r7,8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 8, ctx.xer);
	// bne cr6,0x8287bc68
	if (!ctx.cr6.eq) goto loc_8287BC68;
	// li r10,192
	ctx.r10.s64 = 192;
	// li r9,240
	ctx.r9.s64 = 240;
	// li r7,208
	ctx.r7.s64 = 208;
	// li r6,256
	ctx.r6.s64 = 256;
	// li r31,288
	ctx.r31.s64 = 288;
	// lvx128 v12,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,336
	ctx.r30.s64 = 336;
	// lvx128 v11,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,304
	ctx.r10.s64 = 304;
	// li r9,352
	ctx.r9.s64 = 352;
	// lvx128 v57,r3,r7
	ea = (ctx.r3.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r3,r6
	ea = (ctx.r3.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsldoi128 v8,v12,v57,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8), 14));
	// lvx128 v10,r3,r31
	ea = (ctx.r3.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsldoi128 v7,v11,v56,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8), 14));
	// lvx128 v9,r3,r30
	ea = (ctx.r3.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,-64
	ctx.r7.s64 = ctx.r1.s64 + -64;
	// lvx128 v55,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,-48
	ctx.r6.s64 = ctx.r1.s64 + -48;
	// lvx128 v54,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsldoi128 v6,v10,v55,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8), 14));
	// vsldoi128 v5,v9,v54,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8), 14));
	// vslh v4,v8,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v3,v7,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// vslh v2,v6,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v31,v5,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v30,v4,v12
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v29,v3,v11
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v28,v2,v10
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v27,v31,v9
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vaddshs v26,v30,v8
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v25,v29,v7
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v24,v28,v6
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v23,v27,v5
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v22,v26,v1
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vaddshs v21,v25,v1
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vaddshs v20,v24,v1
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vaddshs v19,v23,v1
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
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
	// vsrah v15,v19,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkshus128 v53,v18,v17
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v18.s16)));
	// vpkshus128 v52,v16,v15
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// stvx128 v53,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,-56(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -56);
	// lwz r7,-52(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -52);
	// stvx128 v52,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,-48(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// lwz r31,-44(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + -44);
	// lwz r30,-40(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -40);
	// lwz r29,-36(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -36);
	// lwz r3,-60(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -60);
	// lwz r9,-64(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -64);
	// stwux r9,r5,r10
	ea = ctx.r5.u32 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r5.u32 = ea;
	// add r9,r4,r5
	ctx.r9.u64 = ctx.r4.u64 + ctx.r5.u64;
	// stw r3,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r3.u32);
	// stwx r8,r4,r5
	REX_STORE_U32(ctx.r4.u32 + ctx.r5.u32, ctx.r8.u32);
	// stw r7,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r7.u32);
	// stwux r6,r11,r10
	ea = ctx.r11.u32 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r6.u32);
	ctx.r11.u32 = ea;
	// add r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 + ctx.r4.u64;
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// stwx r30,r11,r4
	REX_STORE_U32(ctx.r11.u32 + ctx.r4.u32, ctx.r30.u32);
	// stw r29,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r29.u32);
loc_8287BC68:
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

