#include "harmonyrecomp_funcs.93.h"

DEFINE_REX_FUNC(sub_82216AC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82216AD0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,-2
	ctx.r11.s64 = -2;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82216af0
	if (!ctx.cr6.gt) goto loc_82216AF0;
	// bl 0x82738480
	ctx.lr = 0x82216AF0;
	sub_82738480(ctx, base);
loc_82216AF0:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x82216b10
	if (!ctx.cr6.lt) goto loc_82216B10;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r5,20(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822169f0
	ctx.lr = 0x82216B0C;
	sub_822169F0(ctx, base);
	// b 0x82216b6c
	goto loc_82216B6C;
loc_82216B10:
	// clrlwi. r10,r29,24
	ctx.r10.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82216b44
	if (ctx.cr0.eq) goto loc_82216B44;
	// cmplwi cr6,r30,16
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 16, ctx.xer);
	// bge cr6,0x82216b44
	if (!ctx.cr6.lt) goto loc_82216B44;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82216b30
	if (!ctx.cr6.lt) goto loc_82216B30;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82216B30:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235ec48
	ctx.lr = 0x82216B40;
	sub_8235EC48(ctx, base);
	// b 0x82216b6c
	goto loc_82216B6C;
loc_82216B44:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82216b6c
	if (!ctx.cr6.eq) goto loc_82216B6C;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// blt cr6,0x82216b64
	if (ctx.cr6.lt) goto loc_82216B64;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x82216b68
	goto loc_82216B68;
loc_82216B64:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_82216B68:
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
loc_82216B6C:
	// subfic r11,r30,0
	ctx.xer.ca = ctx.r30.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r30.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8221F180) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8221F188;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,15288
	ctx.r9.s64 = ctx.r11.s64 + 15288;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// lfs f12,15288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15288);
	ctx.f12.f64 = double(temp.f32);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lfs f0,-2820(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2820);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r8,26028
	ctx.r3.s64 = ctx.r8.s64 + 26028;
	// stfs f0,8(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f13,244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 244);
	ctx.f13.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// li r30,3
	ctx.r30.s64 = 3;
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// li r29,-1
	ctx.r29.s64 = -1;
	// stfs f0,16(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// addi r7,r7,1384
	ctx.r7.s64 = ctx.r7.s64 + 1384;
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// stb r11,53(r31)
	REX_STORE_U8(ctx.r31.u32 + 53, ctx.r11.u8);
	// lfs f13,-3052(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3052);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stfs f13,44(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// stb r10,52(r31)
	REX_STORE_U8(ctx.r31.u32 + 52, ctx.r10.u8);
	// stfs f0,40(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// stw r29,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r29.u32);
	// lfs f13,-24416(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -24416);
	ctx.f13.f64 = double(temp.f32);
	// stw r6,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r6.u32);
	// lfs f11,26028(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 26028);
	ctx.f11.f64 = double(temp.f32);
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stb r11,64(r31)
	REX_STORE_U8(ctx.r31.u32 + 64, ctx.r11.u8);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stb r11,65(r31)
	REX_STORE_U8(ctx.r31.u32 + 65, ctx.r11.u8);
	// stfs f0,76(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// stfs f12,80(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stfs f13,84(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 84, temp.u32);
	// stfs f11,88(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 88, temp.u32);
	// stw r7,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// stw r11,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r9,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r9.u32);
	// lwz r9,4(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// stw r9,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r9.u32);
	// bne cr6,0x8221f28c
	if (!ctx.cr6.eq) goto loc_8221F28C;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// b 0x8221f290
	goto loc_8221F290;
loc_8221F28C:
	// stw r10,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r10.u32);
loc_8221F290:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,96(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// bl 0x8221f5c8
	ctx.lr = 0x8221F29C;
	sub_8221F5C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82229F30) {
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
	// lbz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 124);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82229fa4
	if (ctx.cr0.eq) goto loc_82229FA4;
	// lbz r11,93(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 93);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82229f70
	if (!ctx.cr0.eq) goto loc_82229F70;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82229F70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82229F70:
	// lwz r30,108(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x82229f9c
	goto loc_82229F9C;
loc_82229F7C:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82229f98
	if (ctx.cr6.eq) goto loc_82229F98;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82229F98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82229F98:
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_82229F9C:
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82229f7c
	if (!ctx.cr6.eq) goto loc_82229F7C;
loc_82229FA4:
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

DEFINE_REX_FUNC(sub_8222F888) {
	REX_FUNC_PROLOGUE();
	// lwz r3,48(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8222F8B0) {
	REX_FUNC_PROLOGUE();
	// stw r4,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r4.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8222FA50) {
	REX_FUNC_PROLOGUE();
	// stw r4,468(r3)
	REX_STORE_U32(ctx.r3.u32 + 468, ctx.r4.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8222FF08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8222FF10;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x82230aa8
	ctx.lr = 0x8222FF30;
	sub_82230AA8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8222ff70
	if (ctx.cr0.eq) goto loc_8222FF70;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x8222ff48
	if (!ctx.cr6.eq) goto loc_8222FF48;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// b 0x8222ff54
	goto loc_8222FF54;
loc_8222FF48:
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// bne cr6,0x8222ff70
	if (!ctx.cr6.eq) goto loc_8222FF70;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
loc_8222FF54:
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8222FF70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8222FF70:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82233670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82233678;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,252(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 252);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,248(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// addi r31,r3,244
	ctx.r31.s64 = ctx.r3.s64 + 244;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822336fc
	if (ctx.cr0.eq) goto loc_822336FC;
	// li r29,0
	ctx.r29.s64 = 0;
loc_822336A4:
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lfs f1,-7544(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -7544);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822336C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822336DC;
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
	// blt cr6,0x822336a4
	if (ctx.cr6.lt) goto loc_822336A4;
loc_822336FC:
	// lwz r11,268(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 268);
	// addi r31,r30,260
	ctx.r31.s64 = ctx.r30.s64 + 260;
	// lwz r10,264(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// li r28,0
	ctx.r28.s64 = 0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82233774
	if (ctx.cr0.eq) goto loc_82233774;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8223371C:
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lfs f1,-7544(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -7544);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82233738;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82233754;
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
	// blt cr6,0x8223371c
	if (ctx.cr6.lt) goto loc_8223371C;
loc_82233774:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8223EB60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8223EB68;
	__savegprlr_26(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lfs f0,25604(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25604);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x8223eb84
	if (!ctx.cr6.gt) goto loc_8223EB84;
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
loc_8223EB84:
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// addi r11,r11,-13032
	ctx.r11.s64 = ctx.r11.s64 + -13032;
	// clrlwi. r27,r6,24
	ctx.r27.u64 = ctx.r6.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r30,84(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lwz r29,100(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bne 0x8223ebe8
	if (!ctx.cr0.eq) goto loc_8223EBE8;
loc_8223EBC0:
	// beq cr6,0x8223ec10
	if (ctx.cr6.eq) goto loc_8223EC10;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823aebd8
	ctx.lr = 0x8223EBD8;
	sub_823AEBD8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8223ec10
	if (ctx.cr0.eq) goto loc_8223EC10;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8223ed24
	goto loc_8223ED24;
loc_8223EBE8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// beq cr6,0x8223ec00
	if (ctx.cr6.eq) goto loc_8223EC00;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823af008
	ctx.lr = 0x8223EC00;
	sub_823AF008(ctx, base);
loc_8223EC00:
	// rlwinm. r11,r3,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223ec10
	if (ctx.cr0.eq) goto loc_8223EC10;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// b 0x8223ebc0
	goto loc_8223EBC0;
loc_8223EC10:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8231e0d8
	ctx.lr = 0x8223EC1C;
	sub_8231E0D8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r10,r10,23536
	ctx.r10.s64 = ctx.r10.s64 + 23536;
	// stfs f1,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f1,96(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vxor128 v62,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r28.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r11,3456(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// stfs f13,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r28,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r28.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stw r28,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r28.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8223ed00
	if (!ctx.cr6.eq) goto loc_8223ED00;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8223ed24
	if (ctx.cr6.eq) goto loc_8223ED24;
	// li r8,3
	ctx.r8.s64 = 3;
	// b 0x8223ed0c
	goto loc_8223ED0C;
loc_8223ED00:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8223ed24
	if (ctx.cr6.eq) goto loc_8223ED24;
	// li r8,2
	ctx.r8.s64 = 2;
loc_8223ED0C:
	// add r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 + ctx.r29.u64;
	// add r6,r11,r30
	ctx.r6.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823af5b0
	ctx.lr = 0x8223ED24;
	sub_823AF5B0(ctx, base);
loc_8223ED24:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82250F90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82250F98;
	__savegprlr_28(ctx, base);
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62596
	ctx.r11.u64 = ctx.r11.u64 | 62596;
	// ori r10,r10,62608
	ctx.r10.u64 = ctx.r10.u64 | 62608;
	// li r28,1
	ctx.r28.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// stbx r28,r3,r10
	REX_STORE_U8(ctx.r3.u32 + ctx.r10.u32, ctx.r28.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82251014
	if (!ctx.cr6.eq) goto loc_82251014;
loc_82250FCC:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-3040
	ctx.r11.s64 = ctx.r11.s64 + -3040;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// ori r10,r10,62500
	ctx.r10.u64 = ctx.r10.u64 | 62500;
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// ori r9,r9,62476
	ctx.r9.u64 = ctx.r9.u64 | 62476;
	// ori r8,r8,62504
	ctx.r8.u64 = ctx.r8.u64 | 62504;
	// addi r5,r5,-1440
	ctx.r5.s64 = ctx.r5.s64 + -1440;
	// lfs f0,12468(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stwx r6,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r6.u32);
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// stbx r28,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r28.u8);
	// b 0x82251204
	goto loc_82251204;
loc_82251014:
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x824443c8
	ctx.lr = 0x8225101C;
	sub_824443C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82250fcc
	if (ctx.cr0.eq) goto loc_82250FCC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82253c10
	ctx.lr = 0x8225102C;
	sub_82253C10(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82430a88
	ctx.lr = 0x8225103C;
	sub_82430A88(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82251078
	if (ctx.cr6.eq) goto loc_82251078;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f12,f0
	ctx.f12.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x82251078;
	sub_823AEFA8(ctx, base);
loc_82251078:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r29,16
	ctx.r10.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82250fcc
	if (!ctx.cr6.eq) goto loc_82250FCC;
	// ld r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 88);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r30,-32227
	ctx.r30.s64 = -2112028672;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f30.f64 = double(temp.f32);
	// fabs f31,f30
	ctx.f31.u64 = ctx.f30.u64 & ~0x8000000000000000;
	// lfs f13,-18544(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -18544);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f31,f13
	ctx.cr6.compare(ctx.f31.f64, ctx.f13.f64);
	// blt cr6,0x82251130
	if (ctx.cr6.lt) goto loc_82251130;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x825a4a90
	ctx.lr = 0x822510F8;
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
	ctx.lr = 0x8225110C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm. r11,r3,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82251130
	if (!ctx.cr0.eq) goto loc_82251130;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lfs f0,-18544(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -18544);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32219
	ctx.r10.s64 = -2111504384;
	// addi r11,r11,-3028
	ctx.r11.s64 = ctx.r11.s64 + -3028;
	// addi r10,r10,4968
	ctx.r10.s64 = ctx.r10.s64 + 4968;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8225114c
	goto loc_8225114C;
loc_82251130:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r9,-32219
	ctx.r9.s64 = -2111504384;
	// addi r11,r11,-3028
	ctx.r11.s64 = ctx.r11.s64 + -3028;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r9,8256
	ctx.r9.s64 = ctx.r9.s64 + 8256;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lfs f0,1604(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1604);
	ctx.f0.f64 = double(temp.f32);
loc_8225114C:
	// fcmpu cr6,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// ble cr6,0x82251190
	if (!ctx.cr6.gt) goto loc_82251190;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// lis r9,0
	ctx.r9.s64 = 0;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r9,r9,62560
	ctx.r9.u64 = ctx.r9.u64 | 62560;
	// ori r7,r7,62564
	ctx.r7.u64 = ctx.r7.u64 | 62564;
	// lis r6,-32219
	ctx.r6.s64 = -2111504384;
	// lfs f0,224(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r6,-808
	ctx.r10.s64 = ctx.r6.s64 + -808;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stwx r8,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r8.u32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82251190:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// ori r10,r10,62480
	ctx.r10.u64 = ctx.r10.u64 | 62480;
	// lfs f0,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r31,r10
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x822511cc
	if (!ctx.cr6.lt) goto loc_822511CC;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r8,-32219
	ctx.r8.s64 = -2111504384;
	// ori r10,r10,62568
	ctx.r10.u64 = ctx.r10.u64 | 62568;
	// addi r8,r8,-368
	ctx.r8.s64 = ctx.r8.s64 + -368;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stwx r9,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u32);
loc_822511CC:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r10,r10,-3040
	ctx.r10.s64 = ctx.r10.s64 + -3040;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r9,r9,62500
	ctx.r9.u64 = ctx.r9.u64 | 62500;
	// ori r8,r8,62476
	ctx.r8.u64 = ctx.r8.u64 | 62476;
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// ori r7,r7,62504
	ctx.r7.u64 = ctx.r7.u64 | 62504;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stfsx f0,r31,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// stwx r6,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r6.u32);
	// stbx r28,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r28.u8);
loc_82251204:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82271AA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82271AB0;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// ori r11,r11,63076
	ctx.r11.u64 = ctx.r11.u64 | 63076;
	// lbzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82271bc4
	if (ctx.cr0.eq) goto loc_82271BC4;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,-2484
	ctx.r11.s64 = ctx.r11.s64 + -2484;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi. r25,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r25.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq 0x82271b94
	if (ctx.cr0.eq) goto loc_82271B94;
	// lbz r11,466(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 466);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82271b94
	if (!ctx.cr0.eq) goto loc_82271B94;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// beq cr6,0x82271b94
	if (ctx.cr6.eq) goto loc_82271B94;
	// addis r28,r3,1
	ctx.r28.s64 = ctx.r3.s64 + 65536;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// addi r28,r28,-2480
	ctx.r28.s64 = ctx.r28.s64 + -2480;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
loc_82271B1C:
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
	// beq cr6,0x82271b48
	if (ctx.cr6.eq) goto loc_82271B48;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_82271B48:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,-13032(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + -13032);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwzx r4,r30,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
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
	// beq cr6,0x82271b7c
	if (ctx.cr6.eq) goto loc_82271B7C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b0af8
	ctx.lr = 0x82271B7C;
	sub_823B0AF8(ctx, base);
loc_82271B7C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82271b94
	if (!ctx.cr0.eq) goto loc_82271B94;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r26,r25
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x82271b1c
	if (ctx.cr6.lt) goto loc_82271B1C;
loc_82271B94:
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
	// beq cr6,0x82271bb8
	if (ctx.cr6.eq) goto loc_82271BB8;
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
loc_82271BB8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82231670
	ctx.lr = 0x82271BC4;
	sub_82231670(ctx, base);
loc_82271BC4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8227B960) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8227b830
	ctx.lr = 0x8227B99C;
	sub_8227B830(ctx, base);
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// stvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	ctx.r11.s64 = 48;
	// lvx128 v62,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stvx128 v62,r31,r9
	ea = (ctx.r31.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r10
	ea = (ctx.r31.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

DEFINE_REX_FUNC(sub_82286C10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x82286C18;
	__savegprlr_21(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r27,r27,-3048
	ctx.r27.s64 = ctx.r27.s64 + -3048;
	// addi r25,r11,11952
	ctx.r25.s64 = ctx.r11.s64 + 11952;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lwz r23,0(r27)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f0,-14140(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -14140);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r3,88
	ctx.r30.s64 = ctx.r3.s64 + 88;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r7,204(r23)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r23.u32 + 204);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r7,20(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 20);
	// lfs f13,8(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
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
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
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
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82286CB0;
	sub_8255F918(ctx, base);
	// addi r28,r31,96
	ctx.r28.s64 = ctx.r31.s64 + 96;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82322d08
	ctx.lr = 0x82286CC4;
	sub_82322D08(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r21,r11,12468
	ctx.r21.s64 = ctx.r11.s64 + 12468;
	// lfs f12,152(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// ori r24,r10,62401
	ctx.r24.u64 = ctx.r10.u64 | 62401;
	// lfs f0,700(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 700);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x82286d00
	if (!ctx.cr6.lt) goto loc_82286D00;
	// lbzx r11,r31,r24
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r24.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82286d00
	if (!ctx.cr0.eq) goto loc_82286D00;
	// li r4,12
	ctx.r4.s64 = 12;
	// b 0x8228706c
	goto loc_8228706C;
loc_82286D00:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r22,0
	ctx.r22.s64 = 0;
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// lwz r29,-13032(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82286d44
	if (ctx.cr6.eq) goto loc_82286D44;
	// lfs f0,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823aefa8
	ctx.lr = 0x82286D40;
	sub_823AEFA8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
loc_82286D44:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82286d78
	if (ctx.cr6.eq) goto loc_82286D78;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f13,100(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aefa8
	ctx.lr = 0x82286D78;
	sub_823AEFA8(ctx, base);
loc_82286D78:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,0
	ctx.r10.s64 = 0;
	// clrlwi r9,r26,24
	ctx.r9.u64 = ctx.r26.u32 & 0xFF;
	// ori r29,r10,62585
	ctx.r29.u64 = ctx.r10.u64 | 62585;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82286f30
	if (ctx.cr6.eq) goto loc_82286F30;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lbzx r11,r31,r24
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r24.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// bne 0x82286dd8
	if (!ctx.cr0.eq) goto loc_82286DD8;
	// lfs f0,-14132(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -14132);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// b 0x82286f0c
	goto loc_82286F0C;
loc_82286DD8:
	// lfs f11,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bgt cr6,0x82286de8
	if (ctx.cr6.gt) goto loc_82286DE8;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
loc_82286DE8:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82286ee0
	if (ctx.cr0.eq) goto loc_82286EE0;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r10,24624
	ctx.r8.s64 = ctx.r10.s64 + 24624;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,24624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24624);
	ctx.f13.f64 = double(temp.f32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x82286e30
	if (ctx.cr6.lt) goto loc_82286E30;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
loc_82286E30:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82286ee0
	if (ctx.cr0.eq) goto loc_82286EE0;
	// lwz r9,40(r23)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r23.u32 + 40);
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82286e88
	if (!ctx.cr6.eq) goto loc_82286E88;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f12,27176(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 27176);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f10,f12
	ctx.cr6.compare(ctx.f10.f64, ctx.f12.f64);
	// bgt cr6,0x82286e80
	if (ctx.cr6.gt) goto loc_82286E80;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
loc_82286E80:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82286ed0
	if (!ctx.cr0.eq) goto loc_82286ED0;
loc_82286E88:
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x82286ee0
	if (!ctx.cr6.eq) goto loc_82286EE0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f13,27184(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 27184);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x82286ec8
	if (ctx.cr6.lt) goto loc_82286EC8;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
loc_82286EC8:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82286ee0
	if (ctx.cr0.eq) goto loc_82286EE0;
loc_82286ED0:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3144
	ctx.r30.s64 = ctx.r30.s64 + -3144;
	// stw r22,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r22.u32);
	// b 0x82287004
	goto loc_82287004;
loc_82286EE0:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
loc_82286F0C:
	// blt cr6,0x82286f14
	if (ctx.cr6.lt) goto loc_82286F14;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
loc_82286F14:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r30,r30,-3144
	ctx.r30.s64 = ctx.r30.s64 + -3144;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// beq 0x82287000
	if (ctx.cr0.eq) goto loc_82287000;
	// stbx r11,r31,r29
	REX_STORE_U8(ctx.r31.u32 + ctx.r29.u32, ctx.r11.u8);
	// b 0x82287004
	goto loc_82287004;
loc_82286F30:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8228a410
	ctx.lr = 0x82286F38;
	sub_8228A410(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,0(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,40(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82286f90
	if (!ctx.cr6.eq) goto loc_82286F90;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bgt cr6,0x82286f88
	if (ctx.cr6.gt) goto loc_82286F88;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
loc_82286F88:
	// clrlwi. r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82286fd0
	if (!ctx.cr0.eq) goto loc_82286FD0;
loc_82286F90:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x82286fe4
	if (!ctx.cr6.eq) goto loc_82286FE4;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82286fc8
	if (ctx.cr6.lt) goto loc_82286FC8;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_82286FC8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82286fe4
	if (ctx.cr0.eq) goto loc_82286FE4;
loc_82286FD0:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// li r11,2
	ctx.r11.s64 = 2;
	// addi r30,r30,-3144
	ctx.r30.s64 = ctx.r30.s64 + -3144;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x82287004
	goto loc_82287004;
loc_82286FE4:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,6
	ctx.r4.s64 = 6;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r30,-3144
	ctx.r30.s64 = ctx.r30.s64 + -3144;
	// bl 0x825a49b0
	ctx.lr = 0x82286FFC;
	sub_825A49B0(ctx, base);
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
loc_82287000:
	// stbx r22,r31,r29
	REX_STORE_U8(ctx.r31.u32 + ctx.r29.u32, ctx.r22.u8);
loc_82287004:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// blt cr6,0x82287018
	if (ctx.cr6.lt) goto loc_82287018;
	// stw r22,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r22.u32);
	// stbx r22,r31,r29
	REX_STORE_U8(ctx.r31.u32 + ctx.r29.u32, ctx.r22.u8);
loc_82287018:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82287068
	if (ctx.cr6.lt) goto loc_82287068;
	// beq cr6,0x82287060
	if (ctx.cr6.eq) goto loc_82287060;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82287058
	if (ctx.cr6.lt) goto loc_82287058;
	// beq cr6,0x82287050
	if (ctx.cr6.eq) goto loc_82287050;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x82287048
	if (ctx.cr6.lt) goto loc_82287048;
	// bne cr6,0x8228707c
	if (!ctx.cr6.eq) goto loc_8228707C;
	// li r4,17
	ctx.r4.s64 = 17;
	// b 0x8228706c
	goto loc_8228706C;
loc_82287048:
	// li r4,16
	ctx.r4.s64 = 16;
	// b 0x8228706c
	goto loc_8228706C;
loc_82287050:
	// li r4,10
	ctx.r4.s64 = 10;
	// b 0x8228706c
	goto loc_8228706C;
loc_82287058:
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x8228706c
	goto loc_8228706C;
loc_82287060:
	// li r4,8
	ctx.r4.s64 = 8;
	// b 0x8228706c
	goto loc_8228706C;
loc_82287068:
	// li r4,6
	ctx.r4.s64 = 6;
loc_8228706C:
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-232(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -232);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8227e158
	ctx.lr = 0x8228707C;
	sub_8227E158(ctx, base);
loc_8228707C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822B2178) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x822B2180;
	__savegprlr_26(ctx, base);
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x8273af28
	ctx.lr = 0x822B2188;
	__savefpr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fmr f31,f2
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f2.f64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// lfs f28,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f28.f64 = double(temp.f32);
	// fcmpu cr6,f1,f28
	ctx.cr6.compare(ctx.f1.f64, ctx.f28.f64);
	// ble cr6,0x822b22c4
	if (!ctx.cr6.gt) goto loc_822B22C4;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
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
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f1
	ctx.cr6.compare(ctx.f13.f64, ctx.f1.f64);
	// bgt cr6,0x822b21e4
	if (ctx.cr6.gt) goto loc_822B21E4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B21E4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b21f4
	if (ctx.cr0.eq) goto loc_822B21F4;
	// stfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// b 0x822b2238
	goto loc_822B2238;
loc_822B21F4:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fneg f13,f1
	ctx.f13.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
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
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x822b222c
	if (ctx.cr6.lt) goto loc_822B222C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B222C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b2238
	if (ctx.cr0.eq) goto loc_822B2238;
	// stfs f13,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
loc_822B2238:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f1
	ctx.cr6.compare(ctx.f13.f64, ctx.f1.f64);
	// bgt cr6,0x822b2270
	if (ctx.cr6.gt) goto loc_822B2270;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B2270:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b2280
	if (ctx.cr0.eq) goto loc_822B2280;
	// stfs f1,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// b 0x822b22c4
	goto loc_822B22C4;
loc_822B2280:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
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
	// fneg f13,f1
	ctx.f13.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
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
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x822b22b8
	if (ctx.cr6.lt) goto loc_822B22B8;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B22B8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b22c4
	if (ctx.cr0.eq) goto loc_822B22C4;
	// stfs f13,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
loc_822B22C4:
	// addis r29,r27,1
	ctx.r29.s64 = ctx.r27.s64 + 65536;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r29,r29,-1292
	ctx.r29.s64 = ctx.r29.s64 + -1292;
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// beq 0x822b268c
	if (ctx.cr0.eq) goto loc_822B268C;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addis r31,r27,1
	ctx.r31.s64 = ctx.r27.s64 + 65536;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r31,r31,-1272
	ctx.r31.s64 = ctx.r31.s64 + -1272;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
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
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f11,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	ctx.cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// blt cr6,0x822b2354
	if (ctx.cr6.lt) goto loc_822B2354;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B2354:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822b23d4
	if (!ctx.cr0.eq) goto loc_822B23D4;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v13,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8d70
	ctx.lr = 0x822B23B8;
	sub_822A8D70(ctx, base);
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bgt cr6,0x822b23cc
	if (ctx.cr6.gt) goto loc_822B23CC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B23CC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b23d8
	if (ctx.cr0.eq) goto loc_822B23D8;
loc_822B23D4:
	// stfs f28,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
loc_822B23D8:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f13,4(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lbz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// ori r30,r6,64268
	ctx.r30.u64 = ctx.r6.u64 | 64268;
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,26612(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 26612);
	ctx.f30.f64 = double(temp.f32);
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// beq 0x822b2450
	if (ctx.cr0.eq) goto loc_822B2450;
	// lfsx f12,r27,r30
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + ctx.r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// b 0x822b2454
	goto loc_822B2454;
loc_822B2450:
	// fmr f12,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f30.f64;
loc_822B2454:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f11,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	ctx.cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// blt cr6,0x822b2470
	if (ctx.cr6.lt) goto loc_822B2470;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B2470:
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f29,-18544(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -18544);
	ctx.f29.f64 = double(temp.f32);
	// bne 0x822b24fc
	if (!ctx.cr0.eq) goto loc_822B24FC;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8dd8
	ctx.lr = 0x822B24DC;
	sub_822A8DD8(ctx, base);
	// fsubs f0,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 - ctx.f29.f64));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x822b24f4
	if (ctx.cr6.gt) goto loc_822B24F4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B24F4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b2500
	if (ctx.cr0.eq) goto loc_822B2500;
loc_822B24FC:
	// stfs f28,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
loc_822B2500:
	// lbz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822b2514
	if (ctx.cr0.eq) goto loc_822B2514;
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// b 0x822b2518
	goto loc_822B2518;
loc_822B2514:
	// fmr f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f30.f64;
loc_822B2518:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x822b2550
	if (ctx.cr6.lt) goto loc_822B2550;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B2550:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b2574
	if (ctx.cr0.eq) goto loc_822B2574;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822b2568
	if (ctx.cr6.eq) goto loc_822B2568;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// b 0x822b256c
	goto loc_822B256C;
loc_822B2568:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f30.f64;
loc_822B256C:
	// stfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// b 0x822b25c4
	goto loc_822B25C4;
loc_822B2574:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8d70
	ctx.lr = 0x822B259C;
	sub_822A8D70(ctx, base);
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bgt cr6,0x822b25b0
	if (ctx.cr6.gt) goto loc_822B25B0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B25B0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b25c4
	if (ctx.cr0.eq) goto loc_822B25C4;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x822a8d70
	ctx.lr = 0x822B25C0;
	sub_822A8D70(ctx, base);
	// stfs f1,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
loc_822B25C4:
	// lbz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822b25d8
	if (ctx.cr0.eq) goto loc_822B25D8;
	// lfsx f13,r27,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + ctx.r30.u32);
	ctx.f13.f64 = double(temp.f32);
	// b 0x822b25dc
	goto loc_822B25DC;
loc_822B25D8:
	// fmr f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f30.f64;
loc_822B25DC:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,4(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
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
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x822b2614
	if (ctx.cr6.lt) goto loc_822B2614;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B2614:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b2634
	if (ctx.cr0.eq) goto loc_822B2634;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822b262c
	if (ctx.cr6.eq) goto loc_822B262C;
	// lfsx f0,r27,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + ctx.r30.u32);
	ctx.f0.f64 = double(temp.f32);
	// b 0x822b2a10
	goto loc_822B2A10;
loc_822B262C:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f30.f64;
	// b 0x822b2a10
	goto loc_822B2A10;
loc_822B2634:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8dd8
	ctx.lr = 0x822B265C;
	sub_822A8DD8(ctx, base);
	// fsubs f0,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 - ctx.f29.f64));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x822b2674
	if (ctx.cr6.gt) goto loc_822B2674;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B2674:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b2a14
	if (ctx.cr0.eq) goto loc_822B2A14;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x822a8dd8
	ctx.lr = 0x822B2684;
	sub_822A8DD8(ctx, base);
	// fsubs f0,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 - ctx.f29.f64));
	// b 0x822b2a10
	goto loc_822B2A10;
loc_822B268C:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r7,-32227
	ctx.r7.s64 = -2112028672;
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
	// lfs f30,26612(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 26612);
	ctx.f30.f64 = double(temp.f32);
	// lvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f30
	ctx.cr6.compare(ctx.f12.f64, ctx.f30.f64);
	// blt cr6,0x822b26f4
	if (ctx.cr6.lt) goto loc_822B26F4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B26F4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822b2788
	if (!ctx.cr0.eq) goto loc_822B2788;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
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
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82577228
	ctx.lr = 0x822B2754;
	sub_82577228(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// li r11,1
	ctx.r11.s64 = 1;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x822b2780
	if (ctx.cr6.gt) goto loc_822B2780;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B2780:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b278c
	if (ctx.cr0.eq) goto loc_822B278C;
loc_822B2788:
	// stfs f28,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
loc_822B278C:
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f13,4(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f12,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f30
	ctx.cr6.compare(ctx.f12.f64, ctx.f30.f64);
	// blt cr6,0x822b27fc
	if (ctx.cr6.lt) goto loc_822B27FC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B27FC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822b2890
	if (!ctx.cr0.eq) goto loc_822B2890;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
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
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82577290
	ctx.lr = 0x822B285C;
	sub_82577290(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// li r11,1
	ctx.r11.s64 = 1;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x822b2888
	if (ctx.cr6.gt) goto loc_822B2888;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B2888:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b2894
	if (ctx.cr0.eq) goto loc_822B2894;
loc_822B2890:
	// stfs f28,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
loc_822B2894:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
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
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	ctx.cr6.compare(ctx.f13.f64, ctx.f30.f64);
	// blt cr6,0x822b28cc
	if (ctx.cr6.lt) goto loc_822B28CC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B28CC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b28dc
	if (ctx.cr0.eq) goto loc_822B28DC;
	// stfs f30,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// b 0x822b2954
	goto loc_822B2954;
loc_822B28DC:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82577228
	ctx.lr = 0x822B2900;
	sub_82577228(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x822b292c
	if (ctx.cr6.gt) goto loc_822B292C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B292C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b2954
	if (ctx.cr0.eq) goto loc_822B2954;
	// bl 0x82577228
	ctx.lr = 0x822B2938;
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
	// fsubs f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// stfs f0,0(r26)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
loc_822B2954:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,4(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
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
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	ctx.cr6.compare(ctx.f13.f64, ctx.f30.f64);
	// blt cr6,0x822b298c
	if (ctx.cr6.lt) goto loc_822B298C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B298C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b299c
	if (ctx.cr0.eq) goto loc_822B299C;
	// stfs f30,4(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r26.u32 + 4, temp.u32);
	// b 0x822b2a14
	goto loc_822B2A14;
loc_822B299C:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82577290
	ctx.lr = 0x822B29C0;
	sub_82577290(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x822b29ec
	if (ctx.cr6.gt) goto loc_822B29EC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822B29EC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822b2a14
	if (ctx.cr0.eq) goto loc_822B2A14;
	// bl 0x82577290
	ctx.lr = 0x822B29F8;
	sub_82577290(ctx, base);
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
	// fsubs f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
loc_822B2A10:
	// stfs f0,4(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 4, temp.u32);
loc_822B2A14:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x8273af74
	ctx.lr = 0x822B2A20;
	__restfpr_28(ctx, base);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82304E60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82304E68;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r27,552(r3)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r3.u32 + 552);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x82429a18
	ctx.lr = 0x82304E7C;
	sub_82429A18(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r29,7
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 7, ctx.xer);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,20068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r28,92(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// beq cr6,0x82304eb4
	if (ctx.cr6.eq) goto loc_82304EB4;
	// ld r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 88);
	// b 0x82304ec0
	goto loc_82304EC0;
loc_82304EB4:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62524
	ctx.r11.u64 = ctx.r11.u64 | 62524;
	// ldx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + ctx.r11.u32);
loc_82304EC0:
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// bl 0x82428150
	ctx.lr = 0x82304EC8;
	sub_82428150(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// ori r11,r11,62448
	ctx.r11.u64 = ctx.r11.u64 | 62448;
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82304ee8
	if (ctx.cr6.lt) goto loc_82304EE8;
	// li r30,64
	ctx.r30.s64 = 64;
loc_82304EE8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a48b0
	ctx.lr = 0x82304EF4;
	sub_825A48B0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lis r8,0
	ctx.r8.s64 = 0;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// addi r4,r4,-3164
	ctx.r4.s64 = ctx.r4.s64 + -3164;
	// ori r10,r10,62380
	ctx.r10.u64 = ctx.r10.u64 | 62380;
	// clrlwi r6,r30,24
	ctx.r6.u64 = ctx.r30.u32 & 0xFF;
	// ori r8,r8,62384
	ctx.r8.u64 = ctx.r8.u64 | 62384;
	// clrlwi r7,r29,28
	ctx.r7.u64 = ctx.r29.u32 & 0xF;
	// stwx r28,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r28.u32);
	// stw r27,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r27.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// stwx r9,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stbx r7,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r7.u8);
	// li r3,15
	ctx.r3.s64 = 15;
	// bl 0x82429ff8
	ctx.lr = 0x82304F44;
	sub_82429FF8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82309768) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82309770;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r29,r3,1
	ctx.r29.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r29,-3160
	ctx.r29.s64 = ctx.r29.s64 + -3160;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82309a24
	if (ctx.cr6.eq) goto loc_82309A24;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// lfs f13,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lis r26,-32226
	ctx.r26.s64 = -2111963136;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f0,-8644(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823097B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// ori r11,r11,62428
	ctx.r11.u64 = ctx.r11.u64 | 62428;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x823097DC;
	sub_8224A2A0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r30,r11,-588
	ctx.r30.s64 = ctx.r11.s64 + -588;
	// addi r28,r10,-604
	ctx.r28.s64 = ctx.r10.s64 + -604;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r25,0(r11)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r27,0(r25)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// bl 0x8255f918
	ctx.lr = 0x82309808;
	sub_8255F918(ctx, base);
	// lwz r11,56(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 56);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8230981C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f0,-8644(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f13,52(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82309844;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
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
	ctx.lr = 0x82309860;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r11,-596
	ctx.r4.s64 = ctx.r11.s64 + -596;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r26,0(r11)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r27,0(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// bl 0x8255f918
	ctx.lr = 0x82309880;
	sub_8255F918(ctx, base);
	// lwz r11,56(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 56);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82309894;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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
	ctx.lr = 0x823098B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823098ec
	if (ctx.cr0.eq) goto loc_823098EC;
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
	ctx.lr = 0x823098E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,20(r10)
	REX_STORE_U8(ctx.r10.u32 + 20, ctx.r11.u8);
loc_823098EC:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x823098FC;
	sub_8255F918(ctx, base);
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r27,r27,-3116
	ctx.r27.s64 = ctx.r27.s64 + -3116;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x8255f918
	ctx.lr = 0x82309914;
	sub_8255F918(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r10,r10,32256
	ctx.r10.s64 = ctx.r10.s64 + 32256;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
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
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// stw r11,24(r9)
	REX_STORE_U32(ctx.r9.u32 + 24, ctx.r11.u32);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// stw r11,28(r9)
	REX_STORE_U32(ctx.r9.u32 + 28, ctx.r11.u32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,60(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 60, temp.u32);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,64(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 64, temp.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r29,0(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x8255f918
	ctx.lr = 0x823099F4;
	sub_8255F918(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x82309A04;
	sub_8255F918(ctx, base);
	// lwz r11,56(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 56);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82309A18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8233c470
	ctx.lr = 0x82309A24;
	sub_8233C470(ctx, base);
loc_82309A24:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823218C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x823218C8;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addis r25,r3,1
	ctx.r25.s64 = ctx.r3.s64 + 65536;
	// addi r23,r11,624
	ctx.r23.s64 = ctx.r11.s64 + 624;
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r27,r3,244
	ctx.r27.s64 = ctx.r3.s64 + 244;
	// li r28,4
	ctx.r28.s64 = 4;
	// lfs f31,7436(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 7436);
	ctx.f31.f64 = double(temp.f32);
	// addi r25,r25,-2932
	ctx.r25.s64 = ctx.r25.s64 + -2932;
	// addi r26,r26,-2896
	ctx.r26.s64 = ctx.r26.s64 + -2896;
	// li r29,16
	ctx.r29.s64 = 16;
	// li r30,255
	ctx.r30.s64 = 255;
	// li r24,0
	ctx.r24.s64 = 0;
loc_82321904:
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8225f630
	ctx.lr = 0x82321918;
	sub_8225F630(ctx, base);
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x82321970
	if (ctx.cr6.gt) goto loc_82321970;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// stb r24,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r24.u8);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82321960;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62644
	ctx.r11.u64 = ctx.r11.u64 | 62644;
	// stbx r24,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r24.u8);
	// b 0x8232199c
	goto loc_8232199C;
loc_82321970:
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stb r30,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r30.u8);
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// stb r30,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// stb r30,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r30.u8);
	// lwzx r3,r29,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bctrl 
	ctx.lr = 0x8232199C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8232199C:
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x823219d0
	if (!ctx.cr6.lt) goto loc_823219D0;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823219D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823219D0:
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpwi cr6,r29,32
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 32, ctx.xer);
	// blt cr6,0x82321904
	if (ctx.cr6.lt) goto loc_82321904;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823219F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82321a3c
	if (ctx.cr0.eq) goto loc_82321A3C;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// ble cr6,0x82321a34
	if (!ctx.cr6.gt) goto loc_82321A34;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82321A34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82321A34:
	// lfs f0,984(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 984);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82321b1c
	goto loc_82321B1C;
loc_82321A3C:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82321A54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82321a80
	if (ctx.cr0.eq) goto loc_82321A80;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// ble cr6,0x82321b18
	if (!ctx.cr6.gt) goto loc_82321B18;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// b 0x82321b04
	goto loc_82321B04;
loc_82321A80:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82321A98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82321ac4
	if (ctx.cr0.eq) goto loc_82321AC4;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// ble cr6,0x82321b18
	if (!ctx.cr6.gt) goto loc_82321B18;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x82321b04
	goto loc_82321B04;
loc_82321AC4:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82321ADC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82321b28
	if (ctx.cr0.eq) goto loc_82321B28;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// ble cr6,0x82321b18
	if (!ctx.cr6.gt) goto loc_82321B18;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,28(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
loc_82321B04:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82321B18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82321B18:
	// lfs f0,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_82321B1C:
	// lfs f13,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,0(r26)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
loc_82321B28:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82334F98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82334FA0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82230b40
	ctx.lr = 0x82334FAC;
	sub_82230B40(ctx, base);
	// lbz r11,544(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 544);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8233505c
	if (ctx.cr0.eq) goto loc_8233505C;
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r31,r31,-3048
	ctx.r31.s64 = ctx.r31.s64 + -3048;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8233503c
	if (ctx.cr6.eq) goto loc_8233503C;
	// bl 0x824281d8
	ctx.lr = 0x82334FD4;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82335004
	if (ctx.cr0.eq) goto loc_82335004;
	// bl 0x824281d8
	ctx.lr = 0x82334FE0;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8233503c
	if (ctx.cr0.eq) goto loc_8233503C;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82429960
	ctx.lr = 0x82334FF0;
	sub_82429960(ctx, base);
	// clrlwi r28,r3,24
	ctx.r28.u64 = ctx.r3.u32 & 0xFF;
	// bl 0x8242a5e0
	ctx.lr = 0x82334FF8;
	sub_8242A5E0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8233503c
	if (!ctx.cr6.eq) goto loc_8233503C;
loc_82335004:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
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
	// bne cr6,0x82335038
	if (!ctx.cr6.eq) goto loc_82335038;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82335038
	if (ctx.cr6.eq) goto loc_82335038;
	// bl 0x82431638
	ctx.lr = 0x82335038;
	sub_82431638(ctx, base);
loc_82335038:
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_8233503C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// lis r9,-32205
	ctx.r9.s64 = -2110586880;
	// ori r10,r10,62380
	ctx.r10.u64 = ctx.r10.u64 | 62380;
	// addi r9,r9,24784
	ctx.r9.s64 = ctx.r9.s64 + 24784;
	// stwx r9,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r9.u32);
	// stwx r29,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r29.u32);
loc_8233505C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82339C70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82339C78;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r30,r11,-4080
	ctx.r30.s64 = ctx.r11.s64 + -4080;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f2,13600(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13600);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,284(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 284);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82339C9C;
	sub_825A4A40(ctx, base);
	// fmr f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f1.f64;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f12,140(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 140);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,144(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,1060(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1060);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1056(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1056);
	ctx.f13.f64 = double(temp.f32);
	// fadds f2,f0,f13
	ctx.f2.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fmuls f0,f10,f12
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fctid f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fnmsubs f0,f0,f11,f10
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f11.f64, -ctx.f10.f64)));
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// bl 0x825a4a40
	ctx.lr = 0x82339CE0;
	sub_825A4A40(ctx, base);
	// stfs f1,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// lis r29,-32228
	ctx.r29.s64 = -2112094208;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r28,r29,17288
	ctx.r28.s64 = ctx.r29.s64 + 17288;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r27,r11,-30236
	ctx.r27.s64 = ctx.r11.s64 + -30236;
	// lfs f2,-30236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30236);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-28428(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -28428);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82339D04;
	sub_825A4A40(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// lfs f1,128(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// stfs f9,100(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 100, temp.u32);
	// lfs f0,-16652(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16652);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 104, temp.u32);
	// bl 0x822ea1a8
	ctx.lr = 0x82339D20;
	sub_822EA1A8(ctx, base);
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// fmuls f0,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r11,31600
	ctx.r6.s64 = ctx.r11.s64 + 31600;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r11,64
	ctx.r11.s64 = 64;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r31,112
	ctx.r7.s64 = ctx.r31.s64 + 112;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,236(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// lvsr v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// li r10,4
	ctx.r10.s64 = 4;
	// li r8,64
	ctx.r8.s64 = 64;
	// lvx128 v63,r6,r11
	ea = (ctx.r6.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// vperm128 v12,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,-31120
	ctx.r11.s64 = ctx.r11.s64 + -31120;
	// lvsr v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v12,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r6,r8
	ea = (ctx.r6.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v12,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v12,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x82339DA4;
	sub_822EA1A8(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// lfs f0,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// li r10,64
	ctx.r10.s64 = 64;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// vor v0,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// lvsr v7,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r6,r10
	ea = (ctx.r6.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vperm128 v12,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// lvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v12,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lvsl v7,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// vor128 v63,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vperm128 v61,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lwz r9,24(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 24);
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
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
	// lvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bctrl 
	ctx.lr = 0x82339E80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-5336(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -5336);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,18868(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 18868);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82339E90;
	sub_825A4A40(ctx, base);
	// stfs f1,136(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 136, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,17288(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 17288);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-1980(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -1980);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82339EA4;
	sub_825A4A40(ctx, base);
	// lfs f12,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,108(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-1980(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -1980);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// fmadds f13,f12,f1,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f1.f64, ctx.f13.f64)));
	// stfs f0,164(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 164, temp.u32);
	// stfs f13,152(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 152, temp.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8234FD00) {
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
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// std r4,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r4.u64);
	// addi r4,r3,88
	ctx.r4.s64 = ctx.r3.s64 + 88;
	// addi r31,r11,1808
	ctx.r31.s64 = ctx.r11.s64 + 1808;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x8255f918
	ctx.lr = 0x8234FD30;
	sub_8255F918(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8255f918
	ctx.lr = 0x8234FD38;
	sub_8255F918(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r31,-13032(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8234fd74
	if (ctx.cr6.eq) goto loc_8234FD74;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,92(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x8234FD74;
	sub_823AEFA8(ctx, base);
loc_8234FD74:
	// clrlwi r30,r3,24
	ctx.r30.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8234fdac
	if (ctx.cr6.eq) goto loc_8234FDAC;
	// lfs f0,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,156(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x8234FDAC;
	sub_823AEFA8(ctx, base);
loc_8234FDAC:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
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

DEFINE_REX_FUNC(sub_82355570) {
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
	// ori r4,r4,64864
	ctx.r4.u64 = ctx.r4.u64 | 64864;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82355598;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823555a8
	if (ctx.cr0.eq) goto loc_823555A8;
	// bl 0x823551f0
	ctx.lr = 0x823555A4;
	sub_823551F0(ctx, base);
	// b 0x823555ac
	goto loc_823555AC;
loc_823555A8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823555AC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823570D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee4
	ctx.lr = 0x823570E0;
	__savegprlr_15(ctx, base);
	// stfd f31,-152(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -152, ctx.f31.u64);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// fmr f9,f1
	ctx.f9.f64 = ctx.f1.f64;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r27,r11,12468
	ctx.r27.s64 = ctx.r11.s64 + 12468;
	// lis r17,-32110
	ctx.r17.s64 = -2104360960;
	// lwz r11,-30672(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -30672);
	// clrlwi. r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8235711c
	if (!ctx.cr0.eq) goto loc_8235711C;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// lfs f0,1132(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1132);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-30676(r17)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r17.u32 + -30676, temp.u32);
	// stw r11,-30672(r10)
	REX_STORE_U32(ctx.r10.u32 + -30672, ctx.r11.u32);
loc_8235711C:
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// rlwinm. r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lis r15,-32110
	ctx.r15.s64 = -2104360960;
	// addi r29,r9,-4080
	ctx.r29.s64 = ctx.r9.s64 + -4080;
	// bne 0x82357140
	if (!ctx.cr0.eq) goto loc_82357140;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// lfs f0,236(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-30680(r15)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r15.u32 + -30680, temp.u32);
	// stw r11,-30672(r10)
	REX_STORE_U32(ctx.r10.u32 + -30672, ctx.r11.u32);
loc_82357140:
	// rlwinm. r8,r11,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// bne 0x82357160
	if (!ctx.cr0.eq) goto loc_82357160;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// lfs f8,960(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 960);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,-30684(r9)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r9.u32 + -30684, temp.u32);
	// stw r11,-30672(r10)
	REX_STORE_U32(ctx.r10.u32 + -30672, ctx.r11.u32);
	// b 0x82357164
	goto loc_82357164;
loc_82357160:
	// lfs f8,-30684(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30684);
	ctx.f8.f64 = double(temp.f32);
loc_82357164:
	// rlwinm. r8,r11,0,28,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// bne 0x82357184
	if (!ctx.cr0.eq) goto loc_82357184;
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// lfs f10,2088(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2088);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,-30688(r9)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r9.u32 + -30688, temp.u32);
	// stw r11,-30672(r10)
	REX_STORE_U32(ctx.r10.u32 + -30672, ctx.r11.u32);
	// b 0x82357188
	goto loc_82357188;
loc_82357184:
	// lfs f10,-30688(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30688);
	ctx.f10.f64 = double(temp.f32);
loc_82357188:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// fmr f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f9.f64;
	// addi r30,r30,-1492
	ctx.r30.s64 = ctx.r30.s64 + -1492;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82358bb0
	ctx.lr = 0x8235719C;
	sub_82358BB0(ctx, base);
	// addis r19,r31,1
	ctx.r19.s64 = ctx.r31.s64 + 65536;
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// addi r19,r19,-1512
	ctx.r19.s64 = ctx.r19.s64 + -1512;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// bl 0x8249e7a8
	ctx.lr = 0x823571B0;
	sub_8249E7A8(ctx, base);
	// addis r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 65536;
	// addi r26,r26,-1600
	ctx.r26.s64 = ctx.r26.s64 + -1600;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x8249e7a8
	ctx.lr = 0x823571C0;
	sub_8249E7A8(ctx, base);
	// addis r20,r31,1
	ctx.r20.s64 = ctx.r31.s64 + 65536;
	// addi r20,r20,-1580
	ctx.r20.s64 = ctx.r20.s64 + -1580;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// bl 0x8249e7a8
	ctx.lr = 0x823571D0;
	sub_8249E7A8(ctx, base);
	// addis r23,r31,1
	ctx.r23.s64 = ctx.r31.s64 + 65536;
	// addi r23,r23,-1552
	ctx.r23.s64 = ctx.r23.s64 + -1552;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x8249e7a8
	ctx.lr = 0x823571E0;
	sub_8249E7A8(ctx, base);
	// addis r21,r31,1
	ctx.r21.s64 = ctx.r31.s64 + 65536;
	// addi r21,r21,-1532
	ctx.r21.s64 = ctx.r21.s64 + -1532;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// bl 0x8249e7a8
	ctx.lr = 0x823571F0;
	sub_8249E7A8(ctx, base);
	// lfs f0,140(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r28,r28,-1608
	ctx.r28.s64 = ctx.r28.s64 + -1608;
	// addi r29,r29,-1560
	ctx.r29.s64 = ctx.r29.s64 + -1560;
	// li r11,18
	ctx.r11.s64 = 18;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// lfs f12,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lfs f11,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// li r16,0
	ctx.r16.s64 = 0;
	// addi r9,r9,-752
	ctx.r9.s64 = ctx.r9.s64 + -752;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r25,r25,-3136
	ctx.r25.s64 = ctx.r25.s64 + -3136;
	// addi r7,r10,-4
	ctx.r7.s64 = ctx.r10.s64 + -4;
	// mr r8,r16
	ctx.r8.u64 = ctx.r16.u64;
	// addi r10,r9,-4
	ctx.r10.s64 = ctx.r9.s64 + -4;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// lfs f7,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,0(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f12,f7,f9,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f7.f64, ctx.f9.f64, ctx.f12.f64)));
	// fmadds f11,f9,f6,f11
	ctx.f11.f64 = double(float(std::fma(ctx.f9.f64, ctx.f6.f64, ctx.f11.f64)));
	// fmuls f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fctid f7,f7
	ctx.f7.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// fctid f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fcfid f7,f7
	ctx.f7.f64 = double(ctx.f7.s64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f7,f7
	ctx.f7.f64 = double(float(ctx.f7.f64));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fnmsubs f12,f7,f13,f12
	ctx.f12.f64 = double(float(-std::fma(ctx.f7.f64, ctx.f13.f64, -ctx.f12.f64)));
	// stfs f12,0(r28)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// fnmsubs f0,f0,f13,f11
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f11.f64)));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
loc_82357280:
	// li r6,16
	ctx.r6.s64 = 16;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// lvsl v0,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// vperm128 v62,v62,v62,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfsu f0,4(r7)
	ea = 4 + ctx.r7.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x82357280
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82357280;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r22,1
	ctx.r22.s64 = 1;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x82357368
	if (ctx.cr6.eq) goto loc_82357368;
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// li r5,17
	ctx.r5.s64 = 17;
loc_823572EC:
	// cmplwi cr6,r7,18
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 18, ctx.xer);
	// bge cr6,0x82357354
	if (!ctx.cr6.lt) goto loc_82357354;
	// subfic r6,r7,18
	ctx.xer.ca = ctx.r7.u32 <= 18;
	ctx.r6.u64 = static_cast<uint64_t>(18) - ctx.r7.u64;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r8,r9,4
	ctx.r8.s64 = ctx.r9.s64 + 4;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_82357304:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82357348
	if (!ctx.cr6.gt) goto loc_82357348;
	// fctidz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// std r6,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lwz r4,0(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stw r6,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// stw r4,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_82357348:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bdnz 0x82357304
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82357304;
loc_82357354:
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x823572ec
	if (!ctx.cr0.eq) goto loc_823572EC;
loc_82357368:
	// addis r24,r31,1
	ctx.r24.s64 = ctx.r31.s64 + 65536;
	// addi r24,r24,-3160
	ctx.r24.s64 = ctx.r24.s64 + -3160;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82357b0c
	if (ctx.cr6.lt) goto loc_82357B0C;
	// beq cr6,0x82357ad0
	if (ctx.cr6.eq) goto loc_82357AD0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8235779c
	if (ctx.cr6.lt) goto loc_8235779C;
	// beq cr6,0x82357778
	if (ctx.cr6.eq) goto loc_82357778;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x823576a0
	if (ctx.cr6.lt) goto loc_823576A0;
	// beq cr6,0x82357624
	if (ctx.cr6.eq) goto loc_82357624;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bge cr6,0x82357b90
	if (!ctx.cr6.lt) goto loc_82357B90;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// blt cr6,0x823573d0
	if (ctx.cr6.lt) goto loc_823573D0;
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f10
	ctx.f1.f64 = ctx.f10.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8224a2a0
	ctx.lr = 0x823573D0;
	sub_8224A2A0(ctx, base);
loc_823573D0:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lfs f0,1908(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-1424
	ctx.r11.s64 = ctx.r11.s64 + -1424;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f9,f13
	ctx.f13.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82357b90
	if (ctx.cr6.lt) goto loc_82357B90;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,19
	ctx.r10.s64 = 19;
	// addi r9,r11,32720
	ctx.r9.s64 = ctx.r11.s64 + 32720;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// li r5,-68
	ctx.r5.s64 = -68;
	// addi r11,r11,-3068
	ctx.r11.s64 = ctx.r11.s64 + -3068;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// vor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// li r6,-52
	ctx.r6.s64 = -52;
	// addi r7,r10,31600
	ctx.r7.s64 = ctx.r10.s64 + 31600;
	// addi r4,r9,2688
	ctx.r4.s64 = ctx.r9.s64 + 2688;
loc_82357428:
	// li r10,8
	ctx.r10.s64 = 8;
	// vor128 v13,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// li r9,64
	ctx.r9.s64 = 64;
	// lvx128 v0,r11,r5
	ea = (ctx.r11.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,8
	ctx.r8.s64 = 8;
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// li r3,64
	ctx.r3.s64 = 64;
	// li r29,-36
	ctx.r29.s64 = -36;
	// lvsr v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// lvx128 v63,r7,r9
	ea = (ctx.r7.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v11,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvsr v7,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vsel v11,v0,v13,v11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v11,r11,r5
	ea = (ctx.r11.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r7,r3
	ea = (ctx.r7.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v13,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v0,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v13,v0,v12,v13
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// stvx128 v13,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	ea = (ctx.r11.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,-4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x823574b4
	if (ctx.cr6.eq) goto loc_823574B4;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r10
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x823574b0
	if (ctx.cr6.eq) goto loc_823574B0;
loc_82357498:
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82357498
	if (!ctx.cr6.eq) goto loc_82357498;
loc_823574B0:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_823574B4:
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// bdnz 0x82357428
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82357428;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,2
	ctx.r7.s64 = 2;
	// fmr f1,f10
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f10.f64;
	// ori r11,r11,64740
	ctx.r11.u64 = ctx.r11.u64 | 64740;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// stbx r16,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r16.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x823574E8;
	sub_8224A2A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,63840
	ctx.r11.u64 = ctx.r11.u64 | 63840;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// mr r8,r16
	ctx.r8.u64 = ctx.r16.u64;
	// lvx128 v63,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v0,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
	// bl 0x82358d08
	ctx.lr = 0x82357548;
	sub_82358D08(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lfs f31,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// ld r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lfs f3,-232(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -232);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,28(r30)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r30.u32 + 28, temp.u32);
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// stfs f31,24(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 24, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// stw r10,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r10.u32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// std r9,16(r30)
	REX_STORE_U64(ctx.r30.u32 + 16, ctx.r9.u64);
	// bl 0x8249e720
	ctx.lr = 0x82357584;
	sub_8249E720(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f3,1908(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1908);
	ctx.f3.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,28324(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28324);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,28320(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28320);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8249e720
	ctx.lr = 0x823575A4;
	sub_8249E720(ctx, base);
	// lis r30,-32228
	ctx.r30.s64 = -2112094208;
	// lfs f3,1908(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1908);
	ctx.f3.f64 = double(temp.f32);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// addi r29,r30,17288
	ctx.r29.s64 = ctx.r30.s64 + 17288;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,-15380(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -15380);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8249e720
	ctx.lr = 0x823575C4;
	sub_8249E720(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f3,1908(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1908);
	ctx.f3.f64 = double(temp.f32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// ori r11,r11,63932
	ctx.r11.u64 = ctx.r11.u64 | 63932;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,28312(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28312);
	ctx.f1.f64 = double(temp.f32);
	// stfsx f31,r31,r11
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f2,28316(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28316);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8249e720
	ctx.lr = 0x823575F0;
	sub_8249E720(ctx, base);
	// lfs f3,1908(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1908);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-28428(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -28428);
	ctx.f2.f64 = double(temp.f32);
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// lfs f1,17288(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 17288);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8249e720
	ctx.lr = 0x82357608;
	sub_8249E720(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// ori r11,r11,63980
	ctx.r11.u64 = ctx.r11.u64 | 63980;
	// mr r22,r16
	ctx.r22.u64 = ctx.r16.u64;
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
	// stfsx f31,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// b 0x82357b90
	goto loc_82357B90;
loc_82357624:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// blt cr6,0x82357654
	if (ctx.cr6.lt) goto loc_82357654;
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f10
	ctx.f1.f64 = ctx.f10.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8224a2a0
	ctx.lr = 0x82357654;
	sub_8224A2A0(ctx, base);
loc_82357654:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// fmr f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f9.f64;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-1680
	ctx.r11.s64 = ctx.r11.s64 + -1680;
	// addi r10,r10,-1696
	ctx.r10.s64 = ctx.r10.s64 + -1696;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r9,r9,2720
	ctx.r9.s64 = ctx.r9.s64 + 2720;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82358628
	ctx.lr = 0x82357690;
	sub_82358628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82357b90
	if (!ctx.cr0.eq) goto loc_82357B90;
	// li r10,6
	ctx.r10.s64 = 6;
	// b 0x82357784
	goto loc_82357784;
loc_823576A0:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r11,r11,-1424
	ctx.r11.s64 = ctx.r11.s64 + -1424;
	// addi r10,r10,17288
	ctx.r10.s64 = ctx.r10.s64 + 17288;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f9,f0
	ctx.f13.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// lfs f0,-12848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12848);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82357b90
	if (ctx.cr6.lt) goto loc_82357B90;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,64740
	ctx.r11.u64 = ctx.r11.u64 | 64740;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r4,-1412
	ctx.r4.s64 = ctx.r4.s64 + -1412;
	// stbx r22,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r22.u8);
	// bl 0x82358920
	ctx.lr = 0x823576E4;
	sub_82358920(ctx, base);
	// lfs f31,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,0(r29)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// stfs f31,0(r28)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f3,f31
	ctx.f3.f64 = ctx.f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8249e720
	ctx.lr = 0x82357708;
	sub_8249E720(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8249e720
	ctx.lr = 0x82357720;
	sub_8249E720(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8249e720
	ctx.lr = 0x82357738;
	sub_8249E720(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8249e720
	ctx.lr = 0x82357750;
	sub_8249E720(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x82357770;
	sub_8224A2A0(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x82357b04
	goto loc_82357B04;
loc_82357778:
	// clrlwi. r11,r18,24
	ctx.r11.u64 = ctx.r18.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82357b90
	if (ctx.cr0.eq) goto loc_82357B90;
	// li r10,4
	ctx.r10.s64 = 4;
loc_82357784:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
	// ori r11,r11,64112
	ctx.r11.u64 = ctx.r11.u64 | 64112;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// b 0x82357b90
	goto loc_82357B90;
loc_8235779C:
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r11,73(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 73);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82357b90
	if (!ctx.cr0.eq) goto loc_82357B90;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// addi r9,r9,-1416
	ctx.r9.s64 = ctx.r9.s64 + -1416;
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82357ab0
	if (ctx.cr6.lt) goto loc_82357AB0;
	// ld r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 96);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r8,r16
	ctx.r8.u64 = ctx.r16.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r29,r29,-1412
	ctx.r29.s64 = ctx.r29.s64 + -1412;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r28,r31,120
	ctx.r28.s64 = ctx.r31.s64 + 120;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lvsl v0,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v0,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v60,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
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
	// std r11,0(r29)
	REX_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
	// bl 0x825a4da8
	ctx.lr = 0x82357878;
	sub_825A4DA8(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f31.f64 = double(temp.f32);
	// fabs f0,f31
	ctx.f0.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f8
	ctx.cr6.compare(ctx.f0.f64, ctx.f8.f64);
	// ble cr6,0x823578e0
	if (!ctx.cr6.gt) goto loc_823578E0;
	// fabs f0,f31
	ctx.f0.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// fdivs f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// fmuls f31,f0,f8
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// fneg f0,f31
	ctx.f0.u64 = ctx.f31.u64 ^ 0x8000000000000000;
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
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8221ada0
	ctx.lr = 0x823578C0;
	sub_8221ADA0(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823bcf40
	ctx.lr = 0x823578D0;
	sub_823BCF40(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
loc_823578E0:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8231e0d8
	ctx.lr = 0x823578EC;
	sub_8231E0D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f3,-232(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -232);
	ctx.f3.f64 = double(temp.f32);
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// ori r10,r10,63888
	ctx.r10.u64 = ctx.r10.u64 | 63888;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfsx f0,r31,r10
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f0,0(r19)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r19.u32 + 0, temp.u32);
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// bl 0x8249e720
	ctx.lr = 0x82357928;
	sub_8249E720(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// lvsl v0,r0,r16
	temp.u32 = ctx.r16.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f12,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lvsl v7,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// vperm128 v63,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// addi r11,r7,32496
	ctx.r11.s64 = ctx.r7.s64 + 32496;
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32228
	ctx.r7.s64 = -2112094208;
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r7,17288
	ctx.r7.s64 = ctx.r7.s64 + 17288;
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r8,4(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stfs f12,104(r1)
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
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stw r9,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// lfs f2,-4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -4);
	ctx.f2.f64 = double(temp.f32);
	// stw r8,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r8.u32);
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// stfs f0,24(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 24, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f3,-232(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -232);
	ctx.f3.f64 = double(temp.f32);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f3,28(r30)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r30.u32 + 28, temp.u32);
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
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,16(r30)
	REX_STORE_U64(ctx.r30.u32 + 16, ctx.r11.u64);
	// bl 0x8249e720
	ctx.lr = 0x82357A90;
	sub_8249E720(ctx, base);
	// lfs f2,-30680(r15)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + -30680);
	ctx.f2.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lfs f3,-232(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -232);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x8249e720
	ctx.lr = 0x82357AA8;
	sub_8249E720(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x82357b04
	goto loc_82357B04;
loc_82357AB0:
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f1,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8224a2a0
	ctx.lr = 0x82357ACC;
	sub_8224A2A0(ctx, base);
	// b 0x82357b8c
	goto loc_82357B8C;
loc_82357AD0:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// blt cr6,0x82357b90
	if (ctx.cr6.lt) goto loc_82357B90;
	// li r7,2
	ctx.r7.s64 = 2;
	// fmr f1,f10
	ctx.f1.f64 = ctx.f10.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8224a2a0
	ctx.lr = 0x82357B00;
	sub_8224A2A0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
loc_82357B04:
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// b 0x82357b90
	goto loc_82357B90;
loc_82357B0C:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// addi r30,r11,17288
	ctx.r30.s64 = ctx.r11.s64 + 17288;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,-5340(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -5340);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,-12848(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -12848);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x8249e720
	ctx.lr = 0x82357B2C;
	sub_8249E720(ctx, base);
	// lfs f2,-30676(r17)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + -30676);
	ctx.f2.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lfs f3,-12848(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -12848);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x8249e720
	ctx.lr = 0x82357B44;
	sub_8249E720(ctx, base);
	// lfs f31,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// lfs f3,-12848(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -12848);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8249e720
	ctx.lr = 0x82357B60;
	sub_8249E720(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x82357B80;
	sub_8224A2A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,64120
	ctx.r11.u64 = ctx.r11.u64 | 64120;
	// stwx r16,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r16.u32);
loc_82357B8C:
	// stw r22,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r22.u32);
loc_82357B90:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -152);
	// b 0x82739f34
	__restgprlr_15(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823A9848) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x823A9850;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273aef0
	ctx.lr = 0x823A9858;
	__savefpr_14(ctx, base);
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823A9870;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823aa058
	if (ctx.cr0.eq) goto loc_823AA058;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823A988C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823aa058
	if (ctx.cr0.eq) goto loc_823AA058;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lfs f13,232(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,260(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 260);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f0,252(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 252);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r30,292
	ctx.r3.s64 = ctx.r30.s64 + 292;
	// mullw r26,r10,r11
	ctx.r26.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lfs f12,236(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// extsw r11,r26
	ctx.r11.s64 = ctx.r26.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f17,f13
	ctx.f17.f64 = double(float(ctx.f13.f64));
	// fdivs f19,f0,f17
	ctx.f19.f64 = double(float(ctx.f0.f64 / ctx.f17.f64));
	// bl 0x8245d190
	ctx.lr = 0x823A98D4;
	sub_8245D190(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r30,308
	ctx.r3.s64 = ctx.r30.s64 + 308;
	// stw r31,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r31.u32);
	// bl 0x8245d190
	ctx.lr = 0x823A98E4;
	sub_8245D190(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stw r3,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// beq cr6,0x823aa058
	if (ctx.cr6.eq) goto loc_823AA058;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823aa058
	if (ctx.cr6.eq) goto loc_823AA058;
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823aa058
	if (ctx.cr6.eq) goto loc_823AA058;
	// lwz r7,256(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 256);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f0,284(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 284);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,424(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// extsw r9,r7
	ctx.r9.s64 = ctx.r7.s32;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f26,32368(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 32368);
	ctx.f26.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r27,r11,14376
	ctx.r27.s64 = ctx.r11.s64 + 14376;
	// addi r6,r10,-4080
	ctx.r6.s64 = ctx.r10.s64 + -4080;
	// lfs f23,-1908(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -1908);
	ctx.f23.f64 = double(temp.f32);
	// lfs f2,236(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 236);
	ctx.f2.f64 = double(temp.f32);
	// fmr f25,f23
	ctx.f25.f64 = ctx.f23.f64;
	// fdivs f13,f26,f13
	ctx.f13.f64 = double(float(ctx.f26.f64 / ctx.f13.f64));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// fadds f1,f0,f2
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f2.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x823A9958;
	sub_822EA1A8(ctx, base);
	// lfs f16,-776(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -776);
	ctx.f16.f64 = double(temp.f32);
	// li r29,0
	ctx.r29.s64 = 0;
	// fmuls f24,f1,f16
	ctx.f24.f64 = double(float(ctx.f1.f64 * ctx.f16.f64));
	// lfs f31,-2140(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -2140);
	ctx.f31.f64 = double(temp.f32);
	// stfs f24,136(r1)
	temp.f32 = float(ctx.f24.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x823a9e10
	if (!ctx.cr6.gt) goto loc_823A9E10;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f22,144(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 144);
	ctx.f22.f64 = double(temp.f32);
	// lfs f21,140(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 140);
	ctx.f21.f64 = double(temp.f32);
	// mulli r24,r26,160
	ctx.r24.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(160));
	// lfs f20,1612(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1612);
	ctx.f20.f64 = double(temp.f32);
	// addi r25,r5,80
	ctx.r25.s64 = ctx.r5.s64 + 80;
loc_823A998C:
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
	// fmr f9,f25
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f25.f64;
	// fmr f18,f24
	ctx.f18.f64 = ctx.f24.f64;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x823a99ac
	if (!ctx.cr6.eq) goto loc_823A99AC;
	// lfs f24,136(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f24.f64 = double(temp.f32);
	// fmr f25,f23
	ctx.f25.f64 = ctx.f23.f64;
	// b 0x823a9a44
	goto loc_823A9A44;
loc_823A99AC:
	// lwz r10,256(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 256);
	// addi r9,r29,1
	ctx.r9.s64 = ctx.r29.s64 + 1;
	// extsw r8,r7
	ctx.r8.s64 = ctx.r7.s32;
	// lfs f0,284(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 284);
	ctx.f0.f64 = double(temp.f32);
	// subf r11,r29,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r29.u64;
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// std r8,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r8.u64);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lfd f13,296(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 296);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r9,312(r1)
	REX_STORE_U64(ctx.r1.u32 + 312, ctx.r9.u64);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfd f12,312(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 312);
	// std r10,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r10.u64);
	// lfd f11,224(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 224);
	// std r11,240(r1)
	REX_STORE_U64(ctx.r1.u32 + 240, ctx.r11.u64);
	// lfd f10,240(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 240);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fmuls f12,f12,f26
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f26.f64));
	// fmuls f10,f10,f26
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f26.f64));
	// fdivs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f13.f64));
	// fdivs f11,f10,f11
	ctx.f11.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// fmuls f12,f11,f21
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f21.f64));
	// fadds f1,f0,f2
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f2.f64));
	// fctid f13,f12
	ctx.f13.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// fcfid f0,f13
	ctx.f0.f64 = double(ctx.f13.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fnmsubs f25,f0,f22,f11
	ctx.f25.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f22.f64, -ctx.f11.f64)));
	// bl 0x822ea1a8
	ctx.lr = 0x823A9A40;
	sub_822EA1A8(ctx, base);
	// fmuls f24,f1,f16
	ctx.fpscr.disableFlushMode();
	ctx.f24.f64 = double(float(ctx.f1.f64 * ctx.f16.f64));
loc_823A9A44:
	// lwz r9,240(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 240);
	// lfs f0,276(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 276);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f3,f31,f0
	ctx.f3.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// rotlwi r10,r29,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r29.u32, 1);
	// divw r11,r29,r9
	ctx.r11.u64 = uint32_t((ctx.r9.s32 && !(ctx.r29.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r29.s32 / ctx.r9.s32 : 0);
	// fmr f4,f23
	ctx.f4.f64 = ctx.f23.f64;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// fadds f1,f9,f2
	ctx.f1.f64 = double(float(ctx.f9.f64 + ctx.f2.f64));
	// mullw r11,r11,r9
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// std r8,320(r1)
	REX_STORE_U64(ctx.r1.u32 + 320, ctx.r8.u64);
	// lfd f0,320(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 320);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// subf r11,r11,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r11.u64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// std r11,256(r1)
	REX_STORE_U64(ctx.r1.u32 + 256, ctx.r11.u64);
	// lfd f13,256(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 256);
	// std r8,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r8.u64);
	// lfd f12,304(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 304);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// andc r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// twllei r9,0
	if (ctx.r9.s32 == 0 || ctx.r9.u32 < 0u) ppc_trap(ctx, base, 0);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// twlgei r11,-1
	if (ctx.r11.s32 == -1 || ctx.r11.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fdivs f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// fdivs f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x823A9AC4;
	sub_822EA1A8(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// fmr f1,f9
	ctx.f1.f64 = ctx.f9.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x823A9AD0;
	sub_822EA1A8(ctx, base);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// fadds f1,f25,f2
	ctx.f1.f64 = double(float(ctx.f25.f64 + ctx.f2.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x823A9ADC;
	sub_822EA1A8(ctx, base);
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// fmr f1,f25
	ctx.f1.f64 = ctx.f25.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x823A9AE8;
	sub_822EA1A8(ctx, base);
	// lfs f6,244(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 244);
	ctx.f6.f64 = double(temp.f32);
	// fmr f27,f1
	ctx.f27.f64 = ctx.f1.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f5,f6
	ctx.f5.f64 = ctx.f6.f64;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x823a9dfc
	if (!ctx.cr6.gt) goto loc_823A9DFC;
	// stfs f23,184(r1)
	temp.f32 = float(ctx.f23.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r5,r30,272
	ctx.r5.s64 = ctx.r30.s64 + 272;
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r4,r30,268
	ctx.r4.s64 = ctx.r30.s64 + 268;
	// stfs f23,200(r1)
	temp.f32 = float(ctx.f23.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// stfs f31,204(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f23,216(r1)
	temp.f32 = float(ctx.f23.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f31,220(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f23,104(r1)
	temp.f32 = float(ctx.f23.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f8,152(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f8,160(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f7,168(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_823A9B3C:
	// lwz r9,264(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// rotlwi r11,r7,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// lwa r8,260(r30)
	ctx.r8.s64 = int32_t(REX_LOAD_U32(ctx.r30.u32 + 260));
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r6,r7,r9
	ctx.r6.u64 = uint32_t((ctx.r9.s32 && !(ctx.r7.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r7.s32 / ctx.r9.s32 : 0);
	// std r8,232(r1)
	REX_STORE_U64(ctx.r1.u32 + 232, ctx.r8.u64);
	// divw r8,r7,r9
	ctx.r8.u64 = uint32_t((ctx.r9.s32 && !(ctx.r7.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r7.s32 / ctx.r9.s32 : 0);
	// std r9,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// mullw r6,r6,r9
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// fmr f9,f6
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f6.f64;
	// fmr f8,f5
	ctx.f8.f64 = ctx.f5.f64;
	// subf r6,r6,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r6.u64;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// std r8,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.r8.u64);
	// extsw r28,r9
	ctx.r28.s64 = ctx.r9.s32;
	// std r6,336(r1)
	REX_STORE_U64(ctx.r1.u32 + 336, ctx.r6.u64);
	// lfd f13,336(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 336);
	// std r28,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.r28.u64);
	// lfd f0,272(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 272);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lfd f12,288(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 288);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lfd f11,232(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 232);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lfd f10,144(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// andc r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ~ctx.r11.u64;
	// andc r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// twllei r9,0
	if (ctx.r9.s32 == 0 || ctx.r9.u32 < 0u) ppc_trap(ctx, base, 0);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// twllei r9,0
	if (ctx.r9.s32 == 0 || ctx.r9.u32 < 0u) ppc_trap(ctx, base, 0);
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// twlgei r11,-1
	if (ctx.r11.s32 == -1 || ctx.r11.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// twlgei r10,-1
	if (ctx.r10.s32 == -1 || ctx.r10.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fmuls f13,f13,f26
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f26.f64));
	// fmuls f12,f12,f26
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f26.f64));
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// fdivs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fdivs f13,f13,f10
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fadds f0,f0,f18
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f18.f64));
	// fadds f7,f13,f24
	ctx.f7.f64 = double(float(ctx.f13.f64 + ctx.f24.f64));
	// fmuls f13,f0,f21
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f21.f64));
	// fctid f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f0,f13,f22,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f22.f64, -ctx.f0.f64)));
	// fadds f1,f0,f2
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f2.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x823A9C28;
	sub_822EA1A8(ctx, base);
	// fmuls f0,f7,f21
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f7.f64 * ctx.f21.f64));
	// fadds f13,f1,f20
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f20.f64));
	// fctid f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fmadds f6,f13,f19,f6
	ctx.f6.f64 = double(float(std::fma(ctx.f13.f64, ctx.f19.f64, ctx.f6.f64)));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fnmsubs f0,f0,f22,f7
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f22.f64, -ctx.f7.f64)));
	// fadds f1,f0,f2
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f2.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x823A9C4C;
	sub_822EA1A8(ctx, base);
	// addi r28,r7,1
	ctx.r28.s64 = ctx.r7.s64 + 1;
	// fadds f0,f1,f20
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f20.f64));
	// fmr f15,f4
	ctx.f15.f64 = ctx.f4.f64;
	// lfs f13,276(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// extsw r11,r28
	ctx.r11.s64 = ctx.r28.s32;
	// fmr f14,f3
	ctx.f14.f64 = ctx.f3.f64;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfd f12,128(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f5,f0,f19,f5
	ctx.f5.f64 = double(float(std::fma(ctx.f0.f64, ctx.f19.f64, ctx.f5.f64)));
	// fdivs f4,f12,f17
	ctx.f4.f64 = double(float(ctx.f12.f64 / ctx.f17.f64));
	// fsubs f0,f31,f4
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f4.f64));
	// fsubs f3,f0,f13
	ctx.f3.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// fmuls f0,f6,f30
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f30.f64));
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fmuls f0,f6,f29
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f29.f64));
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// fmuls f0,f9,f29
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f29.f64));
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// fmuls f0,f9,f30
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f30.f64));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// fmuls f13,f8,f28
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f28.f64));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// fmuls f12,f8,f27
	ctx.f12.f64 = double(float(ctx.f8.f64 * ctx.f27.f64));
	// fmuls f11,f5,f28
	ctx.f11.f64 = double(float(ctx.f5.f64 * ctx.f28.f64));
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// fmuls f10,f5,f27
	ctx.f10.f64 = double(float(ctx.f5.f64 * ctx.f27.f64));
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f12,212(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// addi r18,r31,-80
	ctx.r18.s64 = ctx.r31.s64 + -80;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r23,12(r10)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r22,0(r9)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r21,4(r9)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// addi r3,r1,328
	ctx.r3.s64 = ctx.r1.s64 + 328;
	// lwz r20,8(r9)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// lwz r19,0(r8)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r18,4(r8)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r17,8(r8)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r16,4(r11)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r15,12(r11)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r14,0(r10)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r8,12(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r6,8(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r23,-28(r31)
	REX_STORE_U32(ctx.r31.u32 + -28, ctx.r23.u32);
	// stw r7,-80(r31)
	REX_STORE_U32(ctx.r31.u32 + -80, ctx.r7.u32);
	// stw r22,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r22.u32);
	// stw r21,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r21.u32);
	// stw r20,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r20.u32);
	// stw r19,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r19.u32);
	// stw r18,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r18.u32);
	// stw r16,-76(r31)
	REX_STORE_U32(ctx.r31.u32 + -76, ctx.r16.u32);
	// stw r15,-68(r31)
	REX_STORE_U32(ctx.r31.u32 + -68, ctx.r15.u32);
	// stw r14,-40(r31)
	REX_STORE_U32(ctx.r31.u32 + -40, ctx.r14.u32);
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r17,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r17.u32);
	// stw r8,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r8.u32);
	// stw r6,-32(r31)
	REX_STORE_U32(ctx.r31.u32 + -32, ctx.r6.u32);
	// stw r11,-72(r31)
	REX_STORE_U32(ctx.r31.u32 + -72, ctx.r11.u32);
	// stw r10,-36(r31)
	REX_STORE_U32(ctx.r31.u32 + -36, ctx.r10.u32);
	// bl 0x825a4010
	ctx.lr = 0x823A9D64;
	sub_825A4010(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,248
	ctx.r3.s64 = ctx.r1.s64 + 248;
	// fmr f1,f15
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f15.f64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,-52(r31)
	REX_STORE_U32(ctx.r31.u32 + -52, ctx.r11.u32);
	// bl 0x825a4010
	ctx.lr = 0x823A9D7C;
	sub_825A4010(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,264
	ctx.r3.s64 = ctx.r1.s64 + 264;
	// fmr f1,f15
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f15.f64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,-12(r31)
	REX_STORE_U32(ctx.r31.u32 + -12, ctx.r11.u32);
	// bl 0x825a4010
	ctx.lr = 0x823A9D94;
	sub_825A4010(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,280
	ctx.r3.s64 = ctx.r1.s64 + 280;
	// fmr f1,f4
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f4.f64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bl 0x825a4010
	ctx.lr = 0x823A9DAC;
	sub_825A4010(ctx, base);
	// stfs f14,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f14.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f3,156(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f14,164(r1)
	temp.f32 = float(ctx.f14.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// ld r11,168(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 168);
	// ld r9,160(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// ld r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// cmpw cr6,r28,r26
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r26.s32, ctx.xer);
	// stw r10,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// std r11,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r11.u64);
	// std r9,-8(r31)
	REX_STORE_U64(ctx.r31.u32 + -8, ctx.r9.u64);
	// ld r9,152(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// std r8,72(r31)
	REX_STORE_U64(ctx.r31.u32 + 72, ctx.r8.u64);
	// std r9,-48(r31)
	REX_STORE_U64(ctx.r31.u32 + -48, ctx.r9.u64);
	// addi r31,r31,160
	ctx.r31.s64 = ctx.r31.s64 + 160;
	// blt cr6,0x823a9b3c
	if (ctx.cr6.lt) goto loc_823A9B3C;
	// lwz r3,116(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r31,120(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
loc_823A9DFC:
	// lwz r7,256(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 256);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// add r25,r24,r25
	ctx.r25.u64 = ctx.r24.u64 + ctx.r25.u64;
	// cmpw cr6,r29,r7
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x823a998c
	if (ctx.cr6.lt) goto loc_823A998C;
loc_823A9E10:
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r8,332(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 332);
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// addi r10,r30,332
	ctx.r10.s64 = ctx.r30.s64 + 332;
	// li r6,3
	ctx.r6.s64 = 3;
	// lwz r10,-12872(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + -12872);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lwz r8,336(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 336);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// lwz r8,340(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 340);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// lwz r8,344(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 344);
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// sth r9,72(r11)
	REX_STORE_U16(ctx.r11.u32 + 72, ctx.r9.u16);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// lwz r9,324(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 324);
	// stw r9,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r9.u32);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// stw r31,208(r11)
	REX_STORE_U32(ctx.r11.u32 + 208, ctx.r31.u32);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// stw r3,228(r11)
	REX_STORE_U32(ctx.r11.u32 + 228, ctx.r3.u32);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// stb r6,71(r11)
	REX_STORE_U8(ctx.r11.u32 + 71, ctx.r6.u8);
	// beq cr6,0x823a9e88
	if (ctx.cr6.eq) goto loc_823A9E88;
	// lfs f0,664(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 664);
	ctx.f0.f64 = double(temp.f32);
	// b 0x823a9e8c
	goto loc_823A9E8C;
loc_823A9E88:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_823A9E8C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// fdivs f13,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// stfs f23,104(r1)
	temp.f32 = float(ctx.f23.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,400
	ctx.r5.s64 = ctx.r1.s64 + 400;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
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
	// addi r7,r1,368
	ctx.r7.s64 = ctx.r1.s64 + 368;
	// lwz r10,-15432(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -15432);
	// addi r6,r1,384
	ctx.r6.s64 = ctx.r1.s64 + 384;
	// lwz r11,-15444(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -15444);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r31,r1,384
	ctx.r31.s64 = ctx.r1.s64 + 384;
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// lfs f12,140(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f12.f64 = double(temp.f32);
	// std r10,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// addi r11,r1,352
	ctx.r11.s64 = ctx.r1.s64 + 352;
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// addi r10,r1,368
	ctx.r10.s64 = ctx.r1.s64 + 368;
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// addi r29,r1,400
	ctx.r29.s64 = ctx.r1.s64 + 400;
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// lwz r3,328(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// vmulfp128 v11,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vmulfp128 v9,v56,v58
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmulfp128 v7,v55,v58
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v10,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vspltw128 v8,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v6,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// stvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v5,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// vspltw128 v4,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// li r5,64
	ctx.r5.s64 = 64;
	// vspltw128 v3,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vspltw128 v2,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vspltw128 v1,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vmaddfp v12,v12,v0,v11
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v31,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v11,v10,v0,v9
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vspltw128 v9,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// lfd f10,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// vmaddfp v10,v8,v0,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// lfd f9,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// vmulfp128 v8,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v7,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vmaddfp v12,v6,v13,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// frsp f10,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// vmaddfp v11,v5,v13,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// frsp f9,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// vmaddfp v10,v4,v13,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v0,v9,v0,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// fmuls f10,f10,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmuls f13,f9,f13
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// vmaddfp v13,v7,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// fnmsubs f11,f10,f0,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f0.f64, -ctx.f11.f64)));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmsubs f0,f13,f0,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, -ctx.f12.f64)));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v12,v3,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v11,v2,v0,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v10,v1,v0,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v0,v31,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273a030
	ctx.lr = 0x823A9FE8;
	sub_8273A030(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r10,r10,1798
	ctx.r10.u64 = ctx.r10.u64 | 1798;
	// li r4,2
	ctx.r4.s64 = 2;
	// lfs f0,32388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32388);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// stfs f0,412(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 412, temp.u32);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// lwz r9,408(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 408);
	// ori r9,r9,4
	ctx.r9.u64 = ctx.r9.u64 | 4;
	// stw r9,408(r11)
	REX_STORE_U32(ctx.r11.u32 + 408, ctx.r9.u32);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// stw r10,368(r11)
	REX_STORE_U32(ctx.r11.u32 + 368, ctx.r10.u32);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// lwz r10,408(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 408);
	// ori r10,r10,64
	ctx.r10.u64 = ctx.r10.u64 | 64;
	// stw r10,408(r11)
	REX_STORE_U32(ctx.r11.u32 + 408, ctx.r10.u32);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// lwz r10,408(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 408);
	// ori r10,r10,128
	ctx.r10.u64 = ctx.r10.u64 | 128;
	// stw r10,408(r11)
	REX_STORE_U32(ctx.r11.u32 + 408, ctx.r10.u32);
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// lwz r10,408(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 408);
	// ori r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 256;
	// stw r10,408(r11)
	REX_STORE_U32(ctx.r11.u32 + 408, ctx.r10.u32);
	// lwz r3,328(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// bl 0x82459d08
	ctx.lr = 0x823AA058;
	sub_82459D08(ctx, base);
loc_823AA058:
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af3c
	ctx.lr = 0x823AA064;
	__restfpr_14(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823EB3F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x823EB400;
	__savegprlr_23(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af28
	ctx.lr = 0x823EB408;
	__savefpr_28(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r23,-32112
	ctx.r23.s64 = -2104492032;
	// lbz r10,86(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 86);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// fmr f31,f2
	ctx.f31.f64 = ctx.f2.f64;
	// lwz r11,-12972(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + -12972);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r26,436(r11)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r11.u32 + 436);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x823eb7d8
	if (ctx.cr6.eq) goto loc_823EB7D8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// clrlwi. r31,r10,24
	ctx.r31.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r24,r10,-23056
	ctx.r24.s64 = ctx.r10.s64 + -23056;
	// lfs f29,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// beq 0x823eb458
	if (ctx.cr0.eq) goto loc_823EB458;
	// lfs f0,-24376(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -24376);
	ctx.f0.f64 = double(temp.f32);
	// b 0x823eb45c
	goto loc_823EB45C;
loc_823EB458:
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f29.f64;
loc_823EB45C:
	// lis r27,-32227
	ctx.r27.s64 = -2112028672;
	// lfs f13,-25236(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -25236);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stfs f29,104(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f30,112(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r28,r9,-10736
	ctx.r28.s64 = ctx.r9.s64 + -10736;
	// lfs f0,5460(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 5460);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f1,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f1.f64 = double(temp.f32);
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x823c5ea8
	ctx.lr = 0x823EB4B0;
	sub_823C5EA8(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823eb7d8
	if (ctx.cr6.eq) goto loc_823EB7D8;
	// lbz r10,114(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 114);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r29,-32114
	ctx.r29.s64 = -2104623104;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r25,r11,17284
	ctx.r25.s64 = ctx.r11.s64 + 17284;
	// beq 0x823eb5e4
	if (ctx.cr0.eq) goto loc_823EB5E4;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// li r7,808
	ctx.r7.s64 = 808;
	// lwz r10,-12952(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12952);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823eb510
	if (ctx.cr6.eq) goto loc_823EB510;
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,8(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// subf r8,r9,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r9.u64;
	// divw r8,r8,r7
	ctx.r8.u64 = uint32_t((ctx.r7.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r7.s32 == -1)) ? ctx.r8.s32 / ctx.r7.s32 : 0);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x823eb510
	if (!ctx.cr6.gt) goto loc_823EB510;
	// mulli r8,r11,808
	ctx.r8.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(808));
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lhz r9,662(r9)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + 662);
	// b 0x823eb514
	goto loc_823EB514;
loc_823EB510:
	// li r9,0
	ctx.r9.s64 = 0;
loc_823EB514:
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r4,r9,16
	ctx.r4.u64 = ctx.r9.u32 & 0xFFFF;
	// lwzx r3,r8,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r30.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823eb5e4
	if (ctx.cr6.eq) goto loc_823EB5E4;
	// lbz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x823eb5e4
	if (!ctx.cr0.eq) goto loc_823EB5E4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823eb560
	if (ctx.cr6.eq) goto loc_823EB560;
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// divw r10,r10,r7
	ctx.r10.u64 = uint32_t((ctx.r7.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r7.s32 == -1)) ? ctx.r10.s32 / ctx.r7.s32 : 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x823eb560
	if (!ctx.cr6.gt) goto loc_823EB560;
	// mulli r11,r11,808
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(808));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lfs f29,652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 652);
	ctx.f29.f64 = double(temp.f32);
loc_823EB560:
	// fctiwz f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f29.f64) ? int64_t(0x80000000U) : (ctx.f29.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f29.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwa r11,116(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 116));
	// lfs f0,-22680(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -22680);
	ctx.f0.f64 = double(temp.f32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f11,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,92(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 92);
	// stfs f0,96(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lfd f12,112(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fctiwz f0,f30
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// fcfid f0,f12
	ctx.f0.f64 = double(ctx.f12.s64);
	// lfs f13,-5068(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -5068);
	ctx.f13.f64 = double(temp.f32);
	// li r6,2
	ctx.r6.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r10.u8);
	// sth r11,84(r3)
	REX_STORE_U16(ctx.r3.u32 + 84, ctx.r11.u16);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lbz r7,116(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 116);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// addi r5,r11,53
	ctx.r5.s64 = ctx.r11.s64 + 53;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// subfic r11,r7,0
	ctx.xer.ca = ctx.r7.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r7.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r7,r11,r6
	ctx.r7.u64 = ctx.r11.u64 & ctx.r6.u64;
	// fmadds f0,f11,f0,f31
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f31.f64)));
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r6,116(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823beba0
	ctx.lr = 0x823EB5E4;
	sub_823BEBA0(ctx, base);
loc_823EB5E4:
	// lbz r10,113(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 113);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r31,r11,-4080
	ctx.r31.s64 = ctx.r11.s64 + -4080;
	// beq 0x823eb65c
	if (ctx.cr0.eq) goto loc_823EB65C;
	// lfs f0,3212(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 3212);
	ctx.f0.f64 = double(temp.f32);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// fadds f9,f31,f0
	ctx.f9.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// lfs f0,3208(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 3208);
	ctx.f0.f64 = double(temp.f32);
	// fadds f8,f30,f0
	ctx.f8.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// lfs f10,-26240(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -26240);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,5460(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 5460);
	ctx.f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f13,10712(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 10712);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// lfs f12,1896(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1896);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lfs f11,448(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 448);
	ctx.f11.f64 = double(temp.f32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fsubs f0,f9,f10
	ctx.f0.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f1,-22680(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -22680);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823c5ea8
	ctx.lr = 0x823EB65C;
	sub_823C5EA8(ctx, base);
loc_823EB65C:
	// lwz r11,-12972(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + -12972);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r26,432(r11)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r11.u32 + 432);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x823eb6ec
	if (ctx.cr6.eq) goto loc_823EB6EC;
	// lwz r11,144(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 144);
	// lfs f0,-19468(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -19468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16660(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -16660);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r30,120
	ctx.r29.s64 = ctx.r30.s64 + 120;
	// fadds f29,f30,f0
	ctx.f29.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// fadds f28,f31,f13
	ctx.f28.f64 = double(float(ctx.f31.f64 + ctx.f13.f64));
	// blt cr6,0x823eb698
	if (ctx.cr6.lt) goto loc_823EB698;
	// lwz r28,4(r29)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// b 0x823eb69c
	goto loc_823EB69C;
loc_823EB698:
	// addi r28,r29,4
	ctx.r28.s64 = ctx.r29.s64 + 4;
loc_823EB69C:
	// lis r27,-32114
	ctx.r27.s64 = -2104623104;
loc_823EB6A0:
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x823eb6b4
	if (ctx.cr6.lt) goto loc_823EB6B4;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// b 0x823eb6b8
	goto loc_823EB6B8;
loc_823EB6B4:
	// addi r11,r29,4
	ctx.r11.s64 = ctx.r29.s64 + 4;
loc_823EB6B8:
	// lwz r10,20(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823eb6ec
	if (ctx.cr6.eq) goto loc_823EB6EC;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lfs f3,-22668(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -22668);
	ctx.f3.f64 = double(temp.f32);
	// lbz r3,0(r28)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// fmr f2,f28
	ctx.f2.f64 = ctx.f28.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x823c6b98
	ctx.lr = 0x823EB6E0;
	sub_823C6B98(ctx, base);
	// fadds f29,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = double(float(ctx.f1.f64 + ctx.f29.f64));
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x823eb6a0
	goto loc_823EB6A0;
loc_823EB6EC:
	// lfs f0,-25236(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -25236);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-1024
	ctx.r11.s64 = -67108864;
	// lfs f13,3216(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 3216);
	ctx.f13.f64 = double(temp.f32);
	// fadds f29,f30,f0
	ctx.f29.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// fadds f12,f30,f13
	ctx.f12.f64 = double(float(ctx.f30.f64 + ctx.f13.f64));
	// lfs f0,148(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,152(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-30457
	ctx.r9.s64 = -1996029952;
	// fdivs f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// lfs f0,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// ori r10,r11,511
	ctx.r10.u64 = ctx.r11.u64 | 511;
	// lfs f13,984(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 984);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// ori r11,r9,9727
	ctx.r11.u64 = ctx.r9.u64 | 9727;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fadds f13,f31,f13
	ctx.f13.f64 = double(float(ctx.f31.f64 + ctx.f13.f64));
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stfs f29,128(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stw r10,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stfs f29,152(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// fsubs f30,f12,f29
	ctx.f30.f64 = double(float(ctx.f12.f64 - ctx.f29.f64));
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// fmadds f0,f11,f30,f29
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f30.f64, ctx.f29.f64)));
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x8222d008
	ctx.lr = 0x823EB76C;
	sub_8222D008(ctx, base);
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,3160(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 3160);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// fadds f13,f31,f13
	ctx.f13.f64 = double(float(ctx.f31.f64 + ctx.f13.f64));
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lis r11,243
	ctx.r11.s64 = 15925248;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lis r9,1388
	ctx.r9.s64 = 90963968;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// ori r10,r11,511
	ctx.r10.u64 = ctx.r11.u64 | 511;
	// ori r11,r9,18943
	ctx.r11.u64 = ctx.r9.u64 | 18943;
	// stfs f29,128(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f29,152(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r10,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// lfs f0,156(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,160(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fmadds f0,f0,f30,f29
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f30.f64, ctx.f29.f64)));
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x8222d008
	ctx.lr = 0x823EB7D8;
	sub_8222D008(ctx, base);
loc_823EB7D8:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af74
	ctx.lr = 0x823EB7E4;
	__restfpr_28(ctx, base);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82409EB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82409EB8;
	__savegprlr_27(ctx, base);
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f30.u64);
	// stfd f31,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x82409ED0;
	sub_825A43F0(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// bl 0x82213210
	ctx.lr = 0x82409ED8;
	sub_82213210(ctx, base);
	// lbz r11,19280(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 19280);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82409f04
	if (ctx.cr0.eq) goto loc_82409F04;
	// bl 0x82213210
	ctx.lr = 0x82409EE8;
	sub_82213210(ctx, base);
	// lbz r11,4038(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4038);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82409efc
	if (!ctx.cr0.eq) goto loc_82409EFC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8240aac0
	ctx.lr = 0x82409EFC;
	sub_8240AAC0(ctx, base);
loc_82409EFC:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8240a428
	goto loc_8240A428;
loc_82409F04:
	// lbz r11,37(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 37);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82409f34
	if (ctx.cr0.eq) goto loc_82409F34;
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fadds f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f0,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8240a424
	if (ctx.cr6.lt) goto loc_8240A424;
	// b 0x82409efc
	goto loc_82409EFC;
loc_82409F34:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x8240a410
	if (ctx.cr6.gt) goto loc_8240A410;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82409f7c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82409F7C;
	// bdzf 4*cr6+eq,0x8240a00c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8240A00C;
	// bdzf 4*cr6+eq,0x8240a08c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8240A08C;
	// bdzf 4*cr6+eq,0x8240a210
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8240A210;
	// bdzf 4*cr6+eq,0x8240a2bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8240A2BC;
	// bdzf 4*cr6+eq,0x8240a3e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8240A3E4;
	// bne cr6,0x8240a3e4
	if (!ctx.cr6.eq) goto loc_8240A3E4;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// lwz r3,160(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// bl 0x8242c7d8
	ctx.lr = 0x82409F70;
	sub_8242C7D8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
loc_82409F74:
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x8240a410
	goto loc_8240A410;
loc_82409F7C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,-12960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12960);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82409f98
	if (ctx.cr6.eq) goto loc_82409F98;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// b 0x82409f9c
	goto loc_82409F9C;
loc_82409F98:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_82409F9C:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8240a410
	if (!ctx.cr0.eq) goto loc_8240A410;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82409fb4
	if (ctx.cr6.eq) goto loc_82409FB4;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82409fb8
	goto loc_82409FB8;
loc_82409FB4:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82409FB8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82409fd8
	if (ctx.cr6.eq) goto loc_82409FD8;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r11,r31,80
	ctx.r11.s64 = ctx.r31.s64 + 80;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82409FCC:
	// stwu r29,24(r11)
	ea = 24 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r29.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82409fcc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82409FCC;
	// b 0x8240a004
	goto loc_8240A004;
loc_82409FD8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r29,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r29.u32);
	// beq cr6,0x8240a004
	if (ctx.cr6.eq) goto loc_8240A004;
	// lwz r9,1784(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 1784);
	// addi r10,r11,1728
	ctx.r10.s64 = ctx.r11.s64 + 1728;
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// addi r4,r10,64
	ctx.r4.s64 = ctx.r10.s64 + 64;
	// stw r9,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r9.u32);
	// lwz r11,1784(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1784);
	// mulli r5,r11,24
	ctx.r5.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// bl 0x8273a030
	ctx.lr = 0x8240A004;
	sub_8273A030(ctx, base);
loc_8240A004:
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x82409f74
	goto loc_82409F74;
loc_8240A00C:
	// bl 0x825e0d50
	ctx.lr = 0x8240A010;
	sub_825E0D50(ctx, base);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8240a438
	ctx.lr = 0x8240A01C;
	sub_8240A438(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r10,164(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// lwz r11,-12960(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12960);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240a084
	if (ctx.cr6.eq) goto loc_8240A084;
	// stw r10,1708(r11)
	REX_STORE_U32(ctx.r11.u32 + 1708, ctx.r10.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r10,r31,48
	ctx.r10.s64 = ctx.r31.s64 + 48;
	// stw r29,1712(r11)
	REX_STORE_U32(ctx.r11.u32 + 1712, ctx.r29.u32);
	// stw r10,1704(r11)
	REX_STORE_U32(ctx.r11.u32 + 1704, ctx.r10.u32);
	// stw r29,1716(r11)
	REX_STORE_U32(ctx.r11.u32 + 1716, ctx.r29.u32);
	// stw r29,1720(r11)
	REX_STORE_U32(ctx.r11.u32 + 1720, ctx.r29.u32);
	// stw r29,1724(r11)
	REX_STORE_U32(ctx.r11.u32 + 1724, ctx.r29.u32);
	// lwz r3,228(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240a064
	if (ctx.cr6.eq) goto loc_8240A064;
	// bl 0x825e0378
	ctx.lr = 0x8240A060;
	sub_825E0378(ctx, base);
	// lwz r11,-12960(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12960);
loc_8240A064:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r29,228(r11)
	REX_STORE_U32(ctx.r11.u32 + 228, ctx.r29.u32);
	// lwz r9,1048(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 1048);
	// addi r3,r11,1048
	ctx.r3.s64 = ctx.r11.s64 + 1048;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8240A084;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8240A084:
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x82409f74
	goto loc_82409F74;
loc_8240A08C:
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,-12960(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12960);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240a0a8
	if (ctx.cr6.eq) goto loc_8240A0A8;
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// b 0x8240a0ac
	goto loc_8240A0AC;
loc_8240A0A8:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8240A0AC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8240a410
	if (!ctx.cr0.eq) goto loc_8240A410;
	// bl 0x825e0d50
	ctx.lr = 0x8240A0B8;
	sub_825E0D50(ctx, base);
	// lwz r11,-12960(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12960);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240a0d0
	if (ctx.cr6.eq) goto loc_8240A0D0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8240a0d4
	goto loc_8240A0D4;
loc_8240A0D0:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8240A0D4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240a0f8
	if (ctx.cr6.eq) goto loc_8240A0F8;
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// ori r4,r4,630
	ctx.r4.u64 = ctx.r4.u64 | 630;
loc_8240A0E4:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8240aa30
	ctx.lr = 0x8240A0F0;
	sub_8240AA30(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x82409f74
	goto loc_82409F74;
loc_8240A0F8:
	// bl 0x82213210
	ctx.lr = 0x8240A0FC;
	sub_82213210(ctx, base);
	// lbz r11,4038(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4038);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8240a208
	if (ctx.cr0.eq) goto loc_8240A208;
	// bl 0x8245d770
	ctx.lr = 0x8240A10C;
	sub_8245D770(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8240a208
	if (ctx.cr0.eq) goto loc_8240A208;
	// lwz r10,-12960(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -12960);
	// stw r29,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r29.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8240a158
	if (ctx.cr6.eq) goto loc_8240A158;
	// lwz r11,1712(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 1712);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240a15c
	if (ctx.cr6.eq) goto loc_8240A15C;
	// addi r7,r31,172
	ctx.r7.s64 = ctx.r31.s64 + 172;
	// addi r8,r10,1712
	ctx.r8.s64 = ctx.r10.s64 + 1712;
loc_8240A13C:
	// lwzu r11,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r7.u32 = ea;
	// lwz r11,1712(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 1712);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8240a13c
	if (ctx.cr6.lt) goto loc_8240A13C;
	// b 0x8240a15c
	goto loc_8240A15C;
loc_8240A158:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8240A15C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// beq cr6,0x8240a208
	if (ctx.cr6.eq) goto loc_8240A208;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// beq cr6,0x8240a1c8
	if (ctx.cr6.eq) goto loc_8240A1C8;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r30,r31,176
	ctx.r30.s64 = ctx.r31.s64 + 176;
	// addi r27,r11,-4
	ctx.r27.s64 = ctx.r11.s64 + -4;
loc_8240A18C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8240a9b8
	ctx.lr = 0x8240A198;
	sub_8240A9B8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8240a1b4
	if (ctx.cr0.eq) goto loc_8240A1B4;
	// cmplwi cr6,r3,10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 10, ctx.xer);
	// bgt cr6,0x8240a1b4
	if (ctx.cr6.gt) goto loc_8240A1B4;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stwu r11,4(r27)
	ea = 4 + ctx.r27.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r27.u32 = ea;
loc_8240A1B4:
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8240a18c
	if (ctx.cr6.lt) goto loc_8240A18C;
loc_8240A1C8:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stw r11,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// stw r10,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r10.u32);
	// stw r9,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r9.u32);
	// stw r29,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r29.u32);
	// beq cr6,0x8240a208
	if (ctx.cr6.eq) goto loc_8240A208;
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// li r5,4
	ctx.r5.s64 = 4;
	// ori r4,r4,605
	ctx.r4.u64 = ctx.r4.u64 | 605;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8240aa30
	ctx.lr = 0x8240A200;
	sub_8240AA30(ctx, base);
loc_8240A200:
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x82409f74
	goto loc_82409F74;
loc_8240A208:
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x82409f74
	goto loc_82409F74;
loc_8240A210:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r7,-12864(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + -12864);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8240a230
	if (!ctx.cr6.eq) goto loc_8240A230;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// b 0x8240a26c
	goto loc_8240A26C;
loc_8240A230:
	// lwz r9,32(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8240a248
	if (ctx.cr6.eq) goto loc_8240A248;
	// lwz r11,12(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// b 0x8240a258
	goto loc_8240A258;
loc_8240A248:
	// lwz r10,28(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8240a25c
	if (ctx.cr6.eq) goto loc_8240A25C;
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
loc_8240A258:
	// addi r11,r11,24576
	ctx.r11.s64 = ctx.r11.s64 + 24576;
loc_8240A25C:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8240a26c
	if (!ctx.cr6.eq) goto loc_8240A26C;
	// lwz r9,28(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 28);
loc_8240A26C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12960);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240a2b4
	if (ctx.cr6.eq) goto loc_8240A2B4;
	// lwz r10,168(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r3,r11,1904
	ctx.r3.s64 = ctx.r11.s64 + 1904;
	// addi r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 + 44;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// stw r9,1964(r11)
	REX_STORE_U32(ctx.r11.u32 + 1964, ctx.r9.u32);
	// stw r8,1968(r11)
	REX_STORE_U32(ctx.r11.u32 + 1968, ctx.r8.u32);
	// stw r10,1960(r11)
	REX_STORE_U32(ctx.r11.u32 + 1960, ctx.r10.u32);
	// lwz r10,1904(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1904);
	// stb r7,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r7.u8);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8240A2B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8240A2B4:
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x82409f74
	goto loc_82409F74;
loc_8240A2BC:
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,-12960(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -12960);
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8240a2e8
	if (ctx.cr6.eq) goto loc_8240A2E8;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r10,1904
	ctx.r3.s64 = ctx.r10.s64 + 1904;
	// bl 0x8242c288
	ctx.lr = 0x8240A2E0;
	sub_8242C288(ctx, base);
	// lwz r10,-12960(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -12960);
	// b 0x8240a2ec
	goto loc_8240A2EC;
loc_8240A2E8:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_8240A2EC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240a358
	if (ctx.cr6.eq) goto loc_8240A358;
	// lwz r9,172(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// lwz r7,168(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f13,17092(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 17092);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f12,f12,f1
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f1.f64));
	// fdivs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8240a348
	if (!ctx.cr6.lt) goto loc_8240A348;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// b 0x8240a354
	goto loc_8240A354;
loc_8240A348:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8240a354
	if (!ctx.cr6.gt) goto loc_8240A354;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_8240A354:
	// stfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
loc_8240A358:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8240a36c
	if (ctx.cr6.eq) goto loc_8240A36C;
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// b 0x8240a370
	goto loc_8240A370;
loc_8240A36C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8240A370:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8240a410
	if (!ctx.cr0.eq) goto loc_8240A410;
	// bl 0x825e0d50
	ctx.lr = 0x8240A37C;
	sub_825E0D50(ctx, base);
	// lwz r11,-12960(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12960);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240a394
	if (ctx.cr6.eq) goto loc_8240A394;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8240a398
	goto loc_8240A398;
loc_8240A394:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8240A398:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240a3ac
	if (ctx.cr6.eq) goto loc_8240A3AC;
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// ori r4,r4,631
	ctx.r4.u64 = ctx.r4.u64 | 631;
	// b 0x8240a0e4
	goto loc_8240A0E4;
loc_8240A3AC:
	// lwz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// lwz r10,172(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8240a200
	if (ctx.cr6.lt) goto loc_8240A200;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240a3d4
	if (ctx.cr6.eq) goto loc_8240A3D4;
	// bl 0x823c74f0
	ctx.lr = 0x8240A3D4;
	sub_823C74F0(ctx, base);
loc_8240A3D4:
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x8240a424
	goto loc_8240A424;
loc_8240A3E4:
	// bl 0x82213210
	ctx.lr = 0x8240A3E8;
	sub_82213210(ctx, base);
	// lbz r11,4038(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4038);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8240a3fc
	if (!ctx.cr0.eq) goto loc_8240A3FC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8240aac0
	ctx.lr = 0x8240A3FC;
	sub_8240AAC0(ctx, base);
loc_8240A3FC:
	// bl 0x825e0d50
	ctx.lr = 0x8240A400;
	sub_825E0D50(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// cmplwi cr6,r11,1000
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1000, ctx.xer);
	// bgt cr6,0x82409efc
	if (ctx.cr6.gt) goto loc_82409EFC;
loc_8240A410:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240a424
	if (ctx.cr6.eq) goto loc_8240A424;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x823c9570
	ctx.lr = 0x8240A424;
	sub_823C9570(ctx, base);
loc_8240A424:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8240A428:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82438F50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x82438F58;
	__savegprlr_19(ctx, base);
	// stfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.f30.u64);
	// stfd f31,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,2340(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,972(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 972);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82438F7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,2340(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// li r19,6
	ctx.r19.s64 = 6;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r19,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r19.u32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addi r26,r29,2516
	ctx.r26.s64 = ctx.r29.s64 + 2516;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// lwz r11,480(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 480);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82438FAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x82438fbc
	if (ctx.cr6.eq) goto loc_82438FBC;
	// stw r11,2476(r29)
	REX_STORE_U32(ctx.r29.u32 + 2476, ctx.r11.u32);
loc_82438FBC:
	// lwz r7,2476(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 2476);
	// cmplwi cr6,r7,2
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 2, ctx.xer);
	// bge cr6,0x8243958c
	if (!ctx.cr6.lt) goto loc_8243958C;
	// li r23,1
	ctx.r23.s64 = 1;
	// li r21,0
	ctx.r21.s64 = 0;
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// beq cr6,0x82438ff8
	if (ctx.cr6.eq) goto loc_82438FF8;
	// cmpwi cr6,r31,2
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 2, ctx.xer);
	// beq cr6,0x82439008
	if (ctx.cr6.eq) goto loc_82439008;
	// cmpwi cr6,r31,3
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 3, ctx.xer);
	// bne cr6,0x8243958c
	if (!ctx.cr6.eq) goto loc_8243958C;
	// stw r19,2476(r29)
	REX_STORE_U32(ctx.r29.u32 + 2476, ctx.r19.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82435520
	ctx.lr = 0x82438FF4;
	sub_82435520(ctx, base);
	// b 0x8243958c
	goto loc_8243958C;
loc_82438FF8:
	// stb r23,2480(r29)
	REX_STORE_U8(ctx.r29.u32 + 2480, ctx.r23.u8);
	// stw r21,2484(r29)
	REX_STORE_U32(ctx.r29.u32 + 2484, ctx.r21.u32);
	// stw r21,2488(r29)
	REX_STORE_U32(ctx.r29.u32 + 2488, ctx.r21.u32);
	// stw r21,2492(r29)
	REX_STORE_U32(ctx.r29.u32 + 2492, ctx.r21.u32);
loc_82439008:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// cmpwi cr6,r7,6
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 6, ctx.xer);
	// addi r27,r11,-24848
	ctx.r27.s64 = ctx.r11.s64 + -24848;
	// beq cr6,0x8243902c
	if (ctx.cr6.eq) goto loc_8243902C;
	// addi r11,r27,836
	ctx.r11.s64 = ctx.r27.s64 + 836;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82439034
	if (!ctx.cr6.eq) goto loc_82439034;
loc_8243902C:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// b 0x82439040
	goto loc_82439040;
loc_82439034:
	// lwz r10,2504(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 2504);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_82439040:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// addi r25,r11,17284
	ctx.r25.s64 = ctx.r11.s64 + 17284;
	// addi r11,r25,148
	ctx.r11.s64 = ctx.r25.s64 + 148;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_82439054:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r3,r9
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82439070
	if (ctx.cr6.lt) goto loc_82439070;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplwi cr6,r10,64
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 64, ctx.xer);
	// blt cr6,0x82439054
	if (ctx.cr6.lt) goto loc_82439054;
loc_82439070:
	// bl 0x823b47e8
	ctx.lr = 0x82439074;
	sub_823B47E8(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// cmpwi cr6,r7,6
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 6, ctx.xer);
	// beq cr6,0x82439588
	if (ctx.cr6.eq) goto loc_82439588;
	// addi r11,r7,20
	ctx.r11.s64 = ctx.r7.s64 + 20;
	// lwz r10,2504(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 2504);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r24,r11,r10
	ctx.r24.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x82439588
	if (ctx.cr6.eq) goto loc_82439588;
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,980(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 980);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824390B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f0,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r31,r1,128
	ctx.r31.s64 = ctx.r1.s64 + 128;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2260(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2260);
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
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,992(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 992);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,2264(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2264);
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
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bctrl 
	ctx.lr = 0x82439180;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// mr r28,r21
	ctx.r28.u64 = ctx.r21.u64;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// mr r20,r21
	ctx.r20.u64 = ctx.r21.u64;
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// fmr f30,f31
	ctx.f30.f64 = ctx.f31.f64;
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// beq cr6,0x82439368
	if (ctx.cr6.eq) goto loc_82439368;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x824392a0
	if (ctx.cr6.eq) goto loc_824392A0;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82453810
	ctx.lr = 0x8243920C;
	sub_82453810(ctx, base);
	// li r11,12
	ctx.r11.s64 = 12;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82439220:
	// slw r11,r23,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r23.u32 << (ctx.r10.u8 & 0x3F));
	// and. r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 & ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82439234
	if (ctx.cr0.eq) goto loc_82439234;
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// or r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 | ctx.r8.u64;
loc_82439234:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x82439220
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82439220;
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,512(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 512);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82439258;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// beq 0x82439274
	if (ctx.cr0.eq) goto loc_82439274;
	// bl 0x824539b8
	ctx.lr = 0x82439268;
	sub_824539B8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// bge cr6,0x8243927c
	if (!ctx.cr6.lt) goto loc_8243927C;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
loc_82439274:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824539b8
	ctx.lr = 0x8243927C;
	sub_824539B8(ctx, base);
loc_8243927C:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82439948
	ctx.lr = 0x8243928C;
	sub_82439948(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82453878
	ctx.lr = 0x82439298;
	sub_82453878(ctx, base);
	// extsh r28,r3
	ctx.r28.s64 = ctx.r3.s16;
	// b 0x8243936c
	goto loc_8243936C;
loc_824392A0:
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,368(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 368);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824392B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82456128
	ctx.lr = 0x824392BC;
	sub_82456128(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824392cc
	if (ctx.cr0.eq) goto loc_824392CC;
	// lhz r7,12(r3)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r3.u32 + 12);
	// b 0x824392d0
	goto loc_824392D0;
loc_824392CC:
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
loc_824392D0:
	// li r11,12
	ctx.r11.s64 = 12;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_824392E4:
	// slw r11,r23,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r23.u32 << (ctx.r10.u8 & 0x3F));
	// and. r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 & ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824392f8
	if (ctx.cr0.eq) goto loc_824392F8;
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// or r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 | ctx.r8.u64;
loc_824392F8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x824392e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824392E4;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82439334
	if (ctx.cr0.eq) goto loc_82439334;
	// lhz r11,38(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 38);
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// lfd f13,144(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x82439338
	goto loc_82439338;
loc_82439334:
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f31.f64;
loc_82439338:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82439648
	ctx.lr = 0x82439340;
	sub_82439648(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82456128
	ctx.lr = 0x8243934C;
	sub_82456128(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8243935c
	if (ctx.cr0.eq) goto loc_8243935C;
	// lha r11,8(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 8));
	// b 0x82439360
	goto loc_82439360;
loc_8243935C:
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
loc_82439360:
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// b 0x8243936c
	goto loc_8243936C;
loc_82439368:
	// mr r20,r23
	ctx.r20.u64 = ctx.r23.u64;
loc_8243936C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r24,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 4) & 0xFFFF0;
	// mr r31,r21
	ctx.r31.u64 = ctx.r21.u64;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r24
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x82439394
	if (!ctx.cr6.eq) goto loc_82439394;
	// lwz r31,4(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82439394:
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// ld r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// std r10,80(r31)
	REX_STORE_U64(ctx.r31.u32 + 80, ctx.r10.u64);
	// std r11,72(r31)
	REX_STORE_U64(ctx.r31.u32 + 72, ctx.r11.u64);
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,648(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 648);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824393B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824393D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,96(r31)
	REX_STORE_U64(ctx.r31.u32 + 96, ctx.r11.u64);
	// stfs f31,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// stw r3,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// stw r30,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,504(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 504);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824393F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r30,r31,56
	ctx.r30.s64 = ctx.r31.s64 + 56;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82439424
	if (ctx.cr0.eq) goto loc_82439424;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82439424
	if (ctx.cr6.eq) goto loc_82439424;
	// stfs f1,300(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 300, temp.u32);
loc_82439424:
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82439438;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82439460
	if (ctx.cr0.eq) goto loc_82439460;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82439460
	if (ctx.cr6.eq) goto loc_82439460;
	// stfs f1,304(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 304, temp.u32);
loc_82439460:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82439488
	if (ctx.cr0.eq) goto loc_82439488;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82439488
	if (ctx.cr6.eq) goto loc_82439488;
	// stfs f30,200(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 200, temp.u32);
loc_82439488:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824394e8
	if (ctx.cr0.eq) goto loc_824394E8;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824394e8
	if (ctx.cr6.eq) goto loc_824394E8;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x824394c8
	if (ctx.cr6.eq) goto loc_824394C8;
	// lwz r10,144(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// oris r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 131072;
	// stw r10,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r10.u32);
	// bge cr6,0x824394d0
	if (!ctx.cr6.lt) goto loc_824394D0;
loc_824394C8:
	// stw r21,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r21.u32);
	// b 0x824394e8
	goto loc_824394E8;
loc_824394D0:
	// li r10,-1
	ctx.r10.s64 = -1;
	// subf r10,r28,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r28.u64;
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 & ctx.r28.u64;
	// stw r10,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
loc_824394E8:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82439510
	if (ctx.cr0.eq) goto loc_82439510;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82439510
	if (ctx.cr6.eq) goto loc_82439510;
	// stb r20,284(r11)
	REX_STORE_U8(ctx.r11.u32 + 284, ctx.r20.u8);
loc_82439510:
	// lwz r11,2476(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2476);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// lwz r11,88(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8243952C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,900(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 900);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82439540;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82439554
	if (ctx.cr0.eq) goto loc_82439554;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82432290
	ctx.lr = 0x82439554;
	sub_82432290(ctx, base);
loc_82439554:
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1052(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1052);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8243956C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82439588
	if (ctx.cr0.eq) goto loc_82439588;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82453a68
	ctx.lr = 0x8243957C;
	sub_82453A68(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8243b870
	ctx.lr = 0x82439588;
	sub_8243B870(ctx, base);
loc_82439588:
	// stw r19,2476(r29)
	REX_STORE_U32(ctx.r29.u32 + 2476, ctx.r19.u32);
loc_8243958C:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8246E340) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8246E348;
	__savegprlr_23(ctx, base);
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r23,424
	ctx.r23.s64 = 424;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8246e370
	if (!ctx.cr6.eq) goto loc_8246E370;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8246e37c
	goto loc_8246E37C;
loc_8246E370:
	// lwz r10,12(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r9,r10,r23
	ctx.r9.u64 = uint32_t((ctx.r23.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r10.s32 / ctx.r23.s32 : 0);
loc_8246E37C:
	// lwz r31,8(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lis r10,154
	ctx.r10.s64 = 10092544;
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// ori r10,r10,37095
	ctx.r10.u64 = ctx.r10.u64 | 37095;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// subf r8,r11,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bge cr6,0x8246e3e4
	if (!ctx.cr6.lt) goto loc_8246E3E4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,56
	ctx.r4.s64 = ctx.r11.s64 + 56;
	// bl 0x822167f8
	ctx.lr = 0x8246E3AC;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82216678
	ctx.lr = 0x8246E3B8;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x8246E3BC;
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
	ctx.lr = 0x8246E3D0;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8246E3E0;
	sub_8235EC48(ctx, base);
	// b 0x8246e694
	goto loc_8246E694;
loc_8246E3E4:
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8246e51c
	if (!ctx.cr6.lt) goto loc_8246E51C;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8246e408
	if (!ctx.cr6.lt) goto loc_8246E408;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8246e40c
	goto loc_8246E40C;
loc_8246E408:
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_8246E40C:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8246e418
	if (!ctx.cr6.lt) goto loc_8246E418;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8246E418:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mulli r24,r11,424
	ctx.r24.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(424));
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8246E434;
	sub_825E02A0(ctx, base);
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// divw r26,r11,r23
	ctx.r26.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// mulli r25,r26,424
	ctx.r25.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(424));
	// add. r3,r25,r3
	ctx.r3.u64 = ctx.r25.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8246e45c
	if (ctx.cr0.eq) goto loc_8246E45C;
	// li r5,424
	ctx.r5.s64 = 424;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8246E45C;
	sub_8273A030(ctx, base);
loc_8246E45C:
	// lwz r29,4(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r27,r31
	ctx.r27.u64 = ctx.r31.u64;
	// b 0x8246e488
	goto loc_8246E488;
loc_8246E468:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8246e480
	if (ctx.cr6.eq) goto loc_8246E480;
	// li r5,424
	ctx.r5.s64 = 424;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a030
	ctx.lr = 0x8246E480;
	sub_8273A030(ctx, base);
loc_8246E480:
	// addi r29,r29,424
	ctx.r29.s64 = ctx.r29.s64 + 424;
	// addi r27,r27,424
	ctx.r27.s64 = ctx.r27.s64 + 424;
loc_8246E488:
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8246e468
	if (!ctx.cr6.eq) goto loc_8246E468;
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// lwz r27,8(r28)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// mulli r11,r11,424
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(424));
	// add r29,r11,r31
	ctx.r29.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8246e4e0
	if (ctx.cr6.eq) goto loc_8246E4E0;
	// subf r11,r25,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r25.u64;
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r30,r11,-424
	ctx.r30.s64 = ctx.r11.s64 + -424;
loc_8246E4B8:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8246e4d0
	if (ctx.cr6.eq) goto loc_8246E4D0;
	// li r5,424
	ctx.r5.s64 = 424;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8246E4D0;
	sub_8273A030(ctx, base);
loc_8246E4D0:
	// addi r30,r30,424
	ctx.r30.s64 = ctx.r30.s64 + 424;
	// addi r29,r29,424
	ctx.r29.s64 = ctx.r29.s64 + 424;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8246e4b8
	if (!ctx.cr6.eq) goto loc_8246E4B8;
loc_8246E4E0:
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x8246e500
	if (ctx.cr6.eq) goto loc_8246E500;
	// bl 0x825e0378
	ctx.lr = 0x8246E500;
	sub_825E0378(ctx, base);
loc_8246E500:
	// mulli r11,r30,424
	ctx.r11.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(424));
	// stw r31,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// add r10,r24,r31
	ctx.r10.u64 = ctx.r24.u64 + ctx.r31.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r10,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r10.u32);
	// stw r11,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r11.u32);
	// b 0x8246e694
	goto loc_8246E694;
loc_8246E51C:
	// subf r11,r30,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// li r5,424
	ctx.r5.s64 = 424;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bge cr6,0x8246e5f4
	if (!ctx.cr6.lt) goto loc_8246E5F4;
	// bl 0x8273a030
	ctx.lr = 0x8246E53C;
	sub_8273A030(ctx, base);
	// addi r29,r30,424
	ctx.r29.s64 = ctx.r30.s64 + 424;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8246e574
	if (ctx.cr6.eq) goto loc_8246E574;
	// addi r27,r29,-424
	ctx.r27.s64 = ctx.r29.s64 + -424;
loc_8246E54C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8246e564
	if (ctx.cr6.eq) goto loc_8246E564;
	// li r5,424
	ctx.r5.s64 = 424;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8246E564;
	sub_8273A030(ctx, base);
loc_8246E564:
	// addi r27,r27,424
	ctx.r27.s64 = ctx.r27.s64 + 424;
	// addi r29,r29,424
	ctx.r29.s64 = ctx.r29.s64 + 424;
	// cmplw cr6,r27,r31
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x8246e54c
	if (!ctx.cr6.eq) goto loc_8246E54C;
loc_8246E574:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// divw r11,r10,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r10.s32 / ctx.r23.s32 : 0);
	// subfic r11,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r11.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246e5b8
	if (ctx.cr6.eq) goto loc_8246E5B8;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_8246E594:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8246e5ac
	if (ctx.cr6.eq) goto loc_8246E5AC;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,424
	ctx.r5.s64 = 424;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x8246E5AC;
	sub_8273A030(ctx, base);
loc_8246E5AC:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,424
	ctx.r31.s64 = ctx.r31.s64 + 424;
	// bne 0x8246e594
	if (!ctx.cr0.eq) goto loc_8246E594;
loc_8246E5B8:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// addi r11,r11,424
	ctx.r11.s64 = ctx.r11.s64 + 424;
	// addi r29,r11,-424
	ctx.r29.s64 = ctx.r11.s64 + -424;
	// stw r11,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r11.u32);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8246e694
	if (ctx.cr6.eq) goto loc_8246E694;
loc_8246E5D4:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,424
	ctx.r5.s64 = 424;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x8246E5E4;
	sub_8273A030(ctx, base);
	// addi r31,r31,424
	ctx.r31.s64 = ctx.r31.s64 + 424;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8246e5d4
	if (!ctx.cr6.eq) goto loc_8246E5D4;
	// b 0x8246e694
	goto loc_8246E694;
loc_8246E5F4:
	// bl 0x8273a030
	ctx.lr = 0x8246E5F8;
	sub_8273A030(ctx, base);
	// addi r27,r31,-424
	ctx.r27.s64 = ctx.r31.s64 + -424;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
	// cmplw cr6,r27,r31
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8246e634
	if (ctx.cr6.eq) goto loc_8246E634;
loc_8246E60C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8246e624
	if (ctx.cr6.eq) goto loc_8246E624;
	// li r5,424
	ctx.r5.s64 = 424;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8246E624;
	sub_8273A030(ctx, base);
loc_8246E624:
	// addi r26,r26,424
	ctx.r26.s64 = ctx.r26.s64 + 424;
	// addi r29,r29,424
	ctx.r29.s64 = ctx.r29.s64 + 424;
	// cmplw cr6,r26,r31
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x8246e60c
	if (!ctx.cr6.eq) goto loc_8246E60C;
loc_8246E634:
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8246e668
	if (ctx.cr6.eq) goto loc_8246E668;
	// addi r29,r27,424
	ctx.r29.s64 = ctx.r27.s64 + 424;
loc_8246E648:
	// addi r31,r31,-424
	ctx.r31.s64 = ctx.r31.s64 + -424;
	// addi r29,r29,-424
	ctx.r29.s64 = ctx.r29.s64 + -424;
	// li r5,424
	ctx.r5.s64 = 424;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8246E660;
	sub_8273A030(ctx, base);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8246e648
	if (!ctx.cr6.eq) goto loc_8246E648;
loc_8246E668:
	// addi r29,r30,424
	ctx.r29.s64 = ctx.r30.s64 + 424;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8246e694
	if (ctx.cr6.eq) goto loc_8246E694;
loc_8246E678:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,424
	ctx.r5.s64 = 424;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x8246E688;
	sub_8273A030(ctx, base);
	// addi r31,r31,424
	ctx.r31.s64 = ctx.r31.s64 + 424;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8246e678
	if (!ctx.cr6.eq) goto loc_8246E678;
loc_8246E694:
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824890D0) {
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
	// bl 0x82489128
	ctx.lr = 0x824890F0;
	sub_82489128(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82489108
	if (ctx.cr0.eq) goto loc_82489108;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82489108
	if (ctx.cr6.eq) goto loc_82489108;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82489108;
	sub_825E0378(ctx, base);
loc_82489108:
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

DEFINE_REX_FUNC(sub_8248C2C8) {
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
	// lbz r11,364(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 364);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8248c420
	if (ctx.cr0.eq) goto loc_8248C420;
	// lwz r11,360(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 360);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bge cr6,0x8248c420
	if (!ctx.cr6.lt) goto loc_8248C420;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// stb r30,364(r3)
	REX_STORE_U8(ctx.r3.u32 + 364, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,436
	ctx.r4.s64 = 436;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8248C318;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8248c334
	if (ctx.cr0.eq) goto loc_8248C334;
	// addi r5,r31,44
	ctx.r5.s64 = ctx.r31.s64 + 44;
	// lwz r6,288(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8248cdf0
	ctx.lr = 0x8248C330;
	sub_8248CDF0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8248C334:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8248c420
	if (ctx.cr6.eq) goto loc_8248C420;
	// lwa r11,360(r31)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r31.u32 + 360));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-27696(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27696);
	ctx.f0.f64 = double(temp.f32);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r8,r8,-4080
	ctx.r8.s64 = ctx.r8.s64 + -4080;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,148(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 148);
	// lfs f12,-27700(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27700);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,1528(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 1528);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmadds f1,f0,f13,f12
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// bctrl 
	ctx.lr = 0x8248C388;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stfs f0,196(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 196, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f1,332(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 332);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248C3A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,352(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lhz r9,356(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 356);
	// rldicr r10,r10,16,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 16) & 0xFFFFFFFFFFFFFFFF;
	// lwz r11,160(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// ld r4,336(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 336);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// ld r5,344(r31)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r31.u32 + 344);
	// rldicr r6,r10,16,47
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u64, 16) & 0xFFFFFFFFFFFF0000;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248C3D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// addi r10,r11,46
	ctx.r10.s64 = ctx.r11.s64 + 46;
	// addi r9,r11,53
	ctx.r9.s64 = ctx.r11.s64 + 53;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,348(r30)
	REX_STORE_U32(ctx.r30.u32 + 348, ctx.r8.u32);
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r9,352(r30)
	REX_STORE_U32(ctx.r30.u32 + 352, ctx.r9.u32);
	// lwzx r10,r10,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// stw r10,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,360(r30)
	REX_STORE_U32(ctx.r30.u32 + 360, ctx.r11.u32);
	// lwz r11,360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
loc_8248C420:
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

DEFINE_REX_FUNC(sub_8249C0E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8249C0F0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,4004(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4004);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f13,4008(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4008);
	ctx.f13.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x8249C120;
	sub_825E02A0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r27,r11,-16684
	ctx.r27.s64 = ctx.r11.s64 + -16684;
	// beq 0x8249c180
	if (ctx.cr0.eq) goto loc_8249C180;
	// lhz r11,6(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 6);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f12,8040(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8040);
	ctx.f12.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-4440(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4440);
	ctx.f0.f64 = double(temp.f32);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfs f13,-26732(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -26732);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// addi r4,r8,-23044
	ctx.r4.s64 = ctx.r8.s64 + -23044;
	// fmuls f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x82223b50
	ctx.lr = 0x8249C178;
	sub_82223B50(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8249c184
	goto loc_8249C184;
loc_8249C180:
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_8249C184:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8249c2e4
	if (ctx.cr6.eq) goto loc_8249C2E4;
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
	ctx.lr = 0x8249C1A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r28,-32240
	ctx.r28.s64 = -2112880640;
	// lfs f12,-14792(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -14792);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r10,r28,12468
	ctx.r10.s64 = ctx.r28.s64 + 12468;
	// lfs f0,-4444(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4444);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1908(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f12
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fmuls f2,f0,f13
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// bl 0x825a4a40
	ctx.lr = 0x8249C1CC;
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
	ctx.lr = 0x8249C1E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,12468(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// sth r30,102(r31)
	REX_STORE_U16(ctx.r31.u32 + 102, ctx.r30.u16);
	// addi r28,r11,4440
	ctx.r28.s64 = ctx.r11.s64 + 4440;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f0,19408(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 19408);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stfs f0,108(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 108, temp.u32);
	// stb r9,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r9.u8);
	// stfs f13,104(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 104, temp.u32);
	// stw r30,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r30.u32);
	// sth r10,86(r11)
	REX_STORE_U16(ctx.r11.u32 + 86, ctx.r10.u16);
	// stw r10,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// stw r30,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r30.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// sth r30,88(r31)
	REX_STORE_U16(ctx.r31.u32 + 88, ctx.r30.u16);
	// beq cr6,0x8249c234
	if (ctx.cr6.eq) goto loc_8249C234;
	// sth r30,84(r11)
	REX_STORE_U16(ctx.r11.u32 + 84, ctx.r30.u16);
loc_8249C234:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stb r9,91(r31)
	REX_STORE_U8(ctx.r31.u32 + 91, ctx.r9.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8249c248
	if (ctx.cr6.eq) goto loc_8249C248;
	// stb r9,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r9.u8);
loc_8249C248:
	// li r11,255
	ctx.r11.s64 = 255;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// lfs f1,4000(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4000);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,40(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8249C27C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f2,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lfs f1,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8249C28C;
	sub_825A4A40(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82223bf0
	ctx.lr = 0x8249C29C;
	sub_82223BF0(ctx, base);
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
	ctx.lr = 0x8249C2B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x8249C2C0;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8249c2e4
	if (!ctx.cr6.eq) goto loc_8249C2E4;
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
	ctx.lr = 0x8249C2E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8249C2E4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824A9518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x824A9520;
	__savegprlr_18(ctx, base);
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8273af28
	ctx.lr = 0x824A9528;
	__savefpr_28(ctx, base);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,88(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
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
	// bne cr6,0x824a9564
	if (!ctx.cr6.eq) goto loc_824A9564;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824a956c
	if (!ctx.cr6.eq) goto loc_824A956C;
loc_824A9564:
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
loc_824A956C:
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x824a9a7c
	if (ctx.cr6.eq) goto loc_824A9A7C;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x824a9924
	if (ctx.cr6.eq) goto loc_824A9924;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x824a9d68
	if (!ctx.cr6.eq) goto loc_824A9D68;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r28,r11,12236
	ctx.r28.s64 = ctx.r11.s64 + 12236;
	// addi r6,r10,-4080
	ctx.r6.s64 = ctx.r10.s64 + -4080;
	// li r19,0
	ctx.r19.s64 = 0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lfs f30,232(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 232);
	ctx.f30.f64 = double(temp.f32);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lfs f29,2368(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 2368);
	ctx.f29.f64 = double(temp.f32);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// mr r18,r19
	ctx.r18.u64 = ctx.r19.u64;
	// li r21,1
	ctx.r21.s64 = 1;
	// li r25,-1
	ctx.r25.s64 = -1;
	// lis r23,-32111
	ctx.r23.s64 = -2104426496;
	// addi r20,r11,-30128
	ctx.r20.s64 = ctx.r11.s64 + -30128;
	// addi r27,r10,32576
	ctx.r27.s64 = ctx.r10.s64 + 32576;
	// addi r26,r9,32256
	ctx.r26.s64 = ctx.r9.s64 + 32256;
	// addi r22,r8,22072
	ctx.r22.s64 = ctx.r8.s64 + 22072;
	// addi r24,r7,1340
	ctx.r24.s64 = ctx.r7.s64 + 1340;
loc_824A95DC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 48);
	// li r4,140
	ctx.r4.s64 = 140;
	// bl 0x825e02a0
	ctx.lr = 0x824A95EC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824a9608
	if (ctx.cr0.eq) goto loc_824A9608;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lfs f1,-25804(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + -25804);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82223b50
	ctx.lr = 0x824A9600;
	sub_82223B50(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x824a960c
	goto loc_824A960C;
loc_824A9608:
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
loc_824A960C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824a98bc
	if (ctx.cr6.eq) goto loc_824A98BC;
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
	ctx.lr = 0x824A962C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r19,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r19.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x825a4a90
	ctx.lr = 0x824A9638;
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
	ctx.lr = 0x824A964C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,255
	ctx.r11.s64 = 255;
	// divwu r11,r3,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r3.u32 / ctx.r11.u32 : 0);
	// mulli r11,r11,255
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(255));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// li r11,68
	ctx.r11.s64 = 68;
	// blt cr6,0x824a966c
	if (ctx.cr6.lt) goto loc_824A966C;
	// li r11,69
	ctx.r11.s64 = 69;
loc_824A966C:
	// sth r11,102(r30)
	REX_STORE_U16(ctx.r30.u32 + 102, ctx.r11.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r29,60(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x825a4a40
	ctx.lr = 0x824A9684;
	sub_825A4A40(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f30.f64);
	// bge cr6,0x824a9690
	if (!ctx.cr6.lt) goto loc_824A9690;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
loc_824A9690:
	// stfs f1,108(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r29.u32 + 108, temp.u32);
	// stb r21,28(r29)
	REX_STORE_U8(ctx.r29.u32 + 28, ctx.r21.u8);
	// stfs f30,104(r29)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r29.u32 + 104, temp.u32);
	// stw r19,88(r29)
	REX_STORE_U32(ctx.r29.u32 + 88, ctx.r19.u32);
	// sth r25,86(r29)
	REX_STORE_U16(ctx.r29.u32 + 86, ctx.r25.u16);
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// stw r25,100(r29)
	REX_STORE_U32(ctx.r29.u32 + 100, ctx.r25.u32);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stw r19,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r19.u32);
	// lfs f0,68(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lfs f0,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,68(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,200(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
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
	// vmulfp128 v63,v0,v61
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,288(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f31.f64 = double(temp.f32);
	// fneg f28,f31
	ctx.f28.u64 = ctx.f31.u64 ^ 0x8000000000000000;
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// bl 0x825a4a40
	ctx.lr = 0x824A9770;
	sub_825A4A40(ctx, base);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f1,188(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f1,184(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// stfs f1,180(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f1,176(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,156(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825a4a40
	ctx.lr = 0x824A97C0;
	sub_825A4A40(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f1,92(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,216
	ctx.r4.s64 = ctx.r1.s64 + 216;
	// lfs f0,2140(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 2140);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f13,272(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f31,216(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f28,f13,f0
	ctx.f28.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f28,220(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A9820;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fneg f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f31.u64 ^ 0x8000000000000000;
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// fneg f0,f28
	ctx.f0.u64 = ctx.f28.u64 ^ 0x8000000000000000;
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A9848;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,2140(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 2140);
	ctx.f1.f64 = double(temp.f32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82223bf0
	ctx.lr = 0x824A985C;
	sub_82223BF0(ctx, base);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfs f13,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
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
	ctx.lr = 0x824A988C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x82222ad8
	ctx.lr = 0x824A9898;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x824a98bc
	if (!ctx.cr6.eq) goto loc_824A98BC;
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
	ctx.lr = 0x824A98BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824A98BC:
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// lfs f0,-2088(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -2088);
	ctx.f0.f64 = double(temp.f32);
	// clrldi r11,r18,32
	ctx.r11.u64 = ctx.r18.u64 & 0xFFFFFFFF;
	// std r11,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r11.u64);
	// lfd f13,160(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x824a95dc
	if (ctx.cr6.lt) goto loc_824A95DC;
	// stfs f30,68(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// li r3,22
	ctx.r3.s64 = 22;
	// stfs f30,72(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// std r11,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r11.u64);
	// lfs f0,164(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f0.f64 = double(temp.f32);
	// std r11,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r11.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.f0.u64);
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// lwz r5,164(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82240a58
	ctx.lr = 0x824A991C;
	sub_82240A58(ctx, base);
	// stb r21,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r21.u8);
	// b 0x824a9d68
	goto loc_824A9D68;
loc_824A9924:
	// lbz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 284);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824a9d68
	if (ctx.cr0.eq) goto loc_824A9D68;
	// lfs f0,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r31,68
	ctx.r4.s64 = ctx.r31.s64 + 68;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8231e0d8
	ctx.lr = 0x824A9948;
	sub_8231E0D8(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r8,32256
	ctx.r8.s64 = ctx.r8.s64 + 32256;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfs f0,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v6,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32240
	ctx.r6.s64 = -2112880640;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f12,13784(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 13784);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v0,v0,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
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
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f31,f12,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f12.f64, ctx.f0.f64)));
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
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v60,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,0(r4)
	REX_STORE_U64(ctx.r4.u32 + 0, ctx.r11.u64);
	// b 0x824a9d68
	goto loc_824A9D68;
loc_824A9A7C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,328(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 328);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,284(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 284);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// addi r30,r11,12236
	ctx.r30.s64 = ctx.r11.s64 + 12236;
	// stfs f0,328(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f30,232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
	ctx.f30.f64 = double(temp.f32);
	// bne 0x824a9b54
	if (!ctx.cr0.eq) goto loc_824A9B54;
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
	ctx.lr = 0x824A9ABC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A9AD8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-29616
	ctx.r11.s64 = ctx.r11.s64 + -29616;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,1
	ctx.r6.s64 = 1;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,60(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// stb r6,284(r31)
	REX_STORE_U8(ctx.r31.u32 + 284, ctx.r6.u8);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// stfs f0,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
loc_824A9B54:
	// lfs f0,328(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 328);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f13,2140(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2140);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x824a9d10
	if (!ctx.cr6.lt) goto loc_824A9D10;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f13,328(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A9B94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,304(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
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
	// lfs f0,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
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
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vmulfp128 v59,v59,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v59,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v58,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v58,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v58,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// lfs f0,272(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
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
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// b 0x824a9d68
	goto loc_824A9D68;
loc_824A9D10:
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A9D28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// li r11,2
	ctx.r11.s64 = 2;
	// lwz r9,308(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// stw r10,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// stw r9,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r9.u32);
	// stw r10,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r10.u32);
	// stw r9,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r9.u32);
	// stw r10,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r10.u32);
	// stw r9,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r9.u32);
	// stfs f30,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f30,72(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
loc_824A9D68:
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8273af74
	ctx.lr = 0x824A9D74;
	__restfpr_28(ctx, base);
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824F63B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x824F63B8;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,648(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 648);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x824f63d8
	if (!ctx.cr6.eq) goto loc_824F63D8;
loc_824F63CC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r29)
	REX_STORE_U8(ctx.r29.u32 + 23, ctx.r11.u8);
	// b 0x824f6550
	goto loc_824F6550;
loc_824F63D8:
	// bl 0x8259be58
	ctx.lr = 0x824F63DC;
	sub_8259BE58(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x824f63cc
	if (ctx.cr0.eq) goto loc_824F63CC;
	// lwz r9,380(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 380);
	// li r10,24
	ctx.r10.s64 = 24;
	// lwz r8,376(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 376);
	// addi r11,r29,372
	ctx.r11.s64 = ctx.r29.s64 + 372;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// divw. r9,r9,r10
	ctx.r9.u64 = uint32_t((ctx.r10.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r9.s32 / ctx.r10.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x824f63cc
	if (ctx.cr0.eq) goto loc_824F63CC;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r3,432
	ctx.r3.s64 = 432;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// divw r11,r11,r10
	ctx.r11.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	// mulli r30,r11,3
	ctx.r30.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(3));
	// bl 0x825f8d38
	ctx.lr = 0x824F6420;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x824f644c
	if (ctx.cr0.eq) goto loc_824F644C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b88
	ctx.lr = 0x824F6430;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x824F6444;
	sub_825F8BF8(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// b 0x824f6450
	goto loc_824F6450;
loc_824F644C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_824F6450:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824f63cc
	if (ctx.cr6.eq) goto loc_824F63CC;
	// lwz r10,424(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824f63cc
	if (ctx.cr6.eq) goto loc_824F63CC;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824f64e0
	if (ctx.cr6.eq) goto loc_824F64E0;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// addi r7,r8,12236
	ctx.r7.s64 = ctx.r8.s64 + 12236;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
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
loc_824F649C:
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// ld r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
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
	// bne 0x824f649c
	if (!ctx.cr0.eq) goto loc_824F649C;
loc_824F64E0:
	// lwz r10,676(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 676);
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stw r10,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r10.u32);
	// ori r10,r6,262
	ctx.r10.u64 = ctx.r6.u64 | 262;
	// stw r28,208(r11)
	REX_STORE_U32(ctx.r11.u32 + 208, ctx.r28.u32);
	// lfs f0,-8644(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// stb r9,71(r11)
	REX_STORE_U8(ctx.r11.u32 + 71, ctx.r9.u8);
	// lfs f13,-17696(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -17696);
	ctx.f13.f64 = double(temp.f32);
	// lhz r9,6(r29)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r29.u32 + 6);
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lwz r9,408(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 408);
	// ori r9,r9,4
	ctx.r9.u64 = ctx.r9.u64 | 4;
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stw r9,408(r11)
	REX_STORE_U32(ctx.r11.u32 + 408, ctx.r9.u32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,412(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 412, temp.u32);
	// stw r10,368(r11)
	REX_STORE_U32(ctx.r11.u32 + 368, ctx.r10.u32);
	// lwz r10,408(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 408);
	// ori r10,r10,448
	ctx.r10.u64 = ctx.r10.u64 | 448;
	// stw r10,408(r11)
	REX_STORE_U32(ctx.r11.u32 + 408, ctx.r10.u32);
	// stw r11,484(r29)
	REX_STORE_U32(ctx.r29.u32 + 484, ctx.r11.u32);
	// stw r30,488(r29)
	REX_STORE_U32(ctx.r29.u32 + 488, ctx.r30.u32);
loc_824F6550:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82500540) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82500548;
	__savegprlr_29(ctx, base);
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x8273af24
	ctx.lr = 0x82500550;
	__savefpr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8250098c
	if (!ctx.cr0.eq) goto loc_8250098C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r11,15656
	ctx.r29.s64 = ctx.r11.s64 + 15656;
	// lwz r11,340(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 340);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lfs f27,-3188(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -3188);
	ctx.f27.f64 = double(temp.f32);
	// lfs f28,-3184(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -3184);
	ctx.f28.f64 = double(temp.f32);
	// lfs f29,-3420(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -3420);
	ctx.f29.f64 = double(temp.f32);
	// blt cr6,0x8250078c
	if (ctx.cr6.lt) goto loc_8250078C;
	// beq cr6,0x825006f8
	if (ctx.cr6.eq) goto loc_825006F8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8250064c
	if (ctx.cr6.lt) goto loc_8250064C;
	// beq cr6,0x825005a8
	if (ctx.cr6.eq) goto loc_825005A8;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x82500824
	if (!ctx.cr6.lt) goto loc_82500824;
	// b 0x82500640
	goto loc_82500640;
loc_825005A8:
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// lbz r9,337(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 337);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadds f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// addi r11,r11,-9856
	ctx.r11.s64 = ctx.r11.s64 + -9856;
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// beq 0x825005ec
	if (ctx.cr0.eq) goto loc_825005EC;
	// lfs f13,-18952(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18952);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x825005ec
	if (!ctx.cr6.lt) goto loc_825005EC;
	// lfs f13,732(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 732);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f30,f13,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f30.f64, ctx.f13.f64, -ctx.f0.f64)));
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_825005EC:
	// lwz r9,124(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,156(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f12,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f12.f64 = double(temp.f32);
	// fmsubs f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r9,r9,-256
	ctx.xer.ca = ctx.r9.u32 <= 4294967040;
	ctx.r9.u64 = static_cast<uint64_t>(-256) - ctx.r9.u64;
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82500630;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-1280(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1280);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82500824
	if (!ctx.cr6.gt) goto loc_82500824;
loc_82500640:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x82500824
	goto loc_82500824;
loc_8250064C:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f30,f13
	ctx.f13.f64 = double(float(ctx.f30.f64 + ctx.f13.f64));
	// stfs f13,296(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,312(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1948(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1948);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82500694
	if (!ctx.cr6.gt) goto loc_82500694;
	// lfs f13,1952(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1952);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82500694
	if (!ctx.cr6.lt) goto loc_82500694;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f12,-780(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -780);
	ctx.f12.f64 = double(temp.f32);
	// li r30,1
	ctx.r30.s64 = 1;
	// lfs f13,-16572(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16572);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// b 0x8250069c
	goto loc_8250069C;
loc_82500694:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f13,-16572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16572);
	ctx.f13.f64 = double(temp.f32);
loc_8250069C:
	// fmadds f0,f13,f30,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f30.f64, ctx.f0.f64)));
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// lfs f0,-2056(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -2056);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x825006bc
	if (ctx.cr6.lt) goto loc_825006BC;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8250081c
	goto loc_8250081C;
loc_825006BC:
	// lbz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 336);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825006d0
	if (ctx.cr0.eq) goto loc_825006D0;
	// fmr f31,f28
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f28.f64;
	// b 0x825006d4
	goto loc_825006D4;
loc_825006D0:
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f29.f64;
loc_825006D4:
	// bl 0x82738cc0
	ctx.lr = 0x825006D8;
	sub_82738CC0(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-9856
	ctx.r11.s64 = ctx.r11.s64 + -9856;
	// lfs f0,-18952(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18952);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// b 0x82500824
	goto loc_82500824;
loc_825006F8:
	// lbz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 336);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8250070c
	if (ctx.cr0.eq) goto loc_8250070C;
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f28.f64;
	// b 0x82500710
	goto loc_82500710;
loc_8250070C:
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f29.f64;
loc_82500710:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f13,324(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r7,-32227
	ctx.r7.s64 = -2112028672;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f0,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,-20368(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -20368);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82500824
	if (!ctx.cr6.lt) goto loc_82500824;
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x8250081c
	goto loc_8250081C;
loc_8250078C:
	// lbz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 336);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825007a0
	if (ctx.cr0.eq) goto loc_825007A0;
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f28.f64;
	// b 0x825007a4
	goto loc_825007A4;
loc_825007A0:
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f29.f64;
loc_825007A4:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f0.f64 = double(temp.f32);
	// lis r7,-32228
	ctx.r7.s64 = -2112094208;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f13,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,12216(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12216);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82500824
	if (!ctx.cr6.gt) goto loc_82500824;
	// li r11,2
	ctx.r11.s64 = 2;
loc_8250081C:
	// stfs f27,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stw r11,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r11.u32);
loc_82500824:
	// ld r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// clrlwi. r9,r30,24
	ctx.r9.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r30,r11,20196
	ctx.r30.s64 = ctx.r11.s64 + 20196;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// beq 0x82500844
	if (ctx.cr0.eq) goto loc_82500844;
	// lfs f12,20088(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 20088);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82500848
	goto loc_82500848;
loc_82500844:
	// fmr f12,f29
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f29.f64;
loc_82500848:
	// lbz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 336);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8250085c
	if (ctx.cr0.eq) goto loc_8250085C;
	// fmr f13,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f29.f64;
	// b 0x82500860
	goto loc_82500860;
loc_8250085C:
	// fmr f13,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f28.f64;
loc_82500860:
	// lbz r11,337(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 337);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82500874
	if (ctx.cr0.eq) goto loc_82500874;
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f28.f64;
	// b 0x82500878
	goto loc_82500878;
loc_82500874:
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f29.f64;
loc_82500878:
	// fmuls f13,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f11,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f11.f64 = double(temp.f32);
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f0,-16568(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16568);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmadds f1,f0,f30,f11
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f30.f64, ctx.f11.f64)));
	// stfs f1,308(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825008B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bge cr6,0x8250098c
	if (!ctx.cr6.lt) goto loc_8250098C;
	// lfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,300(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x825008f0
	if (!ctx.cr6.gt) goto loc_825008F0;
	// stfs f27,300(r31)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,19
	ctx.r3.s64 = 19;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8257d438
	ctx.lr = 0x825008F0;
	sub_8257D438(ctx, base);
loc_825008F0:
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,304(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8250098c
	if (!ctx.cr6.gt) goto loc_8250098C;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,160
	ctx.r4.s64 = 160;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82500920;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82500944
	if (ctx.cr0.eq) goto loc_82500944;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lbz r7,80(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// lbz r6,336(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 336);
	// lfs f1,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82500ab8
	ctx.lr = 0x8250093C;
	sub_82500AB8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82500948
	goto loc_82500948;
loc_82500944:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82500948:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82500988
	if (ctx.cr6.eq) goto loc_82500988;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x8250095C;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82500988
	if (!ctx.cr6.eq) goto loc_82500988;
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
	ctx.lr = 0x82500988;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82500988:
	// stfs f27,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
loc_8250098C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x8273af70
	ctx.lr = 0x82500998;
	__restfpr_27(ctx, base);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82521088) {
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
	// lbz r11,304(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 304);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825210f0
	if (!ctx.cr0.eq) goto loc_825210F0;
	// lwz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
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
	ctx.lr = 0x825210C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,50
	ctx.r3.s64 = 50;
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// stb r10,304(r31)
	REX_STORE_U8(ctx.r31.u32 + 304, ctx.r10.u8);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8257d438
	ctx.lr = 0x825210F0;
	sub_8257D438(ctx, base);
loc_825210F0:
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

DEFINE_REX_FUNC(sub_82524318) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82524320;
	__savegprlr_27(ctx, base);
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f30.u64);
	// stfd f31,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// ld r29,0(r5)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r5.u32 + 0);
	// ld r30,0(r4)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r4.u32 + 0);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f31,12236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f31.f64 = double(temp.f32);
	// std r29,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r29.u64);
	// lfs f1,18380(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18380);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// std r30,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r30.u64);
	// bl 0x825a4a40
	ctx.lr = 0x8252435C;
	sub_825A4A40(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stfs f1,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f2,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82524378;
	sub_825A4A40(ctx, base);
	// lis r11,-32513
	ctx.r11.s64 = -2130771968;
	// lwz r9,84(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f1,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// ori r10,r11,65535
	ctx.r10.u64 = ctx.r11.u64 | 65535;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r8,140(r1)
	REX_STORE_U8(ctx.r1.u32 + 140, ctx.r8.u8);
	// stw r10,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// beq cr6,0x825243c0
	if (ctx.cr6.eq) goto loc_825243C0;
	// lwz r9,80(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x825243b8
	goto loc_825243B8;
loc_825243A8:
	// lbz r7,36(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 36);
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne 0x82524494
	if (!ctx.cr0.eq) goto loc_82524494;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_825243B8:
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x825243a8
	if (!ctx.cr6.eq) goto loc_825243A8;
loc_825243C0:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lwz r29,80(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r30,r31,76
	ctx.r30.s64 = ctx.r31.s64 + 76;
	// lwz r27,4(r29)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x825243E4;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x825243f0
	if (ctx.cr0.eq) goto loc_825243F0;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_825243F0:
	// addic. r28,r31,4
	ctx.xer.ca = ctx.r31.u32 > 4294967291;
	ctx.r28.s64 = ctx.r31.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x825243fc
	if (ctx.cr0.eq) goto loc_825243FC;
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
loc_825243FC:
	// addic. r3,r31,8
	ctx.xer.ca = ctx.r31.u32 > 4294967287;
	ctx.r3.s64 = ctx.r31.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82524410
	if (ctx.cr0.eq) goto loc_82524410;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,32
	ctx.r5.s64 = 32;
	// bl 0x8273a030
	ctx.lr = 0x82524410;
	sub_8273A030(ctx, base);
loc_82524410:
	// lis r11,2047
	ctx.r11.s64 = 134152192;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8252446c
	if (!ctx.cr6.lt) goto loc_8252446C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,712
	ctx.r4.s64 = ctx.r11.s64 + 712;
	// bl 0x822167f8
	ctx.lr = 0x82524438;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82216678
	ctx.lr = 0x82524444;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x82524448;
	sub_82216E60(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,112
	ctx.r11.s64 = ctx.r11.s64 + 112;
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// bl 0x82216d98
	ctx.lr = 0x8252445C;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8252446C;
	sub_8235EC48(ctx, base);
loc_8252446C:
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
loc_82524484:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_82524494:
	// std r30,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r30.u64);
	// std r29,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r29.u64);
	// stfs f30,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// stfs f1,32(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// stw r10,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// stb r8,36(r11)
	REX_STORE_U8(ctx.r11.u32 + 36, ctx.r8.u8);
	// b 0x82524484
	goto loc_82524484;
}

DEFINE_REX_FUNC(sub_8252E290) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8252E298;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af28
	ctx.lr = 0x8252E2A0;
	__savefpr_28(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,65(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 65);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8252e2c4
	if (ctx.cr0.eq) goto loc_8252E2C4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8252e5c8
	goto loc_8252E5C8;
loc_8252E2C4:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8231e0d8
	ctx.lr = 0x8252E2D0;
	sub_8231E0D8(ctx, base);
	// lis r29,-32228
	ctx.r29.s64 = -2112094208;
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r29,-8704
	ctx.r9.s64 = ctx.r29.s64 + -8704;
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// lfs f0,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,10312(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10312);
	ctx.f31.f64 = double(temp.f32);
	// lfs f1,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
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
	// bl 0x825a4a40
	ctx.lr = 0x8252E30C;
	sub_825A4A40(ctx, base);
	// lis r28,-32240
	ctx.r28.s64 = -2112880640;
	// lfs f13,-8704(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -8704);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// addi r10,r28,14280
	ctx.r10.s64 = ctx.r28.s64 + 14280;
	// lfs f0,156(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,-1808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1808);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f12,f1,f30
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f1,f13
	ctx.f1.f64 = ctx.f13.f64;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f31.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// bl 0x825a4a40
	ctx.lr = 0x8252E378;
	sub_825A4A40(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r29,-32228
	ctx.r29.s64 = -2112094208;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r27,r29,26028
	ctx.r27.s64 = ctx.r29.s64 + 26028;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f30,-21588(r27)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -21588);
	ctx.f30.f64 = double(temp.f32);
	// lfs f29,14280(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 14280);
	ctx.f29.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f31,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// bl 0x825a4a40
	ctx.lr = 0x8252E3E0;
	sub_825A4A40(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f1,108(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f1,96(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vsubfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x825a4a40
	ctx.lr = 0x8252E454;
	sub_825A4A40(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
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
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f1,96(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f1,108(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vsubfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f2,-7648(r27)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -7648);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-5684(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -5684);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// bl 0x825a4a40
	ctx.lr = 0x8252E4B8;
	sub_825A4A40(ctx, base);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f0,26028(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 26028);
	ctx.f0.f64 = double(temp.f32);
	// stfs f1,164(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stb r9,172(r1)
	REX_STORE_U8(ctx.r1.u32 + 172, ctx.r9.u8);
	// stfs f28,160(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// beq cr6,0x8252e500
	if (ctx.cr6.eq) goto loc_8252E500;
	// lwz r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8252e4f8
	goto loc_8252E4F8;
loc_8252E4E8:
	// lbz r8,36(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 36);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne 0x8252e5d8
	if (!ctx.cr0.eq) goto loc_8252E5D8;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8252E4F8:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8252e4e8
	if (!ctx.cr6.eq) goto loc_8252E4E8;
loc_8252E500:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lwz r29,88(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r30,r31,84
	ctx.r30.s64 = ctx.r31.s64 + 84;
	// lwz r27,4(r29)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8252E524;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8252e530
	if (ctx.cr0.eq) goto loc_8252E530;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_8252E530:
	// addic. r28,r31,4
	ctx.xer.ca = ctx.r31.u32 > 4294967291;
	ctx.r28.s64 = ctx.r31.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x8252e53c
	if (ctx.cr0.eq) goto loc_8252E53C;
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
loc_8252E53C:
	// addic. r3,r31,8
	ctx.xer.ca = ctx.r31.u32 > 4294967287;
	ctx.r3.s64 = ctx.r31.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8252e550
	if (ctx.cr0.eq) goto loc_8252E550;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r5,32
	ctx.r5.s64 = 32;
	// bl 0x8273a030
	ctx.lr = 0x8252E550;
	sub_8273A030(ctx, base);
loc_8252E550:
	// lis r11,2047
	ctx.r11.s64 = 134152192;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8252e5ac
	if (!ctx.cr6.lt) goto loc_8252E5AC;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,712
	ctx.r4.s64 = ctx.r11.s64 + 712;
	// bl 0x822167f8
	ctx.lr = 0x8252E578;
	sub_822167F8(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82216678
	ctx.lr = 0x8252E584;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x8252E588;
	sub_82216E60(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r11,r11,112
	ctx.r11.s64 = ctx.r11.s64 + 112;
	// stw r11,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r11.u32);
	// bl 0x82216d98
	ctx.lr = 0x8252E59C;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8235ec48
	ctx.lr = 0x8252E5AC;
	sub_8235EC48(ctx, base);
loc_8252E5AC:
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
loc_8252E5C4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8252E5C8:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af74
	ctx.lr = 0x8252E5D4;
	__restfpr_28(ctx, base);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_8252E5D8:
	// ld r10,152(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// ld r8,144(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r10,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r10.u64);
	// std r8,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r8.u64);
	// stfs f1,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// stfs f28,24(r11)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stb r9,36(r11)
	REX_STORE_U8(ctx.r11.u32 + 36, ctx.r9.u8);
	// stfs f0,32(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// b 0x8252e5c4
	goto loc_8252E5C4;
}

DEFINE_REX_FUNC(sub_82549098) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x825490A0;
	__savegprlr_18(ctx, base);
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8273af28
	ctx.lr = 0x825490A8;
	__savefpr_28(ctx, base);
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82549724
	if (!ctx.cr0.eq) goto loc_82549724;
	// lwz r11,376(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82549724
	if (!ctx.cr6.eq) goto loc_82549724;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r18,1
	ctx.r18.s64 = 1;
	// addi r20,r11,22072
	ctx.r20.s64 = ctx.r11.s64 + 22072;
	// lwz r11,424(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 424);
	// lis r19,-32112
	ctx.r19.s64 = -2104492032;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825491b0
	if (ctx.cr6.eq) goto loc_825491B0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x825495b0
	if (!ctx.cr6.eq) goto loc_825495B0;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,296(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,15656
	ctx.r11.s64 = ctx.r11.s64 + 15656;
	// lfs f13,-3188(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3188);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82549114
	if (!ctx.cr6.lt) goto loc_82549114;
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,296(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// b 0x825495b0
	goto loc_825495B0;
loc_82549114:
	// lwz r11,384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// li r6,4
	ctx.r6.s64 = 4;
	// stfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stw r6,424(r31)
	REX_STORE_U32(ctx.r31.u32 + 424, ctx.r6.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x825491a4
	goto loc_825491A4;
loc_8254912C:
	// lwz r11,8(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8254919c
	if (ctx.cr6.eq) goto loc_8254919C;
	// lwz r9,-12816(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + -12816);
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r8,r11,16
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r9,172(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 172);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82549168
	if (!ctx.cr6.eq) goto loc_82549168;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
	// bne cr6,0x8254916c
	if (!ctx.cr6.eq) goto loc_8254916C;
loc_82549168:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8254916C:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8254919c
	if (ctx.cr0.eq) goto loc_8254919C;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8254919c
	if (!ctx.cr6.eq) goto loc_8254919C;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8254919c
	if (ctx.cr6.eq) goto loc_8254919C;
	// stfs f13,296(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 296, temp.u32);
	// stw r6,424(r11)
	REX_STORE_U32(ctx.r11.u32 + 424, ctx.r6.u32);
loc_8254919C:
	// lwz r7,0(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r11,384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
loc_825491A4:
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8254912c
	if (!ctx.cr6.eq) goto loc_8254912C;
	// b 0x825495b0
	goto loc_825495B0;
loc_825491B0:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825491C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825495b0
	if (ctx.cr0.eq) goto loc_825495B0;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// fadds f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f28.f64));
	// stfs f0,392(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// li r21,0
	ctx.r21.s64 = 0;
	// addi r24,r11,15656
	ctx.r24.s64 = ctx.r11.s64 + 15656;
	// lis r22,-32114
	ctx.r22.s64 = -2104623104;
	// lfs f29,15656(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15656);
	ctx.f29.f64 = double(temp.f32);
	// addi r23,r10,32256
	ctx.r23.s64 = ctx.r10.s64 + 32256;
loc_825491F8:
	// lfs f13,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,396(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x825495b0
	if (!ctx.cr6.gt) goto loc_825495B0;
	// lwz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f13,392(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// lfs f13,332(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 332);
	ctx.f13.f64 = double(temp.f32);
	// std r9,400(r1)
	REX_STORE_U64(ctx.r1.u32 + 400, ctx.r9.u64);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r5,r1,448
	ctx.r5.s64 = ctx.r1.s64 + 448;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
	// lfs f13,336(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 336);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f13,332(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stfs f13,328(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// stfs f13,324(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// stfs f13,320(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// addi r30,r1,544
	ctx.r30.s64 = ctx.r1.s64 + 544;
	// lfd f12,400(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 400);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lvx128 v62,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,416
	ctx.r10.s64 = ctx.r1.s64 + 416;
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,340(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,576
	ctx.r10.s64 = ctx.r1.s64 + 576;
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// vmulfp128 v63,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// stfs f13,168(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f11,344(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,380(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f0,416(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,448(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 448);
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
	// stfs f10,396(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// stfs f10,392(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// stfs f10,388(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// stfs f10,384(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f10,204(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f10,200(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f10,196(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f10,192(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,236(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// vmulfp128 v60,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,232(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lvx128 v59,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f10,268(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// stfs f11,376(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// stfs f11,372(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// stfs f11,368(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// stvx128 v60,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// lfs f0,480(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 480);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// stfs f0,280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// addi r8,r1,512
	ctx.r8.s64 = ctx.r1.s64 + 512;
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// addi r5,r1,432
	ctx.r5.s64 = ctx.r1.s64 + 432;
	// lfs f13,544(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 544);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,316(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// addi r4,r1,464
	ctx.r4.s64 = ctx.r1.s64 + 464;
	// stfs f13,312(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// stfs f13,308(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,496
	ctx.r30.s64 = ctx.r1.s64 + 496;
	// stfs f13,304(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// addi r29,r1,288
	ctx.r29.s64 = ctx.r1.s64 + 288;
	// lfs f12,576(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 576);
	ctx.f12.f64 = double(temp.f32);
	// addi r28,r1,528
	ctx.r28.s64 = ctx.r1.s64 + 528;
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
	// lfs f12,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3984(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 3984);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f1,-3188(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -3188);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	ctx.cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// lfs f13,352(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 352);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,356(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,512(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 512);
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
	// fmuls f11,f11,f10
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,188(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f12,180(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,432(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 432);
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
	// lfs f0,464(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 464);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,292(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,496(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 496);
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
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// fneg f31,f11
	ctx.f31.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r8,r1,560
	ctx.r8.s64 = ctx.r1.s64 + 560;
	// lfs f0,528(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 528);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,592
	ctx.r10.s64 = ctx.r1.s64 + 592;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r25,r18
	ctx.r25.u64 = ctx.r18.u64;
	// stfs f0,208(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lfs f0,560(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 560);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,592(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 592);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// blt cr6,0x82549500
	if (ctx.cr6.lt) goto loc_82549500;
	// li r25,0
	ctx.r25.s64 = 0;
loc_82549500:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// bl 0x825a4a40
	ctx.lr = 0x82549514;
	sub_825A4A40(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,428
	ctx.r4.s64 = 428;
	// lwz r3,44(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 44);
	// lbz r30,81(r31)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// ld r26,360(r31)
	ctx.r26.u64 = REX_LOAD_U64(ctx.r31.u32 + 360);
	// lwz r29,400(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// lbz r28,80(r31)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// lwz r27,88(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x825e02a0
	ctx.lr = 0x8254953C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82549568
	if (ctx.cr0.eq) goto loc_82549568;
	// clrlwi r10,r30,24
	ctx.r10.u64 = ctx.r30.u32 & 0xFF;
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82548698
	ctx.lr = 0x82549564;
	sub_82548698(ctx, base);
	// b 0x8254956c
	goto loc_8254956C;
loc_82549568:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8254956C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8254957c
	if (!ctx.cr6.eq) goto loc_8254957C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82549588
	goto loc_82549588;
loc_8254957C:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f31,304(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 304, temp.u32);
	// std r26,360(r3)
	REX_STORE_U64(ctx.r3.u32 + 360, ctx.r26.u64);
loc_82549588:
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825495a4
	if (ctx.cr6.eq) goto loc_825495A4;
	// addi r3,r31,380
	ctx.r3.s64 = ctx.r31.s64 + 380;
	// lwz r4,384(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82301c68
	ctx.lr = 0x825495A4;
	sub_82301C68(ctx, base);
loc_825495A4:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// cmplwi cr6,r21,5
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 5, ctx.xer);
	// blt cr6,0x825491f8
	if (ctx.cr6.lt) goto loc_825491F8;
loc_825495B0:
	// lwz r11,376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82549724
	if (!ctx.cr6.eq) goto loc_82549724;
	// lbz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 408);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82549724
	if (ctx.cr0.eq) goto loc_82549724;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,404(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 404);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,20344(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20344);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x825495e8
	if (!ctx.cr6.lt) goto loc_825495E8;
	// fadds f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f28.f64));
	// stfs f0,404(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 404, temp.u32);
	// b 0x82549724
	goto loc_82549724;
loc_825495E8:
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x82549614
	if (ctx.cr6.eq) goto loc_82549614;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8254960C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825496b8
	if (!ctx.cr0.eq) goto loc_825496B8;
loc_82549614:
	// lwz r11,384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x825496a0
	goto loc_825496A0;
loc_82549624:
	// lwz r11,8(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82549698
	if (ctx.cr6.eq) goto loc_82549698;
	// lwz r9,-12816(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + -12816);
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r8,r11,16
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r9,172(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 172);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82549660
	if (!ctx.cr6.eq) goto loc_82549660;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
	// bne cr6,0x82549664
	if (!ctx.cr6.eq) goto loc_82549664;
loc_82549660:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82549664:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82549698
	if (ctx.cr0.eq) goto loc_82549698;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82549698
	if (!ctx.cr6.eq) goto loc_82549698;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82549698
	if (ctx.cr6.eq) goto loc_82549698;
	// lbz r11,409(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 409);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825496ac
	if (ctx.cr0.eq) goto loc_825496AC;
loc_82549698:
	// lwz r7,0(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r11,384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
loc_825496A0:
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82549624
	if (!ctx.cr6.eq) goto loc_82549624;
	// b 0x825496b0
	goto loc_825496B0;
loc_825496AC:
	// mr r6,r18
	ctx.r6.u64 = ctx.r18.u64;
loc_825496B0:
	// clrlwi. r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825496f8
	if (ctx.cr0.eq) goto loc_825496F8;
loc_825496B8:
	// li r5,0
	ctx.r5.s64 = 0;
	// lbz r30,81(r31)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// li r4,348
	ctx.r4.s64 = 348;
	// lbz r29,80(r31)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// ld r28,360(r31)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r31.u32 + 360);
	// lwz r27,88(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r3,44(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x825496D8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825496f4
	if (ctx.cr0.eq) goto loc_825496F4;
	// clrlwi r7,r30,24
	ctx.r7.u64 = ctx.r30.u32 & 0xFF;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x8254ac20
	ctx.lr = 0x825496F4;
	sub_8254AC20(ctx, base);
loc_825496F4:
	// stb r18,420(r31)
	REX_STORE_U8(ctx.r31.u32 + 420, ctx.r18.u8);
loc_825496F8:
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x8254970c
	if (!ctx.cr6.eq) goto loc_8254970C;
	// stb r18,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r18.u8);
	// b 0x82549714
	goto loc_82549714;
loc_8254970C:
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r11,424(r31)
	REX_STORE_U32(ctx.r31.u32 + 424, ctx.r11.u32);
loc_82549714:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8254a618
	ctx.lr = 0x8254971C;
	sub_8254A618(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,408(r31)
	REX_STORE_U8(ctx.r31.u32 + 408, ctx.r11.u8);
loc_82549724:
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8273af74
	ctx.lr = 0x82549730;
	__restfpr_28(ctx, base);
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8257E1F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8257E200;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82213210
	ctx.lr = 0x8257E208;
	sub_82213210(ctx, base);
	// addi r9,r3,4120
	ctx.r9.s64 = ctx.r3.s64 + 4120;
	// li r30,100
	ctx.r30.s64 = 100;
	// lbz r11,28(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,100
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 100, ctx.xer);
	// ble cr6,0x8257e220
	if (!ctx.cr6.gt) goto loc_8257E220;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8257E220:
	// lbz r10,29(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 29);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// cmplwi cr6,r10,100
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 100, ctx.xer);
	// bgt cr6,0x8257e234
	if (ctx.cr6.gt) goto loc_8257E234;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
loc_8257E234:
	// lbz r31,30(r9)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r9.u32 + 30);
	// cmplwi cr6,r31,100
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 100, ctx.xer);
	// ble cr6,0x8257e244
	if (!ctx.cr6.gt) goto loc_8257E244;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_8257E244:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// mulli r11,r11,127
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(127));
	// addi r11,r11,99
	ctx.r11.s64 = ctx.r11.s64 + 99;
	// divwu r4,r11,r30
	ctx.r4.u64 = uint32_t(ctx.r30.u32 ? ctx.r11.u32 / ctx.r30.u32 : 0);
	// bl 0x82576838
	ctx.lr = 0x8257E25C;
	sub_82576838(ctx, base);
	// clrlwi r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	// li r3,5
	ctx.r3.s64 = 5;
	// mulli r11,r11,127
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(127));
	// addi r11,r11,99
	ctx.r11.s64 = ctx.r11.s64 + 99;
	// divwu r4,r11,r30
	ctx.r4.u64 = uint32_t(ctx.r30.u32 ? ctx.r11.u32 / ctx.r30.u32 : 0);
	// bl 0x82576838
	ctx.lr = 0x8257E274;
	sub_82576838(ctx, base);
	// clrlwi r11,r31,24
	ctx.r11.u64 = ctx.r31.u32 & 0xFF;
	// li r3,17
	ctx.r3.s64 = 17;
	// mulli r11,r11,127
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(127));
	// addi r11,r11,99
	ctx.r11.s64 = ctx.r11.s64 + 99;
	// divwu r4,r11,r30
	ctx.r4.u64 = uint32_t(ctx.r30.u32 ? ctx.r11.u32 / ctx.r30.u32 : 0);
	// bl 0x82576838
	ctx.lr = 0x8257E28C;
	sub_82576838(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82582D80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82739c60
	ctx.lr = 0x82582DB8;
	sub_82739C60(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82584BB8) {
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
	// bl 0x82584c10
	ctx.lr = 0x82584BD8;
	sub_82584C10(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82584bf0
	if (ctx.cr0.eq) goto loc_82584BF0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82584bf0
	if (ctx.cr6.eq) goto loc_82584BF0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82584BF0;
	sub_825E0378(ctx, base);
loc_82584BF0:
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

DEFINE_REX_FUNC(sub_82586820) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x82586828;
	__savegprlr_19(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825869ec
	if (ctx.cr6.eq) goto loc_825869EC;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x82586848;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82586870
	if (ctx.cr0.eq) goto loc_82586870;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b88
	ctx.lr = 0x82586858;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x8258686C;
	sub_825F8BF8(ctx, base);
	// b 0x82586874
	goto loc_82586874;
loc_82586870:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82586874:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825869ec
	if (ctx.cr6.eq) goto loc_825869EC;
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// addi r9,r11,-12
	ctx.r9.s64 = ctx.r11.s64 + -12;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8258688C:
	// li r10,0
	ctx.r10.s64 = 0;
	// stwu r10,40(r9)
	ea = 40 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8258688c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8258688C;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r8,r10,14248
	ctx.r8.s64 = ctx.r10.s64 + 14248;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
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
	// lfs f0,14248(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14248);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r11,40
	ctx.r5.s64 = ctx.r11.s64 + 40;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-1780(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -1780);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r1,144
	ctx.r29.s64 = ctx.r1.s64 + 144;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vpermwi128 v60,v63,174
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x51));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r28,r1,160
	ctx.r28.s64 = ctx.r1.s64 + 160;
	// lfs f13,-2012(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -2012);
	ctx.f13.f64 = double(temp.f32);
	// addi r23,r1,192
	ctx.r23.s64 = ctx.r1.s64 + 192;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lwa r10,156(r10)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r10.u32 + 156));
	// lfs f12,-8(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lwz r8,0(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r27,4(r7)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r20,8(r9)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r19,12(r9)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r26,8(r7)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r7,12(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r25,0(r6)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r24,4(r6)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r22,8(r6)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lis r21,-32111
	ctx.r21.s64 = -2104426496;
	// lwz r6,12(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// vpermwi128 v62,v63,234
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x15));
	// stw r27,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// vpermwi128 v61,v63,186
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x45));
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// vpermwi128 v63,v63,171
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x54));
	// stw r26,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r26.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stw r7,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r25,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r25.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r24,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r24.u32);
	// stvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r22,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r22.u32);
	// stvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r6.u32);
	// stw r9,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r9.u32);
	// stvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r8.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stw r20,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r20.u32);
	// stw r19,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r19.u32);
	// lwz r11,44(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// stfs f0,412(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// lwz r10,408(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// stw r10,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r10.u32);
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// lwz r11,3596(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 3596);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// bl 0x8273a030
	ctx.lr = 0x825869E0;
	sub_8273A030(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r31,36(r30)
	REX_STORE_U32(ctx.r30.u32 + 36, ctx.r31.u32);
	// stw r11,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r11.u32);
loc_825869EC:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82594D70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82594D78;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8273af24
	ctx.lr = 0x82594D80;
	__savefpr_27(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,74(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8259530c
	if (ctx.cr0.eq) goto loc_8259530C;
	// lbz r11,56(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 56);
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82594da8
	if (!ctx.cr0.eq) goto loc_82594DA8;
	// stb r30,56(r3)
	REX_STORE_U8(ctx.r3.u32 + 56, ctx.r30.u8);
loc_82594DA8:
	// lbz r11,56(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 56);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8259530c
	if (ctx.cr0.eq) goto loc_8259530C;
	// lwz r11,28(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 28);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8259511c
	if (ctx.cr6.lt) goto loc_8259511C;
	// beq cr6,0x82594dd8
	if (ctx.cr6.eq) goto loc_82594DD8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8259530c
	if (!ctx.cr6.lt) goto loc_8259530C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,74(r25)
	REX_STORE_U8(ctx.r25.u32 + 74, ctx.r11.u8);
	// b 0x8259530c
	goto loc_8259530C;
loc_82594DD8:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r28,r11,12468
	ctx.r28.s64 = ctx.r11.s64 + 12468;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r31,r25,300
	ctx.r31.s64 = ctx.r25.s64 + 300;
	// lfs f29,17092(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17092);
	ctx.f29.f64 = double(temp.f32);
	// addi r29,r25,108
	ctx.r29.s64 = ctx.r25.s64 + 108;
	// lfs f27,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// li r26,6
	ctx.r26.s64 = 6;
	// lfs f28,-30128(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30128);
	ctx.f28.f64 = double(temp.f32);
	// addi r27,r11,3456
	ctx.r27.s64 = ctx.r11.s64 + 3456;
loc_82594E08:
	// lwz r3,-216(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -216);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825950f4
	if (ctx.cr6.eq) goto loc_825950F4;
	// bl 0x824443c8
	ctx.lr = 0x82594E18;
	sub_824443C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x825950f4
	if (ctx.cr0.eq) goto loc_825950F4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x82594E28;
	sub_825A43F0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// bl 0x82430c30
	ctx.lr = 0x82594E38;
	sub_82430C30(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
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
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
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
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,0(r29)
	REX_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,660(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 660);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82594EEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,696(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 696);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82594F04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fdivs f0,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f1.f64));
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// stfs f0,-144(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + -144, temp.u32);
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,664(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 664);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82594F24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,700(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 700);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82594F3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fdivs f0,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f1.f64));
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// stfs f0,-120(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + -120, temp.u32);
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,660(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 660);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82594F5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,-48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -48);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// ble cr6,0x82594fdc
	if (!ctx.cr6.gt) goto loc_82594FDC;
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f27
	ctx.cr6.compare(ctx.f13.f64, ctx.f27.f64);
	// ble cr6,0x82594f8c
	if (!ctx.cr6.gt) goto loc_82594F8C;
	// fsubs f0,f13,f30
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// bge cr6,0x82594ff0
	if (!ctx.cr6.lt) goto loc_82594FF0;
	// stfs f27,0(r31)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// b 0x82594ff0
	goto loc_82594FF0;
loc_82594F8C:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// fsubs f31,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,696(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 696);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82594FA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// fneg f13,f0
	ctx.f13.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f31,f13
	ctx.cr6.compare(ctx.f31.f64, ctx.f13.f64);
	// bge cr6,0x82594fc0
	if (!ctx.cr6.lt) goto loc_82594FC0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82594fcc
	goto loc_82594FCC;
loc_82594FC0:
	// fcmpu cr6,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x82594fcc
	if (ctx.cr6.gt) goto loc_82594FCC;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
loc_82594FCC:
	// lfs f13,-48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -48);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,-48(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + -48, temp.u32);
	// b 0x82594ff0
	goto loc_82594FF0;
loc_82594FDC:
	// fcmpu cr6,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bgt cr6,0x82594ff0
	if (ctx.cr6.gt) goto loc_82594FF0;
	// lfs f0,3188(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 3188);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f1,-48(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + -48, temp.u32);
loc_82594FF0:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,696(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 696);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82595004;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,-48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -48);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f1.f64));
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// stfs f0,-96(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + -96, temp.u32);
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,664(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 664);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82595028;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,-24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -24);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// ble cr6,0x825950a8
	if (!ctx.cr6.gt) goto loc_825950A8;
	// lfs f13,24(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f27
	ctx.cr6.compare(ctx.f13.f64, ctx.f27.f64);
	// ble cr6,0x82595058
	if (!ctx.cr6.gt) goto loc_82595058;
	// fsubs f0,f13,f30
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// bge cr6,0x825950bc
	if (!ctx.cr6.lt) goto loc_825950BC;
	// stfs f27,24(r31)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// b 0x825950bc
	goto loc_825950BC;
loc_82595058:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// fsubs f31,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,700(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 700);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82595070;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// fneg f13,f0
	ctx.f13.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f31,f13
	ctx.cr6.compare(ctx.f31.f64, ctx.f13.f64);
	// bge cr6,0x8259508c
	if (!ctx.cr6.lt) goto loc_8259508C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82595098
	goto loc_82595098;
loc_8259508C:
	// fcmpu cr6,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x82595098
	if (ctx.cr6.gt) goto loc_82595098;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
loc_82595098:
	// lfs f13,-24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -24);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,-24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + -24, temp.u32);
	// b 0x825950bc
	goto loc_825950BC;
loc_825950A8:
	// fcmpu cr6,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bgt cr6,0x825950bc
	if (ctx.cr6.gt) goto loc_825950BC;
	// lfs f0,3188(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 3188);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stfs f1,-24(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + -24, temp.u32);
loc_825950BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x825950C4;
	sub_825A43F0(ctx, base);
	// lfs f0,68(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,68(r25)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r25.u32 + 68, temp.u32);
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,700(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 700);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825950E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,-24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -24);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f1.f64));
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// stfs f0,-72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + -72, temp.u32);
loc_825950F4:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// bne 0x82594e08
	if (!ctx.cr0.eq) goto loc_82594E08;
	// lbz r11,76(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 76);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8259530c
	if (ctx.cr0.eq) goto loc_8259530C;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,28(r25)
	REX_STORE_U32(ctx.r25.u32 + 28, ctx.r11.u32);
	// b 0x8259530c
	goto loc_8259530C;
loc_8259511C:
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lwz r11,40(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 40);
	// mulli r10,r11,52
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(52));
	// lwz r11,-12824(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12824);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82595154
	if (ctx.cr6.eq) goto loc_82595154;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82595154
	if (ctx.cr6.eq) goto loc_82595154;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// bne cr6,0x82595158
	if (!ctx.cr6.eq) goto loc_82595158;
loc_82595154:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82595158:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8259530c
	if (!ctx.cr0.eq) goto loc_8259530C;
	// lwz r3,44(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 44);
	// bl 0x8259be58
	ctx.lr = 0x82595168;
	sub_8259BE58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825951a8
	if (ctx.cr0.eq) goto loc_825951A8;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x825fa250
	ctx.lr = 0x82595178;
	sub_825FA250(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825951a8
	if (ctx.cr0.eq) goto loc_825951A8;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r30,19,11,12
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 19) & 0x180000) | (ctx.r10.u64 & 0xFFFFFFFFFFE7FFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r30,21,9,10
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 21) & 0x600000) | (ctx.r10.u64 & 0xFFFFFFFFFF9FFFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825f9cf8
	ctx.lr = 0x825951A8;
	sub_825F9CF8(ctx, base);
loc_825951A8:
	// lwz r11,-12824(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12824);
	// lwz r10,48(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 48);
	// mulli r10,r10,52
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(52));
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825951dc
	if (ctx.cr6.eq) goto loc_825951DC;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x825951dc
	if (ctx.cr6.eq) goto loc_825951DC;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// bne cr6,0x825951e0
	if (!ctx.cr6.eq) goto loc_825951E0;
loc_825951DC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_825951E0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82595234
	if (!ctx.cr0.eq) goto loc_82595234;
	// lwz r3,52(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 52);
	// bl 0x8259be58
	ctx.lr = 0x825951F0;
	sub_8259BE58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82595230
	if (ctx.cr0.eq) goto loc_82595230;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x825fa250
	ctx.lr = 0x82595200;
	sub_825FA250(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82595230
	if (ctx.cr0.eq) goto loc_82595230;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r30,19,11,12
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 19) & 0x180000) | (ctx.r10.u64 & 0xFFFFFFFFFFE7FFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r30,21,9,10
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 21) & 0x600000) | (ctx.r10.u64 & 0xFFFFFFFFFF9FFFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825f9cf8
	ctx.lr = 0x82595230;
	sub_825F9CF8(ctx, base);
loc_82595230:
	// stw r30,28(r25)
	REX_STORE_U32(ctx.r25.u32 + 28, ctx.r30.u32);
loc_82595234:
	// lis r26,-32112
	ctx.r26.s64 = -2104492032;
	// lwz r8,-12952(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + -12952);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82595274
	if (ctx.cr6.eq) goto loc_82595274;
	// li r11,6
	ctx.r11.s64 = 6;
	// lwz r10,20(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 20);
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82595254:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82595264
	if (ctx.cr6.eq) goto loc_82595264;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_82595264:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82595254
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82595254;
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// b 0x82595278
	goto loc_82595278;
loc_82595274:
	// li r27,0
	ctx.r27.s64 = 0;
loc_82595278:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8259530c
	if (ctx.cr6.eq) goto loc_8259530C;
	// addi r31,r25,252
	ctx.r31.s64 = ctx.r25.s64 + 252;
	// subfic r28,r25,-252
	ctx.xer.ca = ctx.r25.u32 <= 4294967044;
	ctx.r28.u64 = static_cast<uint64_t>(-252) - ctx.r25.u64;
loc_8259528C:
	// cmplwi cr6,r29,6
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 6, ctx.xer);
	// bge cr6,0x825952ac
	if (!ctx.cr6.lt) goto loc_825952AC;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x825952ac
	if (ctx.cr6.eq) goto loc_825952AC;
	// lwz r11,20(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 20);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwzx r3,r11,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// b 0x825952b0
	goto loc_825952B0;
loc_825952AC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825952B0:
	// stw r3,-168(r31)
	REX_STORE_U32(ctx.r31.u32 + -168, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825952fc
	if (ctx.cr6.eq) goto loc_825952FC;
	// bl 0x824443c8
	ctx.lr = 0x825952C0;
	sub_824443C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x825952fc
	if (ctx.cr0.eq) goto loc_825952FC;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,696(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 696);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825952DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,700(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 700);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825952F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,-12952(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + -12952);
	// stfs f1,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
loc_825952FC:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x8259528c
	if (ctx.cr6.lt) goto loc_8259528C;
loc_8259530C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8273af70
	ctx.lr = 0x82595318;
	__restfpr_27(ctx, base);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C0650) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x825C0658;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r28,r11,204
	ctx.r28.s64 = ctx.r11.s64 + 204;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b44
	ctx.lr = 0x825C0670;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x825b3350
	ctx.lr = 0x825C0678;
	sub_825B3350(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c0720
	if (ctx.cr6.lt) goto loc_825C0720;
	// lwz r11,236(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c06d0
	if (ctx.cr6.eq) goto loc_825C06D0;
	// addi r29,r31,24
	ctx.r29.s64 = ctx.r31.s64 + 24;
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
loc_825C0698:
	// lwz r11,204(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 204);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c06ac
	if (ctx.cr6.eq) goto loc_825C06AC;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x825c06b0
	goto loc_825C06B0;
loc_825C06AC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825C06B0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C06C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,236(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x825c0698
	if (!ctx.cr6.eq) goto loc_825C0698;
loc_825C06D0:
	// lwz r3,248(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r30,r31,244
	ctx.r30.s64 = ctx.r31.s64 + 244;
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x825c0708
	if (ctx.cr6.eq) goto loc_825C0708;
loc_825C06E0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825c06fc
	if (ctx.cr6.eq) goto loc_825C06FC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C06FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825C06FC:
	// lwz r3,248(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825c06e0
	if (!ctx.cr6.eq) goto loc_825C06E0;
loc_825C0708:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C0720;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825C0720:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b34
	ctx.lr = 0x825C0728;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C6C38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825C6C40;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r31,48(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r29,r11,44
	ctx.r29.s64 = ctx.r11.s64 + 44;
loc_825C6C58:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x825c6ce8
	if (ctx.cr6.eq) goto loc_825C6CE8;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c6ca0
	if (ctx.cr6.eq) goto loc_825C6CA0;
	// lwz r9,36(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x825c6c98
	if (ctx.cr6.eq) goto loc_825C6C98;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C6C94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_825C6C98:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x825c6cd8
	if (ctx.cr6.lt) goto loc_825C6CD8;
loc_825C6CA0:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c6cd8
	if (ctx.cr6.eq) goto loc_825C6CD8;
	// lwz r9,36(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x825c6cd8
	if (ctx.cr6.eq) goto loc_825C6CD8;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C6CD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_825C6CD8:
	// lwz r31,4(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x825c6c58
	if (!ctx.cr6.lt) goto loc_825C6C58;
loc_825C6CE8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825CC708) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee8
	ctx.lr = 0x825CC710;
	__savegprlr_16(ctx, base);
	// stfd f30,-152(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -152, ctx.f30.u64);
	// stfd f31,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r9,76(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 76);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,92(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// addic r10,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r10.s64 = ctx.r6.s64 + -1;
	// stb r5,343(r1)
	REX_STORE_U8(ctx.r1.u32 + 343, ctx.r5.u8);
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// subfe r3,r10,r6
	temp.u8 = (~ctx.r10.u32 + ctx.r6.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addic r10,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// stb r5,60(r31)
	REX_STORE_U8(ctx.r31.u32 + 60, ctx.r5.u8);
	// lis r12,0
	ctx.r12.s64 = 0;
	// subfe r5,r10,r4
	temp.u8 = (~ctx.r10.u32 + ctx.r4.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r10.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r6,r30,31,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x1;
	// rlwimi r5,r3,5,26,26
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0x20) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFDF);
	// ori r12,r12,47035
	ctx.r12.u64 = ctx.r12.u64 | 47035;
	// rlwinm r3,r5,4,22,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0x3F0;
	// and r4,r9,r12
	ctx.r4.u64 = ctx.r9.u64 & ctx.r12.u64;
	// rlwinm r3,r3,0,27,22
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFFE1F;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// or r10,r3,r6
	ctx.r10.u64 = ctx.r3.u64 | ctx.r6.u64;
	// li r16,1
	ctx.r16.s64 = 1;
	// rlwinm r9,r10,2,16,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFC;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r16,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r16.u32);
	// or r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 | ctx.r4.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// mr r25,r29
	ctx.r25.u64 = ctx.r29.u64;
	// sth r8,76(r31)
	REX_STORE_U16(ctx.r31.u32 + 76, ctx.r8.u16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825cc7e8
	if (ctx.cr6.eq) goto loc_825CC7E8;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r8,56(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r7,32(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 32);
	// lwz r25,64(r8)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r8.u32 + 64);
	// lhz r4,1(r7)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r7.u32 + 1);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x825cc7d0
	if (ctx.cr6.eq) goto loc_825CC7D0;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CC7CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825cc7d4
	goto loc_825CC7D4;
loc_825CC7D0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_825CC7D4:
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lhz r10,76(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// subfe r9,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r10,r9,2,29,29
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// sth r10,76(r31)
	REX_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
loc_825CC7E8:
	// addi r7,r1,343
	ctx.r7.s64 = ctx.r1.s64 + 343;
	// stw r29,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825c3fa8
	ctx.lr = 0x825CC804;
	sub_825C3FA8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825ccd2c
	if (ctx.cr6.lt) goto loc_825CCD2C;
	// lwz r17,96(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r28,r31,24
	ctx.r28.s64 = ctx.r31.s64 + 24;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825c0e98
	ctx.lr = 0x825CC824;
	sub_825C0E98(ctx, base);
	// li r10,9
	ctx.r10.s64 = 9;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stw r29,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r29.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_825CC83C:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x825cc83c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825CC83C;
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lhz r4,28(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CC860;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,40(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r9,124(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// clrlwi r11,r8,30
	ctx.r11.u64 = ctx.r8.u32 & 0x3;
	// lbz r19,343(r1)
	ctx.r19.u64 = REX_LOAD_U8(ctx.r1.u32 + 343);
	// mr r21,r9
	ctx.r21.u64 = ctx.r9.u64;
	// mr r18,r10
	ctx.r18.u64 = ctx.r10.u64;
	// add r23,r10,r9
	ctx.r23.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lwz r20,112(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r24,116(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// blt cr6,0x825cc89c
	if (ctx.cr6.lt) goto loc_825CC89C;
	// beq cr6,0x825cc89c
	if (ctx.cr6.eq) goto loc_825CC89C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x825cc8bc
	if (ctx.cr6.eq) goto loc_825CC8BC;
loc_825CC89C:
	// clrlwi r11,r19,24
	ctx.r11.u64 = ctx.r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825cc8bc
	if (ctx.cr6.eq) goto loc_825CC8BC;
	// cmplw cr6,r27,r9
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x825cc8bc
	if (!ctx.cr6.gt) goto loc_825CC8BC;
	// cmplw cr6,r27,r23
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r23.u32, ctx.xer);
	// mr r26,r16
	ctx.r26.u64 = ctx.r16.u64;
	// blt cr6,0x825cc8c0
	if (ctx.cr6.lt) goto loc_825CC8C0;
loc_825CC8BC:
	// mr r26,r29
	ctx.r26.u64 = ctx.r29.u64;
loc_825CC8C0:
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// stw r29,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r29,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f0,12236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// beq cr6,0x825cc918
	if (ctx.cr6.eq) goto loc_825CC918;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,20(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r8,32(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// lbz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// rlwinm r6,r7,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r6,16
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 16, ctx.xer);
	// bne cr6,0x825cc918
	if (!ctx.cr6.eq) goto loc_825CC918;
	// lwz r9,16(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 16);
	// mr r10,r16
	ctx.r10.u64 = ctx.r16.u64;
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// lfs f0,124(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
loc_825CC918:
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cntlzw r8,r26
	ctx.r8.u64 = ctx.r26.u32 == 0 ? 32 : __builtin_clz(ctx.r26.u32);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// lhz r7,76(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// rlwinm r6,r7,30,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x1;
	// xori r11,r4,1
	ctx.r11.u64 = ctx.r4.u64 ^ 1;
	// lwz r3,36(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 36);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// addi r8,r1,100
	ctx.r8.s64 = ctx.r1.s64 + 100;
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825CC960;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825ccd2c
	if (ctx.cr6.lt) goto loc_825CCD2C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x825c3528
	ctx.lr = 0x825CC974;
	sub_825C3528(ctx, base);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// clrlwi r30,r11,30
	ctx.r30.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x825cc9c4
	if (!ctx.cr6.eq) goto loc_825CC9C4;
	// clrlwi r11,r19,24
	ctx.r11.u64 = ctx.r19.u32 & 0xFF;
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825cc9a4
	if (!ctx.cr6.eq) goto loc_825CC9A4;
	// stw r29,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// stw r29,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
	// stw r29,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// stw r29,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
loc_825CC9A4:
	// cmplwi cr6,r17,128
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 128, ctx.xer);
	// ble cr6,0x825cc9b4
	if (!ctx.cr6.gt) goto loc_825CC9B4;
	// clrlwi r11,r17,25
	ctx.r11.u64 = ctx.r17.u32 & 0x7F;
	// subf r29,r11,r17
	ctx.r29.u64 = ctx.r17.u64 - ctx.r11.u64;
loc_825CC9B4:
	// stw r29,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r29.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x825ccc10
	goto loc_825CCC10;
loc_825CC9C4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r25,r29
	ctx.r25.u64 = ctx.r29.u64;
	// bl 0x825c1128
	ctx.lr = 0x825CC9D0;
	sub_825C1128(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// blt cr6,0x825cca24
	if (ctx.cr6.lt) goto loc_825CCA24;
	// beq cr6,0x825cca24
	if (ctx.cr6.eq) goto loc_825CCA24;
	// cmplwi cr6,r30,3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 3, ctx.xer);
	// bne cr6,0x825cca24
	if (!ctx.cr6.eq) goto loc_825CCA24;
	// lwz r3,8(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lhz r4,4(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CCA00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cca24
	if (ctx.cr6.eq) goto loc_825CCA24;
	// lwz r3,8(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lhz r4,4(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CCA20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_825CCA24:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x825ccb2c
	if (ctx.cr6.eq) goto loc_825CCB2C;
	// subf r11,r24,r23
	ctx.r11.u64 = ctx.r23.u64 - ctx.r24.u64;
	// stw r29,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
	// lwz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r30,r31,108
	ctx.r30.s64 = ctx.r31.s64 + 108;
	// lwz r9,116(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// subf r11,r27,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r27.u64;
	// lwz r6,120(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r29,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r4,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r4.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r29,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// stw r6,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r6.u32);
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// stw r29,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r30,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// stw r29,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r29.u32);
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CCA98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825ccd2c
	if (ctx.cr6.lt) goto loc_825CCD2C;
	// clrlwi r11,r19,24
	ctx.r11.u64 = ctx.r19.u32 & 0xFF;
	// add r10,r21,r20
	ctx.r10.u64 = ctx.r21.u64 + ctx.r20.u64;
	// subf r9,r21,r24
	ctx.r9.u64 = ctx.r24.u64 - ctx.r21.u64;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// bne cr6,0x825ccac4
	if (!ctx.cr6.eq) goto loc_825CCAC4;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x825ccac8
	goto loc_825CCAC8;
loc_825CCAC4:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_825CCAC8:
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// addi r11,r31,124
	ctx.r11.s64 = ctx.r31.s64 + 124;
	// lwz r9,56(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// stw r18,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r18.u32);
	// stw r10,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r3,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stw r10,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stw r29,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// stw r29,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// stw r9,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// stw r16,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r16.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// b 0x825ccc30
	goto loc_825CCC30;
loc_825CCB2C:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x825ccb60
	if (ctx.cr6.lt) goto loc_825CCB60;
	// beq cr6,0x825ccb60
	if (ctx.cr6.eq) goto loc_825CCB60;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x825ccb60
	if (!ctx.cr6.eq) goto loc_825CCB60;
	// clrlwi r11,r19,24
	ctx.r11.u64 = ctx.r19.u32 & 0xFF;
	// stw r17,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r17.u32);
	// stw r21,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r21.u32);
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// stw r18,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r18.u32);
	// b 0x825ccc08
	goto loc_825CCC08;
loc_825CCB60:
	// lwz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// subf r11,r27,r21
	ctx.r11.u64 = ctx.r21.u64 - ctx.r27.u64;
	// lwz r9,116(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// cmplw cr6,r27,r21
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r21.u32, ctx.xer);
	// add r8,r10,r27
	ctx.r8.u64 = ctx.r10.u64 + ctx.r27.u64;
	// subf r7,r27,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r27.u64;
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r7,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// bgt cr6,0x825ccbd4
	if (ctx.cr6.gt) goto loc_825CCBD4;
	// clrlwi r10,r19,24
	ctx.r10.u64 = ctx.r19.u32 & 0xFF;
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825ccba4
	if (!ctx.cr6.eq) goto loc_825CCBA4;
loc_825CCB98:
	// stw r29,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825ccbb0
	if (ctx.cr6.eq) goto loc_825CCBB0;
loc_825CCBA4:
	// cmplw cr6,r27,r21
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r21.u32, ctx.xer);
	// stw r18,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r18.u32);
	// ble cr6,0x825ccbb4
	if (!ctx.cr6.gt) goto loc_825CCBB4;
loc_825CCBB0:
	// stw r29,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
loc_825CCBB4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825ccbe0
	if (ctx.cr6.eq) goto loc_825CCBE0;
	// cmplw cr6,r27,r21
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r21.u32, ctx.xer);
	// bgt cr6,0x825ccbe0
	if (ctx.cr6.gt) goto loc_825CCBE0;
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// subf r9,r17,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r17.u64;
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// b 0x825ccbe4
	goto loc_825CCBE4;
loc_825CCBD4:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r29,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// b 0x825ccb98
	goto loc_825CCB98;
loc_825CCBE0:
	// stw r29,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
loc_825CCBE4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825ccc04
	if (ctx.cr6.eq) goto loc_825CCC04;
	// cmplw cr6,r27,r21
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r21.u32, ctx.xer);
	// bgt cr6,0x825ccc04
	if (ctx.cr6.gt) goto loc_825CCC04;
	// lwz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// subf r10,r17,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r17.u64;
	// stw r10,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// b 0x825ccc08
	goto loc_825CCC08;
loc_825CCC04:
	// stw r29,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
loc_825CCC08:
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
loc_825CCC10:
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r11,r31,108
	ctx.r11.s64 = ctx.r31.s64 + 108;
	// stw r16,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r16.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_825CCC30:
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bctrl 
	ctx.lr = 0x825CCC3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825ccd28
	if (ctx.cr6.lt) goto loc_825CCD28;
	// lhz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// ori r10,r11,16384
	ctx.r10.u64 = ctx.r11.u64 | 16384;
	// sth r10,76(r31)
	REX_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825CCC68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825ccc88
	if (ctx.cr6.eq) goto loc_825CCC88;
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lhz r4,28(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,120(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CCC88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825CCC88:
	// li r11,2
	ctx.r11.s64 = 2;
	// li r4,12
	ctx.r4.s64 = 12;
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825c3d68
	ctx.lr = 0x825CCC9C;
	sub_825C3D68(ctx, base);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825ccd28
	if (ctx.cr6.eq) goto loc_825CCD28;
	// lwz r29,88(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x825ccd28
	if (ctx.cr6.eq) goto loc_825CCD28;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r3,20(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lfs f31,40(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 40);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,56(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 56);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x825c67c0
	ctx.lr = 0x825CCCCC;
	sub_825C67C0(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825CCCE8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,92(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r6,44(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 44);
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,16(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 16);
	// lwz r11,8(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r10,20(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// lfs f13,60(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,44(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lfs f11,128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,100(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f10.f64));
	// fadds f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// fadds f1,f8,f12
	ctx.f1.f64 = double(float(ctx.f8.f64 + ctx.f12.f64));
	// bctrl 
	ctx.lr = 0x825CCD28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825CCD28:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_825CCD2C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f31,-144(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FA4F0) {
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
	// addi r31,r11,-15456
	ctx.r31.s64 = ctx.r11.s64 + -15456;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x825FA510;
	sub_825F8ED0(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lwz r10,-15460(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -15460);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// lwz r11,-15436(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15436);
	// divwu r10,r6,r11
	ctx.r10.u64 = uint32_t(ctx.r11.u32 ? ctx.r6.u32 / ctx.r11.u32 : 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lwz r10,-15464(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + -15464);
	// subf r11,r11,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r11.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,-15460(r9)
	REX_STORE_U32(ctx.r9.u32 + -15460, ctx.r11.u32);
	// lwzx r11,r8,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stw r11,-15440(r7)
	REX_STORE_U32(ctx.r7.u32 + -15440, ctx.r11.u32);
	// lwsync 
	// li r10,0
	ctx.r10.s64 = 0;
loc_825FA558:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
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
	// bne 0x825fa558
	if (!ctx.cr0.eq) goto loc_825FA558;
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

DEFINE_REX_FUNC(sub_825FF020) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x825FF028;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,0(r4)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x825fc6d8
	ctx.lr = 0x825FF040;
	sub_825FC6D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fec48
	ctx.lr = 0x825FF050;
	sub_825FEC48(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825ff27c
	if (ctx.cr0.eq) goto loc_825FF27C;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r27,8
	ctx.r27.s64 = 8;
	// lwz r9,404(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 404);
	// li r28,20
	ctx.r28.s64 = 20;
	// lwz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,12
	ctx.r6.s64 = 12;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,444(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 444);
	// bne cr6,0x825ff0c8
	if (!ctx.cr6.eq) goto loc_825FF0C8;
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r9,14
	ctx.r9.s64 = 14;
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// sth r9,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r9.u16);
	// sth r27,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r27.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r9,444(r10)
	REX_STORE_U32(ctx.r10.u32 + 444, ctx.r9.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r11,436
	ctx.r10.s64 = ctx.r11.s64 + 436;
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,444(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 444);
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// stw r28,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r28.u32);
	// b 0x825ff10c
	goto loc_825FF10C;
loc_825FF0C8:
	// sth r27,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r27.u16);
	// li r8,14
	ctx.r8.s64 = 14;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// sth r8,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r8.u16);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r8,444(r10)
	REX_STORE_U32(ctx.r10.u32 + 444, ctx.r8.u32);
	// lwz r8,400(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 400);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r11,436
	ctx.r10.s64 = ctx.r11.s64 + 436;
	// lwz r5,0(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,444(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 444);
	// stw r5,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
	// stw r8,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
loc_825FF10C:
	// sth r6,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r6.u16);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// sth r28,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r28.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r29,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// stw r7,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// bl 0x825fee28
	ctx.lr = 0x825FF138;
	sub_825FEE28(ctx, base);
	// addi r4,r30,64
	ctx.r4.s64 = ctx.r30.s64 + 64;
	// lwz r5,388(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 388);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825fc918
	ctx.lr = 0x825FF148;
	sub_825FC918(ctx, base);
	// lwz r11,408(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// rlwinm. r11,r11,0,22,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825ff1c0
	if (!ctx.cr0.eq) goto loc_825FF1C0;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r9,13
	ctx.r9.s64 = 13;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,3
	ctx.r7.s64 = 3;
	// lwz r11,444(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 444);
	// sth r9,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r9.u16);
	// sth r27,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r27.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r29,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// stw r9,444(r10)
	REX_STORE_U32(ctx.r10.u32 + 444, ctx.r9.u32);
	// lwz r6,416(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 416);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r5,384(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 384);
	// addi r10,r11,436
	ctx.r10.s64 = ctx.r11.s64 + 436;
	// lwz r11,444(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 444);
	// sth r8,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r8.u16);
	// sth r7,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r7.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// stw r29,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// stw r6,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// b 0x825ff27c
	goto loc_825FF27C;
loc_825FF1C0:
	// lwz r11,420(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 420);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r26,r11,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// bl 0x825feb88
	ctx.lr = 0x825FF1D8;
	sub_825FEB88(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825ff1e8
	if (!ctx.cr0.eq) goto loc_825FF1E8;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// b 0x825ff1fc
	goto loc_825FF1FC;
loc_825FF1E8:
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// lwz r4,428(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 428);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8273a030
	ctx.lr = 0x825FF1F8;
	sub_8273A030(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
loc_825FF1FC:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825ff27c
	if (ctx.cr0.eq) goto loc_825FF27C;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r7,13
	ctx.r7.s64 = 13;
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,444(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 444);
	// lwz r5,4(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// sth r7,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r7.u16);
	// sth r27,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r27.u16);
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r9,444(r10)
	REX_STORE_U32(ctx.r10.u32 + 444, ctx.r9.u32);
	// lwz r7,384(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 384);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,420(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 420);
	// lwz r11,444(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 444);
	// stw r9,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// sth r6,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r6.u16);
	// sth r28,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r28.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// stw r7,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r29,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,444(r10)
	REX_STORE_U32(ctx.r10.u32 + 444, ctx.r11.u32);
loc_825FF27C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82612F18) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,34
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 34, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-7408
	ctx.r12.s64 = ctx.r12.s64 + -7408;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32159
	ctx.r12.s64 = -2107572224;
	// nop 
	// addi r12,r12,12108
	ctx.r12.s64 = ctx.r12.s64 + 12108;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82612F4C;
	case 1:
		goto loc_82612F58;
	case 2:
		goto loc_82612F64;
	case 3:
		goto loc_82612F70;
	case 4:
		goto loc_82612F7C;
	case 5:
		goto loc_82612F88;
	case 6:
		goto loc_82612F94;
	case 7:
		goto loc_82612FA0;
	case 8:
		goto loc_82612FAC;
	case 9:
		goto loc_82612FB8;
	case 10:
		goto loc_82612FC4;
	case 11:
		goto loc_82612FD0;
	case 12:
		goto loc_82612FDC;
	case 13:
		goto loc_82612FE8;
	case 14:
		goto loc_82612FF4;
	case 15:
		goto loc_82613000;
	case 16:
		goto loc_8261300C;
	case 17:
		goto loc_82613018;
	case 18:
		goto loc_82613024;
	case 19:
		goto loc_82613030;
	case 20:
		goto loc_8261303C;
	case 21:
		goto loc_82613048;
	case 22:
		goto loc_82613054;
	case 23:
		goto loc_82613060;
	case 24:
		goto loc_82613068;
	case 25:
		goto loc_82613070;
	case 26:
		goto loc_82613078;
	case 27:
		goto loc_82613080;
	case 28:
		goto loc_8261308C;
	case 29:
		goto loc_82613098;
	case 30:
		goto loc_826130A4;
	case 31:
		goto loc_826130B0;
	case 32:
		goto loc_826130BC;
	case 33:
		goto loc_826130C8;
	case 34:
		goto loc_826130D4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82612F4C:
	// lis r11,44
	ctx.r11.s64 = 2883584;
	// ori r11,r11,33700
	ctx.r11.u64 = ctx.r11.u64 | 33700;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612F58:
	// lis r11,44
	ctx.r11.s64 = 2883584;
	// ori r11,r11,9125
	ctx.r11.u64 = ctx.r11.u64 | 9125;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612F64:
	// lis r11,42
	ctx.r11.s64 = 2752512;
	// ori r11,r11,9145
	ctx.r11.u64 = ctx.r11.u64 | 9145;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612F70:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// ori r11,r11,9126
	ctx.r11.u64 = ctx.r11.u64 | 9126;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612F7C:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// ori r11,r11,8582
	ctx.r11.u64 = ctx.r11.u64 | 8582;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612F88:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// ori r11,r11,8326
	ctx.r11.u64 = ctx.r11.u64 | 8326;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612F94:
	// lis r11,44
	ctx.r11.s64 = 2883584;
	// ori r11,r11,8537
	ctx.r11.u64 = ctx.r11.u64 | 8537;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612FA0:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// ori r11,r11,8538
	ctx.r11.u64 = ctx.r11.u64 | 8538;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612FAC:
	// lis r11,44
	ctx.r11.s64 = 2883584;
	// ori r11,r11,8281
	ctx.r11.u64 = ctx.r11.u64 | 8281;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612FB8:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// ori r11,r11,8282
	ctx.r11.u64 = ctx.r11.u64 | 8282;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612FC4:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// ori r11,r11,9094
	ctx.r11.u64 = ctx.r11.u64 | 9094;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612FD0:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// ori r11,r11,8838
	ctx.r11.u64 = ctx.r11.u64 | 8838;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612FDC:
	// lis r11,44
	ctx.r11.s64 = 2883584;
	// ori r11,r11,9049
	ctx.r11.u64 = ctx.r11.u64 | 9049;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612FE8:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// ori r11,r11,9050
	ctx.r11.u64 = ctx.r11.u64 | 9050;
	// b 0x826130dc
	goto loc_826130DC;
loc_82612FF4:
	// lis r11,44
	ctx.r11.s64 = 2883584;
	// ori r11,r11,8793
	ctx.r11.u64 = ctx.r11.u64 | 8793;
	// b 0x826130dc
	goto loc_826130DC;
loc_82613000:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// ori r11,r11,8794
	ctx.r11.u64 = ctx.r11.u64 | 8794;
	// b 0x826130dc
	goto loc_826130DC;
loc_8261300C:
	// lis r11,44
	ctx.r11.s64 = 2883584;
	// ori r11,r11,9055
	ctx.r11.u64 = ctx.r11.u64 | 9055;
	// b 0x826130dc
	goto loc_826130DC;
loc_82613018:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// ori r11,r11,9056
	ctx.r11.u64 = ctx.r11.u64 | 9056;
	// b 0x826130dc
	goto loc_826130DC;
loc_82613024:
	// lis r11,24
	ctx.r11.s64 = 1572864;
	// ori r11,r11,10374
	ctx.r11.u64 = ctx.r11.u64 | 10374;
	// b 0x826130dc
	goto loc_826130DC;
loc_82613030:
	// lis r11,42
	ctx.r11.s64 = 2752512;
loc_82613034:
	// ori r11,r11,9095
	ctx.r11.u64 = ctx.r11.u64 | 9095;
	// b 0x826130dc
	goto loc_826130DC;
loc_8261303C:
	// lis r11,42
	ctx.r11.s64 = 2752512;
loc_82613040:
	// ori r11,r11,8839
	ctx.r11.u64 = ctx.r11.u64 | 8839;
	// b 0x826130dc
	goto loc_826130DC;
loc_82613048:
	// lis r11,42
	ctx.r11.s64 = 2752512;
loc_8261304C:
	// ori r11,r11,8583
	ctx.r11.u64 = ctx.r11.u64 | 8583;
	// b 0x826130dc
	goto loc_826130DC;
loc_82613054:
	// lis r11,42
	ctx.r11.s64 = 2752512;
loc_82613058:
	// ori r11,r11,8327
	ctx.r11.u64 = ctx.r11.u64 | 8327;
	// b 0x826130dc
	goto loc_826130DC;
loc_82613060:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// b 0x82613034
	goto loc_82613034;
loc_82613068:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// b 0x82613040
	goto loc_82613040;
loc_82613070:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// b 0x8261304c
	goto loc_8261304C;
loc_82613078:
	// lis r11,26
	ctx.r11.s64 = 1703936;
	// b 0x82613058
	goto loc_82613058;
loc_82613080:
	// lis r11,42
	ctx.r11.s64 = 2752512;
	// ori r11,r11,9104
	ctx.r11.u64 = ctx.r11.u64 | 9104;
	// b 0x826130dc
	goto loc_826130DC;
loc_8261308C:
	// lis r11,42
	ctx.r11.s64 = 2752512;
	// ori r11,r11,8848
	ctx.r11.u64 = ctx.r11.u64 | 8848;
	// b 0x826130dc
	goto loc_826130DC;
loc_82613098:
	// lis r11,42
	ctx.r11.s64 = 2752512;
	// ori r11,r11,8592
	ctx.r11.u64 = ctx.r11.u64 | 8592;
	// b 0x826130dc
	goto loc_826130DC;
loc_826130A4:
	// lis r11,42
	ctx.r11.s64 = 2752512;
	// ori r11,r11,8336
	ctx.r11.u64 = ctx.r11.u64 | 8336;
	// b 0x826130dc
	goto loc_826130DC;
loc_826130B0:
	// lis r11,42
	ctx.r11.s64 = 2752512;
	// ori r11,r11,9105
	ctx.r11.u64 = ctx.r11.u64 | 9105;
	// b 0x826130dc
	goto loc_826130DC;
loc_826130BC:
	// lis r11,42
	ctx.r11.s64 = 2752512;
	// ori r11,r11,8849
	ctx.r11.u64 = ctx.r11.u64 | 8849;
	// b 0x826130dc
	goto loc_826130DC;
loc_826130C8:
	// lis r11,42
	ctx.r11.s64 = 2752512;
	// ori r11,r11,8593
	ctx.r11.u64 = ctx.r11.u64 | 8593;
	// b 0x826130dc
	goto loc_826130DC;
loc_826130D4:
	// lis r11,42
	ctx.r11.s64 = 2752512;
	// ori r11,r11,8337
	ctx.r11.u64 = ctx.r11.u64 | 8337;
loc_826130DC:
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261C8A8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,20,9,11
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 20) & 0x700000) | (ctx.r11.u64 & 0xFFFFFFFFFF8FFFFF);
	// stw r11,10548(r3)
	REX_STORE_U32(ctx.r3.u32 + 10548, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261CCE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,12624(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12624);
	// li r12,1
	ctx.r12.s64 = 1;
	// lwz r9,10460(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 10460);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// stw r4,12044(r3)
	REX_STORE_U32(ctx.r3.u32 + 12044, ctx.r4.u32);
	// rldicr r12,r12,37,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 & ctx.r4.u64;
	// rlwimi r9,r11,8,20,23
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFFF0FF);
	// stw r9,10460(r3)
	REX_STORE_U32(ctx.r3.u32 + 10460, ctx.r9.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261DAE8) {
	REX_FUNC_PROLOGUE();
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// mulli r10,r10,24
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(24));
	// lbz r9,12178(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 12178);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// li r8,1
	ctx.r8.s64 = 1;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rldicr r31,r8,63,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r5,12(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r9,r6,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,16(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwimi r5,r30,31,13,31
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x7FFFF) | (ctx.r5.u64 & 0xFFFFFFFFFFF80000);
	// andc r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// rlwimi r5,r30,31,1,11
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x7FF00000) | (ctx.r5.u64 & 0xFFFFFFFF800FFFFF);
	// clrldi r30,r7,32
	ctx.r30.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rlwinm r7,r5,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 13) & 0xFFF;
	// srd r5,r31,r30
	ctx.r5.u64 = ctx.r30.u8 & 0x40 ? 0 : (ctx.r31.u64 >> (ctx.r30.u8 & 0x7F));
	// and r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 & ctx.r9.u64;
	// addi r9,r11,12178
	ctx.r9.s64 = ctx.r11.s64 + 12178;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwimi r8,r4,0,0,29
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFC) | (ctx.r8.u64 & 0xFFFFFFFF00000003);
	// stw r8,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stb r6,12178(r11)
	REX_STORE_U8(ctx.r11.u32 + 12178, ctx.r6.u8);
	// ld r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 | ctx.r11.u64;
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82626310) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r30,16384
	ctx.r30.s64 = 1073741824;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82626358
	if (ctx.cr6.eq) goto loc_82626358;
	// lwz r9,12(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r10,r9,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82626358:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r4,r11,30,2,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// bl 0x82626840
	ctx.lr = 0x8262636C;
	sub_82626840(ctx, base);
	// mr. r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x82626388
	if (!ctx.cr0.eq) goto loc_82626388;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,16936(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16936);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// b 0x826263fc
	goto loc_826263FC;
loc_82626388:
	// addi r11,r8,4
	ctx.r11.s64 = ctx.r8.s64 + 4;
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
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826263d4
	if (ctx.cr6.eq) goto loc_826263D4;
	// rlwinm r10,r8,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFF;
	// clrlwi r9,r8,3
	ctx.r9.u64 = ctx.r8.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x826263d8
	goto loc_826263D8;
loc_826263D4:
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
loc_826263D8:
	// rlwinm r10,r8,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFF;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r8,3
	ctx.r9.u64 = ctx.r8.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r3,r30,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r30.u64;
	// add r4,r11,r3
	ctx.r4.u64 = ctx.r11.u64 + ctx.r3.u64;
	// bl 0x826323d0
	ctx.lr = 0x826263FC;
	sub_826323D0(ctx, base);
loc_826263FC:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r3,r8,4
	ctx.r3.s64 = ctx.r8.s64 + 4;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_82630CE8) {
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
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// srawi. r10,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 31;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82630d18
	if (ctx.cr0.eq) goto loc_82630D18;
	// lis r31,10922
	ctx.r31.s64 = 715784192;
	// ori r31,r31,43690
	ctx.r31.u64 = ctx.r31.u64 | 43690;
	// b 0x82630d30
	goto loc_82630D30;
loc_82630D18:
	// rlwinm. r9,r11,0,1,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82630d2c
	if (ctx.cr0.eq) goto loc_82630D2C;
	// lis r31,5461
	ctx.r31.s64 = 357892096;
	// ori r31,r31,21845
	ctx.r31.u64 = ctx.r31.u64 | 21845;
	// b 0x82630d30
	goto loc_82630D30;
loc_82630D2C:
	// li r31,-1
	ctx.r31.s64 = -1;
loc_82630D30:
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82630d60
	if (ctx.cr0.eq) goto loc_82630D60;
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// li r9,3
	ctx.r9.s64 = 3;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// slw r11,r9,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r8.u8 & 0x3F));
	// and r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 & ctx.r31.u64;
	// bne cr6,0x82630d60
	if (!ctx.cr6.eq) goto loc_82630D60;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82630d60
	if (!ctx.cr6.eq) goto loc_82630D60;
	// oris r31,r31,32768
	ctx.r31.u64 = ctx.r31.u64 | 2147483648;
loc_82630D60:
	// bl 0x82855964
	ctx.lr = 0x82630D64;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82630d78
	if (!ctx.cr6.eq) goto loc_82630D78;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,2256(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2256);
	// b 0x82630d80
	goto loc_82630D80;
loc_82630D78:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,2252(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2252);
loc_82630D80:
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,356(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 356);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82630db0
	if (ctx.cr6.eq) goto loc_82630DB0;
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// stw r31,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r31.u32);
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// ori r11,r11,25088
	ctx.r11.u64 = ctx.r11.u64 | 25088;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82626c50
	ctx.lr = 0x82630DB0;
	sub_82626C50(ctx, base);
loc_82630DB0:
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

DEFINE_REX_FUNC(sub_826395E0) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82855914
	__imp__MmFreePhysicalMemory(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82639830) {
	REX_FUNC_PROLOGUE();
	// li r4,5
	ctx.r4.s64 = 5;
	// b 0x828556f4
	__imp__XamNotifyCreateListener(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82639948) {
	REX_FUNC_PROLOGUE();
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x826398b8
	sub_826398B8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826399E0) {
	REX_FUNC_PROLOGUE();
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x82639950
	sub_82639950(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82639A90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82639A98;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// mulli r10,r4,52
	ctx.r10.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(52));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// mullw r10,r10,r6
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// beq cr6,0x82639adc
	if (ctx.cr6.eq) goto loc_82639ADC;
	// addi r7,r7,-132
	ctx.r7.s64 = ctx.r7.s64 + -132;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_82639AC8:
	// lwzu r6,136(r7)
	ea = 136 + ctx.r7.u32;
	ctx.r6.u64 = REX_LOAD_U32(ea);
	ctx.r7.u32 = ea;
	// mullw r6,r6,r4
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r4.s32);
	// mulli r6,r6,28
	ctx.r6.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(28));
	// add r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 + ctx.r10.u64;
	// bdnz 0x82639ac8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82639AC8;
loc_82639ADC:
	// lwz r31,0(r8)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x82639af4
	if (!ctx.cr6.gt) goto loc_82639AF4;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// li r3,122
	ctx.r3.s64 = 122;
	// b 0x82639b60
	goto loc_82639B60;
loc_82639AF4:
	// stw r4,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r7,28
	ctx.r7.s64 = 28;
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r30,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// ori r4,r4,33
	ctx.r4.u64 = ctx.r4.u64 | 33;
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// bl 0x82855704
	ctx.lr = 0x82639B2C;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82639b3c
	if (!ctx.cr0.lt) goto loc_82639B3C;
	// li r3,1627
	ctx.r3.s64 = 1627;
	// b 0x82639b60
	goto loc_82639B60;
loc_82639B3C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82639b5c
	if (!ctx.cr6.eq) goto loc_82639B5C;
	// bl 0x8263bcc8
	ctx.lr = 0x82639B48;
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
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x82639b60
	goto loc_82639B60;
loc_82639B5C:
	// li r3,997
	ctx.r3.s64 = 997;
loc_82639B60:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8263D6D0) {
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
	// lwz r11,56(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r3,64
	ctx.r4.s64 = ctx.r3.s64 + 64;
	// addi r3,r30,44
	ctx.r3.s64 = ctx.r30.s64 + 44;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r11,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stw r11,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// stw r11,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r11.u32);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// stw r11,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r11.u32);
	// lwz r5,60(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// bl 0x8273a030
	ctx.lr = 0x8263D744;
	sub_8273A030(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stb r10,44(r11)
	REX_STORE_U8(ctx.r11.u32 + 44, ctx.r10.u8);
	// stb r10,304(r30)
	REX_STORE_U8(ctx.r30.u32 + 304, ctx.r10.u8);
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

DEFINE_REX_FUNC(sub_82642B70) {
	REX_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,24(r4)
	REX_STORE_U32(ctx.r4.u32 + 24, ctx.r11.u32);
	// lwz r11,396(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 396);
	// stw r11,28(r4)
	REX_STORE_U32(ctx.r4.u32 + 28, ctx.r11.u32);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stw r11,32(r4)
	REX_STORE_U32(ctx.r4.u32 + 32, ctx.r11.u32);
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// stw r11,36(r4)
	REX_STORE_U32(ctx.r4.u32 + 36, ctx.r11.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// stw r11,40(r4)
	REX_STORE_U32(ctx.r4.u32 + 40, ctx.r11.u32);
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// stw r11,44(r4)
	REX_STORE_U32(ctx.r4.u32 + 44, ctx.r11.u32);
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// stw r11,48(r4)
	REX_STORE_U32(ctx.r4.u32 + 48, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82643558) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82643560;
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82643588;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82642e78
	ctx.lr = 0x82643590;
	sub_82642E78(ctx, base);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x826435d4
	if (ctx.cr0.lt) goto loc_826435D4;
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x826435b4
	if (ctx.cr6.lt) goto loc_826435B4;
	// lis r3,-30570
	ctx.r3.s64 = -2003435520;
	// ori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 | 1;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
loc_826435B4:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826435d4
	if (ctx.cr6.lt) goto loc_826435D4;
	// lwz r10,156(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// mulli r11,r30,1068
	ctx.r11.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(1068));
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r5,1068
	ctx.r5.s64 = 1068;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8273a030
	ctx.lr = 0x826435D4;
	sub_8273A030(ctx, base);
loc_826435D4:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826435E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826422f8
	ctx.lr = 0x826435F0;
	sub_826422F8(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82647600) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// rlwinm. r5,r4,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// beq 0x8264765c
	if (ctx.cr0.eq) goto loc_8264765C;
	// add r7,r3,r5
	ctx.r7.u64 = ctx.r3.u64 + ctx.r5.u64;
loc_8264763C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r6,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8264765c
	if (!ctx.cr0.eq) goto loc_8264765C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bne cr6,0x8264763c
	if (!ctx.cr6.eq) goto loc_8264763C;
loc_8264765C:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8264767c
	if (ctx.cr0.eq) goto loc_8264767C;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x8273a030
	ctx.lr = 0x8264766C;
	sub_8273A030(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82646748
	ctx.lr = 0x82647678;
	sub_82646748(ctx, base);
	// b 0x82647680
	goto loc_82647680;
loc_8264767C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82647680:
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

DEFINE_REX_FUNC(sub_8264AD88) {
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
	// bl 0x82647c50
	ctx.lr = 0x8264ADA8;
	sub_82647C50(ctx, base);
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// bne cr6,0x8264add4
	if (!ctx.cr6.eq) goto loc_8264ADD4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,184(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// b 0x8264adec
	goto loc_8264ADEC;
loc_8264ADD4:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,184(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// lwz r9,32(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
loc_8264ADEC:
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_8264CFD8) {
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
	// addi r31,r3,36
	ctx.r31.s64 = ctx.r3.s64 + 36;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82855b44
	ctx.lr = 0x8264CFFC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,32(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// bl 0x82855f64
	ctx.lr = 0x8264D00C;
	__imp__KeSetEvent(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82855b34
	ctx.lr = 0x8264D014;
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

DEFINE_REX_FUNC(sub_8264ECE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// addi r11,r3,28
	ctx.r11.s64 = ctx.r3.s64 + 28;
loc_8264ECE4:
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
	// bne 0x8264ece4
	if (!ctx.cr0.eq) goto loc_8264ECE4;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826511D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x826511D8;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,184(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 184);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r21,r7
	ctx.r21.u64 = ctx.r7.u64;
	// mr r20,r8
	ctx.r20.u64 = ctx.r8.u64;
	// mr r23,r9
	ctx.r23.u64 = ctx.r9.u64;
	// mr r22,r10
	ctx.r22.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82651210
	if (ctx.cr6.eq) goto loc_82651210;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82651258
	goto loc_82651258;
loc_82651210:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// blt cr6,0x82651244
	if (ctx.cr6.lt) goto loc_82651244;
	// cmplwi cr6,r30,64
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 64, ctx.xer);
	// bgt cr6,0x82651244
	if (ctx.cr6.gt) goto loc_82651244;
	// cmplwi cr6,r27,1
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 1, ctx.xer);
	// blt cr6,0x82651244
	if (ctx.cr6.lt) goto loc_82651244;
	// cmplwi cr6,r27,64
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 64, ctx.xer);
	// bgt cr6,0x82651244
	if (ctx.cr6.gt) goto loc_82651244;
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82651260
	if (ctx.cr6.eq) goto loc_82651260;
	// cmpwi cr6,r18,3
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 3, ctx.xer);
	// beq cr6,0x82651260
	if (ctx.cr6.eq) goto loc_82651260;
loc_82651244:
	// lis r25,-30569
	ctx.r25.s64 = -2003369984;
	// ori r25,r25,1
	ctx.r25.u64 = ctx.r25.u64 | 1;
loc_8265124C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82651000
	ctx.lr = 0x82651254;
	sub_82651000(ctx, base);
loc_82651254:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
loc_82651258:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
loc_82651260:
	// lis r11,16383
	ctx.r11.s64 = 1073676288;
	// stw r21,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r21.u32);
	// mullw r19,r30,r27
	ctx.r19.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r27.s32);
	// stw r20,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r20.u32);
	// ori r26,r11,65535
	ctx.r26.u64 = ctx.r11.u64 | 65535;
	// li r25,-1
	ctx.r25.s64 = -1;
	// cmplw cr6,r19,r26
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r19,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82651288
	if (!ctx.cr6.gt) goto loc_82651288;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82651288:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,8343
	ctx.r10.s64 = 546766848;
	// addi r29,r11,13120
	ctx.r29.s64 = ctx.r11.s64 + 13120;
	// ori r28,r10,10
	ctx.r28.u64 = ctx.r10.u64 | 10;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82641ff8
	ctx.lr = 0x826512A8;
	sub_82641FF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// beq 0x826513a4
	if (ctx.cr0.eq) goto loc_826513A4;
	// cmplw cr6,r19,r26
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r19,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x826512c4
	if (!ctx.cr6.gt) goto loc_826512C4;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_826512C4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x82641ff8
	ctx.lr = 0x826512D4;
	sub_82641FF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r3.u32);
	// beq 0x826513a4
	if (ctx.cr0.eq) goto loc_826513A4;
	// cmplw cr6,r19,r26
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r19,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x826512f0
	if (!ctx.cr6.gt) goto loc_826512F0;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_826512F0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x82641ff8
	ctx.lr = 0x82651300;
	sub_82641FF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r3.u32);
	// beq 0x826513a4
	if (ctx.cr0.eq) goto loc_826513A4;
	// cmplw cr6,r19,r26
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r19,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8265131c
	if (!ctx.cr6.gt) goto loc_8265131C;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8265131C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x82641ff8
	ctx.lr = 0x8265132C;
	sub_82641FF8(ctx, base);
	// stw r3,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x826513a4
	if (ctx.cr0.eq) goto loc_826513A4;
	// cmplw cr6,r19,r26
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r19,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82651348
	if (!ctx.cr6.gt) goto loc_82651348;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82651348:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x82641ff8
	ctx.lr = 0x82651358;
	sub_82641FF8(ctx, base);
	// stw r3,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x826513a4
	if (ctx.cr0.eq) goto loc_826513A4;
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826513b0
	if (ctx.cr6.eq) goto loc_826513B0;
	// lwz r11,292(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// mullw r11,r30,r11
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r11.s32);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82651388
	if (!ctx.cr6.gt) goto loc_82651388;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82651388:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x82641ff8
	ctx.lr = 0x82651398;
	sub_82641FF8(ctx, base);
	// stw r3,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x826513b0
	if (!ctx.cr0.eq) goto loc_826513B0;
loc_826513A4:
	// lis r25,-32761
	ctx.r25.s64 = -2147024896;
	// ori r25,r25,14
	ctx.r25.u64 = ctx.r25.u64 | 14;
	// b 0x8265124c
	goto loc_8265124C;
loc_826513B0:
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826513f4
	if (ctx.cr6.eq) goto loc_826513F4;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r30,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x826513cc
	if (!ctx.cr6.gt) goto loc_826513CC;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_826513CC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x82641ff8
	ctx.lr = 0x826513DC;
	sub_82641FF8(ctx, base);
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x826513a4
	if (ctx.cr0.eq) goto loc_826513A4;
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8273a590
	ctx.lr = 0x826513F4;
	sub_8273A590(ctx, base);
loc_826513F4:
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82651438
	if (ctx.cr6.eq) goto loc_82651438;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r30,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82651410
	if (!ctx.cr6.gt) goto loc_82651410;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_82651410:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x82641ff8
	ctx.lr = 0x82651420;
	sub_82641FF8(ctx, base);
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x826513a4
	if (ctx.cr0.eq) goto loc_826513A4;
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8273a590
	ctx.lr = 0x82651438;
	sub_8273A590(ctx, base);
loc_82651438:
	// addi r24,r31,112
	ctx.r24.s64 = ctx.r31.s64 + 112;
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r30,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// stw r24,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r24.u32);
	// stw r27,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r27.u32);
	// bne cr6,0x82651460
	if (!ctx.cr6.eq) goto loc_82651460;
	// clrlwi r3,r30,16
	ctx.r3.u64 = ctx.r30.u32 & 0xFFFF;
	// bl 0x8264b5d0
	ctx.lr = 0x8265145C;
	sub_8264B5D0(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
loc_82651460:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// bne cr6,0x82651474
	if (!ctx.cr6.eq) goto loc_82651474;
	// clrlwi r3,r27,16
	ctx.r3.u64 = ctx.r27.u32 & 0xFFFF;
	// bl 0x8264b5d0
	ctx.lr = 0x82651470;
	sub_8264B5D0(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_82651474:
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// lwz r7,128(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826509f0
	ctx.lr = 0x8265148C;
	sub_826509F0(ctx, base);
	// mr. r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// blt 0x8265124c
	if (ctx.cr0.lt) goto loc_8265124C;
	// lwz r11,256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// li r26,0
	ctx.r26.s64 = 0;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826514b4
	if (ctx.cr6.eq) goto loc_826514B4;
	// li r29,4
	ctx.r29.s64 = 4;
	// li r28,4
	ctx.r28.s64 = 4;
loc_826514B4:
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8265153c
	if (!ctx.cr6.eq) goto loc_8265153C;
	// ori r29,r29,3
	ctx.r29.u64 = ctx.r29.u64 | 3;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8265153c
	if (ctx.cr6.eq) goto loc_8265153C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// rlwinm r6,r30,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,2524(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2524);
	ctx.f0.f64 = double(temp.f32);
loc_826514DC:
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8265152c
	if (ctx.cr6.eq) goto loc_8265152C;
	// lwz r9,128(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_826514F4:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x82651510
	if (ctx.cr6.eq) goto loc_82651510;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x82651520
	if (ctx.cr6.eq) goto loc_82651520;
	// rlwinm r29,r29,0,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFC;
	// b 0x82651520
	goto loc_82651520;
loc_82651510:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// beq cr6,0x82651520
	if (ctx.cr6.eq) goto loc_82651520;
	// rlwinm r29,r29,0,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFE;
loc_82651520:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x826514f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826514F4;
loc_8265152C:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// add r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 + ctx.r10.u64;
	// cmplw cr6,r8,r27
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x826514dc
	if (ctx.cr6.lt) goto loc_826514DC;
loc_8265153C:
	// cmpwi cr6,r18,1
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 1, ctx.xer);
	// stw r29,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r29.u32);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bne cr6,0x826516a8
	if (!ctx.cr6.eq) goto loc_826516A8;
	// cmplwi cr6,r21,4
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 4, ctx.xer);
	// bne cr6,0x826515e4
	if (!ctx.cr6.eq) goto loc_826515E4;
	// cmplwi cr6,r20,32
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 32, ctx.xer);
	// bne cr6,0x8265158c
	if (!ctx.cr6.eq) goto loc_8265158C;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x82667588
	ctx.lr = 0x8265156C;
	sub_82667588(ctx, base);
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x82667588
	ctx.lr = 0x82651584;
	sub_82667588(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x82651670
	goto loc_82651670;
loc_8265158C:
	// cmplwi cr6,r20,24
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 24, ctx.xer);
	// bne cr6,0x826515bc
	if (!ctx.cr6.eq) goto loc_826515BC;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82667588
	ctx.lr = 0x8265159C;
	sub_82667588(ctx, base);
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82667588
	ctx.lr = 0x826515B4;
	sub_82667588(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x82651670
	goto loc_82651670;
loc_826515BC:
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82667588
	ctx.lr = 0x826515C4;
	sub_82667588(ctx, base);
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82667588
	ctx.lr = 0x826515DC;
	sub_82667588(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x82651670
	goto loc_82651670;
loc_826515E4:
	// cmplwi cr6,r21,3
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 3, ctx.xer);
	// bne cr6,0x82651644
	if (!ctx.cr6.eq) goto loc_82651644;
	// cmplwi cr6,r20,24
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 24, ctx.xer);
	// bne cr6,0x8265161c
	if (!ctx.cr6.eq) goto loc_8265161C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82667588
	ctx.lr = 0x826515FC;
	sub_82667588(ctx, base);
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82667588
	ctx.lr = 0x82651614;
	sub_82667588(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x82651670
	goto loc_82651670;
loc_8265161C:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82667588
	ctx.lr = 0x82651624;
	sub_82667588(ctx, base);
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82667588
	ctx.lr = 0x8265163C;
	sub_82667588(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x82651670
	goto loc_82651670;
loc_82651644:
	// cmplwi cr6,r21,2
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 2, ctx.xer);
	// bne cr6,0x8265167c
	if (!ctx.cr6.eq) goto loc_8265167C;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82667588
	ctx.lr = 0x82651654;
	sub_82667588(ctx, base);
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82667588
	ctx.lr = 0x8265166C;
	sub_82667588(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
loc_82651670:
	// stw r3,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r3.u32);
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// b 0x826516f4
	goto loc_826516F4;
loc_8265167C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82667588
	ctx.lr = 0x82651684;
	sub_82667588(ctx, base);
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82667588
	ctx.lr = 0x8265169C;
	sub_82667588(ctx, base);
	// stw r3,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r3.u32);
	// stw r26,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r26.u32);
	// b 0x826516f4
	goto loc_826516F4;
loc_826516A8:
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x82667588
	ctx.lr = 0x826516B0;
	sub_82667588(ctx, base);
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x82667588
	ctx.lr = 0x826516C8;
	sub_82667588(ctx, base);
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r3,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r3.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// beq cr6,0x826516ec
	if (ctx.cr6.eq) goto loc_826516EC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8266b6f0
	ctx.lr = 0x826516E8;
	sub_8266B6F0(ctx, base);
	// stw r3,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r3.u32);
loc_826516EC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
loc_826516F4:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// stw r29,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r29.u32);
	// rlwinm r30,r19,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r26,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r26.u32);
	// stw r26,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r26.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,128(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// lfs f0,5864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r10.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f0,116(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 116, temp.u32);
	// stw r10,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r10.u32);
	// stfs f0,120(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// lwz r3,152(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// bl 0x8273a030
	ctx.lr = 0x82651744;
	sub_8273A030(ctx, base);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,0(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lfs f13,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,140(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 140, temp.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stfs f13,144(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 144, temp.u32);
	// lwz r4,128(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// stw r10,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r10.u32);
	// stw r9,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r9.u32);
	// lwz r3,176(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// bl 0x8273a030
	ctx.lr = 0x8265177C;
	sub_8273A030(ctx, base);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,0(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lfs f13,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 164, temp.u32);
	// stfs f13,168(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 168, temp.u32);
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// stw r10,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r10.u32);
	// stw r9,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r9.u32);
	// b 0x82651254
	goto loc_82651254;
}

DEFINE_REX_FUNC(sub_82683EF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82683F00;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,13120
	ctx.r3.s64 = ctx.r11.s64 + 13120;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// bl 0x82641ff8
	ctx.lr = 0x82683F3C;
	sub_82641FF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82683f54
	if (ctx.cr0.eq) goto loc_82683F54;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82683dd8
	ctx.lr = 0x82683F4C;
	sub_82683DD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82683f58
	goto loc_82683F58;
loc_82683F54:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82683F58:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82683f6c
	if (!ctx.cr6.eq) goto loc_82683F6C;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x82683fc0
	goto loc_82683FC0;
loc_82683F6C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82683F94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82683fa4
	if (ctx.cr0.lt) goto loc_82683FA4;
	// stw r31,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r31.u32);
	// b 0x82683fc0
	goto loc_82683FC0;
loc_82683FA4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82683FBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8264cf40
	ctx.lr = 0x82683FC0;
	sub_8264CF40(ctx, base);
loc_82683FC0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826896B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee8
	ctx.lr = 0x826896C0;
	__savegprlr_16(ctx, base);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x826898c4
	if (ctx.cr6.eq) goto loc_826898C4;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x826898c4
	if (ctx.cr6.eq) goto loc_826898C4;
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,14
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 14, ctx.xer);
	// blt cr6,0x826898bc
	if (ctx.cr6.lt) goto loc_826898BC;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// clrlwi r18,r7,16
	ctx.r18.u64 = ctx.r7.u32 & 0xFFFF;
	// addi r19,r11,-4624
	ctx.r19.s64 = ctx.r11.s64 + -4624;
	// addi r21,r10,-4652
	ctx.r21.s64 = ctx.r10.s64 + -4652;
	// addi r20,r9,-4680
	ctx.r20.s64 = ctx.r9.s64 + -4680;
loc_826896F8:
	// cmplw cr6,r4,r18
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r18.u32, ctx.xer);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// blt cr6,0x82689708
	if (ctx.cr6.lt) goto loc_82689708;
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
loc_82689708:
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
	// rotlwi r16,r10,2
	ctx.r16.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lbzu r29,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r29.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// lwzx r23,r8,r20
	ctx.r23.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r20.u32);
	// lwzx r22,r8,r21
	ctx.r22.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r21.u32);
	// lwzx r24,r16,r20
	ctx.r24.u64 = REX_LOAD_U32(ctx.r16.u32 + ctx.r20.u32);
	// lbz r6,1(r3)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbzu r30,2(r3)
	ea = 2 + ctx.r3.u32;
	ctx.r30.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// rotlwi r6,r6,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
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
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
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
	// lbz r29,1(r3)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// rotlwi r28,r29,8
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r29.u32, 8);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// add r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 + ctx.r10.u64;
	// lwzx r28,r16,r21
	ctx.r28.u64 = REX_LOAD_U32(ctx.r16.u32 + ctx.r21.u32);
	// sth r11,0(r5)
	REX_STORE_U16(ctx.r5.u32 + 0, ctx.r11.u16);
	// sthu r10,2(r5)
	ea = 2 + ctx.r5.u32;
	REX_STORE_U16(ea, ctx.r10.u16);
	ctx.r5.u32 = ea;
	// sthu r9,2(r5)
	ea = 2 + ctx.r5.u32;
	REX_STORE_U16(ea, ctx.r9.u16);
	ctx.r5.u32 = ea;
	// sthu r8,2(r5)
	ea = 2 + ctx.r5.u32;
	REX_STORE_U16(ea, ctx.r8.u16);
	ctx.r5.u32 = ea;
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// beq 0x826898b4
	if (ctx.cr0.eq) goto loc_826898B4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_826897BC:
	// lbz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// mullw r11,r29,r22
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r22.s32);
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// mullw r30,r9,r23
	ctx.r30.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r23.s32);
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
	// ble cr6,0x82689800
	if (!ctx.cr6.gt) goto loc_82689800;
	// li r11,32767
	ctx.r11.s64 = 32767;
	// b 0x8268980c
	goto loc_8268980C;
loc_82689800:
	// cmpwi cr6,r11,-32768
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -32768, ctx.xer);
	// bge cr6,0x8268980c
	if (!ctx.cr6.lt) goto loc_8268980C;
	// li r11,-32768
	ctx.r11.s64 = -32768;
loc_8268980C:
	// rlwinm r30,r29,2,26,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0x3C;
	// lwzx r30,r30,r19
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r19.u32);
	// mullw r6,r30,r6
	ctx.r6.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r6.s32);
	// srawi r6,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 8;
	// cmpwi cr6,r6,16
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 16, ctx.xer);
	// bge cr6,0x82689828
	if (!ctx.cr6.lt) goto loc_82689828;
	// li r6,16
	ctx.r6.s64 = 16;
loc_82689828:
	// rlwinm r30,r7,4,0,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// sth r11,0(r5)
	REX_STORE_U16(ctx.r5.u32 + 0, ctx.r11.u16);
	// mullw r10,r10,r28
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r28.s32);
	// extsb r30,r30
	ctx.r30.s64 = ctx.r30.s8;
	// mullw r7,r8,r24
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r24.s32);
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// srawi r10,r9,4
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 4;
	// srawi r9,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 8;
	// mullw r10,r10,r31
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmpwi cr6,r7,32767
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 32767, ctx.xer);
	// ble cr6,0x82689878
	if (!ctx.cr6.gt) goto loc_82689878;
	// li r7,32767
	ctx.r7.s64 = 32767;
	// b 0x82689884
	goto loc_82689884;
loc_82689878:
	// cmpwi cr6,r7,-32768
	ctx.cr6.compare<int32_t>(ctx.r7.s32, -32768, ctx.xer);
	// bge cr6,0x82689884
	if (!ctx.cr6.lt) goto loc_82689884;
	// li r7,-32768
	ctx.r7.s64 = -32768;
loc_82689884:
	// rlwinm r11,r30,2,26,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x3C;
	// lwzx r10,r11,r19
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r19.u32);
	// mullw r11,r10,r31
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32);
	// srawi r31,r11,8
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFF) != 0);
	ctx.r31.s64 = ctx.r11.s32 >> 8;
	// cmpwi cr6,r31,16
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 16, ctx.xer);
	// bge cr6,0x826898a0
	if (!ctx.cr6.lt) goto loc_826898A0;
	// li r31,16
	ctx.r31.s64 = 16;
loc_826898A0:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// sth r7,0(r5)
	REX_STORE_U16(ctx.r5.u32 + 0, ctx.r7.u16);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// bdnz 0x826897bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826897BC;
loc_826898B4:
	// cmplwi cr6,r4,14
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 14, ctx.xer);
	// bge cr6,0x826896f8
	if (!ctx.cr6.lt) goto loc_826896F8;
loc_826898BC:
	// subf r3,r17,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r17.u64;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
loc_826898C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8269ACB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8269ACC0;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lwz r29,44(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8269a118
	ctx.lr = 0x8269AD00;
	sub_8269A118(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269aef4
	if (ctx.cr6.lt) goto loc_8269AEF4;
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8269ad24
	if (!ctx.cr6.eq) goto loc_8269AD24;
	// lis r3,-32688
	ctx.r3.s64 = -2142240768;
	// ori r3,r3,9
	ctx.r3.u64 = ctx.r3.u64 | 9;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
loc_8269AD24:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269aeec
	if (ctx.cr6.eq) goto loc_8269AEEC;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// ld r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8269be98
	ctx.lr = 0x8269AD44;
	sub_8269BE98(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269aef4
	if (ctx.cr6.lt) goto loc_8269AEF4;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r26,1
	ctx.r26.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8269ae50
	if (!ctx.cr6.eq) goto loc_8269AE50;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8269ada0
	if (ctx.cr6.eq) goto loc_8269ADA0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// ld r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8269a798
	ctx.lr = 0x8269AD7C;
	sub_8269A798(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269aef4
	if (ctx.cr6.lt) goto loc_8269AEF4;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8269ada0
	if (ctx.cr6.eq) goto loc_8269ADA0;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8269ADA0:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// ld r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8269a798
	ctx.lr = 0x8269ADB4;
	sub_8269A798(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269aef4
	if (ctx.cr6.lt) goto loc_8269AEF4;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8269ae50
	if (!ctx.cr6.eq) goto loc_8269AE50;
	// std r4,48(r29)
	REX_STORE_U64(ctx.r29.u32 + 48, ctx.r4.u64);
	// stw r26,56(r29)
	REX_STORE_U32(ctx.r29.u32 + 56, ctx.r26.u32);
	// lwz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 76);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269ADE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269aef4
	if (ctx.cr6.lt) goto loc_8269AEF4;
	// lwz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 76);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269AE04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269aef4
	if (ctx.cr6.lt) goto loc_8269AEF4;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// ld r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r11,40(r29)
	REX_STORE_U64(ctx.r29.u32 + 40, ctx.r11.u64);
	// lwz r4,88(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x8269a5f8
	ctx.lr = 0x8269AE2C;
	sub_8269A5F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269aef4
	if (ctx.cr6.lt) goto loc_8269AEF4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// ld r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8269a798
	ctx.lr = 0x8269AE48;
	sub_8269A798(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269aef4
	if (ctx.cr6.lt) goto loc_8269AEF4;
loc_8269AE50:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r7,28(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// ld r8,8(r9)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r9.u32 + 8);
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// subf r6,r10,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r10.u64;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// cmpld cr6,r6,r7
	ctx.cr6.compare<uint64_t>(ctx.r6.u64, ctx.r7.u64, ctx.xer);
	// bge cr6,0x8269ae98
	if (!ctx.cr6.lt) goto loc_8269AE98;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// subf r10,r10,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r10.u64;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_8269AE98:
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r7.u32);
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// subf r7,r10,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r10.u64;
	// ld r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// stw r7,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r7.u32);
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// ld r11,8(r5)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r5.u32 + 8);
	// subf r11,r11,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r11.u64;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// stw r26,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r26.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bne cr6,0x8269aef4
	if (!ctx.cr6.eq) goto loc_8269AEF4;
loc_8269AEEC:
	// lis r3,80
	ctx.r3.s64 = 5242880;
	// ori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 | 1;
loc_8269AEF4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826BCD50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x826BCD58;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,1
	ctx.r29.s64 = 1;
	// li r11,-1
	ctx.r11.s64 = -1;
	// std r30,3600(r3)
	REX_STORE_U64(ctx.r3.u32 + 3600, ctx.r30.u64);
	// std r30,3608(r3)
	REX_STORE_U64(ctx.r3.u32 + 3608, ctx.r30.u64);
	// li r10,1000
	ctx.r10.s64 = 1000;
	// std r30,3624(r3)
	REX_STORE_U64(ctx.r3.u32 + 3624, ctx.r30.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r30,3632(r3)
	REX_STORE_U64(ctx.r3.u32 + 3632, ctx.r30.u64);
	// li r4,114
	ctx.r4.s64 = 114;
	// stw r30,3656(r3)
	REX_STORE_U32(ctx.r3.u32 + 3656, ctx.r30.u32);
	// li r3,14
	ctx.r3.s64 = 14;
	// stw r30,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r30.u32);
	// stw r30,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r30.u32);
	// stw r30,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r30.u32);
	// stw r30,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r30.u32);
	// stw r30,3912(r31)
	REX_STORE_U32(ctx.r31.u32 + 3912, ctx.r30.u32);
	// stw r30,3916(r31)
	REX_STORE_U32(ctx.r31.u32 + 3916, ctx.r30.u32);
	// stw r30,3920(r31)
	REX_STORE_U32(ctx.r31.u32 + 3920, ctx.r30.u32);
	// stw r30,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r30.u32);
	// stw r30,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r30.u32);
	// stw r30,440(r31)
	REX_STORE_U32(ctx.r31.u32 + 440, ctx.r30.u32);
	// stw r30,3908(r31)
	REX_STORE_U32(ctx.r31.u32 + 3908, ctx.r30.u32);
	// stw r30,3972(r31)
	REX_STORE_U32(ctx.r31.u32 + 3972, ctx.r30.u32);
	// stw r30,444(r31)
	REX_STORE_U32(ctx.r31.u32 + 444, ctx.r30.u32);
	// stw r30,3924(r31)
	REX_STORE_U32(ctx.r31.u32 + 3924, ctx.r30.u32);
	// stw r30,15540(r31)
	REX_STORE_U32(ctx.r31.u32 + 15540, ctx.r30.u32);
	// stw r30,15544(r31)
	REX_STORE_U32(ctx.r31.u32 + 15544, ctx.r30.u32);
	// stw r30,3688(r31)
	REX_STORE_U32(ctx.r31.u32 + 3688, ctx.r30.u32);
	// stw r30,3692(r31)
	REX_STORE_U32(ctx.r31.u32 + 3692, ctx.r30.u32);
	// stw r30,3696(r31)
	REX_STORE_U32(ctx.r31.u32 + 3696, ctx.r30.u32);
	// stw r29,3700(r31)
	REX_STORE_U32(ctx.r31.u32 + 3700, ctx.r29.u32);
	// stw r30,3704(r31)
	REX_STORE_U32(ctx.r31.u32 + 3704, ctx.r30.u32);
	// stw r30,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r30.u32);
	// stw r30,15800(r31)
	REX_STORE_U32(ctx.r31.u32 + 15800, ctx.r30.u32);
	// stw r30,1892(r31)
	REX_STORE_U32(ctx.r31.u32 + 1892, ctx.r30.u32);
	// stw r30,1896(r31)
	REX_STORE_U32(ctx.r31.u32 + 1896, ctx.r30.u32);
	// stw r30,1900(r31)
	REX_STORE_U32(ctx.r31.u32 + 1900, ctx.r30.u32);
	// stw r30,1904(r31)
	REX_STORE_U32(ctx.r31.u32 + 1904, ctx.r30.u32);
	// stw r30,1908(r31)
	REX_STORE_U32(ctx.r31.u32 + 1908, ctx.r30.u32);
	// stw r30,1912(r31)
	REX_STORE_U32(ctx.r31.u32 + 1912, ctx.r30.u32);
	// stw r30,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r30.u32);
	// stw r30,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r30.u32);
	// stw r30,15580(r31)
	REX_STORE_U32(ctx.r31.u32 + 15580, ctx.r30.u32);
	// stw r30,15548(r31)
	REX_STORE_U32(ctx.r31.u32 + 15548, ctx.r30.u32);
	// stw r11,3668(r31)
	REX_STORE_U32(ctx.r31.u32 + 3668, ctx.r11.u32);
	// std r30,2952(r31)
	REX_STORE_U64(ctx.r31.u32 + 2952, ctx.r30.u64);
	// stw r30,2960(r31)
	REX_STORE_U32(ctx.r31.u32 + 2960, ctx.r30.u32);
	// stw r30,2964(r31)
	REX_STORE_U32(ctx.r31.u32 + 2964, ctx.r30.u32);
	// stw r30,2968(r31)
	REX_STORE_U32(ctx.r31.u32 + 2968, ctx.r30.u32);
	// stw r30,2972(r31)
	REX_STORE_U32(ctx.r31.u32 + 2972, ctx.r30.u32);
	// stw r30,1792(r31)
	REX_STORE_U32(ctx.r31.u32 + 1792, ctx.r30.u32);
	// stw r30,15552(r31)
	REX_STORE_U32(ctx.r31.u32 + 15552, ctx.r30.u32);
	// stw r30,15556(r31)
	REX_STORE_U32(ctx.r31.u32 + 15556, ctx.r30.u32);
	// stw r30,15560(r31)
	REX_STORE_U32(ctx.r31.u32 + 15560, ctx.r30.u32);
	// stw r10,15564(r31)
	REX_STORE_U32(ctx.r31.u32 + 15564, ctx.r10.u32);
	// stw r29,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r29.u32);
	// stw r30,3368(r31)
	REX_STORE_U32(ctx.r31.u32 + 3368, ctx.r30.u32);
	// stw r30,3372(r31)
	REX_STORE_U32(ctx.r31.u32 + 3372, ctx.r30.u32);
	// stw r30,22468(r31)
	REX_STORE_U32(ctx.r31.u32 + 22468, ctx.r30.u32);
	// bl 0x825be980
	ctx.lr = 0x826BCE54;
	sub_825BE980(ctx, base);
	// stw r3,22468(r31)
	REX_STORE_U32(ctx.r31.u32 + 22468, ctx.r3.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826bce70
	if (ctx.cr6.eq) goto loc_826BCE70;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x826bce70
	if (ctx.cr6.eq) goto loc_826BCE70;
	// stw r29,22468(r31)
	REX_STORE_U32(ctx.r31.u32 + 22468, ctx.r29.u32);
	// b 0x826bce74
	goto loc_826BCE74;
loc_826BCE70:
	// stw r30,22468(r31)
	REX_STORE_U32(ctx.r31.u32 + 22468, ctx.r30.u32);
loc_826BCE74:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r30,15536(r31)
	REX_STORE_U32(ctx.r31.u32 + 15536, ctx.r30.u32);
	// stw r30,3376(r31)
	REX_STORE_U32(ctx.r31.u32 + 3376, ctx.r30.u32);
	// stw r11,22484(r31)
	REX_STORE_U32(ctx.r31.u32 + 22484, ctx.r11.u32);
	// stw r30,22256(r31)
	REX_STORE_U32(ctx.r31.u32 + 22256, ctx.r30.u32);
	// stw r30,22260(r31)
	REX_STORE_U32(ctx.r31.u32 + 22260, ctx.r30.u32);
	// stw r30,22264(r31)
	REX_STORE_U32(ctx.r31.u32 + 22264, ctx.r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C6170) {
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
	// bne cr6,0x826c61a4
	if (!ctx.cr6.eq) goto loc_826C61A4;
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_826C61A4:
	// lwz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826c61cc
	if (!ctx.cr6.eq) goto loc_826C61CC;
	// bl 0x826c5b88
	ctx.lr = 0x826C61B8;
	sub_826C5B88(ctx, base);
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
loc_826C61CC:
	// bl 0x826c57e0
	ctx.lr = 0x826C61D0;
	sub_826C57E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826bedc8
	ctx.lr = 0x826C61D8;
	sub_826BEDC8(ctx, base);
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

DEFINE_REX_FUNC(sub_826C8968) {
	REX_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826c897c
	if (!ctx.cr6.eq) goto loc_826C897C;
	// li r11,8
	ctx.r11.s64 = 8;
loc_826C897C:
	// subfic r10,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r10.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// ld r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// clrldi r8,r10,32
	ctx.r8.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// srd r7,r9,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r8.u8 & 0x7F));
	// rotlwi r3,r7,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826CC838) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x826CC840;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af14
	ctx.lr = 0x826CC848;
	__savefpr_23(ctx, base);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = ctx.f1.f64;
	// fmr f23,f2
	ctx.f23.f64 = ctx.f2.f64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// fmr f27,f3
	ctx.f27.f64 = ctx.f3.f64;
	// fmr f26,f4
	ctx.f26.f64 = ctx.f4.f64;
	// fmr f24,f5
	ctx.f24.f64 = ctx.f5.f64;
	// bne cr6,0x826cc880
	if (!ctx.cr6.eq) goto loc_826CC880;
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af60
	ctx.lr = 0x826CC87C;
	__restfpr_23(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_826CC880:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// lwz r8,15360(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lwz r23,15376(r31)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r31.u32 + 15376);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r22,15380(r31)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r31.u32 + 15380);
	// srawi r20,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r20.s64 = ctx.r10.s32 >> 1;
	// frsp f13,f24
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f24.f64));
	// lfs f0,5864(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f0.f64 = double(temp.f32);
	// srawi r26,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r26.s64 = ctx.r8.s32 >> 1;
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// srawi r25,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r25.s64 = ctx.r10.s32 >> 5;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// srawi r24,r10,6
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3F) != 0);
	ctx.r24.s64 = ctx.r10.s32 >> 6;
	// lfd f28,24136(r6)
	ctx.f28.u64 = REX_LOAD_U64(ctx.r6.u32 + 24136);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stw r23,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r23.u32);
	// stw r22,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r22.u32);
	// fcmpu cr6,f25,f28
	ctx.cr6.compare(ctx.f25.f64, ctx.f28.f64);
	// stw r26,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r26.u32);
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r25,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r25.u32);
	// stw r24,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r24.u32);
	// beq cr6,0x826cdb1c
	if (ctx.cr6.eq) goto loc_826CDB1C;
	// fcmpu cr6,f27,f28
	ctx.cr6.compare(ctx.f27.f64, ctx.f28.f64);
	// beq cr6,0x826cdb1c
	if (ctx.cr6.eq) goto loc_826CDB1C;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfd f29,24232(r10)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r10.u32 + 24232);
	// fsub f11,f13,f23
	ctx.f11.f64 = ctx.f13.f64 - ctx.f23.f64;
	// fdiv f12,f29,f25
	ctx.f12.f64 = ctx.f29.f64 / ctx.f25.f64;
	// fdiv f30,f11,f25
	ctx.f30.f64 = ctx.f11.f64 / ctx.f25.f64;
	// fmul f0,f12,f23
	ctx.f0.f64 = ctx.f12.f64 * ctx.f23.f64;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x826cc934
	if (!ctx.cr6.gt) goto loc_826CC934;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
	// fmr f30,f13
	ctx.f30.f64 = ctx.f13.f64;
loc_826CC934:
	// fsel f1,f0,f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64 >= 0.0 ? ctx.f0.f64 : ctx.f28.f64;
	// bl 0x827389a8
	ctx.lr = 0x826CC93C;
	sub_827389A8(ctx, base);
	// lwz r11,15360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bge cr6,0x826cc95c
	if (!ctx.cr6.lt) goto loc_826CC95C;
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
loc_826CC95C:
	// bl 0x827389e8
	ctx.lr = 0x826CC960;
	sub_827389E8(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,15360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// lfd f0,13096(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 13096);
	// fadd f0,f30,f0
	ctx.f0.f64 = ctx.f30.f64 + ctx.f0.f64;
	// lwz r27,84(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x826cc998
	if (!ctx.cr6.lt) goto loc_826CC998;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_826CC998:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x827389e8
	ctx.lr = 0x826CC9A0;
	sub_827389E8(ctx, base);
	// lwz r11,15360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f1,f0
	ctx.f1.f64 = double(ctx.f0.s64);
	// fcmpu cr6,f1,f30
	ctx.cr6.compare(ctx.f1.f64, ctx.f30.f64);
	// blt cr6,0x826cc9c4
	if (ctx.cr6.lt) goto loc_826CC9C4;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
loc_826CC9C4:
	// bl 0x827389e8
	ctx.lr = 0x826CC9C8;
	sub_827389E8(ctx, base);
	// fsel f1,f1,f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : ctx.f28.f64;
	// bl 0x827389a8
	ctx.lr = 0x826CC9D0;
	sub_827389A8(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r29,84(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fsel f1,f31,f31,f28
	ctx.f1.f64 = ctx.f31.f64 >= 0.0 ? ctx.f31.f64 : ctx.f28.f64;
	// bl 0x827389a8
	ctx.lr = 0x826CC9E4;
	sub_827389A8(ctx, base);
	// fctiwz f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r11,15356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15356);
	// fdiv f13,f29,f27
	ctx.f13.f64 = ctx.f29.f64 / ctx.f27.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// lfd f30,6304(r10)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r10.u32 + 6304);
	// fmul f0,f13,f26
	ctx.f0.f64 = ctx.f13.f64 * ctx.f26.f64;
	// lwz r28,84(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fsub f9,f10,f26
	ctx.f9.f64 = ctx.f10.f64 - ctx.f26.f64;
	// fdiv f8,f9,f27
	ctx.f8.f64 = ctx.f9.f64 / ctx.f27.f64;
	// fadd f31,f8,f30
	ctx.f31.f64 = ctx.f8.f64 + ctx.f30.f64;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x826cca34
	if (!ctx.cr6.gt) goto loc_826CCA34;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// fmr f31,f13
	ctx.f31.f64 = ctx.f13.f64;
loc_826CCA34:
	// fsel f1,f0,f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64 >= 0.0 ? ctx.f0.f64 : ctx.f28.f64;
	// bl 0x827389a8
	ctx.lr = 0x826CCA3C;
	sub_827389A8(ctx, base);
	// lwz r11,15364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15364);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bge cr6,0x826cca5c
	if (!ctx.cr6.lt) goto loc_826CCA5C;
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
loc_826CCA5C:
	// bl 0x827389e8
	ctx.lr = 0x826CCA60;
	sub_827389E8(ctx, base);
	// lwz r11,15364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15364);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// lwz r30,108(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f13
	ctx.f0.f64 = double(ctx.f13.s64);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x826cca8c
	if (ctx.cr6.lt) goto loc_826CCA8C;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
loc_826CCA8C:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x827389e8
	ctx.lr = 0x826CCA94;
	sub_827389E8(ctx, base);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// fsel f1,f1,f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : ctx.f28.f64;
	// addi r10,r27,1
	ctx.r10.s64 = ctx.r27.s64 + 1;
	// rlwinm r18,r11,0,0,30
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// rlwinm r30,r10,0,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// rlwinm r29,r29,0,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r18,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r18.u32);
	// rlwinm r14,r28,0,0,30
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r30,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r30.u32);
	// stw r29,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// stw r14,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r14.u32);
	// bl 0x827389a8
	ctx.lr = 0x826CCAC4;
	sub_827389A8(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r28,r9,0,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r28,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r28.u32);
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// bge cr6,0x826ccae8
	if (!ctx.cr6.lt) goto loc_826CCAE8;
	// li r28,2
	ctx.r28.s64 = 2;
	// stw r28,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r28.u32);
loc_826CCAE8:
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lwz r3,15388(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15388);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r6,15392(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 15392);
	// srawi r9,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r30.s32 >> 1;
	// lwz r16,15384(r31)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r31.u32 + 15384);
	// srawi r7,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r29.s32 >> 1;
	// fcmpu cr6,f24,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f24.f64, ctx.f30.f64);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r9,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// lfd f0,13080(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 13080);
	// stw r7,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// lfd f13,13088(r10)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r10.u32 + 13088);
	// fmul f10,f23,f0
	ctx.f10.f64 = ctx.f23.f64 * ctx.f0.f64;
	// fmul f9,f25,f13
	ctx.f9.f64 = ctx.f25.f64 * ctx.f13.f64;
	// srawi r5,r14,1
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r14.s32 >> 1;
	// fmul f11,f26,f0
	ctx.f11.f64 = ctx.f26.f64 * ctx.f0.f64;
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// fmul f8,f27,f13
	ctx.f8.f64 = ctx.f27.f64 * ctx.f13.f64;
	// lfd f12,24264(r8)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r8.u32 + 24264);
	// stw r6,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// stw r5,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r5.u32);
	// fctiwz f6,f10
	ctx.f6.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x80000000U) : (ctx.f10.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f6,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f6.u64);
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f5,f9
	ctx.f5.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x80000000U) : (ctx.f9.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f5,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f5.u64);
	// lwz r29,108(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f7,f11
	ctx.f7.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f7,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f4,f8
	ctx.f4.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mullw r9,r11,r18
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r18.s32);
	// fmul f3,f9,f12
	ctx.f3.f64 = ctx.f9.f64 * ctx.f12.f64;
	// mullw r7,r29,r30
	ctx.r7.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r30.s32);
	// fctiwz f2,f3
	ctx.f2.s64 = std::isnan(ctx.f3.f64) ? int64_t(0x80000000U) : (ctx.f3.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f2.u64);
	// subf r8,r4,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r4.u64;
	// subf r4,r10,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r10.u64;
	// rlwinm r11,r8,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// rlwinm r10,r4,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r15,r11,r8
	ctx.r15.u64 = ctx.r11.u64 & ctx.r8.u64;
	// and r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 & ctx.r4.u64;
	// stw r15,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r15.u32);
	// stw r9,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// ble cr6,0x826ccbb8
	if (!ctx.cr6.gt) goto loc_826CCBB8;
	// fmr f24,f30
	ctx.f24.f64 = ctx.f30.f64;
	// b 0x826ccbc4
	goto loc_826CCBC4;
loc_826CCBB8:
	// fcmpu cr6,f24,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f24.f64, ctx.f28.f64);
	// bge cr6,0x826ccbc4
	if (!ctx.cr6.lt) goto loc_826CCBC4;
	// fmr f24,f28
	ctx.f24.f64 = ctx.f28.f64;
loc_826CCBC4:
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r30,128
	ctx.r30.s64 = 128;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lfd f0,13072(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 13072);
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// fmul f0,f24,f0
	ctx.f0.f64 = ctx.f24.f64 * ctx.f0.f64;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v1,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// ble cr6,0x826ccc94
	if (!ctx.cr6.gt) goto loc_826CCC94;
loc_826CCBF8:
	// lwz r10,15360(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826ccc20
	if (!ctx.cr6.gt) goto loc_826CCC20;
	// addi r10,r16,-1
	ctx.r10.s64 = ctx.r16.s64 + -1;
loc_826CCC0C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbu r4,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r4.u8);
	ctx.r10.u32 = ea;
	// lwz r8,15360(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x826ccc0c
	if (ctx.cr6.lt) goto loc_826CCC0C;
loc_826CCC20:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x826ccc44
	if (!ctx.cr6.gt) goto loc_826CCC44;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// mtctr r26
	ctx.ctr.u64 = ctx.r26.u64;
	// subf r10,r6,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r6.u64;
loc_826CCC34:
	// stbx r30,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r30.u8);
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x826ccc34
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CCC34;
loc_826CCC44:
	// lwz r11,15360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// add r3,r3,r26
	ctx.r3.u64 = ctx.r3.u64 + ctx.r26.u64;
	// add r6,r6,r26
	ctx.r6.u64 = ctx.r6.u64 + ctx.r26.u64;
	// add r8,r11,r16
	ctx.r8.u64 = ctx.r11.u64 + ctx.r16.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826ccc7c
	if (!ctx.cr6.gt) goto loc_826CCC7C;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
loc_826CCC68:
	// stbu r4,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r4.u8);
	ctx.r9.u32 = ea;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r11,15360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826ccc68
	if (ctx.cr6.lt) goto loc_826CCC68;
loc_826CCC7C:
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// add r16,r11,r8
	ctx.r16.u64 = ctx.r11.u64 + ctx.r8.u64;
	// cmpw cr6,r9,r18
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r18.s32, ctx.xer);
	// blt cr6,0x826ccbf8
	if (ctx.cr6.lt) goto loc_826CCBF8;
	// stw r6,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
loc_826CCC94:
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// srawi r8,r15,11
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r15.s32 >> 11;
	// lwz r9,15372(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 15372);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mullw r8,r8,r10
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// ble cr6,0x826ccccc
	if (!ctx.cr6.gt) goto loc_826CCCCC;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
loc_826CCCBC:
	// dcbt r11,r9
	// dcbt r11,r10
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x826cccbc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CCCBC;
loc_826CCCCC:
	// srawi r11,r15,12
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0xFFF) != 0);
	ctx.r11.s64 = ctx.r15.s32 >> 12;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// mullw r11,r11,r20
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r20.s32);
	// ble cr6,0x826cccf0
	if (!ctx.cr6.gt) goto loc_826CCCF0;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_826CCCE0:
	// dcbt r11,r23
	// dcbt r11,r22
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x826ccce0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CCCE0;
loc_826CCCF0:
	// addi r4,r28,-2
	ctx.r4.s64 = ctx.r28.s64 + -2;
	// cmpw cr6,r18,r4
	ctx.cr6.compare<int32_t>(ctx.r18.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x826cd7a8
	if (!ctx.cr6.lt) goto loc_826CD7A8;
	// lwz r11,140(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r10,144(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r8,120(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stw r7,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r7.u32);
	// subf r6,r9,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r9.u64;
	// addi r17,r11,-13520
	ctx.r17.s64 = ctx.r11.s64 + -13520;
	// stw r6,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r6.u32);
	// lfs f13,24248(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24248);
	ctx.f13.f64 = double(temp.f32);
	// stw r17,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r17.u32);
loc_826CCD30:
	// clrlwi r26,r15,21
	ctx.r26.u64 = ctx.r15.u32 & 0x7FF;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// srawi r8,r15,11
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r15.s32 >> 11;
	// lwz r11,15372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15372);
	// extsw r7,r26
	ctx.r7.s64 = ctx.r26.s32;
	// lwz r30,136(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// std r7,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r7.u64);
	// lfd f0,208(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 208);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,176(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// fmuls f0,f11,f13
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// ble cr6,0x826ccd88
	if (!ctx.cr6.gt) goto loc_826CCD88;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826CCD7C:
	// dcbt r11,r28
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x826ccd7c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CCD7C;
loc_826CCD88:
	// lwz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826ccdb4
	if (!ctx.cr6.gt) goto loc_826CCDB4;
	// addi r11,r16,-1
	ctx.r11.s64 = ctx.r16.s64 + -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826ccdb0
	if (ctx.cr6.eq) goto loc_826CCDB0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CCDA8:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x826ccda8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CCDA8;
loc_826CCDB0:
	// add r3,r16,r9
	ctx.r3.u64 = ctx.r16.u64 + ctx.r9.u64;
loc_826CCDB4:
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r17,-8
	ctx.r11.s64 = ctx.r17.s64 + -8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826CCDC0:
	// stwu r26,16(r11)
	ea = 16 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r26.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826ccdc0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CCDC0;
	// subfic r27,r26,2048
	ctx.xer.ca = ctx.r26.u32 <= 2048;
	ctx.r27.u64 = static_cast<uint64_t>(2048) - ctx.r26.u64;
	// stfs f0,204(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// srawi. r11,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r24,r10,r6
	ctx.r24.u64 = ctx.r6.u64 - ctx.r10.u64;
	// ble 0x826ccf7c
	if (!ctx.cr0.gt) goto loc_826CCF7C;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lvx128 v2,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826CCDEC:
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r11,r17,256
	ctx.r11.s64 = ctx.r17.s64 + 256;
	// addi r10,r17,-4
	ctx.r10.s64 = ctx.r17.s64 + -4;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CCE00:
	// srawi r9,r30,11
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r30.s32 >> 11;
	// lwz r7,20(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// add r8,r30,r29
	ctx.r8.u64 = ctx.r30.u64 + ctx.r29.u64;
	// add r9,r9,r28
	ctx.r9.u64 = ctx.r9.u64 + ctx.r28.u64;
	// srawi r5,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 11;
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// clrlwi r4,r30,21
	ctx.r4.u64 = ctx.r30.u32 & 0x7FF;
	// clrlwi r30,r8,21
	ctx.r30.u64 = ctx.r8.u32 & 0x7FF;
	// lbz r23,1(r9)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// subf r22,r4,r27
	ctx.r22.u64 = ctx.r27.u64 - ctx.r4.u64;
	// lbz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// add r9,r5,r28
	ctx.r9.u64 = ctx.r5.u64 + ctx.r28.u64;
	// lbz r21,0(r7)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + ctx.r29.u64;
	// lbz r7,1(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// subf r19,r30,r27
	ctx.r19.u64 = ctx.r27.u64 - ctx.r30.u64;
	// stw r4,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// srawi r5,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 11;
	// subf r7,r21,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r21.u64;
	// stw r23,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r23.u32);
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// clrlwi r15,r8,21
	ctx.r15.u64 = ctx.r8.u32 & 0x7FF;
	// subf r7,r23,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r23.u64;
	// stw r21,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r21.u32);
	// stw r4,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r4.u32);
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + ctx.r29.u64;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r22,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r22.u32);
	// srawi r4,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 11;
	// stw r7,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// subf r23,r15,r27
	ctx.r23.u64 = ctx.r27.u64 - ctx.r15.u64;
	// lbz r22,1(r9)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// clrlwi r21,r8,21
	ctx.r21.u64 = ctx.r8.u32 & 0x7FF;
	// lbz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lwz r7,20(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lbz r14,0(r7)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// add r9,r5,r28
	ctx.r9.u64 = ctx.r5.u64 + ctx.r28.u64;
	// lbz r7,1(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// subf r7,r14,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r14.u64;
	// subf r7,r22,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r22.u64;
	// stw r22,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r22.u32);
	// stw r6,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// subf r22,r21,r27
	ctx.r22.u64 = ctx.r27.u64 - ctx.r21.u64;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r14,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r14.u32);
	// stw r30,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r30.u32);
	// stw r7,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r7.u32);
	// stw r30,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r30.u32);
	// stw r19,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r19.u32);
	// lbz r30,1(r9)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r6,r5,r28
	ctx.r6.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r28.u32);
	// lwz r7,20(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lbz r5,0(r7)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// add r9,r4,r28
	ctx.r9.u64 = ctx.r4.u64 + ctx.r28.u64;
	// lbz r7,1(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// subf r7,r5,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r5.u64;
	// subf r7,r30,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r30.u64;
	// stw r6,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// stw r5,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r5.u32);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r30,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r30.u32);
	// stw r15,40(r10)
	REX_STORE_U32(ctx.r10.u32 + 40, ctx.r15.u32);
	// stw r7,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r7.u32);
	// stw r15,48(r10)
	REX_STORE_U32(ctx.r10.u32 + 48, ctx.r15.u32);
	// stw r23,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r23.u32);
	// lbzx r7,r4,r28
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r28.u32);
	// lbz r5,1(r9)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lwz r6,20(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lbz r4,0(r9)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r9,1(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// subf r6,r4,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r4.u64;
	// subf r9,r5,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r5.u64;
	// stw r4,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r4.u32);
	// stw r5,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r5.u32);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// stw r7,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r7.u32);
	// stw r22,52(r10)
	REX_STORE_U32(ctx.r10.u32 + 52, ctx.r22.u32);
	// stwu r9,64(r11)
	ea = 64 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// stw r21,56(r10)
	REX_STORE_U32(ctx.r10.u32 + 56, ctx.r21.u32);
	// add r30,r8,r29
	ctx.r30.u64 = ctx.r8.u64 + ctx.r29.u64;
	// stwu r21,64(r10)
	ea = 64 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r21.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x826cce00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CCE00;
	// mr r5,r17
	ctx.r5.u64 = ctx.r17.u64;
	// addi r4,r17,256
	ctx.r4.s64 = ctx.r17.s64 + 256;
	// bl 0x826caa78
	ctx.lr = 0x826CCF60;
	sub_826CAA78(ctx, base);
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bne 0x826ccdec
	if (!ctx.cr0.eq) goto loc_826CCDEC;
	// lwz r14,164(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r6,156(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r15,116(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
loc_826CCF7C:
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// li r22,128
	ctx.r22.s64 = 128;
	// lwz r27,100(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// lwz r7,168(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// lwz r21,140(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// ble cr6,0x826cd018
	if (!ctx.cr6.gt) goto loc_826CD018;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_826CCF9C:
	// srawi r11,r30,11
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FF) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 11;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// clrlwi r25,r30,21
	ctx.r25.u64 = ctx.r30.u32 & 0x7FF;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r30,r30,r29
	ctx.r30.u64 = ctx.r30.u64 + ctx.r29.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r24,1(r11)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// mullw r9,r24,r25
	ctx.r9.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r25.s32);
	// lbz r10,1(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// mullw r8,r8,r26
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r26.s32);
	// subf r10,r24,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r24.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mullw r10,r10,r25
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r25.s32);
	// mullw r10,r10,r26
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r26.s32);
	// srawi r10,r10,11
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 11;
	// subfic r25,r25,2048
	ctx.xer.ca = ctx.r25.u32 <= 2048;
	ctx.r25.u64 = static_cast<uint64_t>(2048) - ctx.r25.u64;
	// subf r25,r26,r25
	ctx.r25.u64 = ctx.r25.u64 - ctx.r26.u64;
	// mullw r11,r25,r11
	ctx.r11.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r11.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r9,r11,r8
	ctx.r9.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// srawi r8,r9,11
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 11;
	// mullw r11,r8,r11
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// rlwinm r10,r11,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF;
	// stb r10,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bdnz 0x826ccf9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CCF9C;
loc_826CD018:
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// cmpw cr6,r11,r14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r14.s32, ctx.xer);
	// bge cr6,0x826cd050
	if (!ctx.cr6.lt) goto loc_826CD050;
	// subf r11,r11,r14
	ctx.r11.u64 = ctx.r14.u64 - ctx.r11.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826CD02C:
	// srawi r10,r30,11
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r30.s32 >> 11;
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// add r30,r30,r29
	ctx.r30.u64 = ctx.r30.u64 + ctx.r29.u64;
	// lbzx r9,r10,r28
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r28.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// rlwinm r11,r8,24,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF;
	// stb r11,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bdnz 0x826cd02c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD02C;
loc_826CD050:
	// lwz r10,15360(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// cmpw cr6,r14,r10
	ctx.cr6.compare<int32_t>(ctx.r14.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x826cd07c
	if (!ctx.cr6.lt) goto loc_826CD07C;
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
loc_826CD064:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// lwz r8,15360(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x826cd064
	if (ctx.cr6.lt) goto loc_826CD064;
loc_826CD07C:
	// srawi r11,r15,12
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0xFFF) != 0);
	ctx.r11.s64 = ctx.r15.s32 >> 12;
	// lwz r30,136(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// srawi r10,r15,1
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r15.s32 >> 1;
	// lwz r25,88(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mullw r19,r11,r20
	ctx.r19.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r20.s32);
	// lwz r24,92(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// clrlwi r23,r10,21
	ctx.r23.u64 = ctx.r10.u32 & 0x7FF;
	// add r11,r19,r20
	ctx.r11.u64 = ctx.r19.u64 + ctx.r20.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x826cd0b8
	if (!ctx.cr6.gt) goto loc_826CD0B8;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_826CD0A8:
	// dcbt r11,r4
	// dcbt r11,r27
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x826cd0a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD0A8;
loc_826CD0B8:
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// ble cr6,0x826cd0d8
	if (!ctx.cr6.gt) goto loc_826CD0D8;
	// mtctr r21
	ctx.ctr.u64 = ctx.r21.u64;
loc_826CD0C4:
	// stb r22,0(r25)
	REX_STORE_U8(ctx.r25.u32 + 0, ctx.r22.u8);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stb r22,0(r24)
	REX_STORE_U8(ctx.r24.u32 + 0, ctx.r22.u8);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// bdnz 0x826cd0c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD0C4;
loc_826CD0D8:
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r17,-8
	ctx.r11.s64 = ctx.r17.s64 + -8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826CD0E4:
	// stwu r23,16(r11)
	ea = 16 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r23.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826cd0e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD0E4;
	// lwz r10,180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// subfic r26,r23,2048
	ctx.xer.ca = ctx.r23.u32 <= 2048;
	ctx.r26.u64 = static_cast<uint64_t>(2048) - ctx.r23.u64;
	// srawi. r11,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r21,r9,r10
	ctx.r21.u64 = ctx.r10.u64 - ctx.r9.u64;
	// ble 0x826cd2b4
	if (!ctx.cr0.gt) goto loc_826CD2B4;
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r22,r11
	ctx.r22.u64 = ctx.r11.u64;
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// add r28,r19,r10
	ctx.r28.u64 = ctx.r19.u64 + ctx.r10.u64;
	// add r27,r19,r9
	ctx.r27.u64 = ctx.r19.u64 + ctx.r9.u64;
loc_826CD118:
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r11,r17,256
	ctx.r11.s64 = ctx.r17.s64 + 256;
	// addi r10,r17,-12
	ctx.r10.s64 = ctx.r17.s64 + -12;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CD12C:
	// srawi r7,r30,12
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xFFF) != 0);
	ctx.r7.s64 = ctx.r30.s32 >> 12;
	// lwz r6,108(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// srawi r8,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r30.s32 >> 1;
	// add r9,r28,r7
	ctx.r9.u64 = ctx.r28.u64 + ctx.r7.u64;
	// clrlwi r5,r8,21
	ctx.r5.u64 = ctx.r8.u32 & 0x7FF;
	// add r8,r30,r6
	ctx.r8.u64 = ctx.r30.u64 + ctx.r6.u64;
	// lbzx r4,r28,r7
	ctx.r4.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r7.u32);
	// subf r3,r5,r26
	ctx.r3.u64 = ctx.r26.u64 - ctx.r5.u64;
	// lbzx r14,r9,r20
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r20.u32);
	// lbz r30,1(r9)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// add r9,r27,r7
	ctx.r9.u64 = ctx.r27.u64 + ctx.r7.u64;
	// stw r5,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r5.u32);
	// srawi r7,r8,12
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 12;
	// stw r3,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r3.u32);
	// srawi r5,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 1;
	// stw r4,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// stw r14,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r14.u32);
	// clrlwi r4,r5,21
	ctx.r4.u64 = ctx.r5.u32 & 0x7FF;
	// stw r30,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r30.u32);
	// lbz r30,0(r9)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// subf r5,r4,r26
	ctx.r5.u64 = ctx.r26.u64 - ctx.r4.u64;
	// lbz r14,1(r9)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r3,r9,r20
	ctx.r3.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r20.u32);
	// add r9,r28,r7
	ctx.r9.u64 = ctx.r28.u64 + ctx.r7.u64;
	// stw r3,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r3.u32);
	// stw r30,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r30.u32);
	// stw r14,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r14.u32);
	// lbz r30,1(r9)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r14,r28,r7
	ctx.r14.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r7.u32);
	// lbzx r3,r9,r20
	ctx.r3.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r20.u32);
	// add r9,r27,r7
	ctx.r9.u64 = ctx.r27.u64 + ctx.r7.u64;
	// stw r4,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r4.u32);
	// srawi r7,r8,12
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 12;
	// srawi r4,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 1;
	// stw r3,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r3.u32);
	// stw r5,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r5.u32);
	// clrlwi r3,r4,21
	ctx.r3.u64 = ctx.r4.u32 & 0x7FF;
	// stw r30,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r30.u32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// stw r14,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r14.u32);
	// subf r5,r3,r26
	ctx.r5.u64 = ctx.r26.u64 - ctx.r3.u64;
	// lbz r4,1(r9)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r30,r9,r20
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r20.u32);
	// lbz r14,0(r9)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// add r9,r28,r7
	ctx.r9.u64 = ctx.r28.u64 + ctx.r7.u64;
	// stw r4,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r4.u32);
	// stw r30,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r30.u32);
	// stw r14,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r14.u32);
	// lbzx r14,r9,r20
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r20.u32);
	// lbzx r4,r28,r7
	ctx.r4.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r7.u32);
	// lbz r30,1(r9)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// add r9,r27,r7
	ctx.r9.u64 = ctx.r27.u64 + ctx.r7.u64;
	// stw r3,48(r10)
	REX_STORE_U32(ctx.r10.u32 + 48, ctx.r3.u32);
	// srawi r7,r8,12
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 12;
	// stw r5,44(r10)
	REX_STORE_U32(ctx.r10.u32 + 44, ctx.r5.u32);
	// srawi r3,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r8.s32 >> 1;
	// stw r4,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r4.u32);
	// stw r30,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r30.u32);
	// clrlwi r5,r3,21
	ctx.r5.u64 = ctx.r3.u32 & 0x7FF;
	// stw r14,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r14.u32);
	// lbz r4,1(r9)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// subf r3,r5,r26
	ctx.r3.u64 = ctx.r26.u64 - ctx.r5.u64;
	// lbzx r30,r9,r20
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r20.u32);
	// lbz r14,0(r9)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// add r9,r28,r7
	ctx.r9.u64 = ctx.r28.u64 + ctx.r7.u64;
	// stw r4,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r4.u32);
	// stw r30,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r30.u32);
	// stw r14,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r14.u32);
	// lbzx r30,r9,r20
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r20.u32);
	// lbzx r14,r28,r7
	ctx.r14.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r7.u32);
	// lbz r4,1(r9)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// add r9,r27,r7
	ctx.r9.u64 = ctx.r27.u64 + ctx.r7.u64;
	// stw r3,60(r10)
	REX_STORE_U32(ctx.r10.u32 + 60, ctx.r3.u32);
	// stwu r5,64(r10)
	ea = 64 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r5.u32);
	ctx.r10.u32 = ea;
	// stw r4,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r4.u32);
	// stw r30,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r30.u32);
	// stw r14,104(r11)
	REX_STORE_U32(ctx.r11.u32 + 104, ctx.r14.u32);
	// lbzx r3,r27,r7
	ctx.r3.u64 = REX_LOAD_U8(ctx.r27.u32 + ctx.r7.u32);
	// lbz r7,1(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r5,r9,r20
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r20.u32);
	// stw r3,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r3.u32);
	// add r30,r8,r6
	ctx.r30.u64 = ctx.r8.u64 + ctx.r6.u64;
	// stw r7,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
	// stwu r5,128(r11)
	ea = 128 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r5.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826cd12c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD12C;
	// mr r6,r17
	ctx.r6.u64 = ctx.r17.u64;
	// addi r5,r17,256
	ctx.r5.s64 = ctx.r17.s64 + 256;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x826cb138
	ctx.lr = 0x826CD298;
	sub_826CB138(ctx, base);
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// addi r25,r25,16
	ctx.r25.s64 = ctx.r25.s64 + 16;
	// addi r24,r24,16
	ctx.r24.s64 = ctx.r24.s64 + 16;
	// bne 0x826cd118
	if (!ctx.cr0.eq) goto loc_826CD118;
	// lwz r6,156(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r14,164(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
loc_826CD2B4:
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// ble cr6,0x826cd374
	if (!ctx.cr6.gt) goto loc_826CD374;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mtctr r21
	ctx.ctr.u64 = ctx.r21.u64;
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// add r8,r19,r11
	ctx.r8.u64 = ctx.r19.u64 + ctx.r11.u64;
	// add r7,r19,r10
	ctx.r7.u64 = ctx.r19.u64 + ctx.r10.u64;
loc_826CD2D0:
	// srawi r10,r30,12
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xFFF) != 0);
	ctx.r10.s64 = ctx.r30.s32 >> 12;
	// lwz r9,108(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// srawi r4,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r30.s32 >> 1;
	// add r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// clrlwi r3,r4,21
	ctx.r3.u64 = ctx.r4.u32 & 0x7FF;
	// add r30,r30,r9
	ctx.r30.u64 = ctx.r30.u64 + ctx.r9.u64;
	// subfic r9,r3,2048
	ctx.xer.ca = ctx.r3.u32 <= 2048;
	ctx.r9.u64 = static_cast<uint64_t>(2048) - ctx.r3.u64;
	// lbzx r4,r8,r10
	ctx.r4.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// lbzx r28,r11,r20
	ctx.r28.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r20.u32);
	// subf r27,r23,r9
	ctx.r27.u64 = ctx.r9.u64 - ctx.r23.u64;
	// lbz r11,1(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// mullw r9,r28,r23
	ctx.r9.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r23.s32);
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// mullw r11,r4,r27
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r27.s32);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r9,132(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// add r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 + ctx.r10.u64;
	// srawi r10,r4,11
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 11;
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// mullw r4,r10,r9
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// rlwinm r10,r4,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFFFFFF;
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// stb r10,0(r25)
	REX_STORE_U8(ctx.r25.u32 + 0, ctx.r10.u8);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// lbz r4,1(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbzx r11,r11,r20
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r20.u32);
	// mullw r10,r11,r23
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r23.s32);
	// mullw r11,r4,r3
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r3.s32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mullw r11,r28,r27
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r27.s32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r11,r10,11
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FF) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 11;
	// addi r4,r11,-128
	ctx.r4.s64 = ctx.r11.s64 + -128;
	// mullw r3,r4,r9
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// rlwinm r11,r3,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// stb r11,0(r24)
	REX_STORE_U8(ctx.r24.u32 + 0, ctx.r11.u8);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// bdnz 0x826cd2d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD2D0;
loc_826CD374:
	// lwz r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// cmpw cr6,r11,r5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x826cd3e4
	if (!ctx.cr6.lt) goto loc_826CD3E4;
	// subf r11,r11,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r11.u64;
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// add r9,r19,r10
	ctx.r9.u64 = ctx.r19.u64 + ctx.r10.u64;
	// add r8,r19,r8
	ctx.r8.u64 = ctx.r19.u64 + ctx.r8.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826CD398:
	// srawi r11,r30,12
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xFFF) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 12;
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r7,132(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// add r30,r30,r10
	ctx.r30.u64 = ctx.r30.u64 + ctx.r10.u64;
	// lbzx r10,r9,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// mullw r4,r10,r7
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// rlwinm r10,r4,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFFFFFF;
	// addi r3,r10,128
	ctx.r3.s64 = ctx.r10.s64 + 128;
	// stb r3,0(r25)
	REX_STORE_U8(ctx.r25.u32 + 0, ctx.r3.u8);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// lbzx r11,r8,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r11.u32);
	// addi r4,r11,-128
	ctx.r4.s64 = ctx.r11.s64 + -128;
	// mullw r3,r4,r7
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r7.s32);
	// rlwinm r11,r3,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// stb r11,0(r24)
	REX_STORE_U8(ctx.r24.u32 + 0, ctx.r11.u8);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// bdnz 0x826cd398
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD398;
loc_826CD3E4:
	// lwz r7,152(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// cmpw cr6,r5,r7
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x826cd410
	if (!ctx.cr6.lt) goto loc_826CD410;
	// subf r9,r5,r7
	ctx.r9.u64 = ctx.r7.u64 - ctx.r5.u64;
	// addi r10,r24,-1
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// addi r11,r25,-1
	ctx.r11.s64 = ctx.r25.s64 + -1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// li r9,128
	ctx.r9.s64 = 128;
loc_826CD404:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x826cd404
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD404;
loc_826CD410:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r21,r18,1
	ctx.r21.s64 = ctx.r18.s64 + 1;
	// lwz r9,15360(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// add r11,r15,r11
	ctx.r11.u64 = ctx.r15.u64 + ctx.r11.u64;
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// add r22,r9,r16
	ctx.r22.u64 = ctx.r9.u64 + ctx.r16.u64;
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// lwz r30,136(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// add r3,r10,r7
	ctx.r3.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,15356(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15356);
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// add r8,r4,r7
	ctx.r8.u64 = ctx.r4.u64 + ctx.r7.u64;
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// and r23,r9,r11
	ctx.r23.u64 = ctx.r9.u64 & ctx.r11.u64;
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// clrlwi r26,r23,21
	ctx.r26.u64 = ctx.r23.u32 & 0x7FF;
	// srawi r11,r23,11
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x7FF) != 0);
	ctx.r11.s64 = ctx.r23.s32 >> 11;
	// extsw r7,r26
	ctx.r7.s64 = ctx.r26.s32;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// std r7,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r7.u64);
	// lfd f0,224(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 224);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f11,f13
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// blt cr6,0x826cd480
	if (ctx.cr6.lt) goto loc_826CD480;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_826CD480:
	// lwz r8,20(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,15372(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15372);
	// mullw r11,r8,r11
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ble cr6,0x826cd4bc
	if (!ctx.cr6.gt) goto loc_826CD4BC;
	// addi r11,r22,-1
	ctx.r11.s64 = ctx.r22.s64 + -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826cd4b8
	if (ctx.cr6.eq) goto loc_826CD4B8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CD4B0:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x826cd4b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD4B0;
loc_826CD4B8:
	// add r3,r22,r9
	ctx.r3.u64 = ctx.r22.u64 + ctx.r9.u64;
loc_826CD4BC:
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r17,-8
	ctx.r11.s64 = ctx.r17.s64 + -8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826CD4C8:
	// stwu r26,16(r11)
	ea = 16 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r26.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826cd4c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD4C8;
	// subfic r27,r26,2048
	ctx.xer.ca = ctx.r26.u32 <= 2048;
	ctx.r27.u64 = static_cast<uint64_t>(2048) - ctx.r26.u64;
	// stfs f0,204(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// srawi. r11,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r24,r10,r6
	ctx.r24.u64 = ctx.r6.u64 - ctx.r10.u64;
	// ble 0x826cd68c
	if (!ctx.cr0.gt) goto loc_826CD68C;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lvx128 v2,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826CD4F4:
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r11,r17,256
	ctx.r11.s64 = ctx.r17.s64 + 256;
	// addi r10,r17,-4
	ctx.r10.s64 = ctx.r17.s64 + -4;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CD508:
	// srawi r9,r30,11
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r30.s32 >> 11;
	// lwz r8,20(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// clrlwi r4,r30,21
	ctx.r4.u64 = ctx.r30.u32 & 0x7FF;
	// add r9,r9,r28
	ctx.r9.u64 = ctx.r9.u64 + ctx.r28.u64;
	// subf r19,r4,r27
	ctx.r19.u64 = ctx.r27.u64 - ctx.r4.u64;
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r8,r30,r29
	ctx.r8.u64 = ctx.r30.u64 + ctx.r29.u64;
	// lbz r30,1(r9)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// srawi r5,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 11;
	// lbz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// clrlwi r18,r8,21
	ctx.r18.u64 = ctx.r8.u32 & 0x7FF;
	// lbz r17,0(r7)
	ctx.r17.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// add r9,r5,r28
	ctx.r9.u64 = ctx.r5.u64 + ctx.r28.u64;
	// lbz r7,1(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// subf r16,r18,r27
	ctx.r16.u64 = ctx.r27.u64 - ctx.r18.u64;
	// stw r4,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + ctx.r29.u64;
	// subf r7,r17,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r17.u64;
	// stw r4,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r4.u32);
	// stw r30,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r30.u32);
	// srawi r5,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 11;
	// subf r7,r30,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r30.u64;
	// stw r17,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r17.u32);
	// stw r19,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r19.u32);
	// clrlwi r30,r8,21
	ctx.r30.u64 = ctx.r8.u32 & 0x7FF;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + ctx.r29.u64;
	// stw r7,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// subf r19,r30,r27
	ctx.r19.u64 = ctx.r27.u64 - ctx.r30.u64;
	// srawi r4,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 11;
	// clrlwi r17,r8,21
	ctx.r17.u64 = ctx.r8.u32 & 0x7FF;
	// subf r15,r17,r27
	ctx.r15.u64 = ctx.r27.u64 - ctx.r17.u64;
	// lwz r7,20(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lbz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lbz r9,1(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// add r9,r5,r28
	ctx.r9.u64 = ctx.r5.u64 + ctx.r28.u64;
	// lbz r14,0(r7)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// lbz r7,1(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// subf r7,r14,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r14.u64;
	// stw r14,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r14.u32);
	// lwz r14,116(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// subf r7,r14,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r14.u64;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r18,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r18.u32);
	// stw r18,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r18.u32);
	// stw r7,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r7.u32);
	// stw r16,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r16.u32);
	// stw r14,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r14.u32);
	// stw r6,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// lwz r7,20(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lbzx r6,r5,r28
	ctx.r6.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r28.u32);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lbz r9,1(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r5,0(r7)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// lbz r7,1(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// stw r9,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r9.u32);
	// subf r7,r5,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r5.u64;
	// stw r5,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r5.u32);
	// subf r7,r9,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r9.u64;
	// stw r6,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// add r9,r4,r28
	ctx.r9.u64 = ctx.r4.u64 + ctx.r28.u64;
	// stw r30,40(r10)
	REX_STORE_U32(ctx.r10.u32 + 40, ctx.r30.u32);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r30,48(r10)
	REX_STORE_U32(ctx.r10.u32 + 48, ctx.r30.u32);
	// stw r7,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r7.u32);
	// stw r19,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r19.u32);
	// lbz r6,1(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lwz r7,20(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lbz r5,0(r7)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// lbz r7,1(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// lbzx r9,r4,r28
	ctx.r9.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r28.u32);
	// subf r4,r5,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r5.u64;
	// subf r7,r6,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r6.u64;
	// stw r9,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
	// stw r6,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r6.u32);
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// stw r5,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r5.u32);
	// stw r15,52(r10)
	REX_STORE_U32(ctx.r10.u32 + 52, ctx.r15.u32);
	// add r30,r8,r29
	ctx.r30.u64 = ctx.r8.u64 + ctx.r29.u64;
	// stw r17,56(r10)
	REX_STORE_U32(ctx.r10.u32 + 56, ctx.r17.u32);
	// stwu r9,64(r11)
	ea = 64 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// stwu r17,64(r10)
	ea = 64 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r17.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x826cd508
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD508;
	// lwz r17,184(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// mr r5,r17
	ctx.r5.u64 = ctx.r17.u64;
	// addi r4,r17,256
	ctx.r4.s64 = ctx.r17.s64 + 256;
	// bl 0x826caa78
	ctx.lr = 0x826CD674;
	sub_826CAA78(ctx, base);
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bne 0x826cd4f4
	if (!ctx.cr0.eq) goto loc_826CD4F4;
	// lwz r6,156(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r14,164(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
loc_826CD68C:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// ble cr6,0x826cd714
	if (!ctx.cr6.gt) goto loc_826CD714;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_826CD698:
	// srawi r11,r30,11
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FF) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 11;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// clrlwi r7,r30,21
	ctx.r7.u64 = ctx.r30.u32 & 0x7FF;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r30,r30,r29
	ctx.r30.u64 = ctx.r30.u64 + ctx.r29.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r4,1(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// mullw r9,r4,r7
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r7.s32);
	// lbz r10,1(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// mullw r8,r8,r26
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r26.s32);
	// subf r10,r4,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r4.u64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mullw r10,r4,r7
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r7.s32);
	// mullw r4,r10,r26
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r26.s32);
	// srawi r10,r4,11
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 11;
	// subfic r7,r7,2048
	ctx.xer.ca = ctx.r7.u32 <= 2048;
	ctx.r7.u64 = static_cast<uint64_t>(2048) - ctx.r7.u64;
	// subf r4,r26,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r26.u64;
	// mullw r11,r4,r11
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r11.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r11,r8
	ctx.r10.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// srawi r9,r10,11
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 11;
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// rlwinm r7,r8,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF;
	// stb r7,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r7.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bdnz 0x826cd698
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD698;
loc_826CD714:
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// cmpw cr6,r11,r14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r14.s32, ctx.xer);
	// bge cr6,0x826cd74c
	if (!ctx.cr6.lt) goto loc_826CD74C;
	// subf r11,r11,r14
	ctx.r11.u64 = ctx.r14.u64 - ctx.r11.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826CD728:
	// srawi r10,r30,11
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r30.s32 >> 11;
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// add r30,r30,r29
	ctx.r30.u64 = ctx.r30.u64 + ctx.r29.u64;
	// lbzx r9,r10,r28
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r28.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// rlwinm r7,r8,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF;
	// stb r7,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r7.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bdnz 0x826cd728
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD728;
loc_826CD74C:
	// lwz r11,15360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
	// cmpw cr6,r14,r11
	ctx.cr6.compare<int32_t>(ctx.r14.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826cd778
	if (!ctx.cr6.lt) goto loc_826CD778;
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
loc_826CD760:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// lwz r11,15360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826cd760
	if (ctx.cr6.lt) goto loc_826CD760;
loc_826CD778:
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r18,r21,1
	ctx.r18.s64 = ctx.r21.s64 + 1;
	// lwz r9,160(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// add r16,r11,r22
	ctx.r16.u64 = ctx.r11.u64 + ctx.r22.u64;
	// add r10,r23,r10
	ctx.r10.u64 = ctx.r23.u64 + ctx.r10.u64;
	// addi r4,r9,-2
	ctx.r4.s64 = ctx.r9.s64 + -2;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// cmpw cr6,r18,r4
	ctx.cr6.compare<int32_t>(ctx.r18.s32, ctx.r4.s32, ctx.xer);
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// and r15,r8,r10
	ctx.r15.u64 = ctx.r8.u64 & ctx.r10.u64;
	// stw r15,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r15.u32);
	// blt cr6,0x826ccd30
	if (ctx.cr6.lt) goto loc_826CCD30;
loc_826CD7A8:
	// lwz r11,15356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15356);
	// srawi r6,r15,11
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x7FF) != 0);
	ctx.r6.s64 = ctx.r15.s32 >> 11;
	// lwz r24,136(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// blt cr6,0x826cd7c4
	if (ctx.cr6.lt) goto loc_826CD7C4;
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
loc_826CD7C4:
	// lwz r11,172(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// lwz r17,160(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// cmpw cr6,r17,r10
	ctx.cr6.compare<int32_t>(ctx.r17.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826cda60
	if (ctx.cr6.lt) goto loc_826CDA60;
	// cmpw cr6,r4,r17
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r17.s32, ctx.xer);
	// bge cr6,0x826cda60
	if (!ctx.cr6.lt) goto loc_826CDA60;
	// lwz r28,152(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// li r23,0
	ctx.r23.s64 = 0;
	// lwz r30,112(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// li r14,128
	ctx.r14.s64 = 128;
	// lwz r25,88(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r26,92(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r18,100(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r22,144(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r21,140(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r19,96(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r27,120(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
loc_826CD80C:
	// mr r11,r16
	ctx.r11.u64 = ctx.r16.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ble cr6,0x826cd838
	if (!ctx.cr6.gt) goto loc_826CD838;
	// addi r11,r16,-1
	ctx.r11.s64 = ctx.r16.s64 + -1;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826cd834
	if (ctx.cr6.eq) goto loc_826CD834;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
loc_826CD82C:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x826cd82c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD82C;
loc_826CD834:
	// add r11,r16,r30
	ctx.r11.u64 = ctx.r16.u64 + ctx.r30.u64;
loc_826CD838:
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// lwz r10,15372(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15372);
	// mullw r9,r9,r6
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bge cr6,0x826cd87c
	if (!ctx.cr6.lt) goto loc_826CD87C;
	// subf r9,r30,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r30.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CD858:
	// srawi r7,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 11;
	// lwz r9,132(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + ctx.r29.u64;
	// lbzx r6,r7,r10
	ctx.r6.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r10.u32);
	// mullw r5,r6,r9
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// rlwinm r3,r5,24,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFF;
	// stb r3,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r3.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x826cd858
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD858;
loc_826CD87C:
	// lwz r9,15360(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// cmpw cr6,r27,r9
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x826cd8a4
	if (!ctx.cr6.lt) goto loc_826CD8A4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_826CD890:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbu r23,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r23.u8);
	ctx.r11.u32 = ea;
	// lwz r9,15360(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x826cd890
	if (ctx.cr6.lt) goto loc_826CD890;
loc_826CD8A4:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// ble cr6,0x826cd8cc
	if (!ctx.cr6.gt) goto loc_826CD8CC;
	// mtctr r21
	ctx.ctr.u64 = ctx.r21.u64;
loc_826CD8B8:
	// stb r14,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r14.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r14,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r14.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x826cd8b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD8B8;
loc_826CD8CC:
	// lwz r7,15356(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 15356);
	// srawi r9,r15,12
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0xFFF) != 0);
	ctx.r9.s64 = ctx.r15.s32 >> 12;
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// srawi r7,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 1;
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x826cd8e8
	if (ctx.cr6.lt) goto loc_826CD8E8;
	// addi r9,r7,-1
	ctx.r9.s64 = ctx.r7.s64 + -1;
loc_826CD8E8:
	// mullw r9,r9,r20
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r20.s32);
	// cmpw cr6,r21,r22
	ctx.cr6.compare<int32_t>(ctx.r21.s32, ctx.r22.s32, ctx.xer);
	// bge cr6,0x826cd950
	if (!ctx.cr6.lt) goto loc_826CD950;
	// subf r7,r21,r22
	ctx.r7.u64 = ctx.r22.u64 - ctx.r21.u64;
	// add r6,r9,r19
	ctx.r6.u64 = ctx.r9.u64 + ctx.r19.u64;
	// add r5,r9,r18
	ctx.r5.u64 = ctx.r9.u64 + ctx.r18.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_826CD904:
	// srawi r9,r8,12
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 12;
	// lwz r7,108(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r3,132(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lbzx r7,r6,r9
	ctx.r7.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r9.u32);
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// mullw r7,r7,r3
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r3.s32);
	// rlwinm r7,r7,24,8,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFFFFFF;
	// addi r7,r7,128
	ctx.r7.s64 = ctx.r7.s64 + 128;
	// stb r7,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbzx r9,r5,r9
	ctx.r9.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r9.u32);
	// addi r9,r9,-128
	ctx.r9.s64 = ctx.r9.s64 + -128;
	// mullw r7,r9,r3
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// rlwinm r9,r7,24,8,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFFFFFF;
	// addi r3,r9,128
	ctx.r3.s64 = ctx.r9.s64 + 128;
	// stb r3,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r3.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x826cd904
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD904;
loc_826CD950:
	// cmpw cr6,r22,r28
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x826cd974
	if (!ctx.cr6.lt) goto loc_826CD974;
	// subf r9,r22,r28
	ctx.r9.u64 = ctx.r28.u64 - ctx.r22.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CD968:
	// stbu r14,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r14.u8);
	ctx.r11.u32 = ea;
	// stbu r14,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r14.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x826cd968
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD968;
loc_826CD974:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r25,r25,r28
	ctx.r25.u64 = ctx.r25.u64 + ctx.r28.u64;
	// lwz r9,15360(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// add r11,r15,r11
	ctx.r11.u64 = ctx.r15.u64 + ctx.r11.u64;
	// lwz r10,15356(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15356);
	// add r7,r9,r16
	ctx.r7.u64 = ctx.r9.u64 + ctx.r16.u64;
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r5,r4,1
	ctx.r5.s64 = ctx.r4.s64 + 1;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// and r15,r9,r11
	ctx.r15.u64 = ctx.r9.u64 & ctx.r11.u64;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// srawi r6,r15,11
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x7FF) != 0);
	ctx.r6.s64 = ctx.r15.s32 >> 11;
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826cd9b8
	if (ctx.cr6.lt) goto loc_826CD9B8;
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
loc_826CD9B8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ble cr6,0x826cd9e0
	if (!ctx.cr6.gt) goto loc_826CD9E0;
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826cd9dc
	if (ctx.cr6.eq) goto loc_826CD9DC;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
loc_826CD9D4:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x826cd9d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CD9D4;
loc_826CD9DC:
	// add r11,r7,r30
	ctx.r11.u64 = ctx.r7.u64 + ctx.r30.u64;
loc_826CD9E0:
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// lwz r10,15372(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15372);
	// mullw r9,r9,r6
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bge cr6,0x826cda24
	if (!ctx.cr6.lt) goto loc_826CDA24;
	// subf r9,r30,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r30.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CDA00:
	// srawi r4,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 11;
	// lwz r9,132(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + ctx.r29.u64;
	// lbzx r3,r4,r10
	ctx.r3.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// mullw r9,r3,r9
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// rlwinm r4,r9,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// stb r4,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r4.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x826cda00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDA00;
loc_826CDA24:
	// lwz r10,15360(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// cmpw cr6,r27,r10
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x826cda4c
	if (!ctx.cr6.lt) goto loc_826CDA4C;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_826CDA38:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stbu r23,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r23.u8);
	ctx.r11.u32 = ea;
	// lwz r10,15360(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826cda38
	if (ctx.cr6.lt) goto loc_826CDA38;
loc_826CDA4C:
	// addi r4,r5,1
	ctx.r4.s64 = ctx.r5.s64 + 1;
	// add r16,r10,r7
	ctx.r16.u64 = ctx.r10.u64 + ctx.r7.u64;
	// cmpw cr6,r4,r17
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r17.s32, ctx.xer);
	// blt cr6,0x826cd80c
	if (ctx.cr6.lt) goto loc_826CD80C;
	// b 0x826cda74
	goto loc_826CDA74;
loc_826CDA60:
	// lwz r28,152(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// li r23,0
	ctx.r23.s64 = 0;
	// lwz r25,88(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// li r14,128
	ctx.r14.s64 = 128;
	// lwz r26,92(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
loc_826CDA74:
	// lwz r11,15364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15364);
	// mr r9,r17
	ctx.r9.u64 = ctx.r17.u64;
	// cmpw cr6,r17,r11
	ctx.cr6.compare<int32_t>(ctx.r17.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826cdb1c
	if (!ctx.cr6.lt) goto loc_826CDB1C;
loc_826CDA84:
	// lwz r10,15360(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826cdaac
	if (!ctx.cr6.gt) goto loc_826CDAAC;
	// addi r10,r16,-1
	ctx.r10.s64 = ctx.r16.s64 + -1;
loc_826CDA98:
	// stbu r23,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r23.u8);
	ctx.r10.u32 = ea;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r8,15360(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x826cda98
	if (ctx.cr6.lt) goto loc_826CDA98;
loc_826CDAAC:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x826cdad0
	if (!ctx.cr6.gt) goto loc_826CDAD0;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// mtctr r28
	ctx.ctr.u64 = ctx.r28.u64;
	// subf r10,r26,r25
	ctx.r10.u64 = ctx.r25.u64 - ctx.r26.u64;
loc_826CDAC0:
	// stbx r14,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r14.u8);
	// stb r14,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r14.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x826cdac0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CDAC0;
loc_826CDAD0:
	// lwz r11,15360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// add r25,r25,r28
	ctx.r25.u64 = ctx.r25.u64 + ctx.r28.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// add r8,r11,r16
	ctx.r8.u64 = ctx.r11.u64 + ctx.r16.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826cdb08
	if (!ctx.cr6.gt) goto loc_826CDB08;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
loc_826CDAF4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbu r23,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r23.u8);
	ctx.r9.u32 = ea;
	// lwz r11,15360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826cdaf4
	if (ctx.cr6.lt) goto loc_826CDAF4;
loc_826CDB08:
	// lwz r10,15364(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15364);
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// add r16,r11,r8
	ctx.r16.u64 = ctx.r11.u64 + ctx.r8.u64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826cda84
	if (ctx.cr6.lt) goto loc_826CDA84;
loc_826CDB1C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af60
	ctx.lr = 0x826CDB2C;
	__restfpr_23(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(__restvmx_117) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(sub_8273C638) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r3,20
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 20, ctx.xer);
	// bge cr6,0x8273c654
	if (!ctx.cr6.lt) goto loc_8273C654;
	// lwz r11,12(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// rlwinm r11,r11,0,17,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// stw r11,12(r4)
	REX_STORE_U32(ctx.r4.u32 + 12, ctx.r11.u32);
	// b 0x827415d8
	sub_827415D8(ctx, base);
	return;
loc_8273C654:
	// addi r3,r4,32
	ctx.r3.s64 = ctx.r4.s64 + 32;
	// b 0x82855b34
	__imp__RtlLeaveCriticalSection(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8273CD2C) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-144
	ctx.r31.s64 = ctx.r12.s64 + -144;
	// std r29,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r29.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273c5f8
	ctx.lr = 0x8273CD4C;
	sub_8273C5F8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// ld r29,-16(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8273D450) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8273D458;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// bl 0x8273aa88
	ctx.lr = 0x8273D47C;
	sub_8273AA88(ctx, base);
	// stw r30,176(r3)
	REX_STORE_U32(ctx.r3.u32 + 176, ctx.r30.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x827447a8
	ctx.lr = 0x8273D4A4;
	sub_827447A8(ctx, base);
	// bl 0x8273aa88
	ctx.lr = 0x8273D4A8;
	sub_8273AA88(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,176(r3)
	REX_STORE_U32(ctx.r3.u32 + 176, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8273F7F4) {
	REX_FUNC_PROLOGUE();
	// stw r3,-4(r1)
	REX_STORE_U32(ctx.r1.u32 + -4, ctx.r3.u32);
	// lfd f1,-8(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// mtfsf 255,f1
	ctx.fpscr.storeFromGuest(ctx.f1.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827408A0) {
	REX_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x827406d8
	sub_827406D8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82741440) {
	REX_FUNC_PROLOGUE();
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// cmpwi cr6,r11,101
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 101, ctx.xer);
	// beq cr6,0x82741488
	if (ctx.cr6.eq) goto loc_82741488;
	// cmpwi cr6,r11,69
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 69, ctx.xer);
	// beq cr6,0x82741488
	if (ctx.cr6.eq) goto loc_82741488;
	// cmpwi cr6,r11,102
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 102, ctx.xer);
	// bne cr6,0x82741470
	if (!ctx.cr6.eq) goto loc_82741470;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// b 0x82741218
	sub_82741218(ctx, base);
	return;
loc_82741470:
	// cmpwi cr6,r11,97
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 97, ctx.xer);
	// beq cr6,0x82741484
	if (ctx.cr6.eq) goto loc_82741484;
	// cmpwi cr6,r11,65
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 65, ctx.xer);
	// beq cr6,0x82741484
	if (ctx.cr6.eq) goto loc_82741484;
	// b 0x827412f8
	sub_827412F8(ctx, base);
	return;
loc_82741484:
	// b 0x82740c30
	sub_82740C30(ctx, base);
	return;
loc_82741488:
	// b 0x82740b28
	sub_82740B28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827432F8) {
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
	// bl 0x827415d8
	ctx.lr = 0x8274330C;
	sub_827415D8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82743CD0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// andi. r11,r11,102
	ctx.r11.u64 = ctx.r11.u64 & 102;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82743ce8
	if (!ctx.cr0.eq) goto loc_82743CE8;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82743CE8:
	// stw r5,12(r4)
	REX_STORE_U32(ctx.r4.u32 + 12, ctx.r5.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// ld r11,48(r5)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r5.u32 + 48);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// ld r11,56(r5)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r5.u32 + 56);
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// ld r11,64(r5)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r5.u32 + 64);
	// stw r11,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82745968) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82745970;
	__savegprlr_29(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r3.u32);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// addi r11,r11,-13536
	ctx.r11.s64 = ctx.r11.s64 + -13536;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// li r29,1
	ctx.r29.s64 = 1;
	// mulli r9,r9,72
	ctx.r9.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(72));
	// stw r29,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// lwzx r10,r10,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x827459fc
	if (!ctx.cr6.eq) goto loc_827459FC;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x82741738
	ctx.lr = 0x827459B8;
	sub_82741738(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827459f0
	if (!ctx.cr6.eq) goto loc_827459F0;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r30,12
	ctx.r3.s64 = ctx.r30.s64 + 12;
	// bl 0x82741a70
	ctx.lr = 0x827459D4;
	sub_82741A70(ctx, base);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
loc_827459F0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	ctx.r12.s64 = ctx.r31.s64 + 128;
	// bl 0x82745a30
	ctx.lr = 0x827459FC;
	sub_82745A30(ctx, base);
loc_827459FC:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82745a24
	if (ctx.cr6.eq) goto loc_82745A24;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r9,72
	ctx.r10.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(72));
	// lwzx r11,r8,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// bl 0x82855b44
	ctx.lr = 0x82745A24;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_82745A24:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8274C2D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x8274C2D8;
	__savegprlr_20(ctx, base);
	// stfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f30.u64);
	// stfd f31,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f31.u64);
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8273b374
	ctx.lr = 0x8274C2E8;
	__savevmx_124(ctx, base);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// vor128 v127,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// mr r22,r8
	ctx.r22.u64 = ctx.r8.u64;
	// vor128 v126,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// mr r21,r9
	ctx.r21.u64 = ctx.r9.u64;
	// vor128 v124,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// mr r20,r10
	ctx.r20.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// li r27,0
	ctx.r27.s64 = 0;
	// lis r29,-128
	ctx.r29.s64 = -8388608;
	// bne cr6,0x8274c364
	if (!ctx.cr6.eq) goto loc_8274C364;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// vupkd3d128 v63,v63,0
	vTemp.u32[0] = ctx.v63.u8[3] | 0x3F800000;
	vTemp.u32[1] = ctx.v63.u8[0] | 0x3F800000;
	vTemp.u32[2] = ctx.v63.u8[1] | 0x3F800000;
	vTemp.u32[3] = ctx.v63.u8[2] | 0x3F800000;
	ctx.v63 = vTemp;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// stw r27,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// stw r27,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// lvx128 v125,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// lvx128 v127,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8274c568
	goto loc_8274C568;
loc_8274C364:
	// li r11,-1
	ctx.r11.s64 = -1;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r28,r3,28
	ctx.r28.s64 = ctx.r3.s64 + 28;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r30,1
	ctx.r30.s64 = 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f30,8220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8220);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,5864(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5864);
	ctx.f31.f64 = double(temp.f32);
	// lvx128 v125,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8274C3A4:
	// lwz r10,16(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// srw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// subfic r10,r11,32
	ctx.xer.ca = ctx.r11.u32 <= 32;
	ctx.r10.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8274c558
	if (ctx.cr6.eq) goto loc_8274C558;
	// lwzx r9,r31,r25
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r25.u32);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x8274c3d8
	if (!ctx.cr6.eq) goto loc_8274C3D8;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// slw r11,r30,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// b 0x8274c3dc
	goto loc_8274C3DC;
loc_8274C3D8:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8274C3DC:
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// stvx128 v124,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwx r11,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u32);
	// lvx128 v124,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8274c4e0
	if (!ctx.cr6.eq) goto loc_8274C4E0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8274c494
	if (ctx.cr6.eq) goto loc_8274C494;
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// beq cr6,0x8274c494
	if (ctx.cr6.eq) goto loc_8274C494;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stvx128 v126,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// slw r11,r30,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r10,r9,32
	ctx.r10.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stvx128 v127,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stfsx f30,r31,r7
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lvx128 v127,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// lvx128 v126,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f0,f31,f13
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f13.f64));
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8274c558
	goto loc_8274C558;
loc_8274C494:
	// clrldi r11,r10,32
	ctx.r11.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// sld r11,r30,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r30.u64 << (ctx.r11.u8 & 0x7F));
	// addi r3,r11,-1
	ctx.r3.s64 = ctx.r11.s64 + -1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273acd0
	ctx.lr = 0x8274C4AC;
	sub_8273ACD0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwx r29,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r29.u32);
	// fdivs f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lvx128 v127,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8274c558
	goto loc_8274C558;
loc_8274C4E0:
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfsx f31,r31,r7
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8274c508
	if (ctx.cr6.eq) goto loc_8274C508;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x8274c540
	if (!ctx.cr6.eq) goto loc_8274C540;
loc_8274C508:
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// stvx128 v126,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// slw r11,r30,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lvx128 v126,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8274C540:
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// stvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwx r29,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r29.u32);
	// lvx128 v127,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8274C558:
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bdnz 0x8274c3a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8274C3A4;
	// vmulfp128 v126,v126,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v126.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v63.f32)));
loc_8274C568:
	// stvx128 v125,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8273b60c
	ctx.lr = 0x8274C588;
	__restvmx_124(ctx, base);
	// lfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82767BF0) {
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
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82766f38
	ctx.lr = 0x82767C0C;
	sub_82766F38(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82767c60
	if (ctx.cr0.eq) goto loc_82767C60;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,32(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// bl 0x82736178
	ctx.lr = 0x82767C20;
	sub_82736178(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82767c58
	if (ctx.cr0.eq) goto loc_82767C58;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82767c4c
	if (ctx.cr6.eq) goto loc_82767C4C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82639f18
	ctx.lr = 0x82767C38;
	sub_82639F18(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82767c68
	if (ctx.cr0.lt) goto loc_82767C68;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x82767c68
	goto loc_82767C68;
loc_82767C4C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,997
	ctx.r3.u64 = ctx.r3.u64 | 997;
	// b 0x82767c68
	goto loc_82767C68;
loc_82767C58:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82767c68
	goto loc_82767C68;
loc_82767C60:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,117
	ctx.r3.u64 = ctx.r3.u64 | 117;
loc_82767C68:
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

DEFINE_REX_FUNC(sub_8276AC40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x8276AC48;
	__savegprlr_20(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r20,r4
	ctx.r20.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8276ac84
	if (ctx.cr6.eq) goto loc_8276AC84;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,1609
	ctx.r30.u64 = ctx.r30.u64 | 1609;
	// b 0x8276af5c
	goto loc_8276AF5C;
loc_8276AC84:
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r21,0
	ctx.r21.s64 = 0;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r21,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r21.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8276ACB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82766990
	ctx.lr = 0x8276ACCC;
	sub_82766990(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8276af3c
	if (ctx.cr0.lt) goto loc_8276AF3C;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8276acec
	if (!ctx.cr6.lt) goto loc_8276ACEC;
	// lis r30,-32747
	ctx.r30.s64 = -2146107392;
	// ori r30,r30,20994
	ctx.r30.u64 = ctx.r30.u64 | 20994;
	// b 0x8276af3c
	goto loc_8276AF3C;
loc_8276ACEC:
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8276ad4c
	if (ctx.cr6.eq) goto loc_8276AD4C;
	// lwz r27,324(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_8276AD0C:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,32778
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32778, ctx.xer);
	// bne cr6,0x8276ad30
	if (!ctx.cr6.eq) goto loc_8276AD30;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8276ad28
	if (!ctx.cr6.eq) goto loc_8276AD28;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8276AD28:
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x8276ad3c
	goto loc_8276AD3C;
loc_8276AD30:
	// cmplwi cr6,r11,32779
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32779, ctx.xer);
	// bne cr6,0x8276ad3c
	if (!ctx.cr6.eq) goto loc_8276AD3C;
	// li r8,1
	ctx.r8.s64 = 1;
loc_8276AD3C:
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x8276ad0c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8276AD0C;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8276ad58
	if (!ctx.cr6.eq) goto loc_8276AD58;
loc_8276AD4C:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,87
	ctx.r30.u64 = ctx.r30.u64 | 87;
	// b 0x8276af3c
	goto loc_8276AF3C;
loc_8276AD58:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8276ad4c
	if (ctx.cr6.eq) goto loc_8276AD4C;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8276ad80
	if (ctx.cr6.eq) goto loc_8276AD80;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8276ad88
	if (ctx.cr6.eq) goto loc_8276AD88;
loc_8276AD74:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,117
	ctx.r30.u64 = ctx.r30.u64 | 117;
	// b 0x8276af3c
	goto loc_8276AF3C;
loc_8276AD80:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8276ad74
	if (ctx.cr6.eq) goto loc_8276AD74;
loc_8276AD88:
	// addi r25,r31,228
	ctx.r25.s64 = ctx.r31.s64 + 228;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82771228
	ctx.lr = 0x8276ADA0;
	sub_82771228(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8276af3c
	if (ctx.cr0.lt) goto loc_8276AF3C;
	// addi r26,r31,240
	ctx.r26.s64 = ctx.r31.s64 + 240;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82770d80
	ctx.lr = 0x8276ADC0;
	sub_82770D80(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8276af3c
	if (ctx.cr0.lt) goto loc_8276AF3C;
	// lwz r11,740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 740);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r23,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r23.u8);
	// oris r7,r11,16384
	ctx.r7.u64 = ctx.r11.u64 | 1073741824;
	// stb r22,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r22.u8);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// ori r7,r7,1024
	ctx.r7.u64 = ctx.r7.u64 | 1024;
	// subf r11,r8,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r8.u64;
	// stw r7,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r7.u32);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// bl 0x827647e0
	ctx.lr = 0x8276ADF8;
	sub_827647E0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// rlwinm. r27,r3,0,29,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x6;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x8276ae18
	if (ctx.cr0.eq) goto loc_8276AE18;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x8276ae18
	if (!ctx.cr6.eq) goto loc_8276AE18;
	// lis r30,-32747
	ctx.r30.s64 = -2146107392;
	// ori r30,r30,21001
	ctx.r30.u64 = ctx.r30.u64 | 21001;
	// b 0x8276af3c
	goto loc_8276AF3C;
loc_8276AE18:
	// rlwimi r7,r29,10,20,20
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 10) & 0x800) | (ctx.r7.u64 & 0xFFFFFFFFFFFFF7FF);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r7,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r7.u32);
	// rlwinm r8,r29,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x4;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82769a48
	ctx.lr = 0x8276AE40;
	sub_82769A48(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8276af3c
	if (ctx.cr0.lt) goto loc_8276AF3C;
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// addi r28,r31,380
	ctx.r28.s64 = ctx.r31.s64 + 380;
loc_8276AE50:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8276ae7c
	if (ctx.cr6.eq) goto loc_8276AE7C;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x827718e8
	ctx.lr = 0x8276AE6C;
	sub_827718E8(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82770f88
	ctx.lr = 0x8276AE7C;
	sub_82770F88(ctx, base);
loc_8276AE7C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x8276ae50
	if (ctx.cr6.lt) goto loc_8276AE50;
	// lwz r30,8(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82748820
	ctx.lr = 0x8276AE94;
	sub_82748820(ctx, base);
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// stw r11,44(r30)
	REX_STORE_U32(ctx.r30.u32 + 44, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8276aec8
	if (!ctx.cr6.eq) goto loc_8276AEC8;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8276aec8
	if (!ctx.cr6.eq) goto loc_8276AEC8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8276a260
	ctx.lr = 0x8276AEC4;
	sub_8276A260(ctx, base);
	// b 0x8276af58
	goto loc_8276AF58;
loc_8276AEC8:
	// lbz r9,169(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// lbz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// addi r10,r31,32
	ctx.r10.s64 = ctx.r31.s64 + 32;
	// stw r29,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r29.u32);
	// addi r8,r31,48
	ctx.r8.s64 = ctx.r31.s64 + 48;
	// addi r7,r31,40
	ctx.r7.s64 = ctx.r31.s64 + 40;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// stb r9,173(r31)
	REX_STORE_U8(ctx.r31.u32 + 173, ctx.r9.u8);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stb r11,172(r31)
	REX_STORE_U8(ctx.r31.u32 + 172, ctx.r11.u8);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// std r21,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r21.u64);
	// std r21,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r21.u64);
	// std r21,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r21.u64);
	// stw r21,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r21.u32);
	// lbz r6,169(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// lbz r5,168(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// bl 0x827357b0
	ctx.lr = 0x8276AF14;
	sub_827357B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8276af4c
	if (ctx.cr0.eq) goto loc_8276AF4C;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8276af4c
	if (ctx.cr6.eq) goto loc_8276AF4C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82639f18
	ctx.lr = 0x8276AF2C;
	sub_82639F18(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8276af3c
	if (ctx.cr0.lt) goto loc_8276AF3C;
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16389
	ctx.r30.u64 = ctx.r30.u64 | 16389;
loc_8276AF3C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82769780
	ctx.lr = 0x8276AF48;
	sub_82769780(ctx, base);
	// b 0x8276af5c
	goto loc_8276AF5C;
loc_8276AF4C:
	// lis r11,-32137
	ctx.r11.s64 = -2106130432;
	// addi r11,r11,-23968
	ctx.r11.s64 = ctx.r11.s64 + -23968;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
loc_8276AF58:
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
loc_8276AF5C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8277ACD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8277ACE0;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r27,r3,8
	ctx.r27.s64 = ctx.r3.s64 + 8;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82788388
	ctx.lr = 0x8277ACF8;
	sub_82788388(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8277ae64
	if (!ctx.cr0.eq) goto loc_8277AE64;
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// lwz r10,20(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8277ae60
	if (!ctx.cr6.eq) goto loc_8277AE60;
	// lwz r11,148(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 148);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8277ae60
	if (!ctx.cr6.eq) goto loc_8277AE60;
	// lwz r11,208(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 208);
	// addi r28,r26,208
	ctx.r28.s64 = ctx.r26.s64 + 208;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8277ae44
	if (ctx.cr6.eq) goto loc_8277AE44;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8277ae44
	if (ctx.cr0.eq) goto loc_8277AE44;
loc_8277AD38:
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r31,r29,-4
	ctx.r31.s64 = ctx.r29.s64 + -4;
	// lwz r11,284(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 284);
	// subf r9,r10,r28
	ctx.r9.u64 = ctx.r28.u64 - ctx.r10.u64;
	// rlwinm. r8,r11,0,6,6
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// subfic r9,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r29,r9,r10
	ctx.r29.u64 = ctx.r9.u64 & ctx.r10.u64;
	// beq 0x8277ae3c
	if (ctx.cr0.eq) goto loc_8277AE3C;
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8277ae3c
	if (!ctx.cr0.eq) goto loc_8277AE3C;
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8277ae3c
	if (ctx.cr0.eq) goto loc_8277AE3C;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lis r10,-32646
	ctx.r10.s64 = -2139488256;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// ori r10,r10,4113
	ctx.r10.u64 = ctx.r10.u64 | 4113;
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r10,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x82786608
	ctx.lr = 0x8277AD90;
	sub_82786608(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8277ae20
	if (!ctx.cr0.eq) goto loc_8277AE20;
loc_8277AD98:
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
	// bne 0x8277ad98
	if (!ctx.cr0.eq) goto loc_8277AD98;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82736458
	ctx.lr = 0x8277ADC0;
	sub_82736458(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,8
	ctx.r9.s64 = 8;
	// lwz r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r4,24(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 24);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82787200
	ctx.lr = 0x8277ADE8;
	sub_82787200(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8277ae3c
	if (ctx.cr0.eq) goto loc_8277AE3C;
loc_8277ADF0:
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
	// bne 0x8277adf0
	if (!ctx.cr0.eq) goto loc_8277ADF0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8277ae64
	if (!ctx.cr6.eq) goto loc_8277AE64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82784b48
	ctx.lr = 0x8277AE1C;
	sub_82784B48(ctx, base);
	// b 0x8277ae64
	goto loc_8277AE64;
loc_8277AE20:
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
	// bne 0x8277ae20
	if (!ctx.cr0.eq) goto loc_8277AE20;
loc_8277AE3C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8277ad38
	if (!ctx.cr6.eq) goto loc_8277AD38;
loc_8277AE44:
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8277ae60
	if (ctx.cr6.eq) goto loc_8277AE60;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827886b8
	ctx.lr = 0x8277AE58;
	sub_827886B8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8277ae64
	if (!ctx.cr0.eq) goto loc_8277AE64;
loc_8277AE60:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8277AE64:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82786EA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x82786EB0;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r9,20(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r11,40(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 40);
	// lis r10,13364
	ctx.r10.s64 = 875823104;
	// lwz r4,16(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// ori r29,r10,13364
	ctx.r29.u64 = ctx.r10.u64 | 13364;
	// subf r10,r4,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r4.u64;
	// lwz r3,108(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// mr r22,r8
	ctx.r22.u64 = ctx.r8.u64;
	// lwz r30,112(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r24,44(r31)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lis r8,4626
	ctx.r8.s64 = 303169536;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cntlzw r4,r3
	ctx.r4.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// ori r27,r8,4626
	ctx.r27.u64 = ctx.r8.u64 | 4626;
	// addi r10,r31,112
	ctx.r10.s64 = ctx.r31.s64 + 112;
	// add r25,r11,r31
	ctx.r25.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r26,r9,27,31,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// cmpw cr6,r30,r29
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r29.s32, ctx.xer);
	// bne cr6,0x82786f20
	if (!ctx.cr6.eq) goto loc_82786F20;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82786f44
	if (ctx.cr6.eq) goto loc_82786F44;
	// b 0x82786f30
	goto loc_82786F30;
loc_82786F20:
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// bne cr6,0x82786f38
	if (!ctx.cr6.eq) goto loc_82786F38;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82786f44
	if (!ctx.cr6.eq) goto loc_82786F44;
loc_82786F30:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82786f44
	goto loc_82786F44;
loc_82786F38:
	// addic r11,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r11.s64 = ctx.r26.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
loc_82786F44:
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x82787020
	if (ctx.cr6.eq) goto loc_82787020;
	// li r23,1
	ctx.r23.s64 = 1;
loc_82786F5C:
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r25
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// lwzx r11,r10,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bne cr6,0x82786fa0
	if (!ctx.cr6.eq) goto loc_82786FA0;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82786f90
	if (ctx.cr6.eq) goto loc_82786F90;
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// bne cr6,0x82787144
	if (!ctx.cr6.eq) goto loc_82787144;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82786f94
	if (!ctx.cr6.eq) goto loc_82786F94;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82786f94
	if (!ctx.cr6.eq) goto loc_82786F94;
loc_82786F90:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82786F94:
	// stwx r6,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
	// b 0x82786fbc
	goto loc_82786FBC;
loc_82786FA0:
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// bne cr6,0x82786fbc
	if (!ctx.cr6.eq) goto loc_82786FBC;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82786fb8
	if (!ctx.cr6.eq) goto loc_82786FB8;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82786fbc
	if (ctx.cr6.eq) goto loc_82786FBC;
loc_82786FB8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82786FBC:
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x8278700c
	if (ctx.cr6.eq) goto loc_8278700C;
	// cmpw cr6,r30,r29
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x8278700c
	if (ctx.cr6.eq) goto loc_8278700C;
	// lwzx r11,r10,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// bne cr6,0x82786fe0
	if (!ctx.cr6.eq) goto loc_82786FE0;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// b 0x8278700c
	goto loc_8278700C;
loc_82786FE0:
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// bne cr6,0x82786ff0
	if (!ctx.cr6.eq) goto loc_82786FF0;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// b 0x8278700c
	goto loc_8278700C;
loc_82786FF0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8278700c
	if (!ctx.cr6.lt) goto loc_8278700C;
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x8278700c
	if (ctx.cr6.eq) goto loc_8278700C;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8278700c
	if (ctx.cr6.lt) goto loc_8278700C;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_8278700C:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmplw cr6,r4,r24
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r24.u32, ctx.xer);
	// blt cr6,0x82786f5c
	if (ctx.cr6.lt) goto loc_82786F5C;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x82787038
	if (!ctx.cr6.eq) goto loc_82787038;
loc_82787020:
	// subfic r11,r7,0
	ctx.xer.ca = ctx.r7.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r7.u64;
	// lis r10,-32646
	ctx.r10.s64 = -2139488256;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// ori r10,r10,4106
	ctx.r10.u64 = ctx.r10.u64 | 4106;
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x82787148
	goto loc_82787148;
loc_82787038:
	// lwz r11,92(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 92);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82787144
	if (!ctx.cr0.eq) goto loc_82787144;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x82787058
	if (ctx.cr6.eq) goto loc_82787058;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// bne cr6,0x82787144
	if (!ctx.cr6.eq) goto loc_82787144;
loc_82787058:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x827870c8
	if (ctx.cr6.eq) goto loc_827870C8;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// stw r29,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r29.u32);
	// beq cr6,0x82787078
	if (ctx.cr6.eq) goto loc_82787078;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82786bb8
	ctx.lr = 0x82787074;
	sub_82786BB8(ctx, base);
	// b 0x827870b4
	goto loc_827870B4;
loc_82787078:
	// stw r23,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r23.u32);
loc_8278707C:
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
	// bne 0x8278707c
	if (!ctx.cr0.eq) goto loc_8278707C;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,0(r25)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827870B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827870B4:
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82787148
	if (!ctx.cr0.eq) goto loc_82787148;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x827870c8
	if (ctx.cr6.eq) goto loc_827870C8;
	// stw r23,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r23.u32);
loc_827870C8:
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x82787144
	if (ctx.cr6.eq) goto loc_82787144;
	// cmpw cr6,r30,r29
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82787144
	if (ctx.cr6.eq) goto loc_82787144;
	// stw r30,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82787100;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82787148
	if (!ctx.cr0.eq) goto loc_82787148;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82786b50
	ctx.lr = 0x82787114;
	sub_82786B50(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82786a18
	ctx.lr = 0x82787124;
	sub_82786A18(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82786dc8
	ctx.lr = 0x82787130;
	sub_82786DC8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82787148
	if (!ctx.cr0.eq) goto loc_82787148;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x82787144
	if (ctx.cr6.eq) goto loc_82787144;
	// stw r23,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r23.u32);
loc_82787144:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82787148:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82796670) {
	REX_FUNC_PROLOGUE();
	// li r11,40
	ctx.r11.s64 = 40;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// stw r11,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r11,12(r4)
	REX_STORE_U32(ctx.r4.u32 + 12, ctx.r11.u32);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x827966a8
	if (!ctx.cr6.eq) goto loc_827966A8;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
loc_827966A8:
	// stw r11,16(r4)
	REX_STORE_U32(ctx.r4.u32 + 16, ctx.r11.u32);
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// stw r11,20(r4)
	REX_STORE_U32(ctx.r4.u32 + 20, ctx.r11.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,24(r4)
	REX_STORE_U32(ctx.r4.u32 + 24, ctx.r11.u32);
	// stw r5,28(r4)
	REX_STORE_U32(ctx.r4.u32 + 28, ctx.r5.u32);
	// stw r6,32(r4)
	REX_STORE_U32(ctx.r4.u32 + 32, ctx.r6.u32);
	// stw r7,36(r4)
	REX_STORE_U32(ctx.r4.u32 + 36, ctx.r7.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827993C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x827993D0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// li r24,0
	ctx.r24.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// addi r11,r3,48
	ctx.r11.s64 = ctx.r3.s64 + 48;
	// stw r24,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// ble cr6,0x82799470
	if (!ctx.cr6.gt) goto loc_82799470;
	// addi r27,r3,40
	ctx.r27.s64 = ctx.r3.s64 + 40;
	// addi r26,r3,28
	ctx.r26.s64 = ctx.r3.s64 + 28;
	// addi r28,r11,-20
	ctx.r28.s64 = ctx.r11.s64 + -20;
loc_82799408:
	// lwzu r30,20(r28)
	ea = 20 + ctx.r28.u32;
	ctx.r30.u64 = REX_LOAD_U32(ea);
	ctx.r28.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827976a0
	ctx.lr = 0x82799414;
	sub_827976A0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// bl 0x82797d70
	ctx.lr = 0x82799420;
	sub_82797D70(ctx, base);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// rlwinm r4,r11,1,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// bl 0x827986b0
	ctx.lr = 0x82799440;
	sub_827986B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82798c30
	ctx.lr = 0x82799448;
	sub_82798C30(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82799408
	if (ctx.cr6.lt) goto loc_82799408;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8279947c
	if (!ctx.cr6.eq) goto loc_8279947C;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x8279947c
	if (ctx.cr6.gt) goto loc_8279947C;
loc_82799470:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// oris r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 134217728;
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_8279947C:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r30,r31,24
	ctx.r30.s64 = ctx.r31.s64 + 24;
loc_82799484:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x827994cc
	if (ctx.cr6.eq) goto loc_827994CC;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r5,r11,-4
	ctx.r5.s64 = ctx.r11.s64 + -4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// mulli r11,r11,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(12));
	// subf r11,r11,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r11.u64;
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82799230
	ctx.lr = 0x827994BC;
	sub_82799230(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82789c80
	ctx.lr = 0x827994C4;
	sub_82789C80(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x82799484
	goto loc_82799484;
loc_827994CC:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// addi r10,r31,28
	ctx.r10.s64 = ctx.r31.s64 + 28;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x827994f8
	if (ctx.cr6.eq) goto loc_827994F8;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x827994f8
	if (ctx.cr0.eq) goto loc_827994F8;
	// lhz r10,14(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 14);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// ori r10,r10,1024
	ctx.r10.u64 = ctx.r10.u64 | 1024;
	// sth r10,14(r11)
	REX_STORE_U16(ctx.r11.u32 + 14, ctx.r10.u16);
	// b 0x8279950c
	goto loc_8279950C;
loc_827994F8:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// li r10,-1
	ctx.r10.s64 = -1;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_8279950C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A1670) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x827A1678;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r30,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x827a16d0
	if (!ctx.cr6.gt) goto loc_827A16D0;
	// addi r29,r3,12
	ctx.r29.s64 = ctx.r3.s64 + 12;
loc_827A169C:
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A16B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x827a16bc
	if (!ctx.cr6.eq) goto loc_827A16BC;
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
loc_827A16BC:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x827a169c
	if (ctx.cr6.lt) goto loc_827A169C;
loc_827A16D0:
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827a16e8
	if (ctx.cr6.eq) goto loc_827A16E8;
	// li r11,200
	ctx.r11.s64 = 200;
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// b 0x827a171c
	goto loc_827A171C;
loc_827A16E8:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x827a171c
	if (!ctx.cr6.gt) goto loc_827A171C;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827a1718
	if (ctx.cr6.eq) goto loc_827A1718;
	// bl 0x82748820
	ctx.lr = 0x827A1704;
	sub_82748820(ctx, base);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// subf r10,r3,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r3.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_827A1718:
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
loc_827A171C:
	// bl 0x82748820
	ctx.lr = 0x827A1720;
	sub_82748820(ctx, base);
	// stw r3,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r3.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A8668) {
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
loc_827A8680:
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
	// bdnz 0x827a8680
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A8680;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AA988) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739eec
	ctx.lr = 0x827AA990;
	__savegprlr_17(ctx, base);
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8273af1c
	ctx.lr = 0x827AA998;
	__savefpr_25(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// fmr f26,f3
	ctx.f26.f64 = ctx.f3.f64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// fmr f25,f4
	ctx.f25.f64 = ctx.f4.f64;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// fmr f28,f5
	ctx.f28.f64 = ctx.f5.f64;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lfs f30,7996(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7996);
	ctx.f30.f64 = double(temp.f32);
	// mr r19,r5
	ctx.r19.u64 = ctx.r5.u64;
	// fmuls f13,f1,f30
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// mr r17,r6
	ctx.r17.u64 = ctx.r6.u64;
	// lfs f0,11260(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 11260);
	ctx.f0.f64 = double(temp.f32);
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// fdivs f31,f0,f1
	ctx.f31.f64 = double(float(ctx.f0.f64 / ctx.f1.f64));
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r30,116(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmadds f0,f0,f31,f30
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f30.f64)));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt cr6,0x827aaa18
	if (ctx.cr6.lt) goto loc_827AAA18;
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
loc_827AAA18:
	// cmpwi cr6,r30,100
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 100, ctx.xer);
	// ble cr6,0x827aaa24
	if (!ctx.cr6.gt) goto loc_827AAA24;
	// li r30,100
	ctx.r30.s64 = 100;
loc_827AAA24:
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lfs f13,-20528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20528);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f2,f13
	ctx.f0.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x827aaa48
	if (!ctx.cr6.lt) goto loc_827AAA48;
	// li r11,100
	ctx.r11.s64 = 100;
	// twllei r30,0
	if (ctx.r30.s32 == 0 || ctx.r30.u32 < 0u) ppc_trap(ctx, base, 0);
	// divw r27,r11,r30
	ctx.r27.u64 = uint32_t((ctx.r30.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r30.s32 == -1)) ? ctx.r11.s32 / ctx.r30.s32 : 0);
	// b 0x827aaa4c
	goto loc_827AAA4C;
loc_827AAA48:
	// li r27,1
	ctx.r27.s64 = 1;
loc_827AAA4C:
	// extsw r11,r27
	ctx.r11.s64 = ctx.r27.s32;
	// fmuls f13,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// mullw r21,r27,r30
	ctx.r21.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r30.s32);
	// lfs f0,-14864(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -14864);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// addi r22,r11,-14932
	ctx.r22.s64 = ctx.r11.s64 + -14932;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r22,28
	ctx.r11.s64 = ctx.r22.s64 + 28;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r29,116(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// mullw r20,r29,r27
	ctx.r20.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r27.s32);
	// fcfid f0,f12
	ctx.f0.f64 = double(ctx.f12.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fdivs f27,f31,f0
	ctx.f27.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
loc_827AAA98:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f29,f0
	ctx.cr6.compare(ctx.f29.f64, ctx.f0.f64);
	// bgt cr6,0x827aaabc
	if (ctx.cr6.gt) goto loc_827AAABC;
	// addi r10,r22,28
	ctx.r10.s64 = ctx.r22.s64 + 28;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x827aaa98
	if (ctx.cr6.lt) goto loc_827AAA98;
loc_827AAABC:
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x827a8b78
	ctx.lr = 0x827AAAC4;
	sub_827A8B78(ctx, base);
	// addi r11,r22,4
	ctx.r11.s64 = ctx.r22.s64 + 4;
	// lwz r31,388(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 388);
	// rlwinm r7,r28,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r25,396(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 396);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// fmr f4,f28
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f28.f64;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// stw r23,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r23.u32);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// fmr f3,f27
	ctx.f3.f64 = ctx.f27.f64;
	// mr r8,r19
	ctx.r8.u64 = ctx.r19.u64;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// lfsx f0,r7,r11
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// fmadds f13,f1,f30,f0
	ctx.f13.f64 = double(float(std::fma(ctx.f1.f64, ctx.f30.f64, ctx.f0.f64)));
	// lfs f0,-14880(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -14880);
	ctx.f0.f64 = double(temp.f32);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// bl 0x827ac5f8
	ctx.lr = 0x827AAB14;
	sub_827AC5F8(ctx, base);
	// lfs f13,8(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// fadds f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// lfs f11,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,-14868(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14868);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,-14884(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -14884);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,2524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2524);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f13,f13,f0,f11
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f11.f64)));
	// fmuls f0,f13,f12
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// ble cr6,0x827aab5c
	if (!ctx.cr6.gt) goto loc_827AAB5C;
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// b 0x827aab6c
	goto loc_827AAB6C;
loc_827AAB5C:
	// fsubs f0,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
loc_827AAB6C:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f31,8(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r26.u32 + 8, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfs f0,28104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28104);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f1,f12,f0,f13
	ctx.f1.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// stfs f1,0(r26)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// bl 0x827aa8e0
	ctx.lr = 0x827AABA8;
	sub_827AA8E0(ctx, base);
	// addi r11,r30,-1
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// addi r10,r21,-1
	ctx.r10.s64 = ctx.r21.s64 + -1;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x827aac18
	if (ctx.cr6.lt) goto loc_827AAC18;
	// subf r9,r29,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r29.u64;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r5,r27,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// add r7,r7,r31
	ctx.r7.u64 = ctx.r7.u64 + ctx.r31.u64;
	// subf r4,r31,r25
	ctx.r4.u64 = ctx.r25.u64 - ctx.r31.u64;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
loc_827AABDC:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x827aac0c
	if (!ctx.cr6.gt) goto loc_827AAC0C;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
	// subf r10,r27,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r27.u64;
	// subf r8,r5,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r5.u64;
loc_827AABF4:
	// lfsx f0,r7,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r4,r6
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + ctx.r6.u32, temp.u32);
	// lfs f0,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r6,r6,-4
	ctx.r6.s64 = ctx.r6.s64 + -4;
	// bdnz 0x827aabf4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827AABF4;
loc_827AAC0C:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// bne 0x827aabdc
	if (!ctx.cr0.eq) goto loc_827AABDC;
loc_827AAC18:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x827aac7c
	if (ctx.cr6.lt) goto loc_827AAC7C;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r31,r25
	ctx.r6.u64 = ctx.r25.u64 - ctx.r31.u64;
	// add r8,r9,r31
	ctx.r8.u64 = ctx.r9.u64 + ctx.r31.u64;
loc_827AAC2C:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r8,r6
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// stfsx f0,r9,r25
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r25.u32, temp.u32);
	// lfs f0,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r9,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, temp.u32);
	// ble cr6,0x827aac70
	if (!ctx.cr6.gt) goto loc_827AAC70;
	// addi r9,r27,-1
	ctx.r9.s64 = ctx.r27.s64 + -1;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// add r7,r7,r31
	ctx.r7.u64 = ctx.r7.u64 + ctx.r31.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_827AAC60:
	// stfsx f10,r7,r6
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r7.u32 + ctx.r6.u32, temp.u32);
	// stfs f10,0(r7)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// bdnz 0x827aac60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827AAC60;
loc_827AAC70:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// bge 0x827aac2c
	if (!ctx.cr0.lt) goto loc_827AAC2C;
loc_827AAC7C:
	// cmpw cr6,r20,r21
	ctx.cr6.compare<int32_t>(ctx.r20.s32, ctx.r21.s32, ctx.xer);
	// bge cr6,0x827aad00
	if (!ctx.cr6.lt) goto loc_827AAD00;
	// subf r9,r20,r21
	ctx.r9.u64 = ctx.r21.u64 - ctx.r20.u64;
	// lfs f0,0(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r11,r20,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lwz r9,428(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 428);
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
loc_827AACA0:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// srawi r11,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 16;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// mulli r7,r11,16807
	ctx.r7.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(16807));
	// mulli r8,r8,16807
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(16807));
	// rlwinm r11,r7,16,1,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0x7FFF0000;
	// rlwinm r7,r7,17,15,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 17) & 0x1FFFF;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// stw r11,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// std r8,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f13,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f13,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x827aaca0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827AACA0;
loc_827AAD00:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// lfs f13,5864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f13.f64 = double(temp.f32);
	// ble cr6,0x827aad58
	if (!ctx.cr6.gt) goto loc_827AAD58;
	// addi r11,r25,-4
	ctx.r11.s64 = ctx.r25.s64 + -4;
	// mtctr r21
	ctx.ctr.u64 = ctx.r21.u64;
loc_827AAD18:
	// lfsu f0,4(r11)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fadds f10,f0,f10
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f10.f64));
	// bdnz 0x827aad18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827AAD18;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lfs f0,-30488(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30488);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// ble cr6,0x827aad38
	if (!ctx.cr6.gt) goto loc_827AAD38;
	// fdivs f13,f0,f10
	ctx.f13.f64 = double(float(ctx.f0.f64 / ctx.f10.f64));
loc_827AAD38:
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// ble cr6,0x827aad58
	if (!ctx.cr6.gt) goto loc_827AAD58;
	// mtctr r21
	ctx.ctr.u64 = ctx.r21.u64;
	// addi r11,r25,-4
	ctx.r11.s64 = ctx.r25.s64 + -4;
loc_827AAD48:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfsu f0,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x827aad48
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827AAD48;
loc_827AAD58:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// fmr f3,f25
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f25.f64;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// fmr f2,f26
	ctx.f2.f64 = ctx.f26.f64;
	// mr r8,r17
	ctx.r8.u64 = ctx.r17.u64;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r18
	ctx.r6.u64 = ctx.r18.u64;
	// li r5,160
	ctx.r5.s64 = 160;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// bl 0x827a6a30
	ctx.lr = 0x827AAD84;
	sub_827A6A30(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8273af68
	ctx.lr = 0x827AAD90;
	__restfpr_25(ctx, base);
	// b 0x82739f3c
	__restgprlr_17(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827BF8A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1724(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1252(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1252, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1800) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-968(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1520(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1520);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2980) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,26920
	ctx.r9.s64 = ctx.r11.s64 + 26920;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,26920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-292(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3A98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,208(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 208, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4828) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,620(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 620);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,624(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 624, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C57F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1092(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C67E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28036(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28036);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14376(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14376);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,1584(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7770) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2060(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8600) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,28584
	ctx.r9.s64 = ctx.r11.s64 + 28584;
	// lfs f0,28584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2500(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 2500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9210) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2852(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CA5F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,28904
	ctx.r9.s64 = ctx.r11.s64 + 28904;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,28904(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28904);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3432(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB8B0) {
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
	// lfs f0,29096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3928(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3928);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4000(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CCA50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,4512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4516(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CDB08) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4888(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4888);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5000(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CED18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,5420(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5420);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5528(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CFBA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5952(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0968) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29948(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29948);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6356(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1A58) {
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
	// lfs f0,30056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6740(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6740);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6848(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2CB0) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7384(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D3F30) {
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
	// lfs f0,30440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7820(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7820);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7924(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7924, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D51A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,8456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8456);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8460(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 8460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5B58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8740(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8740);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8744(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6A68) {
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
	// lfs f0,30888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9100(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9100);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9184(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9184, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7CC8) {
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
	// lfs f0,31088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9652(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9652);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9720(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9720, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8F68) {
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
	// lfs f0,31304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10204(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10204);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10264(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA1E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10804(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10804, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB2D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31692);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11292(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DC058) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,31752
	ctx.r9.s64 = ctx.r11.s64 + 31752;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11684(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD470) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31944(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31944);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12192(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12192);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12296(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12296, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE2A8) {
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
	// lfs f0,32088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12592(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12592);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12712(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DF648) {
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
	// lfs f0,32296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13176(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13176);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13288(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0960) {
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
	// lfs f12,13728(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13728);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13844(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1AC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2BA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-32420(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32420);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,14872(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 14872, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3578) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15152(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15152, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E45E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15604(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15604);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15608(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15608, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E54C0) {
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
	// lfs f0,16000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16000);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31896(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31896);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,16024(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 16024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7078) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,16824(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16824);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,16828(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 16828, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7998) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16948(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16948);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17064(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8EC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-24572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24572);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17676(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17676, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9EE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18108(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18108);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18112(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18112, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EADA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18532(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18532, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EBC98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18944(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18944);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18948(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ECBC0) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19244);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19360(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EDFA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-20776
	ctx.r9.s64 = ctx.r11.s64 + -20776;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-20776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19908(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19908, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,20428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20428);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20432(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F03B0) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20824(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20824);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20904(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20904, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F1598) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r8,21400
	ctx.r6.s64 = ctx.r8.s64 + 21400;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r5,97
	ctx.r5.s64 = 97;
	// lwz r11,21400(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 21400);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwimi r11,r7,1,24,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r11,21400(r8)
	REX_STORE_U32(ctx.r8.u32 + 21400, ctx.r11.u32);
	// stb r10,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r10.u8);
	// lwz r11,21400(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 21400);
	// rlwimi r11,r5,16,8,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF0000) | (ctx.r11.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r11,21400(r8)
	REX_STORE_U32(ctx.r8.u32 + 21400, ctx.r11.u32);
	// stb r9,21400(r8)
	REX_STORE_U8(ctx.r8.u32 + 21400, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2F18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-17416
	ctx.r9.s64 = ctx.r11.s64 + -17416;
	// lfs f0,-17416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22108(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 22108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F3D90) {
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
	// lfs f13,22412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 22412);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22520(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22520, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F4F10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,-16280
	ctx.r11.s64 = ctx.r11.s64 + -16280;
	// lfs f0,23176(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 23176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5B48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,23600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23600);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,23604(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 23604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6398) {
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
	// lfs f0,-15592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23732(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23732);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,23836(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23836, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F78F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-13972(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13972);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,24420(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 24420, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8458) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24700);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9278) {
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
	// lfs f0,-11928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11928);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25080(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25080);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,25100(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 25100, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FAB58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9676(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9676);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FBB30) {
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
	// lfs f0,-9560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26184(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26184);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26272(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26272, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FCE48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-9368
	ctx.r9.s64 = ctx.r11.s64 + -9368;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26828(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26828, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FE248) {
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
	// lfs f0,-9176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27300);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27412(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FF5B0) {
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
	// lfs f12,27876(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27876);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27976(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27976, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800910) {
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
	// lfs f0,-8792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28428(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28428);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28540(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801C50) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28980(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28980);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29100(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29100, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802FB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29668(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29668, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803DB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30076(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30076);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30080(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30080, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804C68) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30424(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30424);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30508(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805FA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-7896
	ctx.r9.s64 = ctx.r11.s64 + -7896;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-7896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31068(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828073A8) {
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
	// lfs f0,-7704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31540);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31652(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808780) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32116(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32116);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32228(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809B28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32736(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32736, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A908) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-32332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32332);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32328(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B808) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-7000
	ctx.r9.s64 = ctx.r11.s64 + -7000;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-7000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31892(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280CBC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-31300(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31300);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-31296(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -31296, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280D848) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-6616
	ctx.r9.s64 = ctx.r11.s64 + -6616;
	// lfs f0,-6616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30932(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -30932, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E618) {
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
	// lfs f0,-6424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30640(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30640);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30528(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280FA00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6156);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29948(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810750) {
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
	// lfs f0,-5976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5976);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29612(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29612);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29544(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811B20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28960(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28960, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812B38) {
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
	// lfs f0,-5592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28608(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28608);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28492(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28492, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813E40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27904(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27904);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27900(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814E98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27388);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27384(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815CF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4508);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26960(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26960, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82816E68) {
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
	// lfs f0,-4384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-26564(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -26564);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-26448(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -26448, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818048) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-25904(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25904);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25900(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819168) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-25392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25392);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25388(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25388, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281A1C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3412);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24904(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24904, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281AEC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24508(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281BED8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-24040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24040);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-24036(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -24036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281C9A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-23712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23712);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-23708(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -23708, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281D468) {
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
	// lfs f0,-2632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23452(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23452);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281E870) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-22792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281F8A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-22316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22316);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-22312(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -22312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828201F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1972(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1972);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22044(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-21728(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -21728);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21624(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21624, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82822098) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21212(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21212);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21140(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21140, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828233E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-20576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20572(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82824480) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1092(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1092);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20076(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20076, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825300) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19648(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828261E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82827130) {
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
	// lfs f0,-464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18824(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18824);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18740(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18740, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828285E8) {
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
	// lfs f0,-232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18256(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18256);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18136(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18136, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829B00) {
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
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17636(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17636);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17516(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282AED8) {
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
	// lfs f0,216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17044(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17044);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16936(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C1B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16372(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16372, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 732);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15948(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E038) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-15480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15480);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-15476(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -15476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282EB40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-15152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15148(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282FC58) {
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
	// lfs f0,1160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14652(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830F48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14084(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14084, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831D78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-13660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13660);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-13656(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -13656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832918) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13308(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13308, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833948) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12828(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12828);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834950) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,2296
	ctx.r9.s64 = ctx.r11.s64 + 2296;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,2296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12352(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835BF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-11800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11796(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836C80) {
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
	// lfs f0,2680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11428(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11428);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11316(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838068) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-10732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10732);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-10728(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -10728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838A48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10444);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10440, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828398F0) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10008(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283ACD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-9432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9432);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-9428(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -9428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283B790) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-9120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9116(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9116, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283C670) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8740(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8740);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8680(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8680, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283DA48) {
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
	// lfs f0,4016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8172(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8172);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8100(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8100, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283EEA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,4224
	ctx.r9.s64 = ctx.r11.s64 + 4224;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,4224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7508(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828402E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6908(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6908, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82841168) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6484);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6480(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828422E0) {
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
	// lfs f0,4912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6084(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6084);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5972(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82843740) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,5216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828444D0) {
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
	// lfs f0,5400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5032(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5032);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4964(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845920) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,5708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4356(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828468C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3892(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847988) {
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
	// lfs f12,-3516(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3516);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3408(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848E08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2796(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849C90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284ABF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,6640
	ctx.r9.s64 = ctx.r11.s64 + 6640;
	// lfs f0,6640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1920(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -1920, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284BC20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1452(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1452, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284CAA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1028(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1028);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1024(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284DB50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -516);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-512(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284ECC8) {
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
	// lfs f0,7496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-84(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -84);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284FE48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 516);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,520(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 520, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850DE0) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,892(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 892);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1004(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852398) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1620(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828531C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,8568
	ctx.r9.s64 = ctx.r11.s64 + 8568;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,8568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2048(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828552F8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// addi r3,r11,9864
	ctx.r3.s64 = ctx.r11.s64 + 9864;
	// b 0x827348e0
	sub_827348E0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8286D870) {
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
loc_8286D884:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8286d8bc
	if (ctx.cr6.lt) goto loc_8286D8BC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8ab8
	ctx.lr = 0x8286D8A0;
	sub_826C8AB8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8286d884
	if (ctx.cr6.eq) goto loc_8286D884;
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
loc_8286D8BC:
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

DEFINE_REX_FUNC(sub_8287DC78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8287DC80;
	__savegprlr_26(ctx, base);
	// stwu r1,-928(r1)
	ea = -928 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
	// lvsl v7,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// li r10,16
	ctx.r10.s64 = 16;
	// vspltish v13,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x1)));
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// lwz r29,1012(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 1012);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lvx128 v62,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r6,r8,r11
	ctx.r6.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r7,r3,r11
	ctx.r7.u64 = ctx.r3.u64 + ctx.r11.u64;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// lvx128 v61,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v6,v63,v61,v7
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v57,r8,r10
	ea = (ctx.r8.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subfic r9,r9,8
	ctx.xer.ca = ctx.r9.u32 <= 8;
	ctx.r9.u64 = static_cast<uint64_t>(8) - ctx.r9.u64;
	// lvx128 v58,r6,r10
	ea = (ctx.r6.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r31,r11,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v59,r7,r10
	ea = (ctx.r7.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lvx128 v56,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r31,r31,r3
	ctx.r31.u64 = ctx.r31.u64 + ctx.r3.u64;
	// lvsl v5,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v8,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v4,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v3,v62,v59,v5
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// lvsl v2,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v1,v56,v58,v4
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vperm128 v31,v60,v57,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// cntlzw r9,r29
	ctx.r9.u64 = ctx.r29.u32 == 0 ? 32 : __builtin_clz(ctx.r29.u32);
	// lvx128 v55,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v30,v8,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vmrghb v12,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v54,r31,r10
	ea = (ctx.r31.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v10,v0,v1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v7,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v11,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// vperm128 v6,v55,v54,v7
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vadduhm v5,v30,v8
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vslh v4,v12,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// and r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 & ctx.r30.u64;
	// vslh v3,v10,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// vslh v2,v11,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vmrghb v9,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r29,r1,144
	ctx.r29.s64 = ctx.r1.s64 + 144;
	// vadduhm v1,v4,v12
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// addi r28,r1,192
	ctx.r28.s64 = ctx.r1.s64 + 192;
	// vadduhm v31,v3,v10
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// addi r27,r1,240
	ctx.r27.s64 = ctx.r1.s64 + 240;
	// vadduhm v30,v2,v11
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// vadduhm v29,v5,v12
	simde_mm_store_si128((simde__m128i*)ctx.v29.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vadduhm v28,v1,v11
	simde_mm_store_si128((simde__m128i*)ctx.v28.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// li r26,4
	ctx.r26.s64 = 4;
	// vadduhm v25,v31,v9
	simde_mm_store_si128((simde__m128i*)ctx.v25.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// slw r7,r7,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r9.u8 & 0x3F));
	// vadduhm v27,v30,v10
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// lvx128 v26,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsplth v1,v26,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), simde_mm_set1_epi16(short(0xD0C))));
	// slw r6,r26,r30
	ctx.r6.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r26.u32 << (ctx.r30.u8 & 0x3F));
	// stvx128 v29,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r7,8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 8, ctx.xer);
	// stvx128 v28,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v27,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8287de60
	if (!ctx.cr6.eq) goto loc_8287DE60;
	// add r9,r31,r11
	ctx.r9.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lvx128 v53,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v12,v9,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// rlwinm r31,r11,3,0,28
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r31,r31,r3
	ctx.r31.u64 = ctx.r31.u64 + ctx.r3.u64;
	// add r30,r8,r11
	ctx.r30.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lvx128 v52,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vadduhm v9,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// lvx128 v51,r9,r10
	ea = (ctx.r9.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,288
	ctx.r29.s64 = ctx.r1.s64 + 288;
	// lvx128 v50,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,336
	ctx.r28.s64 = ctx.r1.s64 + 336;
	// lvx128 v49,r8,r10
	ea = (ctx.r8.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r1,384
	ctx.r27.s64 = ctx.r1.s64 + 384;
	// lvx128 v48,r30,r10
	ea = (ctx.r30.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r1,432
	ctx.r26.s64 = ctx.r1.s64 + 432;
	// lvsl v7,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lvsl v6,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v5,v53,v51,v7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvsl v4,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v3,v52,v49,v6
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v2,v50,v48,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// lvx128 v47,r31,r10
	ea = (ctx.r31.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v12,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v7,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v11,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v10,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v6,v46,v47,v7
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vslh v5,v12,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v4,v11,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v3,v10,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vmrghb v2,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vadduhm v31,v9,v12
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vadduhm v30,v5,v12
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vadduhm v29,v4,v11
	simde_mm_store_si128((simde__m128i*)ctx.v29.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vadduhm v28,v3,v10
	simde_mm_store_si128((simde__m128i*)ctx.v28.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// stvx128 v31,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vadduhm v27,v30,v11
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vadduhm v26,v29,v10
	simde_mm_store_si128((simde__m128i*)ctx.v26.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vadduhm v25,v28,v2
	simde_mm_store_si128((simde__m128i*)ctx.v25.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// stvx128 v27,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v26,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8287DE60:
	// cmpwi cr6,r6,8
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 8, ctx.xer);
	// blt cr6,0x8287ded0
	if (ctx.cr6.lt) goto loc_8287DED0;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r3,8
	ctx.r8.s64 = ctx.r3.s64 + 8;
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x8287ded0
	if (!ctx.cr6.gt) goto loc_8287DED0;
	// addi r10,r7,-1
	ctx.r10.s64 = ctx.r7.s64 + -1;
	// subf r27,r9,r11
	ctx.r27.u64 = ctx.r11.u64 - ctx.r9.u64;
	// rlwinm r3,r10,31,1,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 1;
	// subf r3,r9,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r9.u64;
	// addi r11,r30,-48
	ctx.r11.s64 = ctx.r30.s64 + -48;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
loc_8287DE9C:
	// lbzux r8,r3,r9
	ea = ctx.r3.u32 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// lbzx r26,r27,r10
	ctx.r26.u64 = REX_LOAD_U8(ctx.r27.u32 + ctx.r10.u32);
	// rotlwi r30,r8,1
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lbz r31,0(r10)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r28,r26,1
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r26.u32, 1);
	// add r30,r8,r30
	ctx.r30.u64 = ctx.r8.u64 + ctx.r30.u64;
	// add r8,r26,r28
	ctx.r8.u64 = ctx.r26.u64 + ctx.r28.u64;
	// add r30,r30,r26
	ctx.r30.u64 = ctx.r30.u64 + ctx.r26.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// sth r30,48(r11)
	REX_STORE_U16(ctx.r11.u32 + 48, ctx.r30.u16);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sthu r8,96(r11)
	ea = 96 + ctx.r11.u32;
	REX_STORE_U16(ea, ctx.r8.u16);
	ctx.r11.u32 = ea;
	// bdnz 0x8287de9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8287DE9C;
loc_8287DED0:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8287b580
	ctx.lr = 0x8287DED8;
	sub_8287B580(ctx, base);
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

