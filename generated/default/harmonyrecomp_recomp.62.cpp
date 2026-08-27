#include "harmonyrecomp_funcs.62.h"

DEFINE_REX_FUNC(sub_82215120) {
	REX_FUNC_PROLOGUE();
	// addi r11,r4,-1
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// blt cr6,0x82215134
	if (ctx.cr6.lt) goto loc_82215134;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82215134:
	// cmplwi cr6,r4,6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 6, ctx.xer);
	// ble cr6,0x82215194
	if (!ctx.cr6.gt) goto loc_82215194;
	// clrlwi. r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne 0x82215170
	if (!ctx.cr0.eq) goto loc_82215170;
	// beq cr6,0x82215168
	if (ctx.cr6.eq) goto loc_82215168;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r6
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
loc_82215158:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
loc_82215168:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82215170:
	// beq cr6,0x82215184
	if (ctx.cr6.eq) goto loc_82215184;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r6
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	// lbz r11,1(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// b 0x82215158
	goto loc_82215158;
loc_82215184:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x822150c8
	sub_822150C8(ctx, base);
	return;
loc_82215194:
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x822151b0
	if (!ctx.cr6.eq) goto loc_822151B0;
	// clrlwi. r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82215168
	if (ctx.cr0.eq) goto loc_82215168;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x822150c8
	sub_822150C8(ctx, base);
	return;
loc_822151B0:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// b 0x822150c8
	sub_822150C8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8221DF50) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r4,r11,1340
	ctx.r4.s64 = ctx.r11.s64 + 1340;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82223b50
	ctx.lr = 0x8221DF78;
	sub_82223B50(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,984
	ctx.r11.s64 = ctx.r11.s64 + 984;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82223a50
	ctx.lr = 0x8221DF8C;
	sub_82223A50(ctx, base);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,984
	ctx.r9.s64 = ctx.r9.s64 + 984;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lwz r9,20(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r9,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
	// stb r10,104(r31)
	REX_STORE_U8(ctx.r31.u32 + 104, ctx.r10.u8);
	// beq cr6,0x8221dfdc
	if (ctx.cr6.eq) goto loc_8221DFDC;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// stb r10,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r10.u8);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r10,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// sth r9,86(r11)
	REX_STORE_U16(ctx.r11.u32 + 86, ctx.r9.u16);
	// stw r9,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r9.u32);
	// lfs f0,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 108, temp.u32);
	// stfs f0,104(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 104, temp.u32);
loc_8221DFDC:
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r8,52
	ctx.r8.s64 = 52;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// li r7,53
	ctx.r7.s64 = 53;
	// li r8,54
	ctx.r8.s64 = 54;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// lwzx r10,r10,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// sth r10,102(r31)
	REX_STORE_U16(ctx.r31.u32 + 102, ctx.r10.u16);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r10,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,76(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// beq cr6,0x8221e038
	if (ctx.cr6.eq) goto loc_8221E038;
	// stfs f0,40(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// stfs f0,44(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
loc_8221E038:
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// lfs f1,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,36(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221E058;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

DEFINE_REX_FUNC(sub_82226B10) {
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
	// bl 0x82218310
	ctx.lr = 0x82226B2C;
	sub_82218310(ctx, base);
	// lfs f0,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 148);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 144);
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,148(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 148, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82226bb4
	if (!ctx.cr0.eq) goto loc_82226BB4;
	// lfs f13,152(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82226b94
	if (ctx.cr6.lt) goto loc_82226B94;
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82226b7c
	if (!ctx.cr6.gt) goto loc_82226B7C;
loc_82226B64:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82226bd8
	ctx.lr = 0x82226B6C;
	sub_82226BD8(ctx, base);
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82226b64
	if (ctx.cr6.lt) goto loc_82226B64;
loc_82226B7C:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,148(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 148, temp.u32);
loc_82226B94:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82226bb4
	if (ctx.cr6.eq) goto loc_82226BB4;
	// lwz r10,164(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82226bb4
	if (ctx.cr6.lt) goto loc_82226BB4;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,144(r31)
	REX_STORE_U8(ctx.r31.u32 + 144, ctx.r11.u8);
loc_82226BB4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82226ee0
	ctx.lr = 0x82226BBC;
	sub_82226EE0(ctx, base);
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

DEFINE_REX_FUNC(sub_8222F870) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,32(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8222F8B8) {
	REX_FUNC_PROLOGUE();
	// lwz r3,64(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8222FE30) {
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
	// bl 0x82231c80
	ctx.lr = 0x8222FE50;
	sub_82231C80(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8222fe68
	if (ctx.cr0.eq) goto loc_8222FE68;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8222fe68
	if (ctx.cr6.eq) goto loc_8222FE68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8222FE68;
	sub_825E0378(ctx, base);
loc_8222FE68:
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

DEFINE_REX_FUNC(sub_822327F0) {
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
	// lwz r11,268(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82232904
	if (ctx.cr0.eq) goto loc_82232904;
	// addi r8,r3,128
	ctx.r8.s64 = ctx.r3.s64 + 128;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x82239588
	ctx.lr = 0x82232824;
	sub_82239588(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82232904
	if (!ctx.cr0.eq) goto loc_82232904;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,12468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// ble cr6,0x822328bc
	if (!ctx.cr6.gt) goto loc_822328BC;
	// li r4,2
	ctx.r4.s64 = 2;
	// bctrl 
	ctx.lr = 0x82232880;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r9,32688
	ctx.r9.s64 = ctx.r9.s64 + 32688;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x822328fc
	goto loc_822328FC;
loc_822328BC:
	// li r4,0
	ctx.r4.s64 = 0;
	// bctrl 
	ctx.lr = 0x822328C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,32608
	ctx.r11.s64 = ctx.r11.s64 + 32608;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r9,r9,32720
	ctx.r9.s64 = ctx.r9.s64 + 32720;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_822328FC:
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,120(r31)
	REX_STORE_U64(ctx.r31.u32 + 120, ctx.r11.u64);
loc_82232904:
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

DEFINE_REX_FUNC(sub_82240F20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x82240F28;
	__savegprlr_20(ctx, base);
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r31,-3100
	ctx.r31.s64 = ctx.r31.s64 + -3100;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82241d8c
	if (ctx.cr6.eq) goto loc_82241D8C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,156(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 156);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,148(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82240F5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82243ea0
	ctx.lr = 0x82240F64;
	sub_82243EA0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82240F78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,344(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 344);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82240F8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82241034
	if (ctx.cr0.eq) goto loc_82241034;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12964(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12964);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82241034
	if (ctx.cr6.eq) goto loc_82241034;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,320(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 320);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82240FB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// ori r11,r11,62392
	ctx.r11.u64 = ctx.r11.u64 | 62392;
	// stwx r3,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r3.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,324(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 324);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82240FDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// ori r11,r11,62396
	ctx.r11.u64 = ctx.r11.u64 | 62396;
	// stwx r3,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r3.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241000;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,0
	ctx.r10.s64 = 0;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// ori r10,r10,62440
	ctx.r10.u64 = ctx.r10.u64 | 62440;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lis r9,-32220
	ctx.r9.s64 = -2111569920;
	// rlwinm r11,r11,0,30,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r11,r11,15
	ctx.r11.s64 = ctx.r11.s64 + 15;
	// addi r3,r9,15224
	ctx.r3.s64 = ctx.r9.s64 + 15224;
	// stwx r11,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r11.u32);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x8242a0f8
	ctx.lr = 0x82241034;
	sub_8242A0F8(ctx, base);
loc_82241034:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,304(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 304);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241048;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r22,r11,22072
	ctx.r22.s64 = ctx.r11.s64 + 22072;
	// beq 0x82241160
	if (ctx.cr0.eq) goto loc_82241160;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,308(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 308);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241070;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r25,4(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r23,8(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r25,r23
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r23.u32, ctx.xer);
	// beq cr6,0x82241160
	if (ctx.cr6.eq) goto loc_82241160;
	// addis r26,r30,1
	ctx.r26.s64 = ctx.r30.s64 + 65536;
	// li r24,52
	ctx.r24.s64 = 52;
	// addi r26,r26,-3164
	ctx.r26.s64 = ctx.r26.s64 + -3164;
loc_8224108C:
	// stw r25,256(r1)
	REX_STORE_U32(ctx.r1.u32 + 256, ctx.r25.u32);
	// addi r27,r1,256
	ctx.r27.s64 = ctx.r1.s64 + 256;
	// li r29,7
	ctx.r29.s64 = 7;
loc_82241098:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 44);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x825e02a0
	ctx.lr = 0x822410A8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822410c4
	if (ctx.cr0.eq) goto loc_822410C4;
	// stw r28,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r28.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r28,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r28.u32);
	// stw r28,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r28.u32);
	// b 0x822410c8
	goto loc_822410C8;
loc_822410C4:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_822410C8:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stwu r11,4(r27)
	ea = 4 + ctx.r27.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r27.u32 = ea;
	// bne 0x82241098
	if (!ctx.cr0.eq) goto loc_82241098;
	// lwz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x822410e8
	if (!ctx.cr6.eq) goto loc_822410E8;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x822410f4
	goto loc_822410F4;
loc_822410E8:
	// lwz r11,12(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r24
	ctx.r11.u64 = uint32_t((ctx.r24.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r24.s32 == -1)) ? ctx.r11.s32 / ctx.r24.s32 : 0);
loc_822410F4:
	// lwz r29,8(r26)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// subf r10,r10,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r10.u64;
	// divw r10,r10,r24
	ctx.r10.u64 = uint32_t((ctx.r24.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r24.s32 == -1)) ? ctx.r10.s32 / ctx.r24.s32 : 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8224112c
	if (!ctx.cr6.lt) goto loc_8224112C;
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq 0x82241120
	if (ctx.cr0.eq) goto loc_82241120;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x82241120;
	sub_8273A030(ctx, base);
loc_82241120:
	// addi r11,r29,52
	ctx.r11.s64 = ctx.r29.s64 + 52;
	// stw r11,8(r26)
	REX_STORE_U32(ctx.r26.u32 + 8, ctx.r11.u32);
	// b 0x8224113c
	goto loc_8224113C;
loc_8224112C:
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82248a38
	ctx.lr = 0x8224113C;
	sub_82248A38(ctx, base);
loc_8224113C:
	// addi r11,r1,288
	ctx.r11.s64 = ctx.r1.s64 + 288;
	// addi r25,r25,52
	ctx.r25.s64 = ctx.r25.s64 + 52;
	// cmplw cr6,r25,r23
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r23.u32, ctx.xer);
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// stw r28,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r28.u32);
	// stw r28,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r28.u32);
	// stw r28,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r28.u32);
	// stw r28,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r28.u32);
	// bne cr6,0x8224108c
	if (!ctx.cr6.eq) goto loc_8224108C;
loc_82241160:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82244240
	ctx.lr = 0x82241168;
	sub_82244240(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,832(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 832);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241180;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r21,-1
	ctx.r21.s64 = -1;
	// ori r23,r11,62400
	ctx.r23.u64 = ctx.r11.u64 | 62400;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble 0x82241770
	if (!ctx.cr0.gt) goto loc_82241770;
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
loc_82241198:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8235ec48
	ctx.lr = 0x822411A8;
	sub_8235EC48(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,808(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 808);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822411C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822411dc
	if (ctx.cr0.eq) goto loc_822411DC;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r4,r30,r23
	ctx.r4.u64 = ctx.r30.u64 + ctx.r23.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82239208
	ctx.lr = 0x822411DC;
	sub_82239208(ctx, base);
loc_822411DC:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r26,0(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,784(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 784);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822411F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,348(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 348);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241208;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x8224173c
	if (ctx.cr0.eq) goto loc_8224173C;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_82241214:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82241214
	if (!ctx.cr6.eq) goto loc_82241214;
	// subf r11,r4,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r4.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x822390c0
	ctx.lr = 0x82241238;
	sub_822390C0(ctx, base);
	// lwz r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// lwz r24,132(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bge cr6,0x8224124c
	if (!ctx.cr6.lt) goto loc_8224124C;
	// addi r24,r1,132
	ctx.r24.s64 = ctx.r1.s64 + 132;
loc_8224124C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,712(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 712);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241264;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,44(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 44);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,84
	ctx.r4.s64 = 84;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x825e02a0
	ctx.lr = 0x8224127C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82241290
	if (ctx.cr0.eq) goto loc_82241290;
	// bl 0x8222f918
	ctx.lr = 0x82241288;
	sub_8222F918(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// b 0x82241294
	goto loc_82241294;
loc_82241290:
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
loc_82241294:
	// stw r26,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x822412a8
	if (!ctx.cr6.eq) goto loc_822412A8;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x82241338
	goto loc_82241338;
loc_822412A8:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// clrlwi r5,r25,16
	ctx.r5.u64 = ctx.r25.u32 & 0xFFFF;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822412C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822412DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// addi r3,r30,260
	ctx.r3.s64 = ctx.r30.s64 + 260;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822412f4
	if (!ctx.cr6.eq) goto loc_822412F4;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// b 0x82241300
	goto loc_82241300;
loc_822412F4:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_82241300:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82241324
	if (!ctx.cr6.lt) goto loc_82241324;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r26,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r26.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x8224132c
	goto loc_8224132C;
loc_82241324:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// bl 0x823849b0
	ctx.lr = 0x8224132C;
	sub_823849B0(ctx, base);
loc_8224132C:
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r10,281(r30)
	REX_STORE_U8(ctx.r30.u32 + 281, ctx.r10.u8);
loc_82241338:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224173c
	if (ctx.cr0.eq) goto loc_8224173C;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,756(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 756);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224135C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,756(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 756);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241384;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r25,0(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwzx r24,r27,r11
	ctx.r24.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r26,0(r24)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r11,772(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 772);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822413B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,460(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 460);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822413CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,100(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 100);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// fadds f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f31.f64 + ctx.f1.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822413E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,764(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 764);
	// lwz r26,0(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241404;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,84(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 84);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241414;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,768(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 768);
	// lwz r26,0(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241438;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,88(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 88);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241448;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// addi r26,r1,88
	ctx.r26.s64 = ctx.r1.s64 + 88;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,748(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 748);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224146C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r4,0(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241488;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,732(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 732);
	// lwz r26,0(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822414AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,184(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 184);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822414C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,736(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 736);
	// lwz r26,0(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822414E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,112(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 112);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822414F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,740(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 740);
	// lwz r26,0(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224151C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,32(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241530;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,776(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 776);
	// lwz r26,0(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241554;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,120(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 120);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241564;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,780(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 780);
	// lwz r26,0(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241588;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,176(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 176);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224159C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,812(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 812);
	// lwz r26,0(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822415C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,188(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 188);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822415D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// lwz r25,0(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwzx r24,r27,r11
	ctx.r24.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r26,0(r24)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r11,752(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 752);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241600;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwz r11,752(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 752);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241620;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,160(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 160);
	// lfs f13,0(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lhz r5,94(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 94);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lhz r4,94(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 94);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241650;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwzx r3,r27,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224166C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,816(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 816);
	// lwz r26,0(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241690;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,236(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 236);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822416A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r27,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,820(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 820);
	// lwz r26,0(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822416C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,108(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 108);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822416D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,824(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 824);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822416F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224173c
	if (ctx.cr0.eq) goto loc_8224173C;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,828(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 828);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241718;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lhz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r27,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224173C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8224173C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8235ec48
	ctx.lr = 0x8224174C;
	sub_8235EC48(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,832(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 832);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241768;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpw cr6,r29,r3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x82241198
	if (ctx.cr6.lt) goto loc_82241198;
loc_82241770:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,940(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 940);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241788;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble 0x82241c70
	if (!ctx.cr0.gt) goto loc_82241C70;
loc_82241790:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8235ec48
	ctx.lr = 0x822417A0;
	sub_8235EC48(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,920(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 920);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822417B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822417d4
	if (ctx.cr0.eq) goto loc_822417D4;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r4,r30,r23
	ctx.r4.u64 = ctx.r30.u64 + ctx.r23.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82239208
	ctx.lr = 0x822417D4;
	sub_82239208(ctx, base);
loc_822417D4:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r27,0(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,896(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 896);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822417EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,348(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 348);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241800;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x82241c3c
	if (ctx.cr0.eq) goto loc_82241C3C;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_8224180C:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8224180c
	if (!ctx.cr6.eq) goto loc_8224180C;
	// subf r11,r4,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r4.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x822390c0
	ctx.lr = 0x82241830;
	sub_822390C0(ctx, base);
	// lwz r11,200(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// lwz r27,180(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// bge cr6,0x82241844
	if (!ctx.cr6.lt) goto loc_82241844;
	// addi r27,r1,180
	ctx.r27.s64 = ctx.r1.s64 + 180;
loc_82241844:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,836(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 836);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224185C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82232c30
	ctx.lr = 0x8224186C;
	sub_82232C30(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82241c3c
	if (ctx.cr0.eq) goto loc_82241C3C;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,868(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 868);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241890;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,868(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 868);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822418B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r26,0(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwzx r25,r28,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r27,0(r25)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,888(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 888);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822418E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,460(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 460);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241900;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,100(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 100);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fadds f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f31.f64 + ctx.f1.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241914;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r26,r28,r11
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,876(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 876);
	// lwz r27,0(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241938;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,84(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241948;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r26,r28,r11
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,880(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 880);
	// lwz r27,0(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224196C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,88(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 88);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224197C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r26,r28,r11
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,860(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 860);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822419A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// stw r3,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,0(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822419BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r26,r28,r11
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,848(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 848);
	// lwz r27,0(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822419E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,184(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 184);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822419F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r26,r28,r11
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,852(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 852);
	// lwz r27,0(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241A18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,112(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 112);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241A2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r26,r28,r11
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,856(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 856);
	// lwz r27,0(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241A50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,32(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241A64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r26,r28,r11
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,884(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 884);
	// lwz r27,0(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241A88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,120(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 120);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241A98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r26,r28,r11
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,892(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 892);
	// lwz r27,0(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241ABC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,176(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 176);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241AD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r26,r28,r11
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,924(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 924);
	// lwz r27,0(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241AF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,188(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 188);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241B08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r26,0(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwzx r25,r28,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r27,0(r25)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,864(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 864);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241B34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r11,864(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 864);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241B54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,160(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 160);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f13,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lhz r5,102(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lhz r4,102(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// bctrl 
	ctx.lr = 0x82241B84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwzx r3,r28,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241BA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r26,r28,r11
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,928(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 928);
	// lwz r27,0(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241BC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,108(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 108);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241BD8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,932(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 932);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241BF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82241c3c
	if (ctx.cr0.eq) goto loc_82241C3C;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,936(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 936);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241C18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lhz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// lfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r28,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241C3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82241C3C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8235ec48
	ctx.lr = 0x82241C4C;
	sub_8235EC48(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,940(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 940);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241C68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpw cr6,r29,r3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x82241790
	if (ctx.cr6.lt) goto loc_82241790;
loc_82241C70:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,392(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 392);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241C84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x82241d64
	if (ctx.cr0.eq) goto loc_82241D64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82241C90:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82241c90
	if (!ctx.cr6.eq) goto loc_82241C90;
	// subf r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi. r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82241d64
	if (ctx.cr0.eq) goto loc_82241D64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// add r4,r30,r23
	ctx.r4.u64 = ctx.r30.u64 + ctx.r23.u64;
	// bl 0x822489e0
	ctx.lr = 0x82241CBC;
	sub_822489E0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r4,r11,4828
	ctx.r4.s64 = ctx.r11.s64 + 4828;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_82241CCC:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82241ccc
	if (!ctx.cr6.eq) goto loc_82241CCC;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x822390c0
	ctx.lr = 0x82241CF0;
	sub_822390C0(ctx, base);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82241CF4:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82241cf4
	if (!ctx.cr6.eq) goto loc_82241CF4;
	// subf r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x822390c0
	ctx.lr = 0x82241D1C;
	sub_822390C0(ctx, base);
	// addis r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 65536;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// addi r30,r30,-3236
	ctx.r30.s64 = ctx.r30.s64 + -3236;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82239208
	ctx.lr = 0x82241D38;
	sub_82239208(ctx, base);
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82241d4c
	if (ctx.cr6.lt) goto loc_82241D4C;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x82241d50
	goto loc_82241D50;
loc_82241D4C:
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
loc_82241D50:
	// bl 0x82575df0
	ctx.lr = 0x82241D54;
	sub_82575DF0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8235ec48
	ctx.lr = 0x82241D64;
	sub_8235EC48(ctx, base);
loc_82241D64:
	// bl 0x82213210
	ctx.lr = 0x82241D68;
	sub_82213210(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r10,4036(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 4036);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addic r9,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// subfe r4,r9,r10
	temp.u8 = (~ctx.r9.u32 + ctx.r10.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r9.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r11,56(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82241D8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82241D8C:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822B8AA0) {
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
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// lfs f31,-4104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4104);
	ctx.f31.f64 = double(temp.f32);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x822B8AE8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822b8b08
	if (ctx.cr0.eq) goto loc_822B8B08;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r4,r11,1340
	ctx.r4.s64 = ctx.r11.s64 + 1340;
	// bl 0x82223b50
	ctx.lr = 0x822B8B00;
	sub_82223B50(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x822b8b0c
	goto loc_822B8B0C;
loc_822B8B08:
	// li r31,0
	ctx.r31.s64 = 0;
loc_822B8B0C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822b8bfc
	if (ctx.cr6.eq) goto loc_822B8BFC;
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
	ctx.lr = 0x822B8B2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,4
	ctx.r9.s64 = 4;
	// sth r10,88(r31)
	REX_STORE_U16(ctx.r31.u32 + 88, ctx.r10.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r9,102(r31)
	REX_STORE_U16(ctx.r31.u32 + 102, ctx.r9.u16);
	// beq cr6,0x822b8b4c
	if (ctx.cr6.eq) goto loc_822B8B4C;
	// sth r10,84(r11)
	REX_STORE_U16(ctx.r11.u32 + 84, ctx.r10.u16);
loc_822B8B4C:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,91(r31)
	REX_STORE_U8(ctx.r31.u32 + 91, ctx.r10.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822b8b64
	if (ctx.cr6.eq) goto loc_822B8B64;
	// stb r10,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r10.u8);
loc_822B8B64:
	// li r11,255
	ctx.r11.s64 = 255;
	// lis r30,-32240
	ctx.r30.s64 = -2112880640;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// addi r10,r30,12236
	ctx.r10.s64 = ctx.r30.s64 + 12236;
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// lfs f1,2044(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2044);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82223bf0
	ctx.lr = 0x822B8B9C;
	sub_82223BF0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,12236(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12236);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822B8BB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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
	ctx.lr = 0x822B8BCC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x822B8BD8;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822b8bfc
	if (!ctx.cr6.eq) goto loc_822B8BFC;
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
	ctx.lr = 0x822B8BFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822B8BFC:
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

DEFINE_REX_FUNC(sub_822C4170) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x822C4178;
	__savegprlr_24(ctx, base);
	// stfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f29.u64);
	// stfd f30,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C41A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r26,r11,14376
	ctx.r26.s64 = ctx.r11.s64 + 14376;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3108
	ctx.r11.s64 = ctx.r11.s64 + -3108;
	// lfs f30,-2140(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -2140);
	ctx.f30.f64 = double(temp.f32);
	// stfs f30,0(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// bne 0x822c41d0
	if (!ctx.cr0.eq) goto loc_822C41D0;
	// lfs f0,-1904(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1904);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_822C41D0:
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// addi r25,r25,-3164
	ctx.r25.s64 = ctx.r25.s64 + -3164;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bgt cr6,0x822c4fb8
	if (ctx.cr6.gt) goto loc_822C4FB8;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r12,r12,-4504
	ctx.r12.s64 = ctx.r12.s64 + -4504;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32212
	ctx.r12.s64 = -2111045632;
	// addi r12,r12,16908
	ctx.r12.s64 = ctx.r12.s64 + 16908;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_822C420C;
	case 1:
		goto loc_822C4320;
	case 2:
		goto loc_822C432C;
	case 3:
		goto loc_822C4448;
	case 4:
		goto loc_822C4570;
	case 5:
		goto loc_822C47D4;
	case 6:
		goto loc_822C4918;
	case 7:
		goto loc_822C4B24;
	case 8:
		goto loc_822C4BAC;
	case 9:
		goto loc_822C4CB4;
	case 10:
		goto loc_822C4DF8;
	case 11:
		goto loc_822C4FB8;
	case 12:
		goto loc_822C4E50;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_822C420C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f31,-1908(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f31.f64 = double(temp.f32);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// ori r11,r11,62412
	ctx.r11.u64 = ctx.r11.u64 | 62412;
	// stfsx f31,r31,r11
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C4238;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f1,712(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 712);
	ctx.f1.f64 = double(temp.f32);
	// ori r11,r11,62404
	ctx.r11.u64 = ctx.r11.u64 | 62404;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// ori r10,r10,62432
	ctx.r10.u64 = ctx.r10.u64 | 62432;
	// li r30,1
	ctx.r30.s64 = 1;
	// lis r29,-32240
	ctx.r29.s64 = -2112880640;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lfs f2,-29492(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -29492);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822C4268;
	sub_825A4A40(ctx, base);
	// lfs f0,712(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 712);
	ctx.f0.f64 = double(temp.f32);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lfs f2,-29492(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -29492);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825a4a40
	ctx.lr = 0x822C4280;
	sub_825A4A40(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f1,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f1,88(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r4,110
	ctx.r4.s64 = 110;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,90
	ctx.r3.s64 = 90;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// bl 0x825a49b0
	ctx.lr = 0x822C42E8;
	sub_825A49B0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// stw r30,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r30.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r10,-18420
	ctx.r11.s64 = ctx.r10.s64 + -18420;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,-12232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12232);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r10,62440
	ctx.r11.u64 = ctx.r10.u64 | 62440;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// b 0x822c4fb8
	goto loc_822C4FB8;
loc_822C4320:
	// lfs f0,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 152, temp.u32);
	// b 0x822c4fb8
	goto loc_822C4FB8;
loc_822C432C:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-3104
	ctx.r29.s64 = ctx.r29.s64 + -3104;
	// addi r30,r30,-3124
	ctx.r30.s64 = ctx.r30.s64 + -3124;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// lfs f1,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
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
	ctx.lr = 0x822C4364;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x822c438c
	if (!ctx.cr6.lt) goto loc_822C438C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f12,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f13,2992(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2992);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f13,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// b 0x822c4390
	goto loc_822C4390;
loc_822C438C:
	// stfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_822C4390:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r11,32704
	ctx.r11.s64 = ctx.r11.s64 + 32704;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f0,128(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// blt cr6,0x822c4fb8
	if (ctx.cr6.lt) goto loc_822C4FB8;
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x822c4fb8
	if (!ctx.cr6.gt) goto loc_822C4FB8;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-1908(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f1.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822C443C;
	sub_8224A2A0(ctx, base);
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x822c4f6c
	goto loc_822C4F6C;
loc_822C4448:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r11,32704
	ctx.r8.s64 = ctx.r11.s64 + 32704;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,132(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r30,r30,-3104
	ctx.r30.s64 = ctx.r30.s64 + -3104;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r11,r11,12216
	ctx.r11.s64 = ctx.r11.s64 + 12216;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r10.u64);
	// lfs f0,-268(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -268);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f31,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r10,74(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822c4fb8
	if (ctx.cr0.eq) goto loc_822C4FB8;
	// lfs f13,-13508(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13508);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x822c4fb8
	if (!ctx.cr6.gt) goto loc_822C4FB8;
	// lfs f31,-1908(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f31.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x8224a2a0
	ctx.lr = 0x822C4518;
	sub_8224A2A0(ctx, base);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
loc_822C451C:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r29,r29,-3148
	ctx.r29.s64 = ctx.r29.s64 + -3148;
	// bl 0x8222ff78
	ctx.lr = 0x822C4534;
	sub_8222FF78(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x822c51a0
	ctx.lr = 0x822C453C;
	sub_822C51A0(ctx, base);
	// stfs f31,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_822C4540:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-9856
	ctx.r11.s64 = ctx.r11.s64 + -9856;
	// ori r10,r10,62416
	ctx.r10.u64 = ctx.r10.u64 | 62416;
	// ori r9,r9,62424
	ctx.r9.u64 = ctx.r9.u64 | 62424;
	// li r8,4
	ctx.r8.s64 = 4;
	// lfs f0,-22360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22360);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r8.u32);
	// stfsx f1,r31,r10
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// b 0x822c4fb8
	goto loc_822C4FB8;
loc_822C4570:
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,232
	ctx.r3.s64 = ctx.r1.s64 + 232;
	// addi r27,r27,-3148
	ctx.r27.s64 = ctx.r27.s64 + -3148;
	// bl 0x8222ff78
	ctx.lr = 0x822C458C;
	sub_8222FF78(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x8223e420
	ctx.lr = 0x822C4594;
	sub_8223E420(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r29,r11,-18420
	ctx.r29.s64 = ctx.r11.s64 + -18420;
	// ori r11,r10,62440
	ctx.r11.u64 = ctx.r10.u64 | 62440;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lfs f0,-30020(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -30020);
	ctx.f0.f64 = double(temp.f32);
	// ori r30,r9,62424
	ctx.r30.u64 = ctx.r9.u64 | 62424;
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x822c45e4
	if (!ctx.cr6.lt) goto loc_822C45E4;
	// lfs f0,-29832(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -29832);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r31,r30
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x822c45e4
	if (ctx.cr6.lt) goto loc_822C45E4;
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x822c4f6c
	goto loc_822C4F6C;
loc_822C45E4:
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
	ctx.lr = 0x822C45FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,74(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822c4714
	if (ctx.cr0.eq) goto loc_822C4714;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x822c4678
	if (!ctx.cr6.eq) goto loc_822C4678;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r1,248
	ctx.r3.s64 = ctx.r1.s64 + 248;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8222ff78
	ctx.lr = 0x822C4644;
	sub_8222FF78(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
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
	// bne 0x822c46dc
	if (!ctx.cr0.eq) goto loc_822C46DC;
loc_822C4678:
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// bne cr6,0x822c4714
	if (!ctx.cr6.eq) goto loc_822C4714;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r1,264
	ctx.r3.s64 = ctx.r1.s64 + 264;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8222ff78
	ctx.lr = 0x822C46A8;
	sub_8222FF78(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
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
	// beq 0x822c4714
	if (ctx.cr0.eq) goto loc_822C4714;
loc_822C46DC:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-1908(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f1.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822C46FC;
	sub_8224A2A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,5
	ctx.r10.s64 = 5;
	// ori r11,r11,62432
	ctx.r11.u64 = ctx.r11.u64 | 62432;
	// stw r10,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
	// stfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// b 0x822c4fb8
	goto loc_822C4FB8;
loc_822C4714:
	// bl 0x82213210
	ctx.lr = 0x822C4718;
	sub_82213210(ctx, base);
	// add r30,r31,r30
	ctx.r30.u64 = ctx.r31.u64 + ctx.r30.u64;
	// lbz r11,4036(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4036);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// beq 0x822c473c
	if (ctx.cr0.eq) goto loc_822C473C;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r11,r11,12216
	ctx.r11.s64 = ctx.r11.s64 + 12216;
	// lfs f13,-10308(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10308);
	ctx.f13.f64 = double(temp.f32);
	// b 0x822c4740
	goto loc_822C4740;
loc_822C473C:
	// lfs f13,-29832(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -29832);
	ctx.f13.f64 = double(temp.f32);
loc_822C4740:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x822c4758
	if (!ctx.cr6.lt) goto loc_822C4758;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f13,-20940(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20940);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f31,f13,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_822C4758:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,-3104
	ctx.r11.s64 = ctx.r11.s64 + -3104;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// bl 0x8222ff78
	ctx.lr = 0x822C4780;
	sub_8222FF78(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x822c51a0
	ctx.lr = 0x822C4788;
	sub_822C51A0(ctx, base);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfs f3,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// addi r28,r28,-3120
	ctx.r28.s64 = ctx.r28.s64 + -3120;
	// lfs f1,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8223eea0
	ctx.lr = 0x822C47A0;
	sub_8223EEA0(ctx, base);
	// stfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x822C47A8;
	sub_82738CC0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// lfs f1,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82738be0
	ctx.lr = 0x822C47C0;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,132(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// b 0x822c4fb8
	goto loc_822C4FB8;
loc_822C47D4:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r11,r11,-18420
	ctx.r11.s64 = ctx.r11.s64 + -18420;
	// lfs f30,-6220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6220);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x82213210
	ctx.lr = 0x822C47E4;
	sub_82213210(ctx, base);
	// lbz r10,4036(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 4036);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r11,r11,12216
	ctx.r11.s64 = ctx.r11.s64 + 12216;
	// beq 0x822c47fc
	if (ctx.cr0.eq) goto loc_822C47FC;
	// lfs f30,-23336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23336);
	ctx.f30.f64 = double(temp.f32);
loc_822C47FC:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f30,108(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r30,-3104
	ctx.r30.s64 = ctx.r30.s64 + -3104;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f0,128(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,-268(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -268);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r10.u64);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// fmadds f0,f31,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r10,74(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822c4fb8
	if (ctx.cr0.eq) goto loc_822C4FB8;
	// lfs f13,-13776(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13776);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x822c4fb8
	if (!ctx.cr6.gt) goto loc_822C4FB8;
	// lfs f31,-1908(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f31.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x8224a2a0
	ctx.lr = 0x822C48D0;
	sub_8224A2A0(ctx, base);
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
	ctx.lr = 0x822C48E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
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
	// beq 0x822c490c
	if (ctx.cr0.eq) goto loc_822C490C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_822C490C:
	// bctrl 
	ctx.lr = 0x822C4910;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// b 0x822c451c
	goto loc_822C451C;
loc_822C4918:
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
	ctx.lr = 0x822C4930;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ori r30,r11,62388
	ctx.r30.u64 = ctx.r11.u64 | 62388;
	// bne 0x822c499c
	if (!ctx.cr0.eq) goto loc_822C499C;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfsx f0,r31,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8222ff78
	ctx.lr = 0x822C4968;
	sub_8222FF78(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
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
	// bne 0x822c46dc
	if (!ctx.cr0.eq) goto loc_822C46DC;
loc_822C499C:
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// bne cr6,0x822c4a00
	if (!ctx.cr6.eq) goto loc_822C4A00;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfsx f0,r31,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8222ff78
	ctx.lr = 0x822C49CC;
	sub_8222FF78(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
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
	// bne 0x822c46dc
	if (!ctx.cr0.eq) goto loc_822C46DC;
loc_822C4A00:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r11,r11,-18420
	ctx.r11.s64 = ctx.r11.s64 + -18420;
	// lfs f30,-6220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6220);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x82213210
	ctx.lr = 0x822C4A10;
	sub_82213210(ctx, base);
	// lbz r10,4036(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 4036);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r30,r11,12216
	ctx.r30.s64 = ctx.r11.s64 + 12216;
	// beq 0x822c4a28
	if (ctx.cr0.eq) goto loc_822C4A28;
	// lfs f30,-23336(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -23336);
	ctx.f30.f64 = double(temp.f32);
loc_822C4A28:
	// lfs f29,-268(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -268);
	ctx.f29.f64 = double(temp.f32);
	// bl 0x82213210
	ctx.lr = 0x822C4A30;
	sub_82213210(ctx, base);
	// lbz r11,4036(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4036);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822c4a44
	if (ctx.cr0.eq) goto loc_822C4A44;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f29,-29492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29492);
	ctx.f29.f64 = double(temp.f32);
loc_822C4A44:
	// li r4,200
	ctx.r4.s64 = 200;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x822C4A54;
	sub_825A49B0(ctx, base);
	// lfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f0,132(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r11,r11,-3104
	ctx.r11.s64 = ctx.r11.s64 + -3104;
	// stfs f30,148(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f30,144(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f30,156(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f30,152(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-96(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -96);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-268(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -268);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// fcfid f12,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(ctx.f12.s64);
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f0,f12,f0,f29
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f29.f64)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r10.u64);
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f31,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f31.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822c4fb8
	if (!ctx.cr6.gt) goto loc_822C4FB8;
	// li r10,7
	ctx.r10.s64 = 7;
	// lfs f0,-1908(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stw r10,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
	// b 0x822c4fb8
	goto loc_822C4FB8;
loc_822C4B24:
	// li r11,8
	ctx.r11.s64 = 8;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r30,r30,-3148
	ctx.r30.s64 = ctx.r30.s64 + -3148;
	// bl 0x8222ff78
	ctx.lr = 0x822C4B48;
	sub_8222FF78(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x822c51a0
	ctx.lr = 0x822C4B50;
	sub_822C51A0(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lwz r7,4(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f13,-1908(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lfs f0,25300(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 25300);
	ctx.f0.f64 = double(temp.f32);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// ori r10,r8,62416
	ctx.r10.u64 = ctx.r8.u64 | 62416;
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// ori r8,r6,62432
	ctx.r8.u64 = ctx.r6.u64 | 62432;
	// addi r11,r11,-18420
	ctx.r11.s64 = ctx.r11.s64 + -18420;
	// addi r4,r4,-3140
	ctx.r4.s64 = ctx.r4.s64 + -3140;
	// ori r6,r5,62424
	ctx.r6.u64 = ctx.r5.u64 | 62424;
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stfsx f13,r31,r8
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// lfs f12,-29832(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29832);
	ctx.f12.f64 = double(temp.f32);
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stfsx f12,r31,r6
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// stw r7,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r7.u32);
	// b 0x822c4fb8
	goto loc_822C4FB8;
loc_822C4BAC:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r29,r29,-3104
	ctx.r29.s64 = ctx.r29.s64 + -3104;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r28,r11,-18420
	ctx.r28.s64 = ctx.r11.s64 + -18420;
	// addi r30,r30,-3112
	ctx.r30.s64 = ctx.r30.s64 + -3112;
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// stfs f12,0(r29)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// lfs f13,-30060(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -30060);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x822c4bf0
	if (!ctx.cr6.lt) goto loc_822C4BF0;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f13,-20940(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20940);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f31,f13,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_822C4BF0:
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// addi r27,r27,-3140
	ctx.r27.s64 = ctx.r27.s64 + -3140;
	// bl 0x8222ff78
	ctx.lr = 0x822C4C0C;
	sub_8222FF78(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x822c51a0
	ctx.lr = 0x822C4C14;
	sub_822C51A0(ctx, base);
	// addis r24,r31,1
	ctx.r24.s64 = ctx.r31.s64 + 65536;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfs f3,-27904(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -27904);
	ctx.f3.f64 = double(temp.f32);
	// addi r24,r24,-3120
	ctx.r24.s64 = ctx.r24.s64 + -3120;
	// lfs f1,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8223eea0
	ctx.lr = 0x822C4C2C;
	sub_8223EEA0(ctx, base);
	// stfs f1,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x822C4C34;
	sub_82738CC0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// lfs f1,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82738be0
	ctx.lr = 0x822C4C4C;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,132(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// bl 0x8222ff78
	ctx.lr = 0x822C4C70;
	sub_8222FF78(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x8223e420
	ctx.lr = 0x822C4C78;
	sub_8223E420(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r11,r11,12216
	ctx.r11.s64 = ctx.r11.s64 + 12216;
	// stvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -268);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x822c4ca4
	if (ctx.cr6.lt) goto loc_822C4CA4;
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x822c4fb8
	if (!ctx.cr6.gt) goto loc_822C4FB8;
loc_822C4CA4:
	// lfs f0,-1908(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f0.f64 = double(temp.f32);
	// li r11,9
	ctx.r11.s64 = 9;
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// b 0x822c4f6c
	goto loc_822C4F6C;
loc_822C4CB4:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,12216
	ctx.r11.s64 = ctx.r11.s64 + 12216;
	// addi r30,r30,-3104
	ctx.r30.s64 = ctx.r30.s64 + -3104;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r8,r8,-28864
	ctx.r8.s64 = ctx.r8.s64 + -28864;
	// lfs f0,-268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -268);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// fmadds f0,f31,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lfs f0,132(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f13,128(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r28,r11,-18420
	ctx.r28.s64 = ctx.r11.s64 + -18420;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ori r11,r5,62440
	ctx.r11.u64 = ctx.r5.u64 | 62440;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lfs f0,-30020(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -30020);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r10.u64);
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x82213210
	ctx.lr = 0x822C4D68;
	sub_82213210(ctx, base);
	// lbz r11,4036(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4036);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822c4d78
	if (ctx.cr0.eq) goto loc_822C4D78;
	// lfs f31,-30020(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -30020);
	ctx.f31.f64 = double(temp.f32);
loc_822C4D78:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x822c4fb8
	if (!ctx.cr6.gt) goto loc_822C4FB8;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// addi r29,r29,-3148
	ctx.r29.s64 = ctx.r29.s64 + -3148;
	// bl 0x8222ff78
	ctx.lr = 0x822C4DA0;
	sub_8222FF78(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8223e420
	ctx.lr = 0x822C4DA8;
	sub_8223E420(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,-30020(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -30020);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x822c4dd0
	if (!ctx.cr6.lt) goto loc_822C4DD0;
	// lfs f0,-1908(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f0.f64 = double(temp.f32);
	// li r11,6
	ctx.r11.s64 = 6;
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// b 0x822c4f6c
	goto loc_822C4F6C;
loc_822C4DD0:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// bl 0x8222ff78
	ctx.lr = 0x822C4DE4;
	sub_8222FF78(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x822c51a0
	ctx.lr = 0x822C4DEC;
	sub_822C51A0(ctx, base);
	// lfs f0,-1908(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// b 0x822c4540
	goto loc_822C4540;
loc_822C4DF8:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f1,-1908(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f1.f64 = double(temp.f32);
	// li r10,12
	ctx.r10.s64 = 12;
	// lwz r9,264(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// ori r11,r11,62432
	ctx.r11.u64 = ctx.r11.u64 | 62432;
	// stw r10,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,7
	ctx.r4.s64 = 7;
	// stfsx f1,r31,r11
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822C4E2C;
	sub_8224A2A0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// bl 0x8222ff78
	ctx.lr = 0x822C4E3C;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// bl 0x822c54b8
	ctx.lr = 0x822C4E4C;
	sub_822C54B8(ctx, base);
	// b 0x822c4fb8
	goto loc_822C4FB8;
loc_822C4E50:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r11,7
	ctx.r11.s64 = 7;
	// addi r30,r30,-3104
	ctx.r30.s64 = ctx.r30.s64 + -3104;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// divw r11,r10,r11
	ctx.r11.u64 = uint32_t((ctx.r11.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r10.s32 / ctx.r11.s32 : 0);
	// mulli r11,r11,7
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(7));
	// subf. r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822c4edc
	if (!ctx.cr0.eq) goto loc_822C4EDC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8222ff78
	ctx.lr = 0x822C4E98;
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
	// lfs f30,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x822C4EB4;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// li r3,171
	ctx.r3.s64 = 171;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82240a58
	ctx.lr = 0x822C4EDC;
	sub_82240A58(ctx, base);
loc_822C4EDC:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lwz r9,264(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r29,-32226
	ctx.r29.s64 = -2111963136;
	// addi r8,r29,-9856
	ctx.r8.s64 = ctx.r29.s64 + -9856;
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// lfs f0,12216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12216);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f31,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lfs f31,-20272(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -20272);
	ctx.f31.f64 = double(temp.f32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,236(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C4F24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,-9856(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -9856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fnmsubs f12,f11,f31,f0
	ctx.f12.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f31.f64, -ctx.f0.f64)));
	// lfs f13,-1908(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bgt cr6,0x822c4f44
	if (ctx.cr6.gt) goto loc_822C4F44;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
loc_822C4F44:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x822c4f74
	if (ctx.cr6.gt) goto loc_822C4F74;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x822C4F68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
loc_822C4F6C:
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// b 0x822c4fb8
	goto loc_822C4FB8;
loc_822C4F74:
	// fctidz f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r11,87(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// fctidz f0,f12
	ctx.f0.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// stb r11,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r11.u8);
	// stb r9,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r9.u8);
	// stb r9,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r9.u8);
	// stb r9,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r9.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// bctrl 
	ctx.lr = 0x822C4FB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822C4FB8:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
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

DEFINE_REX_FUNC(sub_8233C578) {
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
	// addi r30,r30,-3160
	ctx.r30.s64 = ctx.r30.s64 + -3160;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8233c708
	if (ctx.cr6.eq) goto loc_8233C708;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8233c708
	if (!ctx.cr6.eq) goto loc_8233C708;
	// bl 0x82232628
	ctx.lr = 0x8233C5BC;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8233c708
	if (!ctx.cr0.eq) goto loc_8233C708;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// addi r5,r11,1272
	ctx.r5.s64 = ctx.r11.s64 + 1272;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x8233C5D8;
	sub_8255F918(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r4,5
	ctx.r4.s64 = 5;
	// stb r10,56(r11)
	REX_STORE_U8(ctx.r11.u32 + 56, ctx.r10.u8);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8233C600;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8233c63c
	if (ctx.cr6.eq) goto loc_8233C63C;
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
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x823aefa8
	ctx.lr = 0x8233C63C;
	sub_823AEFA8(ctx, base);
loc_8233C63C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// ori r10,r10,62392
	ctx.r10.u64 = ctx.r10.u64 | 62392;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// sthx r9,r31,r10
	REX_STORE_U16(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u16);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3024
	ctx.r11.s64 = ctx.r11.s64 + -3024;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq 0x8233c6bc
	if (ctx.cr0.eq) goto loc_8233C6BC;
	// lis r10,-32204
	ctx.r10.s64 = -2110521344;
	// addi r10,r10,-13936
	ctx.r10.s64 = ctx.r10.s64 + -13936;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8233c6ac
	if (ctx.cr6.eq) goto loc_8233C6AC;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lis r7,-32204
	ctx.r7.s64 = -2110521344;
	// ori r10,r10,62396
	ctx.r10.u64 = ctx.r10.u64 | 62396;
	// ori r9,r9,62516
	ctx.r9.u64 = ctx.r9.u64 | 62516;
	// addi r7,r7,-13936
	ctx.r7.s64 = ctx.r7.s64 + -13936;
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f0,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stbx r6,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r6.u8);
loc_8233C6AC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8233c990
	ctx.lr = 0x8233C6B8;
	sub_8233C990(ctx, base);
	// b 0x8233c708
	goto loc_8233C708;
loc_8233C6BC:
	// lis r10,-32204
	ctx.r10.s64 = -2110521344;
	// addi r10,r10,-14288
	ctx.r10.s64 = ctx.r10.s64 + -14288;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8233c6fc
	if (ctx.cr6.eq) goto loc_8233C6FC;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lis r7,-32204
	ctx.r7.s64 = -2110521344;
	// ori r10,r10,62396
	ctx.r10.u64 = ctx.r10.u64 | 62396;
	// ori r9,r9,62516
	ctx.r9.u64 = ctx.r9.u64 | 62516;
	// addi r7,r7,-14288
	ctx.r7.s64 = ctx.r7.s64 + -14288;
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f0,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stbx r6,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r6.u8);
loc_8233C6FC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8233c830
	ctx.lr = 0x8233C708;
	sub_8233C830(ctx, base);
loc_8233C708:
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

DEFINE_REX_FUNC(sub_823472C8) {
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
	// ori r4,r4,62484
	ctx.r4.u64 = ctx.r4.u64 | 62484;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823472F0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82347300
	if (ctx.cr0.eq) goto loc_82347300;
	// bl 0x82347048
	ctx.lr = 0x823472FC;
	sub_82347048(ctx, base);
	// b 0x82347304
	goto loc_82347304;
loc_82347300:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82347304:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8234A1A0) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x8234A1C4;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8234a1f0
	if (ctx.cr0.eq) goto loc_8234A1F0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b88
	ctx.lr = 0x8234A1D4;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,48
	ctx.r5.s64 = 48;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x8234A1E8;
	sub_825F8BF8(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// b 0x8234a1f4
	goto loc_8234A1F4;
loc_8234A1F0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8234A1F4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8234a314
	if (ctx.cr6.eq) goto loc_8234A314;
	// lwz r10,424(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8234a314
	if (ctx.cr6.eq) goto loc_8234A314;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// addi r7,r8,12236
	ctx.r7.s64 = ctx.r8.s64 + 12236;
	// li r9,48
	ctx.r9.s64 = 48;
	// lfs f0,12236(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,232(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_8234A238:
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// ld r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,-1
	ctx.r5.s64 = -1;
	// addi r6,r10,-32
	ctx.r6.s64 = ctx.r10.s64 + -32;
	// stw r5,-4(r10)
	REX_STORE_U32(ctx.r10.u32 + -4, ctx.r5.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r4,4(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r3,8(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r8,12(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// std r7,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r7.u64);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// stw r5,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// stw r4,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r4.u32);
	// stw r3,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r3.u32);
	// stw r8,12(r6)
	REX_STORE_U32(ctx.r6.u32 + 12, ctx.r8.u32);
	// bne 0x8234a238
	if (!ctx.cr0.eq) goto loc_8234A238;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r6,-32226
	ctx.r6.s64 = -2111963136;
	// ori r10,r10,62424
	ctx.r10.u64 = ctx.r10.u64 | 62424;
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r6,r6,-4080
	ctx.r6.s64 = ctx.r6.s64 + -4080;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lwzx r10,r30,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// lis r5,-32111
	ctx.r5.s64 = -2104426496;
	// lfs f12,1072(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 1072);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-8644(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lfs f13,1576(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 1576);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stw r10,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r10.u32);
	// ori r8,r8,62428
	ctx.r8.u64 = ctx.r8.u64 | 62428;
	// stb r9,71(r11)
	REX_STORE_U8(ctx.r11.u32 + 71, ctx.r9.u8);
	// ori r7,r7,62432
	ctx.r7.u64 = ctx.r7.u64 | 62432;
	// lwz r10,408(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 408);
	// li r9,48
	ctx.r9.s64 = 48;
	// lhz r6,6(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 6);
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// std r6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stw r10,408(r11)
	REX_STORE_U32(ctx.r11.u32 + 408, ctx.r10.u32);
	// fmadds f0,f11,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f13.f64)));
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// stfs f0,412(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 412, temp.u32);
	// lwz r10,3596(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 3596);
	// stw r10,368(r11)
	REX_STORE_U32(ctx.r11.u32 + 368, ctx.r10.u32);
	// lwz r10,408(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 408);
	// ori r10,r10,448
	ctx.r10.u64 = ctx.r10.u64 | 448;
	// stw r10,408(r11)
	REX_STORE_U32(ctx.r11.u32 + 408, ctx.r10.u32);
	// stwx r11,r30,r8
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, ctx.r11.u32);
	// stwx r9,r30,r7
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.r9.u32);
loc_8234A314:
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

DEFINE_REX_FUNC(sub_82350CB8) {
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
	// bl 0x82350488
	ctx.lr = 0x82350CD4;
	sub_82350488(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r30,164(r31)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r31.u32 + 164);
	// stb r11,164(r31)
	REX_STORE_U8(ctx.r31.u32 + 164, ctx.r11.u8);
	// bl 0x82350a60
	ctx.lr = 0x82350CE8;
	sub_82350A60(ctx, base);
	// stb r30,164(r31)
	REX_STORE_U8(ctx.r31.u32 + 164, ctx.r30.u8);
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

DEFINE_REX_FUNC(sub_82351728) {
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
	// addi r7,r7,-31808
	ctx.r7.s64 = ctx.r7.s64 + -31808;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

DEFINE_REX_FUNC(sub_82358D08) {
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
	// stfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f29.u64);
	// stfd f30,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f30.u64);
	// stfd f31,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ld r10,96(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 96);
	// li r9,4
	ctx.r9.s64 = 4;
	// ori r8,r11,63840
	ctx.r8.u64 = ctx.r11.u64 | 63840;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lvsl v0,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// blt cr6,0x82358da0
	if (ctx.cr6.lt) goto loc_82358DA0;
	// lfs f30,1132(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1132);
	ctx.f30.f64 = double(temp.f32);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// b 0x82358dac
	goto loc_82358DAC;
loc_82358DA0:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f31,1132(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1132);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,28272(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28272);
	ctx.f30.f64 = double(temp.f32);
loc_82358DAC:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f2,-30132(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30132);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82358DBC;
	sub_825A4A40(ctx, base);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82358DD0;
	sub_825A4A40(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f13,144(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// fctid f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fnmsubs f9,f0,f13,f1
	ctx.f9.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f1.f64)));
	// fadds f1,f9,f12
	ctx.f1.f64 = double(float(ctx.f9.f64 + ctx.f12.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x82358E00;
	sub_822EA1A8(ctx, base);
	// fmuls f8,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f29.f64));
	// fmr f1,f9
	ctx.f1.f64 = ctx.f9.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x82358E0C;
	sub_822EA1A8(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// fmuls f0,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f29.f64));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ori r11,r11,64076
	ctx.r11.u64 = ctx.r11.u64 | 64076;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f8,108(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lfsx f0,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stfs f8,104(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f8,100(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ori r10,r10,64080
	ctx.r10.u64 = ctx.r10.u64 | 64080;
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
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lfsx f0,r31,r10
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f29,-48(r1)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f30,-40(r1)
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

DEFINE_REX_FUNC(sub_82365BA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82365BA8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r4,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r10,20516
	ctx.r10.s64 = ctx.r10.s64 + 20516;
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// sth r30,16(r3)
	REX_STORE_U16(ctx.r3.u32 + 16, ctx.r30.u16);
	// stw r30,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// addi r10,r9,22072
	ctx.r10.s64 = ctx.r9.s64 + 22072;
	// stw r30,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r11,12468
	ctx.r29.s64 = ctx.r11.s64 + 12468;
	// lwz r3,44(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82365BFC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82365c08
	if (ctx.cr0.eq) goto loc_82365C08;
	// stw r3,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
loc_82365C08:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82365c14
	if (ctx.cr0.eq) goto loc_82365C14;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_82365C14:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// stw r30,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// addi r9,r11,-32216
	ctx.r9.s64 = ctx.r11.s64 + -32216;
	// lfs f7,1908(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1908);
	ctx.f7.f64 = double(temp.f32);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// stfs f7,68(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// addi r6,r10,-6412
	ctx.r6.s64 = ctx.r10.s64 + -6412;
	// lfs f6,-32216(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32216);
	ctx.f6.f64 = double(temp.f32);
	// lfs f8,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f8.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,-3144(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8696(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8696);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3136(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3136);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28808(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 28808);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,28812(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 28812);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,23468(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 23468);
	ctx.f9.f64 = double(temp.f32);
	// stfs f0,40(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// stfs f13,44(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// stfs f12,48(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// stfs f11,52(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// stfs f10,56(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// stfs f9,60(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// stfs f8,64(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stfs f6,72(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8236BA78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8236BA80;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r3,292
	ctx.r29.s64 = ctx.r3.s64 + 292;
	// li r30,2
	ctx.r30.s64 = 2;
loc_8236BA90:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823edfb8
	ctx.lr = 0x8236BA98;
	sub_823EDFB8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,64
	ctx.r29.s64 = ctx.r29.s64 + 64;
	// bne 0x8236ba90
	if (!ctx.cr0.eq) goto loc_8236BA90;
	// li r24,0
	ctx.r24.s64 = 0;
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
	// bl 0x824281d8
	ctx.lr = 0x8236BAB0;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8236bde0
	if (ctx.cr0.eq) goto loc_8236BDE0;
	// bl 0x82444358
	ctx.lr = 0x8236BABC;
	sub_82444358(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// bl 0x8242a5e0
	ctx.lr = 0x8236BAC4;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8236bad4
	if (!ctx.cr0.eq) goto loc_8236BAD4;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// b 0x8236bad8
	goto loc_8236BAD8;
loc_8236BAD4:
	// bl 0x8242aa28
	ctx.lr = 0x8236BAD8;
	sub_8242AA28(ctx, base);
loc_8236BAD8:
	// lwz r29,440(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r30,r31,416
	ctx.r30.s64 = ctx.r31.s64 + 416;
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// beq 0x8236bc9c
	if (ctx.cr0.eq) goto loc_8236BC9C;
	// lwz r26,416(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// stw r26,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
loc_8236BAF8:
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplw cr6,r26,r9
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r9.u32, ctx.xer);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bne cr6,0x8236bb1c
	if (!ctx.cr6.eq) goto loc_8236BB1C;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8236bb20
	if (ctx.cr6.eq) goto loc_8236BB20;
loc_8236BB1C:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8236BB20:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8236bc00
	if (!ctx.cr0.eq) goto loc_8236BC00;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8236c610
	ctx.lr = 0x8236BB30;
	sub_8236C610(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// rlwinm. r7,r10,25,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8236bb8c
	if (!ctx.cr0.eq) goto loc_8236BB8C;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// b 0x8236bb90
	goto loc_8236BB90;
loc_8236BB8C:
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
loc_8236BB90:
	// lwz r10,-12816(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + -12816);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8236bbdc
	if (!ctx.cr6.eq) goto loc_8236BBDC;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8236bbdc
	if (ctx.cr6.eq) goto loc_8236BBDC;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8236bbdc
	if (ctx.cr0.eq) goto loc_8236BBDC;
	// subf r11,r25,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r25.u64;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 & ctx.r8.u64;
loc_8236BBDC:
	// rlwinm r11,r7,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r27,r8,r27
	ctx.r27.u64 = ctx.r8.u64 + ctx.r27.u64;
	// addi r3,r11,292
	ctx.r3.s64 = ctx.r11.s64 + 292;
	// bl 0x8237fdd0
	ctx.lr = 0x8236BBF4;
	sub_8237FDD0(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// b 0x8236baf8
	goto loc_8236BAF8;
loc_8236BC00:
	// lwz r11,452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// stw r24,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r24.u32);
	// b 0x8236bc24
	goto loc_8236BC24;
loc_8236BC0C:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lwz r10,464(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 464);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r10.u32);
loc_8236BC24:
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8236bc0c
	if (!ctx.cr6.eq) goto loc_8236BC0C;
	// lwz r11,464(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 464);
	// lwz r10,412(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// add r27,r11,r27
	ctx.r27.u64 = ctx.r11.u64 + ctx.r27.u64;
	// cmpw cr6,r27,r10
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8236bc90
	if (ctx.cr6.eq) goto loc_8236BC90;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stw r27,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r27.u32);
	// li r8,525
	ctx.r8.s64 = 525;
	// stw r24,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r24.u32);
	// addi r9,r9,20580
	ctx.r9.s64 = ctx.r9.s64 + 20580;
	// stw r8,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// lwz r11,-13060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13060);
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// beq cr6,0x8236bc8c
	if (ctx.cr6.eq) goto loc_8236BC8C;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82364590
	ctx.lr = 0x8236BC8C;
	sub_82364590(ctx, base);
loc_8236BC8C:
	// stw r27,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r27.u32);
loc_8236BC90:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_8236BC9C:
	// lwz r27,416(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// stw r27,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
loc_8236BCA8:
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,24(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmplw cr6,r27,r9
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r9.u32, ctx.xer);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bne cr6,0x8236bccc
	if (!ctx.cr6.eq) goto loc_8236BCCC;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8236bcd0
	if (ctx.cr6.eq) goto loc_8236BCD0;
loc_8236BCCC:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8236BCD0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8236bd74
	if (!ctx.cr0.eq) goto loc_8236BD74;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8236c610
	ctx.lr = 0x8236BCE0;
	sub_8236C610(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
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
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// not r9,r9
	ctx.r9.u64 = ~ctx.r9.u64;
	// cmplw cr6,r25,r10
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r10.u32, ctx.xer);
	// rlwinm r9,r9,25,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bne cr6,0x8236bd54
	if (!ctx.cr6.eq) goto loc_8236BD54;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8236bd50
	if (!ctx.cr6.eq) goto loc_8236BD50;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// neg r28,r11
	ctx.r28.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// b 0x8236bd54
	goto loc_8236BD54;
loc_8236BD50:
	// lwz r28,12(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
loc_8236BD54:
	// rlwinm r11,r9,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r3,r11,292
	ctx.r3.s64 = ctx.r11.s64 + 292;
	// bl 0x8237fdd0
	ctx.lr = 0x8236BD68;
	sub_8237FDD0(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// b 0x8236bca8
	goto loc_8236BCA8;
loc_8236BD74:
	// lwz r11,464(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 464);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8236bdd8
	if (ctx.cr6.eq) goto loc_8236BDD8;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r9,526
	ctx.r9.s64 = 526;
	// stw r28,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r28.u32);
	// addi r10,r10,20580
	ctx.r10.s64 = ctx.r10.s64 + 20580;
	// stw r24,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r24.u32);
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// bl 0x8242a5e0
	ctx.lr = 0x8236BDAC;
	sub_8242A5E0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// stw r10,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// lwz r11,-13060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13060);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8236bdd4
	if (ctx.cr6.eq) goto loc_8236BDD4;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82364590
	ctx.lr = 0x8236BDD4;
	sub_82364590(ctx, base);
loc_8236BDD4:
	// stw r28,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r28.u32);
loc_8236BDD8:
	// lwz r27,412(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// b 0x8236bc90
	goto loc_8236BC90;
loc_8236BDE0:
	// lwz r28,416(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// addi r30,r31,416
	ctx.r30.s64 = ctx.r31.s64 + 416;
	// lwz r29,440(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
loc_8236BDF0:
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,24(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmplw cr6,r28,r9
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r9.u32, ctx.xer);
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bne cr6,0x8236be18
	if (!ctx.cr6.eq) goto loc_8236BE18;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8236be1c
	if (ctx.cr6.eq) goto loc_8236BE1C;
loc_8236BE18:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8236BE1C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8236bc90
	if (!ctx.cr0.eq) goto loc_8236BC90;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8236c610
	ctx.lr = 0x8236BE2C;
	sub_8236C610(ctx, base);
	// lwz r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f13,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
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
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// lwz r10,12(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8236be84
	if (!ctx.cr0.eq) goto loc_8236BE84;
	// neg r10,r10
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r10.u64);
loc_8236BE84:
	// rlwinm r11,r11,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r27,r10,r27
	ctx.r27.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r3,r11,292
	ctx.r3.s64 = ctx.r11.s64 + 292;
	// bl 0x8237fdd0
	ctx.lr = 0x8236BE98;
	sub_8237FDD0(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// b 0x8236bdf0
	goto loc_8236BDF0;
}

DEFINE_REX_FUNC(sub_82384FC0) {
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
	// bne cr6,0x8238508c
	if (!ctx.cr6.eq) goto loc_8238508C;
	// bl 0x8235fd60
	ctx.lr = 0x82384FE4;
	sub_8235FD60(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8238508c
	if (!ctx.cr6.eq) goto loc_8238508C;
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
	// beq 0x82385064
	if (ctx.cr0.eq) goto loc_82385064;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f0,7340(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7340);
	ctx.f0.f64 = double(temp.f32);
loc_8238501C:
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf r10,r7,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r7.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8238503c
	if (ctx.cr6.lt) goto loc_8238503C;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82385044
	goto loc_82385044;
loc_8238503C:
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwzx r10,r10,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_82385044:
	// li r7,2
	ctx.r7.s64 = 2;
	// stfs f0,96(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r7.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stb r6,164(r10)
	REX_STORE_U8(ctx.r10.u32 + 164, ctx.r6.u8);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x8238501c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238501C;
loc_82385064:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82385078;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r11,r11,0,30,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_8238508C:
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

DEFINE_REX_FUNC(sub_823898D0) {
	REX_FUNC_PROLOGUE();
	// lis r3,3
	ctx.r3.s64 = 196608;
	// ori r3,r3,129
	ctx.r3.u64 = ctx.r3.u64 | 129;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82389A00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82389A08;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r11,r11,25576
	ctx.r11.s64 = ctx.r11.s64 + 25576;
	// addi r31,r3,364
	ctx.r31.s64 = ctx.r3.s64 + 364;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r30,1
	ctx.r30.s64 = 1;
	// addi r28,r11,-27424
	ctx.r28.s64 = ctx.r11.s64 + -27424;
loc_82389A2C:
	// stwu r28,-16(r31)
	ea = -16 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r31.u32 = ea;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8245d0d8
	ctx.lr = 0x82389A38;
	sub_8245D0D8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82389a2c
	if (!ctx.cr0.lt) goto loc_82389A2C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,25272
	ctx.r11.s64 = ctx.r11.s64 + 25272;
	// addi r10,r10,2668
	ctx.r10.s64 = ctx.r10.s64 + 2668;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,300(r29)
	REX_STORE_U32(ctx.r29.u32 + 300, ctx.r10.u32);
	// bl 0x8235f568
	ctx.lr = 0x82389A60;
	sub_8235F568(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8238B568) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwa r11,264(r3)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r3.u32 + 264));
	// lfs f13,280(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 280);
	ctx.f13.f64 = double(temp.f32);
	// std r11,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.r11.u64);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lwa r10,268(r3)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r3.u32 + 268));
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r8,r1,-64
	ctx.r8.s64 = ctx.r1.s64 + -64;
	// addi r5,r1,-64
	ctx.r5.s64 = ctx.r1.s64 + -64;
	// addi r7,r1,-48
	ctx.r7.s64 = ctx.r1.s64 + -48;
	// lfd f0,-80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// std r10,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.r10.u64);
	// lfd f12,-80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// lfs f0,624(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 624);
	ctx.f0.f64 = double(temp.f32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// addi r10,r1,-64
	ctx.r10.s64 = ctx.r1.s64 + -64;
	// addi r9,r1,-48
	ctx.r9.s64 = ctx.r1.s64 + -48;
	// addi r6,r1,-48
	ctx.r6.s64 = ctx.r1.s64 + -48;
	// addi r4,r1,-80
	ctx.r4.s64 = ctx.r1.s64 + -80;
	// addi r31,r1,-32
	ctx.r31.s64 = ctx.r1.s64 + -32;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f13,-76(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// stfs f13,-80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// stfs f13,-68(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// stfs f13,-72(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// lvx128 v60,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f12,f11,f0
	ctx.f12.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// stfs f12,-48(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// fsubs f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// lfs f0,26612(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26612);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f0,-52(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// stfs f0,-56(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stfs f0,-60(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// stfs f0,-64(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,-36(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -36, temp.u32);
	// stfs f12,-40(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// stfs f12,-44(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// stfs f11,-64(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// stfs f11,-52(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// stfs f11,-56(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stfs f11,-60(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-48(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-76(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// lfs f12,-64(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,-80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r11,-80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfs f13,-48(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f13.f64 = double(temp.f32);
	// std r11,308(r3)
	REX_STORE_U64(ctx.r3.u32 + 308, ctx.r11.u64);
	// lfs f0,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-76(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// stfs f13,-80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// ld r10,-80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// std r10,316(r3)
	REX_STORE_U64(ctx.r3.u32 + 316, ctx.r10.u64);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82394030) {
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
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x823940c0
	if (!ctx.cr6.eq) goto loc_823940C0;
	// lbz r11,253(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 253);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823940c0
	if (ctx.cr0.eq) goto loc_823940C0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8239406C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823940c0
	if (!ctx.cr0.eq) goto loc_823940C0;
	// addi r4,r31,264
	ctx.r4.s64 = ctx.r31.s64 + 264;
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// bl 0x8235fad0
	ctx.lr = 0x82394080;
	sub_8235FAD0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823940c0
	if (ctx.cr0.eq) goto loc_823940C0;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r9,262
	ctx.r9.s64 = 262;
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r10,r10,20580
	ctx.r10.s64 = ctx.r10.s64 + 20580;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r8,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// lwz r3,-12816(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// bl 0x825a2f98
	ctx.lr = 0x823940C0;
	sub_825A2F98(ctx, base);
loc_823940C0:
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

DEFINE_REX_FUNC(sub_82398950) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82398958;
	__savegprlr_26(ctx, base);
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x8273af24
	ctx.lr = 0x82398960;
	__savefpr_27(ctx, base);
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8273b36c
	ctx.lr = 0x82398968;
	__savevmx_123(ctx, base);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
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
	ctx.lr = 0x82398980;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823992e4
	if (ctx.cr0.eq) goto loc_823992E4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8239899C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823992e4
	if (ctx.cr0.eq) goto loc_823992E4;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r27,r11,12468
	ctx.r27.s64 = ctx.r11.s64 + 12468;
	// lwz r11,-12872(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -12872);
	// lfs f28,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823989cc
	if (ctx.cr6.eq) goto loc_823989CC;
	// lfs f13,744(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 744);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,748(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 748);
	ctx.f12.f64 = double(temp.f32);
	// b 0x823989d4
	goto loc_823989D4;
loc_823989CC:
	// fmr f12,f28
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f28.f64;
	// fmr f13,f28
	ctx.f13.f64 = ctx.f28.f64;
loc_823989D4:
	// lfs f30,-232(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -232);
	ctx.f30.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823989e8
	if (ctx.cr6.eq) goto loc_823989E8;
	// lfs f0,664(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f0.f64 = double(temp.f32);
	// b 0x823989ec
	goto loc_823989EC;
loc_823989E8:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f30.f64;
loc_823989EC:
	// fdivs f29,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82398a00
	if (ctx.cr6.eq) goto loc_82398A00;
	// lfs f0,664(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82398a04
	goto loc_82398A04;
loc_82398A00:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f30.f64;
loc_82398A04:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f30,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r9,236(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// stfs f30,108(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r29,r11,17984
	ctx.r29.s64 = ctx.r11.s64 + 17984;
	// stfs f29,140(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r7,4(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lwz r5,8(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// stfs f29,136(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r4,12(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// stfs f29,132(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r30,132(r9)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + 132);
	// stfs f29,128(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fdivs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// rlwinm r30,r30,0,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v125,0
	simde_mm_store_si128((simde__m128i*)ctx.v125.u32, simde_mm_set1_epi32(int(0x0)));
	// li r8,30924
	ctx.r8.s64 = 30924;
	// stw r30,132(r9)
	REX_STORE_U32(ctx.r9.u32 + 132, ctx.r30.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r11,236(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stw r10,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r10.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stw r7,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r7.u32);
	// fneg f31,f0
	ctx.f31.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stw r5,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r5.u32);
	// vupkd3d128 v61,v125,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v125.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v125.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v61 = vTemp;
	// stw r4,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r4.u32);
	// lfs f0,328(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 328);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,332(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 332);
	ctx.f13.f64 = double(temp.f32);
	// vor128 v62,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v125.u8));
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vor128 v60,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v125.u8));
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// vpermwi128 v123,v61,171
	simde_mm_store_si128((simde__m128i*)ctx.v123.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x54));
	// lvlx128 v124,r29,r8
	temp.u32 = ctx.r29.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v58,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v124.u8));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vor128 v59,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vrlimi128 v58,v62,7,0
	simde_mm_store_ps(ctx.v58.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v62.f32), 228), 7));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vrlimi128 v59,v124,4,3
	simde_mm_store_ps(ctx.v59.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v124.f32), 57), 4));
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vrlimi128 v60,v124,2,2
	simde_mm_store_ps(ctx.v60.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v124.f32), 78), 2));
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vor128 v57,v123,v123
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v123.u8));
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lvx128 v56,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v62,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v56.f32)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// fmr f3,f28
	ctx.f3.f64 = ctx.f28.f64;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v59,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8245c0c0
	ctx.lr = 0x82398B48;
	sub_8245C0C0(ctx, base);
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// vspltw128 v62,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xFF));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// vspltw128 v11,v58,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xAA));
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// vspltw128 v7,v58,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0x55));
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// vspltw128 v6,v58,3
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0x0));
	// vspltw128 v61,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v58,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0xFF));
	// vmulfp128 v10,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v62,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// lvx128 v12,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v8,v61,v63
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v9,v59,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xAA));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// vspltw128 v4,v57,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0x55));
	// vmulfp128 v5,v62,v63
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r30,r1,192
	ctx.r30.s64 = ctx.r1.s64 + 192;
	// vspltw128 v3,v57,3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0x0));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r5,64
	ctx.r5.s64 = 64;
	// lwz r3,236(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// vmaddfp v11,v11,v0,v10
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v10,v9,v0,v8
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vspltw128 v8,v57,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0xAA));
	// vspltw128 v9,v59,2
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x55));
	// vmaddfp v11,v7,v13,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmulfp128 v7,v58,v63
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v10,v9,v13,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vspltw128 v9,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v11,v6,v12,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v6,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// stvx128 v11,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v11,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vmaddfp v11,v11,v0,v5
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vspltw128 v5,v59,3
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x0));
	// vmaddfp v0,v8,v0,v7
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v10,v5,v12,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v11,v6,v13,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v0,v4,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v10,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v13,v9,v12,v11
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v0,v3,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v13,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273a030
	ctx.lr = 0x82398C18;
	sub_8273A030(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lwz r28,-15444(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + -15444);
	// lfs f27,3052(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3052);
	ctx.f27.f64 = double(temp.f32);
	// lbz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 268);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// beq 0x82398f08
	if (ctx.cr0.eq) goto loc_82398F08;
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r5,132(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// stfs f30,108(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// rlwinm r5,r5,0,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFE;
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vor128 v63,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v125.u8));
	// stw r5,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r5.u32);
	// vor128 v127,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v124.u8));
	// lwz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// addi r5,r11,80
	ctx.r5.s64 = ctx.r11.s64 + 80;
	// lwz r8,4(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// vor128 v126,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// lwz r6,8(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stw r10,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r10.u32);
	// addi r30,r1,176
	ctx.r30.s64 = ctx.r1.s64 + 176;
	// stw r8,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r8.u32);
	// vrlimi128 v127,v63,7,0
	simde_mm_store_ps(ctx.v127.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v63.f32), 228), 7));
	// stw r5,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r5.u32);
	// vrlimi128 v125,v124,2,2
	simde_mm_store_ps(ctx.v125.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v125.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v124.f32), 78), 2));
	// stw r6,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r6.u32);
	// vrlimi128 v126,v124,4,3
	simde_mm_store_ps(ctx.v126.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v124.f32), 57), 4));
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stvx128 v123,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f3,f28
	ctx.f3.f64 = ctx.f28.f64;
	// stvx128 v127,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// stvx128 v125,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,344(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f0.f64 = double(temp.f32);
	// fneg f2,f0
	ctx.f2.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// bl 0x8227b960
	ctx.lr = 0x82398CD4;
	sub_8227B960(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f31,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v59,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// lfs f0,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f0.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r6,32
	ctx.r6.s64 = 32;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r5,48
	ctx.r5.s64 = 48;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,336(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 336);
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
	// stfs f29,92(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f29,88(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f29,84(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f29,80(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v62,v59
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v59.f32)));
	// lfs f1,384(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 384);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v60,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r3,r7
	ea = (ctx.r3.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r3,r6
	ea = (ctx.r3.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r3,r5
	ea = (ctx.r3.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822ea1a8
	ctx.lr = 0x82398D78;
	sub_822EA1A8(ctx, base);
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// clrldi r11,r28,32
	ctx.r11.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfd f0,128(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f27.f64));
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f1,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// fneg f3,f0
	ctx.f3.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// bl 0x8245c0c0
	ctx.lr = 0x82398DA8;
	sub_8245C0C0(ctx, base);
	// vspltw128 v63,v127,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0xFF));
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// vspltw128 v62,v126,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xFF));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// vspltw128 v61,v125,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xFF));
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// vspltw128 v11,v127,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0xAA));
	// lwz r3,240(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// vmulfp128 v5,v63,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vspltw128 v59,v123,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0xFF));
	// vmulfp128 v3,v62,v60
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vspltw128 v4,v126,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xAA));
	// vmulfp128 v1,v61,v60
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vspltw128 v2,v125,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xAA));
	// vspltw128 v29,v127,2
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x55));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// vmulfp128 v30,v59,v60
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vspltw128 v31,v123,1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0xAA));
	// vspltw128 v28,v126,2
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x55));
	// vspltw128 v27,v125,2
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x55));
	// vspltw128 v7,v127,3
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x0));
	// vspltw128 v6,v123,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x55));
	// vspltw128 v8,v126,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x0));
	// vspltw128 v9,v125,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x0));
	// vspltw128 v10,v123,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x0));
	// vmaddfp v5,v11,v0,v5
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v4,v4,v0,v3
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v3,v2,v0,v1
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// vmaddfp v2,v31,v0,v30
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// vmaddfp v1,v29,v13,v5
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v4,v28,v13,v4
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v5,v27,v13,v3
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v13,v6,v13,v2
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v7,v7,v12,v1
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v8,v8,v12,v4
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v9,v9,v12,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v13,v10,v12,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vor128 v62,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// vor128 v61,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vor128 v60,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vspltw128 v59,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vspltw128 v28,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vmulfp128 v29,v59,v63
	simde_mm_store_ps(ctx.v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v59,v13,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0xFF));
	// vmulfp128 v31,v58,v63
	simde_mm_store_ps(ctx.v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw v3,v13,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0xAA));
	// vmulfp128 v2,v57,v63
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v30,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vspltw128 v1,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vmulfp128 v4,v59,v63
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v5,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vspltw v8,v13,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x55));
	// vspltw128 v6,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vspltw128 v7,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vspltw128 v9,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vspltw128 v10,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vspltw128 v12,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vspltw v13,v13,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x0));
	// vmaddfp v29,v28,v0,v29
	simde_mm_store_ps(ctx.v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v31,v30,v0,v31
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v2,v1,v0,v2
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v4,v3,v0,v4
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v5,v5,v11,v29
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v7,v7,v11,v2
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v6,v6,v11,v31
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// vmaddfp v8,v8,v11,v4
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// vmaddfp v9,v9,v0,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// li r5,64
	ctx.r5.s64 = 64;
	// vmaddfp v12,v12,v0,v7
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v11,v10,v0,v6
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v0,v13,v0,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// stvx128 v9,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273a030
	ctx.lr = 0x82398F04;
	sub_8273A030(ctx, base);
	// b 0x82398f14
	goto loc_82398F14;
loc_82398F08:
	// lwz r10,132(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r10.u32);
loc_82398F14:
	// lbz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 316);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// beq 0x8239901c
	if (ctx.cr0.eq) goto loc_8239901C;
	// lwz r6,132(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// stfs f30,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// rlwinm r6,r6,0,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFE;
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f29,104(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r6,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r6.u32);
	// lfs f0,312(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r26,12(r10)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// stfs f29,96(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r30,8(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r10,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r10.u32);
	// stfs f29,108(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r30,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r30.u32);
	// stfs f29,100(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stw r26,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r26.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stw r6,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r6.u32);
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r10,r11,80
	ctx.r10.s64 = ctx.r11.s64 + 80;
	// fmr f3,f28
	ctx.f3.f64 = ctx.f28.f64;
	// lfs f13,356(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,360(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 360);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
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
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8245c0c0
	ctx.lr = 0x82399008;
	sub_8245C0C0(ctx, base);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lwz r3,244(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x8273a030
	ctx.lr = 0x82399018;
	sub_8273A030(ctx, base);
	// b 0x82399028
	goto loc_82399028;
loc_8239901C:
	// lwz r10,132(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r10.u32);
loc_82399028:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823992e4
	if (ctx.cr6.eq) goto loc_823992E4;
	// lbz r10,288(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 288);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82399048
	if (ctx.cr0.eq) goto loc_82399048;
	// lhz r30,252(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 252);
	// b 0x8239904c
	goto loc_8239904C;
loc_82399048:
	// lhz r30,254(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 254);
loc_8239904C:
	// lbz r10,268(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 268);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82399160
	if (ctx.cr0.eq) goto loc_82399160;
	// lfs f0,17288(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 17288);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// stfs f0,40(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// lfs f1,384(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 384);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822ea1a8
	ctx.lr = 0x8239906C;
	sub_822EA1A8(ctx, base);
	// clrldi r11,r28,32
	ctx.r11.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r7,1
	ctx.r7.s64 = 1;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfd f13,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lfs f0,11148(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11148);
	ctx.f0.f64 = double(temp.f32);
	// li r6,6
	ctx.r6.s64 = 6;
	// addi r29,r1,80
	ctx.r29.s64 = ctx.r1.s64 + 80;
	// addi r26,r1,80
	ctx.r26.s64 = ctx.r1.s64 + 80;
	// addi r28,r1,112
	ctx.r28.s64 = ctx.r1.s64 + 112;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// fmuls f13,f13,f27
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f27.f64));
	// fmuls f13,f1,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f13,36(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// lfs f13,344(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f28,56(r11)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r11.u32 + 56, temp.u32);
	// stfs f13,52(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 52, temp.u32);
	// stfs f28,48(r11)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r11.u32 + 48, temp.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stb r7,141(r11)
	REX_STORE_U8(ctx.r11.u32 + 141, ctx.r7.u8);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stw r6,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r6.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,96(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lfs f0,336(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 336);
	ctx.f0.f64 = double(temp.f32);
	// lbz r7,260(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 260);
	// lfs f12,264(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 264);
	ctx.f12.f64 = double(temp.f32);
	// lwz r3,248(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lfs f13,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// stvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r6,132(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x823be020
	ctx.lr = 0x8239914C;
	sub_823BE020(ctx, base);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f0,-232(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// stfs f0,44(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// b 0x823992e4
	goto loc_823992E4;
loc_82399160:
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x8239924c
	if (!ctx.cr6.eq) goto loc_8239924C;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,348(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1536(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1536);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8239924c
	if (ctx.cr6.gt) goto loc_8239924C;
	// lwz r7,280(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// li r11,255
	ctx.r11.s64 = 255;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r11.u8);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stb r11,129(r1)
	REX_STORE_U8(ctx.r1.u32 + 129, ctx.r11.u8);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stb r11,130(r1)
	REX_STORE_U8(ctx.r1.u32 + 130, ctx.r11.u8);
	// addi r29,r1,80
	ctx.r29.s64 = ctx.r1.s64 + 80;
	// lis r5,-32226
	ctx.r5.s64 = -2111963136;
	// stw r7,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r7.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lfs f13,-9856(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -9856);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f12,284(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 284);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lwz r3,248(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f12,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f12.f64 = double(temp.f32);
	// lbz r7,260(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 260);
	// lfs f11,264(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 264);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f12,348(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f0,f12,f0,f30
	ctx.f0.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f30.f64)));
	// lfs f12,336(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 336);
	ctx.f12.f64 = double(temp.f32);
	// fctiwz f12,f12
	ctx.f12.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f12,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fctidz f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lbz r11,103(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,131(r1)
	REX_STORE_U8(ctx.r1.u32 + 131, ctx.r11.u8);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823be020
	ctx.lr = 0x8239924C;
	sub_823BE020(ctx, base);
loc_8239924C:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r29,r1,80
	ctx.r29.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stw r9,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r9.u32);
	// lfs f0,31640(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 31640);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,96(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lfs f0,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,248(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lfs f13,264(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 264);
	ctx.f13.f64 = double(temp.f32);
	// lbz r7,260(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 260);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,336(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 336);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823be020
	ctx.lr = 0x823992E4;
	sub_823BE020(ctx, base);
loc_823992E4:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8273b604
	ctx.lr = 0x823992F0;
	__restvmx_123(ctx, base);
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x8273af70
	ctx.lr = 0x823992F8;
	__restfpr_27(ctx, base);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82404C50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,8(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82404ca0
	if (!ctx.cr6.eq) goto loc_82404CA0;
	// lfs f0,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// beq cr6,0x82404c88
	if (ctx.cr6.eq) goto loc_82404C88;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x82404c80
	if (ctx.cr6.lt) goto loc_82404C80;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82404C80:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
loc_82404C88:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82404ca0
	if (!ctx.cr6.eq) goto loc_82404CA0;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
loc_82404CA0:
	// subfc r11,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82407E40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82407E48;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r30,156(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r11,r11,-31332
	ctx.r11.s64 = ctx.r11.s64 + -31332;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82407ec0
	if (ctx.cr6.eq) goto loc_82407EC0;
	// lwz r3,32(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82407e80
	if (ctx.cr6.eq) goto loc_82407E80;
	// bl 0x823c74f0
	ctx.lr = 0x82407E80;
	sub_823C74F0(ctx, base);
loc_82407E80:
	// addi r31,r30,-4
	ctx.r31.s64 = ctx.r30.s64 + -4;
	// stw r27,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r27.u32);
	// li r29,4
	ctx.r29.s64 = 4;
	// lis r26,-32112
	ctx.r26.s64 = -2104492032;
loc_82407E90:
	// lwz r11,-13064(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -13064);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82407eac
	if (ctx.cr6.eq) goto loc_82407EAC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82407eac
	if (ctx.cr6.eq) goto loc_82407EAC;
	// bl 0x8235d960
	ctx.lr = 0x82407EAC;
	sub_8235D960(ctx, base);
loc_82407EAC:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stwu r27,4(r31)
	ea = 4 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r27.u32);
	ctx.r31.u32 = ea;
	// bne 0x82407e90
	if (!ctx.cr0.eq) goto loc_82407E90;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825e0378
	ctx.lr = 0x82407EC0;
	sub_825E0378(ctx, base);
loc_82407EC0:
	// stw r27,156(r28)
	REX_STORE_U32(ctx.r28.u32 + 156, ctx.r27.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x823c4360
	ctx.lr = 0x82407ECC;
	sub_823C4360(ctx, base);
	// clrlwi. r11,r25,31
	ctx.r11.u64 = ctx.r25.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82407edc
	if (ctx.cr0.eq) goto loc_82407EDC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825e0378
	ctx.lr = 0x82407EDC;
	sub_825E0378(ctx, base);
loc_82407EDC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240CD30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8240CD38;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r28,156(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r11,r11,-31180
	ctx.r11.s64 = ctx.r11.s64 + -31180;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x8240cdc0
	if (ctx.cr6.eq) goto loc_8240CDC0;
	// addi r31,r28,32
	ctx.r31.s64 = ctx.r28.s64 + 32;
	// li r30,2
	ctx.r30.s64 = 2;
loc_8240CD64:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240cd78
	if (ctx.cr6.eq) goto loc_8240CD78;
	// bl 0x8221cc98
	ctx.lr = 0x8240CD74;
	sub_8221CC98(ctx, base);
	// stw r27,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
loc_8240CD78:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x8240cd64
	if (!ctx.cr0.eq) goto loc_8240CD64;
	// addi r31,r28,-4
	ctx.r31.s64 = ctx.r28.s64 + -4;
	// li r30,3
	ctx.r30.s64 = 3;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
loc_8240CD90:
	// lwz r11,-13064(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -13064);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240cdac
	if (ctx.cr6.eq) goto loc_8240CDAC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240cdac
	if (ctx.cr6.eq) goto loc_8240CDAC;
	// bl 0x8235d960
	ctx.lr = 0x8240CDAC;
	sub_8235D960(ctx, base);
loc_8240CDAC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r27,4(r31)
	ea = 4 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r27.u32);
	ctx.r31.u32 = ea;
	// bne 0x8240cd90
	if (!ctx.cr0.eq) goto loc_8240CD90;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825e0378
	ctx.lr = 0x8240CDC0;
	sub_825E0378(ctx, base);
loc_8240CDC0:
	// stw r27,156(r26)
	REX_STORE_U32(ctx.r26.u32 + 156, ctx.r27.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x823c4360
	ctx.lr = 0x8240CDCC;
	sub_823C4360(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82412908) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82412910;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,168(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 168);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82412998
	if (!ctx.cr0.eq) goto loc_82412998;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r31,r3,176
	ctx.r31.s64 = ctx.r3.s64 + 176;
	// addi r30,r10,22072
	ctx.r30.s64 = ctx.r10.s64 + 22072;
	// addi r29,r11,31288
	ctx.r29.s64 = ctx.r11.s64 + 31288;
loc_8241293C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8241297c
	if (!ctx.cr6.eq) goto loc_8241297C;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r4,188
	ctx.r4.s64 = 188;
	// bl 0x825e02a0
	ctx.lr = 0x82412958;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8241296c
	if (ctx.cr0.eq) goto loc_8241296C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x823bdc58
	ctx.lr = 0x82412968;
	sub_823BDC58(ctx, base);
	// b 0x82412970
	goto loc_82412970;
loc_8241296C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82412970:
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824129a4
	if (ctx.cr6.eq) goto loc_824129A4;
loc_8241297C:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// blt cr6,0x8241293c
	if (ctx.cr6.lt) goto loc_8241293C;
	// lwz r11,168(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 168);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stw r11,168(r27)
	REX_STORE_U32(ctx.r27.u32 + 168, ctx.r11.u32);
loc_82412998:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8241299C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_824129A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8241299c
	goto loc_8241299C;
}

DEFINE_REX_FUNC(sub_82418080) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x82418288
	sub_82418288(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82418088) {
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
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x823c8488
	ctx.lr = 0x824180AC;
	sub_823C8488(ctx, base);
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,52(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x824180d4
	if (!ctx.cr6.eq) goto loc_824180D4;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lfs f13,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,15656(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15656);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x824180f8
	if (!ctx.cr6.lt) goto loc_824180F8;
loc_824180D4:
	// lwz r11,64(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r9,52(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x82418100
	if (!ctx.cr6.eq) goto loc_82418100;
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
	// bgt cr6,0x82418100
	if (ctx.cr6.gt) goto loc_82418100;
loc_824180F8:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82418104
	goto loc_82418104;
loc_82418100:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82418104:
	// lbz r9,152(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x82418128
	if (ctx.cr0.eq) goto loc_82418128;
	// lbz r9,153(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 153);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x82418128
	if (!ctx.cr0.eq) goto loc_82418128;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x8241812c
	if (!ctx.cr0.eq) goto loc_8241812C;
loc_82418128:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8241812C:
	// lwz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// stb r11,61(r31)
	REX_STORE_U8(ctx.r31.u32 + 61, ctx.r11.u8);
	// lbz r11,152(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stb r11,60(r31)
	REX_STORE_U8(ctx.r31.u32 + 60, ctx.r11.u8);
	// beq cr6,0x8241814c
	if (ctx.cr6.eq) goto loc_8241814C;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c9570
	ctx.lr = 0x8241814C;
	sub_823C9570(ctx, base);
loc_8241814C:
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

DEFINE_REX_FUNC(sub_82421BA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82421BB0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,528(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 528);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82421db0
	if (ctx.cr6.lt) goto loc_82421DB0;
	// bne cr6,0x82422400
	if (!ctx.cr6.eq) goto loc_82422400;
	// lwz r3,532(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 532);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82421bfc
	if (!ctx.cr6.eq) goto loc_82421BFC;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,404(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x824257e8
	ctx.lr = 0x82421BF8;
	sub_824257E8(ctx, base);
	// b 0x82422400
	goto loc_82422400;
loc_82421BFC:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// bl 0x823cb178
	ctx.lr = 0x82421C0C;
	sub_823CB178(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82422400
	if (ctx.cr0.eq) goto loc_82422400;
	// lwz r3,532(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82421c24
	if (ctx.cr6.eq) goto loc_82421C24;
	// bl 0x823d3de0
	ctx.lr = 0x82421C24;
	sub_823D3DE0(ctx, base);
loc_82421C24:
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r29,532(r31)
	REX_STORE_U32(ctx.r31.u32 + 532, ctx.r29.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82421c3c
	if (!ctx.cr6.eq) goto loc_82421C3C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82421d98
	goto loc_82421D98;
loc_82421C3C:
	// cmplwi cr6,r30,9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 9, ctx.xer);
	// bgt cr6,0x82421d94
	if (ctx.cr6.gt) goto loc_82421D94;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r10,404(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// lwz r3,444(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 444);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r11,r10
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82440d00
	ctx.lr = 0x82421C70;
	sub_82440D00(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x823b56a0
	ctx.lr = 0x82421C78;
	sub_823B56A0(ctx, base);
	// rlwinm r28,r3,30,2,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// bl 0x82213210
	ctx.lr = 0x82421C80;
	sub_82213210(ctx, base);
	// lwz r11,13452(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 13452);
	// stw r11,536(r31)
	REX_STORE_U32(ctx.r31.u32 + 536, ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x82421C8C;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// lis r10,1525
	ctx.r10.s64 = 99942400;
	// mullw r9,r28,r30
	ctx.r9.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r30.s32);
	// lwz r8,9332(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 9332);
	// ori r10,r10,57599
	ctx.r10.u64 = ctx.r10.u64 | 57599;
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82421cb4
	if (!ctx.cr6.gt) goto loc_82421CB4;
	// stw r10,9332(r11)
	REX_STORE_U32(ctx.r11.u32 + 9332, ctx.r10.u32);
	// b 0x82421cd4
	goto loc_82421CD4;
loc_82421CB4:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x82421cd0
	if (!ctx.cr6.lt) goto loc_82421CD0;
	// neg r10,r9
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r9.u64);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82421cd0
	if (!ctx.cr6.lt) goto loc_82421CD0;
	// stw r29,9332(r11)
	REX_STORE_U32(ctx.r11.u32 + 9332, ctx.r29.u32);
	// b 0x82421cd4
	goto loc_82421CD4;
loc_82421CD0:
	// stw r7,9332(r11)
	REX_STORE_U32(ctx.r11.u32 + 9332, ctx.r7.u32);
loc_82421CD4:
	// lis r10,15
	ctx.r10.s64 = 983040;
	// lwz r11,9332(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 9332);
	// ori r10,r10,16960
	ctx.r10.u64 = ctx.r10.u64 | 16960;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82421cf0
	if (ctx.cr6.lt) goto loc_82421CF0;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x82217158
	ctx.lr = 0x82421CF0;
	sub_82217158(ctx, base);
loc_82421CF0:
	// li r30,1
	ctx.r30.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r30,540(r31)
	REX_STORE_U8(ctx.r31.u32 + 540, ctx.r30.u8);
	// bl 0x824246d0
	ctx.lr = 0x82421D00;
	sub_824246D0(ctx, base);
	// lwz r10,356(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// addi r10,r10,90
	ctx.r10.s64 = ctx.r10.s64 + 90;
	// addi r9,r11,3
	ctx.r9.s64 = ctx.r11.s64 + 3;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x82421d34
	if (ctx.cr6.gt) goto loc_82421D34;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82421d34
	if (!ctx.cr6.gt) goto loc_82421D34;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82424240
	ctx.lr = 0x82421D34;
	sub_82424240(ctx, base);
loc_82421D34:
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82421d64
	if (!ctx.cr6.gt) goto loc_82421D64;
	// lwz r9,392(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x82421d64
	if (ctx.cr6.lt) goto loc_82421D64;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
loc_82421D64:
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,396(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// bl 0x82423e50
	ctx.lr = 0x82421D80;
	sub_82423E50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82423730
	ctx.lr = 0x82421D88;
	sub_82423730(ctx, base);
	// lwz r11,432(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// stb r30,22(r11)
	REX_STORE_U8(ctx.r11.u32 + 22, ctx.r30.u8);
	// b 0x82421d9c
	goto loc_82421D9C;
loc_82421D94:
	// li r3,3
	ctx.r3.s64 = 3;
loc_82421D98:
	// bl 0x823c7bd8
	ctx.lr = 0x82421D9C;
	sub_823C7BD8(ctx, base);
loc_82421D9C:
	// stw r29,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r29.u32);
	// lwz r11,340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x823c82a8
	ctx.lr = 0x82421DAC;
	sub_823C82A8(ctx, base);
	// b 0x82422400
	goto loc_82422400;
loc_82421DB0:
	// lwz r11,548(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 548);
	// lbz r11,153(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 153);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82422400
	if (!ctx.cr0.eq) goto loc_82422400;
	// lbz r11,448(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 448);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82421dd8
	if (ctx.cr0.eq) goto loc_82421DD8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82425338
	ctx.lr = 0x82421DD4;
	sub_82425338(ctx, base);
	// b 0x82422400
	goto loc_82422400;
loc_82421DD8:
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// lwz r28,396(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// addi r10,r11,90
	ctx.r10.s64 = ctx.r11.s64 + 90;
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r11,r31
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// bl 0x82213210
	ctx.lr = 0x82421DF4;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,13
	ctx.r3.s64 = 13;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x82421E04;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82421e3c
	if (ctx.cr0.eq) goto loc_82421E3C;
	// lbz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 440);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82421e20
	if (!ctx.cr0.eq) goto loc_82421E20;
	// li r3,3
	ctx.r3.s64 = 3;
	// b 0x824223fc
	goto loc_824223FC;
loc_82421E20:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r3,340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// lfs f1,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823c83b8
	ctx.lr = 0x82421E30;
	sub_823C83B8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r11.u32);
	// b 0x82421ed4
	goto loc_82421ED4;
loc_82421E3C:
	// bl 0x82213210
	ctx.lr = 0x82421E40;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x82421E50;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82421e98
	if (ctx.cr0.eq) goto loc_82421E98;
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r11,432(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// li r10,59
	ctx.r10.s64 = 59;
	// lwz r9,356(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stw r9,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// lwz r11,548(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 548);
	// stb r30,153(r11)
	REX_STORE_U8(ctx.r11.u32 + 153, ctx.r30.u8);
	// lwz r11,548(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 548);
	// std r10,136(r11)
	REX_STORE_U64(ctx.r11.u32 + 136, ctx.r10.u64);
	// bl 0x823c7bd8
	ctx.lr = 0x82421E90;
	sub_823C7BD8(ctx, base);
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x82421ed8
	goto loc_82421ED8;
loc_82421E98:
	// bl 0x82213210
	ctx.lr = 0x82421E9C;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,15
	ctx.r3.s64 = 15;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x82421EAC;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82421ee0
	if (ctx.cr0.eq) goto loc_82421EE0;
	// lbz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 440);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82422400
	if (ctx.cr0.eq) goto loc_82422400;
	// lbz r11,449(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 449);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824223d0
	if (ctx.cr0.eq) goto loc_824223D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82425170
	ctx.lr = 0x82421ED4;
	sub_82425170(ctx, base);
loc_82421ED4:
	// li r3,4
	ctx.r3.s64 = 4;
loc_82421ED8:
	// bl 0x823c7bd8
	ctx.lr = 0x82421EDC;
	sub_823C7BD8(ctx, base);
	// b 0x824223d0
	goto loc_824223D0;
loc_82421EE0:
	// bl 0x82213210
	ctx.lr = 0x82421EE4;
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
	ctx.lr = 0x82421EF8;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82421f0c
	if (!ctx.cr0.eq) goto loc_82421F0C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d5f8
	ctx.lr = 0x82421F0C;
	sub_8242D5F8(ctx, base);
loc_82421F0C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82422038
	if (ctx.cr0.eq) goto loc_82422038;
	// bl 0x82213210
	ctx.lr = 0x82421F18;
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
	ctx.lr = 0x82421F2C;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82421f40
	if (!ctx.cr0.eq) goto loc_82421F40;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d6e8
	ctx.lr = 0x82421F40;
	sub_8242D6E8(ctx, base);
loc_82421F40:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824223d0
	if (ctx.cr0.eq) goto loc_824223D0;
	// lbz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 440);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82422400
	if (ctx.cr0.eq) goto loc_82422400;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82421fd4
	if (!ctx.cr6.eq) goto loc_82421FD4;
	// bl 0x82213210
	ctx.lr = 0x82421F70;
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
	ctx.lr = 0x82421F84;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82421f98
	if (!ctx.cr0.eq) goto loc_82421F98;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d670
	ctx.lr = 0x82421F98;
	sub_8242D670(ctx, base);
loc_82421F98:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824223d0
	if (ctx.cr0.eq) goto loc_824223D0;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r10,r11,90
	ctx.r10.s64 = ctx.r11.s64 + 90;
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwx r11,r10,r31
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r11.u32);
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// cmpwi cr6,r11,12
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 12, ctx.xer);
	// ble cr6,0x824223b4
	if (!ctx.cr6.gt) goto loc_824223B4;
	// addi r4,r11,-12
	ctx.r4.s64 = ctx.r11.s64 + -12;
loc_82421FC8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82424240
	ctx.lr = 0x82421FD0;
	sub_82424240(ctx, base);
	// b 0x824223b4
	goto loc_824223B4;
loc_82421FD4:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// addi r9,r11,3
	ctx.r9.s64 = ctx.r11.s64 + 3;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x82421ff8
	if (ctx.cr6.gt) goto loc_82421FF8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82421ff8
	if (!ctx.cr6.gt) goto loc_82421FF8;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82424240
	ctx.lr = 0x82421FF8;
	sub_82424240(ctx, base);
loc_82421FF8:
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82422018:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824223b4
	if (ctx.cr6.eq) goto loc_824223B4;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,12472
	ctx.r10.s64 = ctx.r10.s64 + 12472;
	// lfs f0,1904(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1904);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// b 0x824223b4
	goto loc_824223B4;
loc_82422038:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7df8
	ctx.lr = 0x82422040;
	sub_823C7DF8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82422104
	if (ctx.cr0.eq) goto loc_82422104;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7e90
	ctx.lr = 0x82422050;
	sub_823C7E90(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824223d0
	if (ctx.cr0.eq) goto loc_824223D0;
	// lbz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 440);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82422400
	if (ctx.cr0.eq) goto loc_82422400;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// lwz r9,392(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x824220b0
	if (!ctx.cr6.eq) goto loc_824220B0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7d60
	ctx.lr = 0x8242208C;
	sub_823C7D60(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824223d0
	if (ctx.cr0.eq) goto loc_824223D0;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
	// b 0x82421fc8
	goto loc_82421FC8;
loc_824220B0:
	// lwz r10,396(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// addi r8,r10,8
	ctx.r8.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x824220e0
	if (ctx.cr6.lt) goto loc_824220E0;
	// cmpwi cr6,r9,12
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 12, ctx.xer);
	// ble cr6,0x824220e0
	if (!ctx.cr6.gt) goto loc_824220E0;
	// addi r11,r9,-12
	ctx.r11.s64 = ctx.r9.s64 + -12;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x824220e0
	if (!ctx.cr6.lt) goto loc_824220E0;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82424240
	ctx.lr = 0x824220E0;
	sub_82424240(ctx, base);
loc_824220E0:
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82422018
	goto loc_82422018;
loc_82422104:
	// bl 0x82213210
	ctx.lr = 0x82422108;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,9
	ctx.r3.s64 = 9;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d5f8
	ctx.lr = 0x82422118;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824221f4
	if (ctx.cr0.eq) goto loc_824221F4;
	// bl 0x82213210
	ctx.lr = 0x82422124;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,9
	ctx.r3.s64 = 9;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d6e8
	ctx.lr = 0x82422134;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824223d0
	if (ctx.cr0.eq) goto loc_824223D0;
	// lbz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 440);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82422400
	if (ctx.cr0.eq) goto loc_82422400;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,-11
	ctx.r10.s64 = ctx.r10.s64 + -11;
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x82422180
	if (!ctx.cr6.lt) goto loc_82422180;
	// stwx r29,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r29.u32);
loc_82422180:
	// lwz r10,396(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// xoris r9,r29,32768
	ctx.r9.u64 = ctx.r29.u64 ^ 2147483648;
	// addi r10,r10,-11
	ctx.r10.s64 = ctx.r10.s64 + -11;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	// bl 0x82424240
	ctx.lr = 0x824221A8;
	sub_82424240(ctx, base);
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_824221B0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824221cc
	if (ctx.cr6.eq) goto loc_824221CC;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,12472
	ctx.r10.s64 = ctx.r10.s64 + 12472;
	// lfs f0,1904(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1904);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
loc_824221CC:
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmpw cr6,r4,r27
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r27.s32, ctx.xer);
	// bne cr6,0x824223c4
	if (!ctx.cr6.eq) goto loc_824223C4;
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x824223d0
	if (ctx.cr6.eq) goto loc_824223D0;
	// b 0x824223c4
	goto loc_824223C4;
loc_824221F4:
	// bl 0x82213210
	ctx.lr = 0x824221F8;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,10
	ctx.r3.s64 = 10;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d5f8
	ctx.lr = 0x82422208;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824222c0
	if (ctx.cr0.eq) goto loc_824222C0;
	// bl 0x82213210
	ctx.lr = 0x82422214;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,10
	ctx.r3.s64 = 10;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d6e8
	ctx.lr = 0x82422224;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824223d0
	if (ctx.cr0.eq) goto loc_824223D0;
	// lbz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 440);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82422400
	if (ctx.cr0.eq) goto loc_82422400;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,11
	ctx.r10.s64 = ctx.r10.s64 + 11;
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r10,r11,90
	ctx.r10.s64 = ctx.r11.s64 + 90;
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x82422274
	if (!ctx.cr6.gt) goto loc_82422274;
	// stwx r11,r10,r31
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r11.u32);
loc_82422274:
	// lwz r10,392(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r9,396(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// addi r10,r10,-12
	ctx.r10.s64 = ctx.r10.s64 + -12;
	// xoris r8,r11,32768
	ctx.r8.u64 = ctx.r11.u64 ^ 2147483648;
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r11,r9,11
	ctx.r11.s64 = ctx.r9.s64 + 11;
	// addc r9,r7,r8
	ctx.xer.ca = ctx.r7.u32 + ctx.r8.u32 < ctx.r7.u32;
	ctx.r9.u64 = ctx.r7.u64 + ctx.r8.u64;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x824222a8
	if (ctx.cr6.lt) goto loc_824222A8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_824222A8:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82424240
	ctx.lr = 0x824222B4;
	sub_82424240(ctx, base);
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x824221b0
	goto loc_824221B0;
loc_824222C0:
	// bl 0x82213210
	ctx.lr = 0x824222C4;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,7
	ctx.r3.s64 = 7;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d5f8
	ctx.lr = 0x824222D4;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82422338
	if (ctx.cr0.eq) goto loc_82422338;
	// bl 0x82213210
	ctx.lr = 0x824222E0;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,7
	ctx.r3.s64 = 7;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d6e8
	ctx.lr = 0x824222F0;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824223d0
	if (ctx.cr0.eq) goto loc_824223D0;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
	// bge 0x82422310
	if (!ctx.cr0.lt) goto loc_82422310;
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
loc_82422310:
	// lwz r11,432(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// lbz r11,21(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824223ac
	if (!ctx.cr0.eq) goto loc_824223AC;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x824223ac
	if (!ctx.cr6.eq) goto loc_824223AC;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
	// b 0x824223ac
	goto loc_824223AC;
loc_82422338:
	// bl 0x82213210
	ctx.lr = 0x8242233C;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d5f8
	ctx.lr = 0x8242234C;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824223d0
	if (ctx.cr0.eq) goto loc_824223D0;
	// bl 0x82213210
	ctx.lr = 0x82422358;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d6e8
	ctx.lr = 0x82422368;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824223d0
	if (ctx.cr0.eq) goto loc_824223D0;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// ble cr6,0x8242238c
	if (!ctx.cr6.gt) goto loc_8242238C;
	// stw r29,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r29.u32);
loc_8242238C:
	// lwz r11,432(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// lbz r11,21(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824223ac
	if (!ctx.cr0.eq) goto loc_824223AC;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x824223ac
	if (!ctx.cr6.eq) goto loc_824223AC;
	// stw r29,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r29.u32);
loc_824223AC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824246d0
	ctx.lr = 0x824223B4;
	sub_824246D0(ctx, base);
loc_824223B4:
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
loc_824223C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,396(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// bl 0x82423e50
	ctx.lr = 0x824223D0;
	sub_82423E50(ctx, base);
loc_824223D0:
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// cmpw cr6,r11,r26
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r26.s32, ctx.xer);
	// bne cr6,0x824223f0
	if (!ctx.cr6.eq) goto loc_824223F0;
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x82422400
	if (ctx.cr6.eq) goto loc_82422400;
loc_824223F0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82423730
	ctx.lr = 0x824223F8;
	sub_82423730(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_824223FC:
	// bl 0x823c7bd8
	ctx.lr = 0x82422400;
	sub_823C7BD8(ctx, base);
loc_82422400:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82462810) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x82462818;
	__savegprlr_21(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// li r24,0
	ctx.r24.s64 = 0;
	// cmpwi cr6,r6,-1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, -1, ctx.xer);
	// bne cr6,0x82462850
	if (!ctx.cr6.eq) goto loc_82462850;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82443da0
	ctx.lr = 0x8246284C;
	sub_82443DA0(ctx, base);
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
loc_82462850:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82462870
	if (ctx.cr6.eq) goto loc_82462870;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x82444000
	ctx.lr = 0x82462868;
	sub_82444000(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// b 0x82462874
	goto loc_82462874;
loc_82462870:
	// mr r25,r24
	ctx.r25.u64 = ctx.r24.u64;
loc_82462874:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12964(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12964);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824628b8
	if (ctx.cr6.eq) goto loc_824628B8;
	// lwz r10,824(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 824);
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// bge cr6,0x824628b8
	if (!ctx.cr6.lt) goto loc_824628B8;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stb r29,100(r10)
	REX_STORE_U8(ctx.r10.u32 + 100, ctx.r29.u8);
	// lwz r10,824(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 824);
	// addi r10,r10,13
	ctx.r10.s64 = ctx.r10.s64 + 13;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r25,r10,r11
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r25.u32);
	// lwz r10,824(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 824);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,824(r11)
	REX_STORE_U32(ctx.r11.u32 + 824, ctx.r10.u32);
loc_824628B8:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x824443c8
	ctx.lr = 0x824628C0;
	sub_824443C8(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r21,r11,22072
	ctx.r21.s64 = ctx.r11.s64 + 22072;
	// li r4,24
	ctx.r4.s64 = 24;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r21)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824628DC;
	sub_825E02A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stb r29,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r29.u8);
	// bl 0x8242a6c0
	ctx.lr = 0x824628F0;
	sub_8242A6C0(ctx, base);
	// stw r3,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r24,16(r30)
	REX_STORE_U8(ctx.r30.u32 + 16, ctx.r24.u8);
	// li r4,97
	ctx.r4.s64 = 97;
	// stb r24,17(r30)
	REX_STORE_U8(ctx.r30.u32 + 17, ctx.r24.u8);
	// lwz r3,44(r21)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82462910;
	sub_825E02A0(ctx, base);
	// stw r3,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r3.u32);
	// stw r26,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r26.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r28,2352(r31)
	REX_STORE_U32(ctx.r31.u32 + 2352, ctx.r28.u32);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82462934;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// clrlwi r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	// clrlwi r29,r27,16
	ctx.r29.u64 = ctx.r27.u32 & 0xFFFF;
	// stw r11,2360(r31)
	REX_STORE_U32(ctx.r31.u32 + 2360, ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8246296c
	if (ctx.cr6.eq) goto loc_8246296C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 576);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246295C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r3,-16
	ctx.r11.s64 = ctx.r3.s64 + -16;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 & ctx.r29.u64;
loc_8246296C:
	// sth r29,88(r31)
	REX_STORE_U16(ctx.r31.u32 + 88, ctx.r29.u16);
	// cmplwi cr6,r28,1
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1, ctx.xer);
	// stw r23,2328(r31)
	REX_STORE_U32(ctx.r31.u32 + 2328, ctx.r23.u32);
	// bne cr6,0x824629cc
	if (!ctx.cr6.eq) goto loc_824629CC;
	// bl 0x82213210
	ctx.lr = 0x82462980;
	sub_82213210(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,254
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 254, ctx.xer);
	// bne cr6,0x82462994
	if (!ctx.cr6.eq) goto loc_82462994;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// b 0x8246299c
	goto loc_8246299C;
loc_82462994:
	// bl 0x82213210
	ctx.lr = 0x82462998;
	sub_82213210(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
loc_8246299C:
	// lwz r10,2352(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 2352);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x824629ac
	if (!ctx.cr6.eq) goto loc_824629AC;
	// stw r11,2356(r31)
	REX_STORE_U32(ctx.r31.u32 + 2356, ctx.r11.u32);
loc_824629AC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,20(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82449908
	ctx.lr = 0x824629BC;
	sub_82449908(ctx, base);
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// rlwinm r11,r11,9,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 9) & 0xFF;
	// stw r11,120(r22)
	REX_STORE_U32(ctx.r22.u32 + 120, ctx.r11.u32);
loc_824629CC:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// li r9,1
	ctx.r9.s64 = 1;
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// lfs f0,12236(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,2380(r31)
	REX_STORE_U32(ctx.r31.u32 + 2380, ctx.r9.u32);
	// stfs f0,2396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2396, temp.u32);
	// std r11,2388(r31)
	REX_STORE_U64(ctx.r31.u32 + 2388, ctx.r11.u64);
	// lwz r3,40(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 40);
	// lbz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82462a00
	if (ctx.cr0.eq) goto loc_82462A00;
	// bl 0x82855b44
	ctx.lr = 0x82462A00;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_82462A00:
	// lwz r11,48(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 48);
	// addi r3,r22,44
	ctx.r3.s64 = ctx.r22.s64 + 44;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82462a18
	if (!ctx.cr6.eq) goto loc_82462A18;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// b 0x82462a24
	goto loc_82462A24;
loc_82462A18:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_82462A24:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82462a48
	if (!ctx.cr6.lt) goto loc_82462A48;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r30,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r30.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x82462a50
	goto loc_82462A50;
loc_82462A48:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823849b0
	ctx.lr = 0x82462A50;
	sub_823849B0(ctx, base);
loc_82462A50:
	// lwz r3,40(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 40);
	// lbz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82462a64
	if (ctx.cr0.eq) goto loc_82462A64;
	// bl 0x82855b34
	ctx.lr = 0x82462A64;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82462A64:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r3,-13068(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -13068);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82462a80
	if (ctx.cr6.eq) goto loc_82462A80;
	// stw r25,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82396cc8
	ctx.lr = 0x82462A80;
	sub_82396CC8(ctx, base);
loc_82462A80:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82474618) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82474620;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,328
	ctx.r4.s64 = 328;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// bl 0x825e02a0
	ctx.lr = 0x8247464C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82474678
	if (ctx.cr0.eq) goto loc_82474678;
	// addic r11,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// li r10,2
	ctx.r10.s64 = 2;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// and r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 & ctx.r10.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82481ae8
	ctx.lr = 0x82474670;
	sub_82481AE8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x8247467c
	goto loc_8247467C;
loc_82474678:
	// li r29,0
	ctx.r29.s64 = 0;
loc_8247467C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8247468c
	if (!ctx.cr6.eq) goto loc_8247468C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824747c8
	goto loc_824747C8;
loc_8247468C:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,4436
	ctx.r9.s64 = ctx.r11.s64 + 4436;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r30,r10,12472
	ctx.r30.s64 = ctx.r10.s64 + 12472;
	// lfs f0,7512(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7512);
	ctx.f0.f64 = double(temp.f32);
	// beq cr6,0x82474748
	if (ctx.cr6.eq) goto loc_82474748;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r31,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x82474748
	if (!ctx.cr6.eq) goto loc_82474748;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82474748
	if (ctx.cr6.eq) goto loc_82474748;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r10,r10,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82474748
	if (ctx.cr0.eq) goto loc_82474748;
	// ld r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 96);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f1,0(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,2616(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2616);
	ctx.f2.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825a4a40
	ctx.lr = 0x8247473C;
	sub_825A4A40(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
loc_82474748:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x82474758
	if (!ctx.cr6.eq) goto loc_82474758;
	// lfs f13,-236(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -236);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8247475c
	goto loc_8247475C;
loc_82474758:
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
loc_8247475C:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r8,0(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// addi r11,r11,-29568
	ctx.r11.s64 = ctx.r11.s64 + -29568;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r8,44(r29)
	REX_STORE_U32(ctx.r29.u32 + 44, ctx.r8.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stb r7,186(r29)
	REX_STORE_U8(ctx.r29.u32 + 186, ctx.r7.u8);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r11,48(r29)
	REX_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,68(r29)
	REX_STORE_U64(ctx.r29.u32 + 68, ctx.r11.u64);
loc_824747C8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82487840) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,6168
	ctx.r4.s64 = ctx.r11.s64 + 6168;
	// bl 0x822167f8
	ctx.lr = 0x82487864;
	sub_822167F8(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82487878
	if (!ctx.cr6.lt) goto loc_82487878;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
loc_82487878:
	// li r5,28
	ctx.r5.s64 = 28;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x82487884;
	sub_8246A2C0(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82487898
	if (!ctx.cr6.lt) goto loc_82487898;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
loc_82487898:
	// li r5,30
	ctx.r5.s64 = 30;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x824878A4;
	sub_8246A2C0(ctx, base);
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
	ctx.lr = 0x824878C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x824878d4
	if (!ctx.cr6.lt) goto loc_824878D4;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
loc_824878D4:
	// li r5,139
	ctx.r5.s64 = 139;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x824878E0;
	sub_8246A4B8(ctx, base);
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
	ctx.lr = 0x824878FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,-24796
	ctx.r4.s64 = ctx.r11.s64 + -24796;
	// bl 0x822167f8
	ctx.lr = 0x8248790C;
	sub_822167F8(ctx, base);
	// lwz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82487920
	if (!ctx.cr6.lt) goto loc_82487920;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
loc_82487920:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x8248792C;
	sub_8246A2C0(ctx, base);
	// lwz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82487940
	if (!ctx.cr6.lt) goto loc_82487940;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
loc_82487940:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x8248794C;
	sub_8246A2C0(ctx, base);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
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
	ctx.lr = 0x82487968;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82487984;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r11,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r11.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235ec48
	ctx.lr = 0x8248799C;
	sub_8235EC48(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x824879AC;
	sub_8235EC48(ctx, base);
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

DEFINE_REX_FUNC(sub_82491F60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82491F68;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r4,r10,4408
	ctx.r4.s64 = ctx.r10.s64 + 4408;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,29
	ctx.r7.s64 = 29;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x82491FA4;
	sub_825190E8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r11,r11,-23192
	ctx.r11.s64 = ctx.r11.s64 + -23192;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r10.u32);
	// stb r30,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r30.u8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4640
	ctx.lr = 0x82491FC8;
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
	ctx.lr = 0x82491FE4;
	sub_825A48B0(ctx, base);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stw r28,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r28.u32);
	// addi r7,r9,12468
	ctx.r7.s64 = ctx.r9.s64 + 12468;
	// stw r27,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r27.u32);
	// addi r10,r11,17288
	ctx.r10.s64 = ctx.r11.s64 + 17288;
	// stw r30,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r30.u32);
	// lis r6,-32114
	ctx.r6.s64 = -2104623104;
	// stb r30,364(r31)
	REX_STORE_U8(ctx.r31.u32 + 364, ctx.r30.u8);
	// addic r8,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r8.s64 = ctx.r28.s64 + -1;
	// lfs f31,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// li r9,128
	ctx.r9.s64 = 128;
	// stfs f31,300(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// lfs f0,3188(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 3188);
	ctx.f0.f64 = double(temp.f32);
	// subfe r11,r8,r28
	temp.u8 = (~ctx.r8.u32 + ctx.r28.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r28.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r8.u64 + ctx.r28.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stb r30,328(r31)
	REX_STORE_U8(ctx.r31.u32 + 328, ctx.r30.u8);
	// lfs f13,-156(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -156);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi. r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lfs f0,-4480(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -4480);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,308(r31)
	REX_STORE_U8(ctx.r31.u32 + 308, ctx.r11.u8);
	// stfs f31,304(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stw r9,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r9.u32);
	// stfs f13,296(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stw r30,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r30.u32);
	// stfs f31,352(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 352, temp.u32);
	// stw r30,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r30.u32);
	// stfs f0,356(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 356, temp.u32);
	// beq 0x82492060
	if (ctx.cr0.eq) goto loc_82492060;
	// lfs f0,-27548(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27548);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82492064
	goto loc_82492064;
loc_82492060:
	// lfs f0,-28432(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28432);
	ctx.f0.f64 = double(temp.f32);
loc_82492064:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r3,-32224
	ctx.r3.s64 = -2111832064;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r6,-29600
	ctx.r6.s64 = ctx.r6.s64 + -29600;
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,-31744
	ctx.r3.s64 = ctx.r3.s64 + -31744;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// vaddfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,376(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// lfs f0,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,380(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// lbz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 308);
	// lfs f0,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v61,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x82492130
	if (ctx.cr0.eq) goto loc_82492130;
	// lfs f0,-26956(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -26956);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82492134
	goto loc_82492134;
loc_82492130:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_82492134:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f12,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r4,10
	ctx.r4.s64 = 10;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r3,-10
	ctx.r3.s64 = -10;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,96(r1)
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// bl 0x825a49b0
	ctx.lr = 0x824921E4;
	sub_825A49B0(ctx, base);
	// lbz r10,308(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 308);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stb r30,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r30.u8);
	// stw r30,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r30.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r11,r11,-30056
	ctx.r11.s64 = ctx.r11.s64 + -30056;
	// beq 0x82492208
	if (ctx.cr0.eq) goto loc_82492208;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82492210
	goto loc_82492210;
loc_82492208:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,8016(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8016);
	ctx.f0.f64 = double(temp.f32);
loc_82492210:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
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
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,384(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 384, temp.u32);
	// lwz r10,404(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8249226c
	if (!ctx.cr6.eq) goto loc_8249226C;
	// lfs f0,-76(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -76);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82492270
	goto loc_82492270;
loc_8249226C:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82492270:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// lwz r4,404(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// bl 0x82493d78
	ctx.lr = 0x824922C4;
	sub_82493D78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824B7C08) {
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
	ctx.lr = 0x824B7C28;
	sub_8235EC48(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823d8ce8
	ctx.lr = 0x824B7C30;
	sub_823D8CE8(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x824b7c44
	if (!ctx.cr6.lt) goto loc_824B7C44;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_824B7C44:
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824b7c94
	if (ctx.cr6.eq) goto loc_824B7C94;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x824B7C5C;
	sub_8246D8F0(ctx, base);
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824b7c94
	if (ctx.cr6.eq) goto loc_824B7C94;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-18484
	ctx.r3.s64 = ctx.r11.s64 + -18484;
	// bl 0x8246d8f0
	ctx.lr = 0x824B7C78;
	sub_8246D8F0(ctx, base);
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824b7c94
	if (ctx.cr6.eq) goto loc_824B7C94;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,1444
	ctx.r3.s64 = ctx.r11.s64 + 1444;
	// bl 0x8246d8f0
	ctx.lr = 0x824B7C94;
	sub_8246D8F0(ctx, base);
loc_824B7C94:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x824B7CA4;
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

DEFINE_REX_FUNC(sub_824BB6A0) {
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
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,27428
	ctx.r4.s64 = ctx.r11.s64 + 27428;
	// bl 0x822167f8
	ctx.lr = 0x824BB6C4;
	sub_822167F8(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x824bb6d8
	if (!ctx.cr6.lt) goto loc_824BB6D8;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
loc_824BB6D8:
	// li r5,17
	ctx.r5.s64 = 17;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x824BB6E4;
	sub_8246A4B8(ctx, base);
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
	ctx.lr = 0x824BB700;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x824BB710;
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

DEFINE_REX_FUNC(sub_824BD9D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824BD9D8;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	ctx.lr = 0x824BD9F8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824bda14
	if (ctx.cr0.eq) goto loc_824BDA14;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f1,-23596(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23596);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8247b060
	ctx.lr = 0x824BDA0C;
	sub_8247B060(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x824bda18
	goto loc_824BDA18;
loc_824BDA14:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824BDA18:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r29,-32240
	ctx.r29.s64 = -2112880640;
	// addi r30,r11,-30264
	ctx.r30.s64 = ctx.r11.s64 + -30264;
	// addi r11,r29,15656
	ctx.r11.s64 = ctx.r29.s64 + 15656;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-1212(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1212);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-3184(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3184);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x824BDA38;
	sub_825A4A40(ctx, base);
	// lfs f0,-1224(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1224);
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
	ctx.lr = 0x824BDA50;
	sub_825A4A40(ctx, base);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// beq cr6,0x824bdab8
	if (ctx.cr6.eq) goto loc_824BDAB8;
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r29,-32227
	ctx.r29.s64 = -2112028672;
	// lfs f1,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,168(r31)
	REX_STORE_U64(ctx.r31.u32 + 168, ctx.r11.u64);
	// lwz r11,-2736(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -2736);
	// lfs f2,-24640(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -24640);
	ctx.f2.f64 = double(temp.f32);
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// bl 0x825a4a40
	ctx.lr = 0x824BDA88;
	sub_825A4A40(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
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
	ctx.lr = 0x824BDAA0;
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
	// lfs f0,1612(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1612);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,188(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 188, temp.u32);
loc_824BDAB8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824C5320) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x824C5328;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,344(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 344);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824c53e0
	if (!ctx.cr0.eq) goto loc_824C53E0;
	// lwz r3,364(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 364);
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stb r30,344(r31)
	REX_STORE_U8(ctx.r31.u32 + 344, ctx.r30.u8);
	// beq cr6,0x824c5364
	if (ctx.cr6.eq) goto loc_824C5364;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824C5364;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824C5364:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c9448
	ctx.lr = 0x824C536C;
	sub_824C9448(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stw r30,4136(r31)
	REX_STORE_U32(ctx.r31.u32 + 4136, ctx.r30.u32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// stb r30,384(r31)
	REX_STORE_U8(ctx.r31.u32 + 384, ctx.r30.u8);
	// addi r28,r31,4052
	ctx.r28.s64 = ctx.r31.s64 + 4052;
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,116(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,284(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 284, temp.u32);
	// stfs f0,288(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// stfs f0,368(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// stfs f13,292(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// lwz r30,4060(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 4060);
	// lwz r29,4056(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 4056);
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x824c53e0
	if (ctx.cr6.eq) goto loc_824C53E0;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r30
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x824c53dc
	if (ctx.cr6.eq) goto loc_824C53DC;
loc_824C53BC:
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x824C53CC;
	sub_8273A030(ctx, base);
	// addi r31,r31,48
	ctx.r31.s64 = ctx.r31.s64 + 48;
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x824c53bc
	if (!ctx.cr6.eq) goto loc_824C53BC;
loc_824C53DC:
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
loc_824C53E0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824CFD20) {
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
	// lwz r11,340(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 340);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x824CFD3C;
	sub_82222BB0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D0E80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x824D0E88;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,88(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// ld r8,44(r3)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r3.u32 + 44);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x824d0f84
	if (!ctx.cr6.eq) goto loc_824D0F84;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824d0f84
	if (ctx.cr6.eq) goto loc_824D0F84;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824d0f84
	if (ctx.cr0.eq) goto loc_824D0F84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x824D0EE4;
	sub_82430A88(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,428(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 428);
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
	// lfs f13,432(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 432);
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
loc_824D0F84:
	// ld r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r31,288
	ctx.r30.s64 = ctx.r31.s64 + 288;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r31,436
	ctx.r4.s64 = ctx.r31.s64 + 436;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
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
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
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
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vsubfp128 v63,v60,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,436(r31)
	REX_STORE_U64(ctx.r31.u32 + 436, ctx.r11.u64);
	// bl 0x8254bb70
	ctx.lr = 0x824D103C;
	sub_8254BB70(ctx, base);
	// addi r26,r31,296
	ctx.r26.s64 = ctx.r31.s64 + 296;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8254bb70
	ctx.lr = 0x824D1048;
	sub_8254BB70(ctx, base);
	// addi r29,r31,304
	ctx.r29.s64 = ctx.r31.s64 + 304;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8254bb70
	ctx.lr = 0x824D1054;
	sub_8254BB70(ctx, base);
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lwz r10,292(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwz r9,304(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// addi r27,r31,352
	ctx.r27.s64 = ctx.r31.s64 + 352;
	// lwz r8,308(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// stw r11,352(r31)
	REX_STORE_U32(ctx.r31.u32 + 352, ctx.r11.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r10,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r10.u32);
	// stw r9,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r9.u32);
	// stw r8,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r8.u32);
	// lfs f4,-16684(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16684);
	ctx.f4.f64 = double(temp.f32);
loc_824D1084:
	// extsw r11,r28
	ctx.r11.s64 = ctx.r28.s32;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmuls f1,f0,f4
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f4.f64));
	// bl 0x825a5eb8
	ctx.lr = 0x824D10B0;
	sub_825A5EB8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplwi cr6,r28,8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 8, ctx.xer);
	// stwu r11,8(r27)
	ea = 8 + ctx.r27.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r27.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// blt cr6,0x824d1084
	if (ctx.cr6.lt) goto loc_824D1084;
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824D10E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824E19E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x824E19F0;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
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
	ctx.lr = 0x824E1A0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824e1ba0
	if (!ctx.cr0.eq) goto loc_824E1BA0;
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,128(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// addi r30,r31,120
	ctx.r30.s64 = ctx.r31.s64 + 120;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r8,124(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r27,255
	ctx.r27.s64 = 255;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
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
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r26,204
	ctx.r26.s64 = 204;
	// li r25,1
	ctx.r25.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// beq 0x824e1aec
	if (ctx.cr0.eq) goto loc_824E1AEC;
	// stb r27,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r27.u8);
	// li r29,0
	ctx.r29.s64 = 0;
	// stb r27,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r27.u8);
	// stb r27,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r27.u8);
	// stb r26,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r26.u8);
loc_824E1A74:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E1A8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r25,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r25.u8);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E1AAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lfs f0,892(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 892);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E1ACC;
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
	// blt cr6,0x824e1a74
	if (ctx.cr6.lt) goto loc_824E1A74;
loc_824E1AEC:
	// lwz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// addi r29,r31,136
	ctx.r29.s64 = ctx.r31.s64 + 136;
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
	// beq 0x824e1b94
	if (ctx.cr0.eq) goto loc_824E1B94;
	// stb r27,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r27.u8);
	// li r30,0
	ctx.r30.s64 = 0;
	// stb r27,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r27.u8);
	// stb r27,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r27.u8);
	// stb r26,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r26.u8);
loc_824E1B1C:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E1B34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r25,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r25.u8);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E1B54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lfs f0,892(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 892);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E1B74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x824e1b1c
	if (ctx.cr6.lt) goto loc_824E1B1C;
loc_824E1B94:
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246c998
	ctx.lr = 0x824E1BA0;
	sub_8246C998(ctx, base);
loc_824E1BA0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824EC9B8) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,101(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 101);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824ec9e8
	if (!ctx.cr0.eq) goto loc_824EC9E8;
loc_824EC9E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824ecc70
	goto loc_824ECC70;
loc_824EC9E8:
	// lbz r11,102(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 102);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824eca0c
	if (ctx.cr0.eq) goto loc_824ECA0C;
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824ECA08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r3,102(r31)
	REX_STORE_U8(ctx.r31.u32 + 102, ctx.r3.u8);
loc_824ECA0C:
	// lbz r11,102(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 102);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824ecc6c
	if (!ctx.cr0.eq) goto loc_824ECC6C;
	// lbz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 100);
	// lfs f31,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824eca98
	if (!ctx.cr0.eq) goto loc_824ECA98;
	// lhz r11,58(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 58);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lwz r8,108(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfs f13,-520(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -520);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,120(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 120);
	// addi r30,r31,108
	ctx.r30.s64 = ctx.r31.s64 + 108;
	// lfs f12,-18968(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -18968);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmadds f0,f11,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f13.f64)));
	// fadds f1,f0,f12
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// bctrl 
	ctx.lr = 0x824ECA78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824ECA90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,100(r31)
	REX_STORE_U8(ctx.r31.u32 + 100, ctx.r11.u8);
loc_824ECA98:
	// lfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f13,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 84, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x824ec9e0
	if (ctx.cr6.gt) goto loc_824EC9E0;
	// lfs f0,80(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r31,68
	ctx.r4.s64 = ctx.r31.s64 + 68;
	// lfs f13,76(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fnmsubs f0,f13,f31,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f31.f64, -ctx.f0.f64)));
	// stfs f0,80(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
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
	// bl 0x8231e0d8
	ctx.lr = 0x824ECADC;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f31,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
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
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,60(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
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
	// lvx128 v13,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,68(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f11.f64 = double(temp.f32);
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
	// lvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
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
	// lfs f12,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v13,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,60(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f0,23848(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 23848);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,64(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// lfs f13,96(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 96, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824ecc6c
	if (!ctx.cr6.gt) goto loc_824ECC6C;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r9,108(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lfs f0,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 96, temp.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ECC6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824ECC6C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_824ECC70:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

DEFINE_REX_FUNC(sub_82503A20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82503A28;
	__savegprlr_23(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af24
	ctx.lr = 0x82503A30;
	__savefpr_27(ctx, base);
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8273b36c
	ctx.lr = 0x82503A38;
	__savevmx_123(ctx, base);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// clrlwi. r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82503a58
	if (ctx.cr0.eq) goto loc_82503A58;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r29,r3,412
	ctx.r29.s64 = ctx.r3.s64 + 412;
	// lfs f27,-16180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16180);
	ctx.f27.f64 = double(temp.f32);
	// b 0x82503a64
	goto loc_82503A64;
loc_82503A58:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r29,r25,424
	ctx.r29.s64 = ctx.r25.s64 + 424;
	// lfs f27,-16192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16192);
	ctx.f27.f64 = double(temp.f32);
loc_82503A64:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825040bc
	if (ctx.cr6.eq) goto loc_825040BC;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82503A84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825040bc
	if (!ctx.cr0.eq) goto loc_825040BC;
	// lwz r3,344(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 344);
	// bl 0x8259be58
	ctx.lr = 0x82503A94;
	sub_8259BE58(ctx, base);
	// mr. r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq 0x825040bc
	if (ctx.cr0.eq) goto loc_825040BC;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r7,r10,12236
	ctx.r7.s64 = ctx.r10.s64 + 12236;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f29,12236(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12236);
	ctx.f29.f64 = double(temp.f32);
	// addi r10,r9,-18544
	ctx.r10.s64 = ctx.r9.s64 + -18544;
	// lfs f8,-18544(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18544);
	ctx.f8.f64 = double(temp.f32);
	// addi r28,r11,-4080
	ctx.r28.s64 = ctx.r11.s64 + -4080;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// stfs f29,296(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// lis r6,-32227
	ctx.r6.s64 = -2112028672;
	// lfs f0,2640(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2640);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,-12872(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -12872);
	// lfs f31,232(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,2140(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2140);
	ctx.f30.f64 = double(temp.f32);
	// lfs f13,-1828(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1828);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f12,-8956(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8956);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,932(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 932);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,1392(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1392);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,24080(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 24080);
	ctx.f9.f64 = double(temp.f32);
	// stfs f31,240(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f31,244(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f31,260(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f30,264(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f30,272(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f31,276(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f11,280(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f11,288(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f31,292(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f31,304(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// stfs f0,308(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// stfs f0,312(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f10,316(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// stfs f31,324(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f30,328(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f10,332(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f13,192(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f12,200(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f12,204(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f9,212(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f12,216(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f8,220(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// beq cr6,0x82503b7c
	if (ctx.cr6.eq) goto loc_82503B7C;
	// lfs f28,664(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f28.f64 = double(temp.f32);
	// b 0x82503b80
	goto loc_82503B80;
loc_82503B7C:
	// fmr f28,f29
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f29.f64;
loc_82503B80:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,352
	ctx.r11.s64 = ctx.r1.s64 + 352;
	// addi r10,r1,368
	ctx.r10.s64 = ctx.r1.s64 + 368;
	// lfs f1,1640(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1640);
	ctx.f1.f64 = double(temp.f32);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// addi r8,r1,400
	ctx.r8.s64 = ctx.r1.s64 + 400;
	// vupkd3d128 v123,v63,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v123 = vTemp;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// vpermwi128 v127,v123,234
	simde_mm_store_si128((simde__m128i*)ctx.v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x15));
	// vpermwi128 v126,v123,186
	simde_mm_store_si128((simde__m128i*)ctx.v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x45));
	// vpermwi128 v125,v123,174
	simde_mm_store_si128((simde__m128i*)ctx.v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x51));
	// vpermwi128 v124,v123,171
	simde_mm_store_si128((simde__m128i*)ctx.v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x54));
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
	ctx.lr = 0x82503BC4;
	sub_823C96B0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// vspltw128 v62,v127,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0xFF));
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// vspltw128 v61,v126,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xFF));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// vspltw128 v60,v125,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xFF));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// vspltw128 v59,v124,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0xFF));
	// vspltw128 v9,v127,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0xAA));
	// fdivs f0,f29,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f29.f64 / ctx.f28.f64));
	// lwz r10,-15444(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -15444);
	// vspltw128 v7,v126,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xAA));
	// lwz r11,-15432(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -15432);
	// vspltw128 v5,v125,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xAA));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v3,v124,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0xAA));
	// vmulfp128 v8,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v12,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v6,v61,v63
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v1,v127,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x55));
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// vmulfp128 v4,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// fcfid f13,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(ctx.f13.s64);
	// vmulfp128 v2,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v9,v9,v12,v8
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// vmaddfp v8,v7,v12,v6
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vspltw128 v31,v126,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x55));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// vspltw128 v30,v125,2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x55));
	// vspltw128 v29,v124,2
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0x55));
	// lfs f11,44(r25)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// vspltw128 v28,v127,3
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x0));
	// lfs f10,48(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 48);
	ctx.f10.f64 = double(temp.f32);
	// lvx128 v11,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v27,v126,3
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x0));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v10,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v26,v125,3
	simde_mm_store_si128((simde__m128i*)ctx.v26.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x0));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f29,108(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// vspltw128 v25,v124,3
	simde_mm_store_si128((simde__m128i*)ctx.v25.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0x0));
	// vmaddfp v7,v5,v12,v4
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vpermwi128 v63,v123,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x15));
	// vmaddfp v12,v3,v12,v2
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vpermwi128 v0,v123,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x45));
	// vmaddfp v9,v1,v11,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vpermwi128 v13,v123,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x51));
	// vmaddfp v8,v31,v11,v8
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// fmuls f12,f12,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// vmaddfp v7,v30,v11,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v12,v29,v11,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v11,v28,v10,v9
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v9,v27,v10,v8
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// fnmsubs f12,f12,f30,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f30.f64, -ctx.f11.f64)));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmsubs f0,f0,f30,f10
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f30.f64, -ctx.f10.f64)));
	// vmaddfp v8,v26,v10,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v26.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vor128 v62,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vmaddfp v10,v25,v10,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v25.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v59,v9,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), 0xFF));
	// vspltw v1,v9,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), 0xAA));
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vspltw v5,v9,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), 0x55));
	// lvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// vmulfp128 v31,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v3,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vspltw128 v4,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// vspltw v9,v9,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), 0x0));
	// addi r11,r1,384
	ctx.r11.s64 = ctx.r1.s64 + 384;
	// vmulfp128 v2,v60,v63
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r8,r1,400
	ctx.r8.s64 = ctx.r1.s64 + 400;
	// lwz r26,4(r29)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// vspltw128 v58,v8,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0xFF));
	// vor128 v61,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vspltw v30,v8,1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0xAA));
	// vspltw v6,v8,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0x55));
	// lwz r31,0(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// vspltw v10,v8,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0x0));
	// vmulfp128 v29,v58,v63
	simde_mm_store_ps(ctx.v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v8,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vspltw128 v57,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v28,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vspltw128 v7,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vmaddfp v3,v3,v0,v2
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vspltw128 v11,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vmulfp128 v27,v57,v63
	simde_mm_store_ps(ctx.v27.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v2,v1,v0,v31
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v1,v30,v0,v29
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v4,v4,v13,v3
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v0,v28,v0,v27
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v27.f32)));
	// vmaddfp v5,v5,v13,v2
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v6,v6,v13,v1
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v8,v8,v12,v4
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v0,v7,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v8,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v9,v9,v12,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v13,v10,v12,v6
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v0,v11,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v9,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825f8d38
	ctx.lr = 0x82503D90;
	sub_825F8D38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82503dbc
	if (ctx.cr0.eq) goto loc_82503DBC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,8(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// bl 0x825f8b88
	ctx.lr = 0x82503DA4;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r5,r29,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x82503DB8;
	sub_825F8BF8(ctx, base);
	// b 0x82503dc0
	goto loc_82503DC0;
loc_82503DBC:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82503DC0:
	// lwz r29,424(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// cmplw cr6,r31,r26
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x8250403c
	if (ctx.cr6.eq) goto loc_8250403C;
	// lfs f28,412(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 412);
	ctx.f28.f64 = double(temp.f32);
	// addi r27,r29,-8
	ctx.r27.s64 = ctx.r29.s64 + -8;
	// stfs f29,348(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
loc_82503DD8:
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// li r11,4
	ctx.r11.s64 = 4;
	// lfs f13,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// subfc r9,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r9.u64 = ctx.r11.u64 - ctx.r10.u64;
	// lfs f30,12(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f30.f64 = double(temp.f32);
	// eqv r11,r10,r11
	ctx.r11.u64 = ~(ctx.r10.u64 ^ ctx.r11.u64);
	// lfs f1,28(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// fneg f29,f13
	ctx.f29.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// rlwinm r11,r11,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addze r23,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r23.s64 = temp.s64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// subfic r28,r11,-256
	ctx.xer.ca = ctx.r11.u32 <= 4294967040;
	ctx.r28.u64 = static_cast<uint64_t>(-256) - ctx.r11.u64;
	// bl 0x82229390
	ctx.lr = 0x82503E20;
	sub_82229390(ctx, base);
	// stfs f31,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// rlwinm r11,r23,4,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 4) & 0x10;
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,196
	ctx.r9.s64 = ctx.r1.s64 + 196;
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,200
	ctx.r8.s64 = ctx.r1.s64 + 200;
	// addi r7,r1,204
	ctx.r7.s64 = ctx.r1.s64 + 204;
	// lfs f0,24(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lfsx f13,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lfsx f12,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfsx f11,r11,r8
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfsx f10,r11,r7
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// fmuls f0,f10,f0
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stfs f31,168(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// li r8,48
	ctx.r8.s64 = 48;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v12,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v0,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v4,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vspltw128 v8,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v5,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmaddfp v4,v0,v4,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v9,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v6,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmaddfp v5,v0,v5,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v10,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmaddfp v6,v0,v6,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v0,v0,v7,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v11,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// lvx128 v13,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v8,v13,v4
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v9,v9,v13,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v12,v10,v13,v6
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v0,v11,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stvx128 v8,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,4
	ctx.r9.s64 = 4;
	// stvx128 v9,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82503F38:
	// addi r8,r1,336
	ctx.r8.s64 = ctx.r1.s64 + 336;
	// lfs f13,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfsu f0,16(r10)
	ea = 16 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// fadds f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f30.f64));
	// lfs f12,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// stfs f13,336(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// stw r28,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r28.u32);
	// stfs f12,344(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stfs f0,340(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r6,8(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r5,12(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stw r6,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// stw r5,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// bne 0x82503f38
	if (!ctx.cr0.eq) goto loc_82503F38;
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// addi r9,r1,244
	ctx.r9.s64 = ctx.r1.s64 + 244;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// addi r7,r1,248
	ctx.r7.s64 = ctx.r1.s64 + 248;
	// addi r6,r1,244
	ctx.r6.s64 = ctx.r1.s64 + 244;
	// addi r5,r1,248
	ctx.r5.s64 = ctx.r1.s64 + 248;
	// lfsx f0,r10,r9
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,252
	ctx.r4.s64 = ctx.r1.s64 + 252;
	// lfsx f13,r10,r8
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r10,r1,252
	ctx.r10.s64 = ctx.r1.s64 + 252;
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// ld r11,184(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 184);
	// std r11,40(r27)
	REX_STORE_U64(ctx.r27.u32 + 40, ctx.r11.u64);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r11,r7
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r6
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// ld r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// std r11,80(r27)
	REX_STORE_U64(ctx.r27.u32 + 80, ctx.r11.u64);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r11,r5
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r4
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// ld r11,224(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 224);
	// std r11,120(r27)
	REX_STORE_U64(ctx.r27.u32 + 120, ctx.r11.u64);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stdu r11,160(r27)
	ea = 160 + ctx.r27.u32;
	REX_STORE_U64(ea, ctx.r11.u64);
	ctx.r27.u32 = ea;
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r31,r26
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x82503dd8
	if (!ctx.cr6.eq) goto loc_82503DD8;
loc_8250403C:
	// lwz r11,352(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 352);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r11,76(r30)
	REX_STORE_U32(ctx.r30.u32 + 76, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r24,208(r30)
	REX_STORE_U32(ctx.r30.u32 + 208, ctx.r24.u32);
	// lfs f0,-8644(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// stb r10,71(r30)
	REX_STORE_U8(ctx.r30.u32 + 71, ctx.r10.u8);
	// lhz r11,6(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lwz r11,408(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// stw r11,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r11.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmadds f0,f13,f0,f27
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f27.f64)));
	// stfs f0,412(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 412, temp.u32);
	// lwz r11,3596(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 3596);
	// stw r11,368(r30)
	REX_STORE_U32(ctx.r30.u32 + 368, ctx.r11.u32);
	// lwz r11,408(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stw r11,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r11.u32);
	// bl 0x8273a030
	ctx.lr = 0x825040AC;
	sub_8273A030(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82459d08
	ctx.lr = 0x825040BC;
	sub_82459D08(ctx, base);
loc_825040BC:
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8273b604
	ctx.lr = 0x825040C8;
	__restvmx_123(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af70
	ctx.lr = 0x825040D0;
	__restfpr_27(ctx, base);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82544DD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,312(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 312);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
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
	// lwz r11,144(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// lwz r10,140(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82544e18
	if (ctx.cr0.eq) goto loc_82544E18;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r10.u32);
loc_82544E18:
	// li r11,2
	ctx.r11.s64 = 2;
	// stfs f0,296(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// stw r11,312(r3)
	REX_STORE_U32(ctx.r3.u32 + 312, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82546B08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82546B10;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r5,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r5.u64);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x82546B40;
	sub_825190E8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r11,32720
	ctx.r9.s64 = ctx.r11.s64 + 32720;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,3704
	ctx.r7.s64 = ctx.r7.s64 + 3704;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,0
	ctx.r30.s64 = 0;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r31,300
	ctx.r29.s64 = ctx.r31.s64 + 300;
	// stfs f13,300(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stb r30,312(r31)
	REX_STORE_U8(ctx.r31.u32 + 312, ctx.r30.u8);
	// lfs f11,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// stb r30,324(r31)
	REX_STORE_U8(ctx.r31.u32 + 324, ctx.r30.u8);
	// stfs f11,308(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stb r30,325(r31)
	REX_STORE_U8(ctx.r31.u32 + 325, ctx.r30.u8);
	// stfs f11,316(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stb r10,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r10.u8);
	// stfs f11,320(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// stb r30,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r30.u8);
	// bne cr6,0x82546bc0
	if (!ctx.cr6.eq) goto loc_82546BC0;
	// lfs f12,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82546bc4
	goto loc_82546BC4;
loc_82546BC0:
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_82546BC4:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,212(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 212);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r11,r11,-30464
	ctx.r11.s64 = ctx.r11.s64 + -30464;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f13,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f12,f11
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r30,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r30.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r28,88(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// rlwinm r10,r28,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 4) & 0xFFFF0;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
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
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// ld r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f12,296(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// std r9,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r9.u64);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82546d90
	if (!ctx.cr6.eq) goto loc_82546D90;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82546d90
	if (ctx.cr6.eq) goto loc_82546D90;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82546d90
	if (ctx.cr0.eq) goto loc_82546D90;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a10
	ctx.lr = 0x82546CE8;
	sub_82430A10(ctx, base);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r9,44(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r29)
	REX_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
loc_82546D90:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r30,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r30.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8255BFB0) {
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
	// bl 0x8255c008
	ctx.lr = 0x8255BFD0;
	sub_8255C008(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8255bfe8
	if (ctx.cr0.eq) goto loc_8255BFE8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8255bfe8
	if (ctx.cr6.eq) goto loc_8255BFE8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8255BFE8;
	sub_825E0378(ctx, base);
loc_8255BFE8:
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

DEFINE_REX_FUNC(sub_8255E4A0) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-15060
	ctx.r4.s64 = ctx.r11.s64 + -15060;
	// bl 0x822167f8
	ctx.lr = 0x8255E4C4;
	sub_822167F8(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8255e4d8
	if (!ctx.cr6.lt) goto loc_8255E4D8;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
loc_8255E4D8:
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x8255E4E4;
	sub_8246A2C0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,33
	ctx.r4.s64 = 33;
	// lbz r6,80(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// stb r11,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r11.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r5,88(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x82517f98
	ctx.lr = 0x8255E500;
	sub_82517F98(ctx, base);
	// stfs f1,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 196, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8255E514;
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

DEFINE_REX_FUNC(sub_82561B90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82561B98;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32226
	ctx.r29.s64 = -2111963136;
	// lfs f13,308(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r29,-9856
	ctx.r10.s64 = ctx.r29.s64 + -9856;
	// lfs f0,-6828(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6828);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f1,308(r3)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 308, temp.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82561BD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f31,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f31.f64 = double(temp.f32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f13,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// fsubs f13,f31,f13
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f13.f64));
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f1,f13,f0,f31
	ctx.f1.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f31.f64)));
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82561C08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f0,-9856(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -9856);
	ctx.f0.f64 = double(temp.f32);
	// li r30,255
	ctx.r30.s64 = 255;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
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
	ctx.lr = 0x82561C50;
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
	ctx.lr = 0x82561C6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x82561ce4
	if (ctx.cr6.lt) goto loc_82561CE4;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// stb r30,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x82561CA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82561CC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82561CDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82561ce8
	goto loc_82561CE8;
loc_82561CE4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82561CE8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8256C858) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8256C860;
	__savegprlr_29(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r8,340(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 340);
	// mulli r9,r4,20
	ctx.r9.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(20));
	// li r10,5
	ctx.r10.s64 = 5;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r8,r1,124
	ctx.r8.s64 = ctx.r1.s64 + 124;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8256C884:
	// lwzu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r10,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x8256c884
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8256C884;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r8,32384
	ctx.r8.s64 = ctx.r8.s64 + 32384;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f13,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r31,r1,112
	ctx.r31.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f13,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vsubfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// lvx128 v58,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,-13032(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// stvx128 v59,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,2688
	ctx.r9.s64 = ctx.r9.s64 + 2688;
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r9,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r29,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r29.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v60,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v61,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r9,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r9.u64);
	// std r10,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.r10.u64);
	// beq cr6,0x8256c9c4
	if (ctx.cr6.eq) goto loc_8256C9C4;
	// lfs f0,196(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lbz r9,81(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 81);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// addi r10,r1,136
	ctx.r10.s64 = ctx.r1.s64 + 136;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lfs f1,200(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// lwz r7,88(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// lwz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r4,100(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x823b0938
	ctx.lr = 0x8256C9C4;
	sub_823B0938(ctx, base);
loc_8256C9C4:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82577228) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-12856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82577280
	if (ctx.cr6.eq) goto loc_82577280;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm. r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82577280
	if (ctx.cr0.eq) goto loc_82577280;
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82577278
	if (ctx.cr6.eq) goto loc_82577278;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82577278
	if (ctx.cr6.eq) goto loc_82577278;
	// bl 0x8259be58
	ctx.lr = 0x82577274;
	sub_8259BE58(ctx, base);
	// b 0x8257727c
	goto loc_8257727C;
loc_82577278:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8257727C:
	// lhz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
loc_82577280:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8257ADE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8257ADF0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x8257ae24
	if (ctx.cr6.eq) goto loc_8257AE24;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x82301ce8
	ctx.lr = 0x8257AE18;
	sub_82301CE8(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r11,r27,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r27.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_8257AE24:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stw r10,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r10.u32);
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8257D5F8) {
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
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r11,-12848(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12848);
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// lbz r10,80(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 80);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8257da14
	if (ctx.cr0.eq) goto loc_8257DA14;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r10,12
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 12, ctx.xer);
	// bgt cr6,0x8257d9ac
	if (ctx.cr6.gt) goto loc_8257D9AC;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-6592
	ctx.r12.s64 = ctx.r12.s64 + -6592;
	// lbzx r0,r12,r10
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r10.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32168
	ctx.r12.s64 = -2108162048;
	// nop 
	// addi r12,r12,-10660
	ctx.r12.s64 = ctx.r12.s64 + -10660;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_8257D65C;
	case 1:
		goto loc_8257D9AC;
	case 2:
		goto loc_8257D678;
	case 3:
		goto loc_8257D724;
	case 4:
		goto loc_8257D7A4;
	case 5:
		goto loc_8257D804;
	case 6:
		goto loc_8257D830;
	case 7:
		goto loc_8257D8A4;
	case 8:
		goto loc_8257D904;
	case 9:
		goto loc_8257D9AC;
	case 10:
		goto loc_8257D938;
	case 11:
		goto loc_8257D97C;
	case 12:
		goto loc_8257D904;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8257D65C:
	// bl 0x82576260
	ctx.lr = 0x8257D660;
	sub_82576260(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257d9ac
	if (!ctx.cr0.eq) goto loc_8257D9AC;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,72(r31)
	REX_STORE_U8(ctx.r31.u32 + 72, ctx.r11.u8);
	// b 0x8257d828
	goto loc_8257D828;
loc_8257D678:
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8257d694
	if (ctx.cr6.eq) goto loc_8257D694;
	// bl 0x82576728
	ctx.lr = 0x8257D688;
	sub_82576728(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257d9ac
	if (!ctx.cr0.eq) goto loc_8257D9AC;
	// lwz r11,-12848(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12848);
loc_8257D694:
	// lwz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r10,r10,11
	ctx.r10.s64 = ctx.r10.s64 + 11;
	// stw r9,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r9.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x8257d708
	if (ctx.cr6.lt) goto loc_8257D708;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257d708
	if (ctx.cr6.eq) goto loc_8257D708;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8257d708
	if (!ctx.cr6.lt) goto loc_8257D708;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8257d6f8
	if (ctx.cr6.lt) goto loc_8257D6F8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8257d6fc
	goto loc_8257D6FC;
loc_8257D6F8:
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
loc_8257D6FC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8257d708
	if (ctx.cr6.eq) goto loc_8257D708;
	// bl 0x82575df0
	ctx.lr = 0x8257D708;
	sub_82575DF0(ctx, base);
loc_8257D708:
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r11,r11,11
	ctx.r11.s64 = ctx.r11.s64 + 11;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
loc_8257D724:
	// bl 0x82576260
	ctx.lr = 0x8257D728;
	sub_82576260(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257d9ac
	if (!ctx.cr0.eq) goto loc_8257D9AC;
	// lwz r11,-12848(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12848);
	// lwz r10,76(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257d79c
	if (ctx.cr6.eq) goto loc_8257D79C;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x8257d79c
	if (ctx.cr6.lt) goto loc_8257D79C;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8257d79c
	if (!ctx.cr6.lt) goto loc_8257D79C;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8257d784
	if (ctx.cr6.lt) goto loc_8257D784;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8257d788
	goto loc_8257D788;
loc_8257D784:
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
loc_8257D788:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8257d79c
	if (ctx.cr6.eq) goto loc_8257D79C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82576350
	ctx.lr = 0x8257D798;
	sub_82576350(ctx, base);
	// stw r3,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r3.u32);
loc_8257D79C:
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x8257d9a8
	goto loc_8257D9A8;
loc_8257D7A4:
	// lbz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 36);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8257d9ac
	if (ctx.cr0.eq) goto loc_8257D9AC;
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8257d7fc
	if (ctx.cr6.eq) goto loc_8257D7FC;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// li r11,13
	ctx.r11.s64 = 13;
	// addi r9,r10,12236
	ctx.r9.s64 = ctx.r10.s64 + 12236;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,12236(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// stb r8,280(r1)
	REX_STORE_U8(ctx.r1.u32 + 280, ctx.r8.u8);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stw r11,284(r1)
	REX_STORE_U32(ctx.r1.u32 + 284, ctx.r11.u32);
	// lfs f0,232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// bl 0x825b0be8
	ctx.lr = 0x8257D7FC;
	sub_825B0BE8(ctx, base);
loc_8257D7FC:
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x8257d9a8
	goto loc_8257D9A8;
loc_8257D804:
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8257d81c
	if (ctx.cr6.eq) goto loc_8257D81C;
	// bl 0x82576728
	ctx.lr = 0x8257D814;
	sub_82576728(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257d9ac
	if (!ctx.cr0.eq) goto loc_8257D9AC;
loc_8257D81C:
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
loc_8257D828:
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// b 0x8257d9ac
	goto loc_8257D9AC;
loc_8257D830:
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8257d848
	if (ctx.cr6.eq) goto loc_8257D848;
	// bl 0x82576728
	ctx.lr = 0x8257D840;
	sub_82576728(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257d9ac
	if (!ctx.cr0.eq) goto loc_8257D9AC;
loc_8257D848:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r10,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// beq cr6,0x8257d89c
	if (ctx.cr6.eq) goto loc_8257D89C;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x8257d894
	if (ctx.cr6.eq) goto loc_8257D894;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8257d88c
	if (ctx.cr6.eq) goto loc_8257D88C;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x8257d884
	if (ctx.cr6.eq) goto loc_8257D884;
	// li r3,107
	ctx.r3.s64 = 107;
	// b 0x8257d974
	goto loc_8257D974;
loc_8257D884:
	// li r3,111
	ctx.r3.s64 = 111;
	// b 0x8257d974
	goto loc_8257D974;
loc_8257D88C:
	// li r3,110
	ctx.r3.s64 = 110;
	// b 0x8257d974
	goto loc_8257D974;
loc_8257D894:
	// li r3,109
	ctx.r3.s64 = 109;
	// b 0x8257d974
	goto loc_8257D974;
loc_8257D89C:
	// li r3,108
	ctx.r3.s64 = 108;
	// b 0x8257d974
	goto loc_8257D974;
loc_8257D8A4:
	// bl 0x82576260
	ctx.lr = 0x8257D8A8;
	sub_82576260(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257d9ac
	if (!ctx.cr0.eq) goto loc_8257D9AC;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8257d8f4
	if (ctx.cr6.eq) goto loc_8257D8F4;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x8257d8ec
	if (ctx.cr6.eq) goto loc_8257D8EC;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8257d8e4
	if (ctx.cr6.eq) goto loc_8257D8E4;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x8257d8dc
	if (ctx.cr6.eq) goto loc_8257D8DC;
	// li r3,5733
	ctx.r3.s64 = 5733;
	// b 0x8257d8f8
	goto loc_8257D8F8;
loc_8257D8DC:
	// li r3,5737
	ctx.r3.s64 = 5737;
	// b 0x8257d8f8
	goto loc_8257D8F8;
loc_8257D8E4:
	// li r3,5736
	ctx.r3.s64 = 5736;
	// b 0x8257d8f8
	goto loc_8257D8F8;
loc_8257D8EC:
	// li r3,5735
	ctx.r3.s64 = 5735;
	// b 0x8257d8f8
	goto loc_8257D8F8;
loc_8257D8F4:
	// li r3,5734
	ctx.r3.s64 = 5734;
loc_8257D8F8:
	// bl 0x825762c8
	ctx.lr = 0x8257D8FC;
	sub_825762C8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// b 0x8257d9a4
	goto loc_8257D9A4;
loc_8257D904:
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8257d91c
	if (ctx.cr6.eq) goto loc_8257D91C;
	// bl 0x82576728
	ctx.lr = 0x8257D914;
	sub_82576728(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257d9ac
	if (!ctx.cr0.eq) goto loc_8257D9AC;
loc_8257D91C:
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,15
	ctx.r9.s64 = 15;
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// stb r10,64(r31)
	REX_STORE_U8(ctx.r31.u32 + 64, ctx.r10.u8);
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// b 0x8257d9ac
	goto loc_8257D9AC;
loc_8257D938:
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8257d950
	if (ctx.cr6.eq) goto loc_8257D950;
	// bl 0x82576728
	ctx.lr = 0x8257D948;
	sub_82576728(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257d9ac
	if (!ctx.cr0.eq) goto loc_8257D9AC;
loc_8257D950:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,12
	ctx.r9.s64 = 12;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r10,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r3,r11,104
	ctx.r3.s64 = ctx.r11.s64 + 104;
loc_8257D974:
	// bl 0x82575c28
	ctx.lr = 0x8257D978;
	sub_82575C28(ctx, base);
	// b 0x8257d9ac
	goto loc_8257D9AC;
loc_8257D97C:
	// bl 0x82576260
	ctx.lr = 0x8257D980;
	sub_82576260(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257d9ac
	if (!ctx.cr0.eq) goto loc_8257D9AC;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r3,r11,5730
	ctx.r3.s64 = ctx.r11.s64 + 5730;
	// bl 0x825762c8
	ctx.lr = 0x8257D9A0;
	sub_825762C8(ctx, base);
	// li r11,13
	ctx.r11.s64 = 13;
loc_8257D9A4:
	// stw r3,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r3.u32);
loc_8257D9A8:
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8257D9AC:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8257af58
	ctx.lr = 0x8257D9B4;
	sub_8257AF58(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r8,-556
	ctx.r6.s64 = ctx.r8.s64 + -556;
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f13,-556(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + -556, temp.u32);
loc_8257DA14:
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
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

DEFINE_REX_FUNC(sub_8259BC68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8259BC70;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r28,-12820(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + -12820);
	// lwz r3,-11576(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -11576);
	// bl 0x8260f5b8
	ctx.lr = 0x8259BC88;
	sub_8260F5B8(ctx, base);
	// lbz r11,64(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 64);
	// addi r27,r28,36
	ctx.r27.s64 = ctx.r28.s64 + 36;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8259bca0
	if (ctx.cr0.eq) goto loc_8259BCA0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82855b44
	ctx.lr = 0x8259BCA0;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8259BCA0:
	// li r26,2
	ctx.r26.s64 = 2;
loc_8259BCA4:
	// lwz r11,32(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 32);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// rlwinm r11,r10,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r10,32(r28)
	REX_STORE_U32(ctx.r28.u32 + 32, ctx.r10.u32);
	// add r31,r11,r28
	ctx.r31.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8259bd1c
	if (ctx.cr0.eq) goto loc_8259BD1C;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8259BCD8:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwzx r3,r11,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8259bcfc
	if (ctx.cr6.eq) goto loc_8259BCFC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8259BCFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8259BCFC:
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
	// blt cr6,0x8259bcd8
	if (ctx.cr6.lt) goto loc_8259BCD8;
loc_8259BD1C:
	// lwz r5,8(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x8259bd4c
	if (ctx.cr6.eq) goto loc_8259BD4C;
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
	// ble 0x8259bd48
	if (!ctx.cr0.gt) goto loc_8259BD48;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x8259BD48;
	sub_827388E8(ctx, base);
loc_8259BD48:
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
loc_8259BD4C:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x8259bca4
	if (!ctx.cr0.eq) goto loc_8259BCA4;
	// lbz r11,28(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8259bd68
	if (ctx.cr0.eq) goto loc_8259BD68;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82855b34
	ctx.lr = 0x8259BD68;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8259BD68:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825A38B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825A38C0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r30,r11,3496
	ctx.r30.s64 = ctx.r11.s64 + 3496;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lbz r11,-16471(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + -16471);
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stb r11,-16471(r10)
	REX_STORE_U8(ctx.r10.u32 + -16471, ctx.r11.u8);
	// b 0x825a390c
	goto loc_825A390C;
loc_825A38EC:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r5,28(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bl 0x8263a410
	ctx.lr = 0x825A3908;
	sub_8263A410(ctx, base);
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_825A390C:
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825a38ec
	if (!ctx.cr6.eq) goto loc_825A38EC;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r31,r11,-12812
	ctx.r31.s64 = ctx.r11.s64 + -12812;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_825A3920:
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
	// bne 0x825a3920
	if (!ctx.cr0.eq) goto loc_825A3920;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14204(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14204);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x825a39d8
	if (!ctx.cr6.gt) goto loc_825A39D8;
	// lwz r10,200(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 200);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x825a39b8
	goto loc_825A39B8;
loc_825A3960:
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,172(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 172);
	// rlwinm r11,r9,4,12,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x825a3984
	if (!ctx.cr6.eq) goto loc_825A3984;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_825A3984:
	// lbz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 20);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825a39a8
	if (!ctx.cr0.eq) goto loc_825A39A8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stb r10,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r10.u8);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A39A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825A39A8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82216520
	ctx.lr = 0x825A39B0;
	sub_82216520(ctx, base);
	// lwz r10,200(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 200);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_825A39B8:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x825a3960
	if (!ctx.cr6.eq) goto loc_825A3960;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f1,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a31b0
	ctx.lr = 0x825A39CC;
	sub_825A31B0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f1,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a32a0
	ctx.lr = 0x825A39D8;
	sub_825A32A0(ctx, base);
loc_825A39D8:
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
	// bne 0x825a39d8
	if (!ctx.cr0.eq) goto loc_825A39D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825AE8E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stfs f1,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f2,20(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825AED58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825AED60;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r10,r10,17356
	ctx.r10.s64 = ctx.r10.s64 + 17356;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stb r30,12(r3)
	REX_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r10,r9,22072
	ctx.r10.s64 = ctx.r9.s64 + 22072;
	// stb r11,13(r3)
	REX_STORE_U8(ctx.r3.u32 + 13, ctx.r11.u8);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// stb r11,14(r3)
	REX_STORE_U8(ctx.r3.u32 + 14, ctx.r11.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x825AEDB0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825aedd0
	if (ctx.cr0.eq) goto loc_825AEDD0;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r30,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// b 0x825aedd4
	goto loc_825AEDD4;
loc_825AEDD0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_825AEDD4:
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82619ce8
	ctx.lr = 0x825AEDE8;
	sub_82619CE8(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lis r10,-32165
	ctx.r10.s64 = -2107965440;
	// lis r9,-32165
	ctx.r9.s64 = -2107965440;
	// addi r10,r10,-5640
	ctx.r10.s64 = ctx.r10.s64 + -5640;
	// addi r9,r9,-5488
	ctx.r9.s64 = ctx.r9.s64 + -5488;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// lis r11,-32165
	ctx.r11.s64 = -2107965440;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-4952
	ctx.r11.s64 = ctx.r11.s64 + -4952;
	// lwz r8,16(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r8,0(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r10,32(r8)
	REX_STORE_U32(ctx.r8.u32 + 32, ctx.r10.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r9.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r11,40(r10)
	REX_STORE_U32(ctx.r10.u32 + 40, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B4A48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x825B4A50;
	__savegprlr_22(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r22,r3,204
	ctx.r22.s64 = ctx.r3.s64 + 204;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
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
	// bl 0x82855b44
	ctx.lr = 0x825B4A80;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825b3350
	ctx.lr = 0x825B4A88;
	sub_825B3350(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// blt cr6,0x825b4b14
	if (ctx.cr6.lt) goto loc_825B4B14;
	// lwz r3,260(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lbz r4,335(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 335);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// lwz r31,324(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// lwz r30,316(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 316);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stb r4,111(r1)
	REX_STORE_U8(ctx.r1.u32 + 111, ctx.r4.u8);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// lwz r11,148(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825B4AEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b4b14
	if (ctx.cr6.lt) goto loc_825B4B14;
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// bne cr6,0x825b4b0c
	if (!ctx.cr6.eq) goto loc_825B4B0C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825B4B0C:
	// lwz r10,340(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 340);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_825B4B14:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82855b34
	ctx.lr = 0x825B4B1C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B8B38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825B8B40;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r28,r3,484
	ctx.r28.s64 = ctx.r3.s64 + 484;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b44
	ctx.lr = 0x825B8B54;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,228(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 228);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b8bd4
	if (ctx.cr6.eq) goto loc_825B8BD4;
	// addi r31,r30,16
	ctx.r31.s64 = ctx.r30.s64 + 16;
loc_825B8B68:
	// lwz r11,204(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b8bc8
	if (ctx.cr6.eq) goto loc_825B8BC8;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r10.u32);
	// beq cr6,0x825b8b90
	if (ctx.cr6.eq) goto loc_825B8B90;
	// stw r29,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r29.u32);
	// b 0x825b8b94
	goto loc_825B8B94;
loc_825B8B90:
	// stw r29,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r29.u32);
loc_825B8B94:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r10,212(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r9,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r9.u32);
	// beq cr6,0x825b8bc8
	if (ctx.cr6.eq) goto loc_825B8BC8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825B8BC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825B8BC8:
	// lwz r11,228(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 228);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825b8b68
	if (!ctx.cr6.eq) goto loc_825B8B68;
loc_825B8BD4:
	// lwz r11,448(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 448);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b8c50
	if (ctx.cr6.eq) goto loc_825B8C50;
	// addi r31,r30,236
	ctx.r31.s64 = ctx.r30.s64 + 236;
loc_825B8BE4:
	// lwz r11,204(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b8c44
	if (ctx.cr6.eq) goto loc_825B8C44;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r10.u32);
	// beq cr6,0x825b8c0c
	if (ctx.cr6.eq) goto loc_825B8C0C;
	// stw r29,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r29.u32);
	// b 0x825b8c10
	goto loc_825B8C10;
loc_825B8C0C:
	// stw r29,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r29.u32);
loc_825B8C10:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r9.u32);
	// beq cr6,0x825b8c44
	if (ctx.cr6.eq) goto loc_825B8C44;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825B8C44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825B8C44:
	// lwz r11,448(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 448);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825b8be4
	if (!ctx.cr6.eq) goto loc_825B8BE4;
loc_825B8C50:
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825b8c64
	if (ctx.cr6.eq) goto loc_825B8C64;
	// bl 0x825b85d0
	ctx.lr = 0x825B8C60;
	sub_825B85D0(ctx, base);
	// stw r29,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r29.u32);
loc_825B8C64:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b34
	ctx.lr = 0x825B8C6C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825B8C84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C1128) {
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
	// lwz r8,16(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r7,r3,16
	ctx.r7.s64 = ctx.r3.s64 + 16;
	// clrlwi r11,r8,30
	ctx.r11.u64 = ctx.r8.u32 & 0x3;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x825c1170
	if (ctx.cr6.lt) goto loc_825C1170;
	// beq cr6,0x825c1168
	if (ctx.cr6.eq) goto loc_825C1168;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x825c1174
	if (!ctx.cr6.eq) goto loc_825C1174;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x825c1174
	goto loc_825C1174;
loc_825C1168:
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x825c1174
	goto loc_825C1174;
loc_825C1170:
	// li r10,0
	ctx.r10.s64 = 0;
loc_825C1174:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x825c11b4
	if (ctx.cr6.lt) goto loc_825C11B4;
	// beq cr6,0x825c11a0
	if (ctx.cr6.eq) goto loc_825C11A0;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x825c11c4
	if (!ctx.cr6.eq) goto loc_825C11C4;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x825b8560
	ctx.lr = 0x825C1190;
	sub_825B8560(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_825C11A0:
	// lis r3,1
	ctx.r3.s64 = 65536;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_825C11B4:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// bl 0x825c12a0
	ctx.lr = 0x825C11BC;
	sub_825C12A0(ctx, base);
	// rlwinm r11,r8,30,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x7;
	// mullw r3,r3,r11
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
loc_825C11C4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825C5248) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825C5250;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x825b32d0
	ctx.lr = 0x825C5268;
	sub_825B32D0(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// rlwinm r11,r10,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// beq cr6,0x825c52b8
	if (ctx.cr6.eq) goto loc_825C52B8;
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// bne cr6,0x825c52d8
	if (!ctx.cr6.eq) goto loc_825C52D8;
	// sth r29,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r29.u16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r28,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// beq cr6,0x825c52d8
	if (ctx.cr6.eq) goto loc_825C52D8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r10,r11,12236
	ctx.r10.s64 = ctx.r11.s64 + 12236;
	// lfs f0,232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
loc_825C52B8:
	// sth r29,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r29.u16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r28,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// beq cr6,0x825c52d8
	if (ctx.cr6.eq) goto loc_825C52D8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
loc_825C52D8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825CA8E0) {
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
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lhz r31,440(r3)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r3.u32 + 440);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r31,65535
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 65535, ctx.xer);
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// beq cr6,0x825ca950
	if (ctx.cr6.eq) goto loc_825CA950;
	// lwz r11,312(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 312);
	// rlwinm r10,r31,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 4) & 0xFFFF0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// bl 0x8273a030
	ctx.lr = 0x825CA934;
	sub_8273A030(ctx, base);
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r9,104(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_825CA950:
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// stfs f13,8(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// sth r31,0(r30)
	REX_STORE_U16(ctx.r30.u32 + 0, ctx.r31.u16);
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// stb r10,2(r30)
	REX_STORE_U8(ctx.r30.u32 + 2, ctx.r10.u8);
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

DEFINE_REX_FUNC(sub_825CFEC8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r3,r10,16
	ctx.r3.u64 = ctx.r10.u32 & 0xFFFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825D0860) {
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
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D088C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d08b0
	if (ctx.cr6.eq) goto loc_825D08B0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D08A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825c3430
	ctx.lr = 0x825D08B0;
	sub_825C3430(ctx, base);
loc_825D08B0:
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

DEFINE_REX_FUNC(sub_825D51F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x825D51F8;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r22,r4
	ctx.r22.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825d5338
	if (!ctx.cr6.eq) goto loc_825D5338;
loc_825D5224:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825d5310
	if (ctx.cr6.eq) goto loc_825D5310;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwsync 
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rldicr r9,r10,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// clrldi r10,r8,33
	ctx.r10.u64 = ctx.r8.u64 & 0x7FFFFFFF;
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_825D5254:
	// mfmsr r6
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r6.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r7,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u64 = *(uint64_t*)REX_RAW_ADDR(ea);
	ctx.r7.u64 = __builtin_bswap64(ctx.reserved.u64);
	// cmpd cr6,r7,r11
	ctx.cr6.compare<int64_t>(ctx.r7.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d5278
	if (!ctx.cr6.eq) goto loc_825D5278;
	// stdcx. r5,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r5.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d5254
	if (!ctx.cr0.eq) goto loc_825D5254;
	// b 0x825d5280
	goto loc_825D5280;
loc_825D5278:
	// stdcx. r7,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r7.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_825D5280:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// cmpd cr6,r7,r11
	ctx.cr6.compare<int64_t>(ctx.r7.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d5224
	if (!ctx.cr6.eq) goto loc_825D5224;
loc_825D528C:
	// li r11,0
	ctx.r11.s64 = 0;
	// std r22,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r22.u64);
	// addi r7,r31,8
	ctx.r7.s64 = ctx.r31.s64 + 8;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// clrlwi r11,r10,1
	ctx.r11.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
loc_825D52AC:
	// ld r10,0(r7)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r7.u32 + 0);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// ld r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r6.u32 + 0);
	// ld r9,0(r7)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r7.u32 + 0);
	// cmpd cr6,r10,r9
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r9.s64, ctx.xer);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bne cr6,0x825d52ac
	if (!ctx.cr6.eq) goto loc_825D52AC;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwsync 
	// bne cr6,0x825d5608
	if (!ctx.cr6.eq) goto loc_825D5608;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rldicr r9,r3,32,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u64, 32) & 0xFFFFFFFF00000000;
	// clrldi r8,r8,33
	ctx.r8.u64 = ctx.r8.u64 & 0x7FFFFFFF;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
loc_825D52EC:
	// mfmsr r4
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r4.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r5,0,r6
	ea = ctx.r6.u32;
	ctx.reserved.u64 = *(uint64_t*)REX_RAW_ADDR(ea);
	ctx.r5.u64 = __builtin_bswap64(ctx.reserved.u64);
	// cmpd cr6,r5,r11
	ctx.cr6.compare<int64_t>(ctx.r5.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d55c0
	if (!ctx.cr6.eq) goto loc_825D55C0;
	// stdcx. r8,0,r6
	ea = ctx.r6.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r8.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r4,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r4.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d52ec
	if (!ctx.cr0.eq) goto loc_825D52EC;
	// b 0x825d55c8
	goto loc_825D55C8;
loc_825D5310:
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825d532c
	if (ctx.cr6.eq) goto loc_825D532C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825d4408
	ctx.lr = 0x825D5324;
	sub_825D4408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825d528c
	if (!ctx.cr6.eq) goto loc_825D528C;
loc_825D532C:
	// li r3,258
	ctx.r3.s64 = 258;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_825D5338:
	// li r29,0
	ctx.r29.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r24,r31,24
	ctx.r24.s64 = ctx.r31.s64 + 24;
loc_825D5344:
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
	// bne 0x825d5344
	if (!ctx.cr0.eq) goto loc_825D5344;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x825d53d4
	if (ctx.cr6.lt) goto loc_825D53D4;
loc_825D5368:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825d53d4
	if (ctx.cr6.eq) goto loc_825D53D4;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwsync 
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rldicr r9,r10,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// clrldi r10,r8,33
	ctx.r10.u64 = ctx.r8.u64 & 0x7FFFFFFF;
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_825D5398:
	// mfmsr r6
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r6.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r7,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u64 = *(uint64_t*)REX_RAW_ADDR(ea);
	ctx.r7.u64 = __builtin_bswap64(ctx.reserved.u64);
	// cmpd cr6,r7,r11
	ctx.cr6.compare<int64_t>(ctx.r7.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d53bc
	if (!ctx.cr6.eq) goto loc_825D53BC;
	// stdcx. r5,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r5.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d5398
	if (!ctx.cr0.eq) goto loc_825D5398;
	// b 0x825d53c4
	goto loc_825D53C4;
loc_825D53BC:
	// stdcx. r7,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r7.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_825D53C4:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// cmpd cr6,r7,r11
	ctx.cr6.compare<int64_t>(ctx.r7.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d5368
	if (!ctx.cr6.eq) goto loc_825D5368;
	// b 0x825d528c
	goto loc_825D528C;
loc_825D53D4:
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825d53f0
	if (ctx.cr6.eq) goto loc_825D53F0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825d4408
	ctx.lr = 0x825D53E8;
	sub_825D4408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825d528c
	if (!ctx.cr6.eq) goto loc_825D528C;
loc_825D53F0:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq cr6,0x825d5498
	if (ctx.cr6.eq) goto loc_825D5498;
	// li r8,1000
	ctx.r8.s64 = 1000;
loc_825D53FC:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_825D5404:
	// db16cyc 
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x825d5404
	if (!ctx.cr0.lt) goto loc_825D5404;
	// cmpwi cr6,r29,511
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 511, ctx.xer);
	// bgt cr6,0x825d5420
	if (ctx.cr6.gt) goto loc_825D5420;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
loc_825D5420:
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
loc_825D5424:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825d5490
	if (ctx.cr6.eq) goto loc_825D5490;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwsync 
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// clrldi r9,r9,33
	ctx.r9.u64 = ctx.r9.u64 & 0x7FFFFFFF;
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_825D5454:
	// mfmsr r6
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r6.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r7,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u64 = *(uint64_t*)REX_RAW_ADDR(ea);
	ctx.r7.u64 = __builtin_bswap64(ctx.reserved.u64);
	// cmpd cr6,r7,r11
	ctx.cr6.compare<int64_t>(ctx.r7.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d5478
	if (!ctx.cr6.eq) goto loc_825D5478;
	// stdcx. r5,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r5.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d5454
	if (!ctx.cr0.eq) goto loc_825D5454;
	// b 0x825d5480
	goto loc_825D5480;
loc_825D5478:
	// stdcx. r7,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r7.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_825D5480:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// cmpd cr6,r7,r11
	ctx.cr6.compare<int64_t>(ctx.r7.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d5424
	if (!ctx.cr6.eq) goto loc_825D5424;
	// b 0x825d528c
	goto loc_825D528C;
loc_825D5490:
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x825d53fc
	if (!ctx.cr0.eq) goto loc_825D53FC;
loc_825D5498:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825d528c
	if (!ctx.cr6.eq) goto loc_825D528C;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
loc_825D54A4:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq cr6,0x825d54d4
	if (ctx.cr6.eq) goto loc_825D54D4;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_825D54B4:
	// db16cyc 
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x825d54b4
	if (!ctx.cr0.lt) goto loc_825D54B4;
	// cmpwi cr6,r29,511
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 511, ctx.xer);
	// bgt cr6,0x825d54d0
	if (ctx.cr6.gt) goto loc_825D54D0;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
loc_825D54D0:
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
loc_825D54D4:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x825d5510
	if (!ctx.cr6.eq) goto loc_825D5510;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x825d54f0
	if (!ctx.cr6.eq) goto loc_825D54F0;
	// li r3,258
	ctx.r3.s64 = 258;
	// b 0x825d5528
	goto loc_825D5528;
loc_825D54F0:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x8263d958
	ctx.lr = 0x825D54FC;
	sub_8263D958(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x825d5528
	if (!ctx.cr6.gt) goto loc_825D5528;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// or r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 | ctx.r30.u64;
	// b 0x825d5528
	goto loc_825D5528;
loc_825D5510:
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mtctr r26
	ctx.ctr.u64 = ctx.r26.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bctrl 
	ctx.lr = 0x825D5528;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825D5528:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825d559c
	if (!ctx.cr6.eq) goto loc_825D559C;
loc_825D5530:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825d54a4
	if (ctx.cr6.eq) goto loc_825D54A4;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwsync 
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// clrldi r9,r9,33
	ctx.r9.u64 = ctx.r9.u64 & 0x7FFFFFFF;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_825D5560:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r8,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u64 = *(uint64_t*)REX_RAW_ADDR(ea);
	ctx.r8.u64 = __builtin_bswap64(ctx.reserved.u64);
	// cmpd cr6,r8,r11
	ctx.cr6.compare<int64_t>(ctx.r8.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d5584
	if (!ctx.cr6.eq) goto loc_825D5584;
	// stdcx. r6,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r6.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d5560
	if (!ctx.cr0.eq) goto loc_825D5560;
	// b 0x825d558c
	goto loc_825D558C;
loc_825D5584:
	// stdcx. r8,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r8.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_825D558C:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// cmpd cr6,r8,r11
	ctx.cr6.compare<int64_t>(ctx.r8.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d5530
	if (!ctx.cr6.eq) goto loc_825D5530;
	// b 0x825d528c
	goto loc_825D528C;
loc_825D559C:
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
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
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
	// bne 0x825d559c
	if (!ctx.cr0.eq) goto loc_825D559C;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_825D55C0:
	// stdcx. r5,0,r6
	ea = ctx.r6.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r5.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r4,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r4.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_825D55C8:
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// cmpd cr6,r5,r11
	ctx.cr6.compare<int64_t>(ctx.r5.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825d52ac
	if (!ctx.cr6.eq) goto loc_825D52AC;
	// lwsync 
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// clrldi r11,r11,33
	ctx.r11.u64 = ctx.r11.u64 & 0x7FFFFFFF;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_825D55E4:
	// mfmsr r6
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r6.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r8,0,r7
	ea = ctx.r7.u32;
	ctx.reserved.u64 = *(uint64_t*)REX_RAW_ADDR(ea);
	ctx.r8.u64 = __builtin_bswap64(ctx.reserved.u64);
	// cmpd cr6,r8,r10
	ctx.cr6.compare<int64_t>(ctx.r8.s64, ctx.r10.s64, ctx.xer);
	// bne cr6,0x825d5648
	if (!ctx.cr6.eq) goto loc_825D5648;
	// stdcx. r5,0,r7
	ea = ctx.r7.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r5.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d55e4
	if (!ctx.cr0.eq) goto loc_825D55E4;
	// b 0x825d5650
	goto loc_825D5650;
loc_825D5608:
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rldicr r11,r9,32,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF00000000;
	// clrldi r9,r8,33
	ctx.r9.u64 = ctx.r8.u64 & 0x7FFFFFFF;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_825D5618:
	// mfmsr r5
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r5.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r6,0,r7
	ea = ctx.r7.u32;
	ctx.reserved.u64 = *(uint64_t*)REX_RAW_ADDR(ea);
	ctx.r6.u64 = __builtin_bswap64(ctx.reserved.u64);
	// cmpd cr6,r6,r10
	ctx.cr6.compare<int64_t>(ctx.r6.s64, ctx.r10.s64, ctx.xer);
	// bne cr6,0x825d563c
	if (!ctx.cr6.eq) goto loc_825D563C;
	// stdcx. r4,0,r7
	ea = ctx.r7.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r4.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r5,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r5.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825d5618
	if (!ctx.cr0.eq) goto loc_825D5618;
	// b 0x825d52ac
	goto loc_825D52AC;
loc_825D563C:
	// stdcx. r6,0,r7
	ea = ctx.r7.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r6.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r5,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r5.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// b 0x825d52ac
	goto loc_825D52AC;
loc_825D5648:
	// stdcx. r8,0,r7
	ea = ctx.r7.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r8.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_825D5650:
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d5680
	if (ctx.cr6.eq) goto loc_825D5680;
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x825d5680
	if (!ctx.cr6.gt) goto loc_825D5680;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82748970
	ctx.lr = 0x825D5674;
	sub_82748970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825d5680
	if (!ctx.cr6.eq) goto loc_825D5680;
	// bl 0x82639f50
	ctx.lr = 0x825D5680;
	sub_82639F50(ctx, base);
loc_825D5680:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FE698) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,-15400
	ctx.r30.s64 = ctx.r11.s64 + -15400;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x825FE6C0;
	sub_825F8ED0(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825fe6e4
	if (ctx.cr6.eq) goto loc_825FE6E4;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r31,5,12,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 5) & 0xFFFE0;
	// lwz r11,-15412(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15412);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x825fe720
	if (ctx.cr6.eq) goto loc_825FE720;
loc_825FE6E4:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_825FE6E8:
	// lwsync 
	// li r11,0
	ctx.r11.s64 = 0;
loc_825FE6F0:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r30
	ea = ctx.r30.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r30
	ea = ctx.r30.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825fe6f0
	if (!ctx.cr0.eq) goto loc_825FE6F0;
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
loc_825FE720:
	// addi r3,r11,28
	ctx.r3.s64 = ctx.r11.s64 + 28;
	// bl 0x825f8f28
	ctx.lr = 0x825FE728;
	sub_825F8F28(ctx, base);
	// b 0x825fe6e8
	goto loc_825FE6E8;
}

DEFINE_REX_FUNC(sub_826055E0) {
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
	// bl 0x82605828
	ctx.lr = 0x826055F0;
	sub_82605828(ctx, base);
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// ori r10,r10,43872
	ctx.r10.u64 = ctx.r10.u64 | 43872;
	// cmpw cr6,r3,r10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x82605718
	if (ctx.cr6.gt) goto loc_82605718;
	// beq cr6,0x82605710
	if (ctx.cr6.eq) goto loc_82605710;
	// lis r10,6184
	ctx.r10.s64 = 405274624;
	// ori r3,r10,390
	ctx.r3.u64 = ctx.r10.u64 | 390;
	// cmpw cr6,r11,r3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r3.s32, ctx.xer);
	// bgt cr6,0x8260569c
	if (ctx.cr6.gt) goto loc_8260569C;
	// beq cr6,0x82605814
	if (ctx.cr6.eq) goto loc_82605814;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82605690
	if (ctx.cr6.eq) goto loc_82605690;
	// lis r10,1168
	ctx.r10.s64 = 76546048;
	// ori r3,r10,258
	ctx.r3.u64 = ctx.r10.u64 | 258;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x82605814
	if (ctx.cr6.eq) goto loc_82605814;
	// lis r10,2048
	ctx.r10.s64 = 134217728;
	// ori r3,r10,330
	ctx.r3.u64 = ctx.r10.u64 | 330;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x82605814
	if (ctx.cr6.eq) goto loc_82605814;
	// lis r10,6184
	ctx.r10.s64 = 405274624;
	// ori r3,r10,262
	ctx.r3.u64 = ctx.r10.u64 | 262;
	// subf. r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82605814
	if (ctx.cr0.eq) goto loc_82605814;
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// beq cr6,0x82605684
	if (ctx.cr6.eq) goto loc_82605684;
	// cmplwi cr6,r11,61
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 61, ctx.xer);
	// beq cr6,0x82605678
	if (ctx.cr6.eq) goto loc_82605678;
	// cmplwi cr6,r11,73
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 73, ctx.xer);
	// bne cr6,0x82605690
	if (!ctx.cr6.eq) goto loc_82605690;
	// lis r3,6184
	ctx.r3.s64 = 405274624;
	// ori r3,r3,335
	ctx.r3.u64 = ctx.r3.u64 | 335;
	// b 0x82605814
	goto loc_82605814;
loc_82605678:
	// lis r3,6184
	ctx.r3.s64 = 405274624;
	// ori r3,r3,323
	ctx.r3.u64 = ctx.r3.u64 | 323;
	// b 0x82605814
	goto loc_82605814;
loc_82605684:
	// lis r3,6184
	ctx.r3.s64 = 405274624;
loc_82605688:
	// ori r3,r3,310
	ctx.r3.u64 = ctx.r3.u64 | 310;
	// b 0x82605814
	goto loc_82605814;
loc_82605690:
	// lis r3,32767
	ctx.r3.s64 = 2147418112;
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
	// b 0x82605814
	goto loc_82605814;
loc_8260569C:
	// lis r10,6688
	ctx.r10.s64 = 438304768;
	// ori r3,r10,338
	ctx.r3.u64 = ctx.r10.u64 | 338;
	// subf. r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82605814
	if (ctx.cr0.eq) goto loc_82605814;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82605704
	if (ctx.cr6.eq) goto loc_82605704;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x826056f8
	if (ctx.cr6.eq) goto loc_826056F8;
	// addis r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -131072;
	// addic. r11,r11,-6
	ctx.xer.ca = ctx.r11.u32 > 5;
	ctx.r11.s64 = ctx.r11.s64 + -6;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826056f0
	if (ctx.cr0.eq) goto loc_826056F0;
	// cmplwi cr6,r11,63
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 63, ctx.xer);
	// beq cr6,0x826056e4
	if (ctx.cr6.eq) goto loc_826056E4;
	// cmplwi cr6,r11,43525
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 43525, ctx.xer);
	// bne cr6,0x82605690
	if (!ctx.cr6.eq) goto loc_82605690;
	// lis r3,6690
	ctx.r3.s64 = 438435840;
	// ori r3,r3,43869
	ctx.r3.u64 = ctx.r3.u64 | 43869;
	// b 0x82605814
	goto loc_82605814;
loc_826056E4:
	// lis r3,6690
	ctx.r3.s64 = 438435840;
	// ori r3,r3,407
	ctx.r3.u64 = ctx.r3.u64 | 407;
	// b 0x82605814
	goto loc_82605814;
loc_826056F0:
	// lis r3,6690
	ctx.r3.s64 = 438435840;
	// b 0x82605794
	goto loc_82605794;
loc_826056F8:
	// lis r3,6688
	ctx.r3.s64 = 438304768;
	// ori r3,r3,340
	ctx.r3.u64 = ctx.r3.u64 | 340;
	// b 0x82605814
	goto loc_82605814;
loc_82605704:
	// lis r3,6688
	ctx.r3.s64 = 438304768;
	// ori r3,r3,339
	ctx.r3.u64 = ctx.r3.u64 | 339;
	// b 0x82605814
	goto loc_82605814;
loc_82605710:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x82605814
	goto loc_82605814;
loc_82605718:
	// lis r10,10280
	ctx.r10.s64 = 673710080;
	// ori r3,r10,390
	ctx.r3.u64 = ctx.r10.u64 | 390;
	// cmpw cr6,r11,r3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r3.s32, ctx.xer);
	// bgt cr6,0x8260579c
	if (ctx.cr6.gt) goto loc_8260579C;
	// beq cr6,0x82605814
	if (ctx.cr6.eq) goto loc_82605814;
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// ori r3,r10,43942
	ctx.r3.u64 = ctx.r10.u64 | 43942;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x82605814
	if (ctx.cr6.eq) goto loc_82605814;
	// lis r10,10240
	ctx.r10.s64 = 671088640;
	// ori r3,r10,258
	ctx.r3.u64 = ctx.r10.u64 | 258;
	// subf. r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82605814
	if (ctx.cr0.eq) goto loc_82605814;
	// cmplwi cr6,r11,86
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 86, ctx.xer);
	// beq cr6,0x82605790
	if (ctx.cr6.eq) goto loc_82605790;
	// addis r11,r11,-40
	ctx.r11.s64 = ctx.r11.s64 + -2621440;
	// addic. r11,r11,-4
	ctx.xer.ca = ctx.r11.u32 > 3;
	ctx.r11.s64 = ctx.r11.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82605784
	if (ctx.cr0.eq) goto loc_82605784;
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// beq cr6,0x8260577c
	if (ctx.cr6.eq) goto loc_8260577C;
	// cmplwi cr6,r11,62
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 62, ctx.xer);
	// bne cr6,0x82605690
	if (!ctx.cr6.eq) goto loc_82605690;
	// lis r3,10280
	ctx.r3.s64 = 673710080;
	// ori r3,r3,324
	ctx.r3.u64 = ctx.r3.u64 | 324;
	// b 0x82605814
	goto loc_82605814;
loc_8260577C:
	// lis r3,10280
	ctx.r3.s64 = 673710080;
	// b 0x82605688
	goto loc_82605688;
loc_82605784:
	// lis r3,10280
	ctx.r3.s64 = 673710080;
	// ori r3,r3,262
	ctx.r3.u64 = ctx.r3.u64 | 262;
	// b 0x82605814
	goto loc_82605814;
loc_82605790:
	// lis r3,10240
	ctx.r3.s64 = 671088640;
loc_82605794:
	// ori r3,r3,344
	ctx.r3.u64 = ctx.r3.u64 | 344;
	// b 0x82605814
	goto loc_82605814;
loc_8260579C:
	// lis r10,11552
	ctx.r10.s64 = 757071872;
	// ori r3,r10,406
	ctx.r3.u64 = ctx.r10.u64 | 406;
	// subf. r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82605814
	if (ctx.cr0.eq) goto loc_82605814;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8260580c
	if (ctx.cr6.eq) goto loc_8260580C;
	// addis r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -196608;
	// addic. r11,r11,22010
	ctx.xer.ca = ctx.r11.u32 > 4294945285;
	ctx.r11.s64 = ctx.r11.s64 + 22010;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82605800
	if (ctx.cr0.eq) goto loc_82605800;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x826057f4
	if (ctx.cr6.eq) goto loc_826057F4;
	// addis r11,r11,-128
	ctx.r11.s64 = ctx.r11.s64 + -8388608;
	// addic. r11,r11,65
	ctx.xer.ca = ctx.r11.u32 > 4294967230;
	ctx.r11.s64 = ctx.r11.s64 + 65;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826057e8
	if (ctx.cr0.eq) goto loc_826057E8;
	// cmplwi cr6,r11,73
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 73, ctx.xer);
	// bne cr6,0x82605690
	if (!ctx.cr6.eq) goto loc_82605690;
	// lis r3,11682
	ctx.r3.s64 = 765591552;
	// ori r3,r3,43940
	ctx.r3.u64 = ctx.r3.u64 | 43940;
	// b 0x82605814
	goto loc_82605814;
loc_826057E8:
	// lis r3,11682
	ctx.r3.s64 = 765591552;
	// ori r3,r3,43867
	ctx.r3.u64 = ctx.r3.u64 | 43867;
	// b 0x82605814
	goto loc_82605814;
loc_826057F4:
	// lis r3,11554
	ctx.r3.s64 = 757202944;
	// ori r3,r3,43935
	ctx.r3.u64 = ctx.r3.u64 | 43935;
	// b 0x82605814
	goto loc_82605814;
loc_82605800:
	// lis r3,11554
	ctx.r3.s64 = 757202944;
	// ori r3,r3,43932
	ctx.r3.u64 = ctx.r3.u64 | 43932;
	// b 0x82605814
	goto loc_82605814;
loc_8260580C:
	// lis r3,11552
	ctx.r3.s64 = 757071872;
	// ori r3,r3,409
	ctx.r3.u64 = ctx.r3.u64 | 409;
loc_82605814:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826159D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x826159D8;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,16
	ctx.r11.s64 = 16;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r10,r3,360
	ctx.r10.s64 = ctx.r3.s64 + 360;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r28,436(r3)
	REX_STORE_U32(ctx.r3.u32 + 436, ctx.r28.u32);
	// addi r31,r3,436
	ctx.r31.s64 = ctx.r3.s64 + 436;
	// stw r28,440(r3)
	REX_STORE_U32(ctx.r3.u32 + 440, ctx.r28.u32);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// stw r28,444(r3)
	REX_STORE_U32(ctx.r3.u32 + 444, ctx.r28.u32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r28,448(r3)
	REX_STORE_U32(ctx.r3.u32 + 448, ctx.r28.u32);
loc_82615A0C:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82615a0c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82615A0C;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r28,352(r29)
	REX_STORE_U32(ctx.r29.u32 + 352, ctx.r28.u32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stw r28,356(r29)
	REX_STORE_U32(ctx.r29.u32 + 356, ctx.r28.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stw r28,424(r29)
	REX_STORE_U32(ctx.r29.u32 + 424, ctx.r28.u32);
	// stw r28,428(r29)
	REX_STORE_U32(ctx.r29.u32 + 428, ctx.r28.u32);
	// lis r23,-32112
	ctx.r23.s64 = -2104492032;
	// stw r28,432(r29)
	REX_STORE_U32(ctx.r29.u32 + 432, ctx.r28.u32);
	// lis r25,-32112
	ctx.r25.s64 = -2104492032;
	// stw r28,336(r29)
	REX_STORE_U32(ctx.r29.u32 + 336, ctx.r28.u32);
	// addi r24,r10,-11520
	ctx.r24.s64 = ctx.r10.s64 + -11520;
	// addi r27,r9,-11504
	ctx.r27.s64 = ctx.r9.s64 + -11504;
	// addi r26,r11,-11524
	ctx.r26.s64 = ctx.r11.s64 + -11524;
loc_82615A4C:
	// lwsync 
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
loc_82615A54:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r11,0,r8
	ea = ctx.r8.u32;
	ctx.reserved.u64 = *(uint64_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap64(ctx.reserved.u64);
	// add r10,r28,r11
	ctx.r10.u64 = ctx.r28.u64 + ctx.r11.u64;
	// stdcx. r10,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r10.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82615a54
	if (!ctx.cr0.eq) goto loc_82615A54;
	// mr r11,r11
	ctx.r11.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82615a94
	if (ctx.cr6.eq) goto loc_82615A94;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82615a98
	if (ctx.cr6.eq) goto loc_82615A98;
loc_82615A94:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_82615A98:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82615b48
	if (!ctx.cr0.eq) goto loc_82615B48;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x826158b8
	ctx.lr = 0x82615AA8;
	sub_826158B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82615ab8
	if (!ctx.cr0.eq) goto loc_82615AB8;
	// bl 0x82749140
	ctx.lr = 0x82615AB4;
	sub_82749140(ctx, base);
	// b 0x82615a4c
	goto loc_82615A4C;
loc_82615AB8:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82615acc
	if (!ctx.cr6.eq) goto loc_82615ACC;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// b 0x82615ad8
	goto loc_82615AD8;
loc_82615ACC:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
loc_82615AD8:
	// lwz r9,448(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 448);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r30,92(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r5,96(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// subfic r8,r30,0
	ctx.xer.ca = ctx.r30.u32 <= 0;
	ctx.r8.u64 = static_cast<uint64_t>(0) - ctx.r30.u64;
	// addi r7,r30,4
	ctx.r7.s64 = ctx.r30.s64 + 4;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// subfe r9,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// and r4,r9,r7
	ctx.r4.u64 = ctx.r9.u64 & ctx.r7.u64;
	// bl 0x825fca40
	ctx.lr = 0x82615B08;
	sub_825FCA40(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82615B20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,79
	ctx.r10.s64 = 79;
	// li r9,4
	ctx.r9.s64 = 4;
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// sth r9,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r9.u16);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x82615a4c
	goto loc_82615A4C;
loc_82615B48:
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
loc_82615B4C:
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
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
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
	// bne 0x82615b4c
	if (!ctx.cr0.eq) goto loc_82615B4C;
	// lwsync 
	// lwz r3,-11508(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + -11508);
	// bl 0x82748898
	ctx.lr = 0x82615B74;
	sub_82748898(ctx, base);
loc_82615B74:
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,-11512(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + -11512);
	// bl 0x8263b630
	ctx.lr = 0x82615B80;
	sub_8263B630(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82615b74
	if (!ctx.cr0.eq) goto loc_82615B74;
	// lwsync 
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
loc_82615B90:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r8
	ea = ctx.r8.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r10,r28,r11
	ctx.r10.u64 = ctx.r28.u64 + ctx.r11.u64;
	// stwcx. r10,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82615b90
	if (!ctx.cr0.eq) goto loc_82615B90;
	// mr r11,r11
	ctx.r11.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82615a4c
	if (ctx.cr6.eq) goto loc_82615A4C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r11,r11,-11500
	ctx.r11.s64 = ctx.r11.s64 + -11500;
loc_82615BC0:
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
	// bne 0x82615bc0
	if (!ctx.cr0.eq) goto loc_82615BC0;
	// lwsync 
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82627170) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r5,48(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r7,15128(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 15128);
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// lwz r10,10896(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 10896);
	// li r3,32767
	ctx.r3.s64 = 32767;
	// ori r6,r9,15104
	ctx.r6.u64 = ctx.r9.u64 | 15104;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// lwz r8,10908(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 10908);
	// lis r31,-16382
	ctx.r31.s64 = -1073610752;
	// stw r7,13420(r11)
	REX_STORE_U32(ctx.r11.u32 + 13420, ctx.r7.u32);
	// li r30,3
	ctx.r30.s64 = 3;
	// stw r5,13416(r11)
	REX_STORE_U32(ctx.r11.u32 + 13416, ctx.r5.u32);
	// ori r31,r31,22528
	ctx.r31.u64 = ctx.r31.u64 | 22528;
	// stwu r6,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r6.u32);
	ctx.r4.u32 = ea;
	// rlwinm r6,r9,12,20,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// addi r6,r6,512
	ctx.r6.s64 = ctx.r6.s64 + 512;
	// clrlwi r7,r7,30
	ctx.r7.u64 = ctx.r7.u32 & 0x3;
	// rlwinm r6,r6,0,19,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x1000;
	// stwu r3,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r4.u32 = ea;
	// or r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 | ctx.r5.u64;
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lis r5,-16382
	ctx.r5.s64 = -1073610752;
	// ori r6,r9,2
	ctx.r6.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r31,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r31.u32);
	ctx.r4.u32 = ea;
	// ori r5,r5,22528
	ctx.r5.u64 = ctx.r5.u64 | 22528;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// li r3,3
	ctx.r3.s64 = 3;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r30,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r4.u32 = ea;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// stwu r6,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r6.u32);
	ctx.r4.u32 = ea;
	// stwu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r4.u32 = ea;
	// stwu r5,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r5.u32);
	ctx.r4.u32 = ea;
	// stwu r3,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r4.u32 = ea;
	// stwu r10,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r4.u32 = ea;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// lwz r10,21740(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 21740);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82627248
	if (!ctx.cr6.eq) goto loc_82627248;
	// lbz r10,10941(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 10941);
	// rlwinm. r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82627248
	if (ctx.cr0.eq) goto loc_82627248;
	// lwz r10,10896(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 10896);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r10,10896(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 10896);
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
loc_82627248:
	// addi r10,r8,2
	ctx.r10.s64 = ctx.r8.s64 + 2;
	// stw r10,10908(r11)
	REX_STORE_U32(ctx.r11.u32 + 10908, ctx.r10.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8262FCF8) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82855fc4
	ctx.lr = 0x8262FD0C;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,2252(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2252);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8262fd44
	if (ctx.cr6.eq) goto loc_8262FD44;
	// lwz r10,24200(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24200);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8262fd44
	if (ctx.cr6.eq) goto loc_8262FD44;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,24196(r11)
	REX_STORE_U32(ctx.r11.u32 + 24196, ctx.r10.u32);
	// lwsync 
	// lwz r11,24200(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24200);
	// li r10,-1
	ctx.r10.s64 = -1;
	// std r10,544(r11)
	REX_STORE_U64(ctx.r11.u32 + 544, ctx.r10.u64);
loc_8262FD44:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82631E40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82631E48;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,10941(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 10941);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82631e6c
	if (!ctx.cr0.eq) goto loc_82631E6C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x82626f78
	ctx.lr = 0x82631E6C;
	sub_82626F78(ctx, base);
loc_82631E6C:
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,148
	ctx.r4.s64 = 148;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82626840
	ctx.lr = 0x82631E7C;
	sub_82626840(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82626840
	ctx.lr = 0x82631E90;
	sub_82626840(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82626840
	ctx.lr = 0x82631EA4;
	sub_82626840(ctx, base);
	// lbz r11,10941(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// li r7,0
	ctx.r7.s64 = 0;
	// rlwinm. r24,r11,27,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// stw r7,13408(r31)
	REX_STORE_U32(ctx.r31.u32 + 13408, ctx.r7.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r7,13412(r31)
	REX_STORE_U32(ctx.r31.u32 + 13412, ctx.r7.u32);
	// beq 0x82631f0c
	if (ctx.cr0.eq) goto loc_82631F0C;
	// lwz r10,13616(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 13616);
	// andi. r9,r11,223
	ctx.r9.u64 = ctx.r11.u64 & 223;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// addi r11,r31,13616
	ctx.r11.s64 = ctx.r31.s64 + 13616;
	// lwz r11,13620(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13620);
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// lwz r11,13624(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13624);
	// stw r11,15136(r31)
	REX_STORE_U32(ctx.r31.u32 + 15136, ctx.r11.u32);
	// lwz r11,13628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13628);
	// stw r11,15132(r31)
	REX_STORE_U32(ctx.r31.u32 + 15132, ctx.r11.u32);
	// lwz r11,13632(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13632);
	// stw r11,15124(r31)
	REX_STORE_U32(ctx.r31.u32 + 15124, ctx.r11.u32);
	// lwz r11,13636(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13636);
	// stw r11,15128(r31)
	REX_STORE_U32(ctx.r31.u32 + 15128, ctx.r11.u32);
	// lwz r11,13620(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13620);
	// addi r11,r11,-160
	ctx.r11.s64 = ctx.r11.s64 + -160;
	// stb r9,10941(r31)
	REX_STORE_U8(ctx.r31.u32 + 10941, ctx.r9.u8);
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// b 0x8263203c
	goto loc_8263203C;
loc_82631F0C:
	// addi r25,r31,13568
	ctx.r25.s64 = ctx.r31.s64 + 13568;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x826262c8
	ctx.lr = 0x82631F18;
	sub_826262C8(ctx, base);
	// addi r3,r31,13424
	ctx.r3.s64 = ctx.r31.s64 + 13424;
	// bl 0x826262c8
	ctx.lr = 0x82631F20;
	sub_826262C8(ctx, base);
	// addi r3,r31,13544
	ctx.r3.s64 = ctx.r31.s64 + 13544;
	// bl 0x826262c8
	ctx.lr = 0x82631F28;
	sub_826262C8(ctx, base);
	// addi r3,r31,13448
	ctx.r3.s64 = ctx.r31.s64 + 13448;
	// bl 0x826262c8
	ctx.lr = 0x82631F30;
	sub_826262C8(ctx, base);
	// addi r3,r31,13472
	ctx.r3.s64 = ctx.r31.s64 + 13472;
	// bl 0x826262c8
	ctx.lr = 0x82631F38;
	sub_826262C8(ctx, base);
	// addi r3,r31,13496
	ctx.r3.s64 = ctx.r31.s64 + 13496;
	// bl 0x826262c8
	ctx.lr = 0x82631F40;
	sub_826262C8(ctx, base);
	// addi r3,r31,13520
	ctx.r3.s64 = ctx.r31.s64 + 13520;
	// bl 0x826262c8
	ctx.lr = 0x82631F48;
	sub_826262C8(ctx, base);
	// lwz r11,13568(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13568);
	// addi r4,r28,-4
	ctx.r4.s64 = ctx.r28.s64 + -4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82631f70
	if (ctx.cr6.eq) goto loc_82631F70;
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	ctx.r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addis r7,r11,-16384
	ctx.r7.s64 = ctx.r11.s64 + -1073741824;
loc_82631F70:
	// lis r11,-32157
	ctx.r11.s64 = -2107441152;
	// ori r5,r27,1
	ctx.r5.u64 = ctx.r27.u64 | 1;
	// addi r6,r11,7096
	ctx.r6.s64 = ctx.r11.s64 + 7096;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826276b8
	ctx.lr = 0x82631F84;
	sub_826276B8(ctx, base);
	// addi r27,r3,4
	ctx.r27.s64 = ctx.r3.s64 + 4;
	// addi r4,r30,-4
	ctx.r4.s64 = ctx.r30.s64 + -4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82627170
	ctx.lr = 0x82631F94;
	sub_82627170(ctx, base);
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r26,r3,4
	ctx.r26.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82631fc0
	if (ctx.cr6.eq) goto loc_82631FC0;
	// addi r8,r31,13592
	ctx.r8.s64 = ctx.r31.s64 + 13592;
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826273e8
	ctx.lr = 0x82631FBC;
	sub_826273E8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_82631FC0:
	// lwz r11,21740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21740);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82631fd8
	if (!ctx.cr6.eq) goto loc_82631FD8;
	// lbz r11,10941(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8263200c
	if (!ctx.cr0.eq) goto loc_8263200C;
loc_82631FD8:
	// rlwinm r11,r28,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r28,3
	ctx.r10.u64 = ctx.r28.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// subf r9,r28,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r28.u64;
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// addi r8,r31,13592
	ctx.r8.s64 = ctx.r31.s64 + 13592;
	// li r7,1
	ctx.r7.s64 = 1;
	// srawi r6,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 2;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826273e8
	ctx.lr = 0x82632008;
	sub_826273E8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_8263200C:
	// rlwinm r11,r30,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r30,3
	ctx.r10.u64 = ctx.r30.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// subf r9,r30,r26
	ctx.r9.u64 = ctx.r26.u64 - ctx.r30.u64;
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// srawi r6,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 2;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826273e8
	ctx.lr = 0x8263203C;
	sub_826273E8(ctx, base);
loc_8263203C:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82641110) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-320
	ctx.r31.s64 = ctx.r12.s64 + -320;
	// std r21,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r21.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8264113c
	if (ctx.cr6.eq) goto loc_8264113C;
	// lwz r3,1408(r21)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + 1408);
	// bl 0x82855b34
	ctx.lr = 0x8264113C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8264113C:
	// lwz r1,0(r1)
	ctx.r1.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// ld r21,-16(r1)
	ctx.r21.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82642770) {
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
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// addi r30,r3,44
	ctx.r30.s64 = ctx.r3.s64 + 44;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826427A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826427B4;
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

DEFINE_REX_FUNC(sub_82643C68) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82643c9c
	if (ctx.cr6.eq) goto loc_82643C9C;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
	// b 0x82643cf8
	goto loc_82643CF8;
loc_82643C9C:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,48
	ctx.r5.s64 = 48;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x8273a590
	ctx.lr = 0x82643CB4;
	sub_8273A590(ctx, base);
	// lis r11,-32156
	ctx.r11.s64 = -2107375616;
	// lis r10,-32155
	ctx.r10.s64 = -2107310080;
	// stw r30,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r30.u32);
	// li r9,52
	ctx.r9.s64 = 52;
	// stw r31,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r31.u32);
	// addi r11,r11,11184
	ctx.r11.s64 = ctx.r11.s64 + 11184;
	// addi r10,r10,-11136
	ctx.r10.s64 = ctx.r10.s64 + -11136;
	// stw r9,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825d5b40
	ctx.lr = 0x82643CE8;
	sub_825D5B40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82643cf8
	if (ctx.cr0.lt) goto loc_82643CF8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_82643CF8:
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

DEFINE_REX_FUNC(sub_82647B88) {
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
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x826543d0
	ctx.lr = 0x82647BB4;
	sub_826543D0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f0,5864(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5864);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r8,6184
	ctx.r10.s64 = ctx.r8.s64 + 6184;
	// addi r9,r9,6056
	ctx.r9.s64 = ctx.r9.s64 + 6056;
	// stfs f0,156(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 156, temp.u32);
	// addi r8,r7,6020
	ctx.r8.s64 = ctx.r7.s64 + 6020;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r8.u32);
	// stw r11,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// stw r11,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// stw r11,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// sth r11,172(r31)
	REX_STORE_U16(ctx.r31.u32 + 172, ctx.r11.u16);
	// stw r11,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_8264AEC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8264AED0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82646800
	ctx.lr = 0x8264AEDC;
	sub_82646800(ctx, base);
	// lwz r3,280(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 280);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8264aef4
	if (ctx.cr6.eq) goto loc_8264AEF4;
	// bl 0x826461c0
	ctx.lr = 0x8264AEF0;
	sub_826461C0(ctx, base);
	// stw r29,280(r30)
	REX_STORE_U32(ctx.r30.u32 + 280, ctx.r29.u32);
loc_8264AEF4:
	// lwz r4,184(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8264af44
	if (ctx.cr6.eq) goto loc_8264AF44;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwz r9,16244(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16244);
loc_8264AF08:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8264af20
	if (ctx.cr6.eq) goto loc_8264AF20;
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8264af24
	goto loc_8264AF24;
loc_8264AF20:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_8264AF24:
	// lwz r11,252(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 252);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8264af08
	if (ctx.cr6.lt) goto loc_8264AF08;
	// lwz r10,256(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 256);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8264af08
	if (!ctx.cr6.lt) goto loc_8264AF08;
	// bl 0x8264ab38
	ctx.lr = 0x8264AF44;
	sub_8264AB38(ctx, base);
loc_8264AF44:
	// addi r31,r30,300
	ctx.r31.s64 = ctx.r30.s64 + 300;
	// b 0x8264af58
	goto loc_8264AF58;
loc_8264AF4C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8264af58
	if (ctx.cr6.eq) goto loc_8264AF58;
	// bl 0x8264cf40
	ctx.lr = 0x8264AF58;
	sub_8264CF40(ctx, base);
loc_8264AF58:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82647fb8
	ctx.lr = 0x8264AF60;
	sub_82647FB8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8264af4c
	if (!ctx.cr0.eq) goto loc_8264AF4C;
	// addi r31,r30,204
	ctx.r31.s64 = ctx.r30.s64 + 204;
	// b 0x8264af7c
	goto loc_8264AF7C;
loc_8264AF70:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8264af7c
	if (ctx.cr6.eq) goto loc_8264AF7C;
	// bl 0x8264cf40
	ctx.lr = 0x8264AF7C;
	sub_8264CF40(ctx, base);
loc_8264AF7C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82647fb8
	ctx.lr = 0x8264AF84;
	sub_82647FB8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8264af70
	if (!ctx.cr0.eq) goto loc_8264AF70;
	// lwz r3,288(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 288);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8264afa0
	if (ctx.cr6.eq) goto loc_8264AFA0;
	// bl 0x8264cf40
	ctx.lr = 0x8264AF9C;
	sub_8264CF40(ctx, base);
	// stw r29,288(r30)
	REX_STORE_U32(ctx.r30.u32 + 288, ctx.r29.u32);
loc_8264AFA0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264F8E8) {
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
	// lwz r3,44(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8264f918
	if (ctx.cr6.eq) goto loc_8264F918;
	// bl 0x8264cf40
	ctx.lr = 0x8264F914;
	sub_8264CF40(ctx, base);
	// stw r30,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
loc_8264F918:
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8264f92c
	if (ctx.cr6.eq) goto loc_8264F92C;
	// bl 0x8264cf40
	ctx.lr = 0x8264F928;
	sub_8264CF40(ctx, base);
	// stw r30,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
loc_8264F92C:
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,36
	ctx.r3.s64 = ctx.r31.s64 + 36;
	// bl 0x8273a590
	ctx.lr = 0x8264F93C;
	sub_8273A590(ctx, base);
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// addi r3,r31,72
	ctx.r3.s64 = ctx.r31.s64 + 72;
	// stw r30,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// stw r30,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// bl 0x8273a590
	ctx.lr = 0x8264F958;
	sub_8273A590(ctx, base);
	// stw r30,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// stw r30,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
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

DEFINE_REX_FUNC(sub_82653EF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82653EF8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82653F2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x826533e8
	ctx.lr = 0x82653F44;
	sub_826533E8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82653a40
	ctx.lr = 0x82653F50;
	sub_82653A40(ctx, base);
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
	ctx.lr = 0x82653F68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265CFF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee4
	ctx.lr = 0x8265CFF8;
	__savegprlr_15(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,92(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 92);
	// mr r21,r5
	ctx.r21.u64 = ctx.r5.u64;
	// lwz r28,108(r5)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r5.u32 + 108);
	// mr r17,r3
	ctx.r17.u64 = ctx.r3.u64;
	// lwz r29,112(r5)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r5.u32 + 112);
	// mr r16,r4
	ctx.r16.u64 = ctx.r4.u64;
	// lwz r19,4(r7)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// lhz r31,2(r7)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r7.u32 + 2);
	// li r23,2
	ctx.r23.s64 = 2;
	// lwz r24,28(r7)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r7.u32 + 28);
	// li r22,0
	ctx.r22.s64 = 0;
	// lwz r25,32(r7)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r7.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r20,36(r7)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// lwz r27,40(r7)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r7.u32 + 40);
	// lwz r5,24(r7)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + 24);
	// lwz r18,44(r7)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r7.u32 + 44);
	// bne cr6,0x8265d05c
	if (!ctx.cr6.eq) goto loc_8265D05C;
	// lwz r11,84(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265d05c
	if (!ctx.cr6.eq) goto loc_8265D05C;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x8265d6c0
	if (ctx.cr6.eq) goto loc_8265D6C0;
loc_8265D05C:
	// li r15,8
	ctx.r15.s64 = 8;
	// cmplwi cr6,r17,2
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 2, ctx.xer);
	// bgt cr6,0x8265d0c4
	if (ctx.cr6.gt) goto loc_8265D0C4;
	// lhz r8,20(r26)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r26.u32 + 20);
	// rlwinm r10,r8,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8265d0bc
	if (ctx.cr6.eq) goto loc_8265D0BC;
	// rlwinm r10,r8,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8265d0bc
	if (ctx.cr6.eq) goto loc_8265D0BC;
	// mr r7,r17
	ctx.r7.u64 = ctx.r17.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// rlwinm r30,r8,29,30,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x3;
	// bl 0x8265cee0
	ctx.lr = 0x8265D0A0;
	sub_8265CEE0(ctx, base);
	// divwu r11,r3,r31
	ctx.r11.u64 = uint32_t(ctx.r31.u32 ? ctx.r3.u32 / ctx.r31.u32 : 0);
	// cmplwi cr6,r11,4000
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4000, ctx.xer);
	// blt cr6,0x8265d0b4
	if (ctx.cr6.lt) goto loc_8265D0B4;
	// slw r31,r15,r30
	ctx.r31.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r15.u32 << (ctx.r30.u8 & 0x3F));
	// b 0x8265d118
	goto loc_8265D118;
loc_8265D0B4:
	// slw r31,r23,r30
	ctx.r31.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r23.u32 << (ctx.r30.u8 & 0x3F));
	// b 0x8265d118
	goto loc_8265D118;
loc_8265D0BC:
	// li r31,1
	ctx.r31.s64 = 1;
	// b 0x8265d118
	goto loc_8265D118;
loc_8265D0C4:
	// lhz r11,20(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 20);
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwinm r9,r11,29,29,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x7;
	// rlwinm r11,r11,0,29,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x6;
	// slw r31,r10,r9
	ctx.r31.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bgt cr6,0x8265d828
	if (ctx.cr6.gt) goto loc_8265D828;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265d118
	if (ctx.cr6.eq) goto loc_8265D118;
	// bdz 0x8265d828
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D828;
	// bdz 0x8265d104
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D104;
	// bdz 0x8265d828
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D828;
	// bdz 0x8265d10c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D10C;
	// bdz 0x8265d828
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D828;
	// b 0x8265d114
	goto loc_8265D114;
loc_8265D104:
	// li r23,1
	ctx.r23.s64 = 1;
	// b 0x8265d118
	goto loc_8265D118;
loc_8265D10C:
	// li r23,4
	ctx.r23.s64 = 4;
	// b 0x8265d118
	goto loc_8265D118;
loc_8265D114:
	// mr r23,r15
	ctx.r23.u64 = ctx.r15.u64;
loc_8265D118:
	// lis r11,-13108
	ctx.r11.s64 = -859045888;
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// ori r5,r11,52429
	ctx.r5.u64 = ctx.r11.u64 | 52429;
	// li r3,5
	ctx.r3.s64 = 5;
	// ori r6,r10,43691
	ctx.r6.u64 = ctx.r10.u64 | 43691;
	// li r4,3
	ctx.r4.s64 = 3;
	// cmplwi cr6,r17,3
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 3, ctx.xer);
	// bne cr6,0x8265d198
	if (!ctx.cr6.eq) goto loc_8265D198;
	// lwz r11,92(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265d198
	if (ctx.cr6.eq) goto loc_8265D198;
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265d198
	if (!ctx.cr6.eq) goto loc_8265D198;
	// lwz r11,96(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 96);
	// cmplwi cr6,r11,151
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 151, ctx.xer);
	// bge cr6,0x8265d178
	if (!ctx.cr6.lt) goto loc_8265D178;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// rlwinm r11,r24,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 30) & 0x3FFFFFFF;
	// bne cr6,0x8265d18c
	if (!ctx.cr6.eq) goto loc_8265D18C;
loc_8265D168:
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8265d388
	if (ctx.cr6.lt) goto loc_8265D388;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// b 0x8265d1a8
	goto loc_8265D1A8;
loc_8265D178:
	// cmplwi cr6,r11,251
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 251, ctx.xer);
	// bge cr6,0x8265d198
	if (!ctx.cr6.lt) goto loc_8265D198;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// rlwinm r11,r24,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 31) & 0x7FFFFFFF;
	// beq cr6,0x8265d168
	if (ctx.cr6.eq) goto loc_8265D168;
loc_8265D18C:
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8265d198
	if (ctx.cr6.lt) goto loc_8265D198;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_8265D198:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x8265d388
	if (ctx.cr6.eq) goto loc_8265D388;
	// cmplwi cr6,r17,3
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 3, ctx.xer);
	// bne cr6,0x8265d388
	if (!ctx.cr6.eq) goto loc_8265D388;
loc_8265D1A8:
	// cmplw cr6,r29,r24
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x8265d388
	if (ctx.cr6.eq) goto loc_8265D388;
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8265d2f4
	if (!ctx.cr6.eq) goto loc_8265D2F4;
	// cmplwi cr6,r23,1
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 1, ctx.xer);
	// ble cr6,0x8265d2f4
	if (!ctx.cr6.gt) goto loc_8265D2F4;
	// lwz r10,0(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// li r22,1
	ctx.r22.s64 = 1;
	// rlwinm r23,r23,31,1,31
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r24,r11
	ctx.r24.u64 = ctx.r11.u64;
	// rlwinm r18,r18,31,1,31
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 31) & 0x7FFFFFFF;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8265d1ec
	if (!ctx.cr6.eq) goto loc_8265D1EC;
	// lwz r11,36(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265d388
	if (!ctx.cr6.eq) goto loc_8265D388;
loc_8265D1EC:
	// rlwinm r11,r27,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 31) & 0x7FFFFFFF;
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8265d200
	if (ctx.cr6.lt) goto loc_8265D200;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
loc_8265D200:
	// rlwinm r11,r20,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 31) & 0x7FFFFFFF;
	// li r20,1
	ctx.r20.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8265d214
	if (ctx.cr6.lt) goto loc_8265D214;
	// mr r20,r11
	ctx.r20.u64 = ctx.r11.u64;
loc_8265D214:
	// cmplwi cr6,r27,5
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 5, ctx.xer);
	// bgt cr6,0x8265d224
	if (ctx.cr6.gt) goto loc_8265D224;
	// mr r25,r27
	ctx.r25.u64 = ctx.r27.u64;
	// b 0x8265d388
	goto loc_8265D388;
loc_8265D224:
	// mulhwu r11,r27,r5
	ctx.r11.u64 = (uint64_t(ctx.r27.u32) * uint64_t(ctx.r5.u32)) >> 32;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf. r8,r10,r27
	ctx.r8.u64 = ctx.r27.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8265d244
	if (!ctx.cr0.eq) goto loc_8265D244;
	// divwu r25,r27,r3
	ctx.r25.u64 = uint32_t(ctx.r3.u32 ? ctx.r27.u32 / ctx.r3.u32 : 0);
	// b 0x8265d388
	goto loc_8265D388;
loc_8265D244:
	// cmplwi cr6,r27,4
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 4, ctx.xer);
	// ble cr6,0x8265d260
	if (!ctx.cr6.gt) goto loc_8265D260;
	// clrlwi r11,r27,30
	ctx.r11.u64 = ctx.r27.u32 & 0x3;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8265d260
	if (!ctx.cr6.eq) goto loc_8265D260;
	// rlwinm r25,r27,30,2,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 30) & 0x3FFFFFFF;
	// b 0x8265d388
	goto loc_8265D388;
loc_8265D260:
	// cmplwi cr6,r27,3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 3, ctx.xer);
	// ble cr6,0x8265d288
	if (!ctx.cr6.gt) goto loc_8265D288;
	// mulhwu r11,r27,r6
	ctx.r11.u64 = (uint64_t(ctx.r27.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf. r9,r10,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8265d288
	if (!ctx.cr0.eq) goto loc_8265D288;
	// divwu r25,r27,r4
	ctx.r25.u64 = uint32_t(ctx.r4.u32 ? ctx.r27.u32 / ctx.r4.u32 : 0);
	// b 0x8265d388
	goto loc_8265D388;
loc_8265D288:
	// mulhwu r11,r27,r6
	ctx.r11.u64 = (uint64_t(ctx.r27.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// clrlwi r11,r27,30
	ctx.r11.u64 = ctx.r27.u32 & 0x3;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r10,r10,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r10.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8265d2c4
	if (ctx.cr6.lt) goto loc_8265D2C4;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x8265d2bc
	if (ctx.cr6.gt) goto loc_8265D2BC;
	// subf r27,r11,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r11.u64;
	// rlwinm r25,r27,30,2,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 30) & 0x3FFFFFFF;
	// b 0x8265d2e0
	goto loc_8265D2E0;
loc_8265D2BC:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8265d2d8
	if (ctx.cr6.gt) goto loc_8265D2D8;
loc_8265D2C4:
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x8265d2d8
	if (ctx.cr6.gt) goto loc_8265D2D8;
	// subf r27,r10,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r10.u64;
	// divwu r25,r27,r4
	ctx.r25.u64 = uint32_t(ctx.r4.u32 ? ctx.r27.u32 / ctx.r4.u32 : 0);
	// b 0x8265d2e0
	goto loc_8265D2E0;
loc_8265D2D8:
	// subf r27,r8,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r8.u64;
	// divwu r25,r27,r3
	ctx.r25.u64 = uint32_t(ctx.r3.u32 ? ctx.r27.u32 / ctx.r3.u32 : 0);
loc_8265D2E0:
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// cmplw cr6,r20,r11
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8265d388
	if (ctx.cr6.lt) goto loc_8265D388;
	// mr r20,r11
	ctx.r20.u64 = ctx.r11.u64;
	// b 0x8265d388
	goto loc_8265D388;
loc_8265D2F4:
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8265d340
	if (!ctx.cr6.eq) goto loc_8265D340;
	// cmplwi cr6,r23,8
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 8, ctx.xer);
	// bge cr6,0x8265d340
	if (!ctx.cr6.lt) goto loc_8265D340;
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// li r22,1
	ctx.r22.s64 = 1;
	// rlwinm r23,r23,1,0,30
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r24,r24,31,1,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r18,r18,1,0,30
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265d330
	if (!ctx.cr6.eq) goto loc_8265D330;
	// lwz r11,36(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265d388
	if (!ctx.cr6.eq) goto loc_8265D388;
loc_8265D330:
	// rlwinm r27,r27,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r20,r20,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r25,r25,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x8265d388
	goto loc_8265D388;
loc_8265D340:
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8265d388
	if (!ctx.cr6.eq) goto loc_8265D388;
	// cmplwi cr6,r23,4
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 4, ctx.xer);
	// bge cr6,0x8265d388
	if (!ctx.cr6.lt) goto loc_8265D388;
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// li r22,1
	ctx.r22.s64 = 1;
	// rlwinm r23,r23,2,0,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r24,r24,30,2,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265d37c
	if (!ctx.cr6.eq) goto loc_8265D37C;
	// lwz r11,36(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265d388
	if (!ctx.cr6.eq) goto loc_8265D388;
loc_8265D37C:
	// rlwinm r27,r27,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r20,r20,2,0,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r25,r25,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
loc_8265D388:
	// lwz r11,92(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 92);
	// li r7,1000
	ctx.r7.s64 = 1000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265d568
	if (ctx.cr6.eq) goto loc_8265D568;
	// lwz r11,96(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 96);
	// lwz r10,0(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// mullw r11,r11,r19
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r19.s32);
	// addi r9,r11,999
	ctx.r9.s64 = ctx.r11.s64 + 999;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// divwu r10,r9,r7
	ctx.r10.u64 = uint32_t(ctx.r7.u32 ? ctx.r9.u32 / ctx.r7.u32 : 0);
	// bne cr6,0x8265d500
	if (!ctx.cr6.eq) goto loc_8265D500;
loc_8265D3B4:
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r24,r11
	ctx.r11.u64 = ctx.r24.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8265d3e0
	if (!ctx.cr6.gt) goto loc_8265D3E0;
	// cmplwi cr6,r17,3
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 3, ctx.xer);
	// blt cr6,0x8265d828
	if (ctx.cr6.lt) goto loc_8265D828;
	// rlwinm r23,r23,1,0,30
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r24,r24,31,1,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 31) & 0x7FFFFFFF;
	// li r22,1
	ctx.r22.s64 = 1;
	// cmplwi cr6,r23,16
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 16, ctx.xer);
	// blt cr6,0x8265d3b4
	if (ctx.cr6.lt) goto loc_8265D3B4;
loc_8265D3E0:
	// addi r11,r27,2
	ctx.r11.s64 = ctx.r27.s64 + 2;
	// mullw r9,r11,r24
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r24.s32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8265d568
	if (!ctx.cr6.lt) goto loc_8265D568;
	// divwu r11,r10,r24
	ctx.r11.u64 = uint32_t(ctx.r24.u32 ? ctx.r10.u32 / ctx.r24.u32 : 0);
	// li r22,1
	ctx.r22.s64 = 1;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8265d828
	if (!ctx.cr6.gt) goto loc_8265D828;
	// addi r27,r11,-2
	ctx.r27.s64 = ctx.r11.s64 + -2;
	// cmplwi cr6,r27,1
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 1, ctx.xer);
	// blt cr6,0x8265d828
	if (ctx.cr6.lt) goto loc_8265D828;
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// cmplw cr6,r20,r11
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8265d420
	if (ctx.cr6.lt) goto loc_8265D420;
	// mr r20,r11
	ctx.r20.u64 = ctx.r11.u64;
loc_8265D420:
	// cmplwi cr6,r27,5
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 5, ctx.xer);
	// bgt cr6,0x8265d430
	if (ctx.cr6.gt) goto loc_8265D430;
	// mr r25,r27
	ctx.r25.u64 = ctx.r27.u64;
	// b 0x8265d568
	goto loc_8265D568;
loc_8265D430:
	// mulhwu r11,r27,r5
	ctx.r11.u64 = (uint64_t(ctx.r27.u32) * uint64_t(ctx.r5.u32)) >> 32;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf. r8,r10,r27
	ctx.r8.u64 = ctx.r27.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8265d450
	if (!ctx.cr0.eq) goto loc_8265D450;
	// divwu r25,r27,r3
	ctx.r25.u64 = uint32_t(ctx.r3.u32 ? ctx.r27.u32 / ctx.r3.u32 : 0);
	// b 0x8265d568
	goto loc_8265D568;
loc_8265D450:
	// cmplwi cr6,r27,4
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 4, ctx.xer);
	// ble cr6,0x8265d46c
	if (!ctx.cr6.gt) goto loc_8265D46C;
	// clrlwi r11,r27,30
	ctx.r11.u64 = ctx.r27.u32 & 0x3;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8265d46c
	if (!ctx.cr6.eq) goto loc_8265D46C;
	// rlwinm r25,r27,30,2,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 30) & 0x3FFFFFFF;
	// b 0x8265d568
	goto loc_8265D568;
loc_8265D46C:
	// cmplwi cr6,r27,3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 3, ctx.xer);
	// ble cr6,0x8265d494
	if (!ctx.cr6.gt) goto loc_8265D494;
	// mulhwu r11,r27,r6
	ctx.r11.u64 = (uint64_t(ctx.r27.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf. r9,r10,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8265d494
	if (!ctx.cr0.eq) goto loc_8265D494;
	// divwu r25,r27,r4
	ctx.r25.u64 = uint32_t(ctx.r4.u32 ? ctx.r27.u32 / ctx.r4.u32 : 0);
	// b 0x8265d568
	goto loc_8265D568;
loc_8265D494:
	// mulhwu r11,r27,r6
	ctx.r11.u64 = (uint64_t(ctx.r27.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// clrlwi r11,r27,30
	ctx.r11.u64 = ctx.r27.u32 & 0x3;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r10,r10,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r10.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8265d4d0
	if (ctx.cr6.lt) goto loc_8265D4D0;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x8265d4c8
	if (ctx.cr6.gt) goto loc_8265D4C8;
	// subf r27,r11,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r11.u64;
	// rlwinm r25,r27,30,2,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 30) & 0x3FFFFFFF;
	// b 0x8265d4ec
	goto loc_8265D4EC;
loc_8265D4C8:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8265d4e4
	if (ctx.cr6.gt) goto loc_8265D4E4;
loc_8265D4D0:
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x8265d4e4
	if (ctx.cr6.gt) goto loc_8265D4E4;
	// subf r27,r10,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r10.u64;
	// divwu r25,r27,r4
	ctx.r25.u64 = uint32_t(ctx.r4.u32 ? ctx.r27.u32 / ctx.r4.u32 : 0);
	// b 0x8265d4ec
	goto loc_8265D4EC;
loc_8265D4E4:
	// subf r27,r8,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r8.u64;
	// divwu r25,r27,r3
	ctx.r25.u64 = uint32_t(ctx.r3.u32 ? ctx.r27.u32 / ctx.r3.u32 : 0);
loc_8265D4EC:
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// cmplw cr6,r20,r11
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8265d568
	if (ctx.cr6.lt) goto loc_8265D568;
	// mr r20,r11
	ctx.r20.u64 = ctx.r11.u64;
	// b 0x8265d568
	goto loc_8265D568;
loc_8265D500:
	// lhz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r26.u32 + 0);
loc_8265D504:
	// cmplwi cr6,r9,355
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 355, ctx.xer);
	// beq cr6,0x8265d518
	if (ctx.cr6.eq) goto loc_8265D518;
	// cmplwi cr6,r9,359
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 359, ctx.xer);
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x8265d51c
	if (!ctx.cr6.eq) goto loc_8265D51C;
loc_8265D518:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8265D51C:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8265d540
	if (!ctx.cr6.gt) goto loc_8265D540;
	// li r22,1
	ctx.r22.s64 = 1;
	// rlwinm r23,r23,1,0,30
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r24,r24,31,1,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r17,3
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 3, ctx.xer);
	// blt cr6,0x8265d828
	if (ctx.cr6.lt) goto loc_8265D828;
	// cmplwi cr6,r23,16
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 16, ctx.xer);
	// blt cr6,0x8265d504
	if (ctx.cr6.lt) goto loc_8265D504;
loc_8265D540:
	// mullw r11,r20,r24
	ctx.r11.s64 = int64_t(ctx.r20.s32) * int64_t(ctx.r24.s32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8265d568
	if (!ctx.cr6.lt) goto loc_8265D568;
	// divwu r20,r10,r24
	ctx.r20.u64 = uint32_t(ctx.r24.u32 ? ctx.r10.u32 / ctx.r24.u32 : 0);
	// li r22,1
	ctx.r22.s64 = 1;
	// cmplw cr6,r25,r20
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r20.u32, ctx.xer);
	// blt cr6,0x8265d560
	if (ctx.cr6.lt) goto loc_8265D560;
	// mr r25,r20
	ctx.r25.u64 = ctx.r20.u64;
loc_8265D560:
	// cmplwi cr6,r20,1
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 1, ctx.xer);
	// blt cr6,0x8265d828
	if (ctx.cr6.lt) goto loc_8265D828;
loc_8265D568:
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265d6b8
	if (!ctx.cr6.eq) goto loc_8265D6B8;
	// lwz r11,84(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265d6b8
	if (ctx.cr6.eq) goto loc_8265D6B8;
	// lwz r10,88(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 88);
	// add r11,r18,r25
	ctx.r11.u64 = ctx.r18.u64 + ctx.r25.u64;
	// mullw r10,r10,r19
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r19.s32);
	// addi r9,r10,999
	ctx.r9.s64 = ctx.r10.s64 + 999;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// divwu r10,r9,r7
	ctx.r10.u64 = uint32_t(ctx.r7.u32 ? ctx.r9.u32 / ctx.r7.u32 : 0);
	// mullw r8,r11,r24
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r24.s32);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8265d6b8
	if (!ctx.cr6.gt) goto loc_8265D6B8;
	// divwu r9,r10,r24
	ctx.r9.u64 = uint32_t(ctx.r24.u32 ? ctx.r10.u32 / ctx.r24.u32 : 0);
	// cmplwi cr6,r9,5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 5, ctx.xer);
	// bge cr6,0x8265d5c0
	if (!ctx.cr6.lt) goto loc_8265D5C0;
	// cmplwi cr6,r17,2
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 2, ctx.xer);
	// beq cr6,0x8265d828
	if (ctx.cr6.eq) goto loc_8265D828;
	// cmplwi cr6,r23,8
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 8, ctx.xer);
	// beq cr6,0x8265d828
	if (ctx.cr6.eq) goto loc_8265D828;
loc_8265D5C0:
	// cmplwi cr6,r9,6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 6, ctx.xer);
	// bge cr6,0x8265d5e4
	if (!ctx.cr6.lt) goto loc_8265D5E4;
	// cmplwi cr6,r17,3
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 3, ctx.xer);
	// bne cr6,0x8265d5e4
	if (!ctx.cr6.eq) goto loc_8265D5E4;
	// cmplwi cr6,r23,8
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 8, ctx.xer);
	// beq cr6,0x8265d5e4
	if (ctx.cr6.eq) goto loc_8265D5E4;
	// divwu r9,r15,r23
	ctx.r9.u64 = uint32_t(ctx.r23.u32 ? ctx.r15.u32 / ctx.r23.u32 : 0);
	// mr r23,r15
	ctx.r23.u64 = ctx.r15.u64;
	// divwu r24,r24,r9
	ctx.r24.u64 = uint32_t(ctx.r9.u32 ? ctx.r24.u32 / ctx.r9.u32 : 0);
loc_8265D5E4:
	// mullw r8,r11,r24
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r24.s32);
	// divwu r9,r10,r24
	ctx.r9.u64 = uint32_t(ctx.r24.u32 ? ctx.r10.u32 / ctx.r24.u32 : 0);
	// cmplw cr6,r20,r11
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8265d5f8
	if (ctx.cr6.lt) goto loc_8265D5F8;
	// mr r20,r11
	ctx.r20.u64 = ctx.r11.u64;
loc_8265D5F8:
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8265d634
	if (!ctx.cr6.gt) goto loc_8265D634;
	// cmplwi cr6,r9,5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 5, ctx.xer);
	// blt cr6,0x8265d828
	if (ctx.cr6.lt) goto loc_8265D828;
	// addi r11,r25,4
	ctx.r11.s64 = ctx.r25.s64 + 4;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8265d688
	if (!ctx.cr6.gt) goto loc_8265D688;
	// subf r11,r25,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r25.u64;
	// addi r11,r11,253
	ctx.r11.s64 = ctx.r11.s64 + 253;
	// clrlwi r18,r11,24
	ctx.r18.u64 = ctx.r11.u32 & 0xFF;
	// add r11,r18,r25
	ctx.r11.u64 = ctx.r18.u64 + ctx.r25.u64;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
loc_8265D628:
	// cmplw cr6,r20,r11
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8265d634
	if (ctx.cr6.lt) goto loc_8265D634;
	// mr r20,r11
	ctx.r20.u64 = ctx.r11.u64;
loc_8265D634:
	// cmplwi cr6,r27,1
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 1, ctx.xer);
	// bne cr6,0x8265d654
	if (!ctx.cr6.eq) goto loc_8265D654;
	// cmplwi cr6,r17,2
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 2, ctx.xer);
	// bgt cr6,0x8265d654
	if (ctx.cr6.gt) goto loc_8265D654;
	// lhz r11,20(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 20);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwinm r10,r10,0,31,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// sth r10,20(r26)
	REX_STORE_U16(ctx.r26.u32 + 20, ctx.r10.u16);
loc_8265D654:
	// addi r11,r23,-1
	ctx.r11.s64 = ctx.r23.s64 + -1;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x8265d828
	if (ctx.cr6.gt) goto loc_8265D828;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265d6cc
	if (ctx.cr6.eq) goto loc_8265D6CC;
	// bdz 0x8265d6e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D6E4;
	// bdz 0x8265d828
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D828;
	// bdz 0x8265d700
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D700;
	// bdz 0x8265d828
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D828;
	// bdz 0x8265d828
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D828;
	// bdz 0x8265d828
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8265D828;
	// b 0x8265d74c
	goto loc_8265D74C;
loc_8265D688:
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// li r18,1
	ctx.r18.s64 = 1;
	// addi r25,r9,-4
	ctx.r25.s64 = ctx.r9.s64 + -4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265d6b0
	if (!ctx.cr6.eq) goto loc_8265D6B0;
	// clrlwi r11,r25,16
	ctx.r11.u64 = ctx.r25.u32 & 0xFFFF;
	// divwu r10,r27,r11
	ctx.r10.u64 = uint32_t(ctx.r11.u32 ? ctx.r27.u32 / ctx.r11.u32 : 0);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// subf r8,r9,r27
	ctx.r8.u64 = ctx.r27.u64 - ctx.r9.u64;
	// subf r27,r8,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r8.u64;
loc_8265D6B0:
	// addi r11,r25,4
	ctx.r11.s64 = ctx.r25.s64 + 4;
	// b 0x8265d628
	goto loc_8265D628;
loc_8265D6B8:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne cr6,0x8265d634
	if (!ctx.cr6.eq) goto loc_8265D634;
loc_8265D6C0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f34
	__restgprlr_15(ctx, base);
	return;
loc_8265D6CC:
	// lhz r11,20(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 20);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwinm r10,r10,0,31,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// ori r9,r10,2
	ctx.r9.u64 = ctx.r10.u64 | 2;
	// sth r9,20(r26)
	REX_STORE_U16(ctx.r26.u32 + 20, ctx.r9.u16);
	// b 0x8265d79c
	goto loc_8265D79C;
loc_8265D6E4:
	// cmplwi cr6,r17,3
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 3, ctx.xer);
	// bne cr6,0x8265d79c
	if (!ctx.cr6.eq) goto loc_8265D79C;
	// lhz r11,20(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 20);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwinm r10,r10,0,31,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// sth r10,20(r26)
	REX_STORE_U16(ctx.r26.u32 + 20, ctx.r10.u16);
	// b 0x8265d79c
	goto loc_8265D79C;
loc_8265D700:
	// lhz r11,20(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 20);
	// cmplwi cr6,r31,8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8, ctx.xer);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwinm r10,r10,0,31,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// ori r11,r10,4
	ctx.r11.u64 = ctx.r10.u64 | 4;
	// sth r11,20(r26)
	REX_STORE_U16(ctx.r26.u32 + 20, ctx.r11.u16);
	// ble cr6,0x8265d720
	if (!ctx.cr6.gt) goto loc_8265D720;
	// mr r31,r15
	ctx.r31.u64 = ctx.r15.u64;
loc_8265D720:
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r10,r10,0,29,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFC7;
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// sth r10,20(r26)
	REX_STORE_U16(ctx.r26.u32 + 20, ctx.r10.u16);
	// ble cr6,0x8265d78c
	if (!ctx.cr6.gt) goto loc_8265D78C;
loc_8265D738:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r9,r31,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r31.u32 >> (ctx.r11.u8 & 0x3F));
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bgt cr6,0x8265d738
	if (ctx.cr6.gt) goto loc_8265D738;
	// b 0x8265d78c
	goto loc_8265D78C;
loc_8265D74C:
	// lhz r11,20(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 20);
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// ori r11,r11,6
	ctx.r11.u64 = ctx.r11.u64 | 6;
	// sth r11,20(r26)
	REX_STORE_U16(ctx.r26.u32 + 20, ctx.r11.u16);
	// ble cr6,0x8265d764
	if (!ctx.cr6.gt) goto loc_8265D764;
	// li r31,4
	ctx.r31.s64 = 4;
loc_8265D764:
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r10,r10,0,29,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFC7;
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// sth r10,20(r26)
	REX_STORE_U16(ctx.r26.u32 + 20, ctx.r10.u16);
	// ble cr6,0x8265d78c
	if (!ctx.cr6.gt) goto loc_8265D78C;
loc_8265D77C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r9,r31,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r31.u32 >> (ctx.r11.u8 & 0x3F));
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bgt cr6,0x8265d77c
	if (ctx.cr6.gt) goto loc_8265D77C;
loc_8265D78C:
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// sth r9,20(r26)
	REX_STORE_U16(ctx.r26.u32 + 20, ctx.r9.u16);
loc_8265D79C:
	// stw r24,28(r26)
	REX_STORE_U32(ctx.r26.u32 + 28, ctx.r24.u32);
	// mr r7,r17
	ctx.r7.u64 = ctx.r17.u64;
	// stw r18,44(r26)
	REX_STORE_U32(ctx.r26.u32 + 44, ctx.r18.u32);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// stw r27,40(r26)
	REX_STORE_U32(ctx.r26.u32 + 40, ctx.r27.u32);
	// stw r25,32(r26)
	REX_STORE_U32(ctx.r26.u32 + 32, ctx.r25.u32);
	// stw r20,36(r26)
	REX_STORE_U32(ctx.r26.u32 + 36, ctx.r20.u32);
	// lhz r8,20(r26)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r26.u32 + 20);
	// lwz r5,24(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 24);
	// lwz r4,4(r16)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r16.u32 + 4);
	// lwz r3,0(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// bl 0x8265cee0
	ctx.lr = 0x8265D7CC;
	sub_8265CEE0(ctx, base);
	// stw r3,8(r26)
	REX_STORE_U32(ctx.r26.u32 + 8, ctx.r3.u32);
	// mr r7,r17
	ctx.r7.u64 = ctx.r17.u64;
	// lhz r8,20(r26)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r26.u32 + 20);
	// lwz r6,32(r26)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r26.u32 + 32);
	// lwz r5,24(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 24);
	// lwz r4,4(r16)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r16.u32 + 4);
	// lwz r3,0(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// bl 0x8265cde0
	ctx.lr = 0x8265D7EC;
	sub_8265CDE0(ctx, base);
	// sth r3,12(r26)
	REX_STORE_U16(ctx.r26.u32 + 12, ctx.r3.u16);
	// lwz r11,28(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265d814
	if (ctx.cr6.eq) goto loc_8265D814;
	// lwz r11,28(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 28);
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// rlwinm r11,r11,2,16,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFC;
	// bne cr6,0x8265d810
	if (!ctx.cr6.eq) goto loc_8265D810;
	// li r11,8192
	ctx.r11.s64 = 8192;
loc_8265D810:
	// sth r11,12(r26)
	REX_STORE_U16(ctx.r26.u32 + 12, ctx.r11.u16);
loc_8265D814:
	// lhz r3,0(r26)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r26.u32 + 0);
	// bl 0x82682748
	ctx.lr = 0x8265D81C;
	sub_82682748(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f34
	__restgprlr_15(ctx, base);
	return;
loc_8265D828:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f34
	__restgprlr_15(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826A3CD8) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x826a3ce8
	if (!ctx.cr6.eq) goto loc_826A3CE8;
	// li r3,7
	ctx.r3.s64 = 7;
	// blr 
	return;
loc_826A3CE8:
	// b 0x8269ecd0
	sub_8269ECD0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826A6D28) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,5(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 5);
	// lbz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r8,3(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r7,1(r3)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r6,2(r3)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// stb r11,5(r3)
	REX_STORE_U8(ctx.r3.u32 + 5, ctx.r11.u8);
	// stb r10,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// stb r9,1(r3)
	REX_STORE_U8(ctx.r3.u32 + 1, ctx.r9.u8);
	// stb r7,4(r3)
	REX_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// stb r8,2(r3)
	REX_STORE_U8(ctx.r3.u32 + 2, ctx.r8.u8);
	// stb r6,3(r3)
	REX_STORE_U8(ctx.r3.u32 + 3, ctx.r6.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826A8B70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x826A8B78;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,84(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r30,5
	ctx.r30.s64 = 5;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x826a8bf4
	if (!ctx.cr6.lt) goto loc_826A8BF4;
loc_826A8B9C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a8bf4
	if (ctx.cr6.eq) goto loc_826A8BF4;
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
	// bge 0x826a8be4
	if (!ctx.cr0.lt) goto loc_826A8BE4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8BE4;
	sub_826C8B78(ctx, base);
loc_826A8BE4:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a8b9c
	if (ctx.cr6.gt) goto loc_826A8B9C;
loc_826A8BF4:
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
	// add r28,r11,r29
	ctx.r28.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x826a8c30
	if (!ctx.cr0.lt) goto loc_826A8C30;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8C30;
	sub_826C8B78(ctx, base);
loc_826A8C30:
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stw r28,3680(r27)
	REX_STORE_U32(ctx.r27.u32 + 3680, ctx.r28.u32);
	// li r30,11
	ctx.r30.s64 = 11;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r28,-13560(r11)
	REX_STORE_U32(ctx.r11.u32 + -13560, ctx.r28.u32);
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bge cr6,0x826a8cb0
	if (!ctx.cr6.lt) goto loc_826A8CB0;
loc_826A8C58:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a8cb0
	if (ctx.cr6.eq) goto loc_826A8CB0;
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
	// bge 0x826a8ca0
	if (!ctx.cr0.lt) goto loc_826A8CA0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8CA0;
	sub_826C8B78(ctx, base);
loc_826A8CA0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a8c58
	if (ctx.cr6.gt) goto loc_826A8C58;
loc_826A8CB0:
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
	// add r28,r11,r29
	ctx.r28.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x826a8cec
	if (!ctx.cr0.lt) goto loc_826A8CEC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8CEC;
	sub_826C8B78(ctx, base);
loc_826A8CEC:
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stw r28,3684(r27)
	REX_STORE_U32(ctx.r27.u32 + 3684, ctx.r28.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r30,1
	ctx.r30.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r28,-13564(r11)
	REX_STORE_U32(ctx.r11.u32 + -13564, ctx.r28.u32);
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// stw r10,3924(r27)
	REX_STORE_U32(ctx.r27.u32 + 3924, ctx.r10.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826a8d74
	if (!ctx.cr6.lt) goto loc_826A8D74;
loc_826A8D1C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a8d74
	if (ctx.cr6.eq) goto loc_826A8D74;
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
	// bge 0x826a8d64
	if (!ctx.cr0.lt) goto loc_826A8D64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8D64;
	sub_826C8B78(ctx, base);
loc_826A8D64:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a8d1c
	if (ctx.cr6.gt) goto loc_826A8D1C;
loc_826A8D74:
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
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x826a8db0
	if (!ctx.cr0.lt) goto loc_826A8DB0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8DB0;
	sub_826C8B78(ctx, base);
loc_826A8DB0:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r29,3912(r27)
	REX_STORE_U32(ctx.r27.u32 + 3912, ctx.r29.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826a8e28
	if (!ctx.cr6.lt) goto loc_826A8E28;
loc_826A8DD0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a8e28
	if (ctx.cr6.eq) goto loc_826A8E28;
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
	// bge 0x826a8e18
	if (!ctx.cr0.lt) goto loc_826A8E18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8E18;
	sub_826C8B78(ctx, base);
loc_826A8E18:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a8dd0
	if (ctx.cr6.gt) goto loc_826A8DD0;
loc_826A8E28:
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
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x826a8e64
	if (!ctx.cr0.lt) goto loc_826A8E64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8E64;
	sub_826C8B78(ctx, base);
loc_826A8E64:
	// stw r29,3916(r27)
	REX_STORE_U32(ctx.r27.u32 + 3916, ctx.r29.u32);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826a8edc
	if (!ctx.cr6.lt) goto loc_826A8EDC;
loc_826A8E84:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a8edc
	if (ctx.cr6.eq) goto loc_826A8EDC;
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
	// bge 0x826a8ecc
	if (!ctx.cr0.lt) goto loc_826A8ECC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8ECC;
	sub_826C8B78(ctx, base);
loc_826A8ECC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a8e84
	if (ctx.cr6.gt) goto loc_826A8E84;
loc_826A8EDC:
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
	// bge 0x826a8f18
	if (!ctx.cr0.lt) goto loc_826A8F18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8F18;
	sub_826C8B78(ctx, base);
loc_826A8F18:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r30,436(r27)
	REX_STORE_U32(ctx.r27.u32 + 436, ctx.r30.u32);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826a8f90
	if (!ctx.cr6.lt) goto loc_826A8F90;
loc_826A8F38:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a8f90
	if (ctx.cr6.eq) goto loc_826A8F90;
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
	// bge 0x826a8f80
	if (!ctx.cr0.lt) goto loc_826A8F80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8F80;
	sub_826C8B78(ctx, base);
loc_826A8F80:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a8f38
	if (ctx.cr6.gt) goto loc_826A8F38;
loc_826A8F90:
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
	// bge 0x826a8fcc
	if (!ctx.cr0.lt) goto loc_826A8FCC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A8FCC;
	sub_826C8B78(ctx, base);
loc_826A8FCC:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r30,3908(r27)
	REX_STORE_U32(ctx.r27.u32 + 3908, ctx.r30.u32);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826a9044
	if (!ctx.cr6.lt) goto loc_826A9044;
loc_826A8FEC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a9044
	if (ctx.cr6.eq) goto loc_826A9044;
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
	// bge 0x826a9034
	if (!ctx.cr0.lt) goto loc_826A9034;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A9034;
	sub_826C8B78(ctx, base);
loc_826A9034:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a8fec
	if (ctx.cr6.gt) goto loc_826A8FEC;
loc_826A9044:
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
	// bge 0x826a9080
	if (!ctx.cr0.lt) goto loc_826A9080;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A9080;
	sub_826C8B78(ctx, base);
loc_826A9080:
	// stw r30,444(r27)
	REX_STORE_U32(ctx.r27.u32 + 444, ctx.r30.u32);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826a90f8
	if (!ctx.cr6.lt) goto loc_826A90F8;
loc_826A90A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a90f8
	if (ctx.cr6.eq) goto loc_826A90F8;
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
	// bge 0x826a90e8
	if (!ctx.cr0.lt) goto loc_826A90E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A90E8;
	sub_826C8B78(ctx, base);
loc_826A90E8:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a90a0
	if (ctx.cr6.gt) goto loc_826A90A0;
loc_826A90F8:
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
	// bge 0x826a9134
	if (!ctx.cr0.lt) goto loc_826A9134;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A9134;
	sub_826C8B78(ctx, base);
loc_826A9134:
	// stw r30,396(r27)
	REX_STORE_U32(ctx.r27.u32 + 396, ctx.r30.u32);
	// li r30,3
	ctx.r30.s64 = 3;
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x826a91ac
	if (!ctx.cr6.lt) goto loc_826A91AC;
loc_826A9154:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a91ac
	if (ctx.cr6.eq) goto loc_826A91AC;
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
	// bge 0x826a919c
	if (!ctx.cr0.lt) goto loc_826A919C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A919C;
	sub_826C8B78(ctx, base);
loc_826A919C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a9154
	if (ctx.cr6.gt) goto loc_826A9154;
loc_826A91AC:
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
	// bge 0x826a91e8
	if (!ctx.cr0.lt) goto loc_826A91E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A91E8;
	sub_826C8B78(ctx, base);
loc_826A91E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,15496(r27)
	REX_STORE_U32(ctx.r27.u32 + 15496, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826EF918) {
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
	// lwz r11,212(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 212);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,204(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// lwz r9,216(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 216);
	// mullw r7,r11,r10
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// lwz r8,208(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 208);
	// lwz r11,14832(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 14832);
	// lwz r4,3756(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 3756);
	// lwz r5,3760(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 3760);
	// lwz r6,3764(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 3764);
	// mullw r8,r9,r8
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826ef970
	if (!ctx.cr6.eq) goto loc_826EF970;
	// lwz r11,14828(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 14828);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826ef994
	if (!ctx.cr6.eq) goto loc_826EF994;
	// bl 0x826ef7d0
	ctx.lr = 0x826EF96C;
	sub_826EF7D0(ctx, base);
	// b 0x826ef98c
	goto loc_826EF98C;
loc_826EF970:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826ef994
	if (!ctx.cr6.eq) goto loc_826EF994;
	// lwz r11,14828(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14828);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826ef994
	if (!ctx.cr6.eq) goto loc_826EF994;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ef870
	ctx.lr = 0x826EF98C;
	sub_826EF870(ctx, base);
loc_826EF98C:
	// lwz r11,14828(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14828);
	// stw r11,14832(r31)
	REX_STORE_U32(ctx.r31.u32 + 14832, ctx.r11.u32);
loc_826EF994:
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

DEFINE_REX_FUNC(sub_826F1120) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32145
	ctx.r10.s64 = -2106654720;
	// lwz r11,20624(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20624);
	// lis r9,-32145
	ctx.r9.s64 = -2106654720;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// addi r7,r10,-1424
	ctx.r7.s64 = ctx.r10.s64 + -1424;
	// addi r6,r9,-1064
	ctx.r6.s64 = ctx.r9.s64 + -1064;
	// lis r5,-32110
	ctx.r5.s64 = -2104360960;
	// stw r7,15888(r3)
	REX_STORE_U32(ctx.r3.u32 + 15888, ctx.r7.u32);
	// stw r6,15884(r3)
	REX_STORE_U32(ctx.r3.u32 + 15884, ctx.r6.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r11,-13792(r8)
	REX_STORE_U32(ctx.r8.u32 + -13792, ctx.r11.u32);
	// lwz r11,20628(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20628);
	// stw r11,-13796(r5)
	REX_STORE_U32(ctx.r5.u32 + -13796, ctx.r11.u32);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32145
	ctx.r11.s64 = -2106654720;
	// lis r10,-32145
	ctx.r10.s64 = -2106654720;
	// addi r9,r11,-8024
	ctx.r9.s64 = ctx.r11.s64 + -8024;
	// addi r8,r10,-7576
	ctx.r8.s64 = ctx.r10.s64 + -7576;
	// stw r9,15888(r3)
	REX_STORE_U32(ctx.r3.u32 + 15888, ctx.r9.u32);
	// stw r8,15884(r3)
	REX_STORE_U32(ctx.r3.u32 + 15884, ctx.r8.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826F2018) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x826F2020;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r31,268(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826f20d4
	if (!ctx.cr6.gt) goto loc_826F20D4;
	// lwz r11,136(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 136);
loc_826F2040:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826f20c4
	if (!ctx.cr6.gt) goto loc_826F20C4;
	// cntlzw r11,r28
	ctx.r11.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// rlwinm r27,r11,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_826F2054:
	// lwz r11,136(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 136);
	// addi r5,r31,-10
	ctx.r5.s64 = ctx.r31.s64 + -10;
	// cntlzw r9,r30
	ctx.r9.u64 = ctx.r30.u32 == 0 ? 32 : __builtin_clz(ctx.r30.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r5,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r4,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// addi r10,r31,14
	ctx.r10.s64 = ctx.r31.s64 + 14;
	// rlwinm r11,r3,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r31,-16
	ctx.r9.s64 = ctx.r31.s64 + -16;
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// addi r7,r31,8
	ctx.r7.s64 = ctx.r31.s64 + 8;
	// addi r5,r11,14
	ctx.r5.s64 = ctx.r11.s64 + 14;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// rlwinm r6,r6,24,29,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0x7;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826ecf70
	ctx.lr = 0x826F20B0;
	sub_826ECF70(ctx, base);
	// lwz r11,136(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 136);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826f2054
	if (ctx.cr6.lt) goto loc_826F2054;
loc_826F20C4:
	// lwz r10,140(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 140);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826f2040
	if (ctx.cr6.lt) goto loc_826F2040;
loc_826F20D4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826FAB98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x826FABA0;
	__savegprlr_14(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,372(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// stw r3,308(r1)
	REX_STORE_U32(ctx.r1.u32 + 308, ctx.r3.u32);
	// stw r4,316(r1)
	REX_STORE_U32(ctx.r1.u32 + 316, ctx.r4.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r7,340(r1)
	REX_STORE_U32(ctx.r1.u32 + 340, ctx.r7.u32);
	// stw r8,348(r1)
	REX_STORE_U32(ctx.r1.u32 + 348, ctx.r8.u32);
	// beq cr6,0x826fb18c
	if (ctx.cr6.eq) goto loc_826FB18C;
	// addi r20,r4,8
	ctx.r20.s64 = ctx.r4.s64 + 8;
	// lwz r23,256(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 256);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r19,r20,-1
	ctx.r19.s64 = ctx.r20.s64 + -1;
	// addi r15,r20,1
	ctx.r15.s64 = ctx.r20.s64 + 1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// addi r16,r19,-1
	ctx.r16.s64 = ctx.r19.s64 + -1;
	// addi r14,r15,1
	ctx.r14.s64 = ctx.r15.s64 + 1;
	// stw r15,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r15.u32);
	// addi r17,r16,-1
	ctx.r17.s64 = ctx.r16.s64 + -1;
	// stw r16,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r16.u32);
	// addi r11,r14,1
	ctx.r11.s64 = ctx.r14.s64 + 1;
	// stw r14,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r14.u32);
	// addi r18,r17,-1
	ctx.r18.s64 = ctx.r17.s64 + -1;
	// stw r17,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r17.u32);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// addi r9,r18,-1
	ctx.r9.s64 = ctx.r18.s64 + -1;
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
loc_826FAC10:
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// clrlwi r7,r9,30
	ctx.r7.u64 = ctx.r9.u32 & 0x3;
	// lbz r25,0(r18)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r18.u32 + 0);
	// lbz r21,0(r11)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r22,0(r10)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lbz r27,0(r17)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r17.u32 + 0);
	// lbz r29,0(r16)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r16.u32 + 0);
	// lbz r31,0(r19)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r19.u32 + 0);
	// lbz r30,0(r20)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r20.u32 + 0);
	// lbz r28,0(r15)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r15.u32 + 0);
	// lbz r26,0(r14)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r14.u32 + 0);
	// lbz r24,0(r8)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// bne cr6,0x826fadc4
	if (!ctx.cr6.eq) goto loc_826FADC4;
	// subf r10,r22,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r22.u64;
	// li r11,2
	ctx.r11.s64 = 2;
	// srawi r9,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 31;
	// srawi r8,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 31;
	// xor r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// subf r6,r24,r26
	ctx.r6.u64 = ctx.r26.u64 - ctx.r24.u64;
	// subf r5,r9,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r9.u64;
	// li r10,2
	ctx.r10.s64 = 2;
	// subfc r4,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r4.u64 = ctx.r11.u64 - ctx.r5.u64;
	// rlwinm r3,r5,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// subf r9,r26,r28
	ctx.r9.u64 = ctx.r28.u64 - ctx.r26.u64;
	// adde r7,r3,r8
	temp.u8 = (ctx.r3.u32 + ctx.r8.u32 < ctx.r3.u32) | (ctx.r3.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ctx.r3.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r8,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r6.s32 >> 31;
	// srawi r5,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 31;
	// xor r4,r6,r8
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r8.u64;
	// subf r17,r30,r31
	ctx.r17.u64 = ctx.r31.u64 - ctx.r30.u64;
	// subf r3,r8,r4
	ctx.r3.u64 = ctx.r4.u64 - ctx.r8.u64;
	// subf r4,r28,r30
	ctx.r4.u64 = ctx.r30.u64 - ctx.r28.u64;
	// subfc r8,r3,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r3.u32;
	ctx.r8.u64 = ctx.r10.u64 - ctx.r3.u64;
	// rlwinm r6,r3,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// subf r16,r29,r27
	ctx.r16.u64 = ctx.r27.u64 - ctx.r29.u64;
	// adde r8,r6,r5
	temp.u8 = (ctx.r6.u32 + ctx.r5.u32 < ctx.r6.u32) | (ctx.r6.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ctx.r6.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r5,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r9.s32 >> 31;
	// srawi r3,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r11.s32 >> 31;
	// xor r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r5.u64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// subf r6,r5,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r5.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// subfc r5,r6,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r6.u32;
	ctx.r5.u64 = ctx.r11.u64 - ctx.r6.u64;
	// rlwinm r11,r6,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1;
	// adde r6,r11,r3
	temp.u8 = (ctx.r11.u32 + ctx.r3.u32 < ctx.r11.u32) | (ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r7,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 31;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// subf r3,r31,r29
	ctx.r3.u64 = ctx.r29.u64 - ctx.r31.u64;
	// subf r7,r7,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r7.u64;
	// li r11,2
	ctx.r11.s64 = 2;
	// subfc r4,r7,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r7.u32;
	ctx.r4.u64 = ctx.r10.u64 - ctx.r7.u64;
	// rlwinm r10,r7,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// adde r5,r10,r5
	temp.u8 = (ctx.r10.u32 + ctx.r5.u32 < ctx.r10.u32) | (ctx.r10.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r7,r17,31
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r17.s32 >> 31;
	// srawi r4,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r9.s32 >> 31;
	// xor r17,r17,r7
	ctx.r17.u64 = ctx.r17.u64 ^ ctx.r7.u64;
	// li r10,2
	ctx.r10.s64 = 2;
	// subf r7,r7,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r7.u64;
	// subf r17,r27,r25
	ctx.r17.u64 = ctx.r25.u64 - ctx.r27.u64;
	// subfc r15,r7,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r7.u32;
	ctx.r15.u64 = ctx.r9.u64 - ctx.r7.u64;
	// rlwinm r7,r7,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// add r9,r8,r6
	ctx.r9.u64 = ctx.r8.u64 + ctx.r6.u64;
	// adde r8,r7,r4
	temp.u8 = (ctx.r7.u32 + ctx.r4.u32 < ctx.r7.u32) | (ctx.r7.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ctx.r7.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r6,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 31;
	// add r7,r9,r5
	ctx.r7.u64 = ctx.r9.u64 + ctx.r5.u64;
	// xor r3,r3,r6
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r6.u64;
	// srawi r4,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 31;
	// subf r9,r6,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r6.u64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// subfc r7,r9,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r9.u32;
	ctx.r7.u64 = ctx.r11.u64 - ctx.r9.u64;
	// rlwinm r6,r9,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// li r9,2
	ctx.r9.s64 = 2;
	// adde r11,r6,r4
	temp.u8 = (ctx.r6.u32 + ctx.r4.u32 < ctx.r6.u32) | (ctx.r6.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ctx.r6.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r5,r16,31
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r16.s32 >> 31;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// xor r3,r16,r5
	ctx.r3.u64 = ctx.r16.u64 ^ ctx.r5.u64;
	// lwz r16,116(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// srawi r4,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 31;
	// subf r11,r5,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r5.u64;
	// subf r7,r25,r21
	ctx.r7.u64 = ctx.r21.u64 - ctx.r25.u64;
	// subfc r6,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r6.u64 = ctx.r10.u64 - ctx.r11.u64;
	// rlwinm r5,r11,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// adde r11,r5,r4
	temp.u8 = (ctx.r5.u32 + ctx.r4.u32 < ctx.r5.u32) | (ctx.r5.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ctx.r5.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r4,r17,31
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r17.s32 >> 31;
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + ctx.r11.u64;
	// xor r6,r17,r4
	ctx.r6.u64 = ctx.r17.u64 ^ ctx.r4.u64;
	// srawi r3,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r9.s32 >> 31;
	// subf r5,r4,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r4.u64;
	// subfc r11,r5,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r5.u32;
	ctx.r11.u64 = ctx.r9.u64 - ctx.r5.u64;
	// rlwinm r4,r5,1,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// adde r11,r4,r3
	temp.u8 = (ctx.r4.u32 + ctx.r3.u32 < ctx.r4.u32) | (ctx.r4.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ctx.r4.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r9,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 31;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r11,2
	ctx.r11.s64 = 2;
	// xor r8,r7,r9
	ctx.r8.u64 = ctx.r7.u64 ^ ctx.r9.u64;
	// lwz r17,112(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// srawi r7,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 31;
	// lwz r15,120(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// subf r6,r9,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r9.u64;
	// lwz r14,124(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// rlwinm r5,r6,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1;
	// subfc r4,r6,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r6.u32;
	ctx.r4.u64 = ctx.r11.u64 - ctx.r6.u64;
	// adde r11,r5,r7
	temp.u8 = (ctx.r5.u32 + ctx.r7.u32 < ctx.r5.u32) | (ctx.r5.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ctx.r5.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r3,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
loc_826FADC4:
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x826fafec
	if (ctx.cr6.lt) goto loc_826FAFEC;
	// lwz r11,380(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 380);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x827114d8
	ctx.lr = 0x826FAE00;
	sub_827114D8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826fb11c
	if (ctx.cr6.eq) goto loc_826FB11C;
	// subf r10,r21,r25
	ctx.r10.u64 = ctx.r25.u64 - ctx.r21.u64;
	// lwz r11,380(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 380);
	// srawi r9,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 31;
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// subf r7,r9,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r9.u64;
	// cmpw cr6,r7,r11
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826fae28
	if (ctx.cr6.lt) goto loc_826FAE28;
	// mr r21,r25
	ctx.r21.u64 = ctx.r25.u64;
loc_826FAE28:
	// subf r10,r22,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r22.u64;
	// srawi r9,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 31;
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// subf r7,r9,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r9.u64;
	// cmpw cr6,r7,r11
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826fae44
	if (ctx.cr6.lt) goto loc_826FAE44;
	// mr r22,r24
	ctx.r22.u64 = ctx.r24.u64;
loc_826FAE44:
	// addi r10,r25,2
	ctx.r10.s64 = ctx.r25.s64 + 2;
	// rlwinm r11,r21,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r21,r11
	ctx.r11.u64 = ctx.r21.u64 + ctx.r11.u64;
	// add r9,r27,r21
	ctx.r9.u64 = ctx.r27.u64 + ctx.r21.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r27
	ctx.r8.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r7,r11,r25
	ctx.r7.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r6,r10,r31
	ctx.r6.u64 = ctx.r10.u64 + ctx.r31.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r5,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 4;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r4,r29,2
	ctx.r4.s64 = ctx.r29.s64 + 2;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r11,r5,r23
	ctx.r11.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r23.u32);
	// addi r9,r31,2
	ctx.r9.s64 = ctx.r31.s64 + 2;
	// addi r8,r30,2
	ctx.r8.s64 = ctx.r30.s64 + 2;
	// srawi r7,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r3.s32 >> 4;
	// addi r6,r28,2
	ctx.r6.s64 = ctx.r28.s64 + 2;
	// stb r11,0(r18)
	REX_STORE_U8(ctx.r18.u32 + 0, ctx.r11.u8);
	// add r11,r10,r30
	ctx.r11.u64 = ctx.r10.u64 + ctx.r30.u64;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r9,r8,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r9,r9,r26
	ctx.r9.u64 = ctx.r9.u64 + ctx.r26.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// rlwinm r8,r6,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r28
	ctx.r9.u64 = ctx.r9.u64 + ctx.r28.u64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// add r5,r11,r21
	ctx.r5.u64 = ctx.r11.u64 + ctx.r21.u64;
	// add r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 + ctx.r22.u64;
	// add r11,r9,r31
	ctx.r11.u64 = ctx.r9.u64 + ctx.r31.u64;
	// add r4,r10,r27
	ctx.r4.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r10,r8,r24
	ctx.r10.u64 = ctx.r8.u64 + ctx.r24.u64;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r26
	ctx.r9.u64 = ctx.r10.u64 + ctx.r26.u64;
	// add r8,r8,r26
	ctx.r8.u64 = ctx.r8.u64 + ctx.r26.u64;
	// lbzx r3,r7,r23
	ctx.r3.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r23.u32);
	// add r7,r11,r29
	ctx.r7.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stb r3,0(r17)
	REX_STORE_U8(ctx.r17.u32 + 0, ctx.r3.u8);
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// add r10,r10,r22
	ctx.r10.u64 = ctx.r10.u64 + ctx.r22.u64;
	// add r6,r8,r28
	ctx.r6.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r5,r9,r31
	ctx.r5.u64 = ctx.r9.u64 + ctx.r31.u64;
	// srawi r4,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 4;
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r9,r11,r25
	ctx.r9.u64 = ctx.r11.u64 + ctx.r25.u64;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r3,r9,r21
	ctx.r3.u64 = ctx.r9.u64 + ctx.r21.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// srawi r9,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 4;
	// add r7,r11,r27
	ctx.r7.u64 = ctx.r11.u64 + ctx.r27.u64;
	// srawi r6,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 4;
	// add r11,r22,r26
	ctx.r11.u64 = ctx.r22.u64 + ctx.r26.u64;
	// lbzx r8,r4,r23
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r23.u32);
	// srawi r5,r7,4
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 4;
	// addi r4,r11,2
	ctx.r4.s64 = ctx.r11.s64 + 2;
	// stb r8,0(r16)
	REX_STORE_U8(ctx.r16.u32 + 0, ctx.r8.u8);
	// lbzx r3,r9,r23
	ctx.r3.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r23.u32);
	// stb r3,0(r19)
	REX_STORE_U8(ctx.r19.u32 + 0, ctx.r3.u8);
	// lbzx r11,r6,r23
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r23.u32);
	// stb r11,0(r20)
	REX_STORE_U8(ctx.r20.u32 + 0, ctx.r11.u8);
	// lbzx r10,r5,r23
	ctx.r10.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r23.u32);
	// stb r10,0(r15)
	REX_STORE_U8(ctx.r15.u32 + 0, ctx.r10.u8);
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r24,2
	ctx.r7.s64 = ctx.r24.s64 + 2;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// rlwinm r10,r22,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r22,r10
	ctx.r10.u64 = ctx.r22.u64 + ctx.r10.u64;
	// add r6,r9,r30
	ctx.r6.u64 = ctx.r9.u64 + ctx.r30.u64;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + ctx.r26.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r3,r4,4
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 4;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbzx r10,r3,r23
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r23.u32);
	// srawi r9,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 4;
	// stb r10,0(r14)
	REX_STORE_U8(ctx.r14.u32 + 0, ctx.r10.u8);
	// lbzx r7,r9,r23
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r23.u32);
	// stb r7,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// b 0x826fb11c
	goto loc_826FB11C;
loc_826FAFEC:
	// subf r5,r30,r31
	ctx.r5.u64 = ctx.r31.u64 - ctx.r30.u64;
	// lwz r9,380(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 380);
	// subf r10,r28,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r28.u64;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// add r7,r5,r11
	ctx.r7.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r4,r7,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r7.u64;
	// srawi r3,r4,3
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 3;
	// addze r6,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r6.s64 = temp.s64;
	// srawi r11,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 31;
	// xor r10,r6,r11
	ctx.r10.u64 = ctx.r6.u64 ^ ctx.r11.u64;
	// subf r4,r11,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmpw cr6,r4,r9
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x826fb11c
	if (!ctx.cr6.lt) goto loc_826FB11C;
	// subf r10,r27,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r27.u64;
	// subf r11,r31,r25
	ctx.r11.u64 = ctx.r25.u64 - ctx.r31.u64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// subf r9,r24,r30
	ctx.r9.u64 = ctx.r30.u64 - ctx.r24.u64;
	// subf r11,r28,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r28.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// addi r7,r9,2
	ctx.r7.s64 = ctx.r9.s64 + 2;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r8,r10
	ctx.r3.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r9,r3,3
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 3;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// addze r10,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r3,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 31;
	// xor r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r3.u64;
	// xor r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 ^ ctx.r9.u64;
	// subf r11,r3,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r3.u64;
	// subf r10,r9,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r9.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826fb094
	if (!ctx.cr6.lt) goto loc_826FB094;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_826FB094:
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x826fb11c
	if (!ctx.cr6.lt) goto loc_826FB11C;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// li r9,-1
	ctx.r9.s64 = -1;
	// blt cr6,0x826fb0ac
	if (ctx.cr6.lt) goto loc_826FB0AC;
	// li r9,1
	ctx.r9.s64 = 1;
loc_826FB0AC:
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// subf r11,r6,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r6.u64;
	// srawi r10,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addze. r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// srawi r8,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 3;
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r11.s64 = temp.s64;
	// ble 0x826fb0e8
	if (!ctx.cr0.gt) goto loc_826FB0E8;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x826fb104
	if (!ctx.cr6.gt) goto loc_826FB104;
	// b 0x826fb100
	goto loc_826FB100;
loc_826FB0E8:
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// subfze r7,r8
	temp.u8 = ~ctx.r8.u32 + ctx.xer.ca < ~ctx.r8.u32;
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x826fb104
	if (!ctx.cr6.lt) goto loc_826FB104;
loc_826FB100:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_826FB104:
	// subf r10,r11,r31
	ctx.r10.u64 = ctx.r31.u64 - ctx.r11.u64;
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbzx r8,r10,r23
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r23.u32);
	// stb r8,0(r19)
	REX_STORE_U8(ctx.r19.u32 + 0, ctx.r8.u8);
	// lbzx r7,r9,r23
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r23.u32);
	// stb r7,0(r20)
	REX_STORE_U8(ctx.r20.u32 + 0, ctx.r7.u8);
loc_826FB11C:
	// lwz r11,388(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 388);
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r9,104(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// add r17,r17,r11
	ctx.r17.u64 = ctx.r17.u64 + ctx.r11.u64;
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r7,108(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r16,r16,r11
	ctx.r16.u64 = ctx.r16.u64 + ctx.r11.u64;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// add r15,r15,r11
	ctx.r15.u64 = ctx.r15.u64 + ctx.r11.u64;
	// stw r6,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// add r14,r14,r11
	ctx.r14.u64 = ctx.r14.u64 + ctx.r11.u64;
	// stw r17,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r17.u32);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r16,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r16.u32);
	// add r4,r7,r11
	ctx.r4.u64 = ctx.r7.u64 + ctx.r11.u64;
	// stw r15,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r15.u32);
	// add r18,r18,r11
	ctx.r18.u64 = ctx.r18.u64 + ctx.r11.u64;
	// stw r14,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r14.u32);
	// add r19,r19,r11
	ctx.r19.u64 = ctx.r19.u64 + ctx.r11.u64;
	// stw r5,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// add r20,r20,r11
	ctx.r20.u64 = ctx.r20.u64 + ctx.r11.u64;
	// stw r4,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// blt cr6,0x826fac10
	if (ctx.cr6.lt) goto loc_826FAC10;
	// lwz r3,308(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// lwz r4,316(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 316);
loc_826FB18C:
	// lwz r11,340(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 340);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826fb750
	if (ctx.cr6.eq) goto loc_826FB750;
	// addi r19,r4,-1
	ctx.r19.s64 = ctx.r4.s64 + -1;
	// lwz r23,256(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 256);
	// addi r11,r4,1
	ctx.r11.s64 = ctx.r4.s64 + 1;
	// addi r15,r19,-1
	ctx.r15.s64 = ctx.r19.s64 + -1;
	// addi r14,r11,1
	ctx.r14.s64 = ctx.r11.s64 + 1;
	// addi r16,r15,-1
	ctx.r16.s64 = ctx.r15.s64 + -1;
	// stw r15,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r15.u32);
	// addi r11,r14,1
	ctx.r11.s64 = ctx.r14.s64 + 1;
	// stw r14,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r14.u32);
	// addi r17,r16,-1
	ctx.r17.s64 = ctx.r16.s64 + -1;
	// stw r16,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r16.u32);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// addi r9,r17,-1
	ctx.r9.s64 = ctx.r17.s64 + -1;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// addi r20,r19,1
	ctx.r20.s64 = ctx.r19.s64 + 1;
	// stw r8,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
loc_826FB1E4:
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r9,108(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// clrlwi r7,r9,30
	ctx.r7.u64 = ctx.r9.u32 & 0x3;
	// lbz r25,0(r17)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r17.u32 + 0);
	// lbz r21,0(r11)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r22,0(r10)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lbz r27,0(r16)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r16.u32 + 0);
	// lbz r29,0(r15)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r15.u32 + 0);
	// lbz r31,0(r19)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r19.u32 + 0);
	// lbz r30,0(r20)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r20.u32 + 0);
	// lbz r28,1(r20)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r20.u32 + 1);
	// lbz r26,0(r14)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r14.u32 + 0);
	// lbz r24,0(r8)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// bne cr6,0x826fb394
	if (!ctx.cr6.eq) goto loc_826FB394;
	// subf r10,r22,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r22.u64;
	// lwz r14,116(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// li r11,2
	ctx.r11.s64 = 2;
	// srawi r9,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 31;
	// srawi r8,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 31;
	// xor r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// subf r6,r24,r26
	ctx.r6.u64 = ctx.r26.u64 - ctx.r24.u64;
	// subf r5,r9,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r9.u64;
	// li r10,2
	ctx.r10.s64 = 2;
	// subfc r4,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r4.u64 = ctx.r11.u64 - ctx.r5.u64;
	// rlwinm r3,r5,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// subf r9,r26,r28
	ctx.r9.u64 = ctx.r28.u64 - ctx.r26.u64;
	// adde r7,r3,r8
	temp.u8 = (ctx.r3.u32 + ctx.r8.u32 < ctx.r3.u32) | (ctx.r3.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ctx.r3.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r8,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r6.s32 >> 31;
	// srawi r5,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 31;
	// xor r4,r6,r8
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r8.u64;
	// subf r18,r30,r31
	ctx.r18.u64 = ctx.r31.u64 - ctx.r30.u64;
	// subf r3,r8,r4
	ctx.r3.u64 = ctx.r4.u64 - ctx.r8.u64;
	// subf r8,r28,r30
	ctx.r8.u64 = ctx.r30.u64 - ctx.r28.u64;
	// subfc r6,r3,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r3.u32;
	ctx.r6.u64 = ctx.r10.u64 - ctx.r3.u64;
	// rlwinm r4,r3,1,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// subf r16,r31,r29
	ctx.r16.u64 = ctx.r29.u64 - ctx.r31.u64;
	// adde r5,r4,r5
	temp.u8 = (ctx.r4.u32 + ctx.r5.u32 < ctx.r4.u32) | (ctx.r4.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ctx.r4.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r3,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r9.s32 >> 31;
	// srawi r6,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 31;
	// xor r4,r9,r3
	ctx.r4.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// subf r3,r3,r4
	ctx.r3.u64 = ctx.r4.u64 - ctx.r3.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// subfc r11,r3,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r3.u32;
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// rlwinm r4,r3,1,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// adde r6,r4,r6
	temp.u8 = (ctx.r4.u32 + ctx.r6.u32 < ctx.r4.u32) | (ctx.r4.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ctx.r4.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r3,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r8.s32 >> 31;
	// srawi r5,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 31;
	// xor r4,r8,r3
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// li r11,2
	ctx.r11.s64 = 2;
	// subf r3,r3,r4
	ctx.r3.u64 = ctx.r4.u64 - ctx.r3.u64;
	// subf r4,r29,r27
	ctx.r4.u64 = ctx.r27.u64 - ctx.r29.u64;
	// subfc r10,r3,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r3.u32;
	ctx.r10.u64 = ctx.r10.u64 - ctx.r3.u64;
	// rlwinm r8,r3,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// adde r8,r8,r5
	temp.u8 = (ctx.r8.u32 + ctx.r5.u32 < ctx.r8.u32) | (ctx.r8.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r3,r18,31
	ctx.xer.ca = (ctx.r18.s32 < 0) & ((ctx.r18.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r18.s32 >> 31;
	// srawi r5,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r9.s32 >> 31;
	// xor r18,r18,r3
	ctx.r18.u64 = ctx.r18.u64 ^ ctx.r3.u64;
	// li r10,2
	ctx.r10.s64 = 2;
	// subf r3,r3,r18
	ctx.r3.u64 = ctx.r18.u64 - ctx.r3.u64;
	// subf r18,r27,r25
	ctx.r18.u64 = ctx.r25.u64 - ctx.r27.u64;
	// subfc r15,r3,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r3.u32;
	ctx.r15.u64 = ctx.r9.u64 - ctx.r3.u64;
	// rlwinm r3,r3,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// add r9,r7,r6
	ctx.r9.u64 = ctx.r7.u64 + ctx.r6.u64;
	// adde r7,r3,r5
	temp.u8 = (ctx.r3.u32 + ctx.r5.u32 < ctx.r3.u32) | (ctx.r3.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ctx.r3.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r6,r16,31
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r16.s32 >> 31;
	// srawi r5,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r11.s32 >> 31;
	// xor r3,r16,r6
	ctx.r3.u64 = ctx.r16.u64 ^ ctx.r6.u64;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// subf r6,r6,r3
	ctx.r6.u64 = ctx.r3.u64 - ctx.r6.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// subfc r3,r6,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r6.u32;
	ctx.r3.u64 = ctx.r11.u64 - ctx.r6.u64;
	// rlwinm r6,r6,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1;
	// add r11,r8,r7
	ctx.r11.u64 = ctx.r8.u64 + ctx.r7.u64;
	// adde r8,r6,r5
	temp.u8 = (ctx.r6.u32 + ctx.r5.u32 < ctx.r6.u32) | (ctx.r6.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ctx.r6.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r5,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r4.s32 >> 31;
	// srawi r3,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r10.s32 >> 31;
	// xor r7,r4,r5
	ctx.r7.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// subf r6,r5,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r5.u64;
	// subf r5,r25,r21
	ctx.r5.u64 = ctx.r21.u64 - ctx.r25.u64;
	// subfc r4,r6,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r6.u32;
	ctx.r4.u64 = ctx.r10.u64 - ctx.r6.u64;
	// rlwinm r10,r6,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1;
	// adde r10,r10,r3
	temp.u8 = (ctx.r10.u32 + ctx.r3.u32 < ctx.r10.u32) | (ctx.r10.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r8,r18,31
	ctx.xer.ca = (ctx.r18.s32 < 0) & ((ctx.r18.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r18.s32 >> 31;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// xor r6,r18,r8
	ctx.r6.u64 = ctx.r18.u64 ^ ctx.r8.u64;
	// srawi r7,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 31;
	// subf r4,r8,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r8.u64;
	// subfc r10,r4,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r4.u32;
	ctx.r10.u64 = ctx.r9.u64 - ctx.r4.u64;
	// rlwinm r3,r4,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1;
	// adde r10,r3,r7
	temp.u8 = (ctx.r3.u32 + ctx.r7.u32 < ctx.r3.u32) | (ctx.r3.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ctx.r3.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r9,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 31;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r11,2
	ctx.r11.s64 = 2;
	// xor r8,r5,r9
	ctx.r8.u64 = ctx.r5.u64 ^ ctx.r9.u64;
	// lwz r16,124(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// srawi r7,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 31;
	// lwz r15,120(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// subf r6,r9,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r9.u64;
	// rlwinm r5,r6,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1;
	// subfc r4,r6,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r6.u32;
	ctx.r4.u64 = ctx.r11.u64 - ctx.r6.u64;
	// adde r11,r5,r7
	temp.u8 = (ctx.r5.u32 + ctx.r7.u32 < ctx.r5.u32) | (ctx.r5.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ctx.r5.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r3,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
loc_826FB394:
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x826fb5b8
	if (ctx.cr6.lt) goto loc_826FB5B8;
	// lwz r18,380(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 380);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// rlwinm r11,r18,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x827114d8
	ctx.lr = 0x826FB3D0;
	sub_827114D8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826fb6e8
	if (ctx.cr6.eq) goto loc_826FB6E8;
	// subf r11,r21,r25
	ctx.r11.u64 = ctx.r25.u64 - ctx.r21.u64;
	// srawi r10,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 31;
	// xor r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r10.u64;
	// subf r8,r10,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmpw cr6,r8,r18
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r18.s32, ctx.xer);
	// blt cr6,0x826fb3f4
	if (ctx.cr6.lt) goto loc_826FB3F4;
	// mr r21,r25
	ctx.r21.u64 = ctx.r25.u64;
loc_826FB3F4:
	// subf r11,r22,r24
	ctx.r11.u64 = ctx.r24.u64 - ctx.r22.u64;
	// srawi r10,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 31;
	// xor r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r10.u64;
	// subf r8,r10,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmpw cr6,r8,r18
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r18.s32, ctx.xer);
	// blt cr6,0x826fb410
	if (ctx.cr6.lt) goto loc_826FB410;
	// mr r22,r24
	ctx.r22.u64 = ctx.r24.u64;
loc_826FB410:
	// rlwinm r10,r21,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r25,2
	ctx.r11.s64 = ctx.r25.s64 + 2;
	// add r9,r21,r10
	ctx.r9.u64 = ctx.r21.u64 + ctx.r10.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r27,r21
	ctx.r10.u64 = ctx.r27.u64 + ctx.r21.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// add r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r10,r27
	ctx.r8.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r7,r10,r25
	ctx.r7.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r6,r11,r31
	ctx.r6.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r5,r29,2
	ctx.r5.s64 = ctx.r29.s64 + 2;
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r10,r30
	ctx.r4.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 2;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r10,r10,r21
	ctx.r10.u64 = ctx.r10.u64 + ctx.r21.u64;
	// add r9,r11,r27
	ctx.r9.u64 = ctx.r11.u64 + ctx.r27.u64;
	// srawi r8,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r6.s32 >> 4;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r7,r30,2
	ctx.r7.s64 = ctx.r30.s64 + 2;
	// lbzx r6,r8,r23
	ctx.r6.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r23.u32);
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + ctx.r24.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r26
	ctx.r9.u64 = ctx.r10.u64 + ctx.r26.u64;
	// addi r3,r28,2
	ctx.r3.s64 = ctx.r28.s64 + 2;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stb r6,0(r17)
	REX_STORE_U8(ctx.r17.u32 + 0, ctx.r6.u8);
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r10,r10,r22
	ctx.r10.u64 = ctx.r10.u64 + ctx.r22.u64;
	// srawi r8,r4,4
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r4.s32 >> 4;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r6,r9,r21
	ctx.r6.u64 = ctx.r9.u64 + ctx.r21.u64;
	// srawi r5,r5,4
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 4;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbzx r4,r8,r23
	ctx.r4.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r23.u32);
	// add r3,r10,r25
	ctx.r3.u64 = ctx.r10.u64 + ctx.r25.u64;
	// srawi r10,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 4;
	// add r9,r11,r27
	ctx.r9.u64 = ctx.r11.u64 + ctx.r27.u64;
	// srawi r8,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 4;
	// srawi r7,r9,4
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 4;
	// stb r4,0(r16)
	REX_STORE_U8(ctx.r16.u32 + 0, ctx.r4.u8);
	// add r11,r22,r26
	ctx.r11.u64 = ctx.r22.u64 + ctx.r26.u64;
	// lbzx r6,r5,r23
	ctx.r6.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r23.u32);
	// stb r6,0(r15)
	REX_STORE_U8(ctx.r15.u32 + 0, ctx.r6.u8);
	// addi r5,r11,2
	ctx.r5.s64 = ctx.r11.s64 + 2;
	// lbzx r4,r10,r23
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r23.u32);
	// stb r4,0(r19)
	REX_STORE_U8(ctx.r19.u32 + 0, ctx.r4.u8);
	// lbzx r3,r8,r23
	ctx.r3.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r23.u32);
	// stb r3,0(r20)
	REX_STORE_U8(ctx.r20.u32 + 0, ctx.r3.u8);
	// lbzx r11,r7,r23
	ctx.r11.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r23.u32);
	// stb r11,1(r20)
	REX_STORE_U8(ctx.r20.u32 + 1, ctx.r11.u8);
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r24,2
	ctx.r7.s64 = ctx.r24.s64 + 2;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// rlwinm r10,r22,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r22,r10
	ctx.r10.u64 = ctx.r22.u64 + ctx.r10.u64;
	// add r6,r9,r30
	ctx.r6.u64 = ctx.r9.u64 + ctx.r30.u64;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + ctx.r26.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r3,r4,4
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 4;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbzx r10,r3,r23
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r23.u32);
	// srawi r9,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 4;
	// stb r10,0(r14)
	REX_STORE_U8(ctx.r14.u32 + 0, ctx.r10.u8);
	// lbzx r7,r9,r23
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r23.u32);
	// stb r7,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// b 0x826fb6e8
	goto loc_826FB6E8;
loc_826FB5B8:
	// subf r5,r30,r31
	ctx.r5.u64 = ctx.r31.u64 - ctx.r30.u64;
	// lwz r9,380(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 380);
	// subf r10,r28,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r28.u64;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// add r7,r5,r11
	ctx.r7.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r4,r7,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r7.u64;
	// srawi r3,r4,3
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 3;
	// addze r6,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r6.s64 = temp.s64;
	// srawi r11,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 31;
	// xor r10,r6,r11
	ctx.r10.u64 = ctx.r6.u64 ^ ctx.r11.u64;
	// subf r4,r11,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmpw cr6,r4,r9
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x826fb6e8
	if (!ctx.cr6.lt) goto loc_826FB6E8;
	// subf r10,r27,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r27.u64;
	// subf r11,r31,r25
	ctx.r11.u64 = ctx.r25.u64 - ctx.r31.u64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// subf r9,r24,r30
	ctx.r9.u64 = ctx.r30.u64 - ctx.r24.u64;
	// subf r11,r28,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r28.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// addi r7,r9,2
	ctx.r7.s64 = ctx.r9.s64 + 2;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r8,r10
	ctx.r3.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r9,r3,3
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 3;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// addze r10,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r3,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 31;
	// xor r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r3.u64;
	// xor r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 ^ ctx.r9.u64;
	// subf r11,r3,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r3.u64;
	// subf r10,r9,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r9.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826fb660
	if (!ctx.cr6.lt) goto loc_826FB660;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_826FB660:
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x826fb6e8
	if (!ctx.cr6.lt) goto loc_826FB6E8;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// li r9,-1
	ctx.r9.s64 = -1;
	// blt cr6,0x826fb678
	if (ctx.cr6.lt) goto loc_826FB678;
	// li r9,1
	ctx.r9.s64 = 1;
loc_826FB678:
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// subf r11,r6,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r6.u64;
	// srawi r10,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addze. r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// srawi r8,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 3;
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r11.s64 = temp.s64;
	// ble 0x826fb6b4
	if (!ctx.cr0.gt) goto loc_826FB6B4;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x826fb6d0
	if (!ctx.cr6.gt) goto loc_826FB6D0;
	// b 0x826fb6cc
	goto loc_826FB6CC;
loc_826FB6B4:
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// subfze r7,r8
	temp.u8 = ~ctx.r8.u32 + ctx.xer.ca < ~ctx.r8.u32;
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x826fb6d0
	if (!ctx.cr6.lt) goto loc_826FB6D0;
loc_826FB6CC:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_826FB6D0:
	// subf r10,r11,r31
	ctx.r10.u64 = ctx.r31.u64 - ctx.r11.u64;
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbzx r8,r10,r23
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r23.u32);
	// stb r8,0(r19)
	REX_STORE_U8(ctx.r19.u32 + 0, ctx.r8.u8);
	// lbzx r7,r9,r23
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r23.u32);
	// stb r7,0(r20)
	REX_STORE_U8(ctx.r20.u32 + 0, ctx.r7.u8);
loc_826FB6E8:
	// lwz r11,388(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 388);
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r9,104(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// add r16,r16,r11
	ctx.r16.u64 = ctx.r16.u64 + ctx.r11.u64;
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r7,100(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r15,r15,r11
	ctx.r15.u64 = ctx.r15.u64 + ctx.r11.u64;
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// add r14,r14,r11
	ctx.r14.u64 = ctx.r14.u64 + ctx.r11.u64;
	// stw r6,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r16,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r16.u32);
	// add r4,r7,r11
	ctx.r4.u64 = ctx.r7.u64 + ctx.r11.u64;
	// stw r15,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r15.u32);
	// add r17,r17,r11
	ctx.r17.u64 = ctx.r17.u64 + ctx.r11.u64;
	// stw r14,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r14.u32);
	// add r19,r19,r11
	ctx.r19.u64 = ctx.r19.u64 + ctx.r11.u64;
	// stw r5,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// add r20,r20,r11
	ctx.r20.u64 = ctx.r20.u64 + ctx.r11.u64;
	// stw r4,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// blt cr6,0x826fb1e4
	if (ctx.cr6.lt) goto loc_826FB1E4;
	// lwz r3,308(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// lwz r4,316(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 316);
loc_826FB750:
	// lwz r11,348(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 348);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826fbbd0
	if (ctx.cr6.eq) goto loc_826FBBD0;
	// addi r16,r4,16
	ctx.r16.s64 = ctx.r4.s64 + 16;
	// lwz r18,256(r3)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r3.u32 + 256);
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r22,r16,-1
	ctx.r22.s64 = ctx.r16.s64 + -1;
	// addi r15,r16,1
	ctx.r15.s64 = ctx.r16.s64 + 1;
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// addi r19,r22,-1
	ctx.r19.s64 = ctx.r22.s64 + -1;
	// addi r9,r15,1
	ctx.r9.s64 = ctx.r15.s64 + 1;
	// addi r20,r19,-1
	ctx.r20.s64 = ctx.r19.s64 + -1;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// addi r21,r20,-1
	ctx.r21.s64 = ctx.r20.s64 + -1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// addi r8,r21,-1
	ctx.r8.s64 = ctx.r21.s64 + -1;
	// stw r7,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// stw r8,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
loc_826FB7A0:
	// lbz r3,0(r7)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// li r11,2
	ctx.r11.s64 = 2;
	// lbz r23,0(r10)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// li r10,2
	ctx.r10.s64 = 2;
	// lbz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// subf r3,r3,r23
	ctx.r3.u64 = ctx.r23.u64 - ctx.r3.u64;
	// lbz r24,0(r9)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r25,0(r15)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r15.u32 + 0);
	// srawi r6,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 31;
	// lbz r28,0(r16)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r16.u32 + 0);
	// srawi r8,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 31;
	// lbz r31,0(r19)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r19.u32 + 0);
	// xor r3,r3,r6
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r6.u64;
	// lbz r26,0(r22)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r22.u32 + 0);
	// subf r7,r23,r24
	ctx.r7.u64 = ctx.r24.u64 - ctx.r23.u64;
	// lbz r29,0(r20)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r20.u32 + 0);
	// subf r6,r6,r3
	ctx.r6.u64 = ctx.r3.u64 - ctx.r6.u64;
	// lbz r30,0(r21)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r21.u32 + 0);
	// subf r4,r24,r25
	ctx.r4.u64 = ctx.r25.u64 - ctx.r24.u64;
	// subfc r3,r6,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r6.u32;
	ctx.r3.u64 = ctx.r11.u64 - ctx.r6.u64;
	// rlwinm r6,r6,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1;
	// subf r27,r25,r28
	ctx.r27.u64 = ctx.r28.u64 - ctx.r25.u64;
	// adde r8,r6,r8
	temp.u8 = (ctx.r6.u32 + ctx.r8.u32 < ctx.r6.u32) | (ctx.r6.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r3,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r7.s32 >> 31;
	// srawi r6,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 31;
	// xor r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r3.u64;
	// subf r17,r31,r29
	ctx.r17.u64 = ctx.r29.u64 - ctx.r31.u64;
	// subf r3,r3,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r3.u64;
	// subfc r9,r3,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r3.u32;
	ctx.r9.u64 = ctx.r10.u64 - ctx.r3.u64;
	// rlwinm r7,r3,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// adde r7,r7,r6
	temp.u8 = (ctx.r7.u32 + ctx.r6.u32 < ctx.r7.u32) | (ctx.r7.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// xor r9,r4,r6
	ctx.r9.u64 = ctx.r4.u64 ^ ctx.r6.u64;
	// srawi r3,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r11.s32 >> 31;
	// subf r9,r6,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r6.u64;
	// subf r4,r26,r31
	ctx.r4.u64 = ctx.r31.u64 - ctx.r26.u64;
	// subfc r8,r9,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r9.u32;
	ctx.r8.u64 = ctx.r11.u64 - ctx.r9.u64;
	// rlwinm r6,r9,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// li r9,2
	ctx.r9.s64 = 2;
	// adde r6,r6,r3
	temp.u8 = (ctx.r6.u32 + ctx.r3.u32 < ctx.r6.u32) | (ctx.r6.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ctx.r6.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r3,r27,31
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r27.s32 >> 31;
	// srawi r8,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 31;
	// xor r11,r27,r3
	ctx.r11.u64 = ctx.r27.u64 ^ ctx.r3.u64;
	// subf r3,r3,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r3.u64;
	// li r11,2
	ctx.r11.s64 = 2;
	// subfc r27,r3,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r3.u32;
	ctx.r27.u64 = ctx.r10.u64 - ctx.r3.u64;
	// rlwinm r3,r3,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// add r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 + ctx.r6.u64;
	// adde r8,r3,r8
	temp.u8 = (ctx.r3.u32 + ctx.r8.u32 < ctx.r3.u32) | (ctx.r3.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ctx.r3.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r7,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r4.s32 >> 31;
	// srawi r6,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 31;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// subf r7,r7,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r7.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// subfc r4,r7,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r7.u32;
	ctx.r4.u64 = ctx.r9.u64 - ctx.r7.u64;
	// rlwinm r9,r7,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// subf r3,r29,r30
	ctx.r3.u64 = ctx.r30.u64 - ctx.r29.u64;
	// adde r9,r9,r6
	temp.u8 = (ctx.r9.u32 + ctx.r6.u32 < ctx.r9.u32) | (ctx.r9.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r8,r17,31
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r17.s32 >> 31;
	// srawi r7,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 31;
	// xor r6,r17,r8
	ctx.r6.u64 = ctx.r17.u64 ^ ctx.r8.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r5,r8,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r8.u64;
	// subf r9,r28,r26
	ctx.r9.u64 = ctx.r26.u64 - ctx.r28.u64;
	// subfc r4,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r4.u64 = ctx.r11.u64 - ctx.r5.u64;
	// rlwinm r8,r5,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// adde r8,r8,r7
	temp.u8 = (ctx.r8.u32 + ctx.r7.u32 < ctx.r8.u32) | (ctx.r8.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r7,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r3.s32 >> 31;
	// srawi r4,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 31;
	// xor r6,r3,r7
	ctx.r6.u64 = ctx.r3.u64 ^ ctx.r7.u64;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// subf r5,r7,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r7.u64;
	// subf r10,r30,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r30.u64;
	// subfc r3,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r3.u64 = ctx.r11.u64 - ctx.r5.u64;
	// rlwinm r11,r5,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// adde r7,r11,r4
	temp.u8 = (ctx.r11.u32 + ctx.r4.u32 < ctx.r11.u32) | (ctx.r11.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ctx.r11.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r6,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 31;
	// li r11,2
	ctx.r11.s64 = 2;
	// xor r5,r10,r6
	ctx.r5.u64 = ctx.r10.u64 ^ ctx.r6.u64;
	// subf r3,r6,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r6.u64;
	// srawi r4,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 31;
	// subfc r6,r3,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r3.u32;
	ctx.r6.u64 = ctx.r11.u64 - ctx.r3.u64;
	// rlwinm r5,r3,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// add r11,r8,r7
	ctx.r11.u64 = ctx.r8.u64 + ctx.r7.u64;
	// adde r8,r5,r4
	temp.u8 = (ctx.r5.u32 + ctx.r4.u32 < ctx.r5.u32) | (ctx.r5.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ctx.r5.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// srawi r4,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r9.s32 >> 31;
	// li r10,2
	ctx.r10.s64 = 2;
	// xor r7,r9,r4
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r4.u64;
	// srawi r3,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r10.s32 >> 31;
	// subf r6,r4,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r4.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r5,r6,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1;
	// subfc r4,r6,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r6.u32;
	ctx.r4.u64 = ctx.r10.u64 - ctx.r6.u64;
	// adde r10,r5,r3
	temp.u8 = (ctx.r5.u32 + ctx.r3.u32 < ctx.r5.u32) | (ctx.r5.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ctx.r5.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// blt cr6,0x826fba54
	if (ctx.cr6.lt) goto loc_826FBA54;
	// lwz r17,380(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 380);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// rlwinm r11,r17,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827114d8
	ctx.lr = 0x826FB95C;
	sub_827114D8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826fbb74
	if (ctx.cr6.eq) goto loc_826FBB74;
	// subf r11,r27,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r27.u64;
	// srawi r10,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 31;
	// xor r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r10.u64;
	// subf r8,r10,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmpw cr6,r8,r17
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r17.s32, ctx.xer);
	// blt cr6,0x826fb980
	if (ctx.cr6.lt) goto loc_826FB980;
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
loc_826FB980:
	// rlwinm r10,r27,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r30,2
	ctx.r11.s64 = ctx.r30.s64 + 2;
	// add r9,r27,r10
	ctx.r9.u64 = ctx.r27.u64 + ctx.r10.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r26,2
	ctx.r10.s64 = ctx.r26.s64 + 2;
	// addi r7,r31,2
	ctx.r7.s64 = ctx.r31.s64 + 2;
	// add r8,r29,r27
	ctx.r8.u64 = ctx.r29.u64 + ctx.r27.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r8,2
	ctx.r6.s64 = ctx.r8.s64 + 2;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r8,r9,r31
	ctx.r8.u64 = ctx.r9.u64 + ctx.r31.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// rlwinm r9,r6,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r5,r8,r29
	ctx.r5.u64 = ctx.r8.u64 + ctx.r29.u64;
	// add r9,r9,r26
	ctx.r9.u64 = ctx.r9.u64 + ctx.r26.u64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// add r4,r10,r29
	ctx.r4.u64 = ctx.r10.u64 + ctx.r29.u64;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r8,r8,r28
	ctx.r8.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r3,r9,r30
	ctx.r3.u64 = ctx.r9.u64 + ctx.r30.u64;
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r8,r8,r26
	ctx.r8.u64 = ctx.r8.u64 + ctx.r26.u64;
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// srawi r7,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 4;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r6,r9,r28
	ctx.r6.u64 = ctx.r9.u64 + ctx.r28.u64;
	// lbzx r5,r7,r18
	ctx.r5.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r18.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r4,r10,r25
	ctx.r4.u64 = ctx.r10.u64 + ctx.r25.u64;
	// srawi r3,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r3.s64 = ctx.r6.s32 >> 4;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// srawi r10,r4,4
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 4;
	// stb r5,0(r21)
	REX_STORE_U8(ctx.r21.u32 + 0, ctx.r5.u8);
	// srawi r9,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 4;
	// lbzx r8,r3,r18
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r18.u32);
	// stb r8,0(r20)
	REX_STORE_U8(ctx.r20.u32 + 0, ctx.r8.u8);
	// lbzx r7,r10,r18
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r18.u32);
	// stb r7,0(r19)
	REX_STORE_U8(ctx.r19.u32 + 0, ctx.r7.u8);
	// lbzx r6,r9,r18
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r18.u32);
	// stb r6,0(r22)
	REX_STORE_U8(ctx.r22.u32 + 0, ctx.r6.u8);
	// b 0x826fbb74
	goto loc_826FBB74;
loc_826FBA54:
	// subf r10,r25,r31
	ctx.r10.u64 = ctx.r31.u64 - ctx.r25.u64;
	// lwz r8,380(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 380);
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r4,r6,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r6.u64;
	// srawi r3,r4,3
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 3;
	// addze r5,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r10,r5,r11
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r11.u64;
	// subf r4,r11,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmpw cr6,r4,r8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x826fbb74
	if (!ctx.cr6.lt) goto loc_826FBB74;
	// subf r10,r29,r31
	ctx.r10.u64 = ctx.r31.u64 - ctx.r29.u64;
	// subf r11,r26,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r26.u64;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// subf r8,r23,r28
	ctx.r8.u64 = ctx.r28.u64 - ctx.r23.u64;
	// subf r11,r25,r24
	ctx.r11.u64 = ctx.r24.u64 - ctx.r25.u64;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addi r6,r8,2
	ctx.r6.s64 = ctx.r8.s64 + 2;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r7,r10
	ctx.r3.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r8,r3,3
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 3;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r6,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// addze r10,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r3,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r10.s32 >> 31;
	// srawi r8,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 31;
	// xor r7,r10,r3
	ctx.r7.u64 = ctx.r10.u64 ^ ctx.r3.u64;
	// xor r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 ^ ctx.r8.u64;
	// subf r11,r3,r7
	ctx.r11.u64 = ctx.r7.u64 - ctx.r3.u64;
	// subf r10,r8,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r8.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826fbaf8
	if (!ctx.cr6.lt) goto loc_826FBAF8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_826FBAF8:
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x826fbb74
	if (!ctx.cr6.lt) goto loc_826FBB74;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// li r8,-1
	ctx.r8.s64 = -1;
	// blt cr6,0x826fbb10
	if (ctx.cr6.lt) goto loc_826FBB10;
	// li r8,1
	ctx.r8.s64 = 1;
loc_826FBB10:
	// mullw r11,r8,r11
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// subf r10,r5,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r5.u64;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addze. r11,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r11.s64 = temp.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// srawi r6,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// addze r10,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r10.s64 = temp.s64;
	// ble 0x826fbb4c
	if (!ctx.cr0.gt) goto loc_826FBB4C;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x826fbb68
	if (!ctx.cr6.gt) goto loc_826FBB68;
	// b 0x826fbb64
	goto loc_826FBB64;
loc_826FBB4C:
	// addic r9,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// subfze r7,r8
	temp.u8 = ~ctx.r8.u32 + ctx.xer.ca < ~ctx.r8.u32;
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ctx.r10.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826fbb68
	if (!ctx.cr6.lt) goto loc_826FBB68;
loc_826FBB64:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_826FBB68:
	// subf r11,r10,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r10.u64;
	// lbzx r10,r11,r18
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r18.u32);
	// stb r10,0(r22)
	REX_STORE_U8(ctx.r22.u32 + 0, ctx.r10.u8);
loc_826FBB74:
	// lwz r11,388(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 388);
	// lwz r9,120(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r10,124(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// add r21,r21,r11
	ctx.r21.u64 = ctx.r21.u64 + ctx.r11.u64;
	// lwz r7,116(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addic. r6,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r6.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwz r4,108(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r10,r5,r11
	ctx.r10.u64 = ctx.r5.u64 + ctx.r11.u64;
	// stw r6,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r6.u32);
	// add r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 + ctx.r11.u64;
	// stw r8,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// add r20,r20,r11
	ctx.r20.u64 = ctx.r20.u64 + ctx.r11.u64;
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// add r19,r19,r11
	ctx.r19.u64 = ctx.r19.u64 + ctx.r11.u64;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// add r22,r22,r11
	ctx.r22.u64 = ctx.r22.u64 + ctx.r11.u64;
	// stw r7,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// add r16,r16,r11
	ctx.r16.u64 = ctx.r16.u64 + ctx.r11.u64;
	// add r15,r15,r11
	ctx.r15.u64 = ctx.r15.u64 + ctx.r11.u64;
	// bne 0x826fb7a0
	if (!ctx.cr0.eq) goto loc_826FB7A0;
loc_826FBBD0:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8275E118) {
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
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// mullw r9,r11,r4
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// lwz r8,100(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r7,104(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mullw r11,r8,r5
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r5.s32);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r5,r7,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// bl 0x8273a030
	ctx.lr = 0x8275E160;
	sub_8273A030(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275e178
	if (ctx.cr6.eq) goto loc_8275E178;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82755c68
	ctx.lr = 0x8275E178;
	sub_82755C68(ctx, base);
loc_8275E178:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275e190
	if (ctx.cr6.eq) goto loc_8275E190;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82756030
	ctx.lr = 0x8275E190;
	sub_82756030(ctx, base);
loc_8275E190:
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

DEFINE_REX_FUNC(sub_82760580) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f30.u64);
	// stfd f31,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x827605ac
	if (!ctx.cr6.eq) goto loc_827605AC;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r8,r11,-29812
	ctx.r8.s64 = ctx.r11.s64 + -29812;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r30,r11,-29836
	ctx.r30.s64 = ctx.r11.s64 + -29836;
	// b 0x827605bc
	goto loc_827605BC;
loc_827605AC:
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r8,r11,-29868
	ctx.r8.s64 = ctx.r11.s64 + -29868;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r30,r11,-29900
	ctx.r30.s64 = ctx.r11.s64 + -29900;
loc_827605BC:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmplwi cr6,r6,8
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 8, ctx.xer);
	// lfs f31,5864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f31.f64 = double(temp.f32);
	// li r11,16
	ctx.r11.s64 = 16;
	// lfs f5,2524(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f5.f64 = double(temp.f32);
	// fmr f10,f31
	ctx.f10.f64 = ctx.f31.f64;
	// fmr f7,f5
	ctx.f7.f64 = ctx.f5.f64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bne cr6,0x82760610
	if (!ctx.cr6.eq) goto loc_82760610;
loc_827605E8:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x827605f8
	if (!ctx.cr6.lt) goto loc_827605F8;
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
loc_827605F8:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// ble cr6,0x82760604
	if (!ctx.cr6.gt) goto loc_82760604;
	// fmr f7,f0
	ctx.f7.f64 = ctx.f0.f64;
loc_82760604:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x827605e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827605E8;
	// b 0x82760650
	goto loc_82760650;
loc_82760610:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x82760628
	if (!ctx.cr6.lt) goto loc_82760628;
	// fcmpu cr6,f0,f5
	ctx.cr6.compare(ctx.f0.f64, ctx.f5.f64);
	// ble cr6,0x82760628
	if (!ctx.cr6.gt) goto loc_82760628;
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
loc_82760628:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// ble cr6,0x8276063c
	if (!ctx.cr6.gt) goto loc_8276063C;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8276063c
	if (!ctx.cr6.lt) goto loc_8276063C;
	// fmr f7,f0
	ctx.f7.f64 = ctx.f0.f64;
loc_8276063C:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82760610
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82760610;
	// fcmpu cr6,f10,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f7.f64);
	// bne cr6,0x82760650
	if (!ctx.cr6.eq) goto loc_82760650;
	// fmr f7,f31
	ctx.f7.f64 = ctx.f31.f64;
loc_82760650:
	// addi r7,r6,-1
	ctx.r7.s64 = ctx.r6.s64 + -1;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrldi r11,r7,32
	ctx.r11.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// std r11,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.r11.u64);
	// lfd f0,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lfs f2,-29908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29908);
	ctx.f2.f64 = double(temp.f32);
	// li r31,0
	ctx.r31.s64 = 0;
	// lfs f4,7996(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7996);
	ctx.f4.f64 = double(temp.f32);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// lfs f3,-29904(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29904);
	ctx.f3.f64 = double(temp.f32);
loc_82760684:
	// fsubs f0,f7,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// fcmpu cr6,f0,f3
	ctx.cr6.compare(ctx.f0.f64, ctx.f3.f64);
	// blt cr6,0x827607f0
	if (ctx.cr6.lt) goto loc_827607F0;
	// fdivs f6,f1,f0
	ctx.f6.f64 = double(float(ctx.f1.f64 / ctx.f0.f64));
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x827606cc
	if (ctx.cr6.eq) goto loc_827606CC;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// subf r10,r8,r30
	ctx.r10.u64 = ctx.r30.u64 - ctx.r8.u64;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
loc_827606B0:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// lfsx f13,r10,r11
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f7,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f7.f64, ctx.f0.f64)));
	// stfsx f0,r9,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r11.u32, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x827606b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827606B0;
loc_827606CC:
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x827606dc
	if (!ctx.cr6.eq) goto loc_827606DC;
	// stfs f5,-40(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// stfs f31,-36(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + -36, temp.u32);
loc_827606DC:
	// li r11,16
	ctx.r11.s64 = 16;
	// fmr f9,f5
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f5.f64;
	// fmr f8,f5
	ctx.f8.f64 = ctx.f5.f64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// fmr f12,f5
	ctx.f12.f64 = ctx.f5.f64;
	// fmr f11,f5
	ctx.f11.f64 = ctx.f5.f64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_827606F8:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f0,f10
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f10.f64));
	// fmuls f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// fcmpu cr6,f13,f5
	ctx.cr6.compare(ctx.f13.f64, ctx.f5.f64);
	// bgt cr6,0x82760728
	if (ctx.cr6.gt) goto loc_82760728;
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x82760720
	if (!ctx.cr6.eq) goto loc_82760720;
	// fmuls f13,f10,f4
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f4.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82760790
	if (!ctx.cr6.gt) goto loc_82760790;
loc_82760720:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82760760
	goto loc_82760760;
loc_82760728:
	// fcmpu cr6,f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f1.f64);
	// blt cr6,0x82760750
	if (ctx.cr6.lt) goto loc_82760750;
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x82760748
	if (!ctx.cr6.eq) goto loc_82760748;
	// fadds f13,f7,f31
	ctx.f13.f64 = double(float(ctx.f7.f64 + ctx.f31.f64));
	// fmuls f13,f13,f4
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f4.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82760790
	if (!ctx.cr6.lt) goto loc_82760790;
loc_82760748:
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// b 0x82760760
	goto loc_82760760;
loc_82760750:
	// fadds f13,f13,f4
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f4.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f13.u64);
	// lwz r11,-76(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -76);
loc_82760760:
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x82760790
	if (!ctx.cr6.lt) goto loc_82760790;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// lfsx f13,r11,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f30,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f12,f13,f13,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f13.f64, ctx.f13.f64, ctx.f12.f64)));
	// fsubs f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// lfsx f30,r11,r30
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f11,f30,f30,f11
	ctx.f11.f64 = double(float(std::fma(ctx.f30.f64, ctx.f30.f64, ctx.f11.f64)));
	// fmadds f9,f13,f0,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f9.f64)));
	// fmadds f8,f30,f0,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f30.f64, ctx.f0.f64, ctx.f8.f64)));
loc_82760790:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x827606f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827606F8;
	// fcmpu cr6,f12,f5
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f5.f64);
	// ble cr6,0x827607a8
	if (!ctx.cr6.gt) goto loc_827607A8;
	// fdivs f0,f9,f12
	ctx.f0.f64 = double(float(ctx.f9.f64 / ctx.f12.f64));
	// fsubs f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
loc_827607A8:
	// fcmpu cr6,f11,f5
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f11.f64, ctx.f5.f64);
	// ble cr6,0x827607b8
	if (!ctx.cr6.gt) goto loc_827607B8;
	// fdivs f0,f8,f11
	ctx.f0.f64 = double(float(ctx.f8.f64 / ctx.f11.f64));
	// fsubs f7,f7,f0
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f0.f64));
loc_827607B8:
	// fcmpu cr6,f10,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f7.f64);
	// ble cr6,0x827607cc
	if (!ctx.cr6.gt) goto loc_827607CC;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// fmr f10,f7
	ctx.f10.f64 = ctx.f7.f64;
	// fmr f7,f0
	ctx.f7.f64 = ctx.f0.f64;
loc_827607CC:
	// fmuls f0,f9,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fcmpu cr6,f0,f2
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// bge cr6,0x827607e4
	if (!ctx.cr6.lt) goto loc_827607E4;
	// fmuls f0,f8,f8
	ctx.f0.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fcmpu cr6,f0,f2
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// blt cr6,0x827607f0
	if (ctx.cr6.lt) goto loc_827607F0;
loc_827607E4:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8, ctx.xer);
	// blt cr6,0x82760684
	if (ctx.cr6.lt) goto loc_82760684;
loc_827607F0:
	// fcmpu cr6,f10,f5
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f5.f64);
	// bge cr6,0x82760800
	if (!ctx.cr6.lt) goto loc_82760800;
	// fmr f0,f5
	ctx.f0.f64 = ctx.f5.f64;
	// b 0x82760814
	goto loc_82760814;
loc_82760800:
	// fcmpu cr6,f10,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f31.f64);
	// ble cr6,0x82760810
	if (!ctx.cr6.gt) goto loc_82760810;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// b 0x82760814
	goto loc_82760814;
loc_82760810:
	// fmr f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f10.f64;
loc_82760814:
	// stfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fcmpu cr6,f7,f5
	ctx.cr6.compare(ctx.f7.f64, ctx.f5.f64);
	// bge cr6,0x82760828
	if (!ctx.cr6.lt) goto loc_82760828;
	// fmr f0,f5
	ctx.f0.f64 = ctx.f5.f64;
	// b 0x8276083c
	goto loc_8276083C;
loc_82760828:
	// fcmpu cr6,f7,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f7.f64, ctx.f31.f64);
	// ble cr6,0x82760838
	if (!ctx.cr6.gt) goto loc_82760838;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// b 0x8276083c
	goto loc_8276083C;
loc_82760838:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f7.f64;
loc_8276083C:
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfd f30,-32(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827718E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x827718F0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8277193c
	if (!ctx.cr6.gt) goto loc_8277193C;
	// li r30,0
	ctx.r30.s64 = 0;
loc_82771914:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// add r5,r30,r11
	ctx.r5.u64 = ctx.r30.u64 + ctx.r11.u64;
	// bl 0x82771170
	ctx.lr = 0x82771928;
	sub_82771170(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r30,r30,24
	ctx.r30.s64 = ctx.r30.s64 + 24;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82771914
	if (ctx.cr6.lt) goto loc_82771914;
loc_8277193C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82772850) {
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
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r10,r10,34464
	ctx.r10.u64 = ctx.r10.u64 | 34464;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82772900
	if (ctx.cr6.gt) goto loc_82772900;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x82735fb0
	ctx.lr = 0x827728A8;
	sub_82735FB0(ctx, base);
	// cmplwi cr6,r3,122
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 122, ctx.xer);
	// beq cr6,0x827728cc
	if (ctx.cr6.eq) goto loc_827728CC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827728d8
	if (ctx.cr6.eq) goto loc_827728D8;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x82772908
	if (!ctx.cr6.gt) goto loc_82772908;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r3,r11,32775
	ctx.r3.u64 = ctx.r11.u64 | 2147942400;
	// b 0x82772908
	goto loc_82772908;
loc_827728CC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x827728e4
	if (!ctx.cr6.eq) goto loc_827728E4;
loc_827728D8:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// b 0x82772908
	goto loc_82772908;
loc_827728E4:
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// lis r9,-32761
	ctx.r9.s64 = -2147024896;
	// subfc r11,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// ori r10,r9,14
	ctx.r10.u64 = ctx.r9.u64 | 14;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x82772908
	goto loc_82772908;
loc_82772900:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
loc_82772908:
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

DEFINE_REX_FUNC(sub_827761B8) {
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
	// lwz r11,44(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 44);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r3,28(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8277621c
	if (ctx.cr0.eq) goto loc_8277621C;
	// lwz r11,36(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 36);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8277621c
	if (!ctx.cr0.eq) goto loc_8277621C;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
loc_827761FC:
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
	// bne 0x827761fc
	if (!ctx.cr0.eq) goto loc_827761FC;
	// b 0x82776270
	goto loc_82776270;
loc_8277621C:
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// ori r11,r11,65534
	ctx.r11.u64 = ctx.r11.u64 | 65534;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x82776254
	if (!ctx.cr6.eq) goto loc_82776254;
loc_82776234:
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
	// bne 0x82776234
	if (!ctx.cr0.eq) goto loc_82776234;
	// b 0x82776270
	goto loc_82776270;
loc_82776254:
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
	// bne 0x82776254
	if (!ctx.cr0.eq) goto loc_82776254;
loc_82776270:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8277628c
	if (!ctx.cr6.eq) goto loc_8277628C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8277628C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8277628C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8277629c
	if (ctx.cr6.eq) goto loc_8277629C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82788a40
	ctx.lr = 0x8277629C;
	sub_82788A40(ctx, base);
loc_8277629C:
	// li r3,0
	ctx.r3.s64 = 0;
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

DEFINE_REX_FUNC(sub_82780BA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82780BA8;
	__savegprlr_25(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,208(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 208);
	// addi r26,r3,208
	ctx.r26.s64 = ctx.r3.s64 + 208;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x82780cec
	if (ctx.cr6.eq) goto loc_82780CEC;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82780cec
	if (ctx.cr0.eq) goto loc_82780CEC;
loc_82780BCC:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r30,r27,-4
	ctx.r30.s64 = ctx.r27.s64 + -4;
	// lwz r10,228(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 228);
	// subf r9,r11,r26
	ctx.r9.u64 = ctx.r26.u64 - ctx.r11.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// subfic r10,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 & ctx.r11.u64;
	// bne cr6,0x82780ce4
	if (!ctx.cr6.eq) goto loc_82780CE4;
	// lwz r11,288(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 288);
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82780ce4
	if (!ctx.cr0.eq) goto loc_82780CE4;
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82780ce4
	if (ctx.cr0.eq) goto loc_82780CE4;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82780C10:
	// lwz r11,196(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 196);
	// lwzx r31,r11,r29
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82780cd0
	if (!ctx.cr6.eq) goto loc_82780CD0;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82780cd0
	if (!ctx.cr0.eq) goto loc_82780CD0;
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82780cd0
	if (!ctx.cr0.eq) goto loc_82780CD0;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r5,8192
	ctx.r5.s64 = 536870912;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82788ae8
	ctx.lr = 0x82780C50;
	sub_82788AE8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82780cd0
	if (ctx.cr0.lt) goto loc_82780CD0;
	// lis r5,8192
	ctx.r5.s64 = 536870912;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82788ae8
	ctx.lr = 0x82780C74;
	sub_82788AE8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82780cd0
	if (ctx.cr0.lt) goto loc_82780CD0;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// ble cr6,0x82780c94
	if (!ctx.cr6.gt) goto loc_82780C94;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_82780C94:
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r9,2
	ctx.r9.s64 = 2;
	// lis r8,512
	ctx.r8.s64 = 33554432;
	// stb r9,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r9.u8);
	// li r9,32
	ctx.r9.s64 = 32;
	// lwz r7,60(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r6,11
	ctx.r6.s64 = 11;
	// stw r7,89(r1)
	REX_STORE_U32(ctx.r1.u32 + 89, ctx.r7.u32);
	// lis r7,512
	ctx.r7.s64 = 33554432;
	// sth r11,93(r1)
	REX_STORE_U16(ctx.r1.u32 + 93, ctx.r11.u16);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r10,95(r1)
	REX_STORE_U32(ctx.r1.u32 + 95, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8277e648
	ctx.lr = 0x82780CD0;
	sub_8277E648(ctx, base);
loc_82780CD0:
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82780c10
	if (ctx.cr6.lt) goto loc_82780C10;
loc_82780CE4:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x82780bcc
	if (!ctx.cr6.eq) goto loc_82780BCC;
loc_82780CEC:
	// lbz r11,396(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 396);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82780d04
	if (ctx.cr0.eq) goto loc_82780D04;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8277f8d8
	ctx.lr = 0x82780D04;
	sub_8277F8D8(ctx, base);
loc_82780D04:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82788A80) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82788a98
	if (ctx.cr6.eq) goto loc_82788A98;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_82788A98:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4105
	ctx.r3.u64 = ctx.r3.u64 | 4105;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82788FA8) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r8,20(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r4,16(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x8277ebc8
	sub_8277EBC8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82789558) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82789560;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r29,220(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 220);
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// addi r5,r31,12
	ctx.r5.s64 = ctx.r31.s64 + 12;
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r3,r31,57
	ctx.r3.s64 = ctx.r31.s64 + 57;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r5,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// stw r5,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r5.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r4,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// stw r28,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r28.u32);
	// stw r6,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r6.u32);
	// stw r7,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r7.u32);
	// stw r30,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// stw r8,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r8.u32);
	// stw r9,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// stw r30,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stb r10,56(r31)
	REX_STORE_U8(ctx.r31.u32 + 56, ctx.r10.u8);
	// lwz r4,212(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 212);
	// bl 0x8273a030
	ctx.lr = 0x827895CC;
	sub_8273A030(ctx, base);
	// lwz r11,228(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 228);
	// stw r29,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r29.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827895f8
	if (ctx.cr6.eq) goto loc_827895F8;
loc_827895DC:
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
	// bne 0x827895dc
	if (!ctx.cr0.eq) goto loc_827895DC;
loc_827895F8:
	// lis r10,4626
	ctx.r10.s64 = 303169536;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// ori r11,r10,4626
	ctx.r11.u64 = ctx.r10.u64 | 4626;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8278D9A0) {
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
	// lwz r11,1008(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1008);
	// addi r10,r3,1008
	ctx.r10.s64 = ctx.r3.s64 + 1008;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8278d9d0
	if (ctx.cr6.eq) goto loc_8278D9D0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8278d9dc
	if (!ctx.cr0.eq) goto loc_8278D9DC;
loc_8278D9D0:
	// addi r3,r31,184
	ctx.r3.s64 = ctx.r31.s64 + 184;
	// bl 0x82795bd0
	ctx.lr = 0x8278D9D8;
	sub_82795BD0(ctx, base);
	// b 0x8278da3c
	goto loc_8278DA3C;
loc_8278D9DC:
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// subf r10,r5,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r5.u64;
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8278da0c
	if (ctx.cr6.lt) goto loc_8278DA0C;
	// addi r3,r31,184
	ctx.r3.s64 = ctx.r31.s64 + 184;
	// bl 0x82795bd0
	ctx.lr = 0x8278D9FC;
	sub_82795BD0(ctx, base);
	// lbz r11,1184(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1184);
	// ori r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 128;
	// stb r11,1184(r31)
	REX_STORE_U8(ctx.r31.u32 + 1184, ctx.r11.u8);
	// b 0x8278da3c
	goto loc_8278DA3C;
loc_8278DA0C:
	// lwz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8278da24
	if (ctx.cr0.eq) goto loc_8278DA24;
	// lwz r10,236(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8278da3c
	if (ctx.cr6.eq) goto loc_8278DA3C;
loc_8278DA24:
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// addi r3,r31,184
	ctx.r3.s64 = ctx.r31.s64 + 184;
	// subfc r10,r9,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r9.u32;
	ctx.r10.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 & ctx.r11.u64;
	// bl 0x82795b30
	ctx.lr = 0x8278DA3C;
	sub_82795B30(ctx, base);
loc_8278DA3C:
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

DEFINE_REX_FUNC(sub_82793220) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r11,-2988
	ctx.r31.s64 = ctx.r11.s64 + -2988;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82855b44
	ctx.lr = 0x82793248;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,132
	ctx.r5.s64 = 132;
	// addi r4,r11,-3120
	ctx.r4.s64 = ctx.r11.s64 + -3120;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x8279325C;
	sub_8273A030(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82855b34
	ctx.lr = 0x82793264;
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

DEFINE_REX_FUNC(sub_827948B0) {
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
	// li r4,1684
	ctx.r4.s64 = 1684;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82772048
	ctx.lr = 0x827948D0;
	sub_82772048(ctx, base);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x827948e4
	if (!ctx.cr0.eq) goto loc_827948E4;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82794944
	goto loc_82794944;
loc_827948E4:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r10,r10,-28464
	ctx.r10.s64 = ctx.r10.s64 + -28464;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// addi r9,r11,340
	ctx.r9.s64 = ctx.r11.s64 + 340;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r6,r9,80
	ctx.r6.s64 = ctx.r9.s64 + 80;
	// stw r7,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r7,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// stw r10,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r9,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// stw r6,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// stw r10,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// stw r8,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r8.u32);
	// stb r10,340(r11)
	REX_STORE_U8(ctx.r11.u32 + 340, ctx.r10.u8);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82794944:
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

DEFINE_REX_FUNC(sub_827979C0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,204(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// rlwinm. r11,r11,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r3,20
	ctx.r10.s64 = ctx.r3.s64 + 20;
	// lwz r7,24(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r11,516
	ctx.r9.s64 = ctx.r11.s64 + 516;
	// stw r7,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// lwz r8,24(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stw r7,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// stw r9,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// lwz r9,520(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 520);
	// stw r9,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// lwz r9,520(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 520);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,520(r11)
	REX_STORE_U32(ctx.r11.u32 + 520, ctx.r10.u32);
	// lwz r11,204(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// oris r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 268435456;
	// stw r11,204(r3)
	REX_STORE_U32(ctx.r3.u32 + 204, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82799AD0) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82799af4
	if (ctx.cr6.eq) goto loc_82799AF4;
loc_82799ADC:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm. r10,r10,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82799af4
	if (!ctx.cr0.eq) goto loc_82799AF4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x82799adc
	if (!ctx.cr6.eq) goto loc_82799ADC;
loc_82799AF4:
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x82799b24
	if (!ctx.cr6.lt) goto loc_82799B24;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// clrlwi. r10,r10,25
	ctx.r10.u64 = ctx.r10.u32 & 0x7F;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82799b24
	if (ctx.cr0.eq) goto loc_82799B24;
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,37
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 37, ctx.xer);
	// bgt cr6,0x82799b24
	if (ctx.cr6.gt) goto loc_82799B24;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82799B24:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8279C130) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// std r4,24(r1)
	REX_STORE_U64(ctx.r1.u32 + 24, ctx.r4.u64);
	// std r5,32(r1)
	REX_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// std r6,40(r1)
	REX_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	REX_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	REX_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	REX_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	REX_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,408
	ctx.r10.s64 = ctx.r1.s64 + 408;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,260
	ctx.r4.s64 = 260;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82855c74
	ctx.lr = 0x8279C17C;
	__imp___vsnprintf(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r11,355(r1)
	REX_STORE_U8(ctx.r1.u32 + 355, ctx.r11.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827484b0
	ctx.lr = 0x8279C190;
	sub_827484B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8279ED00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8279ED08;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8279ed2c
	if (!ctx.cr6.eq) goto loc_8279ED2C;
	// lis r29,-32768
	ctx.r29.s64 = -2147483648;
	// ori r29,r29,16387
	ctx.r29.u64 = ctx.r29.u64 | 16387;
	// b 0x8279ed6c
	goto loc_8279ED6C;
loc_8279ED2C:
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// li r3,2116
	ctx.r3.s64 = 2116;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x8263b678
	ctx.lr = 0x8279ED3C;
	sub_8263B678(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8279ed4c
	if (ctx.cr0.eq) goto loc_8279ED4C;
	// bl 0x8279e958
	ctx.lr = 0x8279ED48;
	sub_8279E958(ctx, base);
	// b 0x8279ed50
	goto loc_8279ED50;
loc_8279ED4C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8279ED50:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8279ed64
	if (ctx.cr6.eq) goto loc_8279ED64;
	// stw r30,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// b 0x8279ed6c
	goto loc_8279ED6C;
loc_8279ED64:
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
loc_8279ED6C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A1E48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x827A1E50;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ori r4,r4,8
	ctx.r4.u64 = ctx.r4.u64 | 8;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r3,16(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// bl 0x8263b678
	ctx.lr = 0x827A1E78;
	sub_8263B678(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x827a1e8c
	if (!ctx.cr0.eq) goto loc_827A1E8C;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x827a1f10
	goto loc_827A1F10;
loc_827A1E8C:
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// addi r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827a2158
	ctx.lr = 0x827A1E9C;
	sub_827A2158(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x827a1f10
	if (ctx.cr0.lt) goto loc_827A1F10;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r29,r31,8
	ctx.r29.s64 = ctx.r31.s64 + 8;
loc_827A1EAC:
	// lwz r3,0(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827a1ec8
	if (ctx.cr6.eq) goto loc_827A1EC8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x827a2158
	ctx.lr = 0x827A1EC0;
	sub_827A2158(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x827a1f10
	if (ctx.cr0.lt) goto loc_827A1F10;
loc_827A1EC8:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmplwi cr6,r27,2
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 2, ctx.xer);
	// blt cr6,0x827a1eac
	if (ctx.cr6.lt) goto loc_827A1EAC;
	// stw r26,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827a1f04
	if (ctx.cr6.eq) goto loc_827A1F04;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A1EFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x827a1f08
	goto loc_827A1F08;
loc_827A1F04:
	// li r30,1
	ctx.r30.s64 = 1;
loc_827A1F08:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x827a1f1c
	if (!ctx.cr6.lt) goto loc_827A1F1C;
loc_827A1F10:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827a1da0
	ctx.lr = 0x827A1F18;
	sub_827A1DA0(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
loc_827A1F1C:
	// stw r31,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A9338) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x827A9340;
	__savegprlr_27(ctx, base);
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x827abd58
	ctx.lr = 0x827A9360;
	sub_827ABD58(ctx, base);
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r11,r31,32
	ctx.r11.s64 = ctx.r31.s64 + 32;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// li r9,-16
	ctx.r9.s64 = -16;
loc_827A9374:
	// li r8,-32
	ctx.r8.s64 = -32;
	// lvlx128 v63,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r7,48
	ctx.r7.s64 = 48;
	// lvlx128 v62,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,16
	ctx.r4.s64 = 16;
	// lvlx128 v61,r11,r8
	temp.u32 = ctx.r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r8,80
	ctx.r8.s64 = 80;
	// vrlimi128 v61,v63,4,3
	simde_mm_store_ps(ctx.v61.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v63.f32), 57), 4));
	// lvlx128 v60,r11,r7
	temp.u32 = ctx.r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v63,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v63,v60,4,3
	simde_mm_store_ps(ctx.v63.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v60.f32), 57), 4));
	// lvlx128 v60,r11,r5
	temp.u32 = ctx.r11.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v59,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v61,v62,2,2
	simde_mm_store_ps(ctx.v61.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v62.f32), 78), 2));
	// lvlx128 v58,r11,r8
	temp.u32 = ctx.r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// vrlimi128 v63,v60,2,2
	simde_mm_store_ps(ctx.v63.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v60.f32), 78), 2));
	// vrlimi128 v61,v59,1,1
	simde_mm_store_ps(ctx.v61.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v59.f32), 147), 1));
	// vrlimi128 v63,v58,1,1
	simde_mm_store_ps(ctx.v63.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v58.f32), 147), 1));
	// vexptefp128 v62,v61
	ctx.fpscr.enableFlushMode();
	{
		simde__m128 x = simde_mm_load_ps(ctx.v61.f32);
		simde__m128 n = simde_mm_round_ps(x, SIMDE_MM_FROUND_TO_NEG_INF | SIMDE_MM_FROUND_NO_EXC);
		simde__m128 f = simde_mm_sub_ps(x, n);
		simde__m128 p = simde_mm_set1_ps(1.8775767e-3f);
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(8.9893397e-3f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(5.5826318e-2f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(2.4015361e-1f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(6.9315308e-1f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(1.0f));
		simde__m128i exp_bits = simde_mm_slli_epi32(
			simde_mm_add_epi32(simde_mm_cvttps_epi32(n), simde_mm_set1_epi32(127)), 23);
		simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(p, simde_mm_castsi128_ps(exp_bits)));
	}
	// vexptefp128 v63,v63
	{
		simde__m128 x = simde_mm_load_ps(ctx.v63.f32);
		simde__m128 n = simde_mm_round_ps(x, SIMDE_MM_FROUND_TO_NEG_INF | SIMDE_MM_FROUND_NO_EXC);
		simde__m128 f = simde_mm_sub_ps(x, n);
		simde__m128 p = simde_mm_set1_ps(1.8775767e-3f);
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(8.9893397e-3f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(5.5826318e-2f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(2.4015361e-1f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(6.9315308e-1f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(1.0f));
		simde__m128i exp_bits = simde_mm_slli_epi32(
			simde_mm_add_epi32(simde_mm_cvttps_epi32(n), simde_mm_set1_epi32(127)), 23);
		simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(p, simde_mm_castsi128_ps(exp_bits)));
	}
	// stvx128 v62,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bdnz 0x827a9374
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A9374;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r5,260
	ctx.r5.s64 = 260;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// lwz r11,-27576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -27576);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A93FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,432
	ctx.r4.s64 = ctx.r1.s64 + 432;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x827a8458
	ctx.lr = 0x827A940C;
	sub_827A8458(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lfs f12,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// srawi r11,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 1;
	// lfs f11,432(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 432);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r1,164
	ctx.r9.s64 = ctx.r1.s64 + 164;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// lfs f13,24808(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 24808);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,104
	ctx.r11.s64 = ctx.r1.s64 + 104;
	// lfs f0,-20544(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -20544);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f12,f11,f0
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,436
	ctx.r8.s64 = ctx.r1.s64 + 436;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// blt cr6,0x827a947c
	if (ctx.cr6.lt) goto loc_827A947C;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
loc_827A9458:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lfsu f13,4(r8)
	ea = 4 + ctx.r8.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r8.u32 = ea;
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f13,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x827a9458
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A9458;
loc_827A947C:
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r10,r30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x827a9494
	if (ctx.cr6.eq) goto loc_827A9494;
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_827A9494:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827a94d0
	ctx.lr = 0x827A94AC;
	sub_827A94D0(ctx, base);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827a8b78
	ctx.lr = 0x827A94B4;
	sub_827A8B78(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,7996(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7996);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827B3F60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7192(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B4CA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6804(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6804, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5A40) {
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
	// lfs f0,24008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6452(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6452);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6392(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6392, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B69E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-5936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5936);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-5932(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5932, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B77A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-5516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5516);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5512(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8538) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5152(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5152, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B92E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4748(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4748, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA0B8) {
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
	// lfs f0,24840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4400(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4400);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4344(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BAFF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,25104
	ctx.r9.s64 = ctx.r11.s64 + 25104;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,25104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3880(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC130) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-3360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3360);
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

DEFINE_REX_FUNC(sub_827BCFE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,25624
	ctx.r9.s64 = ctx.r11.s64 + 25624;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,25624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2928(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BE300) {
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
	// lfs f0,25848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2448(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2448);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2368(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BF428) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1868(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1868, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0300) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1412);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1408(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1340) {
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
	// lfs f0,26600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1008(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1008);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-928(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2588) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-412(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,48(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 48, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4428) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,496(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5200) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,916(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 916);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,920(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 920, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6050) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1340(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1340, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6F40) {
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
	// addi r11,r8,1800
	ctx.r11.s64 = ctx.r8.s64 + 1800;
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
	// stfs f13,1800(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 1800, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9AD0) {
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
	// lfs f0,28776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2988(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2988);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3104(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3104, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CAC40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,28968
	ctx.r9.s64 = ctx.r11.s64 + 28968;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,28968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3616(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CBEC8) {
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
	// lfs f0,29160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4116(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4116);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4180(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD100) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,4708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4712(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CE1F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29548(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29548);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5200(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CEF38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,5584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5588(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5588, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CFCE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,5988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5988);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5992(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5992, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0DB8) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6372(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6372);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6480(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2038) {
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
	// lfs f0,30120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6900(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6900);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7020(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D3328) {
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
	// lfs f12,7452(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7452);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7572(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,8092(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8092);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8096(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 8096, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4ED8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8380(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5DF0) {
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
	// lfs f0,30760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8732(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8732);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8820(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8820, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7090) {
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
	// lfs f0,30952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9284(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9284);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9364(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8380) {
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
	// lfs f0,31160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9836(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9836);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9916(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D9670) {
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
	// lfs f0,31368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10388(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10388);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10468(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA8E8) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10944(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10944);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11008(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DBB40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,11536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DCC48) {
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
	// lfs f0,31880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31880);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11972(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11972);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12060(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DDDA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,12564(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12564);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12568(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12568, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DEE08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12940(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12940);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13048(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DFC98) {
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
	// lfs f0,32376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13360(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13360);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13472(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0F58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14028(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1F28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14516(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3090) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15008(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3F70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15428);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15432(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4F20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15868(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15868);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15872(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15872, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5DE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-30632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16304(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16304, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6D38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,16728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7D00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17156(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8C20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17588);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17592(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17592, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9A30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// addi r11,r11,-23976
	ctx.r11.s64 = ctx.r11.s64 + -23976;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lfs f13,17964(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17964);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,-26844(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -26844);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// fadds f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f11.f64));
	// lfs f12,17980(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 17980);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,17984(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 17984);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,12(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stfs f0,16(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f0,24(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stfs f0,32(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// stfs f0,40(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// stfs f0,48(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 48, temp.u32);
	// stfs f0,56(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 56, temp.u32);
	// stfs f0,64(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// stfs f0,72(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 72, temp.u32);
	// stfs f0,80(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// stfs f0,88(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 88, temp.u32);
	// stfs f0,96(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// stfs f0,104(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 104, temp.u32);
	// stfs f13,112(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 112, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ED2C0) {
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
	// lfs f0,-21416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19456(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19456);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19552(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19552, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EE6B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-20488
	ctx.r9.s64 = ctx.r11.s64 + -20488;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-20488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20100(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20100, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EFB30) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20612(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20612);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20672(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20672, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0D60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21172(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F1E48) {
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
	// lfs f0,21640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-18184(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -18184);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,21644(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 21644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F32B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F4348) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// ld r11,22596(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 22596);
	// addi r7,r8,22792
	ctx.r7.s64 = ctx.r8.s64 + 22792;
	// ld r10,22604(r10)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r10.u32 + 22604);
	// ld r9,22612(r9)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r9.u32 + 22612);
	// std r11,22792(r8)
	REX_STORE_U64(ctx.r8.u32 + 22792, ctx.r11.u64);
	// std r10,8(r7)
	REX_STORE_U64(ctx.r7.u32 + 8, ctx.r10.u64);
	// std r9,16(r7)
	REX_STORE_U64(ctx.r7.u32 + 16, ctx.r9.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5528) {
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
	// lfs f0,-16024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23252(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23252);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,23368(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6808) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23956(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7758) {
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
	// lfs f0,-14040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,24384(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 24384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8DD8) {
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
	// lfs f0,-11960(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11960);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24920(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24920);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,24976(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 24976, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA008) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25484(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25484, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB088) {
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
	// lfs f0,-9688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25852(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25852);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25960(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25960, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC378) {
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
	// lfs f0,-9496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26404(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26404);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26512(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FD6E0) {
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
	// lfs f0,-9304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26956(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26956);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27076(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27076, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FEA18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27636(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FF7D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28036(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28036);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28040(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800638) {
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
	// lfs f0,-8792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28392);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28460(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828019E0) {
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
	// lfs f0,-8600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28944(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28944);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29032(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29032, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802D68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-8408
	ctx.r9.s64 = ctx.r11.s64 + -8408;
	// lfs f0,-8408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8408);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29604(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 29604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803CD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30048(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30048);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30052(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804AD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30460);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30464(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30464, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805BC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7892);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30952(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828069A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31360(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807830) {
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
	// lfs f0,-7640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31712(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31712);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31784(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31784, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808CA0) {
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
	// lfs f0,-7448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32276(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32276);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A028) {
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
	// lfs f0,-7256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32708(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32708);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-32588(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -32588, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B428) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6996(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6996);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32008(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280C208) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-31604(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31604);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31600(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31600, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280CFB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-31184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31180(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E140) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30668(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30668, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F220) {
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
	// lfs f0,-6304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30296(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30296);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30176(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30176, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810410) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29644(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811350) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29192(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812190) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28772(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28772, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813290) {
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
	// lfs f0,-5448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28352(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28352);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28268(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28268, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828142D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27748(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27748, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815408) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27228(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828163C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26764(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26764);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26760(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26760, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817340) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4212);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26300(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818388) {
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
	// lfs f0,-3896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25844(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25844);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25796(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828195B0) {
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
	// lfs f0,-3672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25364(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25364);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25264(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281AA20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24640(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281BC48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24116(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24116);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24112(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24112, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281CA78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-2840
	ctx.r9.s64 = ctx.r11.s64 + -2840;
	// lfs f0,-2840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23684(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -23684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281D9D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2500);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281EAD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-22716(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22716);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22712(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281FC60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-22208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22204(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828209E0) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21912(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21912);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21804(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21804, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821E30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82822C98) {
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
	// lfs f0,-1496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20844(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20844);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20788(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82823F40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-20232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20228(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82824F78) {
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
	// lfs f0,-1032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19856(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19856);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19752(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826260) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-580(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -580);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19172(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82827180) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-464
	ctx.r9.s64 = ctx.r11.s64 + -464;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18732(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828658) {
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
	// lfs f12,-18232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18232);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18124(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829B50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-17612(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17612);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17508(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282AA68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-17068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17068);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17064(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282B968) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16720(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16720);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16612(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C900) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,636(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 636);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16160(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16160, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282DA38) {
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
	// lfs f0,792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15772(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15772);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15656(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282EDE8) {
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
	// lfs f0,1008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15176(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15176);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15072(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828300C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14516);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14512(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828311C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14004(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832168) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832FB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13112(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13112, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833ED8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12664(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12664, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834E48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12204(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12204);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12200(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836040) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2604(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2604);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11676(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11676, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836E60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-11264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11260(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11260, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837D28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10828(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10828);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838D50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-10356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10356);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-10352(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -10352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839718) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10068);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10064(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283A830) {
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
	// lfs f12,-9680(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9680);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9564(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283BBD0) {
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
	// lfs f0,3616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9112(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9112);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8992(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8992, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283CFD8) {
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
	// lfs f0,3856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8516(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8516);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8408(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283E400) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7820(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7820, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283F260) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7404(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7404);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7400(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7400, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840120) {
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
	// lfs f0,4528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7060(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7060);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6956(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828415D8) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6460(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6460);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6352(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842A60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5756);
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

DEFINE_REX_FUNC(sub_82843900) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5324);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5320(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82844980) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4828(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4828);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845860) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4380(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846808) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3916(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828478C8) {
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
	// lfs f0,6032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3540);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3428(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848DA0) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2928(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2928);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2808(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A1E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6588);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2216(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2216, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284B048) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1792(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284C008) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-1340(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1340);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-1336(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -1336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284CA20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7012);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1040(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D8A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-612(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284E9D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-88(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -88);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-84(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -84, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284F940) {
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
	// lfs f12,268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850BC0) {
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
	// lfs f0,8136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,856(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 856);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,944(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852210) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,1572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1572);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1576(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1576, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852B60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,1856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1856);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1860(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1860, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853648) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2180);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2184(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2184, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82854D98) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r8,3616
	ctx.r6.s64 = ctx.r8.s64 + 3616;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,3616(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 3616);
	// rlwimi r11,r7,1,24,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r11,3616(r8)
	REX_STORE_U32(ctx.r8.u32 + 3616, ctx.r11.u32);
	// stb r10,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r10.u8);
	// lwz r11,3616(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 3616);
	// rlwimi r11,r10,16,8,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFF0000) | (ctx.r11.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r11,3616(r8)
	REX_STORE_U32(ctx.r8.u32 + 3616, ctx.r11.u32);
	// stb r9,3616(r8)
	REX_STORE_U8(ctx.r8.u32 + 3616, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82874DD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82874DD8;
	__savegprlr_25(ctx, base);
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// li r11,16
	ctx.r11.s64 = 16;
	// lvx128 v63,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// vspltish v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_set1_epi16(short(0x1)));
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r31,r9,r4
	ctx.r31.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lvsl v3,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// vspltish v13,2
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x2)));
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lvx128 v46,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r5,r3,r4
	ctx.r5.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lvsl v1,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// add r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lvx128 v59,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v6,v60,v58,v1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// lvx128 v56,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r30,r7,r4
	ctx.r30.u64 = ctx.r7.u64 + ctx.r4.u64;
	// lvsl v7,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r28,1104
	ctx.r28.s64 = 1104;
	// vperm128 v4,v59,v56,v7
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v57,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v2,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v9,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// rlwinm r5,r4,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lvx128 v51,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v31,v63,v57,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// lvsl v6,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v8,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v55,r10,r11
	ea = (ctx.r10.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v4,v54,v51,v6
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvsl v5,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v10,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v2,v61,v55,v5
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// lvx128 v53,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r7,r11
	ea = (ctx.r7.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v26,v62,v46,v3
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// lvx128 v49,r30,r11
	ea = (ctx.r30.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v31,v9,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v52,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v1,v10,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvsl v6,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v7,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v5,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v30,v52,v49,v6
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v5,v53,v50,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// lvx128 v47,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v6,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v48,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v4,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vslh v2,v8,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vperm128 v28,v48,v47,v4
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// lvx128 v27,r6,r28
	ea = (ctx.r6.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v5,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r27,48
	ctx.r27.s64 = 48;
	// vmrghb v4,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r26,96
	ctx.r26.s64 = 96;
	// li r25,144
	ctx.r25.s64 = 144;
	// vslh v29,v7,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsrah v11,v27,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// li r11,192
	ctx.r11.s64 = 192;
	// vslh v25,v6,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vmrghb v3,v0,v28
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vslh v24,v5,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// li r10,240
	ctx.r10.s64 = 240;
	// vslh v23,v4,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// li r9,288
	ctx.r9.s64 = 288;
	// vmrghb v22,v0,v26
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddshs v21,v1,v10
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// li r8,336
	ctx.r8.s64 = 336;
	// vaddshs v20,v31,v9
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vaddshs v19,v2,v8
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vslh v17,v3,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v18,v29,v7
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v16,v25,v6
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v15,v24,v5
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v14,v23,v4
	simde_mm_store_si128((simde__m128i*)ctx.v14.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v0,v17,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v12,v21,v22
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v22.s16)));
	// vaddshs v10,v20,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v9,v19,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vaddshs v8,v18,v8
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v7,v16,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v6,v15,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v5,v14,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v14.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v4,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v3,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v2,v10,v11
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v1,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v31,v8,v11
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v30,v7,v11
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v29,v6,v11
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v28,v5,v11
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v27,v4,v11
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsrah v26,v3,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v25,v2,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v24,v1,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v23,v31,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v22,v30,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v26,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v21,v29,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v25,r29,r27
	ea = (ctx.r29.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v20,v28,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v24,r29,r26
	ea = (ctx.r29.u32 + ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v19,v27,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v23,r29,r25
	ea = (ctx.r29.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r29,r11
	ea = (ctx.r29.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v21,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v20,r29,r9
	ea = (ctx.r29.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v19,r29,r8
	ea = (ctx.r29.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

